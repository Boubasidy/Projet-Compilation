#include "figures.hh"
rectangle::rectangle(double x, double y , double x2, double y2, double x3, double y3, double x4, double y4)
    :figure(x,y) , _pos2(position(x2,y2)) , _pos3(position(x3,y3)),_pos4(position(x4,y4)){
    }
carre::carre(double x, double y, double tail)
    :figure(x,y) , _taille(tail){

}
triangle::triangle(double x, double y, double longueur , double haut)
    :figure(x,y) ,_longueur(longueur) , _hauteur(haut) {
    }

chemin::chemin(const position &pos, std::list<position> rest)
    :figure(pos) , _resteposition(rest){
}
texte::texte(double x, double y, std::string &txt, std::string poli)
    :figure(x,y) , _texte(txt) , _police(poli){
}
std::string carre::tostring() const {
    std::string ss = "<rect x=\"" + std::to_string(getPos().x()) + "\" y=\"" + std::to_string(getPos().y()) + "\" width=\"" + getTailleXml() + "\" height=\"" + getTailleXml() + "\" stroke=\"" + getcouleurXML() + "\" fill=\"" + getremplissageXML() + "\" strock-width=\"" + getepaisseurXML() + "\" opacity=\"" + getopaciteXML() + "\" transforme=\"" + getrotationXML() +"\"/>\n";
    return ss;
}

std::string rectangle::tostring() const {
    std::string ss = "<rect x=\"" + std::to_string(getPos().x()) + "\" y=\"" + std::to_string(getPos().y()) + "\" width=\"" + getwidthXML() + "\" height=\"" + getheightXML() + "\" stroke=\"" + getcouleurXML() + "\" fill=\"" + getremplissageXML() + "\" strock-width=\"" + getepaisseurXML() + "\" opacity=\"" + getopaciteXML() + "\" transforme=\"" + getrotationXML() + "\"/>\n";
    return ss;
}


std::string triangle::tostring() const {
    std::string ss = "<polygon points=\"" + getpointsXML() + "\" stroke=\"" + getcouleurXML() + "\" fill=\"" + getremplissageXML() + "\" strock-width=\"" + getepaisseurXML() + "\" opacity=\"" + getopaciteXML() + "\" transforme=\"" + getrotationXML() + "\"/>\n";
    return ss;
}

std::string cercle::tostring() const {
    std::string ss = "<circle cx=\"" + std::to_string(getPos().x()) + "\" cy=\"" + std::to_string(getPos().y()) + "\" r=\"" + std::to_string(_rayon) + "\" stroke=\"" + getcouleurXML() + "\" fill=\"" + getremplissageXML() + "\" strock-width=\"" + getepaisseurXML() + "\" opacity=\"" + getopaciteXML() + "\"/>\n";
    return ss;
}

std::string ellipse::tostring() const {
    std::string ss = "<ellipse cx=\"" + std::to_string(getPos().x()) + "\" cy=\"" + std::to_string(getPos().y()) + "\" rx=\"" + std::to_string(_longueur / 2) + "\" ry=\"" + std::to_string(_hauteur / 2) + "\" stroke=\"" + getcouleurXML() + "\" fill=\"" + getremplissageXML() + "\" strock-width=\"" + getepaisseurXML() + "\" opacity=\"" + getopaciteXML() + "\" transforme=\"" + getrotationXML() + "\"/>\n";
    return ss;
}

std::string ligne::tostring() const {
    std::string ss = "<line x1=\"" + std::to_string(getPos().x()) + "\" y1=\"" + std::to_string(getPos().y()) + "\" x2=\"" + std::to_string(_pos2.x()) + "\" y2=\"" + std::to_string(_pos2.y())  + "\" stroke=\"" + getcouleurXML() + "\" strock-width=\"" + getepaisseurXML() + "\" opacity=\"" + getopaciteXML() + "\" transforme=\"" + getrotationXML() + "\"/>\n";
    return ss;
}

std::string texte::tostring() const {
    std::string ss = "<text x=\"" + std::to_string(getPos().x()) + "\" y=\"" + std::to_string(getPos().y()) + "\" font-family=\"" + _police + "\">" + _texte + "</text>\n";
    return ss;
}

std::string chemin::tostring() const {
    /*
    std::string ss = "<path d=\"";
    for (const auto& pos : _resteposition) {
        ss += "M" + std::to_string(pos.x()) + "," + std::to_string(pos.y()) + " ";
    }
    ss += "\" stroke=\"" + getCouleur() + "\" fill=\"" + getRemplissage() + "\"/>\n";
    return ss;*/
    return "";
}
