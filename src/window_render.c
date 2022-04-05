#include "../include/motor.h"
#include "../include/window_render.h"

int init_window_render(motor_t ** motor)
{
  int retour = 0;

  (*motor)->windows = malloc(sizeof(window_t));    // Allocation de l'espace mémoire pour la fenetre

  if ((*motor)->windows == NULL)
  {
    printf("Erreur a l'allocation de la struture de la fenetre  : %s\n",SDL_GetError());
    retour = -1;
  }

  (*motor)->windows->width = 1280;                 // Définition de la largeur de la fenetre
  (*motor)->windows->height = 720;                 // Définition de la hauteur de la fenetre
  (*motor)->windows->size_coef = 2;                // Définition du Coefficient d'échelle (ne vraiment pas modifier svp)
  (*motor)->windows->font = malloc(sizeof(TTF_Font*));

  if ((*motor)->windows == NULL)
  {
    printf("Erreur a l'allocation de la police : %s\n",SDL_GetError());
    retour = -1;
  }

  return(retour);
}

int create_window_render(SDL_Window ** window, SDL_Renderer ** renderer,int window_width, int window_height)
{
  //SDL_WINDOW_FULLSCREEN
  (*window) = SDL_CreateWindow("Pokemon ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_MAXIMIZED );

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

void limit_fps(unsigned int limit,int fps_limit)
{
  unsigned int ticks = SDL_GetTicks();

  if (limit < ticks)
      return;
  else if (limit > ticks + fps_limit)
      SDL_Delay(fps_limit);
  else
      SDL_Delay(limit-ticks);
}
