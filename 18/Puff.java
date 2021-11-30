import java.util.Scanner;

//dabAcCaCBAcCcaDA
//aA
public class Puff {
    public static void main(String[] args ){
        Scanner in = new Scanner(System.in);
        String entrada = in.nextLine();
        
        int i = 0; int menordetodos = 10;
        
        while ( i < entrada.length()-1 ) { // talvez? não sabemos... nao sabemos. Será?
            char atual = entrada.charAt(i);
            char proxima = entrada.charAt(i+1);
    
            if (atual != proxima &&
                String.valueOf(atual).toUpperCase().equals(
                String.valueOf(proxima).toUpperCase()) ) {
                
                // estamos no caso em que tem que reagir. "xAab" -> "x" "Aa" "b" -> puf -> "xb".
                entrada = entrada.substring(0,i) + entrada.substring(i+2); // "" + "" == ""?

                i = i>0 ? i-1: i;

            }
            else
                i++; // Sera? Sim!
        }

        //         
        // Abakd -> bkd
        
        System.out.println("Res: "+entrada.length());
        System.out.println("PUFFFFFFFFFFFF");
        
    }
}
