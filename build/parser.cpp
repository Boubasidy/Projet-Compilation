// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 28 "parser/parser.yy"

    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 57 "/home/etud/Bureau/compilation/build/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 149 "/home/etud/Bureau/compilation/build/parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        value.copy< couleur > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        value.move< couleur > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        value.YY_MOVE_OR_COPY< couleur > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        value.move< couleur > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        value.copy< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        value.copy< couleur > (that.value);
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        value.move< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        value.move< couleur > (that.value);
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_comparaisons: // comparaisons
      case symbol_kind::S_comparaison: // comparaison
      case symbol_kind::S_figures: // figures
      case symbol_kind::S_VAR_FIGURE: // VAR_FIGURE
      case symbol_kind::S_figureavecattr: // figureavecattr
      case symbol_kind::S_figuresansattr: // figuresansattr
      case symbol_kind::S_ENTIER: // ENTIER
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_VAL_COULEUR: // VAL_COULEUR
        yylhs.value.emplace< couleur > ();
        break;

      case symbol_kind::S_FLOTTANT: // FLOTTANT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR_COULEUR: // VAR_COULEUR
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // main: TAILLE ENTIER ENTIER ';' programme
#line 122 "parser/parser.yy"
                                       {
        double longueur = yystack_[3].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double hauteur = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.getContexte().setLongueur(longueur);
        driver.getContexte().setHauteur(hauteur);
    }
#line 855 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 6: // programme: END ';' NL
#line 138 "parser/parser.yy"
              {
        driver.getContexte().toxml();
        YYACCEPT;
    }
#line 864 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 15: // affectation: STRING '=' figures
#line 170 "parser/parser.yy"
                       {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[0].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        driver.setFig(yystack_[2].value.as < std::string > (),fig);
    }
#line 874 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 16: // affectation: STRING '=' ENTIER
#line 176 "parser/parser.yy"
                      {
        double val = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.setVariable(yystack_[2].value.as < std::string > (),val);
    }
#line 883 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 17: // affectation: BOOL STRING '=' TRUE
#line 181 "parser/parser.yy"
                         {
        driver.setBool(yystack_[2].value.as < std::string > (),true);

    }
#line 892 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 18: // affectation: BOOL STRING '=' FALSE
#line 186 "parser/parser.yy"
                          {
        driver.setBool(yystack_[2].value.as < std::string > (),false);
    }
#line 900 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 19: // affectation: REEL STRING '=' FLOTTANT
#line 190 "parser/parser.yy"
                             {
        driver.setVariable(yystack_[2].value.as < std::string > (),yystack_[0].value.as < double > ());
    }
#line 908 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 20: // affectation: VAR_COULEUR '=' VAL_COULEUR
#line 194 "parser/parser.yy"
                                {
        driver.setCouleur(yystack_[2].value.as < std::string > (),yystack_[0].value.as < couleur > ());
    }
#line 916 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 21: // affectation: VAR_FIGURE '.' TAILLE '=' ENTIER
#line 198 "parser/parser.yy"
                                     {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double tail = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        std::shared_ptr<carre> carrePtr = std::dynamic_pointer_cast<carre>(fig);
        carrePtr->setTaille(tail);
    }
#line 928 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 22: // affectation: VAR_FIGURE '.' LONGUEUR '=' ENTIER
#line 206 "parser/parser.yy"
                                        {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double longu = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        if(fig->typefigure() == "T"){
            std::shared_ptr<triangle> trianglePtr = std::dynamic_pointer_cast<triangle>(fig);
            trianglePtr->setLongueur(longu);
        }else{
            std::shared_ptr<ellipse> ellipsePtr = std::dynamic_pointer_cast<ellipse>(fig);
            ellipsePtr->setLongueur(longu);
        }
    }
#line 945 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 23: // affectation: VAR_FIGURE '.' HAUTEUR '=' ENTIER
#line 219 "parser/parser.yy"
                                       {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double haut = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        if(fig->typefigure() == "T"){
            std::shared_ptr<triangle> trianglePtr = std::dynamic_pointer_cast<triangle>(fig);
            trianglePtr->setHauteur(haut);
        }else{
            std::shared_ptr<ellipse> ellipsePtr = std::dynamic_pointer_cast<ellipse>(fig);
            ellipsePtr->setHauteur(haut);
        }
    }
