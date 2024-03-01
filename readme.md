PROJET_THÉORIE_DES_LANGAGES_ET_COMPILATION
BARRY Boubacar Sidy                   Groupe1
KHTEIRA Habib                         Groupe3



##Figures:
#problèmes:
La figure "chemin" n'est pas appeler dans la partie c++ du projet.
La déclaration de texte (texte) n'accepte pas la syntaxe spécifiée dans les exemples du projet
#grammaire:
figuresansattr:
    RECTANGLE ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER
    |CARRE ENTIER ENTIER ENTIER
    |TRIANGLE  ENTIER ENTIER ENTIER ENTIER
    |CERCLE ENTIER ENTIER ENTIER
    |ELLIPSE ENTIER ENTIER ENTIER ENTIER
    |LIGNE ENTIER ENTIER ENTIER ENTIER
    |CHEMIN ENTIER ENTIER ',' coords
    |TEXTE ENTIER ENTIER STRING STRING
    
coords:
    ENTIER ENTIER ',' coords
    |ENTIER ENTIER


##Attributs:
#problèmes:
Bien que la grammaire permette de changer les attributs des figures, les modifications ne s'affichent pas correctement dans le fichier SVG généré.
L'attribut "rotation" n'accepte pas la déclaration de forme "rotation : entier °" erreur au niveau de '°'.
#grammaire:
figures:
    figuresansattr
    |figureavecattr

figureavecattr:
    figuresansattr FLECHE ATTRS1
    |figuresansattr '{' NL ATTRS2 '}'

ATTRS1 : 
    ATTR '&' ATTRS1
    |ATTR

ATTRS2 :
    ATTR ';' NL ATTRS2
    |

ATTR :
    ROTATION ':' ENTIER
    |OPACITE ':' ENTIER '%'
    |EPAISSEUR ':' ENTIER
    |COULEUR ':' VAL_COULEUR
    |REMPLISSAGE ':'  VAL_COULEUR
    
VAL_COULEUR:
    RGB '(' NUMBER ',' NUMBER ',' NUMBER ')'
    |COULEURG
    |ROUGE
    | VERT
    | JAUNE
    | BLEU
    | VIOLET
    | MAGENTA
    | CYAN
    | NOIR
    | BLANC
    
    
##Variables:
#problèmes:
Les changements d'attributs à l'aide de variables ne sont pas correctement reflétés dans le fichier SVG.
#grammaire:
affectation:
    STRING '=' figures
    |STRING '=' ENTIER
    |BOOL STRING '=' TRUE 
    |BOOL STRING '=' FALSE 
    |REEL STRING '=' FLOTTANT 
    |VAR_COULEUR '=' VAL_COULEUR 
    |VAR_FIGURE '.' TAILLE '=' ENTIER 
    |VAR_FIGURE '.' LONGUEUR  '=' ENTIER 
    |VAR_FIGURE '.' HAUTEUR  '=' ENTIER 
    |VAR_FIGURE '.' X  '=' ENTIER 
    |VAR_FIGURE '.' Y '=' ENTIER 
    |VAR_FIGURE '.' COULEUR '=' VAL_COULEUR 
    |VAR_FIGURE '.' REMPLISSAGE '=' VAL_COULEUR 
    |VAR_FIGURE '.' EPAISSEUR  '=' ENTIER
    |VAR_FIGURE '.' OPACITE  '=' ENTIER '%'
    |VAR_FIGURE '.' ROTATION  '=' ENTIER
    |VAR_FIGURE '.' X1 '=' ENTIER
    |VAR_FIGURE '.' Y1 '=' ENTIER
    |VAR_FIGURE '.' X2 '=' ENTIER
    |VAR_FIGURE '.' Y2 '=' ENTIER
    |VAR_FIGURE '.' X3 '=' ENTIER
    |VAR_FIGURE '.' Y3 '=' ENTIER
    |VAR_FIGURE '.' X4 '=' ENTIER
    |VAR_FIGURE '.' Y4 '=' ENTIER
    |VAR_FIGURE '.' RAYON '=' ENTIER
    
VAR_COULEUR:
    COULEUR STRING
    |STRING
    
VAR_FIGURE: 
    STRING 
    |CARRE '[' ENTIER ']'
    |RECTANGLE '[' ENTIER ']'
    |TRIANGLE '[' ENTIER ']'
    |ELLIPSE '[' ENTIER ']' 
    |CERCLE '[' ENTIER ']' 
    |TEXTE '[' ENTIER ']'
    |CHEMIN '[' ENTIER ']'
    |LIGNE '[' ENTIER ']'

ENTIER : 
    NUMBER 
    |STRING 
    |ENTIER '*' ENTIER 
    |ENTIER '+' ENTIER 
    |ENTIER '-' ENTIER
    |ENTIER '/' ENTIER
    |'-' ENTIER %prec NEG
    |INT STRING


##Conditions, boucles et fonctions:
#problèmes:
Les instructions dans ces parties de la grammaire contiennent des affectations de type "void", ce qui pose des problèmes d'implémentation.
#grammaire:
functions:
    FONCTION STRING '(' parametres ')' '{' NL instructions '}' NL

boucle:
    REPETE ENTIER FOIS '{' NL instructions '}'
    |WHILE '(' comparaison ')' '{' NL instructions '}'
    
COND:
    SI '(' comparaison ')' ALORS '{' NL instructions '}'
    |SI '(' comparaison ')' ALORS '{' NL instructions  '}' NL SINON '{' NL instructions  '}'
    |SI '(' comparaisons ')' ALORS '{' NL instructions '}'
    |SI '(' comparaisons ')' ALORS '{' NL instructions  '}' NL SINON '{' NL instructions  '}'

instructions:
   figures
   |affectation
   |STRING parametres
   |

parametres:
    STRING parametres 
    |ENTIER parametres 
    
comparaisons:
    '(' comparaison ')' AND comparaisons 
    |'(' comparaison ')' AND '(' comparaison ')' 

comparaison :
    ENTIER EGAL ENTIER 
    |ENTIER DIFF ENTIER 
    |ENTIER INFEG ENTIER 
    |ENTIER SUPEG ENTIER 
    |ENTIER '>' ENTIER 
    |ENTIER '<' ENTIER
    |VAR_COULEUR EST VAL_COULEUR
    |VAR_COULEUR NESTPAS VAL_COULEUR
    

    
    
    

