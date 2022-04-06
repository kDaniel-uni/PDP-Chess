# Débrief du rendez-vous du 06/04/202

- Faire des branchements entre les différentes parties du code (architecture). Il faut avoir quelque chose qui permette de lancer le code rapidement.

- Il est actuellement impossible avec l'architecture actuelle de faire jouer un joueur humain.

- Mettre des accesseurs get_white_player ou get_black_player.

- CHanger la valeur d'un pointeur peut facilement casser le projet.

- Dans les tests, il faut vérifier que l'accès est supérieur ou égal à deux.

- Lancer les tests indépendamment sans argument peut provoquer des erreurs de runtime.

- Il ne faut pas laisser des fonctions commentées. Il est nécessaire de les faire fonctionner ou alors de les supprimer du code.

- En ce qui concerne les heuristiques, il est possible :
    -D'avoir une seule heuristique avec des paramètres booléens activés ou non en fonction des règles que l'on applique.
    -D'avoir de multiples classes pour gérer chaque paramètre.
    -Mettre en place un composite.

- Il est préférable pour l'heuristique d'utiliser des valeur int plutôt que float afin d'améliorer les performances. Multiplier les valeurs (ex : par 2 ou par 10) afin d'éviter de se retrouver avec des valeurs décimales.

- Pour la soutenance : il faut présenter une vue d'ensemble, savoir être clair. ON peut prendre des points où l'on souhaite apporter davantage de précision.

- Mettre des commentaires sur les parties du code les moins évidentes à comprendre.

- Coding style : faire attention à la largeur maximale des lignes.
