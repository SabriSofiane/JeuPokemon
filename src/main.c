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

int main(int argc, char * argv[]) {

start_game(fps_limit);

  return 0;
}
