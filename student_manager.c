#include <stdio.h>              // Bibliothèque standard pour les entrées/sorties (printf, scanf)
#include <stdlib.h>             // Bibliothèque standard pour exit() et fonctions diverses
#include <string.h>             // Bibliothèque pour manipuler les chaînes de caractères

#define TAILLE_NOM 50           // Taille maximale pour les noms et prénoms
#define MAX_ETUDIANTS 100       // Nombre maximum d'étudiants dans le tableau

// ============================
// 1. MODÉLISATION ET SAISIE
// ============================

typedef struct {                // Déclaration d'une structure pour représenter un étudiant
    int id;                     // Identifiant unique
    char nom[TAILLE_NOM];       // Nom de l'étudiant
    char prenom[TAILLE_NOM];    // Prénom de l'étudiant
    float note;                 // Note de l'étudiant
} Etudiant;

Etudiant liste[MAX_ETUDIANTS];  // Tableau contenant tous les étudiants
int nb_etudiants = 0;           // Nombre d'étudiants actuellement saisis

void saisirEtudiant(Etudiant *e) {           // Fonction de saisie d’un étudiant (par pointeur)
    printf("Saisir l'ID : ");                // Invite pour l'identifiant
    scanf("%d", &e->id);                     // Lecture de l'identifiant

    printf("Saisir le nom : ");              // Invite pour le nom
    scanf("%s", e->nom);                     // Lecture du nom (chaîne)

    printf("Saisir le prénom : ");           // Invite pour le prénom
    scanf("%s", e->prenom);                  // Lecture du prénom (chaîne)

    printf("Saisir la note : ");             // Invite pour la note
    scanf("%f", &e->note);                   // Lecture de la note (nombre flottant)
}

void saisie() {                              // Fonction d’ajout d’un étudiant à la liste
    if (nb_etudiants >= MAX_ETUDIANTS) {     // Vérifie si on a atteint la limite
        printf("Nombre maximal d'étudiants atteint.\n"); // Affiche un message d'erreur
        return;                              // Sort de la fonction
    }

    printf("\n--- Saisie d'un étudiant ---\n");          // Message de début
    saisirEtudiant(&liste[nb_etudiants]);    // Appel de la fonction pour remplir un étudiant
    nb_etudiants++;                          // Incrémente le nombre total d’étudiants
}

// ============================
// 2. AFFICHAGE ET FILTRAGE
// ============================

void afficher_etudiants() {                  // Fonction pour afficher tous les étudiants
    if (nb_etudiants == 0) {                 // Vérifie s’il y a des étudiants
        printf("Aucun étudiant à afficher.\n");  // Message si vide
        return;                              // Fin de fonction
    }

    printf("\n--- Liste des étudiants ---\n");   // Titre de la liste
    for (int i = 0; i < nb_etudiants; i++) {     // Parcours de la liste
        printf("%d. ID: %d, %s %s, Note: %.2f\n", // Affiche les données de l'étudiant
               i + 1,
               liste[i].id,
               liste[i].nom,
               liste[i].prenom,
               liste[i].note);
    }
}

void affichage() {                           // Fonction wrapper pour affichage
    afficher_etudiants();                    // Appel de la fonction principale
}

void filtrage() {                            // Fonction pour filtrer selon la note
    if (nb_etudiants == 0) {                 // Vérifie s’il y a des étudiants
        printf("Aucun étudiant à filtrer.\n");
        return;
    }

    float seuil;                             // Seuil de note à filtrer
    printf("Afficher les étudiants avec une note >= à : ");
    scanf("%f", &seuil);                     // Lecture du seuil

    printf("\n--- Étudiants avec note >= %.2f ---\n", seuil); // Titre
    int trouve = 0;                          // Variable pour détecter s’il y a des résultats

    for (int i = 0; i < nb_etudiants; i++) { // Parcours de tous les étudiants
        if (liste[i].note >= seuil) {       // Si la note est supérieure ou égale
            printf("%d. ID: %d, %s %s, Note: %.2f\n",
                   i + 1,
                   liste[i].id,
                   liste[i].nom,
                   liste[i].prenom,
                   liste[i].note);
            trouve = 1;                      // On a trouvé au moins un résultat
        }
    }

    if (!trouve) {                           // Aucun étudiant filtré
        printf("Aucun étudiant trouvé.\n");
    }
}

