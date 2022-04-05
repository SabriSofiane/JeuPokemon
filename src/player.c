/**
  * \file player.c
  * \brief fichier du joueur
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/motor.h"
#include "../include/player.h"
#include "../include/textures.h"
/**
  * \function init_player
  * \brief Initialisation du joueur (texture, mouvements...)
  * \param motor : moteur de jeux
*/
int init_player(motor_t ** motor)
{
  int retour = 0;

  (*motor)->player = malloc(sizeof(player_t));

  if ((*motor)->player == NULL)
  {
    printf("Erreur durant l'allocation memoire de la structure\n");
    retour = -1;
  }
  (*motor)->player->movement_id = 1;
  FILE* fout2 = fopen("player","rb");
  fread((*motor)->player, sizeof(player_t), 1, fout2);
  fclose(fout2);
  (*motor)->player->move_step = 0.4;


  (*motor)->player->movement_id = 1;
  (*motor)->keys.lastkey = 'z';
  /*
  (*motor)->player->speed = 1;
  (*motor)->player->move_step = 0.5;


  (*motor)->player->posX = 201;//215;
  (*motor)->player->posY = 216;//220;
  */
  (*motor)->player->width = 1.825;//(int)(64*(floor((*motor)->windows->size_coef)));
  (*motor)->player->height = 1.825;//(int)(64*(floor((*motor)->windows->size_coef)));

  /*
  (*motor)->liste_player = malloc(sizeof(Liste_t));

  if ((*motor)->liste_player == NULL)
  {
    printf("Erreur d'allocation pour player->liste_player\n");
    retour = -1;
  }
*/
  load_texture(&(*motor)->renderer,&(*motor)->textures->player_walk,"./src/asset/lyra/lyra_walk.png");
  load_texture(&(*motor)->renderer,&(*motor)->textures->player_run,"./src/asset/lyra/lyra_run.png");

  if ((*motor)->textures->player_walk== NULL)
  {
    printf("Erreur au chargement de la texture de marche du joueur : %s\n",SDL_GetError());
    retour = -1;
  }

  if ((*motor)->textures->player_run== NULL)
  {
    printf("Erreur au chargement de la texture de course du joueur : %s\n",SDL_GetError());
    retour = -1;
  }

  return(retour);
}
/**
  * \function init_player
  * \brief fonction d'affichage du joueur
  * \param motor : moteur de jeux
*/
void display_player(motor_t ** motor)
{
  SDL_Rect * player_rect;
  player_rect = &(*motor)->player->player_rect;

  player_rect->w = 64*1.825;//*(&(*motor)->player->width);
  player_rect->h = 64*1.825;//*(&(*motor)->player->height);

  player_rect->x = (*(&(*motor)->windows->width) - player_rect->w)/2;
  player_rect->x += 32;

  player_rect->y = (*(&(*motor)->windows->height) - player_rect->h)/2;
  player_rect->y += 32;

  SDL_Rect SrcR;
/*
  SrcR.x = ((*motor)->player->movement_id/2)+(*motor)->player->movement_id%2;
  SrcR.x--;
  SrcR.x *= 64;
*/

  if ((*motor)->keys.z_key + (*motor)->keys.q_key + (*motor)->keys.s_key + (*motor)->keys.d_key > 0)//((((*motor)->keys.z_key + (*motor)->keys.s_key > 0 ) && (floorf((*motor)->player->posY) == (*motor)->player->posY)) && (((*motor)->keys.q_key + (*motor)->keys.d_key > 0 ) && (floorf((*motor)->player->posX) == (*motor)->player->posX)))
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
  if ((*motor)->keys.z_key + (*motor)->keys.q_key + (*motor)->keys.s_key + (*motor)->keys.d_key > 0)
  {
    SrcR.x = sprite;
    SrcR.x *= 64;
  }
  */

  if ((*motor)->player->speed == 1)
  {

      if ((*motor)->keys.z_key + (*motor)->keys.q_key + (*motor)->keys.s_key + (*motor)->keys.d_key > 0)
      {
      if ((*motor)->keys.z_key == 1)
      SrcR.y = 64*0;
      else if ((*motor)->keys.q_key == 1)
      SrcR.y = 64*1;
      else if ((*motor)->keys.s_key == 1)
      SrcR.y = 64*2;
      else if ((*motor)->keys.d_key == 1)
      SrcR.y = 64*3;
      }   else if (1 == 1)
      {
      if ((*motor)->keys.lastkey == 'z')
      SrcR.y = 64*0;
      else if ((*motor)->keys.lastkey == 'q')
      SrcR.y = 64*1;
      else if ((*motor)->keys.lastkey == 's')
      SrcR.y = 64*2;
      else if ((*motor)->keys.lastkey == 'd')
      SrcR.y = 64*3;
    }
  }
  else if ((*motor)->player->speed == 2)
  {
  if ((*motor)->keys.s_key == 1)
  SrcR.y = 64*0;
  else if ((*motor)->keys.q_key == 1)
  SrcR.y = 64*1;
  else if ((*motor)->keys.d_key == 1)
  SrcR.y = 64*2;
  else if ((*motor)->keys.z_key == 1)
  SrcR.y = 64*3;
  }

  SrcR.w = 64;
  SrcR.h = 64;

  int image_width,image_height;


  if ((*motor)->player->speed == 1)
  {
    SDL_QueryTexture((*motor)->textures->player_walk, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->textures->player_walk, &SrcR, player_rect);
  }
  else if ((*motor)->player->speed == 2)
  {
    SDL_QueryTexture((*motor)->textures->player_run, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->textures->player_run, &SrcR, player_rect);
  }
}
