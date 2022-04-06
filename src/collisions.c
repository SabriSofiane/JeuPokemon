/**
  * \file collision.c
  * \brief fichier dédié pour les collisions par rapport au joueur et un élément du monde.
  * \author Elias OKAT
  * \version 1
  * \date 28 mars 2022
*/
#include "../include/global_structure.h"
#include "../include/collisions.h"
#include "../include/string_matrice.h"
#include "../include/audio.h"
#include "../include/combat.h"
/**
  * \function check_collision
  * \brief fonction qui detecter si la case en face du joueur est blocante
  * \return int : retourne l'état de collision
*/
int check_collision(global_structure_t ** global_structure)
{
  int y = (*global_structure)->player->posY;
  y -= 4;

  char *** matrice = get_String_Matrice(&(*global_structure), 1, (*global_structure)->player->posX,y);
  int collision = split_string_data(matrice[1][1],',',4);

  detruire_string_matrice(matrice,3);
  matrice = NULL;

  return collision;
}
/**
  * \function check_interaction
  * \brief Fonction de detection d'une interaction avec un élément du jeu (overworld) à la suite d'un appui sur une touche d'action (a,x,y,b)
  * \param global_structure : Moteur de jeu
*/

int * check_interaction(global_structure_t ** global_structure)
{
  int pos_x = (*global_structure)->player->posX;
  int pos_y = (*global_structure)->player->posY;
  pos_y -= 5;

  if (((*global_structure)->keys.lastkey == 'z')&&((*global_structure)->keys.z_key == 1))
  pos_y--;

  else if (((*global_structure)->keys.lastkey == 's')&&((*global_structure)->keys.s_key == 1))
  pos_y++;

  else if (((*global_structure)->keys.lastkey == 'q')&&((*global_structure)->keys.q_key == 1))
  pos_x--;

  else if (((*global_structure)->keys.lastkey == 'd')&&((*global_structure)->keys.d_key == 1))
  pos_x++;

  printf("Last key : %c\n",(*global_structure)->keys.lastkey );

  char *** matrice = get_String_Matrice(&(*global_structure), 1, pos_x,pos_y);
  static int interaction[10];

  for (size_t i = 0; i < 7; i++) {
    interaction[i] = split_string_data(matrice[1][1],',',i);
    printf("interaction[%i] = %i\n",i,interaction[i]);
  }
  /*
  for (size_t i = 0; i < 5; i++) {
    interaction[i] = split_string_data(matrice[1][1],',',4+i);
  }
*/
  //int interaction = split_string_data(matrice[1][1],',',4);

  printf("-------------\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      printf("%i;%i -> %s\t",i,j,matrice[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");

  detruire_string_matrice(matrice,3);
  matrice = NULL;

  return interaction;
}
/**
  * \function check_tile_agurments
  * \brief
  * \param global_structure : Moteur de jeu
*/
int * check_tile_agurments(global_structure_t ** global_structure)
{

  int pos_x = (*global_structure)->player->posX;
  int pos_y = (*global_structure)->player->posY;
  pos_y -= 4;

  char *** matrice = get_String_Matrice(&(*global_structure), 0, pos_x,pos_y);

  int * arguments = malloc(sizeof(int) * 10);


  arguments[0] = split_string_data(matrice[0][0],',',4);
  arguments[1] = split_string_data(matrice[0][0],',',5);
  arguments[2] = split_string_data(matrice[0][0],',',6);
  arguments[3] = split_string_data(matrice[0][0],',',7);
  arguments[4] = split_string_data(matrice[0][0],',',8);

  if (arguments[0] != 1)
  {
    printf("\nPossition : %i;%i\n",pos_x,pos_y);
    for (size_t i = 0; i < 5; i++) {
      printf("Arguments[%i] : %i\n",i,arguments[i]);
    }
    printf("\n%i,%i,%i,%i,%i\n",arguments[0],arguments[1],arguments[2],arguments[3],arguments[4]);

  }
/*
  for (size_t i = 0; i < 4; i++) {
    printf("Arguments[%i] : %i\n",i,arguments[i] );
  }
*/
  detruire_string_matrice(matrice,0);
  matrice = NULL;

  return arguments;
}
/**
  * \function collision
  * \brief Fonction de blocage du joueur quand une collision est rencontrée
  * \param global_structure : Moteur de jeu
*/
void collision(global_structure_t ** global_structure)
{
  if ((*global_structure)->keys.z_key + (*global_structure)->keys.q_key + (*global_structure)->keys.s_key + (*global_structure)->keys.d_key > 0 )
  {
    int collision = check_collision(global_structure);

    if (collision != -1)
    {
      int * arguments = check_tile_agurments(global_structure);
      //printf("%i\n",collision);

      switch (collision) {
        case 1:
        printf("bump\n");
        /*Le joueur est entré en collision avec un element et doit donc être bumpé dans la direction opposée*/
        if ((*global_structure)->keys.z_key == 1)
        {
          (*global_structure)->player->posY += (*global_structure)->player->move_step;
        }
        else if ((*global_structure)->keys.q_key == 1)
        {
          (*global_structure)->player->posX += (*global_structure)->player->move_step;
        }
        else if ((*global_structure)->keys.s_key == 1)
        {
          (*global_structure)->player->posY -= (*global_structure)->player->move_step;
        }
        else if ((*global_structure)->keys.d_key == 1)
        {
          (*global_structure)->player->posX -= (*global_structure)->player->move_step;
        }

        break;

        case 2:;
        //Le joueur marche dans l'herbe, ou dans les grottes.
        //Les paramètre additionnel correspondes au numéro des pokemon possible a rencontrer
        //srand(time(0));
        if (rand()%30 == 1)
        {
        printf("Combat\n");
        init_pkm_enemy(&(*global_structure)->wild_pkm,rand()%9);
        (*global_structure)->menu->menu_battle = 1;
        }

        break;

        case 3:
        //Le joueur a appuyé sur A en face d'une entié avec une interaction possible.
        /*
        arg 0 : 3;
        arg 1 : type d'interaction (1 : texte a afficher, 2 : combat a lancer, 3 : teleportation, 4 : objet a ramasser, 5 : utiliser la canne a pêche);
        arg 2 : donnée propre a l'interaction (1 : numéro du texte a afficher, 2 : numero du dresseur à combattre, 3 : numero du texte a afficher avant teleportation, 4 : numero de l'objet a ramasser, 5 : rien);
        arg 3 : numero de la musique a jouer, si pas de changement nécessaire (-1);
        */
        switch (arguments[0]) {
          case 1:;
          FILE * file;

          char buffer[10];
          sprintf(buffer,"src/asset/dialogues/data/%i.txt",arguments[1]);
          file = fopen(buffer, "r");

          char str[255];
          fscanf(file, "%s", str);

          printf("%s\n",str);

          fclose(file);
          break;

          case 2:
          break;

          case 3:
          break;

          case 4:
          break;

          case 5:
          break;

          default:
          break;
        }



        break;

        case 4:;
        //Le joueur doit faire un saut dans une direction.


        switch (arguments[1]) {
          case 0:
          //Haut
          (*global_structure)->player->posY -= 1;
          break;

          case 1:
          //Gauche
          (*global_structure)->player->posX -= 1;
          break;

          case 2:
          //Bas
          (*global_structure)->player->posY += 1;
          break;

          case 3:
          //Droite
          (*global_structure)->player->posX += 1;
          break;
        }
        /*
        arg 0 : 4;
        arg 1 : direction du saut (0: haut, 1: gauche, 2:bas, 3:droite);
        arg 2 : pas utilisé;
        arg 3 : pas utilisé;
        */


        break;

        case 5:;
        //Le joueur marche sur une case qui indique un changement/déclenchement d'une musique.

        int enable_play_sound = -1;
        if ((arguments[2] == 0)&&((*global_structure)->keys.z_key == 1))
        enable_play_sound = 1;
        else if ((arguments[2] == 1)&&((*global_structure)->keys.q_key == 1))
        enable_play_sound = 1;
        else if ((arguments[2] == 2)&&((*global_structure)->keys.s_key == 1))
        enable_play_sound = 1;
        else if ((arguments[2] == 3)&&((*global_structure)->keys.d_key == 1))
        enable_play_sound = 1;

        if (enable_play_sound == 1)
        {
          stop_sound();
          play_sound(global_structure,(*global_structure)->musique->track_path_list[arguments[1]],-1,10);
        }
        /*
        arg 0 : 5;
        arg 1 : numero du fichier son à jouer;
        arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
        */
        break;

        case 6:;
        //Le joueur marche sur une case qui indique un changement de map ou une téléportation sur la même map.
        /*
        Marche a suivre :
        Definir une variable (int) dans la struture du moteur
        cette variable correspond au numero de fichier data chargé par
        get_String_Matrice

        après avoir définit cette variable appeler une fonction qui
        change la varriable matrice dans le moteur, pour que ce soit la
        map choisi qui soit maintenant affiché.

        il faut maintenant téléporté le joueur à la bonne position sur la map nouvellement chargé

        Exemple d'utilisation : Le joueur entre/sort dans un batiment. (Donc doit checker les arguments suivant pour avoir les coordonnée de téléportation)
        */

        int enable_tp = -1;
        if ((arguments[4] == 0)&&((*global_structure)->keys.z_key == 1))
        enable_tp = 1;
        else if ((arguments[4] == 1)&&((*global_structure)->keys.q_key == 1))
        enable_tp = 1;
        else if ((arguments[4] == 2)&&((*global_structure)->keys.s_key == 1))
        enable_tp = 1;
        else if ((arguments[4] == 3)&&((*global_structure)->keys.d_key == 1))
        enable_tp = 1;

        if (enable_tp == 1)
        {
          int map_number = arguments[0];
          (*global_structure)->player->posX = arguments[2];
          (*global_structure)->player->posY = arguments[3];
        }


        /*
        arg 0 : 4;
        arg 1 : numero de la map;
        arg 2 : coordonnée x;
        arg 3 : coordonnée y;
        */
        break;

        case 7:
        //Le joueur déclenche une animation

        /*
        arg 0 : 5;
        arg 1 : numero du fichier son à jouer;
        arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
        */
        break;

        case 8:
        //Le joueur fait un saut dans une direction donné en paramètre additionnel

        /*
        arg 0 : 5;
        arg 1 : numero du fichier son à jouer;
        arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
        */
        break;

        case 9:
        //Le joueur ne peut plus bouger pour un temps donnée (le temps d'un évènement)

        /*
        arg 0 : 5;
        arg 1 : numero du fichier son à jouer;
        arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
        */
        break;

        case 10:
        //Le joueur a marché sur une surface glissante qui le fait ce déplacer dans une direction

        /*
        arg 0 : 5;
        arg 1 : numero du fichier son à jouer;
        arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
        */
        break;

        case 11:
        //Le joueur a marché sur une surface glissante qui le fait ce déplacer dans une direction

        /*
        arg 0 : 5;
        arg 1 : numero du fichier son à jouer;
        arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
        */
        break;

        default:
        break;
      }
      free(arguments);
    }
  }


  /*
  printf("-------------\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      printf("%i;%i -> %s\t",i,j,mat2[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
*/ //Pour debug de mat2

  /*
  les cases a surveiller sont :

  haut : mat2[0][1]
  gauche : mat2[1][0]
  bas : mat2[2][1]
  droite : mat2[1][2]
*/
}
