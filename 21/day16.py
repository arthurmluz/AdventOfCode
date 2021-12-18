input = '60556F980272DCE609BC01300042622C428BC200DC128C50FCC0159E9DB9AEA86003430BE5EFA8DB0AC401A4CA4E8A3400E6CFF7518F51A554100180956198529B6A700965634F96C0B99DCF4A13DF6D200DCE801A497FF5BE5FFD6B99DE2B11250034C00F5003900B1270024009D610031400E70020C0093002980652700298051310030C00F50028802B2200809C00F999EF39C79C8800849D398CE4027CCECBDA25A00D4040198D31920C8002170DA37C660009B26EFCA204FDF10E7A85E402304E0E60066A200F4638311C440198A11B635180233023A0094C6186630C44017E500345310FF0A65B0273982C929EEC0000264180390661FC403006E2EC1D86A600F43285504CC02A9D64931293779335983D300568035200042A29C55886200FC6A8B31CE647880323E0068E6E175E9B85D72525B743005646DA57C007CE6634C354CC698689BDBF1005F7231A0FE002F91067EF2E40167B17B503E666693FD9848803106252DFAD40E63D42020041648F24460400D8ECE007CBF26F92B0949B275C9402794338B329F88DC97D608028D9982BF802327D4A9FC10B803F33BD804E7B5DDAA4356014A646D1079E8467EF702A573FAF335EB74906CF5F2ACA00B43E8A460086002A3277BA74911C9531F613009A5CCE7D8248065000402B92D47F14B97C723B953C7B22392788A7CD62C1EC00D14CC23F1D94A3D100A1C200F42A8C51A00010A847176380002110EA31C713004A366006A0200C47483109C0010F8C10AE13C9CA9BDE59080325A0068A6B4CF333949EE635B495003273F76E000BCA47E2331A9DE5D698272F722200DDE801F098EDAC7131DB58E24F5C5D300627122456E58D4C01091C7A283E00ACD34CB20426500BA7F1EBDBBD209FAC75F579ACEB3E5D8FD2DD4E300565EBEDD32AD6008CCE3A492F98E15CC013C0086A5A12E7C46761DBB8CDDBD8BE656780'
curr = input
f = bin(int(curr, 16))[2:].zfill(4*len(curr))

def get_header(pack):
  ver = pack[:3]
  type_ID = pack[3:6]
  pack = pack[6:]
  return int(ver, 2), int(type_ID, 2), pack

def get_value(pack):
  sub_pack = '1'
  value = ""
  while sub_pack[0] != '0':
    sub_pack = pack[:5]
    pack = pack[5:]
    value += sub_pack[1:]
  return int(value, 2), pack

def get_operator_len(pack):
  length_type = pack[0]
  if length_type == '0':
    length_subpacket = int(pack[1:16],2)
    pack = pack[16:]
  else:
    length_subpacket =  int(pack[1:12],2)
    pack = pack[12:]
  return length_type, length_subpacket, pack

def run_op(opcode, values):
  if opcode == 0: #sum
    return sum(values)
  if opcode == 1: #prod
    res = 1
    for value in values:
      res *= value
    return res
  if opcode == 2: #min
    return min(values)
  if opcode == 3: #max
    return max(values)
  if opcode == 5: # gt
    return int(values[0] > values[1])
  if opcode == 6: # ls
    return int(values[0]<values[1])
  if opcode == 7: # eq
    return int(values[0]==values[1])
  

def process(pack, ls):
  global part1
  values = []
  while len(pack) >= 11 and ls > 0:
    ls -= 1
    # processa pacote
    ver, type_ID, pack = get_header(pack)
    part1 += ver
    if type_ID == 4:
      value, pack = get_value(pack)
      #print('literal', value)
    # I 11 ou 15 'L'
    else:
      #print('operator', pack)
      length_type, length_subpacket, pack = get_operator_len(pack)
      if length_type == '0':
        vs, _ = process(pack[:length_subpacket], float('inf'))
        pack = pack[length_subpacket:]
      else:
        vs, pack = process(pack, length_subpacket)
      value = run_op(type_ID, vs)
    values.append(value)
  return values.copy(), pack

part1 = 0
values, pack = process(f, float('inf'))
print('part1:',part1)
print('part2:', values)
