
#include "header.h"


///Constructeurs et destructeurs

Main::Main()
{
    m_nbcarte=0;
}

Main::~Main()
{

}


void Main::ajoutercarte(Carte& carte)
{
    m_main.push_back(&carte);
    m_nbcarte++;
}

///Enlever carte du deck




void Main::enlevercarte(Carte& carte)
{
    int  erreur=0;

    for(int i=0; i<m_nbcarte; i++)
    {
        if(m_main[i]==&carte)
        {
            m_main.erase(m_main.begin()+i);
            m_nbcarte--;
            erreur++;

        }
    }

    if(erreur==0)
    {

        std::cout << "La carte n'est pas dans la main du joueur "  << std::endl;
    }

}


Carte* Main::enlevercartechoisi(int& uniqueinvocation, int nbrcarteattaque)
{
    Carte* carde;
    int choix;
    int decision;
    Carte* yugi;


    if (m_nbcarte==0)
    {
        std::cout <<"Vous n avez plus de carte en main, Vous allez passez a la phase d attaque " << std::endl;
        return NULL;
    }

    std::cout << "Choisissez le numero de carte que vous voulez jouer. Si vous voulez terminer cette phase, ecrivez 0" << std::endl;

    do
    {
        std::cin >> choix;
        if (choix<1 || choix > m_nbcarte )
            std::cout << "Vous n avez pas ce nombre de carte en main. Veuillez ecrire le numero de carte que vous souhaitez jouer" <<std::endl;

    }
    while (choix<0 || choix > m_nbcarte );

    if (choix!=0)
    {
        carde=m_main[choix-1];

        if (carde->gettypecarte()==2)
        {
            if (carde->geteffet()==5 || carde->geteffet()==4 || carde->geteffet()==6) ///METTRE LA VALEUR DES CARTES A EFFETS SUR LES MONSTRES SUR LE TERRAIN
            {
                if (nbrcarteattaque==0)
                    return NULL;

            }
            m_main.erase(m_main.begin() + (choix-1));
            m_nbcarte--;
            return carde;
        }

        if (carde->gettypecarte()==3)
        {
            m_main.erase(m_main.begin() + (choix-1));
            m_nbcarte--;
            return carde;
        }


        if (carde->gettypecarte()==1)
        {
            if (uniqueinvocation==0)
            {
                do
                {
                    std::cout <<"Vous n avez pas le droit de poser deux cartes monstres le meme tour. Veuillez choisir une autre carte ou passer votre tour" << std::endl;
                    do
                    {
                        std::cin >> decision;
                        if (decision<1 || decision > m_nbcarte )
                            std::cout << "Vous n avez pas ce nombre de carte en main. Veuillez ecrire le numero de carte que vous souhaitez jouer" <<std::endl;

                    }
                    while (decision<0 || decision > m_nbcarte );
                    if (decision>0)
                        yugi=m_main[decision-1];

                    if (decision==0)
                        return NULL;
                }
                while (yugi->gettypecarte()==1 && decision!=0);

                if (decision!=0)
                {
                    m_main.erase(m_main.begin() + (decision-1));
                    m_nbcarte--;
                    return yugi;

                }
                if (decision==0)
                    return NULL;


            }


            if (uniqueinvocation>0)
            {
                m_main.erase(m_main.begin() + (choix-1));
                m_nbcarte--;
                uniqueinvocation--;
                return carde;
            }

        }

    }
    else
    {
        return NULL;
    }

    return NULL; //J AI MIS CE RETURN ICI POUR ENLEVER LES WARNING MAIS IL NE SERT A RIEN PUISQU ON NE DEVRAIT JAMAIS L ATTEINDRE
}






void Main::affichermain()
{
    std::cout << std::endl;
    Color(0,15);
    std::cout  << "MAIN DU JOUEUR: ";
    Color(15, 0);
    std::cout << std::endl << std::endl;


    for(int i=0; i<m_nbcarte; i++)
    {

        std::cout << i+1 <<". " << std::endl;
        m_main[i]->affichercarte();
        std::cout << std::endl;
    }

}
