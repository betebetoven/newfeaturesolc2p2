// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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
#line 117 "Parser.y"

yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase3::Interfaz & intr);

#line 50 "parser.cpp"


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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 142 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class Clase3::Interfaz & intr_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      intr (intr_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_retornovalor: // retornovalor
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_declaracion_vector: // declaracion_vector
      case symbol_kind::S_declaracion_matriz: // declaracion_matriz
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_asignacion_vector: // asignacion_vector
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< AbstractExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.YY_MOVE_OR_COPY< NT_Imprimir* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
      case symbol_kind::S_lasig: // lasig
      case symbol_kind::S_lparam: // lparam
      case symbol_kind::S_lparamatriz: // lparamatriz
        value.YY_MOVE_OR_COPY< QVector<AbstractExpr*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
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

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_retornovalor: // retornovalor
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_declaracion_vector: // declaracion_vector
      case symbol_kind::S_declaracion_matriz: // declaracion_matriz
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_asignacion_vector: // asignacion_vector
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.move< AbstractExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.move< NT_Imprimir* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
      case symbol_kind::S_lasig: // lasig
      case symbol_kind::S_lparam: // lparam
      case symbol_kind::S_lparamatriz: // lparamatriz
        value.move< QVector<AbstractExpr*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_retornovalor: // retornovalor
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_declaracion_vector: // declaracion_vector
      case symbol_kind::S_declaracion_matriz: // declaracion_matriz
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_asignacion_vector: // asignacion_vector
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.copy< AbstractExpr* > (that.value);
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.copy< NT_Imprimir* > (that.value);
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
      case symbol_kind::S_lasig: // lasig
      case symbol_kind::S_lparam: // lparam
      case symbol_kind::S_lparamatriz: // lparamatriz
        value.copy< QVector<AbstractExpr*>* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_retornovalor: // retornovalor
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_declaracion_vector: // declaracion_vector
      case symbol_kind::S_declaracion_matriz: // declaracion_matriz
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_asignacion_vector: // asignacion_vector
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.move< AbstractExpr* > (that.value);
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.move< NT_Imprimir* > (that.value);
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
      case symbol_kind::S_lasig: // lasig
      case symbol_kind::S_lparam: // lparam
      case symbol_kind::S_lparamatriz: // lparamatriz
        value.move< QVector<AbstractExpr*>* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 483 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 489 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 495 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 501 "parser.cpp"
        break;

      case symbol_kind::S_STR: // STR
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 507 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 513 "parser.cpp"
        break;

      case symbol_kind::S_FLO: // FLO
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 519 "parser.cpp"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 525 "parser.cpp"
        break;

      case symbol_kind::S_s: // s
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 531 "parser.cpp"
        break;

      case symbol_kind::S_lSentencia: // lSentencia
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 537 "parser.cpp"
        break;

      case symbol_kind::S_sentencia: // sentencia
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 543 "parser.cpp"
        break;

      case symbol_kind::S_ciclo_for: // ciclo_for
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 549 "parser.cpp"
        break;

      case symbol_kind::S_ciclo_while: // ciclo_while
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 555 "parser.cpp"
        break;

      case symbol_kind::S_ins_if: // ins_if
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 561 "parser.cpp"
        break;

      case symbol_kind::S_escapa: // escapa
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 567 "parser.cpp"
        break;

      case symbol_kind::S_retornovalor: // retornovalor
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 573 "parser.cpp"
        break;

      case symbol_kind::S_llamada: // llamada
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 579 "parser.cpp"
        break;

      case symbol_kind::S_aumento: // aumento
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 585 "parser.cpp"
        break;

      case symbol_kind::S_decremento: // decremento
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 591 "parser.cpp"
        break;

      case symbol_kind::S_imprimir: // imprimir
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < NT_Imprimir* > (); }
#line 597 "parser.cpp"
        break;

      case symbol_kind::S_bloque: // bloque
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 603 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_void: // declaracion_void
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 609 "parser.cpp"
        break;

      case symbol_kind::S_lasig: // lasig
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 615 "parser.cpp"
        break;

      case symbol_kind::S_lparam: // lparam
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 621 "parser.cpp"
        break;

      case symbol_kind::S_lparamatriz: // lparamatriz
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 627 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_var: // declaracion_var
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 633 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_vector: // declaracion_vector
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 639 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_matriz: // declaracion_matriz
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 645 "parser.cpp"
        break;

      case symbol_kind::S_asignacion_var: // asignacion_var
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 651 "parser.cpp"
        break;

      case symbol_kind::S_asignacion_vector: // asignacion_vector
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 657 "parser.cpp"
        break;

      case symbol_kind::S_x: // x
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 663 "parser.cpp"
        break;

      case symbol_kind::S_cond: // cond
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 669 "parser.cpp"
        break;

      case symbol_kind::S_oprel: // oprel
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 675 "parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 681 "parser.cpp"
        break;

      case symbol_kind::S_tipo: // tipo
