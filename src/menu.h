/**
  * \file menu.c
  * \brief fichier d'interface graphique
  * \author Sofiane SABRI
  * \version 0.5
  * \date 8 mars 22
*/


/**
  * \function get_text_and_rect
  * \brief cette fonction permet de creer un rectangle configurable et un font pour un texte mis en paramètre
  * \param renderer : rendu
  * \param x : position x du texte
  * \param y : position y du texte
  * \param text : texte à afficher
  * \param font : la police du texte à afficher
  * \param texture : la texture du texte à afficher
  * \param rect : le rectangle pour positioner le texte à afficher
  * \param texColor : Couleur du texte à afficher
*/
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
  TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect,SDL_Color textColor) {

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

  /**
    * \function color
    * \brief cette fonction permet d'attribuer la couleur d'un élément, utilisé pour les rectangles
    * \param r : valeur de la couleur rouge (0-255)
    * \param g : valeur de la couleur vert (0-255)
    * \param b : valeur de la couleur bleu (0-255)
    * \param a : valeur de la transparence (0-255)
    * \param a : valeur de la transparence (0-255)
    * \return col: un tableau avec les valeurs mis en paramètre
  */
  SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
   SDL_Color col = {r,g,b,a};
   return col;
}
/**
  * \function RenderHPBar
  * \brief cette fonction permet de modifier le rectangle de bar de vie avec un pourcentage de vie: vie/vieMaximum
  * \param renderer : rendu
  * \param x : position x du rectangle
  * \param y : position y du rectangle
  * \param w : largeur du rectangle
  * \param h : hauteur du rectangle
  * \param percent : pourcentage de vie d'un pokemon
  * \param FGColor : couleur du rectangle en premier plan
  * \param BGColor : couleur du rectangle en arrière plan
  * \param renderer: rendu du jeu
*/
void RenderHPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor,SDL_Renderer *renderer){

   if(percent > 1.f)
   {
     percent = 1.f;
   }
   else if(percent<0.f){
     percent= 0.f;
   }else{
     percent = percent;
   }
   SDL_Color old;
   SDL_GetRenderDrawColor(renderer, &old.r, &old.g, &old.g, &old.a);
   SDL_Rect bgrect = { x, y, w, h };
   SDL_SetRenderDrawColor(renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
   SDL_RenderFillRect(renderer, &bgrect);
   SDL_SetRenderDrawColor(renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
   int pw = (int)((float)w * percent);
   int px = x + (w - pw);
   SDL_Rect fgrect = { px, y, pw, h };
   SDL_RenderFillRect(renderer, &fgrect);
   SDL_SetRenderDrawColor(renderer, old.r, old.g, old.b, old.a);
}

  void menu(motor_t ** motor)
  {
    SDL_Surface * surface;
    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_Back.png");
    surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_Back.png");
    if (surface == NULL)
    printf("Erreur Background\n");
    SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectBackground;
    char* font_path = "Pokemon_GB.ttf";
    SDL_Color textColor = {255, 255, 255, 0};
    SDL_Rect menu;
    rectBackground.x=0;
    rectBackground.y=0;
    rectBackground.w=640;
    rectBackground.h=480;
    int image_width,image_height;
    SDL_QueryTexture(textureBackgroundMenu, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, textureBackgroundMenu, NULL, &rectBackground);

    for (int i = 0; i < 6; i++) {

      char path[100];
      //sprintf(path,"C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu%i.png",i);
      sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu%i.png",i);
      surface = IMG_Load(path);
      if (surface == NULL)
      printf("Erreur Icone menu\n");

      (*motor)->menu->menu_textures[i] = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
    }


    for (int i = 0; i < 6; i++) {

      menu.x = 230;
      menu.y = 54*i+40;
      menu.w = 80;
      menu.h = 52;

      //int image_width,image_height;
      SDL_QueryTexture((*motor)->menu->menu_textures[i], NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->menu_textures[i], NULL, &menu);
    }

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
    surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");
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
    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/bagfond.png");
    surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/bagfond.png");
    if (surface == NULL)
    printf("Erreur Background\n");
    SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectBackground;
    char* font_path = "Pokemon_GB.ttf";
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
    if(((*motor)->menu->menu_battle)==1){
      //SDL_SetRenderDrawColor((*motor)->renderer,255,0,0,255);
      SDL_Surface * surface;
      char* font_path = "Pokemon_GB.ttf";
      SDL_Color textColor = {0,0,0,0};
      int image_width,image_height;


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battlebacks/battle11.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/battle11.png");
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

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixMultiple.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/ChoixMultiple.png");
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

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite4.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite4.png");
      SDL_Texture * cadreEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectCadreEnnemi;
      rectCadreEnnemi.x=150;
      rectCadreEnnemi.y=100;
      rectCadreEnnemi.w=302;
      rectCadreEnnemi.h=108;
      SDL_QueryTexture(cadreEnnemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, cadreEnnemi_texture, NULL, &rectCadreEnnemi);

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite3.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite3.png");
      SDL_Texture * cadreJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectCadreJoueur;
      rectCadreJoueur.x=840;
      rectCadreJoueur.y=440;
      rectCadreJoueur.w=302;
      rectCadreJoueur.h=108;
      SDL_QueryTexture(cadreJoueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, cadreJoueur_texture, NULL, &rectCadreJoueur);



      float percentAlly = 0.2;
      RenderHPBar(1130,490,-150,20,percentAlly,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);


      SDL_Rect xpLinePlayer;
      xpLinePlayer.x=886;
      xpLinePlayer.y=537;
      xpLinePlayer.w=235  ;
      xpLinePlayer.h=5;
      SDL_SetRenderDrawColor((*motor)->renderer,0,0,255,255);
      SDL_RenderFillRect((*motor)->renderer,&xpLinePlayer);

      SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/hpbar.png");
      SDL_Texture * hpbarJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectHpbarJoueur;
      rectHpbarJoueur.x=940;
      rectHpbarJoueur.y=490;
      rectHpbarJoueur.w=195;
      rectHpbarJoueur.h=21;
      SDL_QueryTexture(hpbarJoueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, hpbarJoueur_texture, NULL, &rectHpbarJoueur);


      float percentEnemi = 0.25;
      RenderHPBar(345,160,-150,20,percentEnemi,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/hpbar.png");
      SDL_Texture * hpbarEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectHpbarEnnemi;
      rectHpbarEnnemi.x=155;
      rectHpbarEnnemi.y=160;
      rectHpbarEnnemi.w=195;
      rectHpbarEnnemi.h=21;

      SDL_QueryTexture(hpbarEnnemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, hpbarEnnemi_texture, NULL, &rectHpbarEnnemi);



      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");
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

      get_text_and_rect((*motor)->renderer, 880, 460, "pokemonJ", font, &textureTextPokemonJoueur, &rectTextPokemonJoueur,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextPokemonJoueur, NULL, &rectTextPokemonJoueur);

      get_text_and_rect((*motor)->renderer, 160, 125, "pokemonE", font, &textureTextPokemonEnnemi, &rectTextPokemonEnnemi,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextPokemonEnnemi, NULL, &rectTextPokemonEnnemi);

      get_text_and_rect((*motor)->renderer, 1080, 460, "Lv", font, &textureTextLvlPJoueur, &rectTextLvlPJoueur,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextLvlPJoueur, NULL, &rectTextLvlPJoueur);

      get_text_and_rect((*motor)->renderer, 360, 125, "Lv", font, &textureTextLvlPEnnemi, &rectTextLvlPEnnemi,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextLvlPEnnemi, NULL, &rectTextLvlPEnnemi);

      get_text_and_rect((*motor)->renderer, 1000, 515, "hp/hpMax", font, &textureTextHpPJoueur, &rectTextHpPJoueur,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextHpPJoueur, NULL, &rectTextHpPJoueur);

      SDL_DestroyTexture(textureBackground);
      SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(textureBattleMenu);
      //  SDL_DestroyTexture(cadreJoueur_texture2);
      SDL_DestroyTexture(cadreEnnemi_texture);
      SDL_DestroyTexture(cadreJoueur_texture);
      SDL_DestroyTexture(hpbarJoueur_texture);
      SDL_DestroyTexture(hpbarEnnemi_texture);
    }
  }

  void menu_Battle_Attaque(motor_t ** motor,Liste_t * player,t_pkm *wild_pkm){
    if(((*motor)->menu->menu_battle_attaque)==1){
      SDL_Surface * surface;
      char* font_path = "Pokemon_GB.ttf";
      SDL_Color textColor = {0,0,0,0};
      int image_width,image_height;

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battlebacks/battle11.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/battle11.png");
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


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite4.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite4.png");
      SDL_Texture * cadreEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectCadreEnnemi;
      rectCadreEnnemi.x=150;
      rectCadreEnnemi.y=100;
      rectCadreEnnemi.w=302;
      rectCadreEnnemi.h=108;
      SDL_QueryTexture(cadreEnnemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, cadreEnnemi_texture, NULL, &rectCadreEnnemi);

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite3.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/battle_sprite3.png");
      SDL_Texture * cadreJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectCadreJoueur;
      rectCadreJoueur.x=840;
      rectCadreJoueur.y=440;
      rectCadreJoueur.w=302;
      rectCadreJoueur.h=108;
      SDL_QueryTexture(cadreJoueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, cadreJoueur_texture, NULL, &rectCadreJoueur);

      float percentAlly = 0.7;
      RenderHPBar(1130,490,-150,20,percentAlly,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);



      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/hpbar.png");
      SDL_Texture * hpbarJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectHpbarJoueur;
      rectHpbarJoueur.x=940;
      rectHpbarJoueur.y=490;
      rectHpbarJoueur.w=195;
      rectHpbarJoueur.h=21;
      SDL_QueryTexture(hpbarJoueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, hpbarJoueur_texture, NULL, &rectHpbarJoueur);

      SDL_Rect xpLinePlayer;
      xpLinePlayer.x=886;
      xpLinePlayer.y=537;
      xpLinePlayer.w=235  ;
      xpLinePlayer.h=5;
      SDL_SetRenderDrawColor((*motor)->renderer,0,0,255,255);
      SDL_RenderFillRect((*motor)->renderer,&xpLinePlayer);


      float percentEnemi = 0.25;
      RenderHPBar(345,160,-150,20,percentEnemi,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);

      SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/hpbar.png");
      SDL_Texture * hpbarEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectHpbarEnnemi;
      rectHpbarEnnemi.x=155;
      rectHpbarEnnemi.y=160;
      rectHpbarEnnemi.w=195;
      rectHpbarEnnemi.h=21;

      SDL_QueryTexture(hpbarEnnemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, hpbarEnnemi_texture, NULL, &rectHpbarEnnemi);


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixAttaque.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battle/ChoixAttaque.png");
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

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");

      if (surface == NULL)
      printf("Erreur\n");

      SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);

      SDL_Rect menu;
      //menu.x = 325;

      if((*motor)->menu->el_battle_menu_atk_select < 2){
        menu.x = 300+35;
        menu.y = 550+54* (*motor)->menu->el_battle_menu_atk_select+18;
      }
      if ((*motor)->menu->el_battle_menu_atk_select == 2)
      {
        menu.x = 200+360;
        menu.y = 550+18;
      }
      if ((*motor)->menu->el_battle_menu_atk_select == 3)
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
      char test[20];

      get_text_and_rect((*motor)->renderer, 350, 590, player->pkm.skill[0], font, &textureTextAbility1, &rectTextAbility1,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextAbility1, NULL, &rectTextAbility1);

      get_text_and_rect((*motor)->renderer, 350, 645, player->pkm.skill[1], font, &textureTextAbility2, &rectTextAbility2,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextAbility2, NULL, &rectTextAbility2);

      get_text_and_rect((*motor)->renderer, 600, 590, player->pkm.skill[2], font, &textureTextAbility3, &rectTextAbility3,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextAbility3, NULL, &rectTextAbility3);

      get_text_and_rect((*motor)->renderer, 600, 645, player->pkm.skill[3], font, &textureTextAbility4, &rectTextAbility4,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextAbility4, NULL, &rectTextAbility4);

      get_text_and_rect((*motor)->renderer, 825, 580, "PP/PPMax", font, &textureTextPP, &rectTextPP,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextPP, NULL, &rectTextPP);

      get_text_and_rect((*motor)->renderer, 825, 650, player->pkm.type1, font, &textureTextType, &rectTextType,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextType, NULL, &rectTextType);

      get_text_and_rect((*motor)->renderer, 880, 460, player->pkm.pkm_name, font, &textureTextPokemonJoueur, &rectTextPokemonJoueur,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextPokemonJoueur, NULL, &rectTextPokemonJoueur);

      get_text_and_rect((*motor)->renderer, 160, 125, wild_pkm->pkm_name, font, &textureTextPokemonEnnemi, &rectTextPokemonEnnemi,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextPokemonEnnemi, NULL, &rectTextPokemonEnnemi);
      sprintf(test,"%d",player->pkm.lvl);
      get_text_and_rect((*motor)->renderer, 1080, 460, test, font, &textureTextLvlPJoueur, &rectTextLvlPJoueur,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextLvlPJoueur, NULL, &rectTextLvlPJoueur);
      sprintf(test,"%d",wild_pkm->hp);
      get_text_and_rect((*motor)->renderer, 360, 125, test, font, &textureTextLvlPEnnemi, &rectTextLvlPEnnemi,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextLvlPEnnemi, NULL, &rectTextLvlPEnnemi);
      sprintf(test,"%d",player->pkm.hp);
      get_text_and_rect((*motor)->renderer, 1000, 515, test  , font, &textureTextHpPJoueur, &rectTextHpPJoueur,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextHpPJoueur, NULL, &rectTextHpPJoueur);



      SDL_DestroyTexture(textureBackground);
      SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(textureBattleAttackMenu);
      SDL_DestroyTexture(cadreEnnemi_texture);
      SDL_DestroyTexture(cadreJoueur_texture);
      SDL_DestroyTexture(hpbarJoueur_texture);
      SDL_DestroyTexture(hpbarEnnemi_texture);
    }

    }



  void speech_bubble(motor_t ** motor,char * text)
  {
    if ((*motor)->menu->speech_bubble == 1)
    {
      printf("speech_bubble\n");
      SDL_Surface * surface;
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/messagedummy.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/messagedummy.png");
      if (surface == NULL)
      printf("Erreur Background\n");
      SDL_Texture * textureSpeechBubble = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectBackground;
      char* font_path = "Pokemon_GB.ttf";
      TTF_Font *font = TTF_OpenFont(font_path, 14);
      SDL_Color textColor = {0,0,0,0};

      rectBackground.x=200;
      rectBackground.y=550;
      rectBackground.w=900;
      rectBackground.h=144;
      int image_width,image_height;
      SDL_QueryTexture(textureSpeechBubble, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, textureSpeechBubble, NULL, &rectBackground);

      SDL_Texture *textureTextSpeech;
      SDL_Rect rectTextSpeech;
      if(font == NULL){
        printf("Erreur font\n");
      }
      get_text_and_rect((*motor)->renderer, 250, 590, text, font, &textureTextSpeech, &rectTextSpeech,textColor);
      SDL_RenderCopy((*motor)->renderer, textureTextSpeech, NULL, &rectTextSpeech);

      SDL_DestroyTexture(textureSpeechBubble);
    }
  }

  void menu_shop(motor_t ** motor){
    SDL_Surface * surface;
    SDL_Color textColor = {0,0,0,0};
    char* font_path = "Pokemon_GB.ttf";
    int image_width,image_height;

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/boxback.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/boxback.png");
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


    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/shopfond.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/shopfond.png");
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

  void menu_save(motor_t ** motor){
    SDL_Surface * surface;
    SDL_Color textColor = {0,0,0,0};
    char* font_path = "Pokemon_GB.ttf";
    int image_width,image_height;

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/name.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/name.png");
    if (surface == NULL)
    printf("Erreur Background\n");
    SDL_Texture * textureBackgroundImage = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectBackground;

    rectBackground.x=0;
    rectBackground.y=0;
    rectBackground.w=1280;
    rectBackground.h=720;

    SDL_QueryTexture(textureBackgroundImage, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, textureBackgroundImage, NULL, &rectBackground);

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/tcard.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/shopfond.png");
    if (surface == NULL)
    printf("Erreur card\n");
    SDL_Texture * textureCard = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectCard;

    rectCard.x=130;
    rectCard.y=240;
    rectCard.w=640;
    rectCard.h=430;

    SDL_QueryTexture(textureCard, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, textureCard, NULL, &rectCard);


    TTF_Font *font = TTF_OpenFont(font_path, 20);
    SDL_Texture *textureTextSave,*textureTextNomDresseur,*textureTextYes,*textureTextNo;
    SDL_Rect rectTextSave,rectNomDresseur,rectYes,rectNo;

    if(font == NULL){
      printf("Erreur font\n");
    }
    get_text_and_rect((*motor)->renderer, 240, 80, "Sauvegarder?", font, &textureTextSave, &rectTextSave,textColor);
    SDL_RenderCopy((*motor)->renderer, textureTextSave, NULL, &rectTextSave);

    get_text_and_rect((*motor)->renderer, 200, 380, "nomDresseur", font, &textureTextNomDresseur, &rectNomDresseur,textColor);
    SDL_RenderCopy((*motor)->renderer, textureTextNomDresseur, NULL, &rectNomDresseur);

    get_text_and_rect((*motor)->renderer, 900, 300, "Oui", font, &textureTextYes, &rectYes,textColor);
    SDL_RenderCopy((*motor)->renderer, textureTextYes, NULL, &rectYes);

    get_text_and_rect((*motor)->renderer, 900, 400, "Non", font, &textureTextNo, &rectNo,textColor);
    SDL_RenderCopy((*motor)->renderer, textureTextNo, NULL, &rectNo);
    SDL_DestroyTexture(textureBackgroundImage);
    SDL_DestroyTexture(textureCard);

  }




  void menu_pokedex(motor_t ** motor){
    SDL_Surface * surface;
    SDL_Color textColor = {0,0,0,0};
    int image_width,image_height;
    char* font_path = "Pokemon_GB.ttf";
    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Pokedex/Background_1.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Pokedex/Background_1.png");
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

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Pokedex/Background_2.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Pokedex/Background_2.png");
    if (surface == NULL)
    printf("Erreur Background\n");
    SDL_Texture * textureBackgroundTwo = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectBackgroundTwo;

    rectBackgroundTwo.x=0;
    rectBackgroundTwo.y=0;
    rectBackgroundTwo.w=1280;
    rectBackgroundTwo.h=720;

    SDL_QueryTexture(textureBackgroundTwo, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, textureBackgroundTwo, NULL, &rectBackgroundTwo);
    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Pokedex/Windows_Pkdx_Detail.png");
surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Pokedex/Windows_Pkdx_Detail.png");
    if (surface == NULL)
    printf("Erreur Background\n");
    SDL_Texture * textureDetail = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rectDetail;

    rectDetail.x=150;
    rectDetail.y=0;
    rectDetail.w=960;
    rectDetail.h=720;

    SDL_QueryTexture(textureDetail, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, textureDetail, NULL, &rectDetail);



    SDL_DestroyTexture(textureBackground);
    SDL_DestroyTexture(textureBackgroundTwo);
    SDL_DestroyTexture(textureDetail);

}

  void afficher(motor_t ** motor){
    printf("%d",(*motor)->menu->el_battle_menu_select);
  }
/*
void menu_pokemon(motor_t ** motor){

}

void ajout(liste_t * l,char * nomFichier){



}
*/
