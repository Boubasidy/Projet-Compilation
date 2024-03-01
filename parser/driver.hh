#ifndef DRIVER_H
#define DRIVER_H

#include <string>

#include "contexte.hh"

class Driver {
private:
    Contexte variables;       

public:
    Driver();
    ~Driver();

    
   Contexte& getContexte();
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);
    FigurePtr getfig(const std::string & name) const;

    void setFig(const std::string & name, FigurePtr fig);

    void setBool(const std::string & name, bool val);
    void setCouleur(const std::string & name,  couleur coul);

  
};

#endif
