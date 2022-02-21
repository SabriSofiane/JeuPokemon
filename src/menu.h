void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect,SDL_Color textColor) {
           //cette fonction permet de creer un rectangle configurable et un f pour un texte mis en paramètre
    int text_width;
    int text_height;
    SDL_Surface *surface;


    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}


void menu(motor_t ** motor)
{
  SDL_Surface * surface;
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_Back.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectBackground;
  char* font_path = "src/Pokemon_GB.ttf";
  SDL_Color textColor = {255, 255, 255, 0};
  SDL_Rect menu;
  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=640;
  rectBackground.h=480;
  int image_width,image_height;
  SDL_QueryTexture(textureBackgroundMenu, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackgroundMenu, NULL, &rectBackground);

  for (size_t i = 0; i < 6; i++) {

    char path[100];
    sprintf(path,"C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu%i.png",i);
    surface = IMG_Load(path);
    if (surface == NULL)
    printf("Erreur Icone menu\n");

    (*motor)->menu->menu_textures[i] = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
  }


  for (size_t i = 0; i < 6; i++) {

    menu.x = 230;
    menu.y = 54*i+40;
    menu.w = 80;
    menu.h = 52;

    //int image_width,image_height;
    SDL_QueryTexture((*motor)->menu->menu_textures[i], NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->menu->menu_textures[i], NULL, &menu);
  }

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");

  if (surface == NULL)
  printf("Erreur\n");

  SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);


  menu.x = 230;
  menu.y = 54* (*motor)->menu->el_menu_select+40;
  menu.w = 80;
  menu.h = 52;

  TTF_Font *font = TTF_OpenFont(font_path, 18);
  SDL_Texture *textureTextMenu,*textureTextPokedex,*textureTextPokemon,*textureTextBag,*textureTextId,*textureTextSave,*textureTextExit;
  SDL_Rect rectTextMenu,rectTextPokedex,rectTextPokemon,rectTextBag,rectTextId,rectTextSave,rectTextExit;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 100, 8, "MENU", font, &textureTextMenu, &rectTextMenu,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextMenu, NULL, &rectTextMenu);

  get_text_and_rect((*motor)->renderer, 25, 60, "Pokedex", font, &textureTextPokedex, &rectTextPokedex,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokedex, NULL, &rectTextPokedex);

  get_text_and_rect((*motor)->renderer, 25, 115, "Pokemon", font, &textureTextPokemon, &rectTextPokemon,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokemon, NULL, &rectTextPokemon);

  get_text_and_rect((*motor)->renderer, 25, 165, "Inventaire", font, &textureTextBag, &rectTextBag,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextBag, NULL, &rectTextBag);

  get_text_and_rect((*motor)->renderer, 25, 220, "Id", font, &textureTextId, &rectTextId,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextId, NULL, &rectTextId);

  get_text_and_rect((*motor)->renderer, 25, 275, "Sauvegarder", font, &textureTextSave, &rectTextSave,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextSave, NULL, &rectTextSave);

  get_text_and_rect((*motor)->renderer, 25, 325, "Quitter", font, &textureTextExit, &rectTextExit,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextExit, NULL, &rectTextExit);

  SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);
  SDL_DestroyTexture(menu_texture);
  SDL_DestroyTexture(textureBackgroundMenu);
}








void menu_Bag(motor_t ** motor){
  SDL_Surface * surface;
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Bagfond.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectBackground;
  char* font_path = "src/Pokemon_GB.ttf";
  SDL_Color textColor = {0,0,0,0};

  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=640;
  rectBackground.h=480;
  int image_width,image_height;
  SDL_QueryTexture(textureBackgroundMenu, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackgroundMenu, NULL, &rectBackground);


  TTF_Font *font = TTF_OpenFont(font_path, 20);
  SDL_Texture *textureTextMenu,*textureTextPokedex,*textureTextPokemon,*textureTextBag,*textureTextId,*textureTextSave,*textureTextExit;
  SDL_Rect rectTextMenu,rectTextPokedex,rectTextPokemon,rectTextBag,rectTextId,rectTextSave,rectTextExit;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 120, 40, "BAG", font, &textureTextMenu, &rectTextMenu,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextMenu, NULL, &rectTextMenu);

  get_text_and_rect((*motor)->renderer, 300, 60, "item0", font, &textureTextPokedex, &rectTextPokedex,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokedex, NULL, &rectTextPokedex);

  get_text_and_rect((*motor)->renderer, 300, 115, "item1", font, &textureTextPokemon, &rectTextPokemon,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokemon, NULL, &rectTextPokemon);

  get_text_and_rect((*motor)->renderer, 300, 165, "item2", font, &textureTextBag, &rectTextBag,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextBag, NULL, &rectTextBag);

  get_text_and_rect((*motor)->renderer, 300, 225, "item3", font, &textureTextSave, &rectTextSave,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextSave, NULL, &rectTextSave);

  get_text_and_rect((*motor)->renderer, 25, 235, "Img", font, &textureTextId, &rectTextId,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextId, NULL, &rectTextId);

  get_text_and_rect((*motor)->renderer, 25, 325, "itemDesc", font, &textureTextExit, &rectTextExit,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextExit, NULL, &rectTextExit);
  SDL_DestroyTexture(textureBackgroundMenu);
}



