#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100  // Nombre maximum d'étudiants que l'on peut gérer

// Définition de la structure Etudiant
typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    float moyenne;
} Etudiant;

// Déclaration du tableau principal et du compteur
Etudiant liste[MAX_ETUDIANTS];
int nbEtudiants = 0;

// Fonction pour ajouter un étudiant
void ajouterEtudiant() {
    if (nbEtudiants >= MAX_ETUDIANTS) {
        printf("Limite atteinte.\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &liste[nbEtudiants].id);

    printf("Nom: ");
    scanf("%s", liste[nbEtudiants].nom);

    printf("Prénom: ");
    scanf("%s", liste[nbEtudiants].prenom);

    printf("Moyenne: ");
    scanf("%f", &liste[nbEtudiants].moyenne);

    nbEtudiants++;  // Incrémentation du nombre d'étudiants
}

// Fonction pour afficher tous les étudiants
void afficherEtudiants() {
    if (nbEtudiants == 0) {
        printf("Aucun étudiant enregistré.\n");
        return;
    }

    printf("\nListe des étudiants :\n");
    for (int i = 0; i < nbEtudiants; i++) {
        printf("%d - %s %s - %.2f\n", 
               liste[i].id, liste[i].nom, 
               liste[i].prenom, liste[i].moyenne);
    }
}

// Fonction pour trier les étudiants par moyenne (ordre décroissant)
void trierEtudiantsParMoyenne() {
    for (int i = 0; i < nbEtudiants - 1; i++) {
        for (int j = i + 1; j < nbEtudiants; j++) {
            if (liste[i].moyenne < liste[j].moyenne) {
                // Échange des structures
                Etudiant temp = liste[i];
                liste[i] = liste[j];
                liste[j] = temp;
            }
        }
    }
    printf("Tri effectué.\n");
}

// Fonction pour sauvegarder la liste des étudiants dans un fichier texte
void sauvegarderDansFichier(const char* nomFichier) {
    FILE* f = fopen(nomFichier, "w");  // Ouvre en écriture
    if (!f) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nbEtudiants; i++) {
        // Écrit les informations de chaque étudiant dans le fichier
        fprintf(f, "%d %s %s %.2f\n", 
                liste[i].id, liste[i].nom, 
                liste[i].prenom, liste[i].moyenne);
    }
    fclose(f);  // Ferme le fichier
    printf("Sauvegarde réussie dans %s.\n", nomFichier);
}

// Fonction pour charger les étudiants depuis un fichier texte
void chargerDepuisFichier(const char* nomFichier) {
    FILE* f = fopen(nomFichier, "r");  // Ouvre en lecture
    if (!f) {
        printf("Fichier introuvable.\n");
        return;
    }

    nbEtudiants = 0;  // Réinitialise la liste actuelle
    while (fscanf(f, "%d %s %s %f", 
           &liste[nbEtudiants].id, 
           liste[nbEtudiants].nom, 
           liste[nbEtudiants].prenom, 
           &liste[nbEtudiants].moyenne) != EOF) {
        nbEtudiants++;  // Incrémente pour chaque étudiant lu
    }
    fclose(f);
    printf("Chargement effectué depuis %s.\n", nomFichier);
}

// Fonction de recherche par nom
void rechercherEtudiantParNom() {
    char recherche[50];
    printf("Nom à rechercher : ");
    scanf("%s", recherche);

    int trouvés = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        if (strcmp(liste[i].nom, recherche) == 0) {
            printf("%d - %s %s - %.2f\n", 
                   liste[i].id, liste[i].nom, 
                   liste[i].prenom, liste[i].moyenne);
            trouvés++;
        }
    }

    if (trouvés == 0) {
        printf("Aucun étudiant trouvé.\n");
    }
}

// Fonction principale avec menu
int main() {
    int choix;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher les étudiants\n");
        printf("3. Trier par moyenne\n");
        printf("4. Sauvegarder dans un fichier\n");
        printf("5. Charger depuis un fichier\n");
        printf("6. Rechercher par nom\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar(); // consomme le \n laissé par scanf

        // Appelle la fonction correspondant au choix
        switch(choix) {
            case 1: ajouterEtudiant(); break;
            case 2: afficherEtudiants(); break;
            case 3: trierEtudiantsParMoyenne(); break;
            case 4: sauvegarderDansFichier("etudiants.txt"); break;
            case 5: chargerDepuisFichier("etudiants.txt"); break;
            case 6: rechercherEtudiantParNom(); break;
            case 0: printf("Au revoir.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);  // Le menu continue tant que l'utilisateur ne choisit pas 0

    return 0;
}
