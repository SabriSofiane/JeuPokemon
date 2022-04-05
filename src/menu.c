#include "../include/motor.h"
#include "../include/menu.h"
#include "../include/text.h"
#include "../include/textures.h"
#include "../include/combat.h"
#include "../include/string_matrice.h"

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
  (*motor)->menu->speech_bubble = 0;
  (*motor)->menu->menu_page_acceuil=0;
  (*motor)->menu->menu_battle=0;
  (*motor)->menu->menu_battle_attaque=0;
  (*motor)->menu->menu_pokemon=0;
  (*motor)->menu->menu_pokedex=0;
  (*motor)->menu->combat=0;
  (*motor)->menu->menu_bag=0;
  (*motor)->menu->menu_shop=0;
  (*motor)->menu->menu_save=0;
  (*motor)->menu->menu_principal=0;
  (*motor)->menu->current_pokemon = 1;
  (*motor)->menu->save_available = 0;

  (*motor)->menu->textures_menu.menu_textures = malloc(sizeof(SDL_Texture*)*10);
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Menu_Back,"./src/asset/images/Pictures/Menu_Back.png");
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Menu_icon,"./src/asset/images/Pictures/MenuIcons.png");
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_bagfond,"./src/asset/images/Pictures/bagfond.png");
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Menu_curseur,"./src/asset/images/Pictures/Menu_curseur.png");
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_battle11, "./src/asset/images/Pictures/Battlebacks/battle11.png" );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_ChoixMultiple,"./src/asset/images/Pictures/Battle/ChoixMultiple.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_battle_sprite4,"./src/asset/images/Pictures/Battle/battle_sprite4.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_battle_sprite3,"./src/asset/images/Pictures/Battle/battle_sprite3.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_hpbar,"./src/asset/images/Pictures/Battle/hpbar.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_groundbattle11,"./src/asset/images/Pictures/Battlebacks/groundbattle11.png"  );
  //load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Front_Male,"./src/asset/images/Pictures/Battlers/Front_Male/%d.png"  );
  //load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Back_Male,  );

  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_ChoixAttaque,"./src/asset/images/Pictures/Battle/ChoixAttaque.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_boxback,"./src/asset/images/Pictures/boxback.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_shopfond,"./src/asset/images/Pictures/shopfond.png"  );
  //load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_name,"./src/asset/images/Pictures/name.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Background_1,"./src/asset/images/Pictures/Pokedex/Background_1.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Background_2,"./src/asset/images/Pictures/Pokedex/Background_2.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Windows_Pkdx_Detail,"./src/asset/images/Pictures/Pokedex/Windows_Pkdx_Detail.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Partyfond2,"./src/asset/images/Pictures/Partyfond2.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_Select_Category,"./src/asset/images/Pictures/Select_Category.png"  );
  load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_titlepage,"./src/asset/images/Pictures/titlepage.png"  );

  return(0);
}

/**
* \file menu.h
* \brief fichier d'interface graphique
* Attention au chemin des textures dans chacune des fonctions!
* \author Sofiane SABRI
* \version 0.5
* \date 8 mars 22
  */
//Fonctionne
void menu(motor_t ** motor)
{
  if(((*motor)->menu->menu_principal)==1){

    if ((*motor)->keys.z_key + (*motor)->keys.q_key + (*motor)->keys.s_key + (*motor)->keys.d_key > 0 )
    {
      (*motor)->menu->menu_principal = 0;
      return;
    }

    //printf("menu\n");
    int posX = 900;
    int posY = 0;

    SDL_Rect rectBackground;

    SDL_Color textColor = {255, 255, 255, 0};
    SDL_Rect menu;
    rectBackground.x=posX;
    rectBackground.y=posY;
    rectBackground.w=720;
    rectBackground.h=480;
    int image_width,image_height;
    SDL_QueryTexture((*motor)->menu->textures_menu.texture_Menu_Back, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_Menu_Back, NULL, &rectBackground);

    rectBackground.x=275+posX;
    rectBackground.y=52;
    rectBackground.w=80;
    rectBackground.h=260;

    SDL_QueryTexture((*motor)->menu->textures_menu.texture_Menu_icon, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_Menu_icon, NULL, &rectBackground);

    menu.x = 275+posX;
    menu.y = 52 * (*motor)->menu->el_menu_select +52;
    menu.y += posY;
    menu.w = 80;
    menu.h = 52;
    SDL_QueryTexture((*motor)->menu->textures_menu.texture_Menu_curseur, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_Menu_curseur, NULL, &menu);




    text_draw(motor,"MENU",100+posX,8+posY);
    text_draw(motor,"Pokedex",25+posX,60+posY);
    text_draw(motor,"Pokemon",25+posX,115+posY);
    text_draw(motor,"Inventaire",25+posX,165+posY);
    text_draw(motor,"Sauvegarder",25+posX,220+posY);
    text_draw(motor,"Quitter",25+posX,275+posY);

    //SDL_DestroyTexture(menu_texture);
    //SDL_DestroyTexture(textureBackgroundMenu);

  }
}

