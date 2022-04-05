/**
  * \file start_game.c
  * \brief fichier appelant toute les fonctions
  * \author OKAT Elias
  * \version 1
  * \date 1 avril 22
*/
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

#include "../include/load_header.h"
/**
  * \function start_game
  * \brief fonction appelant toutes les fonctions du jeu
  * \param fps_limit : la limite des images par secondes que l'on souhaite imposer
*/
void start_game(int fps_limit)
{
  motor_t * game_motor;
  game_motor = init_motor();


  if (game_motor == NULL)
  {
    printf("Erreur avec le moteur\n");
  }

  play_sound(&game_motor,game_motor->musique->track_path_list[0],-1,0);

  while (!game_motor->quit) {

    SDL_RenderClear(game_motor->renderer);

    event_handle(&game_motor);

    game_motor->actual_time = SDL_GetTicks()+fps_limit;

    limit_fps(game_motor->actual_time,fps_limit);

    SDL_SetRenderDrawColor(game_motor->renderer, 128,128,128, 255);
    collision(&game_motor);

    display_map(&game_motor,1);   // Affichage du calque n°1
    display_map(&game_motor,2);   // Affichage du calque n°2
    display_map(&game_motor,3);   // Affichage du calque n°3
    display_player(&game_motor);  // Affichage du joueur
    display_map(&game_motor,4);   // Affichage du calque n°4

    menu(&game_motor);

    ecran_acceuil(&game_motor);

    menu_Bag(&game_motor);

    menu_Battle(&game_motor);

    menu_Battle_Attaque(&game_motor);

    menu_pokemon(&game_motor);

    menu_pokedex(&game_motor);

    menu_save(&game_motor);

    speech_bubble(&game_motor);

    SDL_RenderPresent(game_motor->renderer);
  }

  printf("Fin du jeu\n");
  destroy_window_render(&game_motor->windows->window,&game_motor->renderer);
  destroy_motor(&game_motor);
  //TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
