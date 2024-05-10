%locations
%{
    #include<stdio.h>
    #include"main.h"
    #include"def.h"
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylloc.last_line = yylineno; \
        yylloc.first_column = yycolumn; \
        yylloc.last_column = yycolumn + yyleng - 1; \
        yycolumn += yyleng;
    int yydebug = 1;
    treeNode root;
    extern FILE* fw;
%}
%union{
    treeNode node_;
}
%token <node_> INT  
%token <node_> FLOAT
%token <node_> SEMI COMMA TYPE STRUCT LC RC ID LB RB RETURN IF WHILE ASSIGNOP AND OR RELOP
%token <node_> PLUS MINUS STAR NOT DOT LP RP
%token <node_> ELSE DIV

%type <node_> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag Tag VarDec
%type <node_> FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%start Program
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left DOT RB LB LP RP

%nonassoc ELSE

%%
Program : ExtDefList    { $$ = make_node(yylineno,5,"Program");treeNode N_list[1]={$1};link_node($$,1,N_list);
    if(0) print_tree($$,0);
    if(is_wrong == 1) return;
    table = initTable(); 
    sementic_process($$); 
    interCodeList = newInterCodeList();
    genInterCodes($$);
    if( interError ==0 ) {
        printInterCode(fw, interCodeList);
    }
    deleteTable(table);}
    ;
    
