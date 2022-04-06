/**
  * \file player.c
  * \brief fichier du joueur
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/global_structure.h"
#include "../include/player.h"
#include "../include/textures.h"
/**
  * \function init_player
  * \brief Initialisation du joueur (texture, mouvements...)
  * \param global_structure : moteur de jeux
*/
int init_player(global_structure_t ** global_structure)
{
  int retour = 0;

  (*global_structure)->player = malloc(sizeof(player_t));

  if ((*global_structure)->player == NULL)
  {
    printf("Erreur durant l'allocation memoire de la structure\n");
    retour = -1;
  }
  (*global_structure)->player->movement_id = 1;
  FILE* fout2 = fopen("player","rb");
  fread((*global_structure)->player, sizeof(player_t), 1, fout2);
  fclose(fout2);
  (*global_structure)->player->move_step = 0.4;


  (*global_structure)->player->movement_id = 1;
  (*global_structure)->keys.lastkey = 'z';
  /*
  (*global_structure)->player->speed = 1;
  (*global_structure)->player->move_step = 0.5;


  (*global_structure)->player->posX = 201;//215;
  (*global_structure)->player->posY = 216;//220;
  */
  (*global_structure)->player->width = 1.825;//(int)(64*(floor((*global_structure)->windows->size_coef)));
  (*global_structure)->player->height = 1.825;//(int)(64*(floor((*global_structure)->windows->size_coef)));

  /*
  (*global_structure)->liste_player = malloc(sizeof(Liste_t));

  if ((*global_structure)->liste_player == NULL)
  {
    printf("Erreur d'allocation pour player->liste_player\n");
    retour = -1;
  }
*/
  load_texture(&(*global_structure)->renderer,&(*global_structure)->textures->player_walk,"./src/asset/lyra/lyra_walk.png");
  load_texture(&(*global_structure)->renderer,&(*global_structure)->textures->player_run,"./src/asset/lyra/lyra_run.png");

  if ((*global_structure)->textures->player_walk== NULL)
  {
    printf("Erreur au chargement de la texture de marche du joueur : %s\n",SDL_GetError());
    retour = -1;
  }

  if ((*global_structure)->textures->player_run== NULL)
  {
    printf("Erreur au chargement de la texture de course du joueur : %s\n",SDL_GetError());
    retour = -1;
  }

  return(retour);
}
/**
  * \function init_player
  * \brief fonction d'affichage du joueur
  * \param global_structure : moteur de jeux
*/
void display_player(global_structure_t ** global_structure)
{
  SDL_Rect * player_rect;
  player_rect = &(*global_structure)->player->player_rect;

  player_rect->w = 64*1.825;//*(&(*global_structure)->player->width);
  player_rect->h = 64*1.825;//*(&(*global_structure)->player->height);

  player_rect->x = (*(&(*global_structure)->windows->width) - player_rect->w)/2;
  player_rect->x += 32;

  player_rect->y = (*(&(*global_structure)->windows->height) - player_rect->h)/2;
  player_rect->y += 32;

  SDL_Rect SrcR;
/*
  SrcR.x = ((*global_structure)->player->movement_id/2)+(*global_structure)->player->movement_id%2;
  SrcR.x--;
  SrcR.x *= 64;
*/

  if ((*global_structure)->keys.z_key + (*global_structure)->keys.q_key + (*global_structure)->keys.s_key + (*global_structure)->keys.d_key > 0)//((((*global_structure)->keys.z_key + (*global_structure)->keys.s_key > 0 ) && (floorf((*global_structure)->player->posY) == (*global_structure)->player->posY)) && (((*global_structure)->keys.q_key + (*global_structure)->keys.d_key > 0 ) && (floorf((*global_structure)->player->posX) == (*global_structure)->player->posX)))
   {
    Uint32 ticks = SDL_GetTicks();
    Uint32 seconds = ticks / 200;
    Uint32 sprite = seconds % 4;
    SrcR.x = sprite;
    SrcR.x *= 64;
  } else
  {
    SrcR.x = 0;
  }



  /*
  if ((*global_structure)->keys.z_key + (*global_structure)->keys.q_key + (*global_structure)->keys.s_key + (*global_structure)->keys.d_key > 0)
  {
    SrcR.x = sprite;
    SrcR.x *= 64;
  }
  */

  if ((*global_structure)->player->speed == 1)
  {

      if ((*global_structure)->keys.z_key + (*global_structure)->keys.q_key + (*global_structure)->keys.s_key + (*global_structure)->keys.d_key > 0)
      {
      if ((*global_structure)->keys.z_key == 1)
      SrcR.y = 64*0;
      else if ((*global_structure)->keys.q_key == 1)
      SrcR.y = 64*1;
      else if ((*global_structure)->keys.s_key == 1)
      SrcR.y = 64*2;
      else if ((*global_structure)->keys.d_key == 1)
      SrcR.y = 64*3;
      }   else if (1 == 1)
      {
      if ((*global_structure)->keys.lastkey == 'z')
      SrcR.y = 64*0;
      else if ((*global_structure)->keys.lastkey == 'q')
      SrcR.y = 64*1;
      else if ((*global_structure)->keys.lastkey == 's')
      SrcR.y = 64*2;
      else if ((*global_structure)->keys.lastkey == 'd')
      SrcR.y = 64*3;
    }
  }
  else if ((*global_structure)->player->speed == 2)
  {
  if ((*global_structure)->keys.s_key == 1)
  SrcR.y = 64*0;
  else if ((*global_structure)->keys.q_key == 1)
  SrcR.y = 64*1;
  else if ((*global_structure)->keys.d_key == 1)
  SrcR.y = 64*2;
  else if ((*global_structure)->keys.z_key == 1)
  SrcR.y = 64*3;
  }

  SrcR.w = 64;
  SrcR.h = 64;

  int image_width,image_height;


  if ((*global_structure)->player->speed == 1)
  {
    SDL_QueryTexture((*global_structure)->textures->player_walk, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*global_structure)->renderer, (*global_structure)->textures->player_walk, &SrcR, player_rect);
  }
  else if ((*global_structure)->player->speed == 2)
  {
    SDL_QueryTexture((*global_structure)->textures->player_run, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*global_structure)->renderer, (*global_structure)->textures->player_run, &SrcR, player_rect);
  }
}
