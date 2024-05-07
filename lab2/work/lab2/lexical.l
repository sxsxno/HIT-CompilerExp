%option yylineno
%{
    #include<stdio.h>
    #include<string.h>
    #include "syntax.tab.h"
%}
letter [a-zA-Z]
float ([0-9]+\.[0-9]+)|((([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+))[eE][+-]?[0-9]+)
floaterror (\.[eE][+-]?[0-9]+)|([0-9]*\.[0-9]+[eE][+-]?)|([0-9]+\.[0-9]*[eE][+-]?)|([0-9]+[Ee][+-]?)|(\.[eE][+-]?)
digint ([1-9]+[0-9]*)
digerror ([0-9]+[a-wA-Wy-zY-Z]+[0-9a-dA-Df-zF-Z]*)|([0-9]+[0-9]+[a-dA-Df-zF-Z]+[0-9]*[0-9a-dA-Df-zF-Z]*)
hexint (0[xX][0-9a-fA-f]+)
hexerror (0[xX][0-9a-fA-F]*[g-zG-Z]+[0-9a-zA-Z]*)
oxint (0[0-7]*)
oxerror (0[0-7]*[8-9]+[0-9]*)
id [a-zA-Z_][0-9a-zA-Z_]*
relop >|<|(<=)|(>=)|(==)|(!=)
space [ \t\r]
error .
BLANK   [ ]
TAB [ \t]
%%
"int" { yylval.node_=make_node(yylineno,3,"TYPE");return TYPE;}
"float" { yylval.node_=make_node(yylineno,3,"TYPE");return TYPE;}
"\n" { yycolumn = 1;}
"+" { yylval.node_=make_node(yylineno,4,"PLUS");return PLUS; }
"-" { yylval.node_=make_node(yylineno,4,"MINUS");return MINUS; }
"*" { yylval.node_=make_node(yylineno,4,"STAR");return STAR; }
"/" { yylval.node_=make_node(yylineno,4,"DIV");return DIV; }
";" { yylval.node_=make_node(yylineno,4,"SEMI");return SEMI; }
"," { yylval.node_=make_node(yylineno,4,"COMMA");return COMMA; }
"=" { yylval.node_=make_node(yylineno,4,"ASSIGNOP");return ASSIGNOP; }
"&&" { yylval.node_=make_node(yylineno,4,"AND");return AND; }
"||" { yylval.node_=make_node(yylineno,4,"OR");return OR; }
"." { yylval.node_=make_node(yylineno,4,"DOT");return DOT; }
"!" { yylval.node_=make_node(yylineno,4,"NOT");return NOT; }
"(" { yylval.node_=make_node(yylineno,4,"LP");return LP; }
")" { yylval.node_=make_node(yylineno,4,"RP");return RP; }
"[" { yylval.node_=make_node(yylineno,4,"LB");return LB; }
"]" { yylval.node_=make_node(yylineno,4,"RB");return RB; }
"{" { yylval.node_=make_node(yylineno,4,"LC");return LC; }
"}" { yylval.node_=make_node(yylineno,4,"RC");return RC; }
"struct" { yylval.node_=make_node(yylineno,4,"STRUCT");return STRUCT; }
"return" { yylval.node_=make_node(yylineno,4,"RETURN");return RETURN; }
"if" { yylval.node_=make_node(yylineno,4,"IF");return IF; }
"else" { yylval.node_=make_node(yylineno,4,"ELSE");return ELSE; }
"while" { yylval.node_=make_node(yylineno,4,"WHILE");return WHILE; }
{relop} { yylval.node_=make_node(yylineno,4,"RELOP");return RELOP; }
{id} { yylval.node_=make_node(yylineno,0,"ID");return ID; }
{digint} {
    yylval.node_=make_node(yylineno,1,"INT");
    yylval.node_->INT = atoi(yytext);
    return INT;
}
{hexint} {
    yylval.node_=make_node(yylineno,1,"INT");
    yylval.node_->INT = hex_to_dig(yytext);
    return INT;
}
{oxint} {
    yylval.node_=make_node(yylineno,1,"INT");
    yylval.node_->INT = ox_to_dig(yytext);
    return INT;
}
{float} {
    yylval.node_=make_node(yylineno,2,"FLOAT");
    yylval.node_->FLOAT = atof(yytext);
    return FLOAT;
}
{BLANK} {}
{TAB}   {yycolumn += 3;}
\n|\r {yycolumn = 1;}
"//" {
    char c = input();
    while(c!='\n') c=input();
}
"/*" {
    char c = input();
    char c_f = c;
    c = input();
    while( c!='/' && c_f!='*'){
        if(c == '*' && c_f == '/'){
            printf("Error type %s at line %d : %s\n","B",yylineno,"Syntax error");
        }
        c=input();
        if( c == EOF ) break;
        c_f = c;
    }
}
{error} {
    is_wrong = 1;
    printf("Error type %s at line %d : %s%s\n","A",yylineno,"Mysterious character ",yytext);
}
%%
