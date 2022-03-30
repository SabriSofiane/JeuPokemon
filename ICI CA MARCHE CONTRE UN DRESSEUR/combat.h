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

//cva marche mais c'est moche EN FAIT FAUT CHANGER LA VALEUR DU i SELON LE NBR DE PKM DU DRESSEUR DSL
/**
	* \function initBilly
	* \Initialisation du dresseur adverse
	* \param liste Liste de pkm du dresseur adverse, nomDress nom du fichier du dresseur  
**/
void initBilly(Liste_t *liste, char nomDress[50])
{
  FILE *chercherDress;
  char dir[50] = "dress_ennemi/";
  char nomPkm[50];
  int lvl;
  t_pkm pkm;
  int total = 0;
  strcat(dir, nomDress);
  chercherDress = fopen(dir, "r");
  
  for (int i = 0; i < 2; i++)
  {
    fscanf(chercherDress, "%s %i", nomPkm, &lvl);
    init_pkm_team(&pkm, nomPkm);
    pkm.lvl = lvl;
    if(liste == NULL)
    {
      inserDebut(&liste, pkm);
    }
    else
    {
      inserFin(liste, pkm);
    }
  }
  fclose(chercherDress);
  testEnnemi = liste;
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

//Personnage allie utilise une capacite contre ennemi
void pl_attack2(Liste_t*pl, Liste_t *ennemi,int choix){
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
  ennemi->pkm.hp -= pow;
  printf("%s inflige %i à %s avec %s\n", pl->pkm.pkm_name,  pow, ennemi->pkm.pkm_name, pl->pkm.skill[choix]);
  fclose(file);
}

//Personnage allie utilise une capacite contre ennemi
void enemy_attack2(Liste_t *pl, Liste_t *ennemi){
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
  strcat(choice,ennemi->pkm.skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %i %i %i", nom, type1, &pow, &acc, &pp);
  pl->pkm.hp -= pow;
  printf("%s ennemi inflige %i à %s avec %s\n", ennemi->pkm.pkm_name,  pow, pl->pkm.pkm_name, ennemi->pkm.skill[choix]);
  fclose(file);
}

/*
  je fais les test pour les dresseurs adverse
*/
int combat2(Liste_t *pl, Liste_t *ennemi, int choix){
  if(pl->pkm.hp > 0 && ennemi->pkm.hp > 0){
    printf("ON VA ATTAQUER\n");
    pl_attack2(pl, ennemi, choix);
    if (ennemi->pkm.hp <= 0 && verif_pkmEnVie(ennemi) == 0)
      return 1;
    else if (ennemi->pkm.hp <= 0 && verif_pkmEnVie(ennemi) == 1){
      printf("C'EST LE RETOUR OU PKM SUIVANT \n");
      return 3;
    }
    else{
      enemy_attack(pl, &ennemi->pkm);
    }
  }
  if (pl->pkm.hp <= 0 && verif_pkmEnVie(pl) == 1){
    printf("%s est K.O !\n", pl->pkm.pkm_name);
    return (2);
  }
  if (pl->pkm.hp <= 0 && verif_pkmEnVie(pl) == 0)
    return 0;
  else{
    return 3;
  }
}
