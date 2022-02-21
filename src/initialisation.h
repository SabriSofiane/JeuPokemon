/*
Le but de ce fichier est d'initialiser les structures, les modules SDL
et les autres éléments nécessaire par la suite (texture, ressource audio, fichiers etc)

Si possible lors de la création de nouvelles fonctions,
merci de créer des fonctions d'initialisation pour les variables et autres fichiers
nécéssaire et de les appeler depuis la fonction ci-dessous.
*/

void init(motor_t ** motor)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    printf("Erreur durant l'initialisation Video de SDL");

  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 3)
    printf("Erreur durant l'initialisation de SDL IMAGE");

/*
  Permet d'initialiser le joueur (ne pas décommenter si pas besoin)
  if (init_player(&(*motor)) != 0)
    printf("Erreur durant l'initialisation du joueur");
*/

/*
  Ne pas décommenter
  if (SDL_Init(SDL_INIT_AUDIO) != 0)
    printf("Erreur durant l'initialisation de SDL Audio");
*/


  if(TTF_Init() != 0)
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());


/*
  Exemple d'initialisation de textures

  load_texture(&(*motor)->renderer,&(*motor)->textures->player_walk,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/lyra/lyra_walk.png");
  load_texture(&(*motor)->renderer,&(*motor)->textures->player_run,"C:/Users/Elias/Desktop/JEU_POKEMON/truc_bien_range/asset/lyra/lyra_run.png");
*/
}
