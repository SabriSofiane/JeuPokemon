#include "../include/motor.h"

void menu(motor_t ** motor)
{
  if ((*motor)->keys.m_key == 0))
  return;

  for (size_t i = 0; i < 6; i++) {
    SDL_Rect menu;
    menu.x = 0;
    menu.y = 60*i;
    menu.w = 80;
    menu.h = 52;

    int image_width,image_height;
    SDL_QueryTexture((*motor)->menu->menu_textures[i], NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->menu->menu_textures[i], NULL, &menu);
  }

  SDL_Surface * surface;

  surface = IMG_Load("C:/Users/Elias/Downloads/PSPEvolved 0.10.4/PSPEvolved 0.10.4/Graphics/Pictures/Menu_curseur.png");

  if (surface == NULL)
  printf("Erreur\n");

  SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect menu;
  menu.x = 0;
  menu.y = 60* (*motor)->menu->el_menu_select;
  menu.w = 80;
  menu.h = 52;

  int image_width,image_height;

  SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);
  SDL_DestroyTexture(menu_texture);

}
