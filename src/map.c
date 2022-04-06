/**
  * \file map.c
  * \brief fichier dédié à la map du jeu
  * \author Elias OKAT
  * \version 1
  * \date 28 février 2022
*/
#include "../include/global_structure.h"
#include "../include/map.h"
#include "../include/textures.h"
#include "../include/string_matrice.h"
/**
  * \function init_map
  * \brief fonction d'initialisation de la map de jeu
  * \param global_structure : moteur de jeux
*/
int init_map(global_structure_t ** global_structure)
{
  int retour = 0;

  char * tileset = "./src/asset/composite_game.png";
  char * datafile = "./src/asset/file_map3_game.dat";
  load_texture(&(*global_structure)->renderer,&(*global_structure)->textures->texture_map,tileset);

  if ((*global_structure)->textures->texture_map== NULL)
  {
    printf("Erreur au chargement de la texture de la map : %s\n",SDL_GetError());
    retour = -1;
  }



  int r = (*global_structure)->tiles_number, c = (*global_structure)->tiles_number;

  FILE * file;

  file = fopen(datafile, "r");

  if (file == NULL) {
    printf("Erreur au chargement du fichier data de la map\n");
    retour = -1;
  }

  (*global_structure)->matrice_file = creer_string_matrice((*global_structure)->tiles_number);

  if ((*global_structure)->matrice_file == NULL)
  {
    printf("Erreur au chargement de la matrice de la map\n");
    retour = -1;
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      char str[80];
      fscanf(file, "%s", str);
      strncpy((*global_structure)->matrice_file[i][j],str,30);
    }
  }

  fclose(file);

  return retour;
}
/**
  * \function display_map
  * \brief fonction d'affichage de la matrice de jeu
  * \param global_structure : moteur de jeux
  * \param texture_id : id de la texture que l'on souhaite utilisé
*/
void display_map(global_structure_t ** global_structure,int calque_id)
{
  int nb_bordure = 10;

  char *** mat = get_String_Matrice(&(*global_structure), nb_bordure, (*global_structure)->player->posX,(*global_structure)->player->posY);
  int loop = (2 * nb_bordure) + 1;

  //printf("matrice %s\n",mat[16][16]);
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < loop; j++) {
      int image_width;
      int image_height;

      SDL_Rect SrcR;
      SDL_Rect DestR;

      int tiles_size = (int)(32*(floor((*global_structure)->windows->size_coef)));

      int mat_val = split_string_data(mat[i][j],',',calque_id-1);
      int property = split_string_data(mat[i][j],',',3);


      if (mat_val != -2) //Si la split_string_data à renvoyé -2, alors cela veut dire que la cellule et hors du jeu de donnée et donc hors de la map
      {
        if (mat_val < 510)
        {
          SrcR.x = 0*32;
          SrcR.y = 32*mat_val;

        }else if (mat_val < 2*510)
        {
          SrcR.x = 1*32;
          SrcR.y = 32*(mat_val-509);

        }else if (mat_val < 3*510)
        {

          SrcR.x = 2*32;
          SrcR.y = 32*(mat_val-(2*509));

        }else if (mat_val < 4*510)
        {
          SrcR.x = 3*32;
          SrcR.y = 32*(mat_val-(3*509));

        }else if (mat_val < 5*510)
        {
          SrcR.x = 4*32;
          SrcR.y = 32*(mat_val-(4*509));

        }else if (mat_val < 6*510)
        {
          SrcR.x = 5*32;
          SrcR.y = 32*(mat_val-(5*509));
        }

          SrcR.w = 32;
          SrcR.h = 32;

          DestR.x = 0 + (tiles_size * j);
          DestR.y = 0 + (tiles_size * i);
          DestR.w = tiles_size;
          DestR.h = tiles_size;

          SDL_QueryTexture((*global_structure)->textures->texture_map, NULL, NULL,  &image_width , &image_height);
          SDL_RenderCopy((*global_structure)->renderer, (*global_structure)->textures->texture_map, &SrcR, &DestR);
      }else {

        DestR.x = 0 + (tiles_size * j);
        DestR.y = 0 + (tiles_size * i);
        DestR.w = tiles_size;
        DestR.h = tiles_size;

        SDL_SetRenderDrawColor( (*global_structure)->renderer, 255, 0, 0, 255 );
        SDL_RenderFillRect( (*global_structure)->renderer, &DestR );
      }

    }
  }

  detruire_string_matrice(mat,(2*nb_bordure)+1);
}
