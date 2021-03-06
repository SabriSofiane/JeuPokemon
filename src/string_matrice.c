/**
  * \file string_matrice.c
  * \brief fichier des matrices de jeu
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/global_structure.h"
#include "../include/string_matrice.h"
/**
  * \function creer_string_matrice
  * \brief fonction de creation d'une matrice à 3 dimensions
  * \param size : taille de la matrice
  * \return char: la matrice initialisé
*/
char *** creer_string_matrice(int size)
{
  char *** data = (char *** )malloc(size * sizeof(char ** )) ;

  //Allocate memroy for each row
  for(int i = 0 ; i < size ; i++ )
  {
      data[i] = (char ** ) malloc(size * sizeof(char * )) ;
      for ( int j = 0 ; j < size ; j++ )
      {
          data[i][j] = malloc(30 * sizeof(char));// (char *)malloc(1 * sizeof(char));
      }
   }
   return data;
}
/**
  * \function detruire_string_matrice
  * \brief fonction de destruction de la matrice
  * \param matrice : la matrice que l'on veut détruire
  * \param size : taille de la matrice
*/
void detruire_string_matrice(char *** matrice,int size)
{
  for(int i = 0 ; i < size ; i++ )
  {
      for ( int j = 0 ; j < size ; j++ )
      {
          free(matrice[i][j]);
      }
      free(matrice[i]);
   }
   free(matrice);
}
/**
  * \function get_string_matrice
  * \brief fonction qui récupère une matrice en matrice string
  * \param global_structure : le moteur de jeu
  * \param nb_bordure : le nombre de bordure que l'on souhaite definir dans notre matrice
  * \param x_center :
  * \param y_center :
  * \return char: la matrice en string
*/
char *** get_String_Matrice(global_structure_t ** global_structure, int nb_bordure,int x_center,int y_center)
{
  int r = (*global_structure)->tiles_number;
  int c = (*global_structure)->tiles_number;

  char *** data = (*global_structure)->matrice_file;
  char *** data2 = creer_string_matrice((2*nb_bordure)+1);


  for (int i = -1 * nb_bordure, countY = -1; i < nb_bordure + 1; i++) {
    countY++;
    for (int j = -1 * nb_bordure, countX = 0; j < nb_bordure + 1; j++) {
      if ( ((y_center + i) < 0) || ((x_center + j) < 0) )
      strncpy(data2[countY][countX],"-1",2);
      else if ( ((y_center + i) >= r) || ((x_center + j) >= r) )
      strncpy(data2[countY][countX],"-1",2);
      else
      strncpy(data2[countY][countX],data[(y_center + i)][(x_center + j)],30);//data[(y_center + i)][(x_center + j)];//printf("%s\t",data[(playerY + i)][(playerX + j)]);
      countX++;
    }
  }
  return data2;
}
/**
  * \function split_string_data
  * \brief Cette fonction découpe un string en deux
  * \param str: message
  * \param s2 : récupère le caractère à l'index
  * \param index : la position auquel l'on veut choisir le caractère
  * \return int : la position du caractère
*/
int split_string_data(char str[80], const char s2,int index)
{
  int retour = -2;
  const char s[2] = ",";
  char * token;
  char str_buffer[80];
  strcpy(str_buffer,str);
  // get the first token
  token = strtok(str_buffer, s);



  if (index == 0)
  return atoi(token);
  //walk through other tokens
  while(index != 0) {
    token = strtok(NULL, s);
    index--;
 }

 /*
 if (((token[0] == '[') == 0) && ((token[strlen(token)-1] == ']') == 0))
 {

   char token_buffer[30];
   strncpy(token_buffer, token+1, strlen(token)-2);


   Uint32 ticks = SDL_GetTicks();
   Uint32 seconds = ticks / 200;
   Uint32 index_tiles = seconds % 4;

   token = strtok(token_buffer, s);
   while(index_tiles != 0) {
     token = strtok(NULL, ",");
     index_tiles--;
   }

   strncpy(token,token_buffer,strlen(token_buffer));

 }
*/

 if (token)
 retour = atoi(token);

 return retour;
}
