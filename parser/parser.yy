%skeleton "lalr1.cc"
%require "3.0"

%defines
%define api.parser.class { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    #include "figures.hh"
    #include "expressionFigure.hh"

    class Scanner;
    class Driver;

}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}



%token                  NL
%token                  END
%token                  RECTANGLE
%token                  CARRE
%token                  TRIANGLE
%token                  CERCLE
%token                  ELLIPSE
%token                  LIGNE 
%token                  CHEMIN
%token                  TEXTE
%token <int>            NUMBER
%token <std::string>    STRING
%token                  FLECHE
%token                  REMPLISSAGE
%token                  COULEUR
%token                  EPAISSEUR
%token                  ROTATION
%token                  OPACITE
%token <bool>           BOOL 
%token <double>          FLOTTANT
%token                  TAILLE
%token                  LONGUEUR
%token                  HAUTEUR
%token                  X
%token                  Y 
%token                  X1
%token                  X2
%token                  X3
%token                  X4
%token                  Y1
%token                  Y2
%token                  Y3
%token                  Y4
%token                  RAYON
%token                  RGB
%token                  ROUGE
%token                  BLEU
%token                  VERT
%token                  JAUNE
%token                  VIOLET
%token                  MAGENTA
%token                  CYAN
%token                  NOIR
%token                  BLANC
%token                  TRUE
%token                  FALSE
%token                  INT
%token                  REEL
%token                  SI
%token                  SINON
%token                  ALORS
%token                  EGAL
%token                  DIFF
%token                  INFEG
%token                  SUPEG
%token                  EST
%token                  NESTPAS
%token                  AND
%token                  WHILE
%token                  REPETE
%token                  FOIS
%token                  FONCTION
%token                  COULEURG

%type <ExpressionPtr> ENTIER
%type <ExpressionPtr> comparaison
%type <ExpressionPtr> comparaisons
%type <std::string> VAR_COULEUR
%type <ExpressionPtr> figuresansattr
%type <ExpressionPtr> figureavecattr
%type <ExpressionPtr> figures
%type <ExpressionPtr> VAR_FIGURE
%type <couleur> VAL_COULEUR

%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

main:
    TAILLE ENTIER ENTIER ';' programme {
        double longueur = $2->calculer(driver.getContexte());
        double hauteur = $3->calculer(driver.getContexte());
        driver.getContexte().setLongueur(longueur);
        driver.getContexte().setHauteur(hauteur);
    }

programme:
    functions programme
    |
    instructions';' NL programme
    |
    boucle NL programme
    |
    COND NL programme
    |
    END ';' NL{
        driver.getContexte().toxml();
        YYACCEPT;
    }
    |
    NL programme

functions:
    FONCTION STRING '(' parametres ')' '{' NL instructions '}' NL

boucle:
    REPETE ENTIER FOIS '{' NL instructions  '}'
    |
    WHILE '(' comparaison ')' '{' NL instructions  '}'
    
COND:
    SI '(' comparaison ')' ALORS '{' NL instructions '}'
    |
    SI '(' comparaisons ')' ALORS '{' NL instructions '}'
    |
    COND NL SINON '{' NL instructions '}'

instructions:
   figures 
   | 
   affectation 
   |
   STRING parametres