#line 177 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 687 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
            symbol_type yylookahead (yylex (scanner, loc, intr));
            yyla.move (yylookahead);
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
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_retornovalor: // retornovalor
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_declaracion_vector: // declaracion_vector
      case symbol_kind::S_declaracion_matriz: // declaracion_matriz
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_asignacion_vector: // asignacion_vector
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< AbstractExpr* > ();
        break;

      case symbol_kind::S_imprimir: // imprimir
        yylhs.value.emplace< NT_Imprimir* > ();
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
      case symbol_kind::S_lasig: // lasig
      case symbol_kind::S_lparam: // lparam
      case symbol_kind::S_lparamatriz: // lparamatriz
        yylhs.value.emplace< QVector<AbstractExpr*>* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
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
  case 2: // s: lSentencia
#line 186 "Parser.y"
               {std::cout << "LLEGO A S PARA SALIR" << std::endl;
        intr.raiz = *yystack_[0].value.as < QVector<AbstractExpr*>* > ();
                yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[0].value.as < QVector<AbstractExpr*>* > ();
                if (!yystack_[0].value.as < QVector<AbstractExpr*>* > ()->isEmpty()) {
        AbstractExpr* firstElement = (*yystack_[0].value.as < QVector<AbstractExpr*>* > ())[0]; 
        std::cout << "Class name of the first object in QVector: " << typeid(*firstElement).name() << std::endl;
    } else {
        std::cout << "QVector is empty" << std::endl;
    }
    if (!intr.raiz.isEmpty()) {
        AbstractExpr* firstElement = intr.raiz[0];
        std::cout << "Class name of the first object in intr.raiz: " << typeid(*firstElement).name() << std::endl;
    } else {
        std::cout << "intr.raiz is empty" << std::endl;
    }
    }
#line 1002 "parser.cpp"
    break;

  case 3: // lSentencia: lSentencia sentencia z
#line 205 "Parser.y"
                                   {
                           yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[2].value.as < QVector<AbstractExpr*>* > ();
                            yylhs.value.as < QVector<AbstractExpr*>* > ()->append(yystack_[1].value.as < AbstractExpr* > ());
                        }
#line 1011 "parser.cpp"
    break;

  case 4: // lSentencia: sentencia z
#line 209 "Parser.y"
                  {
        QVector<AbstractExpr*>* vec = new QVector<AbstractExpr*>();
        vec->append(yystack_[1].value.as < AbstractExpr* > ());
        yylhs.value.as < QVector<AbstractExpr*>* > () = vec;
    }
#line 1021 "parser.cpp"
    break;

  case 5: // sentencia: declaracion_var