/*FONCTION BY ELIAS*/
/*
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
*/

/**
* \function text_draw
* \brief cette fonction permet de creer du texte et de le positioner
* \param motor : moteur de jeux
* \param text : texte à afficher
* \param font : la police du texte à afficher
* \param x : position x du texte
* \param y : position y du texte
  */

void render_text(motor_t ** motor,char * text,TTF_Font *font,int x,int y)
{
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
SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
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
void RenderHPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor,SDL_Renderer *renderer)
{

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


/**
  * \function menu_Bag
  * \brief menu du sac du joueur
  * \param motor : moteur de jeux
  */
  //Fonctionne
void menu_Bag(motor_t ** motor)
{
    if(((*motor)->menu->menu_bag)==1)
    {
      /*
      SDL_Surface * surface;
      char* font_path = "./fonts/PKMN_RBYGSC.ttf";
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/bagfond.png");
      surface = IMG_Load("src/asset/images/Pictures/bagfond.png");
      if (surface == NULL)
      printf("Erreur Background\n");
      SDL_Texture * textureBackgroundMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      int image_width,image_height;
      SDL_Rect rectBackground;

      rectBackground.x=0;
      rectBackground.y=0;
      rectBackground.w=640;
      rectBackground.h=480;

      SDL_QueryTexture((*motor)->menu->textures_menu.texture_bagfond, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_bagfond, NULL, &rectBackground);

      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
      surface = IMG_Load("src/asset/images/Pictures/Menu_curseur.png");
      if (surface == NULL)
      printf("Erreur Background\n");
      SDL_Texture * selecteur_bag_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      SDL_Rect rectSelecteurBag;

      rectSelecteurBag.x=280;
      rectSelecteurBag.y=40;
      rectSelecteurBag.w=360;
      rectSelecteurBag.h=55;

      SDL_QueryTexture((*motor)->menu->textures_menu.texture_Menu_curseur, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_Menu_curseur, NULL, &rectSelecteurBag);

      text_draw(motor,"BAG",120,40);
      text_draw(motor,"item0",300,60);
      text_draw(motor,"item1",300,115);
      text_draw(motor,"item2",300,165);
      text_draw(motor,"item3",300,225);
      text_draw(motor,"img",25,235);
      text_draw(motor,"itemDesc",25,335);

    }
  }


/**
  * \function menu_Battle
  * \brief interface de combat du jeux
  * \param motor : moteur de jeux
  * \param player : structure de donnéees contenant les informations des pokémons du joueur
  * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  //Fonctionne
void menu_Battle(motor_t ** motor)
{
    if(((*motor)->menu->menu_battle)==1)
    {
      set_text_font_size(motor,15);
      //printf("menu_Battle\n");
      /*
      //SDL_SetRenderDrawColor((*motor)->renderer,255,0,0,255);
      SDL_Surface * surface;
      char* font_path = "./fonts/PKMN_RBYGSC.ttf";
      SDL_Color textColor = {0,0,0,0};


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battlebacks/battle11.png");
      surface = IMG_Load("src/asset/images/Pictures/Battlebacks/battle11.png");
      if (surface == NULL)
      printf("Erreur Background\n");

      SDL_Texture * textureBackground = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      int image_width,image_height;
      SDL_Rect rectBackground;
      rectBackground.x=0;
      rectBackground.y=0;
      rectBackground.w=1280;
      rectBackground.h=720;
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_battle11, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_battle11, NULL, &rectBackground);

      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/ChoixMultiple.png");
      surface = IMG_Load("src/asset/images/Pictures/Battle/ChoixMultiple.png");
      if (surface == NULL)
      printf("Erreur Battlemenu\n");

      SDL_Texture * textureBattleMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      SDL_Rect rectBattleMenu;
      rectBattleMenu.x=300;
      rectBattleMenu.y=550;
      rectBattleMenu.w=640;
      rectBattleMenu.h=144;

      SDL_QueryTexture((*motor)->menu->textures_menu.texture_ChoixMultiple, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_ChoixMultiple, NULL, &rectBattleMenu);
      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite4.png");
      surface = IMG_Load("src/asset/images/Pictures/Battle/battle_sprite4.png");
      if (surface == NULL)
      printf("Erreur battle_sprite4\n");

      SDL_Texture * cadreEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      SDL_Rect rectCadreEnnemi;
      rectCadreEnnemi.x=150;
      rectCadreEnnemi.y=100;
      rectCadreEnnemi.w=302;
      rectCadreEnnemi.h=108;
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_battle_sprite4, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_battle_sprite4, NULL, &rectCadreEnnemi);

      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/battle_sprite3.png");
      surface = IMG_Load("src/asset/images/Pictures/Battle/battle_sprite3.png");
      if (surface == NULL)
      printf("Erreur battle_sprite3\n");

      //OK ICI
      SDL_Texture * cadreJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      SDL_Rect rectCadreJoueur;
      rectCadreJoueur.x=840;
      rectCadreJoueur.y=440;
      rectCadreJoueur.w=302;
      rectCadreJoueur.h=108;
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_battle_sprite3, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_battle_sprite3, NULL, &rectCadreJoueur);

      float percentAlly = (float)((*motor)->liste_player->pkm.hp)/ ((*motor)->liste_player->pkm.hpMax);

      RenderHPBar(1130,490,-150,20,percentAlly,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);

      SDL_Rect xpLinePlayer;
      xpLinePlayer.x=886;
      xpLinePlayer.y=537;
      xpLinePlayer.w=235;
      xpLinePlayer.h=5;
      SDL_SetRenderDrawColor((*motor)->renderer,0,0,255,255);
      SDL_RenderFillRect((*motor)->renderer,&xpLinePlayer);
      SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);
      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("src/asset/images/Pictures/Battle/hpbar.png");
      if (surface == NULL)
      printf("Erreur hpbar\n");

      SDL_Texture * hpbarJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      */
      SDL_Rect rectHpbarJoueur;
      rectHpbarJoueur.x=940;
      rectHpbarJoueur.y=490;
      rectHpbarJoueur.w=195;
      rectHpbarJoueur.h=21;
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_hpbar, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_hpbar, NULL, &rectHpbarJoueur);

      //Combat 1 seul pkm
      float percentEnemi = (float)(*motor)->wild_pkm.hp/(*motor)->wild_pkm.hpMax;
      RenderHPBar(345,160,-150,20,percentEnemi,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);
      //Combat dresseur
      /*
      float percentEnemi = (float)testEnnemi->pkm.hp/testEnnemi->pkm.hpMax;
      RenderHPBar(345,160,-150,20,percentEnemi,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);*/

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      /*
      SDL_Texture * hpbarEnnemi_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      */
      SDL_Rect rectHpbarEnnemi;
      rectHpbarEnnemi.x=155;
      rectHpbarEnnemi.y=160;
      rectHpbarEnnemi.w=195;
      rectHpbarEnnemi.h=21;

      SDL_QueryTexture((*motor)->menu->textures_menu.texture_hpbar, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_hpbar, NULL, &rectHpbarEnnemi);

      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("src/asset/images/Pictures/Battlebacks/groundbattle11.png");
      if (surface == NULL)
      printf("Erreur groundbattle11\n");

      SDL_Texture * ground_ennemi_texture= SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      */
      SDL_Rect rectGroundEnnemi;
      rectGroundEnnemi.x=640;
      rectGroundEnnemi.y=230;
      rectGroundEnnemi.w=378;
      rectGroundEnnemi.h=90;
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_groundbattle11, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_groundbattle11, NULL, &rectGroundEnnemi);

      SDL_Rect rectGroundJoueur;
      rectGroundJoueur.x=310;
      rectGroundJoueur.y=430;
      rectGroundJoueur.w=378;
      rectGroundJoueur.h=90;
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_groundbattle11, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_groundbattle11, NULL, &rectGroundJoueur);

      char path[100];
      sprintf(path,"src/asset/images/Pictures/Battlers/Front_Male/%d.png",(*motor)->wild_pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("src/asset/images/Pictures/Battlers/Front_Male/003.png");
      SDL_Surface * surface = IMG_Load(path);
      if (surface == NULL)
      printf("Erreur Front_Male\n");

      SDL_Texture * pokemonFront_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonFront;
      rectPokemonFront.x=750;
      rectPokemonFront.y=150;
      rectPokemonFront.w=160;
      rectPokemonFront.h=160;

      SDL_QueryTexture(pokemonFront_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonFront_texture, NULL, &rectPokemonFront);


      sprintf(path,"src/asset/images/Pictures/Battlers/Back_Male/%d.png",(*motor)->liste_player->pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("src/asset/images/Pictures/Battlers/Back_Male/2.png");
      surface = IMG_Load(path);
      if (surface == NULL)
      printf("Erreur Back_Male\n");

      SDL_Texture * pokemonBack_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonBack;
      rectPokemonBack.x=400;
      rectPokemonBack.y=300;
      rectPokemonBack.w=192;
      rectPokemonBack.h=192;

      SDL_QueryTexture(pokemonBack_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonBack_texture, NULL, &rectPokemonBack);
      /*
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Menu_curseur.png");
      surface = IMG_Load("src/asset/images/Pictures/Menu_curseur.png");
      if (surface == NULL)
      printf("Erreur Menu_curseur\n");

      SDL_Texture * menu_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
*/
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
      SDL_QueryTexture((*motor)->menu->textures_menu.texture_Menu_curseur, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_Menu_curseur, NULL, &menu);


      char test[20];
      text_draw(motor,"Que faire?",335,580);
      text_draw(motor,(*motor)->liste_player->pkm.pkm_name,880,460);
      text_draw(motor,(*motor)->wild_pkm.pkm_name,160,125);
      sprintf(test,"%d",(*motor)->liste_player->pkm.lvl);
      text_draw(motor,test,1080,460);
      sprintf(test,"%d",(*motor)->wild_pkm.hp);
      text_draw(motor,test,360,125);
      sprintf(test,"%d",(*motor)->liste_player->pkm.hp);
      text_draw(motor,test,1000,515);


      //SDL_DestroyTexture(textureBackground);

    //  SDL_DestroyTexture(textureBattleMenu);
    //  SDL_DestroyTexture(cadreJoueur_texture);
      //SDL_DestroyTexture(cadreEnnemi_texture);
    //  SDL_DestroyTexture(hpbarJoueur_texture);
      //SDL_DestroyTexture(hpbarEnnemi_texture);

      //SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(pokemonFront_texture);
      SDL_DestroyTexture(pokemonBack_texture);
    //  SDL_DestroyTexture(ground_ennemi_texture);
    //  SDL_DestroyTexture(ground_joueur_texture);

    }
  }