affectation:
    STRING '=' figures {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($3);
        FigurePtr fig = figPtr->calculer2();
        driver.setFig($1,fig);
    }
    |
    STRING '=' ENTIER {
        double val = $3->calculer(driver.getContexte());
        driver.setVariable($1,val);
    }
    |
    BOOL STRING '=' TRUE {
        driver.setBool($2,true);

    }
    |
    BOOL STRING '=' FALSE {
        driver.setBool($2,false);
    }
    |
    REEL STRING '=' FLOTTANT {
        driver.setVariable($2,$4);
    }
    |
    VAR_COULEUR '=' VAL_COULEUR {
        driver.setCouleur($1,$3);
    }
    |
    VAR_FIGURE '.' TAILLE '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double tail = $5->calculer(driver.getContexte());
        std::shared_ptr<carre> carrePtr = std::dynamic_pointer_cast<carre>(fig);
        carrePtr->setTaille(tail);
    }
    |
    VAR_FIGURE '.' LONGUEUR  '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double longu = $5->calculer(driver.getContexte());
        if(fig->typefigure() == "T"){
            std::shared_ptr<triangle> trianglePtr = std::dynamic_pointer_cast<triangle>(fig);
            trianglePtr->setLongueur(longu);
        }else{
            std::shared_ptr<ellipse> ellipsePtr = std::dynamic_pointer_cast<ellipse>(fig);
            ellipsePtr->setLongueur(longu);
        }
    }
    |
    VAR_FIGURE '.' HAUTEUR  '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double haut = $5->calculer(driver.getContexte());
        if(fig->typefigure() == "T"){
            std::shared_ptr<triangle> trianglePtr = std::dynamic_pointer_cast<triangle>(fig);
            trianglePtr->setHauteur(haut);
        }else{
            std::shared_ptr<ellipse> ellipsePtr = std::dynamic_pointer_cast<ellipse>(fig);
            ellipsePtr->setHauteur(haut);
        }
    }
    |
    VAR_FIGURE '.' X  '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double x = $5->calculer(driver.getContexte());
        fig->setX(x);
    }
    |
    VAR_FIGURE '.' Y '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double y = $5->calculer(driver.getContexte());
        fig->setY(y);
    }
    |
    VAR_FIGURE '.' COULEUR '=' VAL_COULEUR {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        fig->setcouleur($5);
    }
    |
    VAR_FIGURE '.' REMPLISSAGE '=' VAL_COULEUR {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        fig->setRemplissage($5);
    }
    |
    VAR_FIGURE '.' EPAISSEUR  '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double x = $5->calculer(driver.getContexte());
        fig->setepaisseur(x);
    }
    |
    VAR_FIGURE '.' OPACITE  '=' ENTIER '%' {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double x = $5->calculer(driver.getContexte());
        fig->setopacite(x);
    }
    |
    VAR_FIGURE '.' ROTATION  '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        double x = $5->calculer(driver.getContexte());
        fig->setrotation(x);
    }
    |
    VAR_FIGURE '.' X1 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = $5->calculer(driver.getContexte());
        rectPtr->setX1(x);
    }
    |
    VAR_FIGURE '.' Y1 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = $5->calculer(driver.getContexte());
        rectPtr->setY1(y);
    }
    |
    VAR_FIGURE '.' X2 '=' ENTIER {
       std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = $5->calculer(driver.getContexte());
        rectPtr->setX2(x);
    }
    |
    VAR_FIGURE '.' Y2 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = $5->calculer(driver.getContexte());
        rectPtr->setY2(y);
    }
    |
    VAR_FIGURE '.' X3 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = $5->calculer(driver.getContexte());
        rectPtr->setX3(x);
    }
    |
    VAR_FIGURE '.' Y3 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = $5->calculer(driver.getContexte());
        rectPtr->setY4(y);
    }
    |
    VAR_FIGURE '.' X4 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = $5->calculer(driver.getContexte());
        rectPtr->setY4(x);
    }
    |
    VAR_FIGURE '.' Y4 '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = $5->calculer(driver.getContexte());
        rectPtr->setY4(y);
    }
    |
    VAR_FIGURE '.' RAYON '=' ENTIER {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<cercle> cerclePtr = std::dynamic_pointer_cast<cercle>(fig);

        double ray = $5->calculer(driver.getContexte());
        cerclePtr->setrayon(ray);
    }

comparaisons:
    '(' comparaison ')' AND comparaisons {
        $$=std::make_shared<ExpressionBinaire>($2,$5,OperateurBinaire::et);
    }
    |
    '(' comparaison ')' AND '(' comparaison ')' {
        $$=std::make_shared<ExpressionBinaire>($2,$6,OperateurBinaire::et);
    }

comparaison :
    ENTIER EGAL ENTIER {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::egal);
    }
    |
    ENTIER DIFF ENTIER {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::different);
    }
    |
    ENTIER INFEG ENTIER {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::infeg);
    }
    |
    ENTIER SUPEG ENTIER {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::supeg);
    }
    |
    ENTIER '>' ENTIER {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::inf);
    }
    |
    ENTIER '<' ENTIER {
        $$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::sup);
    }
    |
    VAR_COULEUR EST VAL_COULEUR {
        //$$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::est);
    }
    |
    VAR_COULEUR NESTPAS VAL_COULEUR {
        //$$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::nestpas);
    }
    
figures:
    figuresansattr{
        $$ = $1;
    }
    |
    figureavecattr{
        $$ = $1;
    }

VAR_COULEUR:
    COULEUR STRING {
        $$ = $2;
    }
    |
    STRING {
        $$ = $1;
    }