void menu_Battle(motor_t ** motor){
  SDL_Surface * surface;
  char* font_path = "src/Pokemon_GB.ttf";
  int image_width,image_height;
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixMultiple.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect rectBackground;
  SDL_Color textColor = {0,0,0,0};

  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=640;
  rectBackground.h=144;

  SDL_QueryTexture(textureBackgroundMenu, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackgroundMenu, NULL, &rectBackground);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");

  if (surface == NULL)
  printf("Erreur\n");

  SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect menu;
  //menu.x = 325;

  if((*motor)->menu->el_battle_menu_select < 2){
    menu.x = 325;
    menu.y = 54* (*motor)->menu->el_battle_menu_select+18;
  }
  if ((*motor)->menu->el_battle_menu_select == 2)
  {
    menu.x = 480;
    menu.y = 18;
  }
  if ((*motor)->menu->el_battle_menu_select == 3)
  {
    menu.x = 480;
    menu.y = 72;
  }

  menu.w = 155;
  menu.h = 55;
  SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);


  TTF_Font *font = TTF_OpenFont(font_path, 14);
  SDL_Texture *textureTextMenu;
  SDL_Rect rectTextMenu;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 35, 35, "Que faire?", font, &textureTextMenu, &rectTextMenu,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextMenu, NULL, &rectTextMenu);

  SDL_DestroyTexture(menu_texture);
  SDL_DestroyTexture(textureBackgroundMenu);

}

void menu_Battle_Attaque(motor_t ** motor){
  SDL_Surface * surface;
  char* font_path = "src/Pokemon_GB.ttf";
  int image_width,image_height;
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixAttaque.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect rectBackground;
  SDL_Color textColor = {0,0,0,0};

  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=640;
  rectBackground.h=144;

  SDL_QueryTexture(textureBackgroundMenu, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackgroundMenu, NULL, &rectBackground);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");

  if (surface == NULL)
  printf("Erreur\n");

  SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect menu;
  //menu.x = 325;

  if((*motor)->menu->el_battle_menu_select < 2){
    menu.x = 35;
    menu.y = 54* (*motor)->menu->el_battle_menu_select+18;
  }
  if ((*motor)->menu->el_battle_menu_select == 2)
  {
    menu.x = 260;
    menu.y = 18;
  }
  if ((*motor)->menu->el_battle_menu_select == 3)
  {
    menu.x = 260;
    menu.y = 72;
  }

  menu.w = 220;
  menu.h = 54;
  SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);


  TTF_Font *font = TTF_OpenFont(font_path, 14);
  SDL_Texture *textureTextAbility1,*textureTextAbility2,*textureTextAbility3,*textureTextAbility4;
  SDL_Rect rectTextAbility1,rectTextAbility2,rectTextAbility3,rectTextAbility4;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 50, 40, "Ability1", font, &textureTextAbility1, &rectTextAbility1,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility1, NULL, &rectTextAbility1);

  get_text_and_rect((*motor)->renderer, 50, 95, "Ability2", font, &textureTextAbility2, &rectTextAbility2,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility2, NULL, &rectTextAbility2);

  get_text_and_rect((*motor)->renderer, 300, 40, "Ability3", font, &textureTextAbility3, &rectTextAbility3,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility3, NULL, &rectTextAbility3);

  get_text_and_rect((*motor)->renderer, 300, 95, "Ability4", font, &textureTextAbility4, &rectTextAbility4,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility4, NULL, &rectTextAbility4);

  SDL_DestroyTexture(menu_texture);
  SDL_DestroyTexture(textureBackgroundMenu);
}
