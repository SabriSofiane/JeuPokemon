#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/collisions.h"
#include "../lib/pokemon/string_matrice.h"
#include "../lib/pokemon/audio.h"

int check_collision(motor_t ** motor)
{
  int y = (*motor)->player->posY;
  y -= 4;

  char *** matrice = get_String_Matrice(&(*motor),"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map3.dat", 1, (*motor)->player->posX,y,"check_collision");
  int collision = split_string_data(matrice[1][1],',',3);

  detruire_string_matrice(matrice,3);
  matrice = NULL;

  return collision;
}

/*Fonction de detection d'une interaction avec un élément du jeu (overworld) à la suite d'un appuis sur une touche d'action (a,x,y,b)*/
int * check_interaction(motor_t ** motor)
{
  int pos_x = (*motor)->player->posX;
  int pos_y = (*motor)->player->posY;
  pos_y -= 5;

  if ((*motor)->keys.lastkey == 'z')
  pos_y--;

  if ((*motor)->keys.lastkey == 's')
  pos_y++;

  if ((*motor)->keys.lastkey == 'q')
  pos_x--;

  if ((*motor)->keys.lastkey == 'd')
  pos_x++;


  char *** matrice = get_String_Matrice(&(*motor),"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map3.dat", 0, pos_x,pos_y,"check_interaction");
  static int interaction[5];

  interaction[0] = split_string_data(matrice[1][1],',',4);
  /*
  for (size_t i = 0; i < 5; i++) {
    interaction[i] = split_string_data(matrice[1][1],',',4+i);
  }
  */
  //int interaction = split_string_data(matrice[1][1],',',4);

/*
  printf("-------------\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      printf("%i;%i -> %s\t",i,j,matrice[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
*/
  detruire_string_matrice(matrice,3);
  matrice = NULL;

  return interaction;
}

int * check_tile_agurments(motor_t ** motor)
{

  int pos_x = (*motor)->player->posX;
  int pos_y = (*motor)->player->posY;
  pos_y -= 4;

  char *** matrice = get_String_Matrice(&(*motor),"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map3.dat", 0, pos_x,pos_y,"check_interaction");

  int * arguments = malloc(sizeof(int) * 10);
  arguments[0] = split_string_data(matrice[0][0],',',3);
  arguments[1] = split_string_data(matrice[0][0],',',4);
  arguments[2] = split_string_data(matrice[0][0],',',5);
  arguments[3] = split_string_data(matrice[0][0],',',6);
/*
  for (size_t i = 0; i < 4; i++) {
    printf("Arguments[%i] : %i\n",i,arguments[i] );
  }
*/
  detruire_string_matrice(matrice,0);
  matrice = NULL;

  return arguments;
}

void collision(motor_t ** motor)
{
  int collision = check_collision(motor);

  if (collision != -1)
  {
    int * arguments = check_tile_agurments(motor);
    //printf("%i\n",collision);

    switch (collision) {
      case 1:
      printf("bump\n");
      /*Le joueur est entré en collision avec un element et doit donc être bumpé dans la direction opposée*/
      if ((*motor)->keys.z_key == 1)
      {
        (*motor)->player->posY++;
      }
      else if ((*motor)->keys.q_key == 1)
      {
        (*motor)->player->posX++;
      }
      else if ((*motor)->keys.s_key == 1)
      {
        (*motor)->player->posY--;
      }
      else if ((*motor)->keys.d_key == 1)
      {
        (*motor)->player->posX--;
      }
      break;

      case 2:;
      //Le joueur marche dans l'herbe, ou dans les grottes.
      //Les paramètre additionnel correspondes au numéro des pokemon possible a rencontrer
      srand(time(0)); //⚠️⚠️⚠️⚠️ Changer ce truc pour rendre vraiment random (la clée ne change pas)
      if (rand()%20 == 5)
      {
        printf("Combat\n");
      }
      break;

      case 3:
      //Le joueur a appuyé sur A en face d'une entié avec un interaction possible.
      break;

      case 4:;
      //Le joueur doit faire un saut dans une direction.


      switch (arguments[1]) {
        case 0:
        //Haut
        (*motor)->player->posY -= 1;
        break;

        case 1:
        //Gauche
        (*motor)->player->posX -= 1;
        break;

        case 2:
        //Bas
        (*motor)->player->posY += 1;
        break;

        case 3:
        //Droite
        (*motor)->player->posX += 1;
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
      if ((arguments[2] == 0)&&((*motor)->keys.z_key == 1))
      enable_play_sound = 1;
      else if ((arguments[2] == 1)&&((*motor)->keys.q_key == 1))
      enable_play_sound = 1;
      else if ((arguments[2] == 2)&&((*motor)->keys.s_key == 1))
      enable_play_sound = 1;
      else if ((arguments[2] == 3)&&((*motor)->keys.d_key == 1))
      enable_play_sound = 1;

      if (enable_play_sound == 1)
      {
        stop_sound();
        play_sound(motor,(*motor)->musique->track_path_list[arguments[1]]);
      }
      /*
      arg 0 : 5;
      arg 1 : numero du fichier son à jouer;
      arg 2 : nombre de boucle ( -1 : infini sinon vaut le nombre de boucle de lecture);
      */
      break;

      case 6:;
      //Le joueur marche sur une case qui indique un changement de map.
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
      int map_number = arguments[0];
      (*motor)->player->posX = arguments[2];
      (*motor)->player->posY = arguments[3];


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
