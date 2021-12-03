#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <iostream>
#include "Carte.h"
#include "Deck.h"
#include "Hand.h"
#include "Carte.h"
#include "Joueur.h"
#include "terrain.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

class Terrain
{
private:

    ///Le mana de chaque domaine
    int m_mana_domaine_un;
    int m_mana_domaine_deux;
    int m_mana_domaine_trois;
    int m_mana_domaine_quatre;

    int m_nbcartemonstre;
    std::vector <Carte*> m_cartemonstre;

public:
    Terrain();
    ~Terrain();

    void posercarte(Carte& card, int& uniqueinvocation, Joueur& j1, Joueur& j2, int& numerotour);

    void phaseattaque(int& degatattaque, int i);
    void subirattaque(int& degatattaque);

    void afficherterrain(int choixterrain, std::string nom) const;
    int getnbcartemonstre() const;

    int getmanaun() const;
    int getmanadeux() const;
    int getmanatrois() const;
    int getmanaquatre() const;



};

#endif // TERRAIN_H_INCLUDED
