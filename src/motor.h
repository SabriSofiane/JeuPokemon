typedef struct
{
    SDL_Texture * calque_map_1;     // Texture pour le calque n°1 de la map
    SDL_Texture * calque_map_2;     // Texture pour le calque n°2 de la map
    SDL_Texture * calque_map_3;     // Texture pour le calque n°3 de la map
    SDL_Texture * player_walk;      // Texture pour les sprite de marche du joueur
    SDL_Texture * player_run;       // Texture pour les sprite de course du joueur
    SDL_Texture * player_bike;      // Texture pour les sprite de vélo du joueur

    /*-------------------------------------*/
    //Ajouter vos nouvelles textures ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
    /*-------------------------------------*/


} texture_t;                        // Struture pour les textures

typedef struct
{
    SDL_Window * window;            // fenêtre SDL
    int width;                      // largeur de la fenêtre
    int height;                     // Hauteur de la fenêtre
    float size_coef;                // Coefficient d'échelle pour adapter les dimensions des textures par rapport à la taille de la fenêtre

} window_t;

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
  SDL_Rect ** map_rect;             // Ne pas utilisé

} map_t;                            // Struture pour la map (pas encore utilisé)

typedef struct
{
  int el_menu_select;//element de selection pour le menu principal
  int el_battle_menu_select;//element de selection pour le menu battle attaque
  int el_battle_menu_atk_select; //element de selection pour le menu battle attaque
  int el_menu_pokemon_select; //element de selection pour le menu pokemon
  int el_menu_save_select; //element de selection pour la sauvegarde
  int el_menu_main_screen_select; //element de selection pour la page d'acceuil /*nouveau*/
  int choixCombat; //variable de choix pour le combat
  SDL_Texture ** menu_textures;
  int taille;
  int speech_bubble; //variable pour l'affichage de la bulle de texte
  int menu_page_acceuil; //variable pour l'affichage de la page d'accueil /*nouveau*/
  int menu_principal; //variable pour l'affichage du menu principal
  int menu_battle; //variable pour l'affichage du menu battle
  int menu_battle_attaque; //variable pour l'affichage du menu battle attaque
  int menu_pokemon;//variable pour l'affichage du menu pokemon
  int menu_bag;//variable pour l'affichage du menu bag
  int menu_shop;//variable pour l'affichage du menu shop
  int menu_save; //variable pour l'affichage du menu de sauvegarde
  int save_available; //Modification d'affichage dans la fonction ecran_acceuil à Continuer si une sauvegarde est disponible /* A DEPLACER */
  int current_pokemon; ////variable utilisé pour savoir quelle pokémon est actif dans le combat.
} menu_t;

typedef struct
{
    window_t * windows;             // Structure de la fenêtre du moteur
    SDL_Renderer * renderer;        // Renderer du moteur
    texture_t * textures;           // Struture des textures ⚠️ En cas de d'ajout merci de le faire dans la zone prévu
    player_t * player;              // Struture du joueur
    char * last_key;                // Chaine de caractere qui contient la dernière touche pressée
    SDL_Event event;                // variable d'évènement SDL
    int quit;                       // variable boolean 0 (false) -> en fonctionnement, 1 (true) -> quitté
    menu_t * menu;
} motor_t;                          // Struture du moteur de jeu (⚠️merci de ne pas modifier⚠️)



/*-------------------------------------*/
//Ajouter vos nouvelles structures ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
/*-------------------------------------*/

//Structure qui defini un pkm
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
t_pkm pkm;
Liste_t * player;
Liste_t * testEnnemi;
t_pkm wild_pkm;

