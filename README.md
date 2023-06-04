# Projet_Tissus
Projet Informatique Semestre 2
- 1) Nous avons fait tout ce qui est demandé + quelques extentions
- 2) Oui, avec Qt
- 3) 1.5-2h par semaine en total par personne (surtout la partie graphique très longue)

Notre projet vise à simuler une évolution dans l'espace d'un, ou plusieurs, tissus en C++. Les tissus, dans notre programme, sont représentées par des masses, connectées entre elles par des ressorts. Cette représentation est assez réaliste, car des tissus sont une vaste collections (d'environ de 10^23) de molécules et donc d'atomes, connectés entre eux par des liens atomiques, qui se rapprochent de liens élastiques. Nous avons ainsi créé des classes et des fonctions en C++ pour nous aider à représenter et à faire évoluer ce tissu.

Pour utiliser notre programme, il faut d'abord choisir quelle représentation nous voulons avoir de notre tissu. Nous avons créé 2 représentations ; une textuelle, et une visuelle. Pour ces 2 simulations, il faut tout d'abord compiler le fichier .pro dans le dossier "general". Pour cela, il suffit de typer les commandes "qmake", puis "make" en étant dans le dossier "general".
Ensuite, il faut aussi choisir quel tissu nous voulons représenter sur l'écran. Pour cela, nous avons déjà créé quelques "presets" de tissus : un TissuRectangle, un TissuDisque et un TissuChaine.

Pour créer un de ces tissus, il faut typer le code suivant:
- Pour un TissuRectangle:
TissuRectangle* tissu = new TissuRectangle(double masse, Vecteur3D longueur, Vecteur3D largeur, Vecteur3D position0, double coefficient, double densité_linéaire, double raideur, double longueur_a_vide);
- Pour un TissuDisque:
TissuDisque* tissu = new TissuDisque(double masse, Vecteur3D position0, Vecteur3D rayon, double pas_radial, double coefficient, double raideur, double pas_angulaire);
- Pour un TissuChaine:
TissuChaine tissu = new TissuChaine(double masse, double coefficient, double raideur, double longueur_a_vide, tableau_Vecteur3D positions);

Si vous avez créé plusieurs tissus, il faut les mettre un après l'autre dans le système, en utilisant "sys.add_tissu(tissu);"

(Si vous voulez créer un TissuSimple, il faut d'abord créer manuellement toutes les pointeurs de masses du tissu, les mettre dans un tableau, et initier le tissu en ajoutant : "TissuS* tissu = new TissuS(tableau_ptr_masses), puis connecter ces masses en prennant leur index dans le tableau et en ajoutant "connecte(size_t index_masse1, size_t index_masse2, double raideur, double longueur_a_vide);". Quand vous avez fini de connecter les masses, il faut utiliser la commande "connecte_masses();" pour que le tissu fonctionne normalement)


Représentation textuelle : 
    1) Dans le dossier "text", ouvrir le fichier "main_text.cc"
    2) Créez le/les tissus voulus
    3) Choisir où l'on veut représenter le texte de la simulation ; 
    - "TextViewer ecran({fstream})" pour écrire dans un fichier
    - "TextViewer ecran(cout)" pour écrire dans le terminal
    3) Ouvrir le dossier "text" (depuis "general", typer la commande "cd ../text")
    4) Typer les commandes "qmake" puis "make"
    5) Executer le programme; l'executable est nommé "simText", typer la commande "./simText"

Représentation visuelle : 
    1) Dans le dossier "Qt_GL", ouvrir le fichier "main_qt_gl.cc"
    2) Créez le/les tissus voulus
    3) Ouvrir le dossier "Qt_GL" (depuis "general", typer la commande "cd ../qt_gl")
    4) Typer les commandes "qmake" puis "make"
    5) Executer le programme; l'executable est nommé "simVisuel", typer la commande "./simVisuel"
