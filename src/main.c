#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

#include "C:/Users/Elias/Desktop/JEU_POKEMON/include/load_header.h"

#define fps_limit 16

void sig_handler(int signum){
  //Return type of the handler function should be void
  printf("\nInside handler function\n");
}

int main(int argc, char * argv[]) {

  motor_t * game_motor;
  game_motor = init_motor();
  if (init(&game_motor) != 0)
  {
    printf("Erreur avec le moteur\n");
    return(-1);
  }

  audio_init(&game_motor);
  init_admin(&game_motor);
  play_sound(&game_motor,(game_motor)->musique->track_path_list[0],-1,0);

  text_init(&game_motor);
  printf("%i\n",sizeof(game_motor->menu) );
  game_motor->menu->speech_bubble = 0;
  game_motor->actual_time = 0;

  while (!game_motor->quit) {

    game_motor->actual_time = SDL_GetTicks()+fps_limit;

    limit_fps(game_motor->actual_time,fps_limit);

    event_handle(&game_motor);

    SDL_RenderClear(game_motor->renderer);
    SDL_SetRenderDrawColor(game_motor->renderer, 128,128,128, 255);
    collision(&game_motor);

    display_map(&game_motor,1);   //calque n°1
    display_map(&game_motor,2);   //calque n°2
    display_map(&game_motor,3);   //calque n°3
    display_player(&game_motor);  //joueur
    display_map(&game_motor,4);   //calque n°3
    //display_console(&game_motor);
    speech_bubble(&game_motor);

    SDL_RenderPresent(game_motor->renderer);
    }

  printf("Fin du while\n");
  /////destroy_window_render(&win,&renderer);
  destroy_motor(&game_motor);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
