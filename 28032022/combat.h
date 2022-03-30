//Affiche tous les elements d' une liste de pokemon
void print_list(Liste_t * pl)
{ //
  int i = 1;
  while(pl)
  {
    printf("%d <----------Pokémon n°%d: ---------->\n Nom: %s \n Type 1: %s Type 2: %s Potentiel evolution: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
    pl->pkm.id, i, pl->pkm.pkm_name, pl->pkm.type1, pl->pkm.type2,pl->pkm.evolution, pl->pkm.atk, pl->pkm.def, pl->pkm.spatk, pl->pkm.spdef, pl->pkm.sp, pl->pkm.talent, pl->pkm.hp, pl->pkm.mp, pl->pkm.lvl, pl->pkm.exp, pl->pkm.skill[0], pl->pkm.skill[1], pl->pkm.skill[2], pl->pkm.skill[3]);
    pl = pl->next;
    i++;
  }
}

//Renvoie la longueur d'une liste de pokemon
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

//Ajoute au debut de la liste p un pokemon
void inserDebut(Liste_t **p, t_pkm pkm)
{
        Liste_t *element = malloc(sizeof(Liste_t));
        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
        pkm.id = 1;
        element->pkm = pkm;
        element->next = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

//Ajoute a la fin de la liste p un pokemon
void inserFin(Liste_t *head, t_pkm pkm){
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

//Supprime pokemon de la liste
void suppr(Liste_t **p, t_pkm pkm)
{
        Liste_t *tmp;
        tmp = (*p)->next;
        pkm = (*p)->pkm;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
}

//Affiche les statistiques des pokemons sur le terrain
void affiche_Stats(Liste_t *pl, t_pkm *wild_pkm){
  printf("<----------Joueur: ---------->\n Nom: %s \n Type 1: %s Type 2: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          pl->pkm.pkm_name, pl->pkm.type1, pl->pkm.type2, pl->pkm.atk, pl->pkm.def, pl->pkm.spatk, pl->pkm.spdef, pl->pkm.sp, pl->pkm.talent, pl->pkm.hp, pl->pkm.mp, pl->pkm.lvl, pl->pkm.exp, pl->pkm.skill[0], pl->pkm.skill[1], pl->pkm.skill[2], pl->pkm.skill[3]);
  printf("<----------Adversaire---------->\n Nom: %s  Type 1: %s Type 2: %s \n \n Atk: %i, Def: %i, SpAtk: %i SpDef: %i, Sp: %i \n Talent : %s, Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          wild_pkm->pkm_name, wild_pkm->type1, wild_pkm->type2, wild_pkm->atk, wild_pkm->def, wild_pkm->spatk, wild_pkm->spdef, wild_pkm->sp, wild_pkm->talent, wild_pkm->hp, wild_pkm->mp, wild_pkm->lvl, wild_pkm->exp, wild_pkm->skill[0], wild_pkm->skill[1], wild_pkm->skill[2], wild_pkm->skill[3]);
}

//Renvoie le pokemon a la place 'index' de la liste
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

/*Echange la place entre deux pokemon dans la liste
  Renvoie 1 si l'echange est possible ou 0 sinon
*/
int swapNodes(int n1, int n2){
    Liste_t *prevNode1 = NULL, *prevNode2 = NULL, *node1 = player, *node2 = player, *temp = NULL;
    int tp;
    //Verifier si la liste est null
    if(player == NULL) {
        return 0;
    }

    //Si n1 et n2 sont egaux, ne rien faire
    if(n1 == n2)
        return 0;

    //Chercher pour l'element n1
    while(node1 != NULL && node1->pkm.id != n1){
        prevNode1 = node1;
        node1 = node1->next;
    }

    //Chercher pour l'element n2
    while(node2 != NULL && node2->pkm.id != n2){
        prevNode2 = node2;
        node2 = node2->next;
    }
    if (node2->pkm.hp > 0)
    {
      tp = node2->pkm.id;
      node2->pkm.id = node1->pkm.id;
      node1->pkm.id = tp;
      if(node1 != NULL && node2 != NULL)
      {
        //Si l'element precedent de node1 n'est pas null, le pointer sur node2
        if(prevNode1 != NULL)
          prevNode1->next = node2;
        else
          player  = node2;
        //Si l'element precedent de node2 n'est pas null, le pointer sur node1
        if(prevNode2 != NULL)
          prevNode2->next = node1;
        else
          player  = node1;
        //Echange les elements de node1 et node2
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
        return 1;
      }
    }
    else
    {
        printf("L'echange n'est pas possible\n");
        return 0;
    }
}

//Recupere les statistiques d'un pokemon allie pour son initialisation
void init_pkm_team(Liste_t* pl, t_pkm *pkm, char nom_pkm[20]){ //inscrit le pokemon dans equipe
  FILE * file_stat;
  char dir[50] = "stat_pkm/";
  strcat(dir, nom_pkm);
  file_stat = fopen(dir, "r");
  fscanf(file_stat, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s %d",
  pkm->pkm_name, pkm->type1, pkm->type2,&pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3],&pkm->pkmId);
  fclose(file_stat);
  pkm->hpMax = pkm->hp;
}

//Fait varier les statistiques d'un pokemon
void rand_scale_stat(t_pkm *pkm){
  srand(time(0));
  int lvl = rand() % (10-4)+4;
  pkm->lvl = lvl;
  pkm->mp += lvl*0.25;

  pkm->atk += pkm->atk*lvl*0.02;
  pkm->def += pkm->def*lvl*0.02;
  pkm->spatk += pkm->spatk*lvl*0.02;
  pkm->spdef += pkm->spdef*lvl*0.02;
  pkm->sp += pkm->sp*lvl*0.02;

}

//Recupere les statistiques d'un pokemon ennemi pour son initialisation
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

//Cherche le multiplicateur de dégats dans la table des types
int chercherMultiplicateur(int typePokemon1, int typeAttaque){
  FILE * fcherch;
  int a[16][16];
  int i, j;
  fcherch = fopen("atk/tableType.txt", "r");
  for (i = 0; i < typePokemon1; i++)
    for (j = 0; j < typeAttaque; j++)
      fscanf(fcherch, "%d", &a[i][j]);
  fclose(fcherch);
  return a[i][j];
}

//Renvoie le multiplicateur de degats selon les types
int verifType(char typePokemon1[50], char typePokemon2[50], char typeAttaque[50]){
  int typeAttaqueInt;
  int multiplicateur = 0;
  //RENVOIE INDICE DE typeAttaque
  if (strcmp(typeAttaque, "Acier")) typeAttaqueInt = 0;
  else if (strcmp(typeAttaque, "Combat")) typeAttaqueInt = 1;
  else if (strcmp(typeAttaque, "Dragon")) typeAttaqueInt = 2;
  else if (strcmp(typeAttaque, "Eau")) typeAttaqueInt = 3;
  else if (strcmp(typeAttaque, "Electrik")) typeAttaqueInt = 4;
  else if (strcmp(typeAttaque, "Feu")) typeAttaqueInt = 5;
  else if (strcmp(typeAttaque, "Glace")) typeAttaqueInt = 6;
  else if (strcmp(typeAttaque, "Insecte")) typeAttaqueInt = 7;
  else if (strcmp(typeAttaque, "Normal")) typeAttaqueInt = 8;
  else if (strcmp(typeAttaque, "Plante")) typeAttaqueInt = 9;
  else if (strcmp(typeAttaque, "Poison")) typeAttaqueInt = 10;
  else if (strcmp(typeAttaque, "Psy")) typeAttaqueInt = 11;
  else if (strcmp(typeAttaque, "Roche")) typeAttaqueInt = 12;
  else if (strcmp(typeAttaque, "Sol")) typeAttaqueInt = 13;
  else if (strcmp(typeAttaque, "Spectre")) typeAttaqueInt = 14;
  else if (strcmp(typeAttaque, "Tenebre")) typeAttaqueInt = 15;
  else if (strcmp(typeAttaque, "Vol")) typeAttaqueInt = 16;

  if (strcmp(typePokemon1, "Acier")) multiplicateur = chercherMultiplicateur(0, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Combat")) multiplicateur = chercherMultiplicateur(1, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Dragon")) multiplicateur = chercherMultiplicateur(2, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Eau")) multiplicateur = chercherMultiplicateur(3, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Electrik")) multiplicateur = chercherMultiplicateur(4, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Feu")) multiplicateur = chercherMultiplicateur(5, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Glace")) multiplicateur = chercherMultiplicateur(6, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Insecte")) multiplicateur = chercherMultiplicateur(7, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Normal")) multiplicateur = chercherMultiplicateur(8, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Plante")) multiplicateur = chercherMultiplicateur(9, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Poison")) multiplicateur = chercherMultiplicateur(10, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Psy")) multiplicateur = chercherMultiplicateur(11, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Roche")) multiplicateur = chercherMultiplicateur(12, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Sol")) multiplicateur = chercherMultiplicateur(13, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Spectre")) multiplicateur = chercherMultiplicateur(14, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Tenebre")) multiplicateur = chercherMultiplicateur(15, typeAttaqueInt);
  else if (strcmp(typePokemon1, "Vol")) multiplicateur = chercherMultiplicateur(16, typeAttaqueInt);

  if (!typePokemon2){
    if (strcmp(typePokemon2, "Acier")) multiplicateur *= chercherMultiplicateur(0, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Combat")) multiplicateur *= chercherMultiplicateur(1, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Dragon")) multiplicateur *= chercherMultiplicateur(2, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Eau")) multiplicateur *= chercherMultiplicateur(3, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Electrik")) multiplicateur *= chercherMultiplicateur(4, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Feu")) multiplicateur *= chercherMultiplicateur(5, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Glace")) multiplicateur *= chercherMultiplicateur(6, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Insecte")) multiplicateur *= chercherMultiplicateur(7, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Normal")) multiplicateur *= chercherMultiplicateur(8, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Plante")) multiplicateur *= chercherMultiplicateur(9, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Poison")) multiplicateur *= chercherMultiplicateur(10, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Psy")) multiplicateur *= chercherMultiplicateur(11, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Roche")) multiplicateur *= chercherMultiplicateur(12, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Sol")) multiplicateur *= chercherMultiplicateur(13, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Spectre")) multiplicateur *= chercherMultiplicateur(14, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Tenebre")) multiplicateur *= chercherMultiplicateur(15, typeAttaqueInt);
    else if (strcmp(typePokemon2, "Vol")) multiplicateur *= chercherMultiplicateur(16, typeAttaqueInt);
  }
}

