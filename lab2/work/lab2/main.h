# include <stdio.h>
# include <string.h>
struct TreeNode
{
    struct TreeNode* next_bro;
    struct TreeNode* first_son;
    int lineno;
    char* name; // ID | ExtDef
    int type;
    char* id;// fibonacci
    int INT;//1
    float FLOAT;//2
};
static inline char* newString(char* src) {
    if (src == NULL) return NULL;
    int length = strlen(src) + 1;
    char* p = (char*)malloc(sizeof(char) * length);
    check(p != NULL);
    strncpy(p, src, length);
    return p;
}
int is_wrong;
extern int yylineno;
typedef struct TreeNode* treeNode;
struct TreeNode* make_node(int line,int type,char* name);
void init_node(treeNode node);
void link_node(treeNode father,int num,treeNode nodelist[]);
void print_tree(treeNode root,int index);
int hex_to_dig(char *hex);
int ox_to_dig(char *ox);

typedef struct type* pType;
typedef struct fieldList* pFieldList;
typedef struct tableItem* pItem;
typedef struct hashTable* pHash;
typedef struct stack* pStack;
typedef struct table* pTable;
enum { 
    BASIC, 
    ARRAY, 
    STRUCTURE, 
    FUNCTION 
};
enum{ 
    INT_TYPE, 
    FLOAT_TYPE 
};
typedef struct type {
    int kind;
    int basic;
    struct {
        pType elem;
        int size;
    } array;
    struct {
        char* structName;
        pFieldList field;
    } structure;
    struct {
        int argc;          
        pFieldList argv;   
        pType returnType;  
    } function;

} Type;
void check(int exp);
typedef struct fieldList {
    char* name;       
    pType type;       
    pFieldList next;  
} FieldList;

typedef struct tableItem {
    int symbolDepth;
    pFieldList field;
    pItem next_Item;
    pItem next_Hash; 
} TableItem;

typedef struct hashTable {
    pItem* hashArray;
} HashTable;

typedef struct stack {
    pItem* stackArray;
    int curStackDepth;
} Stack;

typedef struct table {
    pHash hash;
    pStack stack;
} Table;

extern pTable table;

pType newType(int kind, ...);
pType copyType(pType src);
void deleteType(pType type);
int checkType(pType type1, pType type2);
pFieldList newFieldList(char* newName, pType newType);
pFieldList copyFieldList(pFieldList src);
void deleteFieldList(pFieldList fieldList);
void setFieldListName(pFieldList p, char* newName);

pTable initTable();
void deleteTable(pTable table);
pItem searchTableItem(pTable table, char* name);
int check_conflict(pTable table, pItem item);
void insert_Item(pTable table, pItem item);
void delete_Item(pTable table, pItem item);
void clear_scope_stack(pTable table);

pItem newItem(int symbolDepth, pFieldList pfield);
void deleteItem(pItem item);
int isStructDef(pItem src);
pHash newHash();
void deleteHash(pHash hash);
pItem getHashTop(pHash hash, int index);
void setHashTop(pHash hash, int index, pItem newVal);

pStack newStack();
void deleteStack(pStack stack);
void enter_scope(pStack stack);
void leave_scope(pStack stack);
pItem get_scope_stackhead(pStack stack);
void insert_scope_stackhead(pStack stack, pItem newVal);

static unsigned int hash_pjw(char* name) {
    unsigned int val = 0, i;
    for (; *name; ++name) {
        val = (val << 2) + *name;
        if (i = val & ~0x3fff)
            val = (val ^ (i >> 12)) & 0x3fff;
    }
    return val;
}

void sementic_process(treeNode node);

// Generate symbol table functions语法单元
void ExtDef(treeNode node);
pFieldList ParamDec(treeNode node);
void CompSt(treeNode node, pType returnType);
void StmtList(treeNode node, pType returnType);
void Stmt(treeNode node, pType returnType);
pItem VarDec(treeNode node, pType specifier);
void FunDec(treeNode node, pType returnType);
void Args(treeNode node, pItem funcInfo);
void ExtDecList(treeNode node, pType specifier);
pType Specifier(treeNode node);
pType StructSpecifier(treeNode node);
void DefList(treeNode node, pItem structInfo);
void Def(treeNode node, pItem structInfo);
void DecList(treeNode node, pType specifier, pItem structInfo);
void Dec(treeNode node, pType specifier, pItem structInfo);
pType Exp(treeNode node);
void VarList(treeNode node, pItem func);
// important
static void Error(int type, int line, char* msg) {
    printf("Error type %d at Line %d: %s\n", type, line, msg);
}

