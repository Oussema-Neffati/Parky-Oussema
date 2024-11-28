#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED
#include <stdio.h>
typedef struct
{
    int ID_reservation;
    int ID_parking;
    int date_de_reservation;
    int heure_arriver;
    int heure_de_depart ;

} reservation;

typedef struct
{
    int ID_parking;
    char localisation[100];
    int places_disponibles;

} Parking;

int ajouter(char *filename, reservation res );
int modifier( char *filename, int ID_reservation, reservation res );
int supprimer(char *filename, int ID_reservation );
void afficher(char *filename, int ID_reservation );
reservation chercher(char * filename, int ID_reservation);
void afficher_parkings_tries(char *filename);



#endif
