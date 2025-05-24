# Student Manager

**Projet Semaine 3 — Structures + Fichiers en C**

## Description

Ce projet est une application en ligne de commande permettant de gérer une liste d'étudiants. Il utilise des **structures**, **tableaux**, et la **gestion de fichiers texte** pour stocker les données de manière persistante.

---

## Fonctionnalités

- Ajouter un étudiant (ID, nom, prénom, moyenne)
- Afficher tous les étudiants
- Trier les étudiants par moyenne (ordre décroissant)
- Sauvegarder les étudiants dans un fichier texte (`etudiants.txt`)
- Charger des étudiants depuis un fichier
- Rechercher un étudiant par son nom

---

## Objectifs pédagogiques

- Manipuler des **structures** en langage C
- Utiliser des **tableaux de structures**
- Lire et écrire des **fichiers texte**
- Implémenter un menu interactif en **ligne de commande**
- Appliquer des **algorithmes de tri** et de recherche

---

## Compilation et exécution

### Prérequis

- Un compilateur C (comme `gcc`)
- Terminal (Linux, Mac ou Windows avec MinGW)

### Commandes

```bash
gcc student_manager.c -o student_manager
./student_manager
