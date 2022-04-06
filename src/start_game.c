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
  global_structure_t * game_global_structure;
  game_global_structure = init_global_structure();


  if (game_global_structure == NULL)
  {
    printf("Erreur avec le moteur\n");
  }

  play_sound(&game_global_structure,game_global_structure->musique->track_path_list[0],-1,0);

  while (!game_global_structure->quit) {

    SDL_RenderClear(game_global_structure->renderer);

    event_handle(&game_global_structure);

    game_global_structure->actual_time = SDL_GetTicks()+fps_limit;

    limit_fps(game_global_structure->actual_time,fps_limit);

    SDL_SetRenderDrawColor(game_global_structure->renderer, 128,128,128, 255);
    collision(&game_global_structure);

    display_map(&game_global_structure,1);   // Affichage du calque n°1
    display_map(&game_global_structure,2);   // Affichage du calque n°2
    display_map(&game_global_structure,3);   // Affichage du calque n°3
    display_player(&game_global_structure);  // Affichage du joueur
    display_map(&game_global_structure,4);   // Affichage du calque n°4

    menu(&game_global_structure);

    ecran_acceuil(&game_global_structure);

    menu_Bag(&game_global_structure);

    menu_Battle(&game_global_structure);

    menu_Battle_Attaque(&game_global_structure);

    menu_pokemon(&game_global_structure);

    menu_pokedex(&game_global_structure);

    menu_save(&game_global_structure);

    speech_bubble(&game_global_structure);

    SDL_RenderPresent(game_global_structure->renderer);
  }

  printf("Fin du jeu\n");
  destroy_window_render(&game_global_structure->windows->window,&game_global_structure->renderer);
  destroy_global_structure(&game_global_structure);
  //TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
