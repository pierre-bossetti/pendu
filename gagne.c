#include "pendu.h"

int gagne(char mot_cache[], int lettres_trouvees[])
{
    int i;

    i = 0;
    while (mot_cache[i])
    {
        if (lettres_trouvees[i] == 0)
            return 0;
        i++;
    }
    return (1);
}