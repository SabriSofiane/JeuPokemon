/**
  * \file menu.c
  * \brief fichier d'interface graphique
  * Attention au chemin des textures dans chacune des fonctions!
  * \author Sofiane SABRI
  * \version 0.5
  * \date 8 mars 22
*/


/**
  * \function render_text
  * \brief cette fonction permet de creer du texte et de le positioner
  * \param motor : moteur de jeux
  * \param text : texte à afficher
  * \param font : la police du texte à afficher
  * \param x : position x du texte
  * \param y : position y du texte
*/
  void render_text(motor_t ** motor,char * text,TTF_Font *font,int x,int y) {
      SDL_Color color = {0,0,0,0};
      SDL_Surface * surface = TTF_RenderText_Solid(font,
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
      SDL_FreeSurface(surface);
      SDL_DestroyTexture(texture);
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

/**
  * \function menu
  * \brief menu principal du jeu
  * \param motor : moteur de jeux
*/
void menu(motor_t ** motor)
  {
    if(((*motor)->menu->menu_principal)==1){
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

        SDL_QueryTexture((*motor)->menu->menu_textures[i], NULL, NULL,  &image_width , &image_height);
        SDL_RenderCopy((*motor)->renderer, (*motor)->menu->menu_textures[i], NULL, &menu);
      }

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Menu_curseur.png");
      if (surface == NULL)
      printf("Erreur\n");

      SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);

      menu.x = 230;
      menu.y = 54* (*motor)->menu->el_menu_select+40;
      menu.w = 80;
      menu.h = 52;

      TTF_Font *font = TTF_OpenFont(font_path, 18);

      if(font == NULL){
        printf("Erreur font\n");
      }
      render_text(motor,"MENU",font,100,8);
      render_text(motor,"Pokedex",font,25,60);
      render_text(motor,"Pokemon",font,25,115);
      render_text(motor,"Inventaire",font,25,165);
      render_text(motor,"Id",font,25,220);
      render_text(motor,"Sauvegarder",font,25,275);
      render_text(motor,"Quitter",font,25,325);

      SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(textureBackgroundMenu);

    }

  }

  /**
    * \function menu_Bag
    * \brief menu du sac du joueur
    * \param motor : moteur de jeux
  */
  void menu_Bag(motor_t ** motor){
    if(((*motor)->menu->menu_bag)==1)
      {
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

        if(font == NULL){
          printf("Erreur font\n");
        }
        render_text(motor,"BAG",font,120,40);
        render_text(motor,"item0",font,300,60);
        render_text(motor,"item1",font,300,115);
        render_text(motor,"item2",font,300,165);
        render_text(motor,"item3",font,300,225);
        render_text(motor,"img",font,25,235);
        render_text(motor,"itemDesc",font,25,335);

        SDL_DestroyTexture(textureBackgroundMenu);
      }
  }


  /**
    * \function menu_Battle
    * \brief interface de combat du jeux
    * \param motor : moteur de jeux
    * \param player : structure de donnéees contenant les informations des pokémons du joueur
    * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
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

      float percentAlly = (float)(player->pkm.hp)/ (player->pkm.hpMax);
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


      float percentEnemi = (float)wild_pkm.hp/wild_pkm.hpMax;
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

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/groundbattle11.png");
      SDL_Texture * ground_ennemi_texture= SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectGroundEnnemi;
      rectGroundEnnemi.x=640;
      rectGroundEnnemi.y=220;
      rectGroundEnnemi.w=378;
      rectGroundEnnemi.h=90;
      SDL_QueryTexture(ground_ennemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, ground_ennemi_texture, NULL, &rectGroundEnnemi);


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/groundbattle11.png");
      SDL_Texture * ground_joueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectGroundJoueur;
      rectGroundJoueur.x=310;
      rectGroundJoueur.y=430;
      rectGroundJoueur.w=378;
      rectGroundJoueur.h=90;
      SDL_QueryTexture(ground_joueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, ground_joueur_texture, NULL, &rectGroundJoueur);

      char path[100];
      sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/%d.png",wild_pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/003.png");
      surface = IMG_Load(path);
      SDL_Texture * pokemonFront_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonFront;
      rectPokemonFront.x=750;
      rectPokemonFront.y=150;
      rectPokemonFront.w=160;
      rectPokemonFront.h=160;

      SDL_QueryTexture(pokemonFront_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonFront_texture, NULL, &rectPokemonFront);


      sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Back_Male/%d.png",player->pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Back_Male/2.png");
      surface = IMG_Load(path);
      SDL_Texture * pokemonBack_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonBack;
      rectPokemonBack.x=400;
      rectPokemonBack.y=300;
      rectPokemonBack.w=192;
      rectPokemonBack.h=192;

      SDL_QueryTexture(pokemonBack_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonBack_texture, NULL, &rectPokemonBack);





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
      if ((*motor)->menu->el_battle_menu_select == 2){
        menu.x = 200+580;
        menu.y = 550+18;
      }
      if ((*motor)->menu->el_battle_menu_select == 3){
        menu.x = 200+580;
        menu.y = 550+72;
      }
      menu.w = 155;
      menu.h = 55;
      SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menu);

      TTF_Font *font = TTF_OpenFont(font_path, 14);
      if(font == NULL){
        printf("Erreur font\n");
      }
      char test[20];
      render_text(motor,"Que faire?",font,335,580);
      render_text(motor,player->pkm.pkm_name,font,880,460);
      render_text(motor,wild_pkm.pkm_name,font,160,125);
      sprintf(test,"%d",player->pkm.lvl);
      render_text(motor,test,font,1080,460); //500?
      sprintf(test,"%d",wild_pkm.hp);
      render_text(motor,test,font,360,125);
      sprintf(test,"%d",player->pkm.hp);
      render_text(motor,test,font,1000,515);

      SDL_DestroyTexture(textureBackground);
      SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(textureBattleMenu);
      SDL_DestroyTexture(cadreEnnemi_texture);
      SDL_DestroyTexture(pokemonFront_texture);
      SDL_DestroyTexture(pokemonBack_texture);
      SDL_DestroyTexture(ground_ennemi_texture);
      SDL_DestroyTexture(ground_joueur_texture);
      SDL_DestroyTexture(cadreJoueur_texture);
      SDL_DestroyTexture(hpbarJoueur_texture);
      SDL_DestroyTexture(hpbarEnnemi_texture);
    }
  }


  /**
    * \function menu_Battle_Attaque
    * \brief interface de combat du jeux affichant les attaques disponibles pour le joueur

    * \param motor : moteur de jeux
    * \param player : structure de donnéees contenant les informations des pokémons du joueur
    * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  void menu_Battle_Attaque(motor_t ** motor){
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

      float percentAlly = (float)(player->pkm.hp)/ (player->pkm.hpMax);
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

      float percentEnemi = (float)wild_pkm.hp/wild_pkm.hpMax;
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

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/groundbattle11.png");
      SDL_Texture * ground_ennemi_texture= SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectGroundEnnemi;
      rectGroundEnnemi.x=640;
      rectGroundEnnemi.y=220;
      rectGroundEnnemi.w=378;
      rectGroundEnnemi.h=90;
      SDL_QueryTexture(ground_ennemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, ground_ennemi_texture, NULL, &rectGroundEnnemi);


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlebacks/groundbattle11.png");
      SDL_Texture * ground_joueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectGroundJoueur;
      rectGroundJoueur.x=310;
      rectGroundJoueur.y=430;
      rectGroundJoueur.w=378;
      rectGroundJoueur.h=90;
      SDL_QueryTexture(ground_joueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, ground_joueur_texture, NULL, &rectGroundJoueur);

      char path[100];
      sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/%d.png",wild_pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/003.png");
      surface = IMG_Load(path);
      SDL_Texture * pokemonFront_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonFront;
      rectPokemonFront.x=750;
      rectPokemonFront.y=150;
      rectPokemonFront.w=160;
      rectPokemonFront.h=160;

      SDL_QueryTexture(pokemonFront_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonFront_texture, NULL, &rectPokemonFront);


      sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Back_Male/%d.png",player->pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Back_Male/2.png");
      surface = IMG_Load(path);
      SDL_Texture * pokemonBack_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonBack;
      rectPokemonBack.x=400;
      rectPokemonBack.y=300;
      rectPokemonBack.w=192;
      rectPokemonBack.h=192;

      SDL_QueryTexture(pokemonBack_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonBack_texture, NULL, &rectPokemonBack);

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

      if(font == NULL){
        printf("Erreur font\n");
      }
      char test[20];

      render_text(motor,player->pkm.skill[0],font,350,590);
      render_text(motor,player->pkm.skill[1],font,350,645);
      render_text(motor,player->pkm.skill[2],font,570,590);
      render_text(motor,player->pkm.skill[3],font,570,645);
      render_text(motor,"PP/PPMax",font,815,580);
      render_text(motor,player->pkm.type1,font,825,650);
      render_text(motor,player->pkm.pkm_name,font,880,460);
      sprintf(test,"%d",player->pkm.lvl);
      render_text(motor,test,font,1080,460);
      sprintf(test,"%d",player->pkm.hp);
      render_text(motor,test,font,1000,515);

      render_text(motor,wild_pkm.pkm_name,font,160,125);
      sprintf(test,"%d",wild_pkm.hp);
      render_text(motor,test,font,360,125);

      SDL_DestroyTexture(textureBackground);
      SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(textureBattleAttackMenu);
      SDL_DestroyTexture(ground_ennemi_texture);
      SDL_DestroyTexture(ground_joueur_texture);
      SDL_DestroyTexture(pokemonBack_texture);
      SDL_DestroyTexture(pokemonFront_texture);
      SDL_DestroyTexture(cadreEnnemi_texture);
      SDL_DestroyTexture(cadreJoueur_texture);
      SDL_DestroyTexture(hpbarJoueur_texture);
      SDL_DestroyTexture(hpbarEnnemi_texture);
    }
}


    /**
      * \function speech_bubble
      * \brief fonction qui affiche une bulle de texte contenant du texte mis en paramètre
      * \param motor : moteur de jeux
      * \param text: texte à afficher dans la bulle
    */
  void speech_bubble(motor_t ** motor,char * text)
  {
    if ((*motor)->menu->speech_bubble == 1)
    {
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
      if(font == NULL){
        printf("Erreur font\n");
      }
      render_text(motor,text,font,250,590);
      SDL_DestroyTexture(textureSpeechBubble);
    }
  }


  /**
    * \function menu_shop
    * \brief interface pour le marché
    * \param motor : moteur de jeux
  */
  void menu_shop(motor_t ** motor){
    if ((*motor)->menu->menu_shop == 1)
    {
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

      if(font == NULL){
        printf("Erreur font\n");
      }
      render_text(motor,"Boutique",font,60,40);
      render_text(motor,"item0",font,300,60);
      render_text(motor,"item1",font,300,115);
      render_text(motor,"item2",font,300,165);
      render_text(motor,"item3",font,300,225);
      render_text(motor,"img",font,25,235);
      render_text(motor,"itemDesc",font,25,325);

      SDL_DestroyTexture(textureBackgroundImage);
      SDL_DestroyTexture(textureShop);
    }
  }

  /**
    * \function menu_save
    * \brief interface pour la sauvegarde de jeu
    * \param motor : moteur de jeux
  */
  void menu_save(motor_t ** motor){
      if ((*motor)->menu->menu_save == 1)
      {
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
        surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/tcard.png");
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

        //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Select_Category.png");
        surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Select_Category.png");
        if (surface == NULL)
        printf("Erreur\n");
        SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
        SDL_FreeSurface(surface);
        SDL_Rect menuSelectSave;
        menuSelectSave.x = 760;
        menuSelectSave.y = 108* (*motor)->menu->el_menu_save_select+260;
        menuSelectSave.w = 400;
        menuSelectSave.h = 110;
        SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
        SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menuSelectSave);

        TTF_Font *font = TTF_OpenFont(font_path, 20);
        if(font == NULL){
          printf("Erreur font\n");
        }
        render_text(motor,"Sauvegarder?",font,240,80);
        render_text(motor,"nomDresseur",font,200,380);
        render_text(motor,"Oui",font,900,300);
        render_text(motor,"Non",font,900,400);
        SDL_DestroyTexture(textureBackgroundImage);
        SDL_DestroyTexture(textureCard);
        SDL_DestroyTexture(menu_texture);
      }
    }



  /**
    * \function menu_pokedex
    * \brief interface pour le pokedex qui est une sorte de base de données des pokémons
    * \param motor : moteur de jeux
  */
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



  /**
    * \function menu_pokemon
    * \brief interface pour la selection de pokemons pour le combat.
    * \param motor : moteur de jeux
  */
  void menu_pokemon(motor_t ** motor){
    if(((*motor)->menu->menu_pokemon)==1)
    {
      SDL_Surface * surface;
      char* font_path = "Pokemon_GB.ttf";
      Liste_t * truc = player;

      TTF_Font *font = TTF_OpenFont(font_path, 14);
      int image_width,image_height;

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Partyfond2.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Partyfond2.png");
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

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Select_Category.png");
      surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Select_Category.png");

      if (surface == NULL)
      printf("Erreur\n");

      SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect menuSelectPokemon;

      menuSelectPokemon.x = 550;
      menuSelectPokemon.y = 108* (*motor)->menu->el_menu_pokemon_select+40;
      menuSelectPokemon.w = 740;
      menuSelectPokemon.h = 110;
      SDL_QueryTexture(menu_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, menu_texture, NULL, &menuSelectPokemon);

      render_text(motor,"imgPokemon",font,100,170);

      //Affichage du pokemon dans le menu pokemon
      /*
      char path[100];
      sprintf(path,"/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/%d.png",(*motor)->menu->current_pokemon);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/003.png");
      surface = IMG_Load(path);
      SDL_Texture * pokemonFront_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonFront;
      rectPokemonFront.x=750;
      rectPokemonFront.y=150;
      rectPokemonFront.w=160;
      rectPokemonFront.h=160;
      SDL_QueryTexture(pokemonFront_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonFront_texture, NULL, &rectPokemonFront);*/

      int i = 0;
      char intToText[50];
      char hp[10]="HP";
      char mp[10]="MP";

      while (truc != NULL) {
        render_text(motor,truc->pkm.pkm_name,font,600,105*i+70);
        render_text(motor,"LVL",font,600,105*i+120);
        sprintf(intToText,"%d",truc->pkm.lvl);
        render_text(motor,intToText,font,650,105*i+120);
        sprintf(intToText,"%d",truc->pkm.hp);
        strcat(intToText,hp);
        render_text(motor,intToText,font,700,105*i+120);
        sprintf(intToText,"%d",truc->pkm.mp);
        strcat(intToText,mp);
        render_text(motor,intToText,font,780,105*i+120);
        truc = truc->next;
        i++;
      }
      SDL_DestroyTexture(textureBackground);
      //  SDL_DestroyTexture(pokemonFront_texture);
      SDL_DestroyTexture(menu_texture);
    }
}
