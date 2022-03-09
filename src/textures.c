#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/textures.h"


void init_textures(motor_t ** motor,SDL_Texture * texture_map1,char path[100])
{
  SDL_Surface * map_surface = IMG_Load(path);
  texture_map1 = SDL_CreateTextureFromSurface((*motor)->renderer, map_surface);
  SDL_FreeSurface(map_surface);
}


void load_texture(SDL_Renderer ** renderer,SDL_Texture ** texture,char * path)
{
  SDL_Surface * surface = IMG_Load(path);
  *texture = SDL_CreateTextureFromSurface(*renderer, surface);
  SDL_FreeSurface(surface);
}
