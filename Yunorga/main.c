#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
//#include <SDL_ttf.h>

#include "load_header.h"

int main(int argc, char * argv[]) {
  motor_t * game_motor;
  game_motor = init_motor();
  init(&game_motor);

  game_motor->player->posX = 31;
  game_motor->player->posY = 18;
  game_motor->player->width = (int)(50*(floor((game_motor)->windows->size_coef)));
  game_motor->player->height = (int)(64*(floor((game_motor)->windows->size_coef)));

  //init_textures(&game_motor,(game_motor)->textures->calque_map_1,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/map3.png");
  //init_textures(&game_motor,(game_motor)->textures->calque_map_2,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/map3_bulding.png");


  SDL_Surface * map_surface = IMG_Load("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/map3_ground.png");
  (game_motor)->textures->calque_map_1 = SDL_CreateTextureFromSurface((game_motor)->renderer, map_surface);
  //SDL_FreeSurface(map_surface);

  map_surface = IMG_Load("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/map3_bulding.png");
  (game_motor)->textures->calque_map_2 = SDL_CreateTextureFromSurface((game_motor)->renderer, map_surface);


  map_surface = IMG_Load("C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/map3_bulding_calque_3.png");
  (game_motor)->textures->calque_map_3 = SDL_CreateTextureFromSurface((game_motor)->renderer, map_surface);
  SDL_FreeSurface(map_surface);


  system("cls");

  display_player(&game_motor);
  play_sound(&game_motor,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/Driftveil.mp3");

  while (!game_motor->quit) {
    if (event_handle(&game_motor) == 1)
    {
    SDL_RenderClear(game_motor->renderer);
    collision(&game_motor);
    display_map(&game_motor,(game_motor)->textures->calque_map_1);
    display_map(&game_motor,(game_motor)->textures->calque_map_2);
    display_player(&game_motor);
    display_map(&game_motor,(game_motor)->textures->calque_map_3);
    SDL_RenderPresent(game_motor->renderer);
    }
  }

  printf("Fin du while\n");

  //void (*fun_ptr)(int) = &fun;

  //display_player(&game_motor);

  //printf("%i\n", &(game_motor->player)->posX);
  destroy_motor(&game_motor);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
