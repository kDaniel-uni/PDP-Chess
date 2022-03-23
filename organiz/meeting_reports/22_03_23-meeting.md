# Débrief du rendez-vous du 23/03/2022

-Il faut bien choisir sa convention de codage car ne pas en avoir une serait un problème.

-Il ne faut pas mettre les fichiers .h dans le dossier /include.

-Il ne faut pas utiliser de FactoryDirector, ni de Factory pour les différents algorithmes. Se contenter d'une AI Factory qui utilise directement les algorithmes.

-Le Json cpp est le plus pertinent à utiliser.

-Il faut éviter le Json third party, il est préférable de demander à l'utilisateur d'effectuer des apt install pour utiliser les librairies.

- Il est nécessaire de remplacer les "#endif Pdp..." par des "endif //Pdp..." car autrement, le logiciel considère la partie "Pdp..." comme du code à exécuter. De plus "#pragma once" n'est pas supporté par tous les compilateurs.

- Il faut bien faire la différence entre les include "" et les include <>. Ceux utilisant les guillemets commencent à partir du répertoire courant alors que ceux utilisant les chevrons utilisent une bibliothèque externe.

- Mettre const après une fonction permet de lui dire qu'elle ne doit pas modifier l'objet. (Exemple : int64 getPawns() const;)

- Remplacer les valeurs des différentes pièces par souci de lisibilité. (Exemple : 36 devient (1<<2) + (1<<5)).