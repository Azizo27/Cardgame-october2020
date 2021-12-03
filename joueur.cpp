#include "Joueur.h"
#include <iostream>
#include "header.h"

Joueur::Joueur()
{

}


Joueur::Joueur(Deck& deck_joueur, Main& main, Carte& mise, int choixdeck)
{
    std::string nom;
    if (choixdeck==1)
    {
        std::cout << std::endl << "Pseudo du joueur: ";
        std::cin >> nom;
        m_nom=nom;
    }
    if (choixdeck==2)
        m_nom="Aziz";

    if (choixdeck==3)
        m_nom="Paul";

    m_deck_joueur=&deck_joueur;
    m_main=&main;
    m_mise=&mise;
    m_carte_jouer=NULL;

    m_nbvictoire=0;
    m_argent=0;
    m_PV=100; ///A DEFINIR

}



Joueur::~Joueur()
{

}

void Joueur::afficherJoueur()const
{
    if (m_mise!=NULL){
    Color(0,15);
    std::cout <<  "LA CARTE MISE EN JEU PAR " << m_nom;
    Color(15, 0);
    std::cout << std::endl;
    m_mise->affichercarte();
    std::cout << std::endl << std::endl;
    }

    Color(0,15);
    std::cout << "PSEUDO:";
    Color(15, 0);
    std::cout << std::endl << m_nom;
    std::cout << std::endl << std::endl;

    Color(0,15);
    std::cout << "PV:";
    Color(15, 0);
    std::cout << std::endl << m_PV;
    std::cout << std::endl;

    ///A METTRE SI ON VEUT AFFICHER LE NOMBRE DE VICTOIRE ET L ARGENT
    /*std::cout << "*Nombre victoires gagnees : " << m_nbvictoire <<std::endl;
    std::cout << "*Argent : " << m_argent <<std::endl;*/




    //m_deck_joueur->afficherdeck(); ///sera enlevé dans la version final
    m_main->affichermain();


    ///A METTRE SI ON VEUT AFFICHER LA CARTE MISE EN JEU (LA CARTE QU ON RISQUE DE PERDRE) + LA CARTE QU ON VIENT DE JOUER
    /*if (m_mise!=NULL){
    std::cout << std::endl << "*Carte mise en jeu par " << m_nom << " :" << std::endl;
    m_mise->affichercarte();
    }
    std::cout << std::endl << "*Carte joue sur ce coup :" <<std::endl;
    if (m_carte_jouer==NULL)
        std::cout <<"aucune carte joue" << std::endl << std::endl;
    else
        m_carte_jouer->affichercarte();*/

}


void Joueur::jouercarte(int& uniqueinvocation, int nbrcarteattaque)
{

    m_carte_jouer= m_main->enlevercartechoisi(uniqueinvocation, nbrcarteattaque);

}



void Joueur::piochcarte()
{
    std::vector <Carte*> tempdeck;
    tempdeck=m_deck_joueur->getdeck();

    if (m_deck_joueur->getnbcarte()>0)
    {
        m_main->ajoutercarte(*tempdeck[0]);
        m_deck_joueur->enlevercartedessus();
    }
    else
        std::cout << "Il n y a plus de carte dans le deck, vous ne piochez rien" <<std::endl;

}





Deck* Joueur::getdeck() const
{
    return m_deck_joueur;
}



void Joueur::degatsurpvjoueur(int degatattaque)
{
    m_PV=m_PV- degatattaque;
    if (m_PV<0)
        m_PV=0;
}

void Joueur::soinpvjoueur()
{
    if (m_PV>0)
    {
        m_PV=m_PV + 20;
    }
}

int Joueur::get_pv() const
{
    return m_PV;
}

Carte* Joueur::getcartejouer() const
{
    return m_carte_jouer;
}

Carte* Joueur::getcartemise() const
{
    return m_mise;
}

std::string Joueur::getnomjoueur() const
{
    return m_nom;
}
