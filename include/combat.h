int init_combat(global_structure_t ** global_structure,int pkm_enemy_ids[5]);

void print_list(Liste_t * player);

int getPlayerPkmId(Liste_t * player, int id);

int Length(Liste_t *p);

void inserDebut(Liste_t **p, t_pkm pkm); //push debut

void inserFin(Liste_t *courant, t_pkm pkm);

void Pop(Liste_t **p, t_pkm pkm);

void affiche_Stats(Liste_t *player, t_pkm *wild_pkm);

t_pkm GetNth(Liste_t* head, int index);

int swapNodes(global_structure_t ** global_structure, int n1, int n2);

Liste_t * current_pkm(Liste_t *player, int index);

void init_pkm_team(t_pkm *pkm, char nom_pkm[20]);

void rand_scale_stat(t_pkm *wild_pkm);

void init_pkm_enemy(t_pkm *pkm,int numFichier);

float chercherMultiplicateur(int typePokemon1, int typeAttaque);
float verifType(char typePokemon1[50], char typePokemon2[50], char typeAttaque[50]);

void getAttackJoueur(Liste_t*player, t_pkm *wild_pkm,int choix);

void getAttackEnnemi(Liste_t *pl, t_pkm *wild_pkm);

int verif_pkmEnVie(Liste_t *pl);

int combat(Liste_t *player, t_pkm *wild_pkm, int choix);

void initDresseur(Liste_t *liste, char nomDress[50]);

void getAttackJoueurDuel(Liste_t*pl, Liste_t *ennemi,int choix);

void getAttackEnnemiDuel(Liste_t *pl, Liste_t *ennemi);

int combatDresseur(Liste_t *pl, Liste_t *ennemi, int choix);

int capturer(global_structure_t ** global_structure, Liste_t *player, t_pkm wild_pkm);

int soin(Liste_t *player);