//Personnage allie utilise une capacite contre ennemi
void pl_attack(Liste_t*pl, t_pkm *wild_pkm,int choix){
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "atk/";
  char nom[50];
  char type1[50];
  int pow, acc, pp;
  int accuracy;
  strcat(choice,pl->pkm.skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %i %i %i", nom, type1, &pow, &acc, &pp);
  wild_pkm->hp -= pow;
  printf("%s inflige %i à %s avec %s\n", pl->pkm.pkm_name,  pow, wild_pkm->pkm_name, pl->pkm.skill[choix]);
  fclose(file);
}

//Personnage allie utilise une capacite contre ennemi
void enemy_attack(Liste_t *pl, t_pkm *wild_pkm){
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "atk/";
  char nom[50];
  char type1[50];
  int pow, acc, pp;
  int accuracy;
  srand(time(NULL));
  int choix = (rand() % 4); //Choix de l'attaque entre 0 et 3
  printf("CHOIX : %d\n", choix);
  strcat(choice,wild_pkm->skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %i %i %i", nom, type1, &pow, &acc, &pp);
  pl->pkm.hp -= pow;
  printf("%s inflige %i à %s avec %s\n", pl->pkm.pkm_name,  pow, wild_pkm->pkm_name, pl->pkm.skill[choix]);
  fclose(file);
}

//Verif si tous les pokemon de la liste sont en vie
int verif_pkmEnVie(Liste_t *pl){
  int count = 0;
  int length = Length(pl);
  while(pl){
    if (pl->pkm.hp <= 0)
      count++;
    pl = pl->next;
  }
  if (count == length) return 0;  //si tosu les pokemon sont morts
  else return 1;
}

/*
  Fonction generale de combat par systeme de manche
  Inflige les degats et verifie l'etat de la manche
*/
int combat(Liste_t *pl, t_pkm *wild_pkm, int choix){
  if(pl->pkm.hp > 0 && wild_pkm->hp > 0){
    pl_attack(pl, wild_pkm, choix);
    if (wild_pkm->hp <= 0)
      return 1;
    enemy_attack(pl, wild_pkm);
  }
  if (pl->pkm.hp <= 0 && verif_pkmEnVie(pl) == 1){
    printf("%s est K.O !\n", pl->pkm.pkm_name);
    return (2);
  }
  if (pl->pkm.hp <= 0 && verif_pkmEnVie(pl) == 0)
    return 0;
  else
    return 3;
}
