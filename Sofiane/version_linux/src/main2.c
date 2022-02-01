#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char **argv) {
  SDL_version nb;
  SDL_VERSION(&nb);

  printf("SDL %d.%d.%d\n",nb.major,nb.minor,nb.patch);
  

  return EXIT_SUCCESS;
}
//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
// bin/prog.exe

