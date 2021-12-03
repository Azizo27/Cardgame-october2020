
#include "header.h"


void creermain(Main &main, Deck &deck)
{
    std::vector <Carte*> tempdeck;
    tempdeck=deck.getdeck();

    for (int i=0; i<Nombrecartedebutpartie; i++)
    {
        main.ajoutercarte(*tempdeck[i]);
        deck.enlevercartedessus();
    }


}


void piochercartemise(Deck &deck, Carte &cart)
{
    std::vector <Carte*> tempdeck;
    tempdeck=deck.getdeck();

    if (deck.getnbcarte()>0)
    {
        cart=*tempdeck[0];
        deck.enlevercartedessus();
    }
    else
        std::cout << "Il n y a plus de carte dans le deck, vous ne piochez rien" <<std::endl;

}


///A ENLEVER QUAND LE PROGRAMME EN DESSOUS SERA FINI
void piochercarte(Main &main, Deck &deck)
{
    std::vector <Carte*> tempdeck;
    tempdeck=deck.getdeck();

    if (deck.getnbcarte()>0)
    {
        main.ajoutercarte(*tempdeck[0]);
        deck.enlevercartedessus();
    }
    else
        std::cout << "Il n y a plus de carte dans le deck, vous ne piochez rien" <<std::endl;

}


