/**
  * \file combat.c
  * \brief fichier de gestion de combat
  * \author Léon TER
  * \version 1
  * \date 28 mars 22
*/
#include "../include/global_structure.h"
#include "../include/window_render.h"
#include "../include/combat.h"
#include "../include/liste.h"

int init_combat(global_structure_t ** global_structure,int pkm_enemy_ids[5])
{
  int retour = 0;

  init_pkm_team(&(*global_structure)->pkm, "1.txt");

  inserDebut(&(*global_structure)->liste_player,(*global_structure)->pkm);

  init_pkm_team(&(*global_structure)->pkm, "3.txt");
  inserFin((*global_structure)->liste_player, (*global_structure)->pkm);
/*
  init_pkm_team(&(*global_structure)->pkm, "3.txt");
  inserFin((*global_structure)->liste_player, (*global_structure)->pkm);
*/
  init_pkm_team(&(*global_structure)->pkm, "7.txt");
  inserFin((*global_structure)->liste_player, (*global_structure)->pkm);

  init_pkm_team(&(*global_structure)->pkm, "5.txt");
  inserFin((*global_structure)->liste_player, (*global_structure)->pkm);

  init_pkm_team(&(*global_structure)->pkm, "6.txt");
  inserFin((*global_structure)->liste_player, (*global_structure)->pkm);


  return(retour);
}


/**
  * \function print_list
  * \brief Cette fonction permer de afficher tout les elements d'une liste de pokemon que le joueur possède.
  * \param player : liste du joueur
  */
