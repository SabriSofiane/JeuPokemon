/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <dirent.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
*/

#include "C:/Users/Elias/Desktop/JEU_POKEMON/lib/pokemon/load_header.h"

int main(int argc, char * argv[]) {

  motor_t * game_motor;
  game_motor = init_motor();
  if (init(&game_motor) != 0)
  {
    printf("Erreur avec le moteur\n");
    return(-1);
  }

  /*
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
    if (SDL_IsGameController(i)) {
        (game_motor)->controller->controller = SDL_GameControllerOpen(i);
        if ((game_motor)->controller->controller) {
          printf("Controller find %i\n",i);
            break;
        } else {
            fprintf(stderr, "Could not open gamecontroller %i: %s\n", i, SDL_GetError());
        }
    }
  }
*/

  //system("cls");
  audio_init(&game_motor);
  play_sound(&game_motor,(game_motor)->musique->track_path_list[0]);//"./truc_bien_range/asset/audio/Driftveil.mp3");//(game_motor)->musique->track_path_list[0]);
  printf("%s------ \n", (game_motor)->musique->track_path_list[0]);
  printf("%i \n", strlen((game_motor)->musique->track_path_list[0]));
  /*
  SDL_Window * win;
  SDL_Renderer * renderer;
  create_window_render(&win,&renderer,100,100);//dialog();
*/
  TTF_Init();
  (game_motor)->windows->font = TTF_OpenFont("arial.ttf", 25);

  int game_loop = 0;
  while (!game_motor->quit) {
    game_motor->previous_time = game_motor->actual_time;
    game_motor->actual_time = SDL_GetTicks();

    if (event_handle(&game_motor) == 1)
    {
      if (2 == 2)
      {


        SDL_SetRenderDrawColor(game_motor->renderer, 128,128,128, 255);




        SDL_RenderClear(game_motor->renderer);

        collision(&game_motor);

        display_map(&game_motor,1);   //calque n°1
        display_map(&game_motor,2);   //calque n°2
        display_player(&game_motor);  //joueur
        display_map(&game_motor,3);   //calque n°3
        display_console(&game_motor);
        SDL_RenderPresent(game_motor->renderer);
        game_loop = 0;
      }
      game_loop++;
    }
  }

  printf("Fin du while\n");
  /////destroy_window_render(&win,&renderer);
  destroy_motor(&game_motor);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
