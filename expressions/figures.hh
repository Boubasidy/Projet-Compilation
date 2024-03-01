#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <memory>
#include <map>

enum class couleur {
    rouge , jaune , vert , cyan , magenta , violet , bleu ,blanc,noire
};

class attr{
    public:
    attr() = default;
    double _epaisseur = 1;
    double _rotation = 0;
    couleur _couleur = couleur::noire;
    couleur _remplissage = couleur::blanc;
    double _opacite = 1;

    void setcouleur(couleur coul){ _couleur = coul;}
    void setRemplissage(couleur coul){ _remplissage = coul;}
    void setrotation(double rot){ _rotation = rot;}
    void setepaisseur(double ep) { _epaisseur = ep;}
    void setopacite(double opa) { _opacite = opa;}


};


class position {
public:
    position( double x ,double y):_x(x),_y(y){};
    double x() const {
        return _x ;
    }
    double y() const {
        return _y;
    }
    void setX(double x) {
        _x = x;
    }
    void setY(double y ){
        _y = y ;
    }
    std::shared_ptr<position> calculer() const {
        return std::make_shared<position>(*this);
    }
private:
    double _x ;
    double _y ;
};


class figure {
public:
   figure(position const & pos):_pos(pos){};
   figure(double x, double y):_pos(position(x,y)){
   };
   virtual std::string typefigure() const {
     return "";
   } ;
   
   void setcouleur(couleur coul){
       _couleur = coul;
   };
   void setRemplissage(couleur coul){
       _remplissage  = coul;
   };
   void setepaisseur(double ep){
       _epaisseur = ep;
   };
   void setrotation(double rot){
       rotation = rot;
   };
   void setopacite(double opa){
       opacite = opa;
   };
   virtual std::shared_ptr<figure> calculer() const {
        return std::make_shared<figure>(*this);
    }
    void setX(double x){
        _pos.setX(x);
    }
    void setY(double y){
        _pos.setY(y);
    }
    void getAttr(attr att){
        _couleur = att._couleur;
        _epaisseur = att._epaisseur;
        opacite = att._opacite;
        rotation = att._rotation;
        _remplissage = att._remplissage;
    }
    couleur getCouleur(){ return _couleur; };
    couleur getRemplissage(){ return _remplissage; };
    double getEpaisseur(){ return _epaisseur; };
    double getRotaion(){ return rotation; };
    double getOpacite(){ return opacite; };

    std::string const getcouleurXML() const{
        switch (_couleur)
        {
        case couleur::rouge:
            return "red";
            break;
        case couleur::jaune:
            return "yellow";
            break;
        case couleur::vert:
            return "green";
            break;
        case couleur::cyan:
            return "cyan";
            break;
        case couleur::magenta:
            return "magenta";
            break;
        case couleur::violet:
            return "purple";
            break;
        case couleur::bleu:
            return "blue";
            break;
        case couleur::blanc:
            return "white";
            break;
        case couleur::noire:
            return "black";
            break;
        default:
            break;
        }
    }

    std::string const getremplissageXML() const{
        switch (_remplissage)
        {
        case couleur::rouge:
            return "red";
            break;
        case couleur::jaune:
            return "yellow";
            break;
        case couleur::vert:
            return "green";
            break;
        case couleur::cyan:
            return "cyan";
            break;
        case couleur::magenta:
            return "magenta";
            break;
        case couleur::violet:
            return "purple";
            break;
        case couleur::bleu:
            return "blue";
            break;
        case couleur::blanc:
            return "none";
            break;
        case couleur::noire:
            return "black";
            break;
        default:
            break;
        }
    }

    virtual std::string tostring() const {
    return "";
    }

    position const & getPos() const {
        return _pos ; 
    }

    std::string const getepaisseurXML() const {
        return std::to_string(_epaisseur);
    }

    std::string const getopaciteXML() const {
        return std::to_string(opacite);
    }

    std::string const getrotationXML() const {
        return "rotate("+std::to_string(rotation)+","+std::to_string(_pos.x())+","+std::to_string(_pos.y())+")";
    }

private:
   position _pos;
   couleur _couleur = couleur::noire ;
   double _epaisseur = 1 ;
   couleur _remplissage = couleur::blanc ;
   double rotation = 0 ;
   double opacite = 1;


};

