/**
  * \file textures.c
  * \brief fichier pour les textures
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/global_structure.h"
#include "../include/textures.h"

/**
  * \function init_texture
  * \brief fonction d'initialisation des textures
  * \param global_structure : le moteur de jeu
*/
int init_texture(global_structure_t ** global_structure )
{
  int retour = 0;
  (*global_structure)->textures = malloc(sizeof(texture_t));

  if ((*global_structure)->textures == NULL)
  {
    printf("Erreur a l'allocation de la structure textures : %s\n",SDL_GetError());
    retour = -1;
  }

  (*global_structure)->textures->texture_map = malloc(sizeof(SDL_Texture*));

  if ((*global_structure)->textures->texture_map == NULL)
  {
    printf("Erreur a l'allocation de la structure texture pour la map : %s\n",SDL_GetError());
    retour = -1;
  }

  return(retour);
}

/**
  * \function load_texture
  * \brief fonction d'application de texture sur une surface
  * \param renderer : le renderer de la SDL
  * \param texture : la texture de la SDL
  * \param path : le chemin de la texture
*/
void load_texture(SDL_Renderer ** renderer,SDL_Texture ** texture,char * path)
{
  SDL_Surface * surface = IMG_Load(path);
  *texture = SDL_CreateTextureFromSurface(*renderer, surface);
  SDL_FreeSurface(surface);
}
