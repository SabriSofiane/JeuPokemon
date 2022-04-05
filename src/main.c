/**
  * \file main.c
  * \brief main du programme
  * \author Elias OKAT
  * \version 1
  * \date 28 février 2022
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

#define fps_limit 16

int main(int argc, char * argv[]) {

start_game(fps_limit);

  return 0;
}
