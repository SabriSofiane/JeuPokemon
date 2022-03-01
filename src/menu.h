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
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_Back.png");
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
    //sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu%i.png",i);
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
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");
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
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/bagfond.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/bagfond.png");
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
  //SDL_SetRenderDrawColor((*motor)->renderer,255,0,0,255);
  SDL_Surface * surface;
  char* font_path = "src/Pokemon_GB.ttf";
  SDL_Color textColor = {0,0,0,0};
  int image_width,image_height;

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battlebacks/battle11.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/battle11.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackground = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect rectBackground;


  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=1280;
  rectBackground.h=720;

  SDL_QueryTexture(textureBackground, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackground, NULL, &rectBackground);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixMultiple.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/ChoixMultiple.png");
  if (surface == NULL)
  printf("Erreur Battlemenu\n");
  SDL_Texture * textureBattleMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect rectBattleMenu;

  rectBattleMenu.x=300;
  rectBattleMenu.y=550;
  rectBattleMenu.w=640;
  rectBattleMenu.h=144;

  SDL_QueryTexture(textureBattleMenu, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBattleMenu, NULL, &rectBattleMenu);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite4.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite4.png");
  SDL_Texture * cadreEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectCadreEnnemi;
  rectCadreEnnemi.x=300;
  rectCadreEnnemi.y=100;
  rectCadreEnnemi.w=302;
  rectCadreEnnemi.h=108;
  SDL_QueryTexture(cadreEnnemi_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, cadreEnnemi_texture, NULL, &rectCadreEnnemi);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite3.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite3.png");
  SDL_Texture * cadreJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectCadreJoueur;
  rectCadreJoueur.x=640;
  rectCadreJoueur.y=440;
  rectCadreJoueur.w=302;
  rectCadreJoueur.h=108;
  SDL_QueryTexture(cadreJoueur_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, cadreJoueur_texture, NULL, &rectCadreJoueur);


  SDL_Rect hplinePlayer;
  hplinePlayer.x=780;
  hplinePlayer.y=490;
  hplinePlayer.w=150;
  hplinePlayer.h=20;
  SDL_SetRenderDrawColor((*motor)->renderer,0,255,0,255);
  SDL_RenderFillRect((*motor)->renderer,&hplinePlayer);

  SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/hpbar.png");
  SDL_Texture * hpbarJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectHpbarJoueur;
  rectHpbarJoueur.x=740;
  rectHpbarJoueur.y=490;
  rectHpbarJoueur.w=195;
  rectHpbarJoueur.h=21;
  SDL_QueryTexture(hpbarJoueur_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, hpbarJoueur_texture, NULL, &rectHpbarJoueur);


  SDL_Rect hplineEnnemi;
  hplineEnnemi.x=350;
  hplineEnnemi.y=160;
  hplineEnnemi.w=150;
  hplineEnnemi.h=20;
  SDL_SetRenderDrawColor((*motor)->renderer,0,255,0,255);
  SDL_RenderFillRect((*motor)->renderer,&hplineEnnemi);

  SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/hpbar.png");
  SDL_Texture * hpbarEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectHpbarEnnemi;
  rectHpbarEnnemi.w=195;
  rectHpbarEnnemi.h=21;
  rectHpbarEnnemi.x=310;
  rectHpbarEnnemi.y=160;
  SDL_QueryTexture(hpbarEnnemi_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, hpbarEnnemi_texture, NULL, &rectHpbarEnnemi);




  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");
  if (surface == NULL)
  printf("Erreur\n");

  SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);


  SDL_Rect menu;


  if((*motor)->menu->el_battle_menu_select < 2){
    menu.x = 200+425;
    menu.y = 550+54* (*motor)->menu->el_battle_menu_select+18;
  }
  if ((*motor)->menu->el_battle_menu_select == 2)
  {
    menu.x = 200+580;
    menu.y = 550+18;
  }
  if ((*motor)->menu->el_battle_menu_select == 3)
  {
    menu.x = 200+580;
    menu.y = 550+72;
  }

  menu.w = 155;
  menu.h = 55;
  SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);


  TTF_Font *font = TTF_OpenFont(font_path, 14);
  SDL_Texture *textureTextMenu,*textureTextPokemonJoueur,*textureTextPokemonEnnemi,*textureTextLvlPJoueur,*textureTextLvlPEnnemi,*textureTextHpPJoueur;
  SDL_Rect rectTextMenu,rectTextPokemonJoueur,rectTextPokemonEnnemi,rectTextLvlPJoueur,rectTextLvlPEnnemi,rectTextHpPJoueur;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 335, 585, "Que faire?", font, &textureTextMenu, &rectTextMenu,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextMenu, NULL, &rectTextMenu);

  get_text_and_rect((*motor)->renderer, 680, 460, "pokemonJ", font, &textureTextPokemonJoueur, &rectTextPokemonJoueur,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokemonJoueur, NULL, &rectTextPokemonJoueur);

  get_text_and_rect((*motor)->renderer, 320, 125, "pokemonE", font, &textureTextPokemonEnnemi, &rectTextPokemonEnnemi,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokemonEnnemi, NULL, &rectTextPokemonEnnemi);

  get_text_and_rect((*motor)->renderer, 880, 460, "Lv", font, &textureTextLvlPJoueur, &rectTextLvlPJoueur,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextLvlPJoueur, NULL, &rectTextLvlPJoueur);

  get_text_and_rect((*motor)->renderer, 520, 125, "Lv", font, &textureTextLvlPEnnemi, &rectTextLvlPEnnemi,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextLvlPEnnemi, NULL, &rectTextLvlPEnnemi);

  get_text_and_rect((*motor)->renderer, 800, 515, "hp/hpMax", font, &textureTextHpPJoueur, &rectTextHpPJoueur,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextHpPJoueur, NULL, &rectTextHpPJoueur);

  SDL_DestroyTexture(textureBackground);
  SDL_DestroyTexture(menu_texture);
  SDL_DestroyTexture(textureBattleMenu);
  SDL_DestroyTexture(cadreEnnemi_texture);
  SDL_DestroyTexture(cadreJoueur_texture);
  SDL_DestroyTexture(hpbarJoueur_texture);
  SDL_DestroyTexture(hpbarEnnemi_texture);

}

