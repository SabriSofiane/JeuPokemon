#include "../lib/pokemon/motor.h"
#include "../lib/pokemon/text.h"

void text_init(motor_t ** motor)
{
  TTF_Init();
  (*motor)->windows->font = TTF_OpenFont("arial.ttf", 25);
}

void text_draw(motor_t ** motor,char * text,int x,int y) {
  SDL_Color color = { 23, 101, 125 };
  SDL_Surface * surface = TTF_RenderText_Solid((*motor)->windows->font,
    text, color);


  SDL_Texture * texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);

  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = { x, y, texW, texH };

  SDL_RenderCopy((*motor)->renderer, texture, NULL, &dstrect);
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
