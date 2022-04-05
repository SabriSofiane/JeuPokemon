#include "../include/motor.h"
#include "../include/textures.h"


int init_texture(motor_t ** motor )
{
  int retour = 0;
  (*motor)->textures = malloc(sizeof(texture_t));

  if ((*motor)->textures == NULL)
  {
    printf("Erreur a l'allocation de la structure textures : %s\n",SDL_GetError());
    retour = -1;
  }

  (*motor)->textures->texture_map = malloc(sizeof(SDL_Texture*));

  if ((*motor)->textures->texture_map == NULL)
  {
    printf("Erreur a l'allocation de la structure texture pour la map : %s\n",SDL_GetError());
    retour = -1;
  }

  return(retour);
}


void load_texture(SDL_Renderer ** renderer,SDL_Texture ** texture,char * path)
{
  SDL_Surface * surface = IMG_Load(path);
  *texture = SDL_CreateTextureFromSurface(*renderer, surface);
  SDL_FreeSurface(surface);
}
