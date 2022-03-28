#include "../include/motor.h"
#include "../include/textures.h"


int init_texture(motor_t ** motor )
{
  (*motor)->textures = malloc(sizeof(texture_t));
  (*motor)->textures->texture_map = malloc(sizeof(SDL_Texture*));
}


void load_texture(SDL_Renderer ** renderer,SDL_Texture ** texture,char * path)
{
  SDL_Surface * surface = IMG_Load(path);
  *texture = SDL_CreateTextureFromSurface(*renderer, surface);
  SDL_FreeSurface(surface);
}
