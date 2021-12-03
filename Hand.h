#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include "Carte.h"
#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

class Main
{
private:
    ///METTRE EN TANT QUE FILE LE  m_deck
    ///OU EN TANT QUE VECTEUR
    std::vector<Carte*> m_main;
    int m_nbcarte;


public:
    Main();
    ~Main();
    void ajoutercarte(Carte& carte);
    void enlevercarte(Carte& carte);
    Carte* enlevercartechoisi(int& uniqueinvocation, int nbrcarteattaque);
    void affichermain();

};





#endif // HAND_H_INCLUDED
