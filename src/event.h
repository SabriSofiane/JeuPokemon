/*
Le but de ce fichier est de gérer tous les événements, merci d'adopter la même
syntaxe lors d'ajout d'événement, par défaut les événements de déplacement de
la souris sont désactivées.
*/

/**
  * \function event_handle
  * \brief Gestion d'événement de la SDL
  * \param motor : moteur de jeux
*/
int event_handle(motor_t ** motor)
{
  int retour=3;
  SDL_WaitEvent(&(*motor)->event);

  if ((*motor)->event.type == SDL_MOUSEMOTION)
  return -1;

  char * key_pressed;
  key_pressed = (*motor)->last_key;
  if ((*motor)->event.type == SDL_KEYDOWN)
  {
    switch ((*motor)->event.key.keysym.sym)
    {
      case SDLK_z:
      key_pressed = "z";
      break;

      case SDLK_q:
      key_pressed = "q";
      break;

      case SDLK_s:
      key_pressed = "s";

      break;

      case SDLK_d:
      key_pressed = "d";
      break;



      case SDLK_RETURN:
      if((*motor)->menu->menu_save == 1){
        if((*motor)->menu->el_menu_save_select == 0){
          //fonction sauvegarde ici
        }else{
          (*motor)->menu->menu_save = 0;
        }

      }


      if((*motor)->menu->menu_page_acceuil == 1 && (*motor)->menu->el_menu_main_screen_select == 1){
        (*motor)->quit = 1;
      }


      if ((*motor)->menu->menu_battle == 1){
        switch ((*motor)->menu->el_battle_menu_select) {
          case 0:
          (*motor)->menu->menu_battle_attaque= 1;
          (*motor)->menu->menu_battle = 0;
          break;

          case 1:

          (*motor)->menu->menu_pokemon = 1;
          (*motor)->menu->menu_battle = 0;
          break;

          case 2:
          //(*motor)->menu->menu_battle_attaque= 1;
          (*motor)->menu->menu_battle = 0;
          break;
          case 3:
          //(*motor)->menu->menu_battle_attaque= 1;
          (*motor)->menu->menu_battle = 0;
          break;

        }
      }
      else if ((*motor)->menu->menu_battle_attaque == 1 && (*motor)->menu->menu_battle == 0){
        switch ((*motor)->menu->el_battle_menu_atk_select) {
          case 0:
          (*motor)->menu->choixCombat = 0;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);

            (*motor)->menu->el_battle_menu_select = 0;
            (*motor)->menu->el_battle_menu_atk_select = 0;

          break;
          case 1:
          (*motor)->menu->choixCombat = 1;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_battle_menu_atk_select = 0;
          break;
          case 2:
          (*motor)->menu->choixCombat = 2;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_battle_menu_atk_select = 0;
          break;
          case 3:
          (*motor)->menu->choixCombat = 3;
          retour = combat(player,&wild_pkm,(*motor)->menu->choixCombat);
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_battle_menu_atk_select = 0;
          break;

        }
        if(retour == 1 || retour == 0){    //plus pkm allie ou ennemi mort
          printf("Retour: %d\n", retour);
          (*motor)->menu->speech_bubble = 1;
          (*motor)->menu->menu_battle_attaque = 0;
        }
        else if (retour == 2){ //pkm allie k.o, pkm->next
          printf("Retour: %d\n", retour);
          (*motor)->menu->menu_pokemon = 1;
          (*motor)->menu->menu_battle_attaque = 0;
        }
        else if (retour == 3){  //tour suivant pas de k.o
          printf("Retour: %d\n", retour);
          (*motor)->menu->menu_battle = 1;
          (*motor)->menu->menu_battle_attaque = 0;

        }
      }
      else if ((*motor)->menu->menu_pokemon == 1 && (*motor)->menu->menu_battle == 0){
        switch ((*motor)->menu->el_menu_pokemon_select){
          case 1:
          if (swapNodes( 1, 2) == 1){
            (*motor)->menu->menu_battle = 1;
            (*motor)->menu->menu_pokemon = 0;
          }
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 2:
          if (swapNodes( 1, 3) == 1){
            (*motor)->menu->menu_battle = 1;
            (*motor)->menu->menu_pokemon = 0;
          }
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 3:
          if (swapNodes( 1, 4) == 1){
            (*motor)->menu->menu_battle = 1;
            (*motor)->menu->menu_pokemon = 0;
          }
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 4:
          if (swapNodes( 1, 5) == 1){
            (*motor)->menu->menu_battle = 1;
            (*motor)->menu->menu_pokemon = 0;
          }
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
          case 5:
          if (swapNodes( 1, 6) == 1){
            (*motor)->menu->menu_battle = 1;
            (*motor)->menu->menu_pokemon = 0;
          }
          (*motor)->menu->el_battle_menu_select = 0;
          (*motor)->menu->el_menu_pokemon_select = 0;
          break;
        }
      }

      break;

      case SDLK_m:
      key_pressed = "m";
      (*motor)->menu->menu_principal =1;


      break;

      case SDLK_b:
      key_pressed = "b";
      break;

      case SDLK_a:
      key_pressed = "a";
      (*motor)->menu->speech_bubble =0;
      break;

      case SDLK_UP:
      //Selectionneur du menu principal
      if ((*motor)->menu->el_menu_select > 0){
        (*motor)->menu->el_menu_select--;
      }
      else
      (*motor)->menu->el_menu_select = 5;

      //Selectionneur pour le menu battle
      if ((*motor)->menu->el_battle_menu_select > 0)
      (*motor)->menu->el_battle_menu_select--;
      else
      (*motor)->menu->el_battle_menu_select =3;
      //Selectionneur pour le menu de sauvegarde
      if ((*motor)->menu->el_menu_save_select > 0)
      (*motor)->menu->el_menu_save_select--;
      else
      (*motor)->menu->el_menu_save_select =1;

      //Selectionneur pour l'écran principal
      if ((*motor)->menu->el_menu_main_screen_select > 0)
      (*motor)->menu->el_menu_main_screen_select--;
      else
      (*motor)->menu->el_menu_main_screen_select =1;



      //Selectionneur pour le menu battle attaque
      if ((*motor)->menu->el_battle_menu_atk_select > 0)
      (*motor)->menu->el_battle_menu_atk_select--;
      else
      (*motor)->menu->el_battle_menu_atk_select =3;

      //Selectionneur pour le menu pokemon
      if ((*motor)->menu->el_menu_pokemon_select > 0)
      (*motor)->menu->el_menu_pokemon_select--;
      else
      (*motor)->menu->el_menu_pokemon_select = 5;

      /*
      if ((*motor)->menu->menu_pokemon == 1) {
        Algorithme de récupération de l'id du pokemon pour l'affichage dans le menu pokemon
        Par défaut current_pokemon vaut le premier de la liste.
        Si le menu pokemon est activé
          Le Pokemon actuel est attribué la valeur du pokemon de la liste
          Lorsque d'un appui up or down, on avance ou on recule de la liste

        (*motor)->menu->current_pokemon = temp->pkm.id;
        temp = temp->next;
      }
      */






      break;

      case SDLK_DOWN:

      //Selectionneur du menu principal
      if ((*motor)->menu->el_menu_select < 5)
      (*motor)->menu->el_menu_select++;
      else
      (*motor)->menu->el_menu_select = 0;

      //Selectionneur pour le menu battle
      if ((*motor)->menu->el_battle_menu_select < 3)
      (*motor)->menu->el_battle_menu_select++;
      else
      (*motor)->menu->el_battle_menu_select =0;


      //Selectionneur pour le menu battle attaque
      if ((*motor)->menu->el_battle_menu_atk_select < 3)
      (*motor)->menu->el_battle_menu_atk_select++;
      else
      (*motor)->menu->el_battle_menu_atk_select =0;

      //Selectionneur pour le menu pokemon
      if ((*motor)->menu->el_menu_pokemon_select < 5)
      (*motor)->menu->el_menu_pokemon_select++;
      else
      (*motor)->menu->el_menu_pokemon_select = 0;
      //Selectionneur pour le menu de sauvegarde
      if ((*motor)->menu->el_menu_save_select < 1)
      (*motor)->menu->el_menu_save_select++;
      else
      (*motor)->menu->el_menu_save_select =0;

      //Selectionneur pour l'écran principal
      if ((*motor)->menu->el_menu_main_screen_select < 1)
      (*motor)->menu->el_menu_main_screen_select++;
      else
      (*motor)->menu->el_menu_main_screen_select =0;

      break;

      default:
      break;
    }
    strcpy((*motor)->last_key,key_pressed);
  }
  else if ((*motor)->event.type == SDL_QUIT)
  {
    (*motor)->quit = 1;
  }

  return 1;
}
