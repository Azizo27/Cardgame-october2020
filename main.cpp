#include "header.h"



int main()
{
    ///Les variables
    Deck deck_un;
    Deck deck_deux;
    Deck temp_deck_un;//Ces temp servent a recuperer le deck avant la main, la carte mise...
    Deck temp_deck_deux;//Ces temp servent a recuperer le deck avant la main, la carte mise...
    Main main_un;
    Main main_deux;
    Carte carte_mise_un;
    Carte carte_mise_deux;
    Terrain terrain_un;
    Terrain terrain_deux;
    int choixdeck_un;
    int choixdeck_deux;
    int numerotour=1;
    ///Initialiser le deck, la main et la carte mise pour  joueur 1 et la Mettre ces parametres dans la classe joueur
    std::vector <Carte> card;
    initialisercarte(card); //REMARQUE: Sa fonction d affichage est appelé dans les sous programmes "creerdeck", c est donc inutile de l appeler ici

    ///POUR CREER LE JOUEUR 1:
    std::cout << "Vous allez creer le deck pour le joueur 1 : " << std::endl;

    choixdeck_un=menu(); //Si =1, on cree un nouveau deck, si =2, on charge le deck de AZIZ, Si =3, On charge le deck de PA
    creerdeck(deck_un, card, choixdeck_un);
    temp_deck_un=deck_un;
    deck_un.melangerdeck();
    piochercartemise(deck_un, carte_mise_un);
    creermain(main_un, deck_un); //REMARQUE: On cree la main apres avoir cree le deck et piocher la carte mise
    Joueur j1(deck_un, main_un, carte_mise_un, choixdeck_un);
    system("cls");


    ///POUR CREER LE JOUEUR 2:
    std::cout << "Vous allez creer le deck pour le joueur 2 : " << std::endl;
    choixdeck_deux=menu();
    creerdeck(deck_deux, card, choixdeck_deux);
    temp_deck_deux=deck_deux;
    deck_deux.melangerdeck();
    piochercartemise(deck_deux, carte_mise_deux);
    creermain(main_deux, deck_deux); //REMARQUE: On cree la main apres avoir cree le deck et piocher la carte mise
    Joueur j2(deck_deux, main_deux, carte_mise_deux, choixdeck_deux);
    system("cls");

    do
    {
        partie(j1, terrain_un, j2, terrain_deux, numerotour);

        if (j1.get_pv()>0 && j2.get_pv()>0)
            partie(j2, terrain_deux, j1, terrain_un, numerotour);


    }
    while (j1.get_pv()>0 && j2.get_pv()>0);

    system("cls");

    if (j1.get_pv()==0)
    {
        affichagevictoire(temp_deck_un, temp_deck_deux, *j1.getcartemise(), 2);

    }

    if (j2.get_pv()==0)
    {
        affichagevictoire(temp_deck_deux, temp_deck_un, *j2.getcartemise(), 1);

    }

    return 0;
}
