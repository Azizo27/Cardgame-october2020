
#include "header.h"

Terrain::Terrain()
{
    m_mana_domaine_un=5;
    m_mana_domaine_deux=5;
    m_mana_domaine_trois=5;
    m_mana_domaine_quatre=5;

    m_nbcartemonstre=0;
}

Terrain::~Terrain()
{

}


void Terrain::posercarte(Carte& card, int& uniqueinvocation, Joueur& j1, Joueur& j2, int& numerotour)
{
    int choix;
    int pvsacrified;
    if (card.gettypecarte()==1)
    {
        m_cartemonstre.push_back(&card);
        m_nbcartemonstre++;

    }
    if (card.gettypecarte()==2)
    {
        ///METTRE ICI LES SOUS PROGRAMMES AVEC LES EFFETS
        if (card.geteffet()==1) //PERMET D INVOQUER UN MONSTRE DE PLUS POUR CE TOUR
        {
            std::cout <<"Vous pouvez invoquer un monstre de plus pour ce tour" << std::endl;
            uniqueinvocation++;
        }
        if (card.geteffet()==2) //faire piocher 2 cartes
        {
            j1.piochcarte();
            j1.piochcarte();
        }
        if (card.geteffet()==3)//Augmenter les PV du joueur
        {
            j1.soinpvjoueur(); //REMARQUE: Si on veut changer la valeur qui soignera le joueur, c est dans cette methode la
        }
        if (card.geteffet()==7) //Empecher le joueur adverse d attaquer
        {
            numerotour=0;
        }

        if (card.geteffet()==4 || card.geteffet()==5 || card.geteffet()==6) //CES CARTES LA NE SERONT JOUE QUE SI IL Y A AU MOINS UN MONSTRE SUR LE TERRAIN:
            //la 4 pour soigner, la 5 pour buffer les degats, la 6 pour sacrifier
        {
            if (m_nbcartemonstre!=0)
            {
                if (m_nbcartemonstre==1)
                {
                    choix=1;
                }

                if (m_nbcartemonstre>1)
                {
                    if (card.geteffet()==4 || card.geteffet()==5)
                    {
                        std::cout << "Choisissez le monstre que vous voulez ameliorer :" << std::endl;
                    }
                    if (card.geteffet()==6)
                    {
                        std::cout << "Choisissez le monstre que vous voulez sacrifier :" << std::endl;
                    }
                    do
                    {
                        std::cin >> choix;
                    }
                    while (choix < 1 || choix> m_nbcartemonstre);

                }

                if (card.geteffet()==4)
                {
                    m_cartemonstre[choix-1]->augmentepvmonstre(); //Ca soigne de 15
                }
                if (card.geteffet()==5)
                {
                    m_cartemonstre[choix-1]->augmentedegatmonstre(); //Ca buffe les attaques de 10
                }
                if (card.geteffet()==6)
                {
                    pvsacrified=m_cartemonstre[choix-1]->getpointdevie();
                    m_cartemonstre[choix-1]->setpointdevie(pvsacrified); //J ai mis les PV à zero pour la forme

                    m_cartemonstre.erase(m_cartemonstre.begin()+ (choix-1));
                    m_nbcartemonstre--;
                    j2.degatsurpvjoueur(pvsacrified);
                }

            }
        }
    }

    if (card.gettypecarte()==3)
    {
        if (card.gettypedomaine()=="MUSIQUE") ///Mettre le nom du domaine 1
        {
            m_mana_domaine_un=m_mana_domaine_un+3;
        }

        if (card.gettypedomaine()=="SPORT") ///Mettre le nom du domaine 2
        {
            m_mana_domaine_deux=m_mana_domaine_deux+3;
        }

        if (card.gettypedomaine()=="FILM/SERIE") ///Mettre le nom du domaine 3
        {
            m_mana_domaine_trois=m_mana_domaine_trois+3;
        }

        if (card.gettypedomaine()=="TECHNOLOGIE") ///Mettre le nom du domaine 4
        {
            m_mana_domaine_quatre=m_mana_domaine_quatre+3;
        }

    }
}





