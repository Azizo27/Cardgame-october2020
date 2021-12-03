#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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
#define Nombrecartedeck 20
#define Nombrecartedebutpartie 5
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond);

///ON PEUT METTRE CE HEADER POUR LES .cpp. MAIS POUR LES .h, IL FAUT REECRIRE LES INCLUDES, LES DEFINES...
void creermain(Main &main, Deck &deck);
void piochercarte(Main &main, Deck &deck);
void affichageensemblecarte (std::vector <Carte> &card);
void initialisercarte(std::vector <Carte> &card);
void creerdeck(Deck &undeck, std::vector <Carte> &card, int choixdeck);
void piochercartemise(Deck &deck, Carte &cart);

void partie(Joueur& j1, Terrain& terrain_un, Joueur& j2, Terrain& terrain_deux, int& numerotour);


int menu();
void affichagevictoire(Deck& deckun, Deck& deckdeux, Carte& card, int i);

void gotoligcol( int lig, int col );



#endif // HEADER_H_INCLUDED
