int init_menu(motor_t ** motor);

void menu(motor_t ** motor);

void speech_bubble(motor_t ** motor);

/**
  * \function render_text
  * \brief cette fonction permet de creer du texte et de le positioner
  * \param motor : moteur de jeux
  * \param text : texte à afficher
  * \param font : la police du texte à afficher
  * \param x : position x du texte
  * \param y : position y du texte
*/
void render_text(motor_t ** motor,char * text,TTF_Font *font,int x,int y);


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
SDL_Color color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
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
void RenderHPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor,SDL_Renderer *renderer);

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
  void menu_Bag(motor_t ** motor);


  /**
    * \function menu_Battle
    * \brief interface de combat du jeux
    * \param motor : moteur de jeux
    * \param player : structure de donnéees contenant les informations des pokémons du joueur
    * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  void menu_Battle(motor_t ** motor);


  /**
    * \function menu_Battle_Attaque
    * \brief interface de combat du jeux affichant les attaques disponibles pour le joueur

    * \param motor : moteur de jeux
    * \param player : structure de donnéees contenant les informations des pokémons du joueur
    * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  void menu_Battle_Attaque(motor_t ** motor);


    /**
      * \function speech_bubble
      * \brief fonction qui affiche une bulle de texte contenant du texte mis en paramètre
      * \param motor : moteur de jeux
      * \param text: texte à afficher dans la bulle
    */
//  void speech_bubble(motor_t ** motor,char * text);


  /**
    * \function menu_shop
    * \brief interface pour le marché
    * \param motor : moteur de jeux
  */
  void menu_shop(motor_t ** motor);

  /**
    * \function menu_save
    * \brief interface pour la sauvegarde de jeu
    * \param motor : moteur de jeux
  */
  void menu_save(motor_t ** motor);



  /**
    * \function menu_pokedex
    * \brief interface pour le pokedex qui est une sorte de base de données des pokémons
    * \param motor : moteur de jeux
  */
  void menu_pokedex(motor_t ** motor);



  /**
    * \function menu_pokemon
    * \brief interface pour la selection de pokemons pour le combat.
    * \param motor : moteur de jeux
  */
  void menu_pokemon(motor_t ** motor);


/**
  * \function ecran_acceuil
  * \brief interface pour l'écran principal du jeu
  * \param motor : moteur de jeux
*/
void ecran_acceuil(motor_t ** motor);


void resetSelecteurs(motor_t ** motor);