/**
  * \function menu_Battle_Attaque
  * \brief interface de combat du jeux affichant les attaques disponibles pour le joueur

  * \param motor : moteur de jeux
  * \param player : structure de donnéees contenant les informations des pokémons du joueur
  * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  //Fonctionne
void menu_Battle_Attaque(motor_t ** motor)
{
    if (((*motor)->menu->menu_battle_attaque)==1)
    {
      set_text_font_size(motor,15);
      //printf("menu_Battle_Attaque\n");
      int debug = 0;


      SDL_Surface * surface;

      SDL_Color textColor = {0,0,0,0};
      int image_width,image_height;

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battlebacks/battle11.png");
      surface = IMG_Load("src/asset/images/Pictures/Battlebacks/battle11.png");
      if (surface == NULL)
      printf("Erreur Background dans menu_Battle_Attaque \n");

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
      surface = IMG_Load("src/asset/images/Pictures/Battle/battle_sprite4.png");
      if (surface == NULL)
      printf("Erreur surface battle_sprite4 dans menu_Battle_Attaque \n");

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
      surface = IMG_Load("src/asset/images/Pictures/Battle/battle_sprite3.png");
      if (surface == NULL)
      printf("Erreur surface battle_sprite3 dans menu_Battle_Attaque \n");

      //printf("649\n");
      SDL_Texture * cadreJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectCadreJoueur;
      rectCadreJoueur.x=840;
      rectCadreJoueur.y=440;
      rectCadreJoueur.w=302;
      rectCadreJoueur.h=108;
      SDL_QueryTexture(cadreJoueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, cadreJoueur_texture, NULL, &rectCadreJoueur);

      //printf("659\n");
      float percentAlly = (float)((*motor)->liste_player->pkm.hp)/ ((*motor)->liste_player->pkm.hpMax);

      //ERREUR ICI
      RenderHPBar(1130,490,-150,20,percentAlly,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);



      if (debug)
      printf("663\n");
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("src/asset/images/Pictures/Battle/hpbar.png");

      if (surface == NULL)
      printf("Erreur surface hpbar dans menu_Battle_Attaque \n");

      if (debug)
      printf("667\n" );
      SDL_Texture * hpbarJoueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectHpbarJoueur;
      rectHpbarJoueur.x=940;
      rectHpbarJoueur.y=490;
      rectHpbarJoueur.w=195;
      rectHpbarJoueur.h=21;
      SDL_QueryTexture(hpbarJoueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, hpbarJoueur_texture, NULL, &rectHpbarJoueur);

      if (debug)
      printf("677\n");

      SDL_Rect xpLinePlayer;
      xpLinePlayer.x=886;
      xpLinePlayer.y=537;
      xpLinePlayer.w=235  ;
      xpLinePlayer.h=5;
      SDL_SetRenderDrawColor((*motor)->renderer,0,0,255,255);
      SDL_RenderFillRect((*motor)->renderer,&xpLinePlayer);

      //Combat 1 seul pkm
      float percentEnemi = (float)(*motor)->wild_pkm.hp/(*motor)->wild_pkm.hpMax;
      RenderHPBar(345,160,-150,20,percentEnemi,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);
      //Combat dresseur
      /*
      float percentEnemi = (float)testEnnemi->pkm.hp/testEnnemi->pkm.hpMax;
      RenderHPBar(345,160,-150,20,percentEnemi,color(0,255,0,255),color(0,0,0,255),(*motor)->renderer);*/

      SDL_SetRenderDrawColor((*motor)->renderer,0,0,0,255);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("src/asset/images/Pictures/Battle/hpbar.png");
      if (surface == NULL)
      printf("Erreur surface hpbar2 dans menu_Battle_Attaque \n");

      if (debug)
      printf("695\n");

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
      surface = IMG_Load("src/asset/images/Pictures/Battle/ChoixAttaque.png");
      if (surface == NULL)
      printf("Erreur surface ChoixAttaque dans menu_Battle_Attaque \n");


      SDL_Texture * textureBattleAttackMenu = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);

      SDL_Rect rectBattleAttackMenu;

      if (debug)
      printf("718\n");

      rectBattleAttackMenu.x=300;
      rectBattleAttackMenu.y=550;
      rectBattleAttackMenu.w=640;
      rectBattleAttackMenu.h=144;

      SDL_QueryTexture(textureBattleAttackMenu, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, textureBattleAttackMenu, NULL, &rectBattleAttackMenu);

      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("src/asset/images/Pictures/Battlebacks/groundbattle11.png");
      if (surface == NULL)
      printf("Erreur surface groundbattle11 dans menu_Battle_Attaque \n");

      if (debug)
      printf("731\n");

      SDL_Texture * ground_ennemi_texture= SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectGroundEnnemi;
      rectGroundEnnemi.x=640;
      rectGroundEnnemi.y=230;
      rectGroundEnnemi.w=378;
      rectGroundEnnemi.h=90;
      SDL_QueryTexture(ground_ennemi_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, ground_ennemi_texture, NULL, &rectGroundEnnemi);


      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      surface = IMG_Load("src/asset/images/Pictures/Battlebacks/groundbattle11.png");
      if (surface == NULL)
      printf("Erreur surface groundbattle11_2 dans menu_Battle_Attaque \n");

      SDL_Texture * ground_joueur_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectGroundJoueur;
      rectGroundJoueur.x=310;
      rectGroundJoueur.y=430;
      rectGroundJoueur.w=378;
      rectGroundJoueur.h=90;
      SDL_QueryTexture(ground_joueur_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, ground_joueur_texture, NULL, &rectGroundJoueur);

      if (debug)
      printf("757\n");

      char path[100];
      sprintf(path,"src/asset/images/Pictures/Battlers/Front_Male/%d.png",(*motor)->wild_pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("src/asset/images/Pictures/Battlers/Front_Male/003.png");
      surface = IMG_Load(path);
      if (surface == NULL)
      printf("Erreur surface Front_Male dans menu_Battle_Attaque \n");


      SDL_Texture * pokemonFront_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
      SDL_FreeSurface(surface);
      SDL_Rect rectPokemonFront;
      rectPokemonFront.x=750;
      rectPokemonFront.y=150;
      rectPokemonFront.w=160;
      rectPokemonFront.h=160;

      SDL_QueryTexture(pokemonFront_texture, NULL, NULL,  &image_width , &image_height);
      SDL_RenderCopy((*motor)->renderer, pokemonFront_texture, NULL, &rectPokemonFront);


      sprintf(path,"src/asset/images/Pictures/Battlers/Back_Male/%d.png",(*motor)->liste_player->pkm.pkmId);
      //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
      //surface = IMG_Load("src/asset/images/Pictures/Battlers/Back_Male/2.png");
      surface = IMG_Load(path);
      if (surface == NULL)
      printf("Erreur surface Back_Male dans menu_Battle_Attaque \n");

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
      surface = IMG_Load("src/asset/images/Pictures/Menu_curseur.png");

      if (surface == NULL)
      printf("Erreur surface Menu_curseur dans menu_Battle_Attaque \n");

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



      char test[20];

      text_draw(motor,(*motor)->liste_player->pkm.skill[0],350,590);
      text_draw(motor,(*motor)->liste_player->pkm.skill[1],350,645);
      text_draw(motor,(*motor)->liste_player->pkm.skill[2],570,590);
      text_draw(motor,(*motor)->liste_player->pkm.skill[3],570,645);
      text_draw(motor,"PP/PPMax",815,580);
      text_draw(motor,(*motor)->liste_player->pkm.type1,825,650);
      text_draw(motor,(*motor)->liste_player->pkm.pkm_name,880,460);
      sprintf(test,"%d",(*motor)->liste_player->pkm.lvl);
      text_draw(motor,test,1080,460);
      sprintf(test,"%d",(*motor)->liste_player->pkm.hp);
      text_draw(motor,test,1000,515);

      text_draw(motor,(*motor)->wild_pkm.pkm_name,165,125);
      sprintf(test,"%d",(*motor)->wild_pkm.hp);
      text_draw(motor,test,360,125);

      SDL_DestroyTexture(textureBackground);
      SDL_DestroyTexture(menu_texture);
      SDL_DestroyTexture(textureBattleAttackMenu);
      SDL_DestroyTexture(ground_ennemi_texture);
      SDL_DestroyTexture(ground_joueur_texture);
      SDL_DestroyTexture(pokemonBack_texture);
      SDL_DestroyTexture(pokemonFront_texture);
      //SDL_DestroyTexture(cadreEnnemi_texture);
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
/*
  void speech_bubble(motor_t ** motor,char * text)
  {
  if ((*motor)->menu->speech_bubble == 1)
  {
  SDL_Surface * surface;
  //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/messagedummy.png");
  surface = IMG_Load("src/asset/images/Pictures/messagedummy.png");
  if (surface == NULL)
  printf("Erreur Background\n");
  SDL_Texture * textureSpeechBubble = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
  SDL_FreeSurface(surface);
  SDL_Rect rectBackground;
  char* font_path = "./fonts/PKMN_RBYGSC.ttf";
  TTF_Font *font = TTF_OpenFont(font_path, 35);
  SDL_Color textColor = {0,0,0,0  };

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
text_draw(motor,text,font,250,590);
SDL_DestroyTexture(textureSpeechBubble);
}
}
*/
//Fonctione
void speech_bubble(motor_t ** motor)
{

  if ((*motor)->menu->speech_bubble == 1)
  {
    set_text_font_size(motor,25);
    if ((*motor)->keys.z_key + (*motor)->keys.q_key + (*motor)->keys.s_key + (*motor)->keys.d_key > 0 )
    {
      (*motor)->menu->speech_bubble = 0;
      return;
    }

    load_texture(&(*motor)->renderer,&(*motor)->menu->textures_menu.texture_speech_bubble,"src/asset/dialogues/GUI/messagedummy.png");
    if ((*motor)->menu->textures_menu.texture_speech_bubble== NULL)
    {
      printf("Erreur au chargement de la texture du speech_bubble : %s\n",SDL_GetError());
    }

    SDL_Rect rectBackground;
    rectBackground.x=200;
    rectBackground.y=550;
    rectBackground.w=900;
    rectBackground.h=244/2;
    int image_width,image_height;
    SDL_QueryTexture((*motor)->menu->textures_menu.texture_speech_bubble, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, (*motor)->menu->textures_menu.texture_speech_bubble, NULL, &rectBackground);
    char string[300];
    strncpy(string,(*motor)->menu->speech_bubble_text,strlen((*motor)->menu->speech_bubble_text));
    //printf("%s\n",string );
    text_draw(motor,string,250,580);
  }
}

/**
* \function menu_shop
* \brief interface pour le marché
* \param motor : moteur de jeux
*/
//Fonctione
void menu_shop(motor_t ** motor){
  if ((*motor)->menu->menu_shop == 1)
  {
    SDL_Surface * surface;
    SDL_Color textColor = {0,0,0,0};

    int image_width,image_height;

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/boxback.png");
    surface = IMG_Load("src/asset/images/Pictures/boxback.png");
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
    surface = IMG_Load("src/asset/images/Pictures/shopfond.png");
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



    text_draw(motor,"Boutique",60,40);
    text_draw(motor,"item0",300,60);
    text_draw(motor,"item1",300,115);
    text_draw(motor,"item2",300,165);
    text_draw(motor,"item3",300,225);
    text_draw(motor,"img",25,235);
    text_draw(motor,"itemDesc",25,325);

    SDL_DestroyTexture(textureBackgroundImage);
    SDL_DestroyTexture(textureShop);
  }
}

/**
* \function menu_save
* \brief interface pour la sauvegarde de jeu
* \param motor : moteur de jeux
*/
//Fonctione
void menu_save(motor_t ** motor)
{
  if ((*motor)->menu->menu_save == 1)
  {
    SDL_Surface * surface;
    SDL_Color textColor = {0,0,0,0};

    int image_width,image_height;

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/name.png");
    surface = IMG_Load("src/asset/images/Pictures/name.png");
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
    surface = IMG_Load("src/asset/images/Pictures/tcard.png");
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
    surface = IMG_Load("src/asset/images/Pictures/Select_Category.png");
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


    text_draw(motor,"Sauvegarder?",240,80);
    text_draw(motor,"nomDresseur",200,380);
    text_draw(motor,"Oui",900,300);
    text_draw(motor,"Non",900,400);
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
//Fonctione
void menu_pokedex(motor_t ** motor){
  if ((*motor)->menu->menu_pokedex == 1){
  SDL_Surface * surface;
  SDL_Color textColor = {0,0,0,0};
  int image_width,image_height;

  //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Pokedex/Background_1.png");
  surface = IMG_Load("src/asset/images/Pictures/Pokedex/Background_1.png");
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
  surface = IMG_Load("src/asset/images/Pictures/Pokedex/Background_2.png");
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
  surface = IMG_Load("src/asset/images/Pictures/Pokedex/Windows_Pkdx_Detail.png");
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
}



/**
* \function menu_pokemon
* \brief interface pour la selection de pokemons pour le combat.
* \param motor : moteur de jeux
*/
//Ne fonctionne pas
void menu_pokemon(motor_t ** motor){
  if (((*motor)->menu->menu_pokemon)==1)
  {
    set_text_font_size(motor,15);
    SDL_Surface * surface;

    Liste_t * buffer = (*motor)->liste_player;


    int image_width,image_height;

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Partyfond2.png");
    surface = IMG_Load("src/asset/images/Pictures/Partyfond2.png");
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
    surface = IMG_Load("src/asset/images/Pictures/Select_Category.png");

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

char path[255];
//-----------------NOUVEAU---------------------
//Affichage de l'image du pokemon dans le menu pokemon
sprintf(path,"src/asset/images/Pictures/Battlers/Front_Male/%d.png",getPlayerPkmId((*motor)->liste_player,(*motor)->menu->el_menu_pokemon_select+1) );
//surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/Battle/hpbar.png");
//surface = IMG_Load("/info/etu/l2info/s2103600/SDL2/images/Pictures/Battlers/Front_Male/003.png");
surface = IMG_Load(path);
SDL_Texture * pokemonFront_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
SDL_FreeSurface(surface);
SDL_Rect rectPokemonFront;
rectPokemonFront.x=200;
rectPokemonFront.y=140;
rectPokemonFront.w=160;
rectPokemonFront.h=160;
SDL_QueryTexture(pokemonFront_texture, NULL, NULL,  &image_width , &image_height);
SDL_RenderCopy((*motor)->renderer, pokemonFront_texture, NULL, &rectPokemonFront);
//---------------------------------------------------


    int i = 0;
    char intToText[50];
    char hp[10]="HP";
    char mp[10]="MP";
    //printf("1219\n");
    while (buffer != NULL) {
      text_draw(motor,buffer->pkm.pkm_name,600,105*i+70);
      text_draw(motor,"LVL",600,105*i+120);
      sprintf(intToText,"%d",buffer->pkm.lvl);
      text_draw(motor,intToText,650,105*i+120);
      sprintf(intToText,"%d",buffer->pkm.hp);
      strcat(intToText,hp);
      text_draw(motor,intToText,700,105*i+120);
      sprintf(intToText,"%d",buffer->pkm.mp);
      strcat(intToText,mp);
      text_draw(motor,intToText,780,105*i+120);
      buffer = buffer->next;
      i++;
    }
    //printf("1234\n");
    SDL_DestroyTexture(textureBackground);
    //  SDL_DestroyTexture(pokemonFront_texture);
    SDL_DestroyTexture(menu_texture);
  }
}


/**
* \function ecran_acceuil
* \brief interface pour l'écran principal du jeu
* \param motor : moteur de jeux
*/
//Fonctionne
void ecran_acceuil(motor_t ** motor){

  if ((*motor)->menu->menu_page_acceuil == 1){ //Mis à 0 par défaut

    SDL_Surface * surface;

    int image_width,image_height;

    //surface = IMG_Load("C:/Users/Sofiane/eclipse-workspace/SDL/images/Pictures/titlepage.png");
    surface = IMG_Load("src/asset/images/Pictures/titlepage.png");
    if (surface == NULL)
    printf("Erreur image page d'accueil\n");
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
    surface = IMG_Load("src/asset/images/Pictures/Select_Category.png");
    if (surface == NULL)
    printf("Erreur\n");
    SDL_Texture * select_texture = SDL_CreateTextureFromSurface((*motor)->renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect menuSelectMainScreen;
    menuSelectMainScreen.x = 760;
    menuSelectMainScreen.y = 100* (*motor)->menu->el_menu_main_screen_select+200;
    menuSelectMainScreen.w = 400;
    menuSelectMainScreen.h = 110;
    SDL_QueryTexture(select_texture, NULL, NULL,  &image_width , &image_height);
    SDL_RenderCopy((*motor)->renderer, select_texture, NULL, &menuSelectMainScreen);

    if ((*motor)->menu->save_available == 1) {
      text_draw(motor,"Continuer",800,240);
    }
    text_draw(motor,"Nouvelle partie",800,240);
    text_draw(motor,"Quitter",800,340);

    SDL_DestroyTexture(select_texture);
    SDL_DestroyTexture(textureBackground);

  }
}


void resetSelecteurs(motor_t ** motor){

  (*motor)->menu->el_menu_select = 0;
  (*motor)->menu->el_battle_menu_select = 0;
  (*motor)->menu->el_battle_menu_atk_select = 0;
  (*motor)->menu->el_menu_pokemon_select =0;
  (*motor)->menu->el_menu_save_select =0;
  (*motor)->menu->el_menu_main_screen_select =0;
}
