
#include "header.h"


void affichageensemblecarte (std::vector <Carte> &card)
{
    for(unsigned int i=0; i<card.size(); i++)
    {
        std::cout << i +1 << ". ";
        card[i].affichercarte();
        std::cout<< std::endl;
    }
    std::cout << std::endl<< std::endl<< std::endl;

}

void initialisercarte(std::vector <Carte> &card)
{

///EXEMPLE CARTE (avec les bons parametres) POUR LES MONSTRES
    Carte c_1(1, "Chanteur du groupe Queen", "Freddie Mercury",
             15,
             "Lancer de micro",30,"SPORT",1,
             "Bohemian Rhaspody",50,"MUSIQUE",3,
             0, ""); //GROS TPS

    Carte c_2(1, "Chanteur et guitariste du groupe Nirvana", "Kurt Cobain",
             60,
             "Smells like a teen spirit",5,"MUSIQUE",1,
             "30 millions d'albums",10,"MUSIQUE",2,
             0, ""); // GROS TANK

    Carte c_3(1, "King of the pop", "Michael Jackson",
             35,
             "Thriller",15,"MUSIQUE",1,
             "Moonwalk",20,"SPORT",2,
             0, ""); //MOYEN

    Carte c_4(1, "Chanteuse française pop qui a marque les annees 90", "Larusso",
             25,
             "Tu m'oublieras ",20,"MUSIQUE",1,
             "Premiere partie de Johny",30,"MUSIQUE",2,
             0, ""); //PETIT TPS

    Carte c_5(1, "Console qui marque les debuts du jeux-videos", "Playstation 1",
             60,
             "Tomb raider",5,"TECHNOLOGIE",1,
             "Gran Turismo",10,"TECHNOLOGIE",2,
             0, ""); //GROS TANK

    Carte c_6(1, "Video Home system", "VHS",
             25,
             "Bande magnetique",20,"TECHNOLOGIE",1,
             "Rembobinage",30,"FILM/SERIE",2,
             0, ""); //PETIT TPS

    Carte c_7(1, "Baladeurs à cassette qui a marqué son temps", "Walkman Sony",
             35,
             "Changement de cassette",15,"TECHNOLOGIE",1,
             "Son a fond",20,"MUSIQUE",2,
             0, ""); //MOYEN

    Carte c_8(1, "Premier telephone portable français", "Bi pop France telecom",
             15,
             "Ondes destabilisantes",30,"TECHNOLOGIE",1,
             "Bornes telecom",50,"TECHNOLOGIE",3,
             0, ""); //GROS TPS

    Carte c_9(1, "Légende du football", "Zinedine Zidane",
             45,
             "Roulette",7,"SPORT",1,
             "Coup de boule",12,"SPORT",2,
             0, ""); //PETIT TANK

    Carte c_10(1, "Légende du basketball", "Michael Jordan",
             25,
             "Dribble",20,"SPORT",1,
             "Dunk",30,"SPORT",2,
             0, ""); //PETIT TPS

    Carte c_11(1, "Héros du titre eponyme", "Forrest Gump",
             35,
             "Course effrenee",15,"SPORT",1,
             "Peche a la crevette",20,"FILM/SERIE",2,
             0, ""); //MOYEN

    Carte c_12(1, "Saga incontournable de science fiction", "Star Wars",
             45,
             "Etranglement par la force",7,"FILM/SERIE",1,
             "Sabre laser",12,"TECHNOLOGIE",2,
             0, ""); //PETIT TANK


    Carte c_13(1, "Bobsleigh jamaicain aux JO", "Rasta Rockett",
             60,
             "Resistance au froid",5,"FILM/SERIE",1,
             "Bobsleigh",10,"SPORT",2,
             0, ""); //GROS TANK

    Carte c_25(1, "Film culte", "Retour vers le futur",
             15,
             "La Delorian",30,"FILM/SERIE",1,
             "Hoverboard",50,"FILM/SERIE",3,
             0, ""); //GROS TPS


    Carte c_26(1, "Road movie culte", "Thelma et Louise",
             45,
             "Thelma",7,"FILM/SERIE",1,
             "Louise",12,"FILM/SERIE",2,
             0, ""); //PETIT TANK


///EXEMPLE CARTE (avec les bons parametres) POUR LES SPECIALES
Carte c_14(2, "Augmente l'attaque d'une creature de 20", "Rail de cocaine",
          0,
          "",0,"",0,
          "",0,"",0,
          5, "");

Carte c_15(2, "Augmente les PV d'une creature de 15", "Traitement du VIH",
          0,
          "",0,"",0,
          "",0,"",0,
          4, "");

Carte c_16(2, "Rajoute 20 PV au joueur", "Liberation de Nelson Mandela",
          0,
          "",0,"",0,
          "",0,"",0,
          3, "");

Carte c_17(2, "Vous piochez deux cartes", "Bug de l'an 2000",
          0,
          "",0,"",0,
          "",0,"",0,
          2, "");

Carte c_18(2, "Sacrifiez un de vos monstres et convertir ses PV en degats direct sur l adversaire", "Mort de star",
          0,
          "",0,"",0,
          "",0,"",0,
          6, "");

Carte c_19(2, "Vous pouvez invoquer une creature de plus ce tour-ci", "Bonus",
          0,
          "",0,"",0,
          "",0,"",0,
          1, "");

Carte c_24(2, "Le joueur adverse ne pourra pas vous attaquer au prochain tour", "Immunite diplomatique",
          0,
          "",0,"",0,
          "",0,"",0,
          7, "");




///EXEMPLE CARTE (avec les bons parametres) POUR LES ENERGIES
Carte c_20(3, "Vous donne 3 energie MUSIQUE", "MUSIQUE",
           0,
             "",0,"",0,
             "",0,"",0,
             0, "MUSIQUE");

Carte c_21(3, "Vous donne 3 energie TECHNOLOGIE", "TECHNOLOGIE",
           0,
             "",0,"",0,
             "",0,"",0,
             0, "TECHNOLOGIE");

Carte c_22(3, "Vous donne 3 energie SPORT", "SPORT",
           0,
             "",0,"",0,
             "",0,"",0,
             0, "SPORT");

Carte c_23(3, "Vous donne 3 energie FILM/SERIE", "FILM/SERIE",
           0,
             "",0,"",0,
             "",0,"",0,
             0, "FILM/SERIE");





    card.push_back(c_1);
    card.push_back(c_2);
    card.push_back(c_3);
    card.push_back(c_4);
    card.push_back(c_5);
    card.push_back(c_6);
    card.push_back(c_7);
    card.push_back(c_8);
    card.push_back(c_9);
    card.push_back(c_10);
    card.push_back(c_11);
    card.push_back(c_12);
    card.push_back(c_13);
    card.push_back(c_25);
    card.push_back(c_26);

    card.push_back(c_14);
    card.push_back(c_15);
    card.push_back(c_16);
    card.push_back(c_17);
    card.push_back(c_18);
    card.push_back(c_19);
    card.push_back(c_24); //CETTE CARTE JE L AI AJOUTE LE 28/11 A 18h. C EST LA CARTE QUI PERMET D EMPECHER L ADVERSAIRE DE T ATTAQUER AU PROCHAIN TOUR

    card.push_back(c_20);
    card.push_back(c_21);
    card.push_back(c_22);
    card.push_back(c_23);



}