void menu_Battle_Attaque(motor_t ** motor){
  SDL_Surface * surface;
  char* font_path = "src/Pokemon_GB.ttf";
  SDL_Color textColor = {0,0,0,0};
  int image_width,image_height;

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battlebacks/battle11.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/battle11.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackground = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect rectBackground;


  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=1280;
  rectBackground.h=720;

  SDL_QueryTexture(textureBackground, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackground, NULL, &rectBackground);


  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite4.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite4.png");
  SDL_Texture * cadreEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectCadreEnnemi;
  rectCadreEnnemi.x=300;
  rectCadreEnnemi.y=100;
  rectCadreEnnemi.w=302;
  rectCadreEnnemi.h=108;
  SDL_QueryTexture(cadreEnnemi_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, cadreEnnemi_texture, NULL, &rectCadreEnnemi);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite3.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite3.png");
  SDL_Texture * cadreJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectCadreJoueur;
  rectCadreJoueur.x=640;
  rectCadreJoueur.y=440;
  rectCadreJoueur.w=302;
  rectCadreJoueur.h=108;
  SDL_QueryTexture(cadreJoueur_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, cadreJoueur_texture, NULL, &rectCadreJoueur);



  SDL_Rect hplinePlayer;
  hplinePlayer.x=780;
  hplinePlayer.y=490;
  hplinePlayer.w=150;
  hplinePlayer.h=20;
  SDL_SetRenderDrawColor((*motor)->renderer,0,255,0,255);
  SDL_RenderFillRect((*motor)->renderer,&hplinePlayer);

  SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/hpbar.png");
  SDL_Texture * hpbarJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectHpbarJoueur;
  rectHpbarJoueur.x=740;
  rectHpbarJoueur.y=490;
  rectHpbarJoueur.w=195;
  rectHpbarJoueur.h=21;
  SDL_QueryTexture(hpbarJoueur_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, hpbarJoueur_texture, NULL, &rectHpbarJoueur);


  SDL_Rect hplineEnnemi;
  hplineEnnemi.x=350;
  hplineEnnemi.y=160;
  hplineEnnemi.w=150;
  hplineEnnemi.h=20;
  SDL_SetRenderDrawColor((*motor)->renderer,0,255,0,255);
  SDL_RenderFillRect((*motor)->renderer,&hplineEnnemi);

  SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/hpbar.png");
  SDL_Texture * hpbarEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectHpbarEnnemi;
  rectHpbarEnnemi.w=195;
  rectHpbarEnnemi.h=21;
  rectHpbarEnnemi.x=310;
  rectHpbarEnnemi.y=160;
  SDL_QueryTexture(hpbarEnnemi_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, hpbarEnnemi_texture, NULL, &rectHpbarEnnemi);


  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixAttaque.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/ChoixAttaque.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBattleAttackMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect rectBattleAttackMenu;

  rectBattleAttackMenu.x=300;
  rectBattleAttackMenu.y=550;
  rectBattleAttackMenu.w=640;
  rectBattleAttackMenu.h=144;

  SDL_QueryTexture(textureBattleAttackMenu, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBattleAttackMenu, NULL, &rectBattleAttackMenu);

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");

  if (surface == NULL)
  printf("Erreur\n");

  SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);

  SDL_Rect menu;
  //menu.x = 325;

  if((*motor)->menu->el_battle_menu_select < 2){
    menu.x = 300+35;
    menu.y = 550+54* (*motor)->menu->el_battle_menu_select+18;
  }
  if ((*motor)->menu->el_battle_menu_select == 2)
  {
    menu.x = 200+360;
    menu.y = 550+18;
  }
  if ((*motor)->menu->el_battle_menu_select == 3)
  {
    menu.x = 200+360;
    menu.y = 550+72;
  }

  menu.w = 220;
  menu.h = 54;
  SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);


  TTF_Font *font = TTF_OpenFont(font_path, 14);
  SDL_Texture *textureTextAbility1,*textureTextAbility2,*textureTextAbility3,*textureTextAbility4,*textureTextPP,*textureTextType,*textureTextPokemonJoueur,*textureTextPokemonEnnemi,*textureTextLvlPJoueur,*textureTextLvlPEnnemi,*textureTextHpPJoueur;
  SDL_Rect rectTextAbility1,rectTextAbility2,rectTextAbility3,rectTextAbility4,rectTextPP,rectTextType,rectTextPokemonJoueur,rectTextPokemonEnnemi,rectTextLvlPJoueur,rectTextLvlPEnnemi,rectTextHpPJoueur;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 350, 590, "Ability1", font, &textureTextAbility1, &rectTextAbility1,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility1, NULL, &rectTextAbility1);

  get_text_and_rect((*motor)->renderer, 350, 645, "Ability2", font, &textureTextAbility2, &rectTextAbility2,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility2, NULL, &rectTextAbility2);

  get_text_and_rect((*motor)->renderer, 600, 590, "Ability3", font, &textureTextAbility3, &rectTextAbility3,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility3, NULL, &rectTextAbility3);

  get_text_and_rect((*motor)->renderer, 600, 645, "Ability4", font, &textureTextAbility4, &rectTextAbility4,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextAbility4, NULL, &rectTextAbility4);

  get_text_and_rect((*motor)->renderer, 825, 580, "PP/PPMax", font, &textureTextPP, &rectTextPP,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPP, NULL, &rectTextPP);

  get_text_and_rect((*motor)->renderer, 825, 650, "Type", font, &textureTextType, &rectTextType,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextType, NULL, &rectTextType);

  get_text_and_rect((*motor)->renderer, 680, 460, "pokemonJ", font, &textureTextPokemonJoueur, &rectTextPokemonJoueur,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokemonJoueur, NULL, &rectTextPokemonJoueur);

  get_text_and_rect((*motor)->renderer, 320, 125, "pokemonE", font, &textureTextPokemonEnnemi, &rectTextPokemonEnnemi,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextPokemonEnnemi, NULL, &rectTextPokemonEnnemi);

  get_text_and_rect((*motor)->renderer, 880, 460, "Lv", font, &textureTextLvlPJoueur, &rectTextLvlPJoueur,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextLvlPJoueur, NULL, &rectTextLvlPJoueur);

  get_text_and_rect((*motor)->renderer, 520, 125, "Lv", font, &textureTextLvlPEnnemi, &rectTextLvlPEnnemi,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextLvlPEnnemi, NULL, &rectTextLvlPEnnemi);

  get_text_and_rect((*motor)->renderer, 800, 515, "hp/hpMax", font, &textureTextHpPJoueur, &rectTextHpPJoueur,textColor);
  SDL_RenderCopy((*motor)->renderer, textureTextHpPJoueur, NULL, &rectTextHpPJoueur);



  SDL_DestroyTexture(textureBackground);
  SDL_DestroyTexture(menu_texture);
  SDL_DestroyTexture(textureBattleAttackMenu);
  SDL_DestroyTexture(cadreEnnemi_texture);
  SDL_DestroyTexture(cadreJoueur_texture);
  SDL_DestroyTexture(hpbarJoueur_texture);
  SDL_DestroyTexture(hpbarEnnemi_texture);
}

