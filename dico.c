#include "dico.h"

int piocher_mot(char *mot)
{
    FILE    *dico = NULL;
    int     nombre_mots;
    int     num_mot_choisi;
    int     c;

    c = 0;
    nombre_mots = 0;
    num_mot_choisi = 0;

    dico = fopen("mots.txt", "r");
    if (dico == NULL)
    {
        printf("Le fichier n'a pas pu être ouvert.");
        return(0);
    }
    // compte le nombre de mots ds fichier grace retour de ligne
    // fgets retourne un int c'est pourquoi c est un int
    while(c != EOF)
    {
        c = fgetc(dico); //parcoure le fichier char par char
        if (c == '\n')
            nombre_mots++;
    }
    num_mot_choisi = nombre_aleatoire(nombre_mots);
    rewind(dico);
    while(num_mot_choisi > 0) // on revient au bon mot avec curseur
    {
        c = fgetc(dico);
        if (c == '\n')
            num_mot_choisi--;
    }
    fgets(mot, 100, dico);
    mot[strlen(mot) - 1] = '\0';
    fclose(dico);
    return (1);
}

int nombre_aleatoire(int nombre_max)
{
    srand(time(NULL));
    return (rand() % nombre_max);
}