# Student Manager

**Projet Semaine 3 — Structures + Fichiers en C**

## Description
Ce programme en langage C permet de gérer une base de données simple d'étudiants. Il propose des fonctionnalités interactives via un menu pour saisir, afficher, trier, filtrer, rechercher, sauvegarder et charger des étudiants.

## Fonctionnement du menu
Le menu est un système interactif en boucle qui permet à l'utilisateur de naviguer dans les différentes fonctionnalités du programme. Voilà une présentation lorsque le programme est lancé, le menu principal s'affiche automatiquement :
=== MENU PRINCIPAL ===
1. Saisie d’un étudiant
2. Affichage des données
3. Filtrage par note
4. Tri des étudiants
5. Recherche par nom
6. Sauvegarde
7. Chargement
0. Quitter
Votre choix :

## Fonctionnalités
1. Saisie : Ajouter un nouvel étudiant avec son ID, nom, prénom et note.
2. Affichage : Voir la liste complète des étudiants.
3. Filtrage : Afficher uniquement les étudiants ayant une note supérieure ou égale à un seuil donné.
4. Tri : Classer les étudiants par note (ordre décroissant).
5. Recherche : Trouver un étudiant par son nom.
6. Sauvegarde : Enregistrer la liste dans un fichier etudiants.txt.
7. Chargement : Recharger les étudiants depuis le fichier etudiants.txt.
   
## Structure des Données
Chaque étudiant est représenté par une structure contenant :
int id
char nom[50]
char prenom[50]
float note

## Fichiers
main.c : Code source principal du programme
etudiants.txt : Fichier de sauvegarde/chargement des étudiants

## Compilation
Utilisez un compilateur C ou un compilateur gcc.

## Les tâches du travail associés à chaque membres :
1. Modélisation et  Saisie : Ali_Dan_Baba_AR
2. Affichage et Filtrage : Nana_Fourera_ZY
3. Tri et Recherche : Ridiwane_AG
4. Sauvegarde et Chargement : Ibrahim_B
5. Menu et Intégration : Hassan_I

## Remarques
1.Le programme supporte jusqu'à 100 étudiants maximum.
2.Les noms et prénoms ne doivent pas contenir d'espaces (utilisez un mot par champ).
3.Les données sauvegardées dans le fichier texte sont réutilisables même après fermeture du programme.
