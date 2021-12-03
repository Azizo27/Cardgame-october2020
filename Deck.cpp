
#include "header.h"


///Constructeurs et destructeurs

Deck::Deck()
{
    m_nbcarte=0;
}

Deck::~Deck()
{

}

///Ajouter l'adresse d'une carte dans le deck

void Deck::ajoutercarte(Carte& carte)
{
        Carte* nouveau=new Carte(carte.gettypecarte(), carte.getdescription(), carte.getnomcarte(),

           carte.getpointdevie(),

            carte.getnomattaqueun(),
           carte.getdegatattaqueun(),
            carte.gettype_domaine_consomme_par_attaqueun(),
          carte.getcoutattaqueun() ,

          carte.getnomattaquedeux(),
          carte.getdegatattaquedeux(),
           carte.gettype_domaine_consomme_par_attaquedeux(),
          carte.getcoutattaquedeux(),

          carte.geteffet(),

          carte.gettypedomaine());

        m_deck.push_back(nouveau);
        m_nbcarte++;


}

///Enlever carte du deck

void Deck::enlevercarte(Carte& carte)
{
    int  erreur=0;

    for(int i=0; i<m_nbcarte; i++)
    {
        if(m_deck[i]==&carte)
        {
            m_deck.erase(m_deck.begin()+i);
            m_nbcarte--;
            erreur++;

        }
    }

    if(erreur==0)
    {

        std::cout << "La carte n'est pas dans le deck " << std::endl;
    }

}



void Deck::enlevercartedessus()
{
    if (m_nbcarte>0)
    {
        m_deck.erase(m_deck.begin());
        m_nbcarte--;
    }
    else
        std::cout << "Il n y a plus de carte dans le deck, vous ne piochez rien" <<std::endl;
}

///Afficher le contenu d'un deck

void Deck::afficherdeck() const
{
    std::cout  << std::endl << "Deck:" <<  std::endl;

    int i=0;

    for(i=0; i<m_nbcarte; i++)
    {

        m_deck[i]->affichercarte();
        std::cout << std::endl;
    }

}

///Melanger les cartes du deck (idealement en debut de partie)

void Deck::melangerdeck()
{
    for (int i=0; i<m_nbcarte; i++)
    {
        int second=(rand()+ time(0)) % m_nbcarte;

        Carte* temp=m_deck[i];
        m_deck[i]=m_deck[second];
        m_deck[second]=temp;
    }

}

std::vector<Carte*> Deck::getdeck() const
{
    return m_deck;
}

int Deck::getnbcarte() const
{
    return m_nbcarte;
}
