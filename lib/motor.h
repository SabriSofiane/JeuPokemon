#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <dirent.h>
#include "../../include/SDL.h"
#include "../../include/SDL_image.h"
#include "../../include/SDL_mixer.h"
#include "../../include/SDL_ttf.h"

typedef struct
{
    SDL_Texture * texture_map;     // Texture pour la map
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
    float monney;                   // Pas encore utilisé
    int badge[8];                   // Pas encore utilisé
    int pkm_ids[6];                 // Pas encore utilisé
    SDL_Rect player_rect;           // Pas encore utilisé

} player_t;                         // Struture pour le joueur (donc avec les variables importante)

typedef struct
{
  int x;             // Ne pas utilisé
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
  SDL_Texture * texture;
}menu_texture_t;

typedef struct
{
  int el_menu_select;
  menu_texture_t ** menu_textures;
  int taille;
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
    SDL_bool key[SDL_NUM_SCANCODES];
    SDL_bool key_pressed;
    controller_t * controller;
    unsigned int motor_time;
    SDL_bool collision;
    int previous_time;
    int actual_time;
    map_t * map;
    keys_t keys;
    admin_console_t * admin_console;
    musique_t * musique;
} motor_t;                          // Struture du moteur de jeu (⚠️merci de ne pas modifier⚠️)


/*-------------------------------------*/
//Ajouter vos nouvelle structure ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
/*-------------------------------------*/


motor_t * init_motor();



void destroy_motor(motor_t ** motor);