void speech_bubble(motor_t ** motor)
{
  SDL_Surface * surface;
  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/messagedummy.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/messagedummy.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureSpeechBubble = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectBackground;
  char* font_path = "src/Pokemon_GB.ttf";
  SDL_Color textColor = {0,0,0,0};

  rectBackground.x=200;
  rectBackground.y=550;
  rectBackground.w=900;
  rectBackground.h=144;
  int image_width,image_height;
  SDL_QueryTexture(textureSpeechBubble, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureSpeechBubble, NULL, &rectBackground);



  SDL_DestroyTexture(textureSpeechBubble);
}

void menu_shop(motor_t ** motor){
  SDL_Surface * surface;
  SDL_Color textColor = {0,0,0,0};
  char* font_path = "src/Pokemon_GB.ttf";
  int image_width,image_height;

  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/boxback.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/boxback.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureBackgroundImage = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectBackground;

  rectBackground.x=0;
  rectBackground.y=0;
  rectBackground.w=640;
  rectBackground.h=480;

  SDL_QueryTexture(textureBackgroundImage, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureBackgroundImage, NULL, &rectBackground);


  surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/shopfond.png");
  //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/shopfond.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureShop = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectShop;

  rectShop.x=0;
  rectShop.y=0;
  rectShop.w=640;
  rectShop.h=480;

  SDL_QueryTexture(textureShop, NULL, NULL,  &image_width , &image_height);
  SDL_RenderCopy((*motor)->renderer, textureShop, NULL, &rectShop);


  TTF_Font *font = TTF_OpenFont(font_path, 20);
  SDL_Texture *textureTextMenu,*textureTextPokedex,*textureTextPokemon,*textureTextBag,*textureTextId,*textureTextSave,*textureTextExit;
  SDL_Rect rectTextMenu,rectTextPokedex,rectTextPokemon,rectTextBag,rectTextId,rectTextSave,rectTextExit;

  if(font == NULL){
    printf("Erreur font\n");
  }
  get_text_and_rect((*motor)->renderer, 60, 40, "Boutique", font, &textureTextMenu, &rectTextMenu,textColor);
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
  SDL_DestroyTexture(textureBackgroundImage);
  SDL_DestroyTexture(textureShop);
}
