typedef struct
{
    SDL_Texture * calque_map_1;
    SDL_Texture * calque_map_2;
    SDL_Texture * calque_map_3;
    SDL_Texture * player_walk;
    SDL_Texture * player_run;
    SDL_Texture * player_bike;
} texture_t;

typedef struct
{
    SDL_Window * window;
    int width;
    int height;
    float size_coef;
} window_t;

typedef struct
{
    int posX;
    int posY;
    int width;
    int height;
    int movement_id;
    int player_cooldown;
    //
    float monney;
    int badge[8];
    int pkm_ids[6];
    int speed;
    SDL_Rect player_rect;
} player_t;

typedef struct
{
  SDL_Rect ** map_rect;
} map_t;

typedef struct
{
    window_t * windows;
    SDL_Renderer * renderer;
    texture_t * textures;
    player_t * player;
    char * last_key;
    SDL_Event event;
    int quit; // variable boolean 0 (false) -> en fonctionnement, 1 (true) -> quitté
} motor_t;

motor_t * init_motor()
{
    int retour = 0;
    motor_t * motor = malloc(sizeof(motor_t));

    if(motor == NULL)
    {
        printf("Erreur pendant l'allocation mémoire pour le moteurr\n");
        return NULL;
    }
    else
    {
        printf("Creation du moteur\n");
    }

    /* Initialisation de la fenetre du moteur */
    motor->windows = malloc(sizeof(window_t));
    motor->windows->width = 1280;
    motor->windows->height = 720;
    motor->windows->size_coef = 2;

    /* Initialisation de la texture */
    motor->textures = malloc(sizeof(texture_t));

    /* Initialisation de la chaine de char*/
    motor->last_key = malloc(10*sizeof(char));

    /* Initialisation du joueur */
    motor->player = malloc(sizeof(player_t));
    motor->player->movement_id = 1;

    SDL_GetWindowSize(motor->windows->window, &motor->windows->width, &motor->windows->height);

    if(create_window_render(&motor->windows->window, &motor->renderer,motor->windows->width,motor->windows->height) == 0)
    {
        printf("Erreur a la creation de la fenetre du moteur\n");
        free(motor);
        return NULL;
    }

    strcpy(motor->last_key,"s");
    motor->quit = 0;

    return motor;
}


void destroy_motor(motor_t ** motor)
{
    if(*motor != NULL)
    {
        destroy_window_render(&(*motor)->windows->window, &(*motor)->renderer);
        free(&(*motor)->windows);
        free(&(*motor)->player);
        free(&(*motor)->last_key);
        printf("Destruction du moteur\n");
    }
    free(*motor);
    *motor = NULL;
}