VAR_FIGURE: 
    STRING {
        FigurePtr fig = driver.getfig($1);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    | 
    CARRE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getCarre(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    RECTANGLE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getRectangle(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    TRIANGLE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getTriangle(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    ELLIPSE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getEllipse(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    CERCLE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getCercle(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    TEXTE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getTexte(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    CHEMIN '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getChemin(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    LIGNE '[' ENTIER ']' {
        double indice = $3->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getLigne(indice);
        $$ = std::make_shared<expressionFigure>(fig);
    }


    





figureavecattr:
    figuresansattr FLECHE ATTRS1 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        fig->getAttr(driver.getContexte().getattr());
        $$ = std::make_shared<expressionFigure>(fig);
    }
    |
    figuresansattr '{' NL ATTRS2 '}' {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>($1);
        FigurePtr fig = figPtr->calculer2();
        fig->getAttr(driver.getContexte().getattr());
        $$ = std::make_shared<expressionFigure>(fig);
    }


figuresansattr:
    RECTANGLE ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());
        double x2 = $4->calculer(driver.getContexte());
        double y2 = $5->calculer(driver.getContexte());
        double x3 = $6->calculer(driver.getContexte());
        double y3 = $7->calculer(driver.getContexte());
        double x4 = $8->calculer(driver.getContexte());
        double y4 = $9->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<rectangle>(x,y,x2,y2,x3,y3,x4,y4);
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertRectangle(fig);
    }
    |
    CARRE ENTIER ENTIER ENTIER {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());
        double tail1 = $4->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<carre>(x,y,tail1);
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertCarre(fig);
    }
    |
    TRIANGLE  ENTIER ENTIER ENTIER ENTIER  {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());
        double longu = $4->calculer(driver.getContexte());
        double haut = $5->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<triangle>(x,y,longu, haut);
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertTriangle(fig);
    }
    |
    CERCLE ENTIER ENTIER ENTIER {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());
        double ray = $4->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<cercle>(x,y,ray);
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertCercle(fig);
    }
    |
    ELLIPSE ENTIER ENTIER ENTIER ENTIER {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());
        double longu = $4->calculer(driver.getContexte());
        double haut = $5->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<ellipse>(x,y,longu, haut); 
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertEllipse(fig);
    }
    |
    LIGNE ENTIER ENTIER ENTIER ENTIER {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());
        double x2 = $4->calculer(driver.getContexte());
        double y2 = $5->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<ligne>(x,y,x2,y2);
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertLigne(fig);
    }
    |
    CHEMIN ENTIER ENTIER ',' coords
    |
    TEXTE ENTIER ENTIER STRING STRING {
        double x = $2->calculer(driver.getContexte());
        double y = $3->calculer(driver.getContexte());

        FigurePtr fig = std::make_shared<texte>(x,y,$4,$5);
        $$ = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertTexte(fig);
    }
    
coords:
    ENTIER ENTIER ',' coords
    |
    ENTIER ENTIER

ATTRS1 : 
    ATTR '&' ATTRS1
    | 
    ATTR

ATTRS2 :
    ATTR ';' NL ATTRS2
    |

ATTR :
    ROTATION ':' ENTIER {
        double rot = $3->calculer(driver.getContexte());
        driver.getContexte().getattr().setrotation(rot);  
    }
    |
    OPACITE ':' ENTIER '%' {
        double opa = $3->calculer(driver.getContexte());
        driver.getContexte().getattr().setopacite(opa);  
    }
    |
    EPAISSEUR ':' ENTIER {
        double ep = $3->calculer(driver.getContexte());
        driver.getContexte().getattr().setepaisseur(ep);  
    }
    |
    COULEUR ':' VAL_COULEUR {
        driver.getContexte().getattr().setcouleur($3); 
    }
    |
    REMPLISSAGE ':'  VAL_COULEUR {
        driver.getContexte().getattr().setRemplissage($3);
    }

ENTIER : 
    NUMBER {
        $$ = std::make_shared<Constante>($1);
    }
    |
    STRING {
        $$ = std::make_shared<Variable>($1);
    }
    |
    ENTIER '*' ENTIER {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::multiplie);
    }
    |
    ENTIER '+' ENTIER {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::plus);
    }
    |
    ENTIER '-' ENTIER {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::moins);
    }
    |
    ENTIER '/' ENTIER {
        $$ = std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::divise);
    }
    |
    '-' ENTIER %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2,OperateurUnaire::neg);
    }
    |
    INT STRING {
        $$ = std::make_shared<Variable>($2);
    }
 
parametres:
    STRING parametres 
    | 
    ENTIER parametres 

VAL_COULEUR:
    RGB '(' NUMBER ',' NUMBER ',' NUMBER ')' {
        $$ = couleur::noire;
    }
    |
    COULEURG {
        $$ = couleur::noire;
    }
    |ROUGE  {
        $$ = couleur::rouge;
    }
    | VERT {
        $$ = couleur::vert;
    }
    | JAUNE {
        $$ = couleur::jaune;
    }
    | BLEU {
        $$ = couleur::bleu;
    }
    | VIOLET {
        $$ = couleur::violet;
    }
    | MAGENTA {
        $$ = couleur::magenta;
    }
    | CYAN {
        $$ = couleur::cyan;
    }
    | NOIR {
        $$ = couleur::noire;
    }
    | BLANC{
        $$ = couleur::blanc;
    }
 

%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}

