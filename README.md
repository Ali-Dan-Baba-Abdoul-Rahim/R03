# Student Manager

**Projet Semaine 3 — Structures + Fichiers en C**

## Description
Ce programme en langage C permet de gérer une base de données simple d'étudiants. Il propose des fonctionnalités interactives via un menu pour saisir, afficher, trier, filtrer, rechercher, sauvegarder et charger des étudiants.

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
Utilisez un compilateur C

## Remarques
1.Le programme supporte jusqu'à 100 étudiants maximum.
2.Les noms et prénoms ne doivent pas contenir d'espaces (utilisez un mot par champ).
3.Les données sauvegardées dans le fichier texte sont réutilisables même après fermeture du programme.
