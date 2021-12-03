#include "header.h"

Carte::Carte()
{
}


Carte::~Carte()
{
}


Carte::Carte(int type, std::string description, std::string nomcarte,

             ///TYPE MONSTRE
             int pointdevie,

             std::string nomattaqueun,
             int degatattaqueun,
             std::string type_energie_consommeun,
             int coutattaqueun,

             std::string nomattaquedeux,
             int degatattaquedeux,
             std::string type_energie_consommedeux,
             int coutattaquedeux,

             ///TYPE SPECIALE
             int effet,

             ///TYPE ENERGIE
             std::string type_domaine )
{
    m_type=type;
    m_nomcarte=nomcarte;
    m_description=description;

///POUR LES MONSTRES
    m_pointdevie=pointdevie;

    m_degatattaqueun=degatattaqueun;
    m_degatattaquedeux=degatattaquedeux;

    m_type_energie_consommeun=type_energie_consommeun;
    m_type_energie_consommedeux=type_energie_consommedeux;


    m_coutattaqueun=coutattaqueun;
    m_coutattaquedeux=coutattaquedeux;

    m_nomattaqueun=nomattaqueun;
    m_nomattaquedeux=nomattaquedeux;

///POUR LES EFFETS
    m_effet=effet;


///POUR LE DOMAINE
    m_type_domaine=type_domaine;




}


void Carte::affichercarte() const
{

    if (m_type==1)
    {
        ///AFFICHAGE NOM,DESCRIPTION ET POINT DE VIE
        Color(12,0);
        std::cout << m_nomcarte << " :  Type Monstre" << std::endl;
        Color(2,0);
        std::cout << "PV : " << m_pointdevie << std::endl;
        Color(15,0);

        ///AFFICHAGE ATTAQUE 1
        Color(7,0);
        std::cout <<"ATTAQUE 1: " << m_nomattaqueun << std::endl;
        std::cout <<"Cette attaque inflige " << m_degatattaqueun << " degats et coute "
                  <<m_coutattaqueun<< " de l'energie " << m_type_energie_consommeun << std::endl;
        Color(15,0);


        ///AFFICHAGE ATTAQUE 2
        Color(8,0);
        std::cout <<"ATTAQUE 2: " << m_nomattaquedeux << std::endl;
        std::cout <<"Cette attaque inflige " << m_degatattaquedeux << " degats et coute "
                  <<m_coutattaquedeux<< " de l'energie " << m_type_energie_consommedeux << std::endl << std::endl;
        Color(15,0);

        ///OPTIONNELLE POUR UNE DESCRIPTION DU MONSTRE
       //std::cout  <<m_description <<  std::endl;

    }
    if (m_type==2)
    {
        Color(3,0);
        std::cout << m_nomcarte << " :  Type Speciale" << std::endl;
        Color(15,0);
        std::cout  <<m_description << std::endl << std::endl;
    }

    if (m_type==3)
    {
        Color(10, 0);
        std::cout << m_nomcarte << " :  Type Energie " << m_type_domaine << std::endl;
        Color(15,0);
        std::cout  <<m_description << std::endl << std::endl;
    }


}

void Carte::setpointdevie(int degatattaque)
{
    if (m_pointdevie>0)
    {
        m_pointdevie=m_pointdevie-degatattaque;
    }
    if (m_pointdevie<0)
        m_pointdevie=0;
}

void Carte::augmentepvmonstre()
{
    if (m_pointdevie>0)
    {
        m_pointdevie=m_pointdevie +15;
    }
}

void Carte::augmentedegatmonstre()
{
    m_degatattaqueun= m_degatattaqueun + 20;
    m_degatattaquedeux=m_degatattaquedeux + 20;
}


int Carte::gettypecarte() const
{
    return m_type;
}


std::string Carte::gettypedomaine() const
{
    return m_type_domaine;
}

std::string Carte::gettype_domaine_consomme_par_attaqueun() const
{
    return m_type_energie_consommeun;
}


std::string Carte::gettype_domaine_consomme_par_attaquedeux() const
{
    return m_type_energie_consommedeux;
}


int Carte::getdegatattaqueun() const
{
    return m_degatattaqueun;
}

int Carte::getcoutattaqueun() const
{
    return m_coutattaqueun;
}

int Carte::getcoutattaquedeux()const
{
    return m_coutattaquedeux;
}

int Carte::getdegatattaquedeux() const
{
    return m_degatattaquedeux;
}

int Carte::getpointdevie() const
{
    return m_pointdevie;
}


std::string Carte::getdescription() const
{
    return m_description;
}

std::string Carte::getnomcarte() const
{
    return m_nomcarte;
}

std::string Carte::getnomattaqueun() const
{
    return m_nomattaqueun;
}

std::string Carte::getnomattaquedeux() const
{
    return m_nomattaquedeux;
}


int Carte::geteffet() const
{
    return m_effet;
}


