#include "driver.hh"
#include <iostream>

Driver::Driver() {}
Driver::~Driver() {}


 Contexte& Driver::getContexte() {
    //TODO Retourne le contexte pour qu'il soit accessible en dehors de la classe Driver
    return variables ; 
}

double Driver::getVariable(const std::string & name) const {
    //TODO Retourne la valeur de la variable name
    return variables.getVar(name); 
}

void Driver::setVariable(const std::string & name, double value) {
    //TODO Affecte une valeur à une variable avec l'utilisation du contexte variables
    variables[name] = value ; 
}

void Driver::setFig(const std::string & name, FigurePtr fig) {
    //TODO Affecte une valeur à une variable avec l'utilisation du contexte variables
    variables.insertfigure(name,fig) ; 
}

void Driver::setBool(const std::string & name, bool val) {
    //TODO Affecte une valeur à une variable avec l'utilisation du contexte variables
    variables.insertbool(name,val) ; 
}

void Driver::setCouleur(const std::string & name,  couleur coul) {
    //TODO Affecte une valeur à une variable avec l'utilisation du contexte variables
    variables.insertcouleur(name,coul) ; 
}

FigurePtr Driver::getfig(const std::string & name) const {
    return variables.getFigure(name);
}