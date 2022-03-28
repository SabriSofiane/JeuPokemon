/**
  * \file combat.h
  * \brief fichier de gestion de combat
  * \author Léon TER
  * \version 0.5
  * \date 28 mars 22
*/





/**
  * \function print_list
  * \brief Cette fonction permer de afficher tout les elements d'une liste de pokemon que le joueur possède.
  * \param player : liste du joueur
  */

void print_list(Liste_t * player)
{ //
  int i = 1;
  while(player)
  {
    printf("%d <----------Pokémon n°%d: ---------->\n Nom: %s \n Type 1: %s Type 2: %s Potentiel evolution: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
    player->pkm.id, i, player->pkm.pkm_name, player->pkm.type1, player->pkm.type2,player->pkm.evolution, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
    player = player->next;
    i++;
  }
}

/**
  * \function length
  * \brief Cette fonction Renvoie la longueur d'une liste de pokemon
  * \param player : liste de pokemon
  */

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

/**
  * \function inserDebut
  * \brief Cette fonction ajoute au debut de la liste un pokemon
  * \param player : liste de pokemon
  * \param pkm : le pokemon à inserer
  */
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

/**
  * \function inserFin
  * \brief Cette fonction ajoute à la fin de la liste p un pokemon
  * \param player : liste de pokemon
  * \param pkm : le pokemon à inserer
  */
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

/**
  * \function suppr
  * \brief Cette fonction Supprime un pokemon de la liste
  * \param player : liste de pokemon
  * \param pkm : le pokemon à supprimer
  */

void suppr(Liste_t **p, t_pkm pkm)
{
        Liste_t *tmp;
        tmp = (*p)->next;
        pkm = (*p)->pkm;
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
}

/**
  * \function affiche_Stats
  * \brief Cette fonction affiche les statistiques des pokemons sur le terrain
  * \param player : liste de pokemon
  * \param wild_pkm : le pokémon que l'on veut afficher
  */

void affiche_Stats(Liste_t *player, t_pkm *wild_pkm){
  printf("<----------Joueur: ---------->\n Nom: %s \n Type 1: %s Type 2: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          player->pkm.pkm_name, player->pkm.type1, player->pkm.type2, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
  printf("<----------Adversaire---------->\n Nom: %s  Type 1: %s Type 2: %s \n \n Atk: %i, Def: %i, SpAtk: %i SpDef: %i, Sp: %i \n Talent : %s, Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
          wild_pkm->pkm_name, wild_pkm->type1, wild_pkm->type2, wild_pkm->atk, wild_pkm->def, wild_pkm->spatk, wild_pkm->spdef, wild_pkm->sp, wild_pkm->talent, wild_pkm->hp, wild_pkm->mp, wild_pkm->lvl, wild_pkm->exp, wild_pkm->skill[0], wild_pkm->skill[1], wild_pkm->skill[2], wild_pkm->skill[3]);
}

/**
  * \function GetNth
  * \brief Cette fonction renvoie le pokemon a la place 'index' de la liste
  * \param head : tête de la liste
  * \param index : l'index de la liste
  * \return t_pkm : retourne le pokemon
  */

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

/**
  * \function swapNodes
  * \brief Echange la place entre deux pokemon dans la liste
  * \param n1 : le premier pokemon
  * \param n2 : le deuxième pokemon
  * \return int : Renvoie 1 si l'echange est possible ou 0 sinon
  */
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

/**
  * \function init_pkm_team
  * \brief Recupere les statistiques d'un pokemon allie pour son initialisation et inscrit le pokemon dans equipe
  * \param pkm : le pokemon
  * \param nom_pkm : le nom du pokemon
  */

void init_pkm_team(t_pkm *pkm, char nom_pkm[20]){
  FILE * file_stat;
  char dir[50] = "stat_pkm/";
  strcat(dir, nom_pkm);
  file_stat = fopen(dir, "r");
  fscanf(file_stat, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s %d",
  pkm->pkm_name, pkm->type1, pkm->type2,&pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3],&pkm->pkmId);
  fclose(file_stat);
  pkm->hpMax = pkm->hp;
}

/**
  * \function rand_scale_stat
  * \brief Fait varier les statistiques d'un pokemon
  * \param pkm : le pokemon que l'on veut faire varier
  */

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
/**
  * \function init_pkm_team
  * \brief Recupere les statistiques d'un pokemon ennemi pour son initialisation
  * \param pkm : le pokemon que l'on veut initialiser
  */
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

/**
  * \function init_pkm_team
  * \brief Fonction pour quand le personnage allie utilise une capacite contre ennemi
  * \param player : la liste du joueur
  * \param wild_pkm : le pokemon énnemi
  * \param choix : le choix apporté par l'utilisateur
  */

void player_attack(Liste_t*player, t_pkm *wild_pkm,int choix){
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "atk/";
  char nom[50];
  char type1[50];
  int pow, acc, pp;
  int accuracy;
  strcat(choice,player->pkm.skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %i %i %i", nom, type1, &pow, &acc, &pp);
  wild_pkm->hp -= pow;
  printf("%s inflige %i à %s avec %s\n", player->pkm.pkm_name,  pow, wild_pkm->pkm_name, player->pkm.skill[choix]);
  fclose(file);
}

/**
  * \function enemy_attack
  * \brief Fonction pour le okemon énnemi utilise une attaque contre le personnage
  * \param player : la liste du joueur
  * \param wild_pkm : le pokemon énnemi
  */
void enemy_attack(Liste_t *player, t_pkm *wild_pkm){
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
  player->pkm.hp -= pow;
  printf("%s inflige %i à %s avec %s\n", player->pkm.pkm_name,  pow, wild_pkm->pkm_name, player->pkm.skill[choix]);
  fclose(file);
}

/**
  * \function verif_pkmEnVie
  * \brief Fonction qui verifie si tous les pokémons de la liste sont en vie
  * \param player : la liste du joueur
  * \return int : retourne 0 si tout les pokémons sont morts, 1 sinon
  */

int verif_pkmEnVie(Liste_t *player){
  int count = 0;
  int length = Length(player);
  while(player){
    if (player->pkm.hp <= 0)
      count++;
    player = player->next;
  }
  if (count == length) return 0;  //si tous les pokemons sont morts
  else return 1;
}

//jsp si ca marche
void initBilly(Liste_t *liste, char nomDress[50])
{
  FILE *chercherDress;
  char dir[50] = "dress_ennemi/";
  char nomPkm[50];
  int lvl;
  t_pkm *pkm;
  strcat(dir, nomDress);
  chercherDress = fopen(dir, "r");
  while (!feof(chercherDress))
  {
    fscanf(chercherDress, "%s %i", nomPkm, &lvl);
    init_pkm_team(pkm, nomPkm);
    pkm->lvl = lvl;
    inserFin(liste, *pkm);
  }
  fclose(chercherDress);
}

/**
  * \function combat
  * \brief Fonction generale de combat par systeme de manche, inflige les degats et verifie l'etat de la manche
  * \param player : la liste du joueur
  * \param wild_pkm : le pokémon ennemi
  * \param choix : le choix du joueur
  * \return int : retourne 1 si tout le pokémon adverse est Ko, 1 si le pokémon du joueur actuelle est KO, 2 si les tout les pokémons du joueur sont KO
  */

int combat(Liste_t *player, t_pkm *wild_pkm, int choix){
  if(player->pkm.hp > 0 && wild_pkm->hp > 0){
    player_attack(player, wild_pkm, choix);
    if (wild_pkm->hp < 0)
      return 1;
    enemy_attack(player, wild_pkm);
  }
  if (player->pkm.hp <= 0 && verif_pkmEnVie(player) == 1){
    printf("%s est K.O !\n", player->pkm.pkm_name);
    return (2);
  }
  if (player->pkm.hp <= 0 && verif_pkmEnVie(player) == 0)
    return 0;
  else
    return 3;
}

/*
  je fais les test pour les dresseurs adverse
*/
int combat2(Liste_t *player, Liste_t *ennemi, int choix){
  if(player->pkm.hp > 0 && &ennemi->pkm.hp > 0){
    player_attack(player, &ennemi->pkm, choix);
    if (ennemi->pkm.hp < 0 && verif_pkmEnVie(ennemi) == 0)
      return 1;
    enemy_attack(player, &ennemi->pkm);
  }
  if (player->pkm.hp <= 0 && verif_pkmEnVie(player) == 1){
    printf("%s est K.O !\n", player->pkm.pkm_name);
    return (2);
  }
  if (player->pkm.hp <= 0 && verif_pkmEnVie(player) == 0)
    return 0;
  else{
    if (verif_pkmEnVie(ennemi) == 1)
      ennemi = ennemi->next;
    return 3;
  }
}
