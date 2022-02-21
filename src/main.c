
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "load_header.h"

int main(int argc, char * argv[]) {
  motor_t * game_motor;
  game_motor = init_motor();
  init(&game_motor);

  //play_sound(&game_motor,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/Driftveil.mp3");

  while (!game_motor->quit) {
    if (event_handle(&game_motor) == 1)
    {
    SDL_RenderClear(game_motor->renderer);
    //menu_Battle_Attaque(&game_motor);
    //menu_Battle(&game_motor);
    //menu_Bag(&game_motor);
    //menu(&game_motor);
    //1280x720
    SDL_RenderPresent(game_motor->renderer);
    }
  }

  printf("Fin du while\n");

  destroy_motor(&game_motor);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
