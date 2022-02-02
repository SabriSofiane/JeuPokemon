void init(motor_t ** motor)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    printf("Erreur durant l'initialisation Video de SDL");

  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 3)
    printf("Erreur durant l'initialisation de SDL IMAGE");

  if (init_player(&(*motor)) != 0)
    printf("Erreur durant l'initialisation du joueur");
/*
  if (SDL_Init(SDL_INIT_AUDIO) != 0)
    printf("Erreur durant l'initialisation de SDL Audio");
*/

  /*
  A activer quand ajout de SDL_TTF
  if(TTF_Init() != 0)
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
*/

  load_texture(&(*motor)->renderer,&(*motor)->textures->player_walk,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/dawn/dawn_walk.png");
}