// ============================
// 3. TRI ET RECHERCHE
// ============================

void tri() {                                 // Fonction de tri décroissant des notes
    for (int i = 0; i < nb_etudiants - 1; i++) {
        for (int j = i + 1; j < nb_etudiants; j++) {
            if (liste[i].note < liste[j].note) { // Si l’ordre est incorrect
                Etudiant temp = liste[i];        // Échange
                liste[i] = liste[j];
                liste[j] = temp;
            }
        }
    }

    printf("Tri effectué par ordre décroissant des notes.\n");
}

void recherche() {                           // Recherche d’un étudiant par nom
    if (nb_etudiants == 0) {
        printf("Aucun étudiant enregistré.\n");
        return;
    }

    char nom_cherche[TAILLE_NOM];            // Nom à chercher
    printf("Saisir le nom de l'étudiant à rechercher : ");
    scanf("%s", nom_cherche);                // Lecture du nom

    int trouve = 0;                          // Booléen indicateur de succès
    for (int i = 0; i < nb_etudiants; i++) {
        if (strcmp(liste[i].nom, nom_cherche) == 0) { // Comparaison
            printf("Étudiant trouvé : ID: %d, %s %s, Note: %.2f\n",
                   liste[i].id,
                   liste[i].nom,
                   liste[i].prenom,
                   liste[i].note);
            trouve = 1;                      // Étudiant trouvé
        }
    }

    if (!trouve) {                           // Aucun étudiant correspondant
        printf("Aucun étudiant trouvé avec ce nom.\n");
    }
}

// ============================
// 4. SAUVEGARDE ET CHARGEMENT
// ============================

void sauvegarde() {                          // Enregistrement des étudiants dans un fichier
    FILE *f = fopen("etudiants.txt", "w");   // Ouverture en écriture
    if (!f) {                                // Vérification de l'ouverture
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nb_etudiants; i++) { // Parcours des étudiants
        fprintf(f, "%d %s %s %.2f\n",        // Écriture dans le fichier
                liste[i].id,
                liste[i].nom,
                liste[i].prenom,
                liste[i].note);
    }

    fclose(f);                               // Fermeture du fichier
    printf("Données sauvegardées avec succès.\n");
}

void chargement() {                          // Chargement des étudiants depuis un fichier
    FILE *f = fopen("etudiants.txt", "r");   // Ouverture en lecture
    if (!f) {                                // Fichier introuvable
        printf("Erreur : fichier non trouvé.\n");
        return;
    }

    nb_etudiants = 0;                        // Réinitialisation du compteur
    while (fscanf(f, "%d %s %s %f",          // Lecture ligne par ligne
                  &liste[nb_etudiants].id,
                  liste[nb_etudiants].nom,
                  liste[nb_etudiants].prenom,
                  &liste[nb_etudiants].note) == 4) {
        nb_etudiants++;                      // Incrémentation
        if (nb_etudiants >= MAX_ETUDIANTS) break; // Limite atteinte
    }

    fclose(f);                               // Fermeture du fichier
    printf("Chargement des données terminé.\n");
}

// ============================
// 5. MENU ET INTÉGRATION
// ============================

int main() {                                 // Fonction principale
    int choix;                               // Choix de l’utilisateur

    do {
        // Affichage du menu
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Saisie d’un étudiant\n");
        printf("2. Affichage des données\n");
        printf("3. Filtrage par note\n");
        printf("4. Tri des étudiants\n");
        printf("5. Recherche par nom\n");
        printf("6. Sauvegarde\n");
        printf("7. Chargement\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);                 // Lecture du choix

        // Exécution selon le choix
        switch(choix) {
            case 1: saisie(); break;
            case 2: affichage(); break;
            case 3: filtrage(); break;
            case 4: tri(); break;
            case 5: recherche(); break;
            case 6: sauvegarde(); break;
            case 7: chargement(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n");
        }

    } while (choix != 0);                    // Boucle jusqu’à choix = 0 (quitter)

    return 0;                                // Fin normale du programme
}