#line 218 "Parser.y"
                           {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1027 "parser.cpp"
    break;

  case 6: // sentencia: asignacion_var
#line 219 "Parser.y"
                         {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > (); }
#line 1033 "parser.cpp"
    break;

  case 7: // sentencia: imprimir
#line 220 "Parser.y"
               {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < NT_Imprimir* > (); }
#line 1039 "parser.cpp"
    break;

  case 8: // sentencia: bloque
#line 221 "Parser.y"
             {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1045 "parser.cpp"
    break;

  case 9: // sentencia: aumento
#line 222 "Parser.y"
             {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1051 "parser.cpp"
    break;

  case 10: // sentencia: decremento
#line 223 "Parser.y"
                {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1057 "parser.cpp"
    break;

  case 11: // sentencia: ciclo_for
#line 224 "Parser.y"
               {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1063 "parser.cpp"
    break;

  case 12: // sentencia: ciclo_while
#line 225 "Parser.y"
                {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1069 "parser.cpp"
    break;

  case 13: // sentencia: ins_if
#line 226 "Parser.y"
            {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1075 "parser.cpp"
    break;

  case 14: // sentencia: escapa
#line 227 "Parser.y"
            {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1081 "parser.cpp"
    break;

  case 15: // sentencia: retornovalor
#line 228 "Parser.y"
                  {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1087 "parser.cpp"
    break;

  case 16: // sentencia: declaracion_void
#line 229 "Parser.y"
                      {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1093 "parser.cpp"
    break;

  case 17: // sentencia: llamada
#line 230 "Parser.y"
             {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1099 "parser.cpp"
    break;

  case 18: // sentencia: declaracion_vector
#line 231 "Parser.y"
                        {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1105 "parser.cpp"
    break;

  case 19: // sentencia: asignacion_vector
#line 232 "Parser.y"
                       {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1111 "parser.cpp"
    break;

  case 20: // sentencia: declaracion_matriz
#line 233 "Parser.y"
                        {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1117 "parser.cpp"
    break;

  case 21: // ciclo_for: FOR '(' declaracion_var z x z aumento ')' '{' lSentencia '}'
#line 236 "Parser.y"
                                                                       {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),yystack_[8].value.as < AbstractExpr* > (),yystack_[6].value.as < AbstractExpr* > (),yystack_[4].value.as < AbstractExpr* > (),true,nullptr);}
#line 1123 "parser.cpp"
    break;

  case 22: // ciclo_while: WHILE '(' x ')' '{' lSentencia '}'
#line 239 "Parser.y"
                                                {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[4].value.as < AbstractExpr* > (),nullptr,true,nullptr);}
#line 1129 "parser.cpp"
    break;

  case 23: // ins_if: IF '(' x ')' '{' lSentencia '}'
#line 243 "Parser.y"
                                        {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[4].value.as < AbstractExpr* > (),nullptr,false,nullptr);}
#line 1135 "parser.cpp"
    break;

  case 24: // ins_if: IF '(' x ')' '{' lSentencia '}' ELSE '{' lSentencia '}'
#line 244 "Parser.y"
                                                              {Bloque* elsa = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,nullptr,nullptr,false, nullptr);
                                                                yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[5].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[8].value.as < AbstractExpr* > (),nullptr,false,elsa);}
#line 1142 "parser.cpp"
    break;

  case 25: // ins_if: IF '(' x ')' '{' lSentencia '}' ELSE ins_if
#line 246 "Parser.y"
                                                    {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[3].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[6].value.as < AbstractExpr* > (),nullptr,false,yystack_[0].value.as < AbstractExpr* > ());}
#line 1148 "parser.cpp"
    break;

  case 26: // escapa: BREAK
#line 249 "Parser.y"
              { yylhs.value.as < AbstractExpr* > () = new NT_Escape(QString::fromStdString("break"));}
#line 1154 "parser.cpp"
    break;

  case 27: // escapa: CONTINUE
#line 250 "Parser.y"
               { yylhs.value.as < AbstractExpr* > () = new NT_Escape(QString::fromStdString("continue"));}
#line 1160 "parser.cpp"
    break;

  case 28: // escapa: RETORNO
#line 251 "Parser.y"
              { yylhs.value.as < AbstractExpr* > () = new NT_Escape(QString::fromStdString("return"));}
#line 1166 "parser.cpp"
    break;

  case 29: // retornovalor: RETORNO x
#line 253 "Parser.y"
                        { NT_ID* id_avar = new NT_ID(QString::fromStdString("return"));
                            yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar, yystack_[0].value.as < AbstractExpr* > (),true);}
#line 1173 "parser.cpp"
    break;

  case 30: // llamada: ID '(' lparam ')'
#line 258 "Parser.y"
                           { 
    
    NT_ID* id_av = new NT_ID(QString::fromStdString(yystack_[3].value.as < std::string > ()));
    yylhs.value.as < AbstractExpr* > () = new NT_Llamada(id_av,*yystack_[1].value.as < QVector<AbstractExpr*>* > ());}
#line 1182 "parser.cpp"
    break;

  case 31: // llamada: ID '(' ')'
#line 262 "Parser.y"
                 { 
        NT_ID* id_av = new NT_ID(QString::fromStdString(yystack_[2].value.as < std::string > ()));
        yylhs.value.as < AbstractExpr* > () = new NT_Llamada(id_av);}
#line 1190 "parser.cpp"
    break;

  case 32: // aumento: INCREMENT ID
#line 270 "Parser.y"
                       {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1198 "parser.cpp"
    break;

  case 33: // aumento: ID INCREMENT
#line 273 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1206 "parser.cpp"
    break;

  case 34: // decremento: DECREMENT ID
#line 277 "Parser.y"
                         {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1214 "parser.cpp"
    break;

  case 35: // decremento: ID DECREMENT
#line 280 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1222 "parser.cpp"
    break;

  case 36: // imprimir: IMPR '(' lparam ')'
#line 290 "Parser.y"
                              { yylhs.value.as < NT_Imprimir* > () = new NT_Imprimir(*yystack_[1].value.as < QVector<AbstractExpr*>* > ()); }
#line 1228 "parser.cpp"
    break;

  case 37: // bloque: '{' lSentencia '}'
#line 302 "Parser.y"
                           { yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,nullptr,nullptr,false, nullptr); }
#line 1234 "parser.cpp"
    break;

  case 38: // z: ';'
#line 304 "Parser.y"
       {  }
#line 1240 "parser.cpp"
    break;

  case 39: // z: %empty
#line 305 "Parser.y"
             { }
#line 1246 "parser.cpp"
    break;

  case 40: // declaracion_void: tipo ID '(' ')' bloque
#line 308 "Parser.y"
                                        { 
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[3].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclFunc(yystack_[4].value.as < AbstractExpr* > (), id, yystack_[0].value.as < AbstractExpr* > ());
                                }
#line 1255 "parser.cpp"
    break;

  case 41: // declaracion_void: tipo ID '(' lasig ')' bloque
#line 312 "Parser.y"
                                               { 
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[4].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclFunc(yystack_[5].value.as < AbstractExpr* > (), id, yystack_[0].value.as < AbstractExpr* > (), *yystack_[2].value.as < QVector<AbstractExpr*>* > ());
                                }
#line 1264 "parser.cpp"
    break;

  case 42: // lasig: lasig ',' declaracion_var
#line 317 "Parser.y"
                                  {
                           yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[2].value.as < QVector<AbstractExpr*>* > ();
                            yylhs.value.as < QVector<AbstractExpr*>* > ()->append(yystack_[0].value.as < AbstractExpr* > ());
                        }
#line 1273 "parser.cpp"
    break;

  case 43: // lasig: declaracion_var
#line 321 "Parser.y"
                       {    
        QVector<AbstractExpr*>* vec = new QVector<AbstractExpr*>();
        vec->append(yystack_[0].value.as < AbstractExpr* > ());
        yylhs.value.as < QVector<AbstractExpr*>* > () = vec;
    }
#line 1283 "parser.cpp"
    break;

  case 44: // lparam: lparam ',' x
#line 330 "Parser.y"
                     {
                           yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[2].value.as < QVector<AbstractExpr*>* > ();
                            yylhs.value.as < QVector<AbstractExpr*>* > ()->append(yystack_[0].value.as < AbstractExpr* > ());
                        }
#line 1292 "parser.cpp"
    break;

  case 45: // lparam: x
#line 334 "Parser.y"
         {  
        QVector<AbstractExpr*>* vec = new QVector<AbstractExpr*>();
        vec->append(yystack_[0].value.as < AbstractExpr* > ());
        yylhs.value.as < QVector<AbstractExpr*>* > () = vec;
    }
#line 1302 "parser.cpp"
    break;

  case 46: // lparamatriz: lparamatriz '[' x ']'
#line 341 "Parser.y"
                                   {
                           yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[3].value.as < QVector<AbstractExpr*>* > ();
                            yylhs.value.as < QVector<AbstractExpr*>* > ()->append(yystack_[1].value.as < AbstractExpr* > ());
                        }
#line 1311 "parser.cpp"
    break;

  case 47: // lparamatriz: '[' x ']'
#line 345 "Parser.y"
               {  
        QVector<AbstractExpr*>* vec = new QVector<AbstractExpr*>();
        vec->append(yystack_[1].value.as < AbstractExpr* > ());
        yylhs.value.as < QVector<AbstractExpr*>* > () = vec;
    }
#line 1321 "parser.cpp"
    break;

  case 48: // declaracion_var: tipo ID
#line 357 "Parser.y"
                          {   NT_ID* id = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                    yylhs.value.as < AbstractExpr* > () = new NT_DeclVar(yystack_[1].value.as < AbstractExpr* > (), id); }
#line 1328 "parser.cpp"
    break;

  case 49: // declaracion_var: tipo ID '=' x
#line 359 "Parser.y"
                     {    
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[2].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclVar(yystack_[3].value.as < AbstractExpr* > (), id,yystack_[0].value.as < AbstractExpr* > () );  }
#line 1336 "parser.cpp"
    break;

  case 50: // declaracion_vector: VECTOR MENOR tipo MAYOR ID
#line 364 "Parser.y"
                                                {   NT_ID* id = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                    yylhs.value.as < AbstractExpr* > () = new NT_DeclVector(yystack_[2].value.as < AbstractExpr* > (), id); }
#line 1343 "parser.cpp"
    break;

  case 51: // declaracion_vector: VECTOR MENOR tipo MAYOR ID '=' '[' lparam ']'
#line 366 "Parser.y"
                                                     {    
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[4].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclVector(yystack_[6].value.as < AbstractExpr* > (), id, *yystack_[1].value.as < QVector<AbstractExpr*>* > () );  }
#line 1351 "parser.cpp"
    break;

  case 52: // declaracion_matriz: tipo ID lparamatriz
#line 370 "Parser.y"
                                           {    
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclMatriz(yystack_[2].value.as < AbstractExpr* > (), id, *yystack_[0].value.as < QVector<AbstractExpr*>* > () );  }
#line 1359 "parser.cpp"
    break;

  case 53: // asignacion_var: ID '=' x
#line 384 "Parser.y"
                         {   NT_ID* id_avar = new NT_ID(QString::fromStdString(yystack_[2].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar, yystack_[0].value.as < AbstractExpr* > (),true);
                                }
#line 1367 "parser.cpp"
    break;

  case 54: // asignacion_vector: ID lparamatriz '=' x
#line 388 "Parser.y"
                                        {   NT_ID* id_avar = new NT_ID(QString::fromStdString(yystack_[3].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVector(id_avar,*yystack_[2].value.as < QVector<AbstractExpr*>* > (),yystack_[0].value.as < AbstractExpr* > ());
                                }
#line 1375 "parser.cpp"
    break;

  case 55: // x: cond
#line 396 "Parser.y"
         {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1381 "parser.cpp"
    break;

  case 56: // cond: cond OR cond
#line 399 "Parser.y"
                   {yylhs.value.as < AbstractExpr* > () = new NT_Or(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());}
#line 1387 "parser.cpp"
    break;

  case 57: // cond: cond AND cond
#line 400 "Parser.y"
                    {yylhs.value.as < AbstractExpr* > () = new NT_And(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());}
#line 1393 "parser.cpp"
    break;

  case 58: // cond: NOT cond
#line 401 "Parser.y"
               { yylhs.value.as < AbstractExpr* > () = new NT_Not(yystack_[0].value.as < AbstractExpr* > ());}
#line 1399 "parser.cpp"
    break;

  case 59: // cond: '(' cond ')'
#line 402 "Parser.y"
                 {yylhs.value.as < AbstractExpr* > () = yystack_[1].value.as < AbstractExpr* > ();}
#line 1405 "parser.cpp"
    break;

  case 60: // cond: expr oprel expr
#line 403 "Parser.y"
                     {if (yystack_[1].value.as < std::string > () == "mayor") {
        yylhs.value.as < AbstractExpr* > () = new NT_Mayor(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "menor") {
        yylhs.value.as < AbstractExpr* > () = new NT_Menor(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "igual") {
        yylhs.value.as < AbstractExpr* > () = new NT_IgualIgual(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "menorigual") {
        yylhs.value.as < AbstractExpr* > () = new NT_MenorIgual(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "mayorigual") {
        yylhs.value.as < AbstractExpr* > () = new NT_MayorIgual(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "diferente") {
        yylhs.value.as < AbstractExpr* > () = new NT_Diferente(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else {
        yylhs.value.as < AbstractExpr* > () = new NT_Diferente(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    }}
#line 1425 "parser.cpp"
    break;

  case 61: // cond: expr
#line 418 "Parser.y"
         {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1431 "parser.cpp"
    break;

  case 62: // oprel: MAYOR
#line 420 "Parser.y"
            {yylhs.value.as < std::string > () = "mayor";}
#line 1437 "parser.cpp"
    break;

  case 63: // oprel: MENOR
#line 421 "Parser.y"
           {yylhs.value.as < std::string > () = "menor";}
#line 1443 "parser.cpp"
    break;

  case 64: // oprel: IGUAL_IGUAL
#line 422 "Parser.y"
                 {yylhs.value.as < std::string > () = "igual";}
#line 1449 "parser.cpp"
    break;

  case 65: // oprel: MENOR_IGUAL
#line 423 "Parser.y"
                 {yylhs.value.as < std::string > () = "menorigual";}
#line 1455 "parser.cpp"
    break;

  case 66: // oprel: MAYOR_IGUAL
#line 424 "Parser.y"
                 {yylhs.value.as < std::string > () = "mayorigual";}
#line 1461 "parser.cpp"
    break;

  case 67: // oprel: DIFERENTE
#line 425 "Parser.y"
               {yylhs.value.as < std::string > () = "diferente";}
#line 1467 "parser.cpp"
    break;

  case 68: // expr: expr SUMA expr
#line 427 "Parser.y"
                       { yylhs.value.as < AbstractExpr* > () = new NT_Suma(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());  }
#line 1473 "parser.cpp"
    break;

  case 69: // expr: expr MENOS expr
#line 428 "Parser.y"
                      { yylhs.value.as < AbstractExpr* > () = new NT_Resta(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1479 "parser.cpp"
    break;

  case 70: // expr: expr MULTIPLICACION expr
#line 429 "Parser.y"
                               { yylhs.value.as < AbstractExpr* > () = new NT_Multiplicacion(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1485 "parser.cpp"
    break;

  case 71: // expr: expr DIVISION expr
#line 430 "Parser.y"
                         { yylhs.value.as < AbstractExpr* > () = new NT_Division(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1491 "parser.cpp"
    break;

  case 72: // expr: expr MOD expr
#line 431 "Parser.y"
                    { yylhs.value.as < AbstractExpr* > () = new NT_Modulo(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1497 "parser.cpp"
    break;

  case 73: // expr: expr EXPONENCIAL expr
#line 432 "Parser.y"
                            { yylhs.value.as < AbstractExpr* > () = new NT_Exponencial(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1503 "parser.cpp"
    break;

  case 74: // expr: '(' expr ')'
#line 433 "Parser.y"
                   { yylhs.value.as < AbstractExpr* > () = yystack_[1].value.as < AbstractExpr* > (); }
#line 1509 "parser.cpp"
    break;

  case 75: // expr: INCREMENT ID
#line 434 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1517 "parser.cpp"
    break;

  case 76: // expr: ID INCREMENT
#line 437 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1525 "parser.cpp"
    break;

  case 77: // expr: DECREMENT ID
#line 440 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1533 "parser.cpp"
    break;

  case 78: // expr: ID DECREMENT
#line 443 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1541 "parser.cpp"
    break;

  case 79: // expr: MENOS expr
#line 446 "Parser.y"
                            { yylhs.value.as < AbstractExpr* > () = new NT_Negacion(yystack_[0].value.as < AbstractExpr* > ());  }
#line 1547 "parser.cpp"
    break;

  case 80: // expr: NUMERO
#line 447 "Parser.y"
             { yylhs.value.as < AbstractExpr* > () = new T_Numero( QString::fromStdString(yystack_[0].value.as < std::string > ())); }
#line 1553 "parser.cpp"
    break;

  case 81: // expr: ID
#line 448 "Parser.y"
         { yylhs.value.as < AbstractExpr* > () = new T_ID( QString::fromStdString(yystack_[0].value.as < std::string > ())); }
#line 1559 "parser.cpp"
    break;

  case 82: // expr: ID lparamatriz
#line 449 "Parser.y"
                       { yylhs.value.as < AbstractExpr* > () = new T_ID( QString::fromStdString(yystack_[1].value.as < std::string > ()),*yystack_[0].value.as < QVector<AbstractExpr*>* > ()); }
#line 1565 "parser.cpp"
    break;

  case 83: // expr: llamada
#line 450 "Parser.y"
             {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1571 "parser.cpp"
    break;

  case 84: // expr: STRING
#line 451 "Parser.y"
             { yylhs.value.as < AbstractExpr* > () = new T_String( QString::fromStdString(yystack_[0].value.as < std::string > ()));  }
#line 1577 "parser.cpp"
    break;

  case 85: // expr: FLOAT
#line 452 "Parser.y"
            { yylhs.value.as < AbstractExpr* > () = new T_Float( QString::fromStdString(yystack_[0].value.as < std::string > ()));  }
#line 1583 "parser.cpp"
    break;

  case 86: // expr: TRUE
#line 453 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new T_Boolean( QString::fromStdString("true"));  }
#line 1589 "parser.cpp"
    break;

  case 87: // expr: FALSE
#line 454 "Parser.y"
            { yylhs.value.as < AbstractExpr* > () = new T_Boolean( QString::fromStdString("false"));  }
#line 1595 "parser.cpp"
    break;

  case 88: // tipo: INT
#line 457 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Integer")); }
#line 1601 "parser.cpp"
    break;

  case 89: // tipo: STR
#line 458 "Parser.y"
          { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("String")); }
#line 1607 "parser.cpp"
    break;

  case 90: // tipo: FLO
#line 459 "Parser.y"
          { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Float")); }
#line 1613 "parser.cpp"
    break;

  case 91: // tipo: BOOL
#line 460 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Boolean")); }
#line 1619 "parser.cpp"
    break;

  case 92: // tipo: VOID
#line 461 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Void")); }
#line 1625 "parser.cpp"
    break;


#line 1629 "parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -81;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     317,    54,   -81,   -81,   -81,   -81,   -40,   -81,   -32,    -3,
       5,    56,    69,    40,   325,   -81,   -81,   317,    78,   317,
      22,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,    79,   -81,   -81,
      81,   325,   325,   -35,   325,   325,   325,   140,   -81,   -81,
     140,   -81,   -26,   -81,   -81,   121,   -81,   -81,   325,    83,
      84,   325,   -81,   -81,     4,   394,    34,   -81,    22,   -81,
     -81,    45,   -81,   -48,   -81,   -81,    30,   325,   325,   -24,
      21,    43,    22,    97,    74,   -81,   -81,    47,   121,    89,
       4,   -81,   -81,    -9,   385,   325,   325,   121,   121,   121,
     121,   121,   121,   -81,   -81,   -81,   -81,   -81,   -81,   121,
     -81,   -81,    16,   325,    47,   -81,   325,   -81,   -81,    49,
     -81,    60,    64,   325,    66,   130,   189,   -81,   -81,   -81,
     123,   101,   101,    89,    89,    89,    89,   224,    85,    -6,
     -81,   -81,   -81,   -81,   317,   317,    22,    93,   -81,    85,
     140,   167,   181,    14,    91,   -81,   -81,   135,   -81,   124,
     102,   325,   -15,   103,    -5,   317,   -81,   317,   -81,   242,
     256,   -81,   -81
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,     0,     0,     0,    28,    26,    27,     0,     0,     2,
      39,    11,    12,    13,    14,    15,    17,     9,    10,     7,
       8,    16,     5,    18,    20,     6,    19,     0,    33,    35,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    34,
       0,    80,    81,    84,    85,     0,    86,    87,     0,     0,
       0,     0,    83,    29,    55,    61,     0,     1,    39,    38,
       4,    48,    31,     0,    45,    53,     0,     0,     0,     0,
       0,     0,    39,     0,     0,    76,    78,    82,     0,    79,
      58,    75,    77,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    64,    67,    63,    62,     0,
      37,     3,     0,     0,    52,    30,     0,    47,    54,     0,
      36,     0,     0,     0,    48,     0,     0,    59,    74,    57,
      56,    68,    69,    72,    70,    71,    73,    60,     0,     0,
      43,    49,    44,    46,     0,     0,    39,    50,    40,     0,
       0,     0,     0,     0,     0,    41,    42,    23,    22,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    51,     0,
       0,    24,    21
  };

  const short
  Parser::yypgoto_[] =
  {
     -81,   -81,    -7,   -16,   -81,   -81,     6,   -81,   -81,     0,
      19,   -81,   -81,   -80,   -66,   -81,   -81,   -43,     1,   -41,
     -81,   -81,   -81,   -81,   -10,   -49,   -81,   293,   -42
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    62,
      27,    28,    29,    30,    70,    31,   139,    73,    43,    32,
      33,    34,    35,    36,    74,    64,   109,    65,    37
  };

  const unsigned char
  Parser::yytable_[] =
  {
      26,    79,   111,    68,    63,    83,    82,     8,    84,    90,
      66,    95,    93,   115,    85,    86,   123,    26,   159,    26,
      44,   116,     2,     3,    95,     4,     5,    77,    45,    96,
      78,    75,    76,     7,    40,    80,    81,   120,     1,    42,
       2,     3,    96,     4,     5,   116,   129,   130,   165,     6,
      68,     7,   127,    87,    11,   149,     8,    46,   148,     9,
      48,   168,    10,   150,   116,    47,    26,   118,   119,   155,
      83,   140,   114,    49,    11,    12,    50,   138,    67,    13,
     153,    69,   121,    71,    51,    52,    53,    91,    92,    54,
      14,    15,    16,    55,    38,    39,   117,    17,   110,    56,
      57,   124,    58,   141,   122,   112,   142,   113,    83,   156,
      42,   125,    78,   146,    40,   143,    41,    99,   164,    42,
     102,    59,    60,   144,    51,    52,    53,   145,   113,    54,
     100,   101,   102,    55,   147,    68,    68,   151,   152,    56,
      57,    61,    72,    95,    26,    26,     2,     3,    17,     4,
       5,    26,    26,    68,    68,   154,   161,     7,   169,   162,
     170,    59,    60,   163,    38,    26,   167,    26,   166,    26,
      26,     1,   160,     2,     3,     0,     4,     5,     0,     0,
       0,    88,     6,     0,     7,     1,     0,     2,     3,     8,
       4,     5,     9,     0,     0,    10,     6,     0,     7,     0,
      97,    98,     0,     8,     0,    99,     9,    11,    12,    10,
       0,     0,    13,     0,     0,     0,     0,     0,   100,   101,
     102,    11,    12,    14,    15,    16,    13,     0,     0,     0,
      17,   157,     0,     0,     0,    97,    98,    14,    15,    16,
      99,     0,     0,     0,    17,   158,     1,     0,     2,     3,
     128,     4,     5,   100,   101,   102,     0,     6,     0,     7,
       1,     0,     2,     3,     8,     4,     5,     9,     0,     0,
      10,     6,     0,     7,     0,     0,     0,     0,     8,     0,
       0,     9,    11,    12,    10,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,    14,    15,
      16,    13,     0,     0,     0,    17,   171,     0,     0,     0,
       0,     0,    14,    15,    16,     0,     0,     0,     0,    17,
     172,     1,     0,     2,     3,     0,     4,     5,    51,    52,
      53,     0,     6,    54,     7,     0,     0,    55,     0,     8,
       0,     0,     9,    56,    57,    10,    58,     0,    89,     0,
       0,     0,     0,     0,    94,     0,     0,    11,    12,     0,
       0,     0,    13,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,    14,    15,    16,     0,     0,     0,     0,
      17,   126,     0,     0,     0,    61,     0,     0,     0,     0,
     131,   132,   133,   134,   135,   136,    97,    98,     0,     0,
       0,    99,   137,     0,     0,    97,    98,     0,     0,     0,
      99,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128
  };

  const short
  Parser::yycheck_[] =
  {
       0,    44,    68,    19,    14,    47,    47,    22,    50,    58,
      17,    20,    61,    61,    40,    41,    82,    17,     4,    19,
      60,    69,     6,     7,    20,     9,    10,    62,    60,    38,
      65,    41,    42,    17,    60,    45,    46,    61,     4,    65,
       6,     7,    38,     9,    10,    69,    95,    96,    63,    15,
      66,    17,    61,    52,    40,    61,    22,    60,   138,    25,
       4,    66,    28,    69,    69,    60,    66,    77,    78,   149,
     112,   112,    71,     4,    40,    41,    36,    61,     0,    45,
     146,    59,    61,     4,     3,     4,     5,     4,     4,     8,
      56,    57,    58,    12,    40,    41,    66,    63,    64,    18,
      19,     4,    21,   113,    61,    60,   116,    62,   150,   150,
      65,    37,    65,   123,    60,    66,    62,    16,   161,    65,
      31,    40,    41,    63,     3,     4,     5,    63,    62,     8,
      29,    30,    31,    12,     4,   151,   152,   144,   145,    18,
      19,    60,    61,    20,   144,   145,     6,     7,    63,     9,
      10,   151,   152,   169,   170,    62,    65,    17,   165,    24,
     167,    40,    41,    61,    40,   165,    63,   167,   162,   169,
     170,     4,   153,     6,     7,    -1,     9,    10,    -1,    -1,
      -1,    60,    15,    -1,    17,     4,    -1,     6,     7,    22,
       9,    10,    25,    -1,    -1,    28,    15,    -1,    17,    -1,
      11,    12,    -1,    22,    -1,    16,    25,    40,    41,    28,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    40,    41,    56,    57,    58,    45,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    11,    12,    56,    57,    58,
      16,    -1,    -1,    -1,    63,    64,     4,    -1,     6,     7,
      61,     9,    10,    29,    30,    31,    -1,    15,    -1,    17,
       4,    -1,     6,     7,    22,     9,    10,    25,    -1,    -1,
      28,    15,    -1,    17,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    25,    40,    41,    28,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    56,    57,
      58,    45,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,     4,    -1,     6,     7,    -1,     9,    10,     3,     4,
       5,    -1,    15,     8,    17,    -1,    -1,    12,    -1,    22,
      -1,    -1,    25,    18,    19,    28,    21,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    40,    41,    -1,
      -1,    -1,    45,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    88,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    11,    12,    -1,    -1,
      -1,    16,   109,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     6,     7,     9,    10,    15,    17,    22,    25,
      28,    40,    41,    45,    56,    57,    58,    63,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    85,    89,    90,    91,    92,    93,    98,    40,    41,
      60,    62,    65,    88,    60,    60,    60,    60,     4,     4,
      36,     3,     4,     5,     8,    12,    18,    19,    21,    40,
      41,    60,    79,    94,    95,    97,    72,     0,    73,    59,
      84,     4,    61,    87,    94,    94,    94,    62,    65,    87,
      94,    94,    89,    98,    98,    40,    41,    88,    60,    97,
      95,     4,     4,    95,    97,    20,    38,    11,    12,    16,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    96,
      64,    84,    60,    62,    88,    61,    69,    66,    94,    94,
      61,    61,    61,    84,     4,    37,    97,    61,    61,    95,
      95,    97,    97,    97,    97,    97,    97,    97,    61,    86,
      89,    94,    94,    66,    63,    63,    94,     4,    83,    61,
      69,    72,    72,    84,    62,    83,    89,    64,    64,     4,
      80,    65,    24,    61,    87,    63,    76,    63,    66,    72,
      72,    64,    64
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    75,    76,    76,    76,    77,    77,    77,    78,
      79,    79,    80,    80,    81,    81,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    92,    93,    94,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    11,     7,     7,    11,     9,     1,     1,     1,     2,
       4,     3,     2,     2,     2,     2,     4,     3,     1,     0,
       5,     6,     3,     1,     3,     1,     4,     3,     2,     4,
       5,     9,     3,     3,     4,     1,     3,     3,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "INT",
  "STR", "FLOAT", "FLO", "BOOL", "SUMA", "MENOS", "DIM", "AS", "IMPR",
  "MOD", "VOID", "TRUE", "FALSE", "AND", "NOT", "IF", "THEN", "ELSE",
  "WHILE", "PRINT", "PRINTF", "FOR", "MULTIPLICACION", "DIVISION",
  "EXPONENCIAL", "MENOR_IGUAL", "MAYOR_IGUAL", "IGUAL_IGUAL", "DIFERENTE",
  "MENOR", "MAYOR", "OR", "INTERROGACION", "INCREMENT", "DECREMENT", "DOT",
  "LEFT_BRACKET", "RIGHT_BRACKET", "VECTOR", "PUSH_FRONT", "DOT_PUSH_BACK",
  "STRUCT", "REMOVE", "MEDIAN", "IOTA", "MEAN", "SIZE", "ATOI", "GET",
  "RETORNO", "BREAK", "CONTINUE", "';'", "'('", "')'", "'='", "'{'", "'}'",
  "'['", "']'", "'.'", "NEG", "','", "$accept", "s", "lSentencia",
  "sentencia", "ciclo_for", "ciclo_while", "ins_if", "escapa",
  "retornovalor", "llamada", "aumento", "decremento", "imprimir", "bloque",
  "z", "declaracion_void", "lasig", "lparam", "lparamatriz",
  "declaracion_var", "declaracion_vector", "declaracion_matriz",
  "asignacion_var", "asignacion_vector", "x", "cond", "oprel", "expr",
  "tipo", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   186,   186,   205,   209,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   236,   239,   243,   244,   246,   249,   250,   251,   253,
     258,   262,   270,   273,   277,   280,   290,   302,   304,   305,
     308,   312,   317,   321,   330,   334,   341,   345,   357,   359,
     364,   366,   370,   384,   388,   396,   399,   400,   401,   402,
     403,   418,   420,   421,   422,   423,   424,   425,   427,   428,
     429,   430,   431,   432,   433,   434,   437,   440,   443,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   457,   458,
     459,   460,   461
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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


} // yy
#line 2269 "parser.cpp"

#line 464 "Parser.y"

void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

