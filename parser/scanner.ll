%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%option caseless

%%
%{
    yylval = lval;
%}



fin {return token::END;}
(?i:rectangle) {return token::RECTANGLE;}
(?i:carré) {return token::CARRE;}
(?i:triangle) {return token::TRIANGLE;}
(?i:cercle) {return token::CERCLE;}
(?i:ellipse) {return token::ELLIPSE;}
(?i:ligne) {return token::LIGNE;} 
(?i:chemin) {return token::CHEMIN;}
(?i:texte) {return token::TEXTE;}

(?i:couleur) {return token::COULEUR;}
(?i:rotation) {return token::ROTATION;}
(?i:remplissage) {return token::REMPLISSAGE;}
(?i:opacité) {return token::OPACITE;}
(?i:épaisseur) {return token::EPAISSEUR;}
(?i:booléen) {return token::BOOL;}
(?i:entier) {return token::INT;}
(?i:réel) {return token::REEL;}
(?i:positionX) {return token::X;}
(?i:positionY) {return token::Y;}
(?i:positionX1) {return token::X1;}
(?i:positionX2) {return token::X2;}
(?i:positionX3) {return token::X3;}
(?i:positionX4) {return token::X4;}
(?i:positionY1) {return token::Y1;}
(?i:positionY2) {return token::Y2;}
(?i:positionY3) {return token::Y3;}
(?i:positionY4) {return token::Y4;}
(?i:taille) {return token::TAILLE;}
(?i:hauteur) {return token::HAUTEUR;}
(?i:longueur) {return token::LONGUEUR;}
(?i:rayon) {return token::RAYON;}
(?i:true) {return token::TRUE;}
(?i:false) {return token::FALSE;}
(?i:rgb) {return token::RGB;}
(?i:rouge) {return token::ROUGE;}
(?i:bleu) {return token::BLEU;}
(?i:vert) {return token::VERT;}
(?i:jaune) {return token::JAUNE;}
(?i:violet) {return token::VIOLET;}
(?i:magenta) {return token::MAGENTA;}
(?i:cyan) {return token::CYAN;}
(?i:noire) {return token::NOIR;}
(?i:blanc) {return token::BLANC;}
(?i:si) {return token::SI;}
(?i:sinon) { return token::SINON;}
(?i:alors) { return token::ALORS;}
(?i:est) { return token::EST;}
"n'est pas" { return token::NESTPAS;}
"tant que" { return token::WHILE;}
"repete" { return token::REPETE;}
"fois" { return token::FOIS;}
(?i:fonction) { return token::FONCTION;}

"==" { return token::EGAL;}
"!=" { return token::DIFF;}
"<=" { return token::INFEG;}
">=" { return token::SUPEG;}
"&&" { return token::AND;}


"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';
":" return ':';
";" return ';';
"," return ','; 
"{" return  '{';
"}" return '}'; 
"&" return '&'; 
"." return '.';
"[" return '[';
"]" return ']' ; 
"->" return token::FLECHE;
"#" return '#';
">" return '>';
"<" return '<';
"%" return '%';
""" return '"';

[0-9]+\.[0-9]+ {
    yylval->build<double>(std::atof(yytext));
    return token::FLOTTANT;
} 
[0-9]+    {
    yylval->build<int>(std::atof(YYText()));
    return token::NUMBER;
}
#[A-Z0-9]{6} {
    return token::COULEURG;
}
[a-zA-Z0-9]+ {
     yylval->build<std::string>(YYText()); 
    return token::STRING; 
}


"\n"          {
    loc->lines();
    return token::NL;
}

%%
