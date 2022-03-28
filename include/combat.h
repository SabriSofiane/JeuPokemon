int init_combat(motor_t ** motor);

void print_list(Liste_t * player);

int Length(Liste_t *p);

void push(Liste_t **p, t_pkm pkm); //push debut

void insertAtEnd(Liste_t *head, t_pkm pkm);

void Pop(Liste_t **p, t_pkm pkm);

void affiche_Stats(Liste_t *player, t_pkm *wild_pkm);

t_pkm GetNth(Liste_t* head, int index);

void swapNodes(motor_t ** motor, int n1, int n2);

Liste_t * current_pkm(Liste_t *player, int index);

void init_pkm_team(t_pkm *pkm, char nom_pkm[20]);

void rand_scale_stat(t_pkm *wild_pkm);

void init_pkm_enemy(t_pkm *pkm);

void player_attack(Liste_t*player, t_pkm *wild_pkm,int choix);
void getAttackJoueur(Liste_t*player, t_pkm *wild_pkm,int choix);

void enemy_attack(Liste_t *player, t_pkm *wild_pkm);

int verif_fin_combat(Liste_t *player);


int combat(Liste_t *player, t_pkm *wild_pkm, int choix);
