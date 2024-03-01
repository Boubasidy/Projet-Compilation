#ifndef context_h
#define context_h

#include <string>
#include<vector>
#include<fstream>
#include"figures.hh"


class Contexte {
private:
    std::map<std::string, double> variables;
    std::map<std::string, FigurePtr> _figures;
    std::vector<FigurePtr> _carres;
    std::vector<FigurePtr> _rectangles;
    std::vector<FigurePtr> _triangles;
    std::vector<FigurePtr> _cercles;
    std::vector<FigurePtr> _ellipses;
    std::vector<FigurePtr> _lignes;
    std::vector<FigurePtr> _textes;
    std::vector<FigurePtr> _chemins;

    std::map<std::string, bool> _bools;
    std::map<std::string, couleur> _couleurs;


    attr cont_attr;

    double _longueur;
    double _hauteur;





public:
    attr getattr() { return cont_attr;}
    Contexte() = default;
    Contexte(const Contexte & autre) = default;


    double& getVar(const std::string & nom);
    const double& getVar(const std::string & nom) const;

    FigurePtr& getFigure(const std::string & nom);
    const FigurePtr& getFigure(const std::string & nom) const;

    const FigurePtr& getCarre(const double indice) const;
    const FigurePtr& getRectangle(const double indice) const;
    const FigurePtr& getTriangle(const double indice) const;
    const FigurePtr& getCercle(const double indice) const;
    const FigurePtr& getTexte(const double indice) const;
    const FigurePtr& getLigne(const double indice) const;
    const FigurePtr& getChemin(const double indice) const;
    const FigurePtr& getEllipse(const double indice) const;

    void insertfigure(std::string name, FigurePtr fig) {
        _figures[name] = fig;
    }
    void insertbool(std::string name, bool val) {
        _bools[name] = val;
    }
    void insertcouleur(std::string name, couleur coul) {
        _couleurs[name] = coul;
    }

    void insertCarre(FigurePtr& fig){ _carres.push_back(fig);};
    void insertRectangle(FigurePtr& fig){ _rectangles.push_back(fig);};
    void insertCercle(FigurePtr& fig){ _cercles.push_back(fig);};
    void insertTriangle(FigurePtr& fig){ _triangles.push_back(fig);};
    void insertTexte(FigurePtr& fig){ _textes.push_back(fig);};
    void insertLigne(FigurePtr& fig){ _lignes.push_back(fig);};
    void insertChemin(FigurePtr& fig){ _chemins.push_back(fig);};
    void insertEllipse(FigurePtr& fig){ _ellipses.push_back(fig);};

    void setLongueur(double longue){ _longueur = longue;};

    void setHauteur(double haut){ _hauteur = haut;};

    bool& getBool(const std::string & nom);
    const bool& getBool(const std::string & nom) const;

    couleur& getCouleur(const std::string & nom);
    const couleur& getCouleur(const std::string & nom) const;


    double& operator[](const std::string & nom);
    const double& operator[](const std::string & nom) const;

    void toxml();

};


#endif