#include <stdio.h>
#define TAM 10       //mudar dps

typedef enum {slashing=0, cold=1, fire=2, radiation=3, bludgeoning=4}att_type;

typedef struct {
  int n, hp, att, init;
  att_type attack_type;
  int weak[5];
  int immune[5];
  int faccao, id_enemy, targeted, id;     // 1 immune 0 infecc
 } grupos;

int compTarget (const void *aa , const void *bb) {
  grupos *a = ( grupos * ) aa; //NOTE might be b - a
  grupos *b = ( grupos * ) bb;
  int comp =    b->n * b->att - a->n * a->att;
  if ( !comp ) comp = b->init - a->init;
  return comp;
}


int compFight (const void *aa , const void *bb) {
  grupos *a = ( grupos * ) aa; //NOTE might be b - a
  grupos *b = ( grupos * ) bb;
  return b->init - a->init;
}

//slashing=0, cold=1, fire=2, radiation=3, bludgeoning=4;
int main(){
   grupos imunes[TAM];
   grupos infec[TAM];

		//typedef enum {slashing=0, cold=1, fire=2, radiation=3, bludgeoning=4}att_type;

	imunes[0] = (grupos) {.n =479, .hp = 3393, .att=66+42, .init = 8, .attack_type = cold, .weak = {0,0,0,1,0}, .immune={},.faccao=1,.id_enemy = -1};
	imunes[1] = (grupos) {.n=2202, .hp=4950,   .att=18+42, .init=2, .attack_type=cold, .weak={0,0,1,0,0}, .immune={1,0,0,0,0},.faccao=1,.id_enemy = -1};
	imunes[2] = (grupos) {.n=8132, .hp=9680,   .att=9 +42, .init=7, .attack_type=radiation, .weak={0,0,1,0,1}, .immune={1,0,0,0,0},.faccao=1,.id_enemy = -1};
	imunes[3] = (grupos) {.n=389, .hp=13983,  .att=256+42, .init=13, .attack_type=cold, .weak={}, .immune={0,0,0,0,1},.faccao=1,.id_enemy = -1};
	imunes[4] = (grupos) {.n=1827, .hp=5107,   .att=24+42, .init=18, .attack_type=slashing, .weak={}, .immune={},.faccao=1,.id_enemy = -1};
	imunes[5] = (grupos) {.n =7019, .hp = 2261,.att= 3+42, .init = 16, .attack_type = fire, .weak = {}, .immune={1,1,0,1,0},.faccao=1,.id_enemy = -1};
	imunes[6] = (grupos) {.n=4736, .hp=8421,   .att=17+42, .init=3, .attack_type=slashing, .weak={0,1,0,0,0}, .immune={},.faccao=1,.id_enemy = -1};
	imunes[7] = (grupos) {.n=491, .hp=3518,    .att=65+42, .init=1, .attack_type=radiation, .weak={0,1,0,0,0}, .immune={0,0,1,0,1},.faccao=1,.id_enemy = -1};
	imunes[8] = (grupos) {.n=2309, .hp=7353,   .att=31+42, .init=20, .attack_type=bludgeoning, .weak={0,0,0,0,0}, .immune={0,0,0,1,0},.faccao=1,.id_enemy = -1};
	imunes[9] = (grupos) {.n=411, .hp=6375,   .att=151+42, .init=14, .attack_type=bludgeoning, .weak={0,1,1,0,0}, .immune={1,0,0,0,0},.faccao=1,.id_enemy = -1};

	infec[0] = (grupos) {.n=148, .hp=31914, .att=416, .init=4, .attack_type=cold, .weak={0,0,0,0,1}, .immune={0,1,1,1,0},.faccao=0,.id_enemy = -1};
	infec[1] = (grupos) {.n=864, .hp=38189, .att=72, .init=6, .attack_type=slashing, .weak={0,0,0,0,0}, .immune={0,0,0,0,0},.faccao=0,.id_enemy = -1};
	infec[2] = (grupos) {.n=2981, .hp=7774, .att=4, .init=15, .attack_type=fire, .weak={0,0,0,0,0}, .immune={0,1,0,0,1},.faccao=0,.id_enemy = -1};
	infec[3] = (grupos) {.n=5259, .hp=22892, .att=8, .init=5, .attack_type=fire, .weak={0,0,0,0,0}, .immune={0,0,0,0,0},.faccao=0,.id_enemy = -1};
	infec[4] = (grupos) {.n=318, .hp=16979, .att=106, .init=9, .attack_type=bludgeoning, .weak={0,0,1,0,0}, .immune={0,0,0,0,0},.faccao=0,.id_enemy = -1};
	infec[5] = (grupos) {.n=5017, .hp=32175, .att=11, .init=17, .attack_type=bludgeoning, .weak={1,0,0,0,0}, .immune={0,0,0,1,0},.faccao=0,.id_enemy = -1};
	infec[6] = (grupos) {.n=4308, .hp=14994, .att=5, .init=10, .attack_type=fire, .weak={1,0,0,0,0}, .immune={0,1,1,0,0},.faccao=0,.id_enemy = -1};
	infec[7] = (grupos) {.n=208, .hp=14322, .att=133, .init=19, .attack_type=cold, .weak={0,0,0,1,0}, .immune={0,0,0,0,0},.faccao=0,.id_enemy = -1};
	infec[8] = (grupos) {.n=3999, .hp=48994, .att=20, .init=11, .attack_type=cold, .weak={1,1,0,0,0}, .immune={0,0,0,0,0},.faccao=0,.id_enemy = -1};
	infec[9] = (grupos) {.n=1922, .hp=34406, .att=35, .init=12, .attack_type=slashing, .weak={1,0,0,0,0}, .immune={0,0,0,0,0},.faccao=0,.id_enemy = -1};


//   infec[1] = (grupos) {.n=4485, .hp=2961, .att=12, .init=4, .attack_type=slashing, .weak={0,1,1,0,0}, .immune={0,0,0,1,0},.faccao=0,.id_enemy = -1};

    //atribuir ids
    int id; 
    for( id = 0; id < TAM; id++) imunes[id].id = id;
    for( id    ; id < 2*TAM; id++)  infec[id-TAM].id = id;

    //copy
    int n_infec = TAM; //NOTE change according to input
    int n_imunes = TAM; //NOTE change according to input
    int n_combined = n_infec + n_imunes;
    grupos combined[n_combined];
    memcpy(combined, infec, n_infec * sizeof(grupos)); 
    memcpy(combined + n_infec, imunes, n_imunes * sizeof(grupos)); 

   while(1){
     int sum_imune = 0;
     int sum_infec = 0;
     int i;
     
     for(i = 0; i < TAM*2; i ++){
       if ( combined[i].faccao )  //imune
          sum_imune += combined[i].n;
       else //infec
          sum_infec += combined[i].n;
     }

     if(sum_imune <= 0 || sum_infec <= 0) break;


    //É HORA DO DUELO
//    printf("HORA DO DUELO\n");

    // Selecao dos targueti
    qsort(combined , n_combined, sizeof(grupos), &compTarget);

    for(i = 0; i < TAM*2; i++){
      grupos *atacante = &combined[i];
      grupos *to_attack;
      int max_damage = 0;

      if ( atacante->n <= 0) continue;
      
      int achei = 0;
      for(int j = 0; j < 2*TAM; j++){
        grupos *candidato = &combined[j];
        if(candidato->targeted || candidato->faccao == atacante->faccao || candidato->n <= 0 ) 
            continue;

        int curr_damage = atacante->att * atacante->n;
        if(candidato->immune[atacante->attack_type]) curr_damage = 0;
        else if( candidato->weak[atacante->attack_type]) curr_damage *= 2;

        if(curr_damage > max_damage){ 
          max_damage = curr_damage;
          to_attack = candidato;
          achei = 1;
        }
      }
      
      if (achei) {
        atacante->id_enemy = to_attack->id;
        to_attack->targeted = 1;
      }
//      printf("Atacante id %d setou id enemy %d como alvo\n", atacante->id, atacante->id_enemy);
    }

    //fase de ataque
    qsort(combined , n_combined, sizeof(grupos), &compFight);

    for( int i = 0; i < n_combined; i++ ) {
      grupos *atacante = &combined[i];
      grupos *atacado;
      
      //nao tenho alvo passo a vez 
      if ( atacante->id_enemy == -1 ) continue;
      
      //pesquisa pelo meu inimigo
      for(int j =0; j < n_combined; j++){
        if(atacante->id_enemy == combined[j].id){
        atacado = &combined[j];
          break;
        }
      }
      
      int damage = atacante->n * atacante->att;
      if(damage < 0) damage = 0; //cuida quando meu n < 0
      if(atacado->weak[atacante->attack_type]) damage *=2;
      else if(atacado->immune[atacante->attack_type]) damage =0;
      
      atacado->n -= (int) damage/atacado->hp;
      
      char imune[] = "imune";
      char infec[] = "infec";
      char fac_att[10];
      if ( atacante->faccao) memcpy(fac_att, imune,6);
      else memcpy(fac_att, infec,6);
      char fac_hit[10];
      if ( atacante->faccao) memcpy(fac_hit,infec,6);
      else memcpy(fac_hit, imune,6);

  //    printf( "%s %d atacando %s %d com %d de dano, matei %d!\n", fac_att, atacante->id, fac_hit, atacado->id, damage, (int) damage/atacado->hp);
      
    }
    printf("\n\nNova rodada:\n");
    for(int i = 0; i < 2*TAM; i++){
      grupos v = combined[i];
      if (v.faccao) printf("Imune %d : %d units\n", v.id, v.n);
      else printf("Infect %d : %d units\n", v.id, v.n);
      
    }
    printf("-----------------------\n");
  
    //reseta flags          ---- quais mais? ----
    for( i = 0; i < 2*TAM; i++ ){
        combined[i].targeted = 0;
        combined[i].id_enemy = -1;
    }
   }
   return 0;
 }
