/**
  * \file text.c
  * \brief fichier dédié pour les textes à écrire
  * \author OKAT Elias
  * \version 1
  * \date 8 mars 22
*/
#include "../include/global_structure.h"
#include "../include/text.h"
/**
  * \function text_init
  * \brief fonction d'initialisation du module de texte
  * \param global_structure : le moteur de jeu
*/
int text_init(global_structure_t ** global_structure)
{
  int retour = 0;
  TTF_Init();

  (*global_structure)->windows->font = TTF_OpenFont("./fonts/PKMN_RBYGSC.ttf", 25);

  if ((*global_structure)->windows->font == NULL)
  {
    printf("Erreur a la definition de la police\n");
    retour = -1;
  }

  return(retour);
}
/**
  * \function set_text_font_size
  * \brief fonction de paramètrage de la taille de la police de texte
  * \param global_structure : le moteur de jeu
  * \param size : la taille de police
*/
void set_text_font_size(global_structure_t ** global_structure,int size)
{
  (*global_structure)->windows->font = TTF_OpenFont("./fonts/PKMN_RBYGSC.ttf", size);
}
/**
  * \function text_draw
  * \brief fonction d'initialisation du module de texte
  * \param global_structure : le moteur de jeu
*/
void text_draw(global_structure_t ** global_structure,char * text,int x,int y)
{
  SDL_Color color = { 23, 101, 125 ,255};

  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % strlen(text);

  SDL_Surface * surface = TTF_RenderText_Solid((*global_structure)->windows->font,
  text, color);


  SDL_Texture * texture = SDL_CreateTextureFromSurface((*global_structure)->renderer, surface);
  int text_width = surface->w;
  int text_height = surface->h;
  SDL_Rect textRect;
  textRect.x = x;
  textRect.y = y;
  textRect.w = text_width;
  textRect.h = text_height;

  SDL_QueryTexture(texture, NULL, NULL, &text_width, &text_height);


  SDL_RenderCopy((*global_structure)->renderer, texture, NULL, &textRect);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
}
/**
  * \function text_quit
  * \brief fonction de destruction du texte
  * \param global_structure : le moteur de jeu
*/
void text_quit(global_structure_t ** global_structure)
{
  TTF_CloseFont((*global_structure)->windows->font);
  TTF_Quit();

  free((*global_structure)->windows->font);
  (*global_structure)->windows->font = NULL;
}
