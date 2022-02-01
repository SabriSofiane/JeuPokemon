#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <stdlib.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void SDL_ExitWithError(const char *message)
{
  SDL_Log("Erreur: %s -> %s\n",message,SDL_GetError());
  SDL_Quit();
  exit(EXIT_FAILURE);
}

void clean_resources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t){
  if (t!=NULL)
  {
    SDL_DestroyTexture(t);
  }
  if (r!=NULL)
  {
    SDL_DestroyRenderer(r);
  }
  if (w!=NULL)
  {
    SDL_DestroyWindow(w);
  }

}

void SDL_DestroyRenderAndWindow(SDL_Renderer *renderer,SDL_Window *window){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

int main(int argc, char **argv) {
  /*SDL_version nb;
  SDL_VERSION(&nb);

  printf("SDL %d.%d.%d\n",nb.major,nb.minor,nb.patch);*/
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Surface *image = NULL;
  SDL_Texture *texture = NULL;
  TTF_Font *police = NULL;
  SDL_Surface *texte=NULL;
  SDL_Surface *texteOpt1=NULL;
  SDL_Surface *texteOpt2=NULL;
  SDL_Surface *texteOpt3=NULL;
  SDL_Surface *texteOpt4=NULL;
  SDL_Color couleurNoire = {0, 0, 0};
  SDL_bool program_launched = SDL_TRUE;
  SDL_Rect txtDestRect;
  SDL_Rect txt1DestRect;
  SDL_Rect txt2DestRect;
  SDL_Rect txt3DestRect;
  SDL_Rect txt4DestRect;
  SDL_Rect rectChoix;
  int continuer = 3;
  int choix = 0;
  //Lancement SDL
  if(SDL_Init(SDL_INIT_VIDEO)!=0){
    SDL_ExitWithError("Initialisation SDL");
  }
  //Initialisation de TTF
  if(TTF_Init() != 0) {
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
  //Création fenêtre + rendu
  if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,0,&window,&renderer)!=0){
    SDL_ExitWithError("Impossible de creer la fenetre et rendu");
  }
  if((police = TTF_OpenFont("Pokemon_GB.ttf", 24)) == NULL){
    printf("erreur chargement font\n");
    exit(EXIT_FAILURE);
  }

  /*----------------Codage----------------------*/
  //  SDL_RenderPresent(renderer);

  //TexteMenu
  texte = TTF_RenderUTF8_Blended(police, "Menu", couleurNoire);

  if(!texte){
    printf("Erreur à la création du texte : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  //texteOpt1
  texteOpt1 = TTF_RenderUTF8_Blended(police, "Inventory", couleurNoire);
  if(!texteOpt1){
    printf("Erreur à la création du texte : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  //texteOpt2
  texteOpt2 = TTF_RenderUTF8_Blended(police, "Pokedex", couleurNoire);
  if(!texteOpt2){
    printf("Erreur à la création du texte : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  //texteOpt3
  texteOpt3 = TTF_RenderUTF8_Blended(police, "Options", couleurNoire);
  if(!texteOpt3){
    printf("Erreur à la création du texte : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  //texteOpt4
  texteOpt4 = TTF_RenderUTF8_Blended(police, "Exit", couleurNoire);
  if(!texteOpt4){
    printf("Erreur à la création du texte : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_Texture *texteTextureMenu = SDL_CreateTextureFromSurface(renderer, texte);
  SDL_Texture *texteTextureOpt1 = SDL_CreateTextureFromSurface(renderer, texteOpt1);

  SDL_Texture *texteTextureOpt2 = SDL_CreateTextureFromSurface(renderer, texteOpt2);

  SDL_Texture *texteTextureOpt3 = SDL_CreateTextureFromSurface(renderer, texteOpt3);
  SDL_Texture *texteTextureOpt4 = SDL_CreateTextureFromSurface(renderer, texteOpt4);
  if(!texteTextureMenu){
    printf("Erreur a la creation du rendu du texteMenu : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if(!texteTextureOpt1){
    printf("Erreur a la creation du rendu du texteOpt1 : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if(!texteTextureOpt2){
    printf("Erreur a la creation du rendu du texteOpt2 : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  if(!texteTextureOpt3){
    printf("Erreur a la creation du rendu du texteOpt3 : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if(!texteTextureOpt4){
    printf("Erreur a la creation du rendu du texteOpt4 : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_FreeSurface(texte);

  SDL_FreeSurface(texteOpt1);

  SDL_FreeSurface(texteOpt2);

  SDL_FreeSurface(texteOpt3);
  SDL_FreeSurface(texteOpt4);
  txtDestRect.x = txtDestRect.y = 75;

  if(SDL_QueryTexture(texteTextureMenu, NULL, NULL, &txtDestRect.w, &txtDestRect.h) != 0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible de charger la texture en memoire");
  }
  txt1DestRect.x = 500;
  txt1DestRect.y = 100;
  if(SDL_QueryTexture(texteTextureOpt1, NULL, NULL, &txt1DestRect.w, &txt1DestRect.h) != 0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible de charger la texture en memoire");
  }
  txt2DestRect.x = 500;
  txt2DestRect.y = 200;
  if(SDL_QueryTexture(texteTextureOpt2, NULL, NULL, &txt2DestRect.w, &txt2DestRect.h) != 0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible de charger la texture en memoire");
  }

  txt3DestRect.x = 500;
  txt3DestRect.y = 300;
  if(SDL_QueryTexture(texteTextureOpt3, NULL, NULL, &txt3DestRect.w, &txt3DestRect.h) != 0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible de charger la texture en memoire");
  }
  txt4DestRect.x = 500;
  txt4DestRect.y = 400;
  if(SDL_QueryTexture(texteTextureOpt4, NULL, NULL, &txt4DestRect.w, &txt4DestRect.h) != 0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible de charger la texture en memoire");
  }


  image = SDL_LoadBMP("white.bmp");
  if(image==NULL){
    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    clean_resources(window,renderer,NULL);
    SDL_ExitWithError("Impossible de charger l'image");
  }

  texture=SDL_CreateTextureFromSurface(renderer,image);
  SDL_FreeSurface(image);

  if(texture==NULL){
    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    clean_resources(window,renderer,NULL);
    SDL_ExitWithError("Impossible de creer la texture");
  }
  SDL_Rect rectangle;

  if(SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,&rectangle.h) != 0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible de charger la texture en memoire");
  }

  rectangle.x=(WINDOW_WIDTH - rectangle.w) / 2;
  rectangle.y=(WINDOW_HEIGHT - rectangle.h) / 2;
  if(SDL_RenderCopy(renderer,texture,NULL,&rectangle)!=0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible d'afficher la texture");
  }
  rectChoix.x = 500;
  rectChoix.y = 100;
  rectChoix.w = 250;
  rectChoix.h = 50;
  if(SDL_RenderDrawRect(renderer,&rectChoix)!=0)
  {
    clean_resources(window,renderer,texture);
    SDL_ExitWithError("Impossible d'afficher le rectangle rectChoix");
  }

  while(program_launched)
  {
    SDL_Event event;

    //Boucle de gestion d'événements
    while (SDL_PollEvent(&event)) {
      //Type de l'événement traité
      switch (event.type) {
        //Cas appui d'un bouton
        case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
          program_launched = SDL_FALSE;
          break;
          case SDLK_UP:
          printf("Up\n");

          if(choix !=0){
            choix--;
            rectChoix.y-=100;
            if(SDL_RenderDrawRect(renderer,&rectChoix)!=0)
            {
              clean_resources(window,renderer,texture);
              SDL_ExitWithError("Impossible d'afficher le rectangle rectChoix");
            }
          }
          else
          {
            choix = 3;
            rectChoix.y=400;
          }
          printf("Choix = %d\n",choix);
          continue;
          case SDLK_DOWN:
          printf("Down\n");

          if(choix !=3){

            choix++;
            rectChoix.y+=100;
            if(SDL_RenderDrawRect(renderer,&rectChoix)!=0)
            {
              clean_resources(window,renderer,texture);
              SDL_ExitWithError("Impossible d'afficher le rectangle rectChoix");
            }
          }
          else
          {
            choix = 0;
            rectChoix.y=100;
          }
          printf("Choix = %d\n",choix);
          continue;
          default:
          continue;

        }
        //cas si l'on clique sur la croix en haut à droite
        case SDL_QUIT:
        program_launched = SDL_FALSE;
        break;
        default:
        break;
      }
    }
    //affichage
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    if(SDL_RenderCopy(renderer, texteTextureMenu, NULL, &txtDestRect)!=0)
    {
      clean_resources(window,renderer,texture);
      SDL_ExitWithError("Impossible d'afficher la texture du texture");
    }

    if(SDL_RenderCopy(renderer, texteTextureOpt1, NULL, &txt1DestRect)!=0)
    {
      clean_resources(window,renderer,texture);
      SDL_ExitWithError("Impossible d'afficher la texture du texture");
    }

    if(SDL_RenderCopy(renderer, texteTextureOpt2, NULL, &txt2DestRect)!=0)
    {
      clean_resources(window,renderer,texture);
      SDL_ExitWithError("Impossible d'afficher la texture du texture");
    }

    if(SDL_RenderCopy(renderer, texteTextureOpt3, NULL, &txt3DestRect)!=0)
    {
      clean_resources(window,renderer,texture);
      SDL_ExitWithError("Impossible d'afficher la texture du texture");
    }
    if(SDL_RenderCopy(renderer, texteTextureOpt4, NULL, &txt4DestRect)!=0)
    {
      clean_resources(window,renderer,texture);
      SDL_ExitWithError("Impossible d'afficher la texture du texture");
    }
  }

  /*--------------------------------------------*/


  //destruction du rendu , fenetre et texture
//  SDL_DestroyTexture(texture);
  TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
	TTF_Quit();
  clean_resources(window,renderer,texture);
  SDL_Quit();
  //SDL_DestroyRenderer(renderer);
  //SDL_DestroyWindow(window);
  //SDL_Quit();

  return EXIT_SUCCESS;
}
//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
// bin/prog.exe
