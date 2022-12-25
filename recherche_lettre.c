#include "pendu.h"

int recherche_lettre(char lettre, char *mot_cache, int lettres_trouvees[])
{
    int i;
    int bonne_lettre;

    i = 0;
    bonne_lettre = 0;
    while (mot_cache[i])
    {
        if (lettre == mot_cache[i])
        {
            bonne_lettre = 1;
            lettres_trouvees[i] = 1;
        }
        i++;
    }
    return (bonne_lettre);
}