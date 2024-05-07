#include<stdio.h>
#include<string.h>
#include"main.h"
#include<stdlib.h>
extern char* yytext;
extern char* yydebug;
void init_node(treeNode node){
    node->lineno=-1;
    node->next_bro=NULL;
    node->first_son=NULL;
    node->name=NULL;
    node->type=-1;
    return;
}
struct TreeNode* make_node(int line,int type,char* name){
    treeNode node = malloc(sizeof(struct TreeNode));
    init_node(node);
    node->lineno=line;
    node->type=type;
    node->name = (char *)malloc(10);
    strcpy(node->name,name);
    if(type == 0){ // !
        node->id =(char *)malloc(40);
        strcpy(node->id,yytext);
    }
    return node;
}
void link_node(treeNode father,int num,treeNode nodelist[]){
    father->first_son = nodelist[0];
    father->lineno = father->first_son->lineno;
    for (int i = 0; i < (num-1); i++){
        nodelist[i]->next_bro = nodelist[i+1];
    }
    return;
}
void print_tree(treeNode root,int index){
    for (int i = 0; i < index; i++){
        printf("  ");
    }
    printf("%s",root->name);
    if (root->type==0){
        printf(": %s",root->id);
    }
    else if (root->type == 1)
    {
        printf(": %d",root->INT);
    }
    else if(root->type == 2){
        printf(": %f",root->FLOAT);
    }
    if (root->first_son != NULL){
        printf(" (%d)",root->lineno);
    }
    printf("\n");
    treeNode tmp = root->first_son;
    while (tmp != NULL){
        print_tree(tmp,index+1);
        tmp = tmp->next_bro;
    }
    return;
}
int hex_to_dig(char *hex){
    int num = 0;
    hex=hex+2;
    while (*hex!='\0'){
        if (*hex >= '0' && *hex <= '9'){
            num *= 16; 
            num += (*hex -'0');
        }
        else{
            num *= 16; 
            num += (tolower(*hex) - 'a' + 10);
        }
        hex++;
    }
    return num;
}

int ox_to_dig(char *ox){
    int num = 0;
    ox=ox+1;
    while (*ox!='\0'){
        num *=8;
        num +=(*ox-'0');
        ox++;
    }    
    return num;
}
int main(int argc, char** argv){
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f){
        perror(argv[1]);
        return 1;
    }
    is_wrong = 0;
    yyrestart(f);
    // yydebug=1;
    yyparse();
    return 0;
}