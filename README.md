# Projet Jeu Pokemon

Le jeu serait un jeu Pokémon classique, les graphismes seraient ceux utilisés dans les versions ds (donc en 2d vu du dessus). 
Certains éléments comme la carte, les objets les pnj ne seraient pas ceux des jeux originaux. 
De nouveaux éléments de gameplay seront ajoutés pour rendre le jeu plus difficile et plus prenant que les jeux originaux.

Pour le moment chacun des trois membres du groupe dispose de sa propre branche dans ce dépo, chaque branche à sa propre structure.
À termes l'ensemble des fonctions développé par chacun d'entre nous serons regroupés dans une seul branche.

Contrôles pour l’overworld :<br/>
• **Z** - Avancer<br/>
• **S** - Reculer<br/>
• **D** - Aller à droite<br/>
• **Q** - Aller à gauche<br/>


Contrôles pour les menus :<br/>
• **M** - Ouvrir le menu principal<br/>
• **Échap** - Fermer le menu actuellement ouvert<br/>
• **Entrer** - Confirmer la sélection d’un menu<br/>
• **↑** - Sélectionner le menu plus haut<br/>
• **↓** - Sélectionner le menu plus bas<br/>

---

Modifications effectués après la date limite


suppresion des éléments suivant :

admin.h

creations des éléments suivant :

Dossier objets (nécéssaire à la compilation)

---
Si vous avez l'erreur suivante sous windows: 
![alt text](https://cdn.discordapp.com/attachments/885897962591510579/961254122038915082/unknown.png)

Vérifier de bien recompiler le makefile, ci la recompilation échoue et que les messages d'érreurs spécifie que vous arrivez pas à trouver les librairies SDL2 SDL2Image SDL2TTF et SDL2Mixer, veuiller re-télécharger les librairies indiqués sous MinGW32/64 (exemple sur le site de la SDL2 : SDL2-devel-2.0.20-mingw.tar.gz (MinGW 32/64-bit)) et de reprendre les fichier contenus dans le dossier x86_64-w64-mingw32 puis recompiler.
