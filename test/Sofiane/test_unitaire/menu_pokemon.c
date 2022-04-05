#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> //Time.h à ajouter en commun
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "load_header.h"
//export LD_LIBRARY_PATH="$HOME/SDL2/lib"
int main(int argc, char * argv[]) {
  motor_t * game_motor;
  game_motor = init_motor();
  init(&game_motor);
  init_pkm_enemy(&wild_pkm);
  init_pkm_team(&pkm, "1.txt");
  push(&player, pkm);
  init_pkm_team(&pkm, "2.txt");
  insertAtEnd(player, pkm);
  init_pkm_team(&pkm, "3.txt");
  insertAtEnd(player, pkm);
  init_pkm_team(&pkm, "7.txt");
  insertAtEnd(player, pkm);
  init_pkm_team(&pkm, "5.txt");
  insertAtEnd(player, pkm);
  init_pkm_team(&pkm, "6.txt");
  insertAtEnd(player, pkm);
  //play_sound(&game_motor,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/Driftveil.mp3");
  while (!game_motor->quit) {
    if (event_handle(&game_motor) == 1)
    {
    SDL_RenderClear(game_motor->renderer);
    
    menu_pokemon(&game_motor);
    
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





