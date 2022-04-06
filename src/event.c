/**
  * \file event.c
  * \brief fichier de gestion des événements
  * \author Elias OKAT
  * \version 1
  * \date 28 février 2022
*/
#include "../include/global_structure.h"
#include "../include/event.h"
#include "../include/string_matrice.h"
#include "../include/collisions.h"
#include "../include/audio.h"
#include "../include/menu.h"
#include "../include/combat.h"

/**
  * \function mouvement
  * \param global_structure : moteur de jeu
  * \param move_add : valeur de déplacement
  * \param axis : axe auquel le personnage devra se déplacer
*/
void mouvement(global_structure_t ** global_structure, float move_add, char axis) {
  if ((*global_structure)->keys.z_key + (*global_structure)->keys.q_key + (*global_structure)->keys.s_key + (*global_structure)->keys.d_key == 1)
  {
    if (axis == 'x')
    {
      (*global_structure)->player->posX += move_add;
    }
    else if (axis == 'y')
    {
      (*global_structure)->player->posY += move_add;
    }

    if ((*global_structure)->keys.z_key == 1)
    {
      (*global_structure)->keys.q_key = 0;
      (*global_structure)->keys.s_key = 0;
      (*global_structure)->keys.d_key = 0;
    } else if ((*global_structure)->keys.q_key == 1)
    {
      (*global_structure)->keys.z_key = 0;
      (*global_structure)->keys.s_key = 0;
      (*global_structure)->keys.d_key = 0;
    } else if ((*global_structure)->keys.s_key == 1)
    {
      (*global_structure)->keys.z_key = 0;
      (*global_structure)->keys.q_key = 0;
      (*global_structure)->keys.d_key = 0;
    } else if ((*global_structure)->keys.d_key == 1)
    {
      (*global_structure)->keys.z_key = 0;
      (*global_structure)->keys.q_key = 0;
      (*global_structure)->keys.s_key = 0;
    }
  }
}
/**
  * \function event_handle
  * \param global_structure : moteur de jeu
  * \return retourne l'événement
*/
int event_handle(global_structure_t ** global_structure) {
  int retour=3;
  while (SDL_PollEvent(&(*global_structure)->event)) {

    float move_step =  (*global_structure)->player->move_step;

    if ((*global_structure)->event.type == SDL_KEYDOWN)
    {
      switch ((*global_structure)->event.key.keysym.sym)
      {
        case SDLK_z:

        if (((*global_structure)->keys.q_key + (*global_structure)->keys.d_key) == 0)
        {
          if ((*global_structure)->keys.lastkey != 'z')
          (*global_structure)->player->posY += (-1)*move_step;
          else if (((*global_structure)->keys.z_key == 0))
          (*global_structure)->player->posY += (-1)*move_step;

          if (((*global_structure)->keys.z_key == 0))
          (*global_structure)->player->movement_id = 1;


          (*global_structure)->keys.z_key = 1;
          mouvement(global_structure,(-1)*move_step,'y');
          (*global_structure)->keys.lastkey = 'z';
        }

        break;

        case SDLK_q:

        if (((*global_structure)->keys.z_key + (*global_structure)->keys.s_key) == 0)
        {

          if ((*global_structure)->keys.lastkey != 'q')
          (*global_structure)->player->posX += (-1)*move_step;
          else if (((*global_structure)->keys.q_key == 0))
          (*global_structure)->player->posX += (-1)*move_step;

          if (((*global_structure)->keys.q_key == 0))
          (*global_structure)->player->movement_id = 1;




          (*global_structure)->keys.q_key = 1;
          mouvement(global_structure,(-1)*move_step,'x');
          (*global_structure)->keys.lastkey = 'q';
        }
        break;

        case SDLK_s:

        if (((*global_structure)->keys.q_key + (*global_structure)->keys.d_key) == 0)
        {

          if ((*global_structure)->keys.lastkey != 's')
          (*global_structure)->player->posY += move_step;
          else if (((*global_structure)->keys.s_key == 0))
          (*global_structure)->player->posY += move_step;

          if (((*global_structure)->keys.s_key == 0))
          (*global_structure)->player->movement_id = 1;

          (*global_structure)->keys.s_key = 1;
          mouvement(global_structure,move_step,'y');
          (*global_structure)->keys.lastkey = 's';
        }
        break;

        case SDLK_d:

        if (((*global_structure)->keys.z_key + (*global_structure)->keys.s_key) == 0)
        {
          if ((*global_structure)->keys.lastkey != 'd')
          (*global_structure)->player->posX += move_step;
          else if (((*global_structure)->keys.d_key == 0))
          (*global_structure)->player->posX += move_step;

          if (((*global_structure)->keys.d_key == 0))
          (*global_structure)->player->movement_id = 1;

          (*global_structure)->keys.d_key = 1;
          mouvement(global_structure,move_step,'x');
          (*global_structure)->keys.lastkey = 'd';
        }
        break;

        case SDLK_ESCAPE:
        //-----------------NOUVEAU----------------------
        if((*global_structure)->menu->menu_save == 1){
          (*global_structure)->menu->menu_save = 0;
        }
        if((*global_structure)->menu->menu_pokedex == 1){
          (*global_structure)->menu->menu_pokedex = 0;
        }
        if((*global_structure)->menu->menu_pokemon == 1){
          (*global_structure)->menu->menu_pokemon = 0;
        }
        if((*global_structure)->menu->menu_bag == 1){
          (*global_structure)->menu->menu_bag = 0;
        }
        if((*global_structure)->menu->menu_shop == 1){
          (*global_structure)->menu->menu_shop = 0;
        }
        //-----------------------------------------------
        break;


        case SDLK_RETURN:
        if((*global_structure)->menu->menu_save == 1){
          if((*global_structure)->menu->el_menu_save_select == 0){
            FILE* fout = fopen("player", "wb");
            fwrite((*global_structure)->player, sizeof(player_t), 1, fout);
            fclose(fout);
          }else{
            (*global_structure)->menu->menu_save = 0;
          }

        }

        if((*global_structure)->menu->menu_principal == 1){
          switch ((*global_structure)->menu->el_menu_select) { //switch pour le menu principal
            case 0 :
            (*global_structure)->menu->menu_pokedex= 1;
            (*global_structure)->menu->menu_principal=0;
            resetSelecteurs(&(*global_structure));
            break;

            case 1:
            (*global_structure)->menu->menu_pokemon= 1;
            (*global_structure)->menu->menu_principal=0;
            resetSelecteurs(&(*global_structure));
            break;

            case 2:
            (*global_structure)->menu->menu_bag= 1;
            (*global_structure)->menu->menu_principal=0;
            resetSelecteurs(&(*global_structure));
            break;

            case 32:
            //(*global_structure)->menu->menu_bag= 1;
            (*global_structure)->menu->menu_principal=0;
            resetSelecteurs(&(*global_structure));
            break;

            case 3:
            (*global_structure)->menu->menu_save= 1;
            (*global_structure)->menu->menu_principal=0;
            resetSelecteurs(&(*global_structure));
            break;

            case 4:
            (*global_structure)->menu->menu_principal=0;
            break;
          }
          //--------------------------------------
        }


        if((*global_structure)->menu->menu_page_acceuil == 1 && (*global_structure)->menu->el_menu_main_screen_select == 1){
          (*global_structure)->quit = 1;
        }


        if ((*global_structure)->menu->menu_battle == 1){
          (*global_structure)->menu->combat = 1;
          switch ((*global_structure)->menu->el_battle_menu_select) {
            case 0:
            (*global_structure)->menu->menu_battle_attaque= 1;
            (*global_structure)->menu->menu_battle = 0;
            break;

            case 1:
            (*global_structure)->menu->menu_pokemon = 1;
            (*global_structure)->menu->menu_battle = 0;
            resetSelecteurs(&(*global_structure)); //NOUVEAU : Reset de selecteur
            break;

            case 2:
            //(*global_structure)->menu->menu_battle_attaque= 1;
            if (capturer(&(*global_structure),(*global_structure)->liste_player,(*global_structure)->wild_pkm) == 1){ //NOUVEAU : CAPTURE DE Pokemon
              printf("Vous avez capture %s !\n",(*global_structure)->wild_pkm.pkm_name);
              (*global_structure)->menu->menu_battle = 0;
              (*global_structure)->menu->combat = 0;
            }

            break;
            case 3:
            //(*global_structure)->menu->menu_battle_attaque= 1;
            (*global_structure)->menu->menu_battle = 0;
            break;

          }
        }
        //Combat 1 pkm
        else if ((*global_structure)->menu->menu_battle_attaque == 1 && (*global_structure)->menu->menu_battle == 0){
          switch ((*global_structure)->menu->el_battle_menu_atk_select) {
            case 0:
            (*global_structure)->menu->choixCombat = 0;
            retour = combat((*global_structure)->liste_player,&(*global_structure)->wild_pkm,(*global_structure)->menu->choixCombat);
            resetSelecteurs(&(*global_structure));
            break;
            case 1:
            (*global_structure)->menu->choixCombat = 1;
            retour = combat((*global_structure)->liste_player,&(*global_structure)->wild_pkm,(*global_structure)->menu->choixCombat);
            resetSelecteurs(&(*global_structure));
            break;
            case 2:
            (*global_structure)->menu->choixCombat = 2;
            retour = combat((*global_structure)->liste_player,&(*global_structure)->wild_pkm,(*global_structure)->menu->choixCombat);
            resetSelecteurs(&(*global_structure));
            break;
            case 3:
            (*global_structure)->menu->choixCombat = 3;
            retour = combat((*global_structure)->liste_player,&(*global_structure)->wild_pkm,(*global_structure)->menu->choixCombat);
            resetSelecteurs(&(*global_structure));
            break;

          }
          if(retour == 0){    //le joueur a perdu le combat et n'a plus de pkm en vie
            printf("Retour: %d\n", retour);
            strncpy((*global_structure)->menu->speech_bubble_text,"Tous vos pokemon sont Ko",1);
            (*global_structure)->menu->speech_bubble = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;
            (*global_structure)->menu->combat = 0;
          }
          else if(retour == 1){    //le joueur a gagné le combat
            printf("Retour: %d\n", retour);
            strncpy((*global_structure)->menu->speech_bubble_text,"Vous avez gagné !",1);
            (*global_structure)->menu->speech_bubble = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;
            (*global_structure)->menu->combat = 0;
          }
          else if (retour == 2){ //pkm allie k.o, pkm->next
            printf("Retour: %d\n", retour);
            (*global_structure)->menu->menu_pokemon = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;
          }
          else if (retour == 3){  //tour suivant pas de k.o
            printf("Retour: %d\n", retour);
            (*global_structure)->menu->menu_battle = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;

          }
        }
        //Combat dresseur
        /*
        else if ((*global_structure)->menu->menu_battle_attaque == 1 && (*global_structure)->menu->menu_battle == 0){
          print_list(player);
          printf("-----------------------------------\n");
          print_list(testEnnemi);
          printf("-----------------------------------\n");
          switch ((*global_structure)->menu->el_battle_menu_atk_select) {
            case 0:
            (*global_structure)->menu->choixCombat = 0;
            retour = combatDresseur(player,testEnnemi,(*global_structure)->menu->choixCombat);
            (*global_structure)->menu->el_battle_menu_select = 0;
            (*global_structure)->menu->el_battle_menu_atk_select = 0;
            break;
            case 1:
            (*global_structure)->menu->choixCombat = 1;
            retour = combatDresseur(player,testEnnemi,(*global_structure)->menu->choixCombat);
            (*global_structure)->menu->el_battle_menu_select = 0;
            (*global_structure)->menu->el_battle_menu_atk_select = 0;
            break;
            case 2:
            (*global_structure)->menu->choixCombat = 2;
            retour = combatDresseur(player,testEnnemi,(*global_structure)->menu->choixCombat);
            (*global_structure)->menu->el_battle_menu_select = 0;
            (*global_structure)->menu->el_battle_menu_atk_select = 0;
            break;
            case 3:
            (*global_structure)->menu->choixCombat = 3;
            retour = combatDresseur(player,testEnnemi,(*global_structure)->menu->choixCombat);
            (*global_structure)->menu->el_battle_menu_select = 0;
            (*global_structure)->menu->el_battle_menu_atk_select = 0;
            break;

          }
          if(retour == 1 || retour == 0){    //plus pkm allie ou ennemi mort
            printf("Retour: %d\n", retour);
            (*global_structure)->menu->speech_bubble = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;
          }
          else if (retour == 2){ //pkm allie k.o, pkm->next
            printf("Retour: %d\n", retour);
            (*global_structure)->menu->menu_pokemon = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;
          }
          else if (retour == 3){  //tour suivant pas de k.o
            printf("Retour: %d\n", retour);
            if (testEnnemi->pkm.hp <=0)
              testEnnemi = testEnnemi->next;
            (*global_structure)->menu->menu_battle = 1;
            (*global_structure)->menu->menu_battle_attaque = 0;

          }
        }*/
        else if ((*global_structure)->menu->menu_pokemon == 1 && (*global_structure)->menu->menu_battle == 0 && (*global_structure)->menu->combat ==1) {
          switch ((*global_structure)->menu->el_menu_pokemon_select){
            case 1:

            if (swapNodes(&(*global_structure), 1, 2) == 0){
              (*global_structure)->menu->menu_battle = 1;
              (*global_structure)->menu->menu_pokemon = 0;
            }
            resetSelecteurs(&(*global_structure));//NOUVEAU : Reset de selecteur

            break;
            case 2:
            if (swapNodes(&(*global_structure), 1, 3) == 0){
              (*global_structure)->menu->menu_battle = 1;
              (*global_structure)->menu->menu_pokemon = 0;
            }
            resetSelecteurs(&(*global_structure));//NOUVEAU : Reset de selecteur

            break;
            case 3:
            if (swapNodes(&(*global_structure), 1, 4) == 0){
              (*global_structure)->menu->menu_battle = 1;
              (*global_structure)->menu->menu_pokemon = 0;
            }
            resetSelecteurs(&(*global_structure));//NOUVEAU : Reset de selecteur

            break;
            case 4:
            if (swapNodes(&(*global_structure), 1, 5) == 0){
              (*global_structure)->menu->menu_battle = 1;
              (*global_structure)->menu->menu_pokemon = 0;
            }
            resetSelecteurs(&(*global_structure));//NOUVEAU : Reset de selecteur

            break;
            case 5:
            if (swapNodes(&(*global_structure), 1, 6) == 0){
              (*global_structure)->menu->menu_battle = 1;
              (*global_structure)->menu->menu_pokemon = 0;
            }
            resetSelecteurs(&(*global_structure));//NOUVEAU : Reset de selecteur

            break;
          }
        }

        break;

        case SDLK_m:
        (*global_structure)->menu->menu_principal =1;
        break;

        case SDLK_k:
        system("cls");

        int y = (*global_structure)->player->posY;
        y -= 5;
        char *** mat2 = get_String_Matrice(&(*global_structure), 0, (*global_structure)->player->posX, y);
        char command[100];
        sprintf(command, "node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\index.js %0.f %0.f 1", (*global_structure)->player->posY,(*global_structure)->player->posX);
        system(command);

        detruire_string_matrice(mat2, 1);
        mat2 = NULL;
        break;

        case SDLK_b:
        /*
        //printf("%i\n",(*global_structure)->collision_cell_add[(*global_structure)->nb_collision_cell_add]);
        if ((*global_structure)->player->speed == 1)
        (*global_structure)->player->speed = 2;
        else
        (*global_structure)->player->speed = 1;

        printf("Vitesse : %i\n", (*global_structure)->player->speed);
        */
        printf("Position : %0.f;%0.f\n", (*global_structure)->player->posX,(*global_structure)->player->posY);
        break;

        case SDLK_l:;
        FILE* fout = fopen("player", "wb");
        fwrite((*global_structure)->player, sizeof(player_t), 1, fout);
        fclose(fout);
        break;

        case SDLK_r:;
        player_t lol;
        FILE* fout2 = fopen("player","rb");
        fread(&lol, sizeof(player_t), 1, fout2);
        fclose(fout2);

        printf("%f\n",lol.posX);
        break;

        case SDLK_a:;

        if ((*global_structure)->menu->speech_bubble == 1)
        (*global_structure)->menu->speech_bubble = 0;

        if (1 == 2)
        {
          char *** mat;
          int px = (*global_structure)->player->posX;

          mat = get_String_Matrice(&(*global_structure), 0, px, (*global_structure)->player->posY-4);
          int calque1 = split_string_data(mat[0][0],',',0);
          int calque2 = split_string_data(mat[0][0],',',1);
          int calque3 = split_string_data(mat[0][0],',',2);
          int calque4 = split_string_data(mat[0][0],',',3);
          int calque_collision = split_string_data(mat[0][0],',',4);


          printf("calque1 : %i \ncalque2 : %i \ncalque3 : %i \ncalque4 : %i \ncalque_collision : %i \n Full calque : %s",calque1,calque2,calque3,calque4,calque_collision,mat[0][0]);
          detruire_string_matrice(mat, 1);
        }
        if (1 == 3) {
          char *** mat;
          int px = (*global_structure)->player->posX;

          mat = get_String_Matrice(&(*global_structure), 0, px, (*global_structure)->player->posY-4);
          //int mat_val = split_string_data(mat[i][j],',',0);
          printf("%s\n", mat[0][0]);
          detruire_string_matrice(mat, 1);
        } //Trouver la position
        else if (1 == 1)
        {
          int * arguments = check_interaction(&(*global_structure));

          printf("A pressed %i;%i;%i \n",arguments[4],arguments[5],arguments[6]);

          for (size_t i = 0; i < 7; i++) {
            printf("argument[%i] = %i\n",i,arguments[i]);
          }

          //Le joueur a appuyé sur A en face d'une entié avec une interaction possible.
          /*
          arg 0 : 3;
          arg 1 : type d'interaction (1 : texte a afficher, 2 : combat a lancer, 3 : teleportation, 4 : objet a ramasser, 5 : utiliser la canne a pêche);
          arg 2 : donnée propre a l'interaction (1 : numéro du texte a afficher, 2 : numero du dresseur à combattre, 3 : numero du texte a afficher avant teleportation, 4 : numero de l'objet a ramasser, 5 : rien);
          arg 3 : numero de la musique a jouer, si pas de changement nécessaire (-1);
          *///(arguments[5])

          switch (arguments[5]) {
            case 1:;
            FILE * file;

            char buffer[10];
            sprintf(buffer,"src/asset/dialogues/data/%i.txt",arguments[6]);
            file = fopen(buffer, "r");

            if (file == NULL) {
              printf("Erreur au chargement du fichier du dialogue\n");
            }

            char string[255] = "";
            fscanf(file,"%s",string);
            while (!feof(file)) {
              char buffer[255] = "";
              fscanf(file,"%s",buffer);
              strncat(string, " ", 2);
              strncat(string, buffer, strlen(buffer));
            }



            (*global_structure)->menu->speech_bubble = 1;

            strncpy((*global_structure)->menu->speech_bubble_text,string,ftell(file));
            speech_bubble(&(*global_structure));
            fclose(file);



            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            default:
            break;
          }


        }
        break;

        case SDLK_t:
        stop_sound();
        play_sound(global_structure,(*global_structure)->musique->track_path_list[1],-1,10);
        printf("Check_collision : %i\n",check_collision(global_structure));
        break;

        case SDLK_c:;
        //(*global_structure)->collision != (*global_structure)->collision;
        //printf("%s\n",(*global_structure)->collision );

        char command2[100];
        //sprintf(command2, "node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\dialog.js %i %f %f %i %s %s %s",(*global_structure)->map->map_id,(*global_structure)->player->posX,(*global_structure)->player->posY-4,(*global_structure)->admin_console->selected_menu+1,(*global_structure)->admin_console->arguments[0],(*global_structure)->admin_console->arguments[1],(*global_structure)->admin_console->arguments[2]);
        system(command2);

        break;

        case SDLK_y:
        SDL_SetWindowSize((*global_structure)->windows->window,2000,720);
        break;

        case SDLK_w:
        break;

        case SDLK_o:
        (*global_structure)->quit = 1;
        break;

        case SDLK_LEFT:
        (*global_structure)->keys.left_arrow = 1;
        break;

        case SDLK_UP:
        //Selectionneur du menu principal
        if ((*global_structure)->menu->el_menu_select > 0){
          (*global_structure)->menu->el_menu_select--;
        }
        else
        (*global_structure)->menu->el_menu_select = 4;

        //Selectionneur pour le menu battle
        if ((*global_structure)->menu->el_battle_menu_select > 0)
        (*global_structure)->menu->el_battle_menu_select--;
        else
        (*global_structure)->menu->el_battle_menu_select =3;
        //Selectionneur pour le menu de sauvegarde
        if ((*global_structure)->menu->el_menu_save_select > 0)
        (*global_structure)->menu->el_menu_save_select--;
        else
        (*global_structure)->menu->el_menu_save_select =1;

        //Selectionneur pour l'écran principal
        if ((*global_structure)->menu->el_menu_main_screen_select > 0)
        (*global_structure)->menu->el_menu_main_screen_select--;
        else
        (*global_structure)->menu->el_menu_main_screen_select =1;



        //Selectionneur pour le menu battle attaque
        if ((*global_structure)->menu->el_battle_menu_atk_select > 0)
        (*global_structure)->menu->el_battle_menu_atk_select--;
        else
        (*global_structure)->menu->el_battle_menu_atk_select =3;

        //Selectionneur pour le menu pokemon
        if ((*global_structure)->menu->el_menu_pokemon_select > 0)
        (*global_structure)->menu->el_menu_pokemon_select--;
        else
        (*global_structure)->menu->el_menu_pokemon_select = 5;

        /*
        if ((*global_structure)->menu->menu_pokemon == 1) {
        Algorithme de récupération de l'id du pokemon pour l'affichage dans le menu pokemon
        Par défaut current_pokemon vaut le premier de la liste.
        Si le menu pokemon est activé
        Le Pokemon actuel est attribué la valeur du pokemon de la liste
        Lorsque d'un appui up or down, on avance ou on recule de la liste
        (*global_structure)->menu->current_pokemon = temp->pkm.id;
        temp = temp->next;
      }
      */






      (*global_structure)->keys.up_arrow = 1;
      break;

      case SDLK_DOWN:
      (*global_structure)->keys.down_arrow = 1;
      //Selectionneur du menu principal
      if ((*global_structure)->menu->el_menu_select < 4)
      (*global_structure)->menu->el_menu_select++;
      else
      (*global_structure)->menu->el_menu_select = 0;

      //Selectionneur pour le menu battle
      if ((*global_structure)->menu->el_battle_menu_select < 3)
      (*global_structure)->menu->el_battle_menu_select++;
      else
      (*global_structure)->menu->el_battle_menu_select =0;


      //Selectionneur pour le menu battle attaque
      if ((*global_structure)->menu->el_battle_menu_atk_select < 3)
      (*global_structure)->menu->el_battle_menu_atk_select++;
      else
      (*global_structure)->menu->el_battle_menu_atk_select =0;

      //Selectionneur pour le menu pokemon
      if ((*global_structure)->menu->el_menu_pokemon_select < 5)
      (*global_structure)->menu->el_menu_pokemon_select++;
      else
      (*global_structure)->menu->el_menu_pokemon_select = 0;
      //Selectionneur pour le menu de sauvegarde
      if ((*global_structure)->menu->el_menu_save_select < 1)
      (*global_structure)->menu->el_menu_save_select++;
      else
      (*global_structure)->menu->el_menu_save_select =0;

      //Selectionneur pour l'écran principal
      if ((*global_structure)->menu->el_menu_main_screen_select < 1)
      (*global_structure)->menu->el_menu_main_screen_select++;
      else
      (*global_structure)->menu->el_menu_main_screen_select =0;


      break;

      case SDLK_RIGHT:
      (*global_structure)->keys.right_arrow = 1;
      break;

      case SDLK_u:;
      int * arguments = check_tile_agurments(global_structure);
      free(arguments);

      for (size_t i = 0; i < 5; i++) {
        printf("Interaction[%i] : %i\n",i,arguments[i]);
      }

      break;

      /*
             case SDLK_SPACE:
      if (2)
      {
        int posX = (*global_structure)->player->posX;

        int posY = (*global_structure)->player->posY;
        posY -= 5;

        char ** * matrice = get_String_Matrice(&(*global_structure), 1, posX, posY);
        char * matrix_cell_id;
        if ((*global_structure)->keys.z_key == 1)
        matrix_cell_id = matrice[0][1];

        if ((*global_structure)->keys.s_key == 1)
        matrix_cell_id = matrice[2][1];

        if ((*global_structure)->keys.q_key == 1)
        matrix_cell_id = matrice[1][0];

        if ((*global_structure)->keys.d_key == 1)
        matrix_cell_id = matrice[1][2];

        char command[100];
        sprintf(command, "node C:\\Users\\Elias\\Desktop\\JEU_POKEMON\\codes_complementaires\\nodejs\\index.js %s 0 1", matrix_cell_id);
        system(command);

        printf("-------------\n");
        for (size_t i = 0; i < 3; i++) {
          for (size_t j = 0; j < 3; j++) {
            printf("%i;%i->%s\t", i, j, matrice[i][j]);
          }
          printf("\n");
        }
        printf("-------------\n");
        detruire_string_matrice(matrice, 3);
      }
      break;
      */

      default:
      //return -1;
      break;
    }


    if ((*global_structure)->player->movement_id < 8)
    (*global_structure)->player->movement_id++;
    else
    (*global_structure)->player->movement_id = 1;


  }
  else if ((*global_structure)->event.type == SDL_KEYUP)
  {
    switch ((*global_structure)->event.key.keysym.sym)
    {

      case SDLK_z:

      (*global_structure)->keys.z_key = 0;
      (*global_structure)->keys.lastkey = 'z';

      break;

      case SDLK_q:
      (*global_structure)->keys.q_key = 0;
      (*global_structure)->keys.lastkey = 'q';

      break;

      case SDLK_s:
      (*global_structure)->keys.s_key = 0;
      (*global_structure)->keys.lastkey = 's';

      break;

      case SDLK_d:
      (*global_structure)->keys.d_key = 0;
      (*global_structure)->keys.lastkey = 'd';

      break;

      case SDLK_UP:
      (*global_structure)->keys.up_arrow = 0;
      break;

      case SDLK_LEFT:
      (*global_structure)->keys.left_arrow = 0;
      break;

      case SDLK_DOWN:
      (*global_structure)->keys.down_arrow = 0;
      break;

      case SDLK_RIGHT:
      (*global_structure)->keys.right_arrow = 0;
      break;

      default:
      //return -1;
      break;
    }
  }
  else if ((*global_structure)->event.type == SDL_QUIT)
  {
    (*global_structure)->quit = 1;
  }

}

}
