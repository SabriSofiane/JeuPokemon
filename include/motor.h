#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <dirent.h>

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

/**/
//////////////FUSION//////////////////
//Ce qui defini un pkm
typedef struct{
  char pkm_name[50];
  char type1[50];
  char type2[50];
  int atk;
  int def;
  int spatk;
  int spdef;
  int sp;
  char talent[50];
  int hp;
  int mp;
  int lvl;
  int exp;
  char evolution[50];
  char skill[4][20];
  int pkmId;
  int id;
  int hpMax;
}t_pkm;

// Declaration du tableau contenant les elements de liste
typedef struct listeEl{
  t_pkm pkm;
  struct listeEl *next;
}Liste_t;
/**/


typedef struct
{
    SDL_Texture * texture_map;     // Texture pour la map
    SDL_Texture * texture_animation_water;
    SDL_Texture * player_walk;      // Texture pour les sprite de marche du joueur
    SDL_Texture * player_run;       // Texture pour les sprite de course du joueur
    SDL_Texture * player_bike;      // Texture pour les sprite de vélo du joueur

    /*-------------------------------------*/
    //Ajouter vos nouvelle textures ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
    /*-------------------------------------*/
} texture_t;                        // Struture pour les textures

typedef struct
{
    SDL_Window * window;            // Fenetre SDL
    TTF_Font * font;                //
    SDL_Color font_color;           //
    int width;                      // largeur de la fenetre
    int height;                     // Hauteur de la fenetre
    float size_coef;                // Coefficient d'échelle pour adapter les dimmension des textures par rapport à la taille de la fenetre
} window_t;

typedef struct
{
  int z_key;//move_left;
  int q_key;//move_right;
  int s_key;//move_up;
  int d_key;//move_down;

  int up_arrow;
  int left_arrow;
  int down_arrow;
  int right_arrow;

  int keypad0;
  int keypad1;
  int keypad2;
  int keypad3;
  int keypad4;
  int keypad5;
  int keypad6;
  int keypad7;
  int keypad8;
  int keypad9;

  int m_key;
  int virgule_key;
  int c_key;
  int t_key;

  int a_key;
  int b_key;
  int x_key;
  int y_key;

  int select_key;
  int start_key;

  char lastkey;
} keys_t;

typedef struct
{
    float posX;                     // Possition X du rectangle du joueur
    float posY;                     // Possition Y du rectangle du joueur
   int width;                      // Largeur du rectangle du joueur
   int height;                     // Hauteur du rectangle du joueur
   int movement_id;                // Correspond au numéro du sprite du joueur
   int speed;                      // Correspond à la vitesse de déplacement du joueur

   int player_cooldown;            // Pas encore utilisé
   SDL_Rect player_rect;           // Rectangle SDL pour le joueur
   int player_last_time;
   float move_step;

   //Liste_t * liste_player;
} player_t;                         // Struture pour le joueur (donc avec les variables importante)

typedef struct
{
  int x;                // Ne pas utilisé
  int y;
  char * spritesheet;
} npc_t;                            // Struture pour la map (pas encore utilisé)

typedef struct
{
  SDL_Texture * texture_map;
  SDL_Texture * texture_map_indoor;
  int map_id;
  char * music_path;
} map_t;                            // Struture pour la map (pas encore utilisé)

typedef struct
{
  char * texture_name;
  SDL_Texture ** menu_textures;
  SDL_Texture * texture_speech_bubble;
  SDL_Texture * texture_Menu_icon;
  SDL_Texture * texture_Menu_Back;
  SDL_Texture * texture_Menu_curseur;
  SDL_Texture * texture_bagfond;
  SDL_Texture * texture_battle11;
  SDL_Texture * texture_ChoixMultiple;
  SDL_Texture * texture_battle_sprite4;
  SDL_Texture * texture_battle_sprite3;
  SDL_Texture * texture_hpbar;
  SDL_Texture * texture_groundbattle11;
  SDL_Texture * texture_Front_Male;
  SDL_Texture * texture_Back_Male;
  int texture_Back_Male_id;
  SDL_Texture * texture_ChoixAttaque;
  SDL_Texture * texture_boxback;
  SDL_Texture * texture_shopfond;
  SDL_Texture * texture_Background_1;
  SDL_Texture * texture_Background_2;
  SDL_Texture * texture_Windows_Pkdx_Detail;
  SDL_Texture * texture_Partyfond2;
  SDL_Texture * texture_Select_Category;
  SDL_Texture * texture_titlepage;
  /*
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  SDL_Texture * texture_;
  */
}menu_texture_t;

typedef struct
{
  int el_menu_select;
  int el_battle_menu_select;
  int el_battle_menu_atk_select;
  int el_menu_pokemon_select;
  int el_menu_save_select;
  int el_menu_main_screen_select; //new
  int choixCombat;
  menu_texture_t textures_menu;
  char speech_bubble_text[255];
  int taille;
  int speech_bubble;
  int menu_page_acceuil;
  int menu_principal;
  int menu_battle;
  int menu_battle_attaque;
  int menu_pokemon;
  int menu_bag;
  int menu_shop;
  int menu_save;
  int menu_pokedex;
  int combat;
  int save_available; //Modification d'affichage dans la fonction ecran_acceuil à Continuer si une sauvegarde est disponible /* A DEPLACER */
  int current_pokemon;
} menu_t;


typedef struct
{
   int leftX;                     // Axe X du joystick de Gauche
   int leftY;                     // Axe Y du joystick de Gauche
   int rightX;                    // Axe X du joystick de Droite
   int rightY;                    // Axe Y du joystick de Droite

    char joy;

   int press;

   int joystick_max_offset;
    SDL_GameController * controller;
    SDL_Joystick * joy1;
    SDL_Joystick * joy2;
} controller_t;

typedef struct
{
  Mix_Music * music;
  int volume;
  char * track_path;
  char * track_path_list[20];
  int track_in_list;
  int loop;
} musique_t;

typedef struct
{
  int menu_change;
  int selected_menu;
  int selection_bar_x;
  int selection_bar_y;
  char keypad[5];
  char arguments[10][5];
  unsigned int key_delay;
} admin_console_t;


typedef struct
{
    window_t * windows;             // Structure de la fenetre du moteur
    SDL_Renderer * renderer;        // Renderer du moteur
    texture_t * textures;           // Struture des textures ⚠️ En cas de d'ajout merci de le faire dans la zone prévu
    player_t * player;              // Struture du joueur
    SDL_Event event;                // variable d'évènement SDL
    int quit;                       // variable boolean 0 (false) -> en fonctionnement, 1 (true) -> quitté
    int tiles_number;
    char *** matrice_file;
    controller_t * controller;
    SDL_bool collision;
    unsigned int previous_time;
    unsigned int actual_time;
    map_t * map;
    keys_t keys;
    admin_console_t * admin_console;
    musique_t * musique;
    menu_t * menu;
    t_pkm pkm;
    t_pkm wild_pkm;
    Liste_t * liste_player;
} motor_t;                          // Struture du moteur de jeu (⚠️merci de ne pas modifier⚠️)


/*-------------------------------------*/
//Ajouter vos nouvelle structure ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
/*-------------------------------------*/


motor_t * init_motor();

void destroy_motor(motor_t ** motor);
