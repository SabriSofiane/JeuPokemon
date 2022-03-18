void print_list(Liste_t * player) {
  int i = 1;
  while(player){
    printf("%d <----------Pokémon n°%d: ---------->\n Nom: %s \n Type 1: %s Type 2: %s Potentiel evolution: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
    player->pkm.id, i, player->pkm.pkm_name, player->pkm.type1, player->pkm.type2,player->pkm.evolution, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
    player = player->next;
    i++;
  }
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

void push(Liste_t **p, t_pkm pkm) //push debut
{
        Liste_t *element = malloc(sizeof(Liste_t));
        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
        pkm.id = 1;
        element->pkm = pkm;
        element->next = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

void insertAtEnd(Liste_t *head, t_pkm pkm){
    /* Input validation */
    if (head == NULL) {
       printf("Error : Invalid node pointer !!!\n");
       return;
    }
    pkm.id = Length(head)+1;
    /* creates a new node */
    Liste_t* newNode =malloc(sizeof(Liste_t));
    newNode->pkm  = pkm;
    newNode->next = NULL;
    /* Traverse from head to last node  */
    while(head->next != NULL)
       head = head->next;
    /* Insert newNode after Tail node */
    head->next = newNode;
}

void Pop(Liste_t **p, t_pkm pkm)
{
        Liste_t *tmp;
        tmp = (*p)->next;
        pkm = (*p)->pkm;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
}

void affiche_Stats(Liste_t *player, t_pkm *wild_pkm){
  printf("<----------Joueur: ---------->\n Nom: %s \n Type 1: %s Type 2: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          player->pkm.pkm_name, player->pkm.type1, player->pkm.type2, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
  printf("<----------Adversaire---------->\n Nom: %s  Type 1: %s Type 2: %s \n \n Atk: %i, Def: %i, SpAtk: %i SpDef: %i, Sp: %i \n Talent : %s, Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          wild_pkm->pkm_name, wild_pkm->type1, wild_pkm->type2, wild_pkm->atk, wild_pkm->def, wild_pkm->spatk, wild_pkm->spdef, wild_pkm->sp, wild_pkm->talent, wild_pkm->hp, wild_pkm->mp, wild_pkm->lvl, wild_pkm->exp, wild_pkm->skill[0], wild_pkm->skill[1], wild_pkm->skill[2], wild_pkm->skill[3]);
}

t_pkm GetNth(Liste_t* head, int index){
    Liste_t* current = head;

    int count = 0;
    while (current) {
        if (count == index)
            return (current->pkm);
        count++;
        current = current->next;
    }
}

void swapNodes(int n1, int n2){
    Liste_t *prevNode1 = NULL, *prevNode2 = NULL, *node1 = player, *node2 = player, *temp = NULL;
    int tp;
    //Checks if list is empty
    if(player == NULL) {
        return;
    }

    //If n1 and n2 are equal, then list will remain the same
    if(n1 == n2)
        return;

    //Search for node1
    while(node1 != NULL && node1->pkm.id != n1){
        prevNode1 = node1;
        node1 = node1->next;
    }

    //Search for node2
    while(node2 != NULL && node2->pkm.id != n2){
        prevNode2 = node2;
        node2 = node2->next;
    }
    tp = node2->pkm.id;
    node2->pkm.id = node1->pkm.id;
    node1->pkm.id = tp;
    if(node1 != NULL && node2 != NULL) {
        //If previous node to node1 is not null then, it will point to node2
        if(prevNode1 != NULL){
            prevNode1->next = node2;
        }
        else{
            player  = node2;
        }
        //If previous node to node2 is not null then, it will point to node1
        if(prevNode2 != NULL)
            prevNode2->next = node1;
        else{
            player  = node1;
        }
        //Swaps the next nodes of node1 and node2
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
    else{
        printf("Swapping is not possible\n");
    }
}

Liste_t * current_pkm(Liste_t *player, int index){
  //Liste_t * temp = player;
  for (int i = 0; i < index; i++){
    player = player -> next;
    //player -> next = temp;
  }
  return player;
}

void init_pkm_team(t_pkm *pkm, char nom_pkm[20]){ //inscrit le pokemon dans equipe
  FILE * file_stat;
  char dir[50] = "stat_pkm/";
  strcat(dir, nom_pkm);
  file_stat = fopen(dir, "r");
  fscanf(file_stat, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s %d",
  pkm->pkm_name, pkm->type1, pkm->type2,&pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3],&pkm->pkmId);
  fclose(file_stat);
  pkm->hpMax = pkm->hp;
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
  fscanf(file, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s %d",
  pkm->pkm_name, pkm->type1, pkm->type2, &pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3],&pkm->pkmId);
  fclose(file);
  rand_scale_stat(pkm);
  pkm->hpMax = pkm->hp;
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
  printf("%s inflige %i à %s avec %s\n", player->pkm.pkm_name,  pow, wild_pkm->pkm_name, player->pkm.skill[choix]);
  fclose(file);
}
void getAttackJoueur(Liste_t*player, t_pkm *wild_pkm,int choix)
{
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
  fscanf(file, "%i", &pow);
  wild_pkm->hp -= pow;
  printf("%s inflige %i à %s avec %s\n", player->pkm.pkm_name,  pow, wild_pkm->pkm_name, player->pkm.skill[choix]);
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

int verif_fin_combat(Liste_t *player){
  int count = 0;
  int length = Length(player);
  while(player){
    if (player->pkm.hp <= 0)
      count++;
  }
  if (count == length) return 0;
  else return 1;
}



int combat(Liste_t *player, t_pkm *wild_pkm, int choix){
  if(player->pkm.hp > 0 && wild_pkm->hp > 0){
    player_attack(player, wild_pkm, choix);
    if (wild_pkm->hp <= 0)
      return 0;
    enemy_attack(player, wild_pkm);
  }
  if (player->pkm.hp <= 0 && player->next->pkm.hp > 0){
    printf("%s est K.O !\n", player->pkm.pkm_name);
    return (2);
  }
  else
    return 3;
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
