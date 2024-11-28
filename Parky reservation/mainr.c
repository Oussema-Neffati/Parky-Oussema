#include <stdio.h>
#include <string.h>
#include "reservation.h"

int main() {
    reservation res1 = {1, 101, 10112024, 800, 1700};
    reservation res2 = {2, 102, 11112024, 900, 1800};

   int x;

    x = ajouter("reservation.txt", res1);
    if (x == 1) {
        printf("\nAjout de la réservation avec succès");
	}
    else
        printf("\nÉchec de l'ajout");


    x = ajouter("reservation.txt", res2);
    if (x == 1)
        printf("\nAjout de la deuxième réservation avec succès");
    else
        printf("\nÉchec de l'ajout");


    reservation resModifie = {1, 101, 10112024, 1000, 1900};
    x = modifier("reservation.txt", 1, resModifie);
    if (x == 1)
        printf("\nModification de la réservation avec succès");
    else
        printf("\nÉchec de la modification");


    x = supprimer("reservation.txt", 2);
    if (x == 1)
        printf("\nSuppression de la réservation avec succès");
    else
        printf("\nÉchec de la suppression");

    chercher("reservation.txt", 1);
	if (res1.ID_reservation == -1)
	printf("Introuvable.txt");


    printf("\nToutes les réservations :\n");
    afficher("reservation.txt", 1 );


    printf("\nliste des parking tries\n");
    afficher_parkings_tries("parkings.txt");

	return 0;
}
