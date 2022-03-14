#include "../include/motor.h"
#include "../include/window_render.h"

int create_window_render(SDL_Window ** window, SDL_Renderer ** renderer,int window_width, int window_height)
{
  (*window) = SDL_CreateWindow("Pokemon ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_RESIZABLE );

  SDL_Surface * icon = IMG_Load("C:/Users/Elias/Desktop/JEU_POKEMON/src/asset/icon.png");
  SDL_SetWindowIcon(*window,icon);
  SDL_FreeSurface(icon);

  if(*window == NULL)
  {
    printf("Erreur a la creation la fenetre : %s\n", SDL_GetError());
    return 0;
  }else
  {
      printf("Creation de la fenetre\n");
  }

  (*renderer) = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

  if(*renderer == NULL)
  {
    printf("Erreur a la creation du rendu : %s\n", SDL_GetError());
    SDL_DestroyWindow(*window);
    return 0;
  }else
  {
      printf("Creation du rendu\n");
  }

  return 1;
}



void destroy_window_render(SDL_Window ** window, SDL_Renderer ** renderer)
{
  if(*renderer != NULL)
    {
        SDL_DestroyRenderer(*renderer);
        (*renderer) = NULL;
        printf("Destruction du rendu\n");
    }

  if(*window != NULL)
    {
        SDL_DestroyWindow(*window);
        (*window) = NULL;
        printf("Destruction de la fenetre\n");
    }
}
