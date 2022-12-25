#include "pendu.h"

void continuer_partie(int *continuer_jouer)
{
    printf("Souhaitez-vous rejouer? Oui[1] Non [0]\n");
    scanf("%d", continuer_jouer);
    printf("Char : %d\n", *continuer_jouer);
}