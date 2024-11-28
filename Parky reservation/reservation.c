#include "reservation.h"

int ajouter(char * filename, reservation res )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %d\n",res.ID_reservation, res.ID_parking, res.date_de_reservation, res.heure_arriver, res.heure_de_depart);

        fclose(f);
        return 1;
    }
    else return 0;

}

int modifier(char *filename, int ID_reservation, reservation nouv) {
    int tr = 0;
    reservation res;

    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f == NULL || f2 == NULL) {
        if (f) fclose(f);
        if (f2) fclose(f2);
        return 0;
    }

    while (1) {
        int result = fscanf(f, "%d %d %d %d %d\n",
                            &res.ID_reservation, &res.ID_parking, &res.date_de_reservation,
                            &res.heure_arriver, &res.heure_de_depart);

        if (result == EOF) {
            break;
        }

        if (result != 5) {
            printf("Erreur : Ligne mal formatée dans le fichier.\n");
            continue;
        }

        if (res.ID_reservation == ID_reservation) {
            fprintf(f2, "%d %d %d %d %d\n",
                    nouv.ID_reservation, nouv.ID_parking, nouv.date_de_reservation,
                    nouv.heure_arriver, nouv.heure_de_depart);
            tr = 1;
        } else {
            fprintf(f2, "%d %d %d %d %d\n",
                    res.ID_reservation, res.ID_parking, res.date_de_reservation,
                    res.heure_arriver, res.heure_de_depart);
        }
    }

    fclose(f);
    fclose(f2);

    remove(filename);
    rename("nouv.txt", filename);

    return tr;
}

int supprimer(char *filename, int ID_reservation) {
    int tr = 0;
    reservation res;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f == NULL || f2 == NULL) {
        printf("Erreur : Impossible d'ouvrir les fichiers pour suppression.\n");
        if (f) fclose(f);
        if (f2) fclose(f2);
        return 0;
    }

    while (1) {
        int result = fscanf(f, "%d %d %d %d %d\n",
                            &res.ID_reservation, &res.ID_parking, &res.date_de_reservation,
                            &res.heure_arriver, &res.heure_de_depart);

        if (result == EOF) {
            break;
        }

        if (result != 5) {
            printf("Erreur : Ligne mal formatée dans le fichier.\n");
            continue;
        }

        if (res.ID_reservation == ID_reservation) {
            tr = 1;
        } else {
            fprintf(f2, "%d %d %d %d %d\n",
                    res.ID_reservation, res.ID_parking, res.date_de_reservation,
                    res.heure_arriver, res.heure_de_depart);
        }
    }

    fclose(f);
    fclose(f2);

    remove(filename);
    rename("nouv.txt", filename);

    return tr;
}


void afficher(char *filename, int ID_reservation) {
    reservation res;
    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        while (fscanf(f, "%d %d %d %d %d\n", &res.ID_reservation, &res.ID_parking, &res.date_de_reservation, &res.heure_arriver, &res.heure_de_depart) != EOF) {
            if (res.ID_reservation == ID_reservation) {
                printf("%d %d %d %d %d\n", res.ID_reservation, res.ID_parking, res.date_de_reservation, res.heure_arriver, res.heure_de_depart);
            }
        }
        fclose(f);
    } else {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
    }
}

reservation chercher(char * filename, int ID_reservation)
{
    reservation res;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %d %d %d\n",&res.ID_reservation,&res.ID_parking,&res.date_de_reservation,&res.heure_arriver,&res.heure_de_depart)!=EOF)
        {
            if (res.ID_reservation== ID_reservation)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        res.ID_reservation=-1;
	return res;
}


void afficher_parkings_tries(char *filename)
{ 
     Parking parkings[100];
  int count = 0;
   FILE *f = fopen(filename, "r"); 
     if (f == NULL) {
    printf("Erreur : Impossible d'ouvrir le fichier %s\n", filename);
    return;   }

  while (fscanf(f, "%d %s %d\n", &parkings[count].ID_parking, parkings[count].localisation, &parkings[count].places_disponibles) != EOF) {
	 count++;
    } 
      fclose(f);

  for (int i = 0; i < count - 1; i++) {
	 for (int j = 0; j < count - i - 1; j++) {
	   if (parkings[j].places_disponibles < parkings[j + 1].places_disponibles) {
	  Parking temp = parkings[j]; parkings[j] = parkings[j + 1]; parkings[j + 1] = temp;
         }  
      }
    }

  printf("Liste des parkings triés par nombre de places disponibles :\n");
  printf("ID Parking | Localisation | Places Disponibles\n");
   for (int i = 0; i < count; i++) {
   printf("%d | %s | %d\n", parkings[i].ID_parking,parkings[i].localisation,parkings[i].places_disponibles);
      }
}
