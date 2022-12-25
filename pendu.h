#ifndef PENDU_H
# define PENDU_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int ft_counts_words(FILE *ptr_fichier);
int recherche_lettre(char lettre, char *mot_cache, int lettres_trouvees[]);
int gagne(char mot_cache[], int lettres_trouvees[]);
void continuer_partie(int *continuer_partie);

#endif