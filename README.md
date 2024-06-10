# lupin-word-sorting-exercise

L’exercice est le suivant. Il s’agit de créer une petite application capable de :

* Recevoir (ou lire) une liste de mots en entrée
* Les trier par ordre croissant ou décroissant, en fonction d’une option donnée en argument
* Si une autre option est spécifiée, l’application supprime alors les valeurs qui apparaissent plusieurs fois
* Enfin, afficher (ou sauvegarder) le résultat trié, avec ou sans suppression des doublons comme demandé

# Arguments de commandes
* --sorting : Trier, par défaut croissant, *--sorting:desc* pour décroissant
* --remove-duplicates: supprimer les doublons
* --input:<input-file> : chemin du fichier d'entrée, input.txt par défaut
* --output:<output-file> : chemin du fichier de sortie, output.txt par défaut