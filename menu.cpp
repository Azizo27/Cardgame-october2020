#include "header.h"


int menu()
{
    int choix;
    std::cout <<std::endl;
    Color(0,15);
    std::cout << "MENU:";
    Color(15, 0);
    std::cout << std::endl << std::endl;
    std::cout << "1. Creer un nouveau deck" << std::endl;
    std::cout << "2. Charger le deck du Joueur Aziz" << std::endl;
    std::cout << "3. Charger le deck du Joueur Paul" << std::endl;
    do
    {
        std::cin >> choix;
        if (choix!=1 && choix!=2 && choix!=3)
            std::cout <<"Veuillez ecrire un chiffre entre 1 et 3" << std::endl;
    }
    while (choix!=1 && choix!=2 && choix!=3);


    system("cls");
    return choix;
}




void affichagevictoire(Deck& deckun, Deck& deckdeux, Carte& card, int i)
{
    std::cout <<"C est le joueur "<<i <<" qui a gagne. Nous ajoutons donc les deux cartes mises au deck du gagnant et nous retirons la carte mise du deck du perdant" << std::endl;
        deckdeux.ajoutercarte(card);
        deckun.enlevercarte(card);
        std::cout << "LE NOUVEAU DECK DU GAGNANT :" << std::endl;
        deckdeux.afficherdeck();
}


