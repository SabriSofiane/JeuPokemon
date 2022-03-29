#include "../include/motor.h"
#include "../include/menu.h"
#include "../include/text.h"
#include "../include/textures.h"
#include "../include/string_matrice.h"

void menu(motor_t ** motor)
{
  /*
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
  */
}

int init_menu(motor_t ** motor)
{
  (*motor)->menu = malloc(sizeof(menu_t));

  (*motor)->menu->el_menu_select = 0;
  (*motor)->menu->el_battle_menu_select = 0;
  (*motor)->menu->el_battle_menu_atk_select = 0;
  (*motor)->menu->el_menu_pokemon_select=0;
  (*motor)->menu->el_menu_save_select=0;
  (*motor)->menu->el_menu_main_screen_select=0;
  (*motor)->menu->choixCombat = 1;
  (*motor)->menu->taille = 6;
  (*motor)->menu->menu_textures = malloc(sizeof(SDL_Texture*)*10);
  (*motor)->menu->speech_bubble = 0;
  (*motor)->menu->menu_page_acceuil=1;
  (*motor)->menu->menu_battle=1;
  (*motor)->menu->menu_battle_attaque=0;
  (*motor)->menu->menu_pokemon=0;
  (*motor)->menu->menu_bag=0;
  (*motor)->menu->menu_shop=0;
  (*motor)->menu->menu_save=0;
  (*motor)->menu->menu_principal=0;
  (*motor)->menu->current_pokemon = 1;
  (*motor)->menu->save_available = 0;
}

void speech_bubble(motor_t ** motor)
{
    if ((*motor)->menu->speech_bubble == 1)
    {
      load_texture(&(*motor)->renderer,&(*motor)->menu->texture_speech_bubble,"src/asset/dialogues/GUI/messagedummy.png");
      if ((*motor)->menu->texture_speech_bubble== NULL)
      {
        printf("Erreur au chargement de la texture du speech_bubble : %s\n",SDL_GetError());
      }

      SDL_Rect rectBackground;
      rectBackground.x=200;
      rectBackground.y=550;
      rectBackground.w=900;
      rectBackground.h=244/2;
      int image_width,image_height;
      SDL_QueryTexture((*motor)->menu->texture_speech_bubble, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->texture_speech_bubble, NULL, &rectBackground);
      char string[300];
      strncpy(string,(*motor)->menu->speech_bubble_text,strlen((*motor)->menu->speech_bubble_text));
      //printf("%s\n",string );
      text_draw(motor,string,250,580);
    }
  }