#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Deck.h"
#include "Carte.h"
#include "Hand.h"

class Joueur
{
private:
    std::string m_nom;
    Deck* m_deck_joueur;
    Main* m_main;
    Carte* m_mise;
    Carte* m_carte_jouer;
    int m_nbvictoire;
    int m_argent;
    int m_PV;

public:
    Joueur();
    Joueur(Deck& deck_joueur, Main& main, Carte& mise, int choixdeck);
    ~Joueur();

    void afficherJoueur() const;
    void jouercarte(int& uniqueinvocation, int nbrcarteattaque);
    Carte* getcartejouer() const;
    void degatsurpvjoueur(int degatattaque);
    int get_pv() const;

    Carte* getcartemise() const;
    std::string getnomjoueur() const;


    void piochcarte();
    void soinpvjoueur();


    Deck* getdeck() const;


};


#endif // JOUEUR_H_INCLUDED
