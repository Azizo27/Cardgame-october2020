#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "Carte.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>


class Deck
{
private:
    ///METTRE EN TANT QUE FILE LE  m_deck
    ///OU EN TANT QUE VECTEUR
    std::vector<Carte*> m_deck;
    int m_nbcarte;


public:
    Deck();
    ~Deck();

    void ajoutercarte(Carte& carte);
    void enlevercarte(Carte& carte);
    void enlevercartedessus(); ///Cette fonction enleve spécifiquement la carte du dessus du deck
    void afficherdeck() const;
    void melangerdeck();

    std::vector<Carte*> getdeck() const;
    int getnbcarte() const;

};




#endif // DECK_H_INCLUDED
