
#include "header.h"



void partie(Joueur& j1, Terrain& terrain_un, Joueur& j2, Terrain& terrain_deux, int& numerotour)
{
    int uniqueinvocation=1;
    int degatattaque;
    int i;

    std::string nom_un;
    std::string nom_deux;
    nom_un=j1.getnomjoueur();
    nom_deux=j2.getnomjoueur();

    system("cls");

    j1.piochcarte();
    do
    {

        j1.afficherJoueur();
        terrain_un.afficherterrain(1, nom_un); ///PEUT ETRE A ENLEVER

        j1.jouercarte(uniqueinvocation, terrain_un.getnbcartemonstre());
        if (j1.getcartejouer()!=NULL)
        {
            terrain_un.posercarte(*j1.getcartejouer(), uniqueinvocation, j1, j2, numerotour);
        }
        system("cls");
    }
    while (j1.getcartejouer()!=NULL); ///CETTE BOUCLE DO PERMET DE SAVOIR QUAND LE JOUEUR NE VEUT PLUS POSER DE CARTE.
    ///A CE MOMENT, LA VARIABLE CARTE JOUER PREND LA VALEUR DE NULL



    if (numerotour==1)
    {

    }
    else
    {
        for (i=0; i<terrain_un.getnbcartemonstre(); i++)
        {
            if (terrain_un.getmanaun()==0 && terrain_un.getmanadeux()==0 && terrain_un.getmanatrois()==0 && terrain_un.getmanaquatre()==0)
            {
                std::cout <<"Vous n avez pas de mana. Nous passons donc votre phase d attaque." <<std::endl;
                Sleep(4000);
                i=terrain_un.getnbcartemonstre();
            }
            else
            {
                system("cls");
                terrain_un.afficherterrain(1, nom_un);
                terrain_deux.afficherterrain(2, nom_deux);
                terrain_un.phaseattaque(degatattaque, i);

                system("cls");

                ///ICI, IL FAUT AFFICHER LE TERRAIN DU JOUEUR QUI SE FAIT ATTAQUER, MAIS SANS AFFICHER SON MANA, SINON ON RISQUE DE PERDRE LE JOUEUR

                terrain_deux.afficherterrain(2, nom_deux);
                terrain_deux.subirattaque(degatattaque);
                j2.degatsurpvjoueur(degatattaque);
            }

        }
    }
    numerotour++;
}
