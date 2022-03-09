#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/map.h"
#include "../lib/pokemon/textures.h"
#include "../lib/pokemon/string_matrice.h"

int init_map(motor_t ** motor)
{
  int retour = 0;

  char * tileset = "C:/Users/Elias/Desktop/JEU_POKEMON/composite_game.png";
  char * datafile = "C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map3_game.dat";
  load_texture(&(*motor)->renderer,&(*motor)->textures->texture_map,tileset);

  if ((*motor)->textures->texture_map== NULL)
  {
    printf("Erreur au chargement de la texture de la map : %s\n",SDL_GetError());
    retour = -1;
  }



  int r = (*motor)->tiles_number, c = (*motor)->tiles_number;

  FILE * file;

  file = fopen(datafile, "r");

  if (file == NULL) {
    printf("Erreur au chargement du fichier data de la map\n");
    retour = -1;
  }

  (*motor)->matrice_file = creer_string_matrice((*motor)->tiles_number);

  if ((*motor)->matrice_file == NULL)
  {
    printf("Erreur au chargement de la matrice de la map\n");
    retour = -1;
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      char str[80];
      fscanf(file, "%s", str);
      strncpy((*motor)->matrice_file[i][j],str,30);
    }
  }

  fclose(file);

  return retour;
}

void display_map(motor_t ** motor,int texture_id)
{
  int nb_bordure = 10;

  char *** mat = get_String_Matrice(&(*motor),"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/file_map3.dat", nb_bordure, (*motor)->player->posX,(*motor)->player->posY,"display_map_convert");
  int loop = (2 * nb_bordure) + 1;

  //printf("matrice %s\n",mat[16][16]);
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < loop; j++) {
      int image_width;
      int image_height;

      SDL_Rect SrcR;
      SDL_Rect DestR;

      int tiles_size = (int)(32*(floor((*motor)->windows->size_coef)));

      int mat_val = split_string_data(mat[i][j],',',texture_id-1);
      int property = split_string_data(mat[i][j],',',3);
      //mat_val--;

      if (atoi(mat[i][j]) != -1)
      {
        /*
        int y = mat_val/tiles_size;
        int x = mat_val-(y*tiles_size);
        y++;
*/
        /*
        if (! ((texture_id == 3) && (property == 2) && ((i == (*motor)->player->posX-1) && (j == ((*motor)->player->posY-4)))) )
        {
*/
        /*
          //Fonctionne
          if (mat_val < 510)
          {
            SrcR.x = 0;
            SrcR.y = 32*mat_val;
          }else if (mat_val < 2*510)
          {
            SrcR.x = 32;
            SrcR.y = 32*(mat_val-509);
          }else if (mat_val < 3*510)
          {
            SrcR.x = 64;
            SrcR.y = 32*(mat_val-1018);
          }
*/
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

          SDL_QueryTexture((*motor)->textures->texture_map, NULL, NULL,  &image_width , &image_height);
          SDL_RenderCopy((*motor)->renderer, (*motor)->textures->texture_map, &SrcR, &DestR);
      }else {

        DestR.x = 0 + (tiles_size * j);
        DestR.y = 0 + (tiles_size * i);
        DestR.w = tiles_size;
        DestR.h = tiles_size;

        SDL_SetRenderDrawColor( (*motor)->renderer, 255, 0, 0, 255 );
        SDL_RenderFillRect( (*motor)->renderer, &DestR );
      }

    }
  }

  detruire_string_matrice(mat,(2*nb_bordure)+1);
}
