// Mise en oeuvre contigue d'une liste d'entiers
#define TAILLE_MAX 100

// Declaration du tableau contenant les elements de liste
int liste[TAILLE_MAX];
// Declaration des indices de queue et d'element courant
int queue, ec;

void init_liste(void);

int liste_vide(void);

int hors_liste(void);

void en_tete(void);

void en_queue(void);

void precedent(void);

void suivant(void);

void valeur_elt(int* v);

void modif_elt(int v);

void oter_elt(void);

void ajout_droit(int v);

void ajout_gauche(int v);
