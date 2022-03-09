#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/player.h"
#include "../lib/pokemon/textures.h"

int init_player(motor_t ** motor)
{
  int retour = 0;
  (*motor)->player->movement_id = 1;
  (*motor)->player->speed = 1;
  (*motor)->player->player_cooldown = 0;


  (*motor)->player->posX = 201;//215;
  (*motor)->player->posY = 216;//220;

  (*motor)->player->width = (int)(64*(floor((*motor)->windows->size_coef)));
  (*motor)->player->height = (int)(64*(floor((*motor)->windows->size_coef)));

  load_texture(&(*motor)->renderer,&(*motor)->textures->player_walk,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/lyra/lyra_walk.png");
  load_texture(&(*motor)->renderer,&(*motor)->textures->player_run,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/lyra/lyra_run.png");

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

void display_player(motor_t ** motor)
{
  /*
  if ((*motor)->player->player_cooldown > 0)
  (*motor)->player->player_cooldown--;
  else if ((*motor)->player->player_cooldown == 0)
  {
    (*motor)->player->movement_id = 1;
    (*motor)->player->player_cooldown = -1;
  }
  */

  SDL_Rect * player_rect;
  player_rect = &(*motor)->player->player_rect;

  player_rect->w = *(&(*motor)->player->width);
  player_rect->h = *(&(*motor)->player->height);

  player_rect->x = (*(&(*motor)->windows->width) - player_rect->w)/2;
  player_rect->x += 32;

  player_rect->y = (*(&(*motor)->windows->height) - player_rect->h)/2;
  player_rect->y += 32;

  SDL_Rect SrcR;

  SrcR.x = ((*motor)->player->movement_id/2)+(*motor)->player->movement_id%2;
  SrcR.x--;
  SrcR.x *= 64;


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
  } else
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

  //free(player_rect);
  //player_rect = NULL;
}
