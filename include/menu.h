int init_menu(global_structure_t ** global_structure);

void menu(global_structure_t ** global_structure);

void speech_bubble(global_structure_t ** global_structure);

/**
  * \function render_text
  * \brief cette fonction permet de creer du texte et de le positioner
  * \param global_structure : moteur de jeux
  * \param text : texte à afficher
  * \param font : la police du texte à afficher
  * \param x : position x du texte
  * \param y : position y du texte
*/
void render_text(global_structure_t ** global_structure,char * text,TTF_Font *font,int x,int y);


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
  * \param global_structure : moteur de jeux
*/


  /**
    * \function menu_Bag
    * \brief menu du sac du joueur
    * \param global_structure : moteur de jeux
  */
  void menu_Bag(global_structure_t ** global_structure);


  /**
    * \function menu_Battle
    * \brief interface de combat du jeux
    * \param global_structure : moteur de jeux
    * \param player : structure de donnéees contenant les informations des pokémons du joueur
    * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  void menu_Battle(global_structure_t ** global_structure);


  /**
    * \function menu_Battle_Attaque
    * \brief interface de combat du jeux affichant les attaques disponibles pour le joueur

    * \param global_structure : moteur de jeux
    * \param player : structure de donnéees contenant les informations des pokémons du joueur
    * \param wild_pkm : structure de donnéees contenant les informations des pokémons adversaire
  */
  void menu_Battle_Attaque(global_structure_t ** global_structure);


    /**
      * \function speech_bubble
      * \brief fonction qui affiche une bulle de texte contenant du texte mis en paramètre
      * \param global_structure : moteur de jeux
      * \param text: texte à afficher dans la bulle
    */
//  void speech_bubble(global_structure_t ** global_structure,char * text);


  /**
    * \function menu_shop
    * \brief interface pour le marché
    * \param global_structure : moteur de jeux
  */
  void menu_shop(global_structure_t ** global_structure);

  /**
    * \function menu_save
    * \brief interface pour la sauvegarde de jeu
    * \param global_structure : moteur de jeux
  */
  void menu_save(global_structure_t ** global_structure);



  /**
    * \function menu_pokedex
    * \brief interface pour le pokedex qui est une sorte de base de données des pokémons
    * \param global_structure : moteur de jeux
  */
  void menu_pokedex(global_structure_t ** global_structure);



  /**
    * \function menu_pokemon
    * \brief interface pour la selection de pokemons pour le combat.
    * \param global_structure : moteur de jeux
  */
  void menu_pokemon(global_structure_t ** global_structure);


/**
  * \function ecran_acceuil
  * \brief interface pour l'écran principal du jeu
  * \param global_structure : moteur de jeux
*/
void ecran_acceuil(global_structure_t ** global_structure);


void resetSelecteurs(global_structure_t ** global_structure);
