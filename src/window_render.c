/**
  * \file window_render.c
  * \brief fichier pour l'affichage de la fenetre
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/global_structure.h"
#include "../include/window_render.h"
/**
  * \function init_window_render
  * \brief fonction d'initialisation de la fenetre
  * \param global_structure : le moteur de jeu
*/
int init_window_render(global_structure_t ** global_structure)
{
  int retour = 0;

  (*global_structure)->windows = malloc(sizeof(window_t));    // Allocation de l'espace mémoire pour la fenetre

  if ((*global_structure)->windows == NULL)
  {
    printf("Erreur a l'allocation de la struture de la fenetre  : %s\n",SDL_GetError());
    retour = -1;
  }

  (*global_structure)->windows->width = 1280;                 // Définition de la largeur de la fenetre
  (*global_structure)->windows->height = 720;                 // Définition de la hauteur de la fenetre
  (*global_structure)->windows->size_coef = 2;                // Définition du Coefficient d'échelle (ne vraiment pas modifier svp)
  (*global_structure)->windows->font = malloc(sizeof(TTF_Font*));

  if ((*global_structure)->windows == NULL)
  {
    printf("Erreur a l'allocation de la police : %s\n",SDL_GetError());
    retour = -1;
  }

  return(retour);
}
/**
  * \function create_window_render
  * \brief Creation de la fenetre
  * \param window : la fenetre SDL
  * \param renderer : le renderer SDL
  * \param window_width : la taille définit pour la longueur de la fenetre
  * \param window_height : la taille définit pour la largeur de la fenetre
*/
int create_window_render(SDL_Window ** window, SDL_Renderer ** renderer,int window_width, int window_height)
{
  //SDL_WINDOW_FULLSCREEN
  (*window) = SDL_CreateWindow("Pokemon ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_MAXIMIZED );

  SDL_Surface * icon = IMG_Load("./src/asset/icon.png");
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


/**
  * \function destroy_window_render
  * \brief destruction de la fenetre
  * \param window : la fenetre SDL
  * \param renderer : le renderer SDL
*/
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
/**
  * \function limit_fps
  * \brief limitation des images par secondes du jeu
  * \param limit : la fenetre SDL
  * \param fps_limit : le renderer SDL
*/
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