void Terrain::phaseattaque(int& degatattaque, int i)
{
    ///ON VA SUREMENT LE METTRE EN PARAMETRE
    //system("cls");
    printf("\n\n\n\n\n");
    int choix=0;

    if (m_mana_domaine_un==0 && m_mana_domaine_deux==0 && m_mana_domaine_trois==0 && m_mana_domaine_quatre==0)
    {
        std::cout <<"Vous n avez pas de mana. Vous n allez donc pas avoir de phase d attaque." <<std::endl;
        degatattaque=0;
    }

    else
    {
        std::cout <<std::endl;
        Color(0,15);
        std::cout << "LE MONSTRE DE L'ATTAQUANT UTILISE POUR CE COUP :";
        Color(15, 0);
        std::cout << std::endl << std::endl;

        m_cartemonstre[i]->affichercarte(); //REMARQUE: La carte est forcément un monstre (donc de type 1)
        std::cout <<" Saisissez 1 pour lancer l'attaque 1 et deux pour lancer l'attaque 2." << std::endl;
        std::cout << "Vous pouvez egalement ecrire 0 pour ne pas attaquer et economiser votre mana" << std::endl;
        do
        {
            std::cin >> choix;
            if (choix!=0 && choix!=1 && choix!=2)
               std::cout <<"Votre saisie n'est pas valide" << std::endl;
        }
        while (choix!=0 && choix!=1 && choix!=2);

        if (choix==0)
        {
            degatattaque=0;
        }
        //Le choix de l attaque
        if (choix==1)
        {
            //quel type d energie l attaqueun consomme
            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaqueun()=="MUSIQUE")
            {
                //verification que l attaque peut etre lancé car assez de mana
                if (m_mana_domaine_un>=m_cartemonstre[i]->getcoutattaqueun() && m_mana_domaine_un>0)
                {
                    m_mana_domaine_un=m_mana_domaine_un- m_cartemonstre[i]->getcoutattaqueun();
                    degatattaque=m_cartemonstre[i]->getdegatattaqueun();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaqueun()=="SPORT")
            {
                if (m_mana_domaine_deux>=m_cartemonstre[i]->getcoutattaqueun() && m_mana_domaine_deux>0)
                {
                    m_mana_domaine_deux=m_mana_domaine_deux- m_cartemonstre[i]->getcoutattaqueun();
                    degatattaque=m_cartemonstre[i]->getdegatattaqueun();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaqueun()=="FILM/SERIE")
            {
                if (m_mana_domaine_trois>=m_cartemonstre[i]->getcoutattaqueun() && m_mana_domaine_trois>0)
                {
                    m_mana_domaine_trois=m_mana_domaine_trois- m_cartemonstre[i]->getcoutattaqueun();
                    degatattaque=m_cartemonstre[i]->getdegatattaqueun();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaqueun()=="TECHNOLOGIE")
            {
                //verification que l attaque peut etre lancé car assez de mana
                if (m_mana_domaine_quatre>=m_cartemonstre[i]->getcoutattaqueun() && m_mana_domaine_quatre>0)
                {
                    m_mana_domaine_quatre=m_mana_domaine_quatre- m_cartemonstre[i]->getcoutattaqueun();
                    degatattaque=m_cartemonstre[i]->getdegatattaqueun();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


        }



        //meme chose que pour l attaque1 sauf qu on remplace pour les donnees de l attaque2
        if (choix==2)
        {
            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaquedeux()=="MUSIQUE")
            {
                if (m_mana_domaine_un>=m_cartemonstre[i]->getcoutattaquedeux() && m_mana_domaine_un>0)
                {
                    m_mana_domaine_un=m_mana_domaine_un- m_cartemonstre[i]->getcoutattaquedeux();
                    degatattaque=m_cartemonstre[i]->getdegatattaquedeux();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaquedeux()=="SPORT")
            {
                if (m_mana_domaine_deux>=m_cartemonstre[i]->getcoutattaquedeux() && m_mana_domaine_deux>0)
                {
                    m_mana_domaine_deux=m_mana_domaine_deux- m_cartemonstre[i]->getcoutattaquedeux();
                    degatattaque=m_cartemonstre[i]->getdegatattaquedeux();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaquedeux()=="FILM/SERIE")
            {
                if (m_mana_domaine_trois>=m_cartemonstre[i]->getcoutattaquedeux() && m_mana_domaine_trois>0)
                {
                    m_mana_domaine_trois=m_mana_domaine_trois- m_cartemonstre[i]->getcoutattaquedeux();
                    degatattaque=m_cartemonstre[i]->getdegatattaquedeux();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }


            if (m_cartemonstre[i]->gettype_domaine_consomme_par_attaquedeux()=="TECHNOLOGIE")
            {
                //verification que l attaque peut etre lancé car assez de mana
                if (m_mana_domaine_quatre>=m_cartemonstre[i]->getcoutattaquedeux() && m_mana_domaine_quatre>0)
                {
                    m_mana_domaine_quatre=m_mana_domaine_quatre- m_cartemonstre[i]->getcoutattaquedeux();
                    degatattaque=m_cartemonstre[i]->getdegatattaquedeux();
                }
                else
                {
                    degatattaque=0;
                    std::cout <<"pas assez de mana" << std::endl;
                }
            }

        }

    }
}


///PAS FINI
void Terrain::subirattaque(int& degatattaque)
{

    int choix;
    int temp;
    //QUAND L ADVERSAIRE A QU UNE SEULE CARTE, IL NE CHOISIT PAS QUI ATTAQUER


    if (degatattaque==0)
    {

    }
    else
    {
        if (m_nbcartemonstre!=0)
        {
            if (m_nbcartemonstre==1)
            {
                choix=1;
            }


            if (m_nbcartemonstre>1)
            {
                std::cout << "Choisissez le monstre que vous voulez attaquer :" << std::endl;
                do
                {
                    std::cin >> choix;
                    if (choix < 1 || choix> m_nbcartemonstre)
                        std::cout <<"L'adversaire n'a pas ce nombre de monstre, recommencez votre saisie" <<std::endl;
                }
                while (choix < 1 || choix> m_nbcartemonstre);

            }

            temp=m_cartemonstre[choix-1]->getpointdevie();
            m_cartemonstre[choix-1]->setpointdevie(degatattaque);


            ///POUR LES DEGATS QUE VA SUBIR LE JOUEUR
            if (degatattaque>temp && degatattaque!=0)
                degatattaque=degatattaque-temp;

            else
                degatattaque=0;


            ///DETRUIRE LE MONSTRE SI LES PV SONT A NUL
            if (m_cartemonstre[choix-1]->getpointdevie()==0)
            {
                m_cartemonstre.erase(m_cartemonstre.begin()+ (choix-1));
                m_nbcartemonstre--;
            }
        }
    }

}






void Terrain::afficherterrain(int choixterrain, std::string nom) const
{
    int i;
    //choixterrain: 1 pour l attaquant et 2 pour l attaqué

    if (choixterrain==1)
    {

        Color(0,15);
        std::cout  << "MANA DE "<< nom << "(L'ATTAQUANT):";
        Color(15, 0);
        std::cout << std::endl << std::endl;
        std::cout << "Mana MUSIQUE: " << m_mana_domaine_un<< std::endl;
        std::cout << "Mana SPORT: " << m_mana_domaine_deux<< std::endl;
        std::cout << "Mana FILM/SERIE: " << m_mana_domaine_trois<< std::endl;
        std::cout << "Mana TECHNOLOGIE: " << m_mana_domaine_quatre << std::endl;

        std::cout <<std::endl;
        Color(0,15);
        std::cout << "MONSTRE(S) SUR LE TERRAIN DE "<< nom <<"(L'ATTAQUANT):";
        Color(15, 0);
        std::cout << std::endl << std::endl;
    }

    if (choixterrain==2)
    {
        Color(0,15);
        std::cout <<  "LE TERRAIN DE "<< nom <<"(JOUEUR QUI SUBIT L'ATTAQUE) : ";
        Color(15, 0);
        std::cout << std::endl << std::endl;
    }

    if (m_nbcartemonstre==0)
    {
        std::cout << "Aucune carte monstre active" << std::endl << std::endl;
    }
    if (m_nbcartemonstre>0)
    {

        for(i=0; i<m_nbcartemonstre; i++)
        {

            m_cartemonstre[i]->affichercarte();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
}



int Terrain::getnbcartemonstre() const
{
    return m_nbcartemonstre;
}


int Terrain::getmanaun() const
{
    return m_mana_domaine_un;
}


int Terrain::getmanadeux() const
{
    return m_mana_domaine_deux;
}

int Terrain::getmanatrois() const
{
    return m_mana_domaine_trois;
}

int Terrain::getmanaquatre() const
{
    return m_mana_domaine_quatre;
}