#line 962 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 24: // affectation: VAR_FIGURE '.' X '=' ENTIER
#line 232 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        fig->setX(x);
    }
#line 973 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 25: // affectation: VAR_FIGURE '.' Y '=' ENTIER
#line 239 "parser/parser.yy"
                                {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double y = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        fig->setY(y);
    }
#line 984 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 26: // affectation: VAR_FIGURE '.' COULEUR '=' VAL_COULEUR
#line 246 "parser/parser.yy"
                                           {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        fig->setcouleur(yystack_[0].value.as < couleur > ());
    }
#line 994 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 27: // affectation: VAR_FIGURE '.' REMPLISSAGE '=' VAL_COULEUR
#line 252 "parser/parser.yy"
                                               {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        fig->setRemplissage(yystack_[0].value.as < couleur > ());
    }
#line 1004 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 28: // affectation: VAR_FIGURE '.' EPAISSEUR '=' ENTIER
#line 258 "parser/parser.yy"
                                         {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        fig->setepaisseur(x);
    }
#line 1015 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 29: // affectation: VAR_FIGURE '.' OPACITE '=' ENTIER '%'
#line 265 "parser/parser.yy"
                                           {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[5].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double x = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        fig->setopacite(x);
    }
#line 1026 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 30: // affectation: VAR_FIGURE '.' ROTATION '=' ENTIER
#line 272 "parser/parser.yy"
                                        {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        fig->setrotation(x);
    }
#line 1037 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 31: // affectation: VAR_FIGURE '.' X1 '=' ENTIER
#line 279 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setX1(x);
    }
#line 1050 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 32: // affectation: VAR_FIGURE '.' Y1 '=' ENTIER
#line 288 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setY1(y);
    }
#line 1063 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 33: // affectation: VAR_FIGURE '.' X2 '=' ENTIER
#line 297 "parser/parser.yy"
                                 {
       std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setX2(x);
    }
#line 1076 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 34: // affectation: VAR_FIGURE '.' Y2 '=' ENTIER
#line 306 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setY2(y);
    }
#line 1089 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 35: // affectation: VAR_FIGURE '.' X3 '=' ENTIER
#line 315 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setX3(x);
    }
#line 1102 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 36: // affectation: VAR_FIGURE '.' Y3 '=' ENTIER
#line 324 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setY4(y);
    }
#line 1115 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 37: // affectation: VAR_FIGURE '.' X4 '=' ENTIER
#line 333 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double x = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setY4(x);
    }
#line 1128 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 38: // affectation: VAR_FIGURE '.' Y4 '=' ENTIER
#line 342 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<rectangle> rectPtr = std::dynamic_pointer_cast<rectangle>(fig);

        double y = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        rectPtr->setY4(y);
    }
#line 1141 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 39: // affectation: VAR_FIGURE '.' RAYON '=' ENTIER
#line 351 "parser/parser.yy"
                                    {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        std::shared_ptr<cercle> cerclePtr = std::dynamic_pointer_cast<cercle>(fig);

        double ray = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        cerclePtr->setrayon(ray);
    }
#line 1154 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 40: // comparaisons: '(' comparaison ')' AND comparaisons
#line 361 "parser/parser.yy"
                                         {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[3].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::et);
    }
#line 1162 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 41: // comparaisons: '(' comparaison ')' AND '(' comparaison ')'
#line 365 "parser/parser.yy"
                                                {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[5].value.as < ExpressionPtr > (),yystack_[1].value.as < ExpressionPtr > (),OperateurBinaire::et);
    }
#line 1170 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 42: // comparaison: ENTIER EGAL ENTIER
#line 370 "parser/parser.yy"
                       {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::egal);
    }
#line 1178 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 43: // comparaison: ENTIER DIFF ENTIER
#line 374 "parser/parser.yy"
                       {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::different);
    }
#line 1186 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 44: // comparaison: ENTIER INFEG ENTIER
#line 378 "parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::infeg);
    }
#line 1194 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 45: // comparaison: ENTIER SUPEG ENTIER
#line 382 "parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::supeg);
    }
#line 1202 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 46: // comparaison: ENTIER '>' ENTIER
#line 386 "parser/parser.yy"
                      {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::inf);
    }