class rectangle : public figure {
public:
    rectangle (double x, double y , double x2, double y2, double x3, double y3, double x4, double y4);
    std::string typefigure() const override {
        return "R";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<rectangle>(*this);
    }
    void setX1(double x){
        figure::setX(x);
    }
    void setY1(double y){
        figure::setY(y);
    }
    void setX2(double x){
        _pos2.setX(x);
    }
    void setY2(double y){
        _pos2.setY(y);
    }
    void setX3(double x){
        _pos3.setX(x);
    }
    void setY3(double y){
        _pos3.setY(y);
    }
    void setX4(double x){
        _pos4.setX(x);
    }
    void setY4(double y){
        _pos4.setY(y);
    }

    std::string tostring() const override;

    std::string const getwidthXML() const{
        double width = _pos4.x() - _pos2.x();
        return std::to_string(width);
    }

    std::string const getheightXML() const{
        double height = _pos2.y() - _pos4.y();
        return std::to_string(height);
    }
   
private:
    position _pos2 ;
    position _pos3 ;
    position _pos4 ;

};

class carre : public figure {
public:
    carre(double x, double y, double tail);
    std::string typefigure() const override {
        return "C";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<carre>(*this);
    }
    void setTaille(double tail){ _taille = tail; }
    std::string tostring() const override;
    std::string const getTailleXml() const { return std::to_string(_taille);}
private:
   double _taille;
};

class triangle : public figure {
public:
    triangle (double x, double y , double longueur , double haut);
    std::string typefigure() const override {
        return "T";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<triangle>(*this);
    }
    void setLongueur(double longu) { _longueur = longu; }
    void setHauteur(double haut) { _hauteur = haut; }

    std::string tostring() const override;

    std::string const getpointsXML() const{
        double x = getPos().x();
        double y = getPos().y();
        double half = _longueur/2;
        return std::to_string(x-_longueur) + "," + std::to_string(y) + " " + std::to_string(x) + "," + std::to_string(y) + " " + std::to_string(x-half) + "," + std::to_string(y-_hauteur);
    }
private:
    double _longueur ;
    double _hauteur ;
};

class cercle : public figure {
public:
    cercle (double x, double y , double r) : figure(x,y) , _rayon(r){}
    std::string typefigure() const override {
        return "Cer";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<cercle>(*this);
    }
    void setrayon(double ray){
        _rayon = ray;
    }

    std::string tostring() const override;
private:
    double _rayon ;
};

class ellipse : public figure {
public:
    ellipse(double x, double y , double longueur , double haut ): figure(x,y),_longueur(longueur) , _hauteur(haut){}
    
    std::string typefigure() const override {
        return "E";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<ellipse>(*this);
    }
    void setLongueur(double longu) { _longueur = longu; }
    void setHauteur(double haut) { _hauteur = haut; }

    std::string tostring() const override;
private:
    double _longueur ;
    double _hauteur ;

};

class ligne : public figure {
public:
    ligne(double x, double y , double x2, double y2 ) : figure(x,y) , _pos2(position(x2,y2)){}
    std::string typefigure() const override {
        return "L";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<ligne>(*this);
    }

    std::string tostring() const override;
private:
    position _pos2;
};

class chemin : public figure {
public:
    chemin(position const & pos, std::list<position> rest);
    std::string typefigure() const override {
        return "Ch";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<chemin>(*this);
    }

    std::string tostring() const override;
private:
    std::list<position> _resteposition;
};

class texte : public figure {
public:
    texte(double x, double y , std::string &txt , std::string poli);
    std::string typefigure() const override {
        return "Txt";
    }
    std::shared_ptr<figure> calculer() const override {
        return std::make_shared<texte>(*this);
    }

    std::string tostring() const override;
private:
    std::string _texte;
    std::string _police ;
};


using FigurePtr = std::shared_ptr<figure>;
using PositionPtr = std::shared_ptr<position>;
