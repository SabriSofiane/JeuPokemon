#include "../include/motor.h"
#include "../include/text.h"

int text_init(motor_t ** motor)
{
  int retour = 0;
  TTF_Init();

  (*motor)->windows->font = TTF_OpenFont("./fonts/PKMN_RBYGSC.ttf", 25);

  if ((*motor)->windows->font == NULL)
  {
    printf("Erreur a la definition de la police\n");
    retour = -1;
  }

  return(retour);
}

void set_text_font_size(motor_t ** motor,int size)
{
  (*motor)->windows->font = TTF_OpenFont("./fonts/PKMN_RBYGSC.ttf", size);
}

void text_draw(motor_t ** motor,char * text,int x,int y)
{
  SDL_Color color = { 23, 101, 125 ,255};

  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % strlen(text);

  SDL_Surface * surface = TTF_RenderText_Solid((*motor)->windows->font,
  text, color);


  SDL_Texture * texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  int text_width = surface->w;
  int text_height = surface->h;
  SDL_Rect textRect;
  textRect.x = x;
  textRect.y = y;
  textRect.w = text_width;
  textRect.h = text_height;

  SDL_QueryTexture(texture, NULL, NULL, &text_width, &text_height);


  SDL_RenderCopy((*motor)->renderer, texture, NULL, &textRect);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
}

void text_quit(motor_t ** motor)
{
  TTF_CloseFont((*motor)->windows->font);
  TTF_Quit();

  free((*motor)->windows->font);
  (*motor)->windows->font = NULL;
}