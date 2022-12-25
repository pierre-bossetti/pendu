#include "pendu.h"
#include "dico.h"

char    lire_caractere()
{
    char    caractere;

    caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while(getchar() != '\n');

    return (caractere);
}

int main (void)
{
    char    mot_cache[100] = {0}; // un mot du fichier mots.txt fera max 100 chars
    char    lettre;
    int     *lettres_trouvees;
    int     vies;
    int     i;
    int     taille_mot;
    int     continuer_jouer;

    printf("Bienvenue dans le jeu du Pendu !\n");
    printf("-------------------------\n");
    printf("INSEREZ UNIQUEMENT DES LETTRES MAJUSCULES SVP\n");
    while (continuer_jouer)
    {
        if (!piocher_mot(mot_cache))
        exit(0);
        lettres_trouvees = NULL;
        vies = 10;
        lettre = 0;
        i = 0;
        continuer_jouer = 1;
        taille_mot = strlen(mot_cache);
        lettres_trouvees = malloc(sizeof(int) * taille_mot);
        if (lettres_trouvees == NULL)
            exit (0);
        while (vies > 0 && !gagne(mot_cache, lettres_trouvees))
        {
            printf("\nIl vous reste %d vies\n", vies);
            printf("Quel est le mot secret? ");
            
            i = 0;
            while(mot_cache[i])
            {
                if (lettres_trouvees[i])
                    printf("%c", mot_cache[i]);
                else
                    printf("*");
                i++;
            }

            printf("\nProposez une lettre : ");
            lettre = lire_caractere();

            if(!recherche_lettre(lettre, mot_cache, lettres_trouvees))
                vies--;
        }
        if (gagne(mot_cache, lettres_trouvees))
            printf("🎉🎉🎉 Bravo vous avez trouvé le mot %s 🎉🎉🎉", mot_cache);
        else
            printf("\n❌❌❌ Vous avez perdu le mot était %s ❌❌❌", mot_cache);
        continuer_partie(&continuer_jouer);
    }
    free(lettres_trouvees);
}
