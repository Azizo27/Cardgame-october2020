#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <iostream>


class Carte
{
private:
    int m_type; //type==1 pour Monstre, 2 pour speciale et 3 pour energie
    std::string m_description;
    std::string m_nomcarte;

    ///POUR LE TYPE MONSTRE:
    int m_pointdevie;

    int m_degatattaqueun;
    std::string m_nomattaqueun;
    std::string m_type_energie_consommeun;
    int m_coutattaqueun;


    int m_degatattaquedeux;
    std::string m_nomattaquedeux;
    std::string m_type_energie_consommedeux;
    int m_coutattaquedeux;

    ///POUR LE TYPE SPECIALE:
    int m_effet; //si effet==0, faire piocher, si effet==1, augmenter les point de vie...


    ///POUR LE TYPE ENERGIE:
    std::string m_type_domaine; //On pourrait l enlever en récuperant simplement le nom de la carte

public:
    Carte();

    Carte(int type, std::string description, std::string nomcarte,

          int pointdevie,

          std::string nomattaqueun,
          int degatattaqueun,
          std::string type_energie_consommeun,
          int coutattaqueun,

          std::string nomattaquedeux,
          int degatattaquedeux,
          std::string type_energie_consommedeux,
          int coutattaquedeux,

          int effet,

          std::string type_domaine);

    ~Carte();

    void affichercarte() const;



    std::string getdescription() const;
    std::string getnomcarte() const;
    std::string getnomattaqueun() const;
    std::string getnomattaquedeux() const;
    int geteffet() const;


    int gettypecarte() const;

    int getpointdevie() const;

    int getdegatattaqueun() const;
    int getdegatattaquedeux() const;

    int getcoutattaqueun() const;
    int getcoutattaquedeux() const;

    std::string gettype_domaine_consomme_par_attaqueun() const;
    std::string gettype_domaine_consomme_par_attaquedeux() const;

    std::string gettypedomaine() const;

    void setpointdevie(int degatattaque);

    void augmentepvmonstre();
    void augmentedegatmonstre();



};





#endif // CARTE_H_INCLUDED
