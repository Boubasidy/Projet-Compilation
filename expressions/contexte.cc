#include "contexte.hh"

double& Contexte::getVar(const std::string & nom) {
    return variables[nom];
}

const double& Contexte::getVar(const std::string & nom) const {
    return variables.at(nom);
}

FigurePtr& Contexte::getFigure(const std::string & nom) {
    return _figures[nom];
}

const FigurePtr& Contexte::getFigure(const std::string & nom) const {
    return _figures.at(nom);
}

const FigurePtr& Contexte::getCarre(const double indice) const {
   return _carres.at(indice);
}

const FigurePtr& Contexte::getRectangle(const double indice) const {
   return _rectangles.at(indice);
}

const FigurePtr& Contexte::getTriangle(const double indice) const {
   return _triangles.at(indice);
}

const FigurePtr& Contexte::getCercle(const double indice) const {
   return _cercles.at(indice);
}

const FigurePtr& Contexte::getTexte(const double indice) const {
   return _textes.at(indice);
}

const FigurePtr& Contexte::getLigne(const double indice) const {
   return _lignes.at(indice);
}

const FigurePtr& Contexte::getChemin(const double indice) const {
   return _chemins.at(indice);
}

const FigurePtr& Contexte::getEllipse(const double indice) const {
   return _ellipses.at(indice);
}

bool& Contexte::getBool(const std::string & nom) {
    return _bools[nom];
}

const bool& Contexte::getBool(const std::string & nom) const {
    return _bools.at(nom);
}

couleur& Contexte::getCouleur(const std::string & nom) {
    return _couleurs[nom];
}

const couleur& Contexte::getCouleur(const std::string & nom) const {
    return _couleurs.at(nom);
}


double& Contexte::operator[](const std::string & nom) {
    return variables[nom];
}

const double& Contexte::operator[](const std::string & nom) const {
    return variables.at(nom);
}

void Contexte::toxml() {

    std::ofstream svgFile("output.svg");


    std::string xml = "<svg version=\"1.1\"\nwidth=\"1000\" height=\"1000\" \nxmlns=\"http://www.w3.org/2000/svg\">\n";


    for (const auto& figure : _carres) {
        xml += figure->tostring();
    }
    for (const auto& figure : _rectangles) {
        xml += figure->tostring();
    }
    for (const auto& figure : _triangles) {
        xml += figure->tostring();
    }
    for (const auto& figure : _cercles) {
        xml += figure->tostring();
    }
    for (const auto& figure : _ellipses) {
        xml += figure->tostring();
    }
    for (const auto& figure : _lignes) {
        xml += figure->tostring();
    }
    for (const auto& figure : _textes) {
        xml += figure->tostring();
    }
    /*for (const auto& figure : _chemins) {
        xml += figure->tostring();
    }*/
    
    xml += "</svg>\n";
    
    svgFile << xml ; 
    svgFile.close();
    
}