#line 1210 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 47: // comparaison: ENTIER '<' ENTIER
#line 390 "parser/parser.yy"
                      {
        yylhs.value.as < ExpressionPtr > ()=std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::sup);
    }
#line 1218 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 48: // comparaison: VAR_COULEUR EST VAL_COULEUR
#line 394 "parser/parser.yy"
                                {
        //$$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::est);
    }
#line 1226 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 49: // comparaison: VAR_COULEUR NESTPAS VAL_COULEUR
#line 398 "parser/parser.yy"
                                    {
        //$$=std::make_shared<ExpressionBinaire>($1,$3,OperateurBinaire::nestpas);
    }
#line 1234 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 50: // figures: figuresansattr
#line 403 "parser/parser.yy"
                  {
        yylhs.value.as < ExpressionPtr > () = yystack_[0].value.as < ExpressionPtr > ();
    }
#line 1242 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 51: // figures: figureavecattr
#line 407 "parser/parser.yy"
                  {
        yylhs.value.as < ExpressionPtr > () = yystack_[0].value.as < ExpressionPtr > ();
    }
#line 1250 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 52: // VAR_COULEUR: COULEUR STRING
#line 412 "parser/parser.yy"
                   {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 1258 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 53: // VAR_COULEUR: STRING
#line 416 "parser/parser.yy"
           {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 1266 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 54: // VAR_FIGURE: STRING
#line 422 "parser/parser.yy"
           {
        FigurePtr fig = driver.getfig(yystack_[0].value.as < std::string > ());
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1275 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 55: // VAR_FIGURE: CARRE '[' ENTIER ']'
#line 427 "parser/parser.yy"
                         {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getCarre(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1285 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 56: // VAR_FIGURE: RECTANGLE '[' ENTIER ']'
#line 433 "parser/parser.yy"
                             {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getRectangle(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1295 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 57: // VAR_FIGURE: TRIANGLE '[' ENTIER ']'
#line 439 "parser/parser.yy"
                            {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getTriangle(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1305 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 58: // VAR_FIGURE: ELLIPSE '[' ENTIER ']'
#line 445 "parser/parser.yy"
                           {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getEllipse(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1315 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 59: // VAR_FIGURE: CERCLE '[' ENTIER ']'
#line 451 "parser/parser.yy"
                          {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getCercle(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1325 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 60: // VAR_FIGURE: TEXTE '[' ENTIER ']'
#line 457 "parser/parser.yy"
                         {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getTexte(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1335 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 61: // VAR_FIGURE: CHEMIN '[' ENTIER ']'
#line 463 "parser/parser.yy"
                          {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getChemin(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1345 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 62: // VAR_FIGURE: LIGNE '[' ENTIER ']'
#line 469 "parser/parser.yy"
                         {
        double indice = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = driver.getContexte().getLigne(indice);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1355 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 63: // figureavecattr: figuresansattr FLECHE ATTRS1
#line 483 "parser/parser.yy"
                                 {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[2].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        fig->getAttr(driver.getContexte().getattr());
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1366 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 64: // figureavecattr: figuresansattr '{' NL ATTRS2 '}'
#line 490 "parser/parser.yy"
                                     {
        std::shared_ptr<expressionFigure> figPtr = std::dynamic_pointer_cast<expressionFigure>(yystack_[4].value.as < ExpressionPtr > ());
        FigurePtr fig = figPtr->calculer2();
        fig->getAttr(driver.getContexte().getattr());
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
    }
#line 1377 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 65: // figuresansattr: RECTANGLE ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER ENTIER
#line 499 "parser/parser.yy"
                                                                      {
        double x = yystack_[7].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[6].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double x2 = yystack_[5].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y2 = yystack_[4].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double x3 = yystack_[3].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y3 = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double x4 = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y4 = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<rectangle>(x,y,x2,y2,x3,y3,x4,y4);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertRectangle(fig);
    }
#line 1395 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 66: // figuresansattr: CARRE ENTIER ENTIER ENTIER
#line 513 "parser/parser.yy"
                               {
        double x = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double tail1 = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<carre>(x,y,tail1);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertCarre(fig);
    }
#line 1408 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 67: // figuresansattr: TRIANGLE ENTIER ENTIER ENTIER ENTIER
#line 522 "parser/parser.yy"
                                           {
        double x = yystack_[3].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double longu = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double haut = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<triangle>(x,y,longu, haut);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertTriangle(fig);
    }
#line 1422 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 68: // figuresansattr: CERCLE ENTIER ENTIER ENTIER
#line 532 "parser/parser.yy"
                                {
        double x = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double ray = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<cercle>(x,y,ray);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertCercle(fig);
    }
#line 1435 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 69: // figuresansattr: ELLIPSE ENTIER ENTIER ENTIER ENTIER
#line 541 "parser/parser.yy"
                                        {
        double x = yystack_[3].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double longu = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double haut = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<ellipse>(x,y,longu, haut); 
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertEllipse(fig);
    }
#line 1449 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 70: // figuresansattr: LIGNE ENTIER ENTIER ENTIER ENTIER
#line 551 "parser/parser.yy"
                                      {
        double x = yystack_[3].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double x2 = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y2 = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        FigurePtr fig = std::make_shared<ligne>(x,y,x2,y2);
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertLigne(fig);
    }
#line 1463 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 72: // figuresansattr: TEXTE ENTIER ENTIER STRING STRING
#line 563 "parser/parser.yy"
                                      {
        double x = yystack_[3].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        double y = yystack_[2].value.as < ExpressionPtr > ()->calculer(driver.getContexte());

        FigurePtr fig = std::make_shared<texte>(x,y,yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::string > ());
        yylhs.value.as < ExpressionPtr > () = std::make_shared<expressionFigure>(fig);
        driver.getContexte().insertTexte(fig);
    }
#line 1476 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 79: // ATTR: ROTATION ':' ENTIER
#line 587 "parser/parser.yy"
                        {
        double rot = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.getContexte().getattr().setrotation(rot);  
    }
#line 1485 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 80: // ATTR: OPACITE ':' ENTIER '%'
#line 592 "parser/parser.yy"
                           {
        double opa = yystack_[1].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.getContexte().getattr().setopacite(opa);  
    }
#line 1494 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 81: // ATTR: EPAISSEUR ':' ENTIER
#line 597 "parser/parser.yy"
                         {
        double ep = yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte());
        driver.getContexte().getattr().setepaisseur(ep);  
    }
#line 1503 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 82: // ATTR: COULEUR ':' VAL_COULEUR
#line 602 "parser/parser.yy"
                            {
        driver.getContexte().getattr().setcouleur(yystack_[0].value.as < couleur > ()); 
    }
#line 1511 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 83: // ATTR: REMPLISSAGE ':' VAL_COULEUR
#line 606 "parser/parser.yy"
                                 {
        driver.getContexte().getattr().setRemplissage(yystack_[0].value.as < couleur > ());
    }
#line 1519 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 84: // ENTIER: NUMBER
#line 611 "parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < int > ());
    }
#line 1527 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 85: // ENTIER: STRING
#line 615 "parser/parser.yy"
           {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ());
    }
#line 1535 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 86: // ENTIER: ENTIER '*' ENTIER
#line 619 "parser/parser.yy"
                      {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::multiplie);
    }
#line 1543 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 87: // ENTIER: ENTIER '+' ENTIER
#line 623 "parser/parser.yy"
                      {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::plus);
    }
#line 1551 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 88: // ENTIER: ENTIER '-' ENTIER
#line 627 "parser/parser.yy"
                      {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::moins);
    }
#line 1559 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 89: // ENTIER: ENTIER '/' ENTIER
#line 631 "parser/parser.yy"
                      {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (),yystack_[0].value.as < ExpressionPtr > (),OperateurBinaire::divise);
    }
#line 1567 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 90: // ENTIER: '-' ENTIER
#line 635 "parser/parser.yy"
                         {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (),OperateurUnaire::neg);
    }
#line 1575 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 91: // ENTIER: INT STRING
#line 639 "parser/parser.yy"
               {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ());
    }
#line 1583 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 92: // VAL_COULEUR: RGB '(' NUMBER ',' NUMBER ',' NUMBER ')'
#line 649 "parser/parser.yy"
                                             {
        yylhs.value.as < couleur > () = couleur::noire;
    }
#line 1591 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 93: // VAL_COULEUR: COULEURG
#line 653 "parser/parser.yy"
             {
        yylhs.value.as < couleur > () = couleur::noire;
    }
#line 1599 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 94: // VAL_COULEUR: ROUGE
#line 656 "parser/parser.yy"
            {
        yylhs.value.as < couleur > () = couleur::rouge;
    }
#line 1607 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 95: // VAL_COULEUR: VERT
#line 659 "parser/parser.yy"
           {
        yylhs.value.as < couleur > () = couleur::vert;
    }
#line 1615 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 96: // VAL_COULEUR: JAUNE
#line 662 "parser/parser.yy"
            {
        yylhs.value.as < couleur > () = couleur::jaune;
    }
#line 1623 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 97: // VAL_COULEUR: BLEU
#line 665 "parser/parser.yy"
           {
        yylhs.value.as < couleur > () = couleur::bleu;
    }
#line 1631 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 98: // VAL_COULEUR: VIOLET
#line 668 "parser/parser.yy"
             {
        yylhs.value.as < couleur > () = couleur::violet;
    }
#line 1639 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 99: // VAL_COULEUR: MAGENTA
#line 671 "parser/parser.yy"
              {
        yylhs.value.as < couleur > () = couleur::magenta;
    }
#line 1647 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 100: // VAL_COULEUR: CYAN
#line 674 "parser/parser.yy"
           {
        yylhs.value.as < couleur > () = couleur::cyan;
    }
#line 1655 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 101: // VAL_COULEUR: NOIR
#line 677 "parser/parser.yy"
           {
        yylhs.value.as < couleur > () = couleur::noire;
    }
#line 1663 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;

  case 102: // VAL_COULEUR: BLANC
#line 680 "parser/parser.yy"
           {
        yylhs.value.as < couleur > () = couleur::blanc;
    }
#line 1671 "/home/etud/Bureau/compilation/build/parser.cpp"
    break;


#line 1675 "/home/etud/Bureau/compilation/build/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const short  Parser ::yypact_ninf_ = -159;

  const signed char  Parser ::yytable_ninf_ = -89;

  const short
   Parser ::yypact_[] =
  {
      -9,   118,     4,  -159,  -159,    20,   118,   245,  -159,  -159,
    -159,   118,   118,   118,   118,   125,   118,   266,   -60,  -159,
    -159,   257,   -60,   257,     3,    26,    29,    31,    57,    59,
      68,   114,   116,     1,    65,    70,    72,    16,    22,   118,
    -159,    93,   106,    40,  -159,  -159,    60,    39,  -159,     2,
    -159,   130,   118,   245,   118,   245,   118,   245,   118,   245,
     118,   245,   118,   245,   118,   245,   118,   245,   224,  -159,
      61,    63,   105,   107,    84,   257,   236,   132,   303,   354,
     443,   138,  -159,   329,   245,   333,   245,   337,   245,   355,
     245,   359,   245,   363,   245,   367,   -48,   384,    76,   118,
     118,   118,   118,   118,   118,   118,   118,  -159,   -19,   -25,
     124,   -26,   107,    82,    85,   -22,   296,    88,    83,  -159,
      90,  -159,   257,    96,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,    99,   100,   102,   103,   139,
     144,   146,   148,   149,   150,   151,   173,   175,   176,   178,
     179,   180,   194,   199,    98,   191,   192,   196,   197,  -159,
      97,   443,  -159,   245,  -159,   -19,  -159,   245,  -159,   -19,
    -159,   245,  -159,   245,  -159,   118,  -159,   155,  -159,  -159,
    -159,   210,   238,   239,   303,   303,   118,   118,   118,   118,
     118,   118,   215,   290,   293,  -159,   286,   303,   303,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   303,   303,   118,   118,
     118,   443,   225,   230,   245,   -19,   -19,   -19,  -159,   245,
    -159,   242,   231,   232,  -159,  -159,   -19,   -19,   -19,   -19,
     -19,   -19,   306,   317,   317,   227,  -159,  -159,   -19,   -19,
     288,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,  -159,  -159,   -19,   -19,   389,
    -159,  -159,   318,   245,   325,   248,   327,   334,   317,   264,
     283,   346,  -159,  -159,   443,   245,   118,   107,  -159,   317,
     317,   285,  -159,  -159,   278,  -159,   245,  -159,   336,   294,
     332,  -159,   397,   -19,   242,  -159,  -159,   339,  -159
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    84,    85,     0,     0,     0,     1,    91,
      90,     0,     0,     0,     0,     0,     0,    90,    87,    86,
      89,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,    14,    13,     0,     0,    51,    50,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     5,     0,     0,    94,    97,    95,    96,    98,    99,
     100,   101,   102,    93,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      76,    78,    56,     0,    55,    66,    57,     0,    59,    68,
      58,     0,    62,     0,    61,     0,    60,     0,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    69,    70,    71,     0,
      72,     0,     0,     0,    48,    49,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,    27,    26,    28,    30,
       0,    21,    22,    23,    24,    25,    31,    33,    35,    37,
      32,    34,    36,    38,    39,    83,    82,    81,    79,     0,
      75,    64,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,    29,    80,    78,     0,     0,     0,    40,     0,
       0,     0,     8,    12,     0,    77,     0,    73,     0,     0,
       0,     9,     0,    65,    41,    11,    10,     0,    92
  };

  const short
   Parser ::yypgoto_[] =
  {
    -159,  -159,    -7,  -159,  -159,  -130,  -159,   141,   -66,   345,
     -71,  -159,  -159,  -159,   128,   217,   133,  -158,    -1,   119
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,     2,    40,    41,    42,    43,    44,   113,   114,    45,
      46,    47,    48,    49,   228,   159,   222,   160,   116,   134
  };

  const short
   Parser ::yytable_[] =
  {
       7,   115,   115,   223,     8,    10,    15,   117,    13,    14,
      17,    18,    19,    20,     1,    22,    50,    80,    16,    12,
      13,    14,   178,   179,    53,    55,    57,    59,    61,    63,
      65,    67,   -53,   -53,     9,   175,   184,   185,    74,     3,
       4,   115,     3,     4,     3,     4,   181,    16,    12,    13,
      14,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   108,   119,   121,
       3,     4,     3,     4,    51,     5,    81,    68,     5,    69,
       5,     3,     4,   163,    70,   165,    71,   167,    72,   169,
     177,   171,     6,   173,    73,     6,    75,     6,    53,    55,
      57,    59,    61,    63,    65,    67,     5,    52,     5,    76,
      54,    77,    56,   279,   280,   195,    79,     5,     3,   111,
       3,   111,    34,     6,    34,     6,   223,     3,     4,     3,
       4,     3,     4,    82,     6,   122,    78,   109,    58,   110,
      60,   161,    16,    12,    13,    14,   180,   118,   291,    62,
      16,    12,    13,    14,     5,   182,     5,   193,   183,   299,
     300,   192,   224,     5,   194,     5,   225,     5,   196,   230,
     226,     6,   227,     6,   229,   197,   198,   112,   199,   200,
       6,   221,     6,   216,     6,   236,   237,   238,   239,   240,
     241,    16,    12,    13,    14,    64,    21,    66,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   201,   115,   267,   268,   269,
     202,   298,   203,   273,   204,   205,   206,   207,   274,    99,
     100,   101,   102,   103,   104,   105,   106,     3,     4,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   208,
      33,   209,   210,    34,   211,   212,   213,    35,     3,     4,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     214,    33,   285,     5,    34,   215,   217,   218,    35,   -88,
     -88,   219,   220,   231,   296,   229,    36,    37,   120,   242,
       6,   232,   233,   243,     5,   303,   244,    38,    39,   245,
     271,   272,   275,   234,   235,   276,   277,    36,    37,   278,
     281,    11,    12,    13,    14,   -88,   246,   247,    38,    39,
     287,   284,    25,    26,    27,    28,    29,    30,    31,    32,
     289,    33,   -88,   -88,    34,   265,   266,   290,    35,   292,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     186,   187,   188,   189,    16,    12,    13,    14,   293,   294,
     301,   302,    16,    12,    13,    14,   282,    36,   133,   305,
     135,   136,   137,   138,   139,   190,   191,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    16,    12,    13,    14,    16,    12,    13,    14,    16,
      12,    13,    14,    16,    12,    13,    14,   306,   286,   304,
     307,   162,   308,   107,   297,   164,   288,   295,     0,   166,
       0,    16,    12,    13,    14,    16,    12,    13,    14,    16,
      12,    13,    14,    16,    12,    13,    14,   168,   270,     0,
       0,   170,     0,     0,     0,   172,     0,     0,     0,   174,
      16,    12,    13,    14,     0,    16,    12,    13,    14,   154,
     155,   156,   157,   158,     0,     0,   176,   283
  };

  const short
   Parser ::yycheck_[] =
  {
       1,    72,    73,   161,     0,     6,     7,    73,    68,    69,
      11,    12,    13,    14,    23,    16,    23,    15,    66,    67,
      68,    69,    47,    48,    25,    26,    27,    28,    29,    30,
      31,    32,    58,    59,    14,    83,    58,    59,    39,    13,
      14,   112,    13,    14,    13,    14,   112,    66,    67,    68,
      69,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    75,    76,
      13,    14,    13,    14,    71,    49,    74,    76,    49,    14,
      49,    13,    14,    84,    14,    86,    14,    88,    72,    90,
      14,    92,    66,    94,    72,    66,     3,    66,    99,   100,
     101,   102,   103,   104,   105,   106,    49,    81,    49,     3,
      81,    71,    81,   243,   244,   122,    77,    49,    13,    14,
      13,    14,    17,    66,    17,    66,   284,    13,    14,    13,
      14,    13,    14,     3,    66,     3,    76,    76,    81,    76,
      81,     3,    66,    67,    68,    69,    22,    63,   278,    81,
      66,    67,    68,    69,    49,    73,    49,    74,    73,   289,
     290,    73,   163,    49,    74,    49,   167,    49,    72,    14,
     171,    66,   173,    66,   175,    76,    76,    72,    76,    76,
      66,    84,    66,    85,    66,   186,   187,   188,   189,   190,
     191,    66,    67,    68,    69,    81,    71,    81,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    76,   287,   218,   219,   220,
      76,   287,    76,   224,    76,    76,    76,    76,   229,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    76,
      14,    76,    76,    17,    76,    76,    76,    21,    13,    14,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      76,    14,   273,    49,    17,    76,    85,    85,    21,    13,
      14,    85,    85,    73,   285,   286,    50,    51,    52,    74,
      66,    53,    53,     3,    49,   296,     3,    61,    62,    13,
      75,    71,    60,   184,   185,    74,    74,    50,    51,     3,
      83,    66,    67,    68,    69,    49,   197,   198,    61,    62,
      72,     3,     5,     6,     7,     8,     9,    10,    11,    12,
       3,    14,    66,    67,    17,   216,   217,     3,    21,    75,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      54,    55,    56,    57,    66,    67,    68,    69,    75,    13,
      75,    83,    66,    67,    68,    69,    78,    50,    65,    75,
      16,    17,    18,    19,    20,    79,    80,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    66,    67,    68,    69,    66,    67,    68,    69,    66,
      67,    68,    69,    66,    67,    68,    69,    75,    83,    73,
      13,    82,    73,    68,   286,    82,   275,   284,    -1,    82,
      -1,    66,    67,    68,    69,    66,    67,    68,    69,    66,
      67,    68,    69,    66,    67,    68,    69,    82,   221,    -1,
      -1,    82,    -1,    -1,    -1,    82,    -1,    -1,    -1,    82,
      66,    67,    68,    69,    -1,    66,    67,    68,    69,    16,
      17,    18,    19,    20,    -1,    -1,    82,    78
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    23,    87,    13,    14,    49,    66,   104,     0,    14,
     104,    66,    67,    68,    69,   104,    66,   104,   104,   104,
     104,    71,   104,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    14,    17,    21,    50,    51,    61,    62,
      88,    89,    90,    91,    92,    95,    96,    97,    98,    99,
      88,    71,    81,   104,    81,   104,    81,   104,    81,   104,
      81,   104,    81,   104,    81,   104,    81,   104,    76,    14,
      14,    14,    72,    72,   104,     3,     3,    71,    76,    77,
      15,    74,     3,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,     5,
       6,     7,     8,     9,    10,    11,    12,    95,   104,    76,
      76,    14,    72,    93,    94,    96,   104,    94,    63,    88,
      52,    88,     3,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    65,   105,    16,    17,    18,    19,    20,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    16,    17,    18,    19,    20,   101,
     103,     3,    82,   104,    82,   104,    82,   104,    82,   104,
      82,   104,    82,   104,    82,    83,    82,    14,    47,    48,
      22,    94,    73,    73,    58,    59,    54,    55,    56,    57,
      79,    80,    73,    74,    74,    88,    72,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    85,    85,    85,    85,
      85,    84,   102,   103,   104,   104,   104,   104,   100,   104,
      14,    73,    53,    53,   105,   105,   104,   104,   104,   104,
     104,   104,    74,     3,     3,    13,   105,   105,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   104,   104,   104,
     101,    75,    71,   104,   104,    60,    74,    74,     3,    91,
      91,    83,    78,    78,     3,   104,    83,    72,    93,     3,
       3,    91,    75,    75,    13,   102,   104,   100,    94,    91,
      91,    75,    83,   104,    73,    75,    75,    13,    73
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    86,    87,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     5,     4,     3,     3,     3,     2,     7,     8,
       9,     9,     7,     1,     1,     3,     3,     4,     4,     4,
       3,     5,     5,     5,     5,     5,     5,     5,     5,     6,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     5,     9,     4,     5,     4,     5,
       5,     5,     5,     4,     2,     3,     1,     4,     0,     3,
       4,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       2,     2,     8,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NL", "END",
  "RECTANGLE", "CARRE", "TRIANGLE", "CERCLE", "ELLIPSE", "LIGNE", "CHEMIN",
  "TEXTE", "NUMBER", "STRING", "FLECHE", "REMPLISSAGE", "COULEUR",
  "EPAISSEUR", "ROTATION", "OPACITE", "BOOL", "FLOTTANT", "TAILLE",
  "LONGUEUR", "HAUTEUR", "X", "Y", "X1", "X2", "X3", "X4", "Y1", "Y2",
  "Y3", "Y4", "RAYON", "RGB", "ROUGE", "BLEU", "VERT", "JAUNE", "VIOLET",
  "MAGENTA", "CYAN", "NOIR", "BLANC", "TRUE", "FALSE", "INT", "REEL", "SI",
  "SINON", "ALORS", "EGAL", "DIFF", "INFEG", "SUPEG", "EST", "NESTPAS",
  "AND", "WHILE", "REPETE", "FOIS", "FONCTION", "COULEURG", "'-'", "'+'",
  "'*'", "'/'", "NEG", "';'", "'('", "')'", "'{'", "'}'", "'='", "'.'",
  "'%'", "'>'", "'<'", "'['", "']'", "','", "'&'", "':'", "$accept",
  "main", "programme", "boucle", "COND", "instructions", "affectation",
  "comparaisons", "comparaison", "figures", "VAR_COULEUR", "VAR_FIGURE",
  "figureavecattr", "figuresansattr", "coords", "ATTRS1", "ATTRS2", "ATTR",
  "ENTIER", "VAL_COULEUR", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   122,   122,   132,   134,   136,   138,   143,   149,   151,
     154,   156,   158,   161,   163,   170,   176,   181,   186,   190,
     194,   198,   206,   219,   232,   239,   246,   252,   258,   265,
     272,   279,   288,   297,   306,   315,   324,   333,   342,   351,
     361,   365,   370,   374,   378,   382,   386,   390,   394,   398,
     403,   407,   412,   416,   422,   427,   433,   439,   445,   451,
     457,   463,   469,   483,   490,   499,   513,   522,   532,   541,
     551,   561,   563,   573,   575,   578,   580,   583,   584,   587,
     592,   597,   602,   606,   611,   615,   619,   623,   627,   631,
     635,   639,   649,   653,   656,   659,   662,   665,   668,   671,
     674,   677,   680
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    78,    84,     2,
      72,    73,    68,    67,    83,    66,    77,    69,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    71,
      80,    76,    79,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,    75,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    70
    };
    // Last valid token kind.
    const int code_max = 321;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 2251 "/home/etud/Bureau/compilation/build/parser.cpp"

#line 685 "parser/parser.yy"


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}

