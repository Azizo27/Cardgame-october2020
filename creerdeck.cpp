

#include "header.h"




void creerdeck(Deck &undeck, std::vector <Carte> &card, int choixdeck)
{
    int choix;

    if (choixdeck==1)
    {
        std::cout<< "Ci-dessous, voici les cartes avec lequelles vous pouvez composer votre deck de "<< Nombrecartedeck << " cartes" << std::endl
                 << "Tapez le chiffre correspondant a la carte que vous souhaitez."<< std::endl << std::endl;

        ///Affichage de toutes les cartes disponible
        affichageensemblecarte(card);


        for (int i=0; i<Nombrecartedeck; i++)
        {
            do
            {
                std::cin >> choix;
                if (choix <1 || choix > 26)
                    std::cout <<"La valeur saisie n'est pas valide " << std::endl;
            }
            while (choix <1 || choix > 26);   ///IL EXISTE 26 TYPE DE CARTE POUR L INSTANT

            undeck.ajoutercarte(card[choix - 1]); ///ON MET -1 POUR CORRESPONDRE A L AFFICHAGE
        }
    }
    if (choixdeck==2) //Deck specialisé Tech/film offensif(deck aziz)
    {

    //8 Cartes monstres
        undeck.ajoutercarte(card[4]);
        undeck.ajoutercarte(card[5]);
        undeck.ajoutercarte(card[6]);
        undeck.ajoutercarte(card[7]);
        undeck.ajoutercarte(card[10]);
        undeck.ajoutercarte(card[11]);
        undeck.ajoutercarte(card[13]);
        undeck.ajoutercarte(card[14]);


        //6 cartes speciales
        undeck.ajoutercarte(card[15]);
        undeck.ajoutercarte(card[18]);
        undeck.ajoutercarte(card[19]);
        undeck.ajoutercarte(card[20]);
        undeck.ajoutercarte(card[20]);
        undeck.ajoutercarte(card[21]);

        //6 Cartes energies
        undeck.ajoutercarte(card[23]);
        undeck.ajoutercarte(card[23]);
        undeck.ajoutercarte(card[23]);
        undeck.ajoutercarte(card[25]);
        undeck.ajoutercarte(card[25]);
        undeck.ajoutercarte(card[25]);

    }

    if (choixdeck==3) //Deck specialisé Musique/Sport defensif (deck Paul)
    {

    //8 Cartes monstres
        undeck.ajoutercarte(card[0]);
        undeck.ajoutercarte(card[1]);
        undeck.ajoutercarte(card[2]);
        undeck.ajoutercarte(card[3]);
        undeck.ajoutercarte(card[6]);
        undeck.ajoutercarte(card[8]);
        undeck.ajoutercarte(card[9]);
        undeck.ajoutercarte(card[10]);


        //6 cartes speciales
        undeck.ajoutercarte(card[16]);
        undeck.ajoutercarte(card[17]);
        undeck.ajoutercarte(card[18]);
        undeck.ajoutercarte(card[18]);
        undeck.ajoutercarte(card[19]);
        undeck.ajoutercarte(card[21]);

        //6 Cartes energies
        undeck.ajoutercarte(card[22]);
        undeck.ajoutercarte(card[22]);
        undeck.ajoutercarte(card[22]);
        undeck.ajoutercarte(card[24]);
        undeck.ajoutercarte(card[24]);
        undeck.ajoutercarte(card[24]);

    }



}



///J AVAIS JUSTE BESOIN D UNE FICHE OU METTRE CE SS PROGRAMME
void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void gotoligcol( int lig, int col )
{
// ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