void print_list(Liste_t * player) {
  int i = 0;
  while(player){
    printf("%d <----------Pokemon n%d: ---------->\n Nom: %s \n Type 1: %s Type 2: %s Potentiel evolution: %s \n Atk: %i, Def: %i, SpAtk: %i, SpDef: %i, Sp: %i \n Talent: %s \n Hp: %i  Mp: %i \n LvL: %i ExP: %i \n Attaques: %s %s %s %s \n",
    player->pkm.id, i, player->pkm.pkm_name, player->pkm.type1, player->pkm.type2,player->pkm.evolution, player->pkm.atk, player->pkm.def, player->pkm.spatk, player->pkm.spdef, player->pkm.sp, player->pkm.talent, player->pkm.hp, player->pkm.mp, player->pkm.lvl, player->pkm.exp, player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
    player = player->next;
    i++;
  }
}

int getPlayerPkmId(Liste_t * pl, int id){
  while(pl)
  {
    if (pl->pkm.id == id){
      return pl->pkm.pkmId;
    }
    pl = pl->next;
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
        while(p != NULL)
          {
              p = p->next;
              n++;
          }
        return n;
}

/**
  * \function inserDebut
  * \brief Cette fonction ajoute au debut de la liste un pokemon
  * \param player : liste de pokemon
  * \param pkm : le pokemon à inserer
  */
void inserDebut(Liste_t **p, t_pkm pkm)
{
        Liste_t *element = malloc(sizeof(Liste_t));
        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
        pkm.id = 1;
        element->pkm = pkm;
        element->next = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}

//inserFin((*global_structure)->liste_player, (*global_structure)->pkm);

/**
  * \function inserFin
  * \brief Cette fonction ajoute à la fin de la liste p un pokemon
  * \param player : liste de pokemon
  * \param pkm : le pokemon à inserer
  */
void inserFin(Liste_t *courant, t_pkm pkm){
    /* Input validation */
    if (courant == NULL) {
       printf("Erreur : pointeur sur element invalide\n");
       return;
    }
    pkm.id = Length(courant)+1;
    /* creation element */
    Liste_t* newEl =malloc(sizeof(Liste_t));
    newEl->pkm  = pkm;
    newEl->next = NULL;
    /* De l'element courant au dernier  */
    while(courant->next != NULL)
       courant = courant->next;
    /* Inserer nouvel element a la fin */
    courant->next = newEl;
}

/**
  * \function Pop
  * \brief Cette fonction Supprime un pokemon de la liste
  * \param player : liste de pokemon
  * \param pkm : le pokemon à supprimer
  */
void Pop(Liste_t **p, t_pkm pkm)
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
void affiche_Stats(Liste_t *player, t_pkm *wild_pkm)
{
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
t_pkm GetNth(Liste_t* head, int index)
{
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
int swapNodes(global_structure_t ** global_structure, int n1, int n2){
    Liste_t *prevNode1 = NULL, *prevNode2 = NULL, *node1 = (*global_structure)->liste_player, *node2 = (*global_structure)->liste_player, *temp = NULL;
    int tp;
    int retour = 0;
    //Verifier si la liste est null
    if((*global_structure)->liste_player == NULL) {
      retour = -1;
    }

    //Si n1 et n2 sont egaux, ne rien faire
    if(n1 == n2)
      retour = -1;

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
          (*global_structure)->liste_player  = node2;
        //Si l'element precedent de node2 n'est pas null, le pointer sur node1
        if(prevNode2 != NULL)
          prevNode2->next = node1;
        else
          (*global_structure)->liste_player  = node1;
        //Echange les elements de node1 et node2
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
      }
    }
    else
    {
        printf("L'echange n'est pas possible\n");
        retour = -1;
    }
    return(retour);
}

Liste_t * current_pkm(Liste_t *player, int index)
{
  //Liste_t * temp = player;
  for (int i = 0; i < index; i++){
    player = player -> next;
    //player -> next = temp;
  }
  return player;
}

/**
  * \function init_pkm_team
  * \brief Recupere les statistiques d'un pokemon allie pour son initialisation et inscrit le pokemon dans equipe
  * \param pkm : le pokemon
  * \param nom_pkm : le nom du pokemon
  */
void init_pkm_team(t_pkm *pkm, char nom_pkm[20])//inscrit le pokemon dans equipe
{
  FILE * file_stat;
  char dir[100] = "./src/asset/stat_pkm/";
  strcat(dir, nom_pkm);
  file_stat = fopen(dir, "r");

  if (file_stat == NULL)
  {
    printf("Erreur fichier stat pokemon \n");
  }

  fscanf(file_stat, "%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s %d",
  pkm->pkm_name, pkm->type1, pkm->type2,&pkm->atk, &pkm->def, &pkm->spatk, &pkm->spdef, &pkm->sp, pkm->talent, &pkm->hp, &pkm->mp, &pkm->lvl, &pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3],&pkm->pkmId);
  fclose(file_stat);
  pkm->hpMax = pkm->hp;
/*
  printf("%s %s %s %d %d %d %d %d %s %d %d %d %d %s %s %s %s %s %d\n----",
  pkm->pkm_name, pkm->type1, pkm->type2,pkm->atk, pkm->def, pkm->spatk, pkm->spdef, pkm->sp, pkm->talent, pkm->hp, pkm->mp, pkm->lvl, pkm->exp, pkm->evolution, pkm->skill[0], pkm->skill[1], pkm->skill[2], pkm->skill[3], pkm->pkmId);
*/
}

/**
  * \function rand_scale_stat
  * \brief Fait varier les statistiques d'un pokemon
  * \param pkm : le pokemon que l'on veut faire varier
  */
void rand_scale_stat(t_pkm *wild_pkm)
{
  int lvl = rand() % (10-4)+4;
  wild_pkm->lvl = lvl;
  wild_pkm->mp += lvl*0.25;

  wild_pkm->atk += wild_pkm->atk*lvl*0.02;
  wild_pkm->def += wild_pkm->def*lvl*0.02;
  wild_pkm->spatk += wild_pkm->spatk*lvl*0.02;
  wild_pkm->spdef += wild_pkm->spdef*lvl*0.02;
  wild_pkm->sp += wild_pkm->sp*lvl*0.02;

}

/**
  * \function init_pkm_team
  * \brief Recupere les statistiques d'un pokemon ennemi pour son initialisation
  * \param pkm : le pokemon que l'on veut initialiser
  */
void init_pkm_enemy(t_pkm *pkm,int numFichier2)
{
  FILE * file;
  FILE * file_equipe;
  char dir[100] = "./src/asset/stat_pkm/";
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
  * \function chercherMultiplicateur
  * \brief Lit depuis le fichier tableType.txt le multiplicateur associe a l'attaque
  * \param indices des types d'un type defensif et d'un type offensif
  */
float chercherMultiplicateur(int typePokemon1, int typeAttaque){
  FILE * fcherch;
  float a[20][20];
  int i, j;
  fcherch = fopen("./src/asset/atk/tableType.txt", "r");
  for (i = 0; i < 18; i++)
    for (j = 0; j < 18; j++)
      fscanf(fcherch, "%f", &a[i][j]);
  fclose(fcherch);
  return (a[typePokemon1][typeAttaque]);
}

/**
  * \function verifType
  * \brief Renvoie le multiplicateur de degats si attaque super efficace
  * \param 3 Types: typePokemon1 1er type du pokemon defensif, typePokemon 2eme type du pokemon defensif, typeAttaque type du pokemon offensif
  */
float verifType(char typePokemon1[50], char typePokemon2[50], char typeAttaque[50]){
  int typeAttaqueInt = 0;
  float multiplicateur = 0;
  if (strcmp(typeAttaque, "Acier") == 0) typeAttaqueInt = 0;
  else if (strcmp(typeAttaque, "Combat") == 0) typeAttaqueInt = 1;
  else if (strcmp(typeAttaque, "Dragon") == 0) typeAttaqueInt = 2;
  else if (strcmp(typeAttaque, "Eau") == 0) typeAttaqueInt = 3;
  else if (strcmp(typeAttaque, "Electrik") == 0) typeAttaqueInt = 4;
  else if (strcmp(typeAttaque, "Feu") == 0) typeAttaqueInt = 5;
  else if (strcmp(typeAttaque, "Glace") == 0) typeAttaqueInt = 6;
  else if (strcmp(typeAttaque, "Insecte") == 0) typeAttaqueInt = 7;
  else if (strcmp(typeAttaque, "Normal") == 0) typeAttaqueInt = 8;
  else if (strcmp(typeAttaque, "Plante") == 0) typeAttaqueInt = 9;
  else if (strcmp(typeAttaque, "Poison") == 0) typeAttaqueInt = 10;
  else if (strcmp(typeAttaque, "Psy") == 0) typeAttaqueInt = 11;
  else if (strcmp(typeAttaque, "Roche") == 0) typeAttaqueInt = 12;
  else if (strcmp(typeAttaque, "Sol") == 0) typeAttaqueInt = 13;
  else if (strcmp(typeAttaque, "Spectre") == 0) typeAttaqueInt = 14;
  else if (strcmp(typeAttaque, "Tenebre") == 0) typeAttaqueInt = 15;
  else if (strcmp(typeAttaque, "Vol") == 0) typeAttaqueInt = 16;
  if (strcmp(typePokemon1, "Acier") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 0);
  else if (strcmp(typePokemon1, "Combat") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 1);
  else if (strcmp(typePokemon1, "Dragon") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 2);
  else if (strcmp(typePokemon1, "Eau") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 3);
  else if (strcmp(typePokemon1, "Electrik") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 4);
  else if (strcmp(typePokemon1, "Feu") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 5);
  else if (strcmp(typePokemon1, "Glace") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 6);
  else if (strcmp(typePokemon1, "Insecte") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 7);
  else if (strcmp(typePokemon1, "Normal") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 8);
  else if (strcmp(typePokemon1, "Plante") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 9);
  else if (strcmp(typePokemon1, "Poison") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 10);
  else if (strcmp(typePokemon1, "Psy") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 11);
  else if (strcmp(typePokemon1, "Roche") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 12);
  else if (strcmp(typePokemon1, "Sol") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 13);
  else if (strcmp(typePokemon1, "Spectre") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 14);
  else if (strcmp(typePokemon1, "Tenebre") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 15);
  else if (strcmp(typePokemon1, "Vol") == 0) multiplicateur = chercherMultiplicateur(typeAttaqueInt, 16);
  if (strcmp(typePokemon2, "NULL") == 1){
    if (strcmp(typePokemon2, "Acier") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 0);
    else if (strcmp(typePokemon2, "Combat") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 1);
    else if (strcmp(typePokemon2, "Dragon") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 2);
    else if (strcmp(typePokemon2, "Eau") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 3);
    else if (strcmp(typePokemon2, "Electrik") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 4);
    else if (strcmp(typePokemon2, "Feu") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 5);
    else if (strcmp(typePokemon2, "Glace") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 6);
    else if (strcmp(typePokemon2, "Insecte") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 7);
    else if (strcmp(typePokemon2, "Normal") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 8);
    else if (strcmp(typePokemon2, "Plante") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 9);
    else if (strcmp(typePokemon2, "Poison") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 10);
    else if (strcmp(typePokemon2, "Psy") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 11);
    else if (strcmp(typePokemon2, "Roche") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 12);
    else if (strcmp(typePokemon2, "Sol") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 13);
    else if (strcmp(typePokemon2, "Spectre") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 14);
    else if (strcmp(typePokemon2, "Tenebre") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 15);
    else if (strcmp(typePokemon2, "Vol") == 0) multiplicateur *= chercherMultiplicateur(typeAttaqueInt, 16);
  }
  if (multiplicateur >= 2)
    printf("C'est super efficace\n");
  else if (multiplicateur < 1)
    printf("Ce n'est pas très efficace\n");
  return multiplicateur;
}

/**
  * \function getAttackEnnemi
  * \brief Fonction pour le okemon énnemi utilise une attaque contre le personnage
  * \param pl : la liste du joueur
  * \param wild_pkm : le pokemon énnemi
  */
void getAttackJoueur(Liste_t*player, t_pkm *wild_pkm,int choix)
{
  printf("%i\n",choix );
  FILE * file;
  char choice[50]= {"\0"};
  char dir[100] = "./src/asset/atk/";
  char nom[50];
  char type1[50];
  int acc;
  float pow;
  //printf("Attaques disponibles: \n -%s -%s \n -%s -%s\n", player->pkm.skill[0], player->pkm.skill[1], player->pkm.skill[2], player->pkm.skill[3]);
  //scanf("%s", choix);
  strcat(choice,player->pkm.skill[choix]);
  printf("choice %s\n",choice );
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");

  if (file == NULL)
  {
    printf("Erreur ouverture fichier des attaques\n");
  }

  fscanf(file, "%s %s %f %i", nom, type1, &pow, &acc);
  wild_pkm->hp -= (int)pow;
  printf("getAttackJoueur ---------- %s inflige %i a %s avec %s\n", player->pkm.pkm_name,  (int)pow, wild_pkm->pkm_name, player->pkm.skill[choix]);
  fclose(file);
}

/**
  * \function getAttackEnnemi
  * \brief Fonction pour le okemon énnemi utilise une attaque contre le personnage
  * \param pl : la liste du joueur
  * \param wild_pkm : le pokemon énnemi
  */
void getAttackEnnemi(Liste_t *pl, t_pkm *wild_pkm){
  printf("pokemon name %s\n",pl->pkm.pkm_name );
  printf("pokemon id %i\n",pl->pkm.id );
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "./src/asset/atk/";
  char nom[50];
  char type1[50];
  int acc;
  float pow;
  srand(time(NULL));
  int choix = (rand() % 4); //Choix de l'attaque entre 0 et 3
  strcat(choice,wild_pkm->skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %f %i", nom, type1, &pow, &acc);
  float multiplicateur = verifType(wild_pkm->type1, wild_pkm->type2, type1);
  pow*=(int)multiplicateur;
  pl->pkm.hp -= (int)pow;
  printf("getAttackEnnemi ---------- %s inflige %i a %s avec %s getAttackEnnemi\n", wild_pkm->pkm_name,  (int)pow, pl->pkm.pkm_name, wild_pkm->skill[choix]);
  fclose(file);
}

/**
  * \function verif_pkmEnVie
  * \brief Fonction qui verifie si tous les pokémons de la liste sont en vie
  * \param player : la liste du joueur
  * \return int : retourne 0 si tout les pokémons sont morts, 1 sinon
  */
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

/**
  * \function combat
  * \brief Fonction generale de combat par systeme de manche, inflige les degats et verifie l'etat de la manche
  * \param pl : la liste du joueur
  * \param wild_pkm : le pokémon ennemi
  * \param choix : le choix du joueur
  * \return int : retourne 1 si tout le pokémon adverse est Ko, 1 si le pokémon du joueur actuelle est KO, 2 si les tout les pokémons du joueur sont KO
  */
int combat(Liste_t *pl, t_pkm *wild_pkm, int choix){
  if(pl->pkm.hp > 0 && wild_pkm->hp > 0){
    getAttackJoueur(pl, wild_pkm, choix);
    if (wild_pkm->hp <= 0)
      return 1;
    getAttackEnnemi(pl, wild_pkm);
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

/**
	* \function initBilly
	* \brief Initialisation du dresseur adverse
	* \param liste : Liste de pkm du dresseur adverse
  * \param nomDress : nom du fichier du dresseur
  */
  /*
void initDresseur(Liste_t *liste, char nomDress[50])
{
  FILE *chercherDress;
  char dir[50] = "./src/asset/dress_ennemi/";
  char nomPkm[50];
  int lvl;
  t_pkm pkm;
  int total = 0;
  strcat(dir, nomDress);
  chercherDress = fopen(dir, "r");
  for (int i = 0; i < 3; i++)
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
*/
/**
  * \function getAttackJoueurDuel
  * \brief Fonction pour quand le personnage allie utilise une capacite contre pokemon de dresseur ennemi
  * \param player : la liste du joueur
  * \param ennemi : la liste du dresseur ennemi
  * \param choix : le choix apporté par l'utilisateur
  */
  /*
void getAttackJoueurDuel(Liste_t*pl, Liste_t *ennemi,int choix){
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "./src/asset/atk/";
  char nom[50];
  char type1[50];
  int acc;
  float pow;
  strcat(choice,pl->pkm.skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %f %i", nom, type1, &pow, &acc);
  float multiplicateur = verifType(ennemi->pkm.type1, ennemi->pkm.type2, type1);
  pow*=multiplicateur;
  ennemi->pkm.hp -= (int)pow;
  printf("%s inflige %i à %s avec %s getAttackJoueurDuel\n", pl->pkm.pkm_name,  (int)pow, ennemi->pkm.pkm_name, pl->pkm.skill[choix]);
  fclose(file);
}
*/
/**
  * \function getAttackEnnemiDuel
  * \brief Fonction pour le pokemon énnemi utilise une attaque contre le personnage
  * \param player : la liste du joueur
  * \param wild_ennemipkm : la liste du dresseur ennemi
  */
  /*
void getAttackEnnemiDuel(Liste_t *pl, Liste_t *ennemi){
  FILE * file;
  char choice[50]= {"\0"};
  char dir[50] = "./src/asset/atk/";
  char nom[50];
  char type1[50];
  int acc;
  float pow;
  srand(time(NULL));
  int choix = (rand() % 4); //Choix de l'attaque entre 0 et 3
  printf("CHOIX : %d\n", choix);
  strcat(choice,ennemi->pkm.skill[choix]);
  strcat(choice, ".txt");
  strcat(dir, choice);
  file=fopen(dir, "r");
  fscanf(file, "%s %s %f %i", nom, type1, &pow, &acc);
  float multiplicateur = verifType(pl->pkm.type1, pl->pkm.type2, type1);
  pow*=multiplicateur;
  pl->pkm.hp -= (int)pow;
  printf("%s ennemi inflige %i à %s avec %s getAttackEnnemiDuel\n", ennemi->pkm.pkm_name,  (int)pow, pl->pkm.pkm_name, ennemi->pkm.skill[choix]);
  fclose(file);
}
*/

/**
  * \function combatDresseur
  * \brief Fonction generale de combat par systeme de manche, inflige les degats et verifie l'etat de la manche
  * \param player : la liste du joueur
  * \param ennemi : la liste du dresseur ennemi
  * \param choix : le choix du joueur
  * \return int : retourne 1 si tout le pokémon adverse est Ko, 1 si le pokémon du joueur actuelle est KO, 2 si les tout les pokémons du joueur sont KO
  */
  /*
int combatDresseur(Liste_t *pl, Liste_t *ennemi, int choix){
  if(pl->pkm.hp > 0 && ennemi->pkm.hp > 0){
    getAttackJoueurDuel(pl, ennemi, choix);
    if (ennemi->pkm.hp <= 0 && verif_pkmEnVie(ennemi) == 0)
      return 1;
    else if (ennemi->pkm.hp <= 0 && verif_pkmEnVie(ennemi) == 1){
      return 3;
    }
    else{
      getAttackEnnemi(pl, &ennemi->pkm);
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
*/

int capturer(global_structure_t ** global_structure, Liste_t *player, t_pkm wild_pkm)
{
  int proba = rand() % 2;
  if (proba == 0){
    printf("rate\n");
    strncpy((*global_structure)->menu->speech_bubble_text,"La capture a rate !",19);
    (*global_structure)->menu->speech_bubble = 1;
    return 0;
  }
  else if (proba == 1 && Length(player) <  6){
    inserFin(player, wild_pkm);
    printf("La capture a fonctionne\n");
    strncpy((*global_structure)->menu->speech_bubble_text,"La capture a fonctionne !",25);
    (*global_structure)->menu->speech_bubble = 1;
    return 1;
  }
  else{
    printf("CA MARCHE PAS\n");
    strncpy((*global_structure)->menu->speech_bubble_text,"Vous avez deja 6 pokemon !",26);
    (*global_structure)->menu->speech_bubble = 1;
  }
}

int soin(Liste_t *player)
{
  while(player){
    player->pkm.hp = player->pkm.hpMax;
    player = player->next;
  }
  return 1;
}
