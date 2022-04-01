void inserFin(Liste_t *head, t_pkm pkm);
int Length(Liste_t *p);
/**
  * \function capturer
  * \brief 1 chance sur 2 de rajouter le pkm ennemi dans equipe
  * \param liste des pkm du joueur et pkm ennemi
**/
int capturer(Liste_t *player, t_pkm wild_pkm)
{
  srand(time(0));
  int proba = rand() % 2;
  if (proba == 0){
    printf("rate\n");
    return 0;
  }
  else if (proba == 1 && Length(player) <  6){
    inserFin(player, wild_pkm);
    return 1;
  }
  else{
    printf("CA MARCHE PAS\n");
  }
}

/**
  * \function soin
  * \brief rend tous les points de vie aux pokemon de l'equipe
  * \param liste des pkm du joueur
**/

int soin(Liste_t *player)
{
  while(player){
    player->pkm.hp = player->pkm.hpMax;
    player = player->next;
  }
  return 1;
}
