
void print_list(Liste_t * player) {
  int i = 1;
  while(player){
    printf("<----------Pokémon n°%d: ---------->\n Nom: %s \n Type 1: %s Type 2: %s Potentiel evolution: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
    i, player->pkm.pkm_name, player->pkm.type1, player->pkm.type2,player->pkm.evolution, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
    player = player->next;
    i++;
  }
}

void push(Liste_t **p, t_pkm pkm)
{
        Liste_t *element = malloc(sizeof(Liste_t));
        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
        element->pkm = pkm;
        element->next = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

void Pop(Liste_t **p, t_pkm pkm)
{
        Liste_t *tmp;
        tmp = (*p)->next;
        pkm = (*p)->pkm;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
}

int Length(Liste_t *p)
{
        int n=0;
        while(p)
          {
              n++;
              p = p->next;
          }
        return n;
}

void affiche_Stats(Liste_t *player, t_pkm *wild_pkm){
  printf("<----------Joueur: ---------->\n Nom: %s \n Type 1: %s Type 2: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          player->pkm.pkm_name, player->pkm.type1, player->pkm.type2, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
  printf("<----------Adversaire---------->\n Nom: %s  Type 1: %s Type 2: %s \n \n Atk: %i, Def: %i, SpAtk: %i SpDef: %i, Sp: %i \n Talent : %s, Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          wild_pkm->pkm_name, wild_pkm->type1, wild_pkm->type2, wild_pkm->atk, wild_pkm->def, wild_pkm->spatk, wild_pkm->spdef, wild_pkm->sp, wild_pkm->talent, wild_pkm->hp, wild_pkm->mp, wild_pkm->lvl, wild_pkm->exp, wild_pkm->skill[0], wild_pkm->skill[1], wild_pkm->skill[2], wild_pkm->skill[3]);
}

void init_pkm_team(t_pkm *pkm, char nom_pkm[20]){ //inscrit le pokemon dans equipe
  FILE * file_stat;
  char dir[50] = "stat_pkm/";
  strcat(dir, nom_pkm);
  file_stat = fopen(dir, "r");
  fscanf(file_stat, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s",
  pkm->pkm_name, pkm->type1, pkm->type2,&pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3]);
  fclose(file_stat);
}

void rand_scale_stat(t_pkm *wild_pkm){
  srand(time(0));
  int lvl = rand() % (10-4)+4;
  wild_pkm->lvl = lvl;
  wild_pkm->mp += lvl*0.25;

  wild_pkm->atk += wild_pkm->atk*lvl*0.02;
  wild_pkm->def += wild_pkm->def*lvl*0.02;
  wild_pkm->spatk += wild_pkm->spatk*lvl*0.02;
  wild_pkm->spdef += wild_pkm->spdef*lvl*0.02;
  wild_pkm->sp += wild_pkm->sp*lvl*0.02;

}

void init_pkm_enemy(t_pkm *pkm){
  FILE * file;
  FILE * file_equipe;
  char dir[50] = "stat_pkm/";
  srand(time(0));
  int numFichier = rand() % 9+1;
  char convert_numFichier[12];
  sprintf(convert_numFichier, "%d", numFichier);
  strcat(convert_numFichier, ".txt");
  strcat(dir, convert_numFichier);
  file = fopen(dir, "r");
  fscanf(file, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s",
  pkm->pkm_name, pkm->type1, pkm->type2, &pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3]);
  fclose(file);
  rand_scale_stat(pkm);
}

void player_attack(Liste_t*player, t_pkm *wild_pkm,int choix){
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "atk/";
  char nom[50];
  char type1[50];
  int pow, acc, pp;
  int accuracy;
  //printf("Attaques disponibles: \n -%s -%s \n -%s -%s\n", player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
  //scanf("%s", choix);
  strcat(choice,player->pkm.skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %i %i %i", nom, type1, &pow, &acc, &pp);
  wild_pkm->hp -= pow;
  //printf("%s utilise %s\n", player->pkm.pkm_name, nom);
  fclose(file);
}

void enemy_attack(Liste_t *player, t_pkm *wild_pkm){
  player->pkm.hp -= wild_pkm->atk;
  printf("%s inflige %i à %s\n", wild_pkm->pkm_name,  wild_pkm->atk, player->pkm.pkm_name);
}

int player_choice(){
  int choix;
  printf("Action 1-Attaque ou 0-Fuir\n");
  scanf("%d", &choix);
  return choix;
}

int verif_fin_combat(Liste_t *player, t_pkm *wild_pkm){
  if (wild_pkm->hp < 0){  //joueur gagne
    return (2);
  }
  else if (player->pkm.hp < 0){ //joueur perd
    return (0);
  }
  else{
    return (1);
  }
}



int combat(Liste_t *player, t_pkm *wild_pkm){


  while(player->pkm.hp > 0 && wild_pkm->hp >0){

      enemy_attack(player, wild_pkm);
  }
  if(player->pkm.hp <= 0){
    printf("player est mort\n");
    return 1;
  }else if(wild_pkm->hp <=0){
    printf("Pokemon ennemi est mort\n");
    return 0;
  }

}
  /*

  if (verif_fin_combat(player->next, wild_pkm) == 1){
    printf("%s est K.O !\n", player->pkm.pkm_name);
    combat(player->next, wild_pkm);
  }
  else if (verif_fin_combat(player->next, wild_pkm) == 2){
    printf("Joueur a gagné!\n");
  }
  else if (verif_fin_combat(player->next, wild_pkm) == 0){
    printf("Joueur n'a plus de pokémon\n");
  }
}
/*
int main(){
  //Init test pkm sauvage
  t_pkm wild_pkm;
  init_pkm_enemy(&wild_pkm);

  t_pkm pkm;
  Liste_t * player;
  init_pkm_team(&pkm, "1.txt");
  push(&player, pkm);
  init_pkm_team(&pkm, "2.txt");
  push(&player, pkm);
  init_pkm_team(&pkm, "4.txt");
  push(&player, pkm);
  init_pkm_team(&pkm, "6.txt");
  push(&player, pkm);
  init_pkm_team(&pkm, "9.txt");
  push(&player, pkm);
  init_pkm_team(&pkm, "8.txt");
  push(&player, pkm);
  combat(player, &wild_pkm);
  print_list(player);
  return 0;
}*/
