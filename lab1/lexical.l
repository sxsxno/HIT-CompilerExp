%option yylineno
%{
    #include<stdio.h>
    #include<string.h>
    #include "syntax.tab.h"
%}
letter [a-zA-Z]
float ([0-9]+\.[0-9]+)|((([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+))[eE][+-]?[0-9]+)
digint ([1-9]+[0-9]*)
hexint (0[xX][0-9a-fA-f]+)
oxint (0[0-7]*)
id [a-zA-Z_][0-9a-zA-Z_]*
relop >|<|(<=)|(>=)|(==)|(!=)
space [ \t\r]
error .
%%
{space} { }
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
"int" { yylval.node_=make_node(yylineno,0,"TYPE");return TYPE;}
"float" { yylval.node_=make_node(yylineno,0,"TYPE");return TYPE;}
"\n" { yycolumn = 1;}
"+" { yylval.node_=make_node(yylineno,-1,"PLUS");return PLUS; }
"-" { yylval.node_=make_node(yylineno,-1,"MINUS");return MINUS; }
"*" { yylval.node_=make_node(yylineno,-1,"STAR");return STAR; }
"/" { yylval.node_=make_node(yylineno,-1,"DIV");return DIV; }
";" { yylval.node_=make_node(yylineno,-1,"SEMI");return SEMI; }
"," { yylval.node_=make_node(yylineno,-1,"COMMA");return COMMA; }
"=" { yylval.node_=make_node(yylineno,-1,"ASSIGNOP");return ASSIGNOP; }
"&&" { yylval.node_=make_node(yylineno,-1,"AND");return AND; }
"||" { yylval.node_=make_node(yylineno,-1,"OR");return OR; }
"." { yylval.node_=make_node(yylineno,-1,"DOT");return DOT; }
"!" { yylval.node_=make_node(yylineno,-1,"NOT");return NOT; }
"(" { yylval.node_=make_node(yylineno,-1,"LP");return LP; }
")" { yylval.node_=make_node(yylineno,-1,"RP");return RP; }
"[" { yylval.node_=make_node(yylineno,-1,"LB");return LB; }
"]" { yylval.node_=make_node(yylineno,-1,"RB");return RB; }
"{" { yylval.node_=make_node(yylineno,-1,"LC");return LC; }
"}" { yylval.node_=make_node(yylineno,-1,"RC");return RC; }
"struct" { yylval.node_=make_node(yylineno,-1,"STRUCT");return STRUCT; }
"return" { yylval.node_=make_node(yylineno,-1,"RETURN");return RETURN; }
"if" { yylval.node_=make_node(yylineno,-1,"IF");return IF; }
"else" { yylval.node_=make_node(yylineno,-1,"ELSE");return ELSE; }
"while" { yylval.node_=make_node(yylineno,-1,"WHILE");return WHILE; }
{relop} { yylval.node_=make_node(yylineno,-1,"RELOP");return RELOP; }
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
{error} {
    is_wrong = 1;
    printf("Error type %s at line %d : %s%s\n","A",yylineno,"Mysterious character ",yytext);
}
%%
