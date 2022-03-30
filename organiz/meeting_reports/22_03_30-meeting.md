# Débrief du rendez-vous du 30/03/2022

- L'archive ne doit pas contenir de fichiers qui peuvent être générés par d'autres fichiers. Elle ne doit donc pas contenir le fichier .pdf qui sera généré à partir du fichier .tex.

- Lorsque l'on créé une branche afin de développer une partie du projet, il faut faire attention à ne pas la laisser séparée trop longtemps et donc régulièrement récupérer les avancées de la branche principale.

- Il est important de réaliser des tests pour la gestion des mouvements pour éviter des erreurs importantes.

- Si des éléments sont facilement corrigeables sur la branche master, il est préférable d'effectuer les corrections directmeent dessus plutôt que de le faire sur une branche et merge plus tard.

- Dans le cas de la fonction Bitboard* pieces[2], il est inutile de converser l'étoile. Cela peut provoquer des fuites mémoires avec les fonctions reset_to_classic() et reset_to_empty().

- Les algorithmes minmax, etc... doivent directement hériter de ai_player.

- Il n'y a pas besoin que tout fonctionne pour effectuer une bonne structuration du code.

- Dans le cas des dossiers src et include : les chemins menant aux fichiers .cpp de src et aux fichiers .h de include doivent être identiques.

- Le readme contient trop d'éléments autogénérés et qui n'ont pas de rapport avec le projet de pdp.

- Il ne faut jamais prendre du code sur internet sans citer la source et ce, même si on le modifie.