/**
  * \function init_motor
  * \brief Fonction d'initialisation de la structure globale de moteur de jeu
  * \return motor_t Retourne le moteur de jeux
*/
motor_t * init_motor()
{
    motor_t * motor = malloc(sizeof(motor_t));  // Création du moteur

    if(motor == NULL) // On test si le moteur a bien été créer
    {
        printf("Erreur pendant l'allocation mémoire pour le moteurr\n");
        return NULL;
    }
    else
    {
        printf("Creation du moteur\n");
    }

    /* Initialisation de la fenêtre du moteur */
    motor->windows = malloc(sizeof(window_t));  // Allocation de l'espace mémoire pour la fenêtre
    motor->windows->width = 1280;               // Définition de la largeur de la fenêtre
    motor->windows->height = 720;               // Définition de la hauteur de la fenêtre
    motor->windows->size_coef = 2;              // Définition du Coefficient d'échelle (ne vraiment pas modifier svp)

    /* Initialisation de la struture textures */
    motor->textures = malloc(sizeof(texture_t));

    /*
    Exemple d'initialisation d'une texture
    motor->textures->calque_map_1 = malloc(sizeof(SDL_Texture*));
    */
    /* Initialisation de tout les éléments utiles pour le menu et les interfaces. */
    motor->menu = malloc(sizeof(menu_t));
    //Initialisation de tout les selecteurs des menus
    motor->menu->el_menu_select = 0;
    motor->menu->el_battle_menu_select = 0;
    motor->menu->el_battle_menu_atk_select = 0;
    motor->menu->el_menu_pokemon_select=0;
    motor->menu->el_menu_save_select=0;
    motor->menu->el_menu_main_screen_select=0; /*nouveau*/

    motor->menu->choixCombat = 1;
    motor->menu->taille = 6;
    motor->menu->menu_textures = malloc(sizeof(SDL_Texture*)*10);
    motor->menu->save_available = 0;
    //Initialisation de toutes les variables qui concerne l'affichage des menu.
    motor->menu->speech_bubble = 0;
    motor->menu->menu_page_acceuil=0; /*nouveau*/
    motor->menu->menu_battle=1;
    motor->menu->menu_battle_attaque=0;
    motor->menu->menu_pokemon=0;
    motor->menu->menu_bag=0;
    motor->menu->menu_shop=0;
    motor->menu->menu_save=0;
    motor->menu->menu_principal=1;
    motor->menu->current_pokemon = 1;


    /* Initialisation de la chaine de char*/
    motor->last_key = malloc(10*sizeof(char));

    if(create_window_render(&motor->windows->window, &motor->renderer,motor->windows->width,motor->windows->height) == 0)  // Création de la fenêtre et du rendu
    {
        printf("Erreur a la creation de la fenetre du moteur\n");
        free(motor);
        return NULL;
    }

    motor->quit = 0;  // Empèche la fermeture du programme

    return motor;    // Retourne le moteur
}

/**
  * \function destroy_motor
  * \brief Fonction de destruction du moteur de jeu
  * \param motor : moteur de jeux
*/
void destroy_motor(motor_t ** motor)
{
  /*
  //⚠️
  Cette fonction de destruction du moteur est voué a fortement évolué au fur et à mesure des prochaines versions de nos codes
  si possible lors de la création d'un élément (structure, élément SDL ou autres)
  merci de créer une fonction de destruction et de l'appelé dans cette fonction.
  //⚠️
  */
    if(*motor != NULL)
    {
        destroy_window_render(&(*motor)->windows->window, &(*motor)->renderer);

        /*
        Exemple de destruction d'une texture

        SDL_DestroyTexture(motor->textures->calque_map_1);

        ⚠️ TOUJOURS détruire une élément d'une structure avant de détruire la structure
        */

        /*-------------------------------------*/
        //Ajouter vos nouvelles fonctions de destruction ICI (et donc pas ailleur, pour plus de simplicité lors de la fusion des codes)
        /*-------------------------------------*/


        free(&(*motor)->textures);
        free(&(*motor)->player);
        free(&(*motor)->last_key);

        printf("Destruction du moteur\n");
    }

    free(*motor);
    //*motor = NULL;
}