ExtDefList : ExtDef ExtDefList  { $$ = make_node(yylineno,5,"ExtDefList");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | /* empty */       { $$ = NULL;}
    ;
ExtDef : Specifier ExtDecList SEMI { $$ = make_node(yylineno,5,"ExtDef");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Specifier SEMI    { $$ = make_node(yylineno,5,"ExtDef");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | Specifier FunDec CompSt { $$ = make_node(yylineno,5,"ExtDef");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Specifier error SEMI { is_wrong=1;$$ = make_node(yylineno,5,"ExtDef"); }
    | error SEMI  { is_wrong=1;$$ = make_node(yylineno,5,"ExtDef"); }
    | error Specifier SEMI { is_wrong=1;$$ = make_node(yylineno,5,"ExtDef"); }
;
ExtDecList : VarDec     { $$ = make_node(yylineno,5,"ExtDecList");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | VarDec COMMA ExtDecList   { $$ = make_node(yylineno,5,"ExtDecList");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | VarDec error ExtDefList { is_wrong=1; }
    ;
Specifier : TYPE        { $$ = make_node(yylineno,5,"Specifier");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | StructSpecifier   { $$ = make_node(yylineno,5,"Specifier");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    ;
StructSpecifier : STRUCT OptTag LC DefList RC { $$ = make_node(yylineno,5,"StructSpecifier");treeNode N_list[5]={$1,$2,$3,$4,$5};link_node($$,5,N_list); }
    | STRUCT Tag        { $$ = make_node(yylineno,5,"StructSpecifier");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    ;

OptTag : ID             { $$ = make_node(yylineno,5,"OptTag");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | /* empty */       { $$ = NULL;}
    ;
    
Tag : ID                { $$ = make_node(yylineno,5,"Tag");treeNode N_list[1]={$1};link_node($$,1,N_list); }
;

VarDec : ID             { $$ = make_node(yylineno,5,"VarDec");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | VarDec LB INT RB  { $$ = make_node(yylineno,5,"VarDec");treeNode N_list[4]={$1,$2,$3,$4};link_node($$,4,N_list); }
    | VarDec LB error RB { is_wrong=1; }
    | error RB { is_wrong=1; }
;

FunDec : ID LP VarList RP { $$ = make_node(yylineno,5,"FunDec");treeNode N_list[4]={$1,$2,$3,$4};link_node($$,4,N_list); }
    | ID LP RP          { $$ = make_node(yylineno,5,"FunDec");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | ID LP error RP { is_wrong=1; }
    | error LP VarList RP { is_wrong=1; }
;

VarList : ParamDec COMMA VarList { $$ = make_node(yylineno,5,"VarList");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | ParamDec          { $$ = make_node(yylineno,5,"VarList");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    ;
ParamDec : Specifier VarDec { $$ = make_node(yylineno,5,"ParamDec");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
;
CompSt : LC DefList StmtList RC { $$ = make_node(yylineno,5,"CompSt");treeNode N_list[4]={$1,$2,$3,$4};link_node($$,4,N_list); }
    | error RC { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
    ;
    
StmtList : Stmt StmtList { $$ = make_node(yylineno,5,"StmtList");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | /* empty */       { $$ = NULL;}
    ;
Stmt : Exp SEMI         { $$ = make_node(yylineno,5,"Stmt");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | CompSt            { $$ = make_node(yylineno,5,"Stmt");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | RETURN Exp SEMI   { $$ = make_node(yylineno,5,"Stmt");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | IF LP Exp RP Stmt  { $$ = make_node(yylineno,5,"Stmt");treeNode N_list[5]={$1,$2,$3,$4,$5};link_node($$,5,N_list); }
    | IF LP Exp RP Stmt ELSE Stmt { $$ = make_node(yylineno,5,"Stmt");treeNode N_list[7]={$1,$2,$3,$4,$5,$6,$7};link_node($$,7,N_list); }
    | WHILE LP Exp RP Stmt { $$ = make_node(yylineno,5,"Stmt");treeNode N_list[5]={$1,$2,$3,$4,$5};link_node($$,5,N_list); }
    | error SEMI    { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
    | Exp error SEMI { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
    | RETURN Exp error  { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
    | RETURN error SEMI  { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
    ;

DefList : Def DefList { $$ = make_node(yylineno,5,"DefList");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | /* empty */       { $$ = NULL;}
    ;
Def : Specifier DecList SEMI  { $$ = make_node(yylineno,5,"Def");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Specifier error SEMI { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
    | Specifier DecList error { is_wrong=1;$$ = make_node(yylineno,5,"CompSt"); }
;
DecList : Dec           { $$ = make_node(yylineno,5,"DecList");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | Dec COMMA DecList { $$ = make_node(yylineno,5,"DecList");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    ;
Dec : VarDec            { $$ = make_node(yylineno,5,"Dec");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | VarDec ASSIGNOP Exp  { $$ = make_node(yylineno,5,"Dec");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    ;
Exp : Exp ASSIGNOP Exp  { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp AND Exp       { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp OR Exp        { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp RELOP Exp     { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp PLUS Exp      { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp MINUS Exp     { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp STAR Exp      { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp DIV Exp       { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | LP Exp RP         { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | MINUS Exp         { $$ = make_node(yylineno,5,"Exp");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | NOT Exp           { $$ = make_node(yylineno,5,"Exp");treeNode N_list[2]={$1,$2};link_node($$,2,N_list); }
    | ID LP Args RP     { $$ = make_node(yylineno,5,"Exp");treeNode N_list[4]={$1,$2,$3,$4};link_node($$,4,N_list); }
    | ID LP RP          { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp LB Exp RB     { $$ = make_node(yylineno,5,"Exp");treeNode N_list[4]={$1,$2,$3,$4};link_node($$,4,N_list); }
    | Exp DOT ID        { $$ = make_node(yylineno,5,"Exp");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | ID                { $$ = make_node(yylineno,5,"Exp");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | INT               { $$ = make_node(yylineno,5,"Exp");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    | FLOAT             { $$ = make_node(yylineno,5,"Exp");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    ;
Args : Exp COMMA Args   { $$ = make_node(yylineno,5,"Args");treeNode N_list[3]={$1,$2,$3};link_node($$,3,N_list); }
    | Exp               { $$ = make_node(yylineno,5,"Args");treeNode N_list[1]={$1};link_node($$,1,N_list); }
    ;
%%
#include"lex.yy.c"
void yyerror(const char* msg){
    fprintf(stderr, "Error type B at line %d: %s.\n", yylineno, msg);
    return;
}
