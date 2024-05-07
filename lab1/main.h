# include <stdio.h>
# include <string.h>
struct TreeNode
{
    struct TreeNode* next_bro;
    struct TreeNode* first_son;
    int lineno;
    char* name;
    int type;
    char* id;//0
    int INT;//1
    float FLOAT;//2
};
int is_wrong;
extern int yylineno;
typedef struct TreeNode* treeNode;
struct TreeNode* make_node(int line,int type,char* name);
void init_node(treeNode node);
void link_node(treeNode father,int num,treeNode nodelist[]);
void print_tree(treeNode root,int index);
int hex_to_dig(char *hex);
int ox_to_dig(char *ox);