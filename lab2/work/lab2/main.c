#include<stdio.h>
#include<string.h>
#include"main.h"
#include"def.h"
#include<stdarg.h>
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
    if(type == TYPE_ID){ // !
        node->id =(char *)malloc(40);
        strcpy(node->id,yytext);
    }
    if(type == TYPE_TY){
        node->id =(char *)malloc(40);
        strcpy(node->id,yytext);
    }
    return node;
}
void link_node(treeNode father,int num,treeNode nodelist[]){
    father->first_son = nodelist[0];
    // if(!strcmp(father->name,"Stmt")){
    //     printf("%d\n",num);
    // }
    father->lineno = father->first_son->lineno;
    treeNode tmplist[50];
    int index = 0;
    for (int i = 0; i < num; i++)
    {
        if (nodelist[i]==NULL)
        {
            continue;
        }
        tmplist[index] = nodelist[i];
        index ++;
    }
    for (int i = 0; i < (index-1); i++)
    {
        tmplist[i]->next_bro = tmplist[i+1];
    }
    tmplist[index-1]->next_bro = NULL;
    // for (int i = 0; i < (num-1); i++){
    //     while(nodelist[i]==NULL && i < (num-1)){
    //         for (int j = i; j < (num-1); j++)
    //         {
    //             nodelist[j] = nodelist[j+1];
    //         }
    //         num -= 1;
    //     }
    //     nodelist[i]->next_bro = nodelist[i+1];
    // }
    // return;
}
void print_tree(treeNode root,int index){
    if(root == NULL){
        return;
    }
    for (int i = 0; i < index; i++){
        printf("  ");
    }
    printf("%s",root->name);
    if (root->type==TYPE_ID||root->type == TYPE_TY){ 
        printf(": %s",root->id);
    }
    else if (root->type == TYPE_INT) 
    {
        printf(": %d",root->INT);
    }
    else if(root->type == TYPE_FLOAT){ 
        printf(": %f",root->FLOAT);
    }
    if (root->first_son != NULL){
        printf(" (%d)",root->lineno);
    }
    printf("\n"); // -1 == non_terminal
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
pTable table;//全局符号表

// Done
pType newType(int kind, ...) {
    pType p = (pType)malloc(sizeof(Type));
    check(p != NULL);
    p->kind = kind;
    va_list vaList;
    if (kind == BASIC)
    {
        va_start(vaList, 1);
        p->basic = va_arg(vaList, int);
    }
    else if (kind == ARRAY)
    {
        va_start(vaList, 2);
        p->array.elem = va_arg(vaList, pType);
        p->array.size = va_arg(vaList, int);
    }
    else if (kind == FUNCTION)
    {
        va_start(vaList, 3);
        p->function.argc = va_arg(vaList, int);
        p->function.argv = va_arg(vaList, pFieldList);
        p->function.returnType = va_arg(vaList, pType);
    }
    else if (kind == STRUCTURE)
    {
        va_start(vaList, 2);
        p->structure.structName = va_arg(vaList, char*);
        p->structure.field = va_arg(vaList, pFieldList);
    }
    else{
        printf("NewType Error!\n");
        exit(0);
    }
    va_end(vaList);
    return p;
}

// Done
pType copyType(pType src) {
    if (src == NULL) return NULL;
    pType p = (pType)malloc(sizeof(Type));
    check(p != NULL);
    p->kind = src->kind;
    check(p->kind == BASIC || p->kind == ARRAY || p->kind == STRUCTURE ||
           p->kind == FUNCTION);
    switch (p->kind) {
        case BASIC:
            p->basic = src->basic;
            break;
        case ARRAY:
            p->array.elem = copyType(src->array.elem);
            p->array.size = src->array.size;
            break;
        case STRUCTURE:
            p->structure.structName = newString(src->structure.structName);
            p->structure.field = copyFieldList(src->structure.field);
            break;
        case FUNCTION:
            p->function.argc = src->function.argc;
            p->function.argv = copyFieldList(src->function.argv);
            p->function.returnType = copyType(src->function.returnType);
            break;
    }

    return p;
}

void deleteType(pType type) {
    check(type != NULL);
    pFieldList temp = NULL;
    // pFieldList tDelete = NULL;
    switch (type->kind) {
        case BASIC:
            break;
        case ARRAY:
            deleteType(type->array.elem);
            type->array.elem = NULL;
            break;
        case STRUCTURE:
            if (type->structure.structName)
                free(type->structure.structName);
            type->structure.structName = NULL;

            temp = type->structure.field;
            while (temp) {
                pFieldList tDelete = temp;
                temp = temp->next;
                deleteFieldList(tDelete);
            }
            type->structure.field = NULL;
            break;
        case FUNCTION:
            deleteType(type->function.returnType);
            type->function.returnType = NULL;
            temp = type->function.argv;
            while (temp) {
                pFieldList tDelete = temp;
                temp = temp->next;
                deleteFieldList(tDelete);
            }
            type->function.argv = NULL;
            break;
        default:
            return;
            break;
    }
    free(type);
}

int checkType(pType type1, pType type2) {
    if (type1 == NULL || type2 == NULL) return 1;
    if (type1->kind == FUNCTION || type2->kind == FUNCTION) return 0;
    if (type1->kind != type2->kind)
        return 0;
    else {
        switch (type1->kind) {
            case BASIC:
                return type1->basic == type2->basic;
            case ARRAY:
                return checkType(type1->array.elem, type2->array.elem);
            case STRUCTURE:
                return !strcmp(type1->structure.structName,
                               type2->structure.structName);
            default:
                printf("Type Error!");
        }
    }
}

// Done
pFieldList newFieldList(char* newName, pType newtype) {
    pFieldList p = (pFieldList)malloc(sizeof(FieldList));
    check(p != NULL);
    p->name = newString(newName);
    p->type = newtype;
    p->next = NULL;
    return p;
}

pFieldList copyFieldList(pFieldList src) {
    check(src != NULL);
    pFieldList head = NULL, cur = NULL;
    pFieldList temp = src;

    while (temp) {
        if (!head) {
            head = newFieldList(temp->name, copyType(temp->type));
            cur = head;
            temp = temp->next;
        } else {
            cur->next = newFieldList(temp->name, copyType(temp->type));
            cur = cur->next;
            temp = temp->next;
        }
    }
    return head;
}

void deleteFieldList(pFieldList fieldList) {
    check(fieldList != NULL);
    if (fieldList->name) {
        free(fieldList->name);
        fieldList->name = NULL;
    }
    if (fieldList->type) deleteType(fieldList->type);
    fieldList->type = NULL;
    free(fieldList);
}

void setFieldListName(pFieldList p, char* newName) {
    check(p != NULL && newName != NULL);
    if (p->name != NULL) {
        free(p->name);
    }
    p->name = newString(newName);
}

// Done
pItem newItem(int symbolDepth, pFieldList pfield) {
    pItem p = (pItem)malloc(sizeof(TableItem));
    check(p != NULL);
    p->symbolDepth = symbolDepth;
    p->field = pfield;
    p->next_Hash = NULL;
    p->next_Item = NULL;
    return p;
}

void check(int exp){
    if(exp == 0){
        printf("Check Error!\n");
        exit(0);
    }
}

void deleteItem(pItem item) {
    check(item != NULL);
    if (item->field != NULL) deleteFieldList(item->field);
    //printf("Item\n");
    free(item);
}

// Done
pHash newHash() {
    pHash p = (pHash)malloc(sizeof(HashTable));
    check(p != NULL);
    p->hashArray = (pItem*)malloc(sizeof(pItem) * 0x3fff);
    check(p->hashArray != NULL);
    for (int i = 0; i < 0x3fff; i++) {
        p->hashArray[i] = NULL;
    }
    return p;
}

void deleteHash(pHash hash) {
    check(hash != NULL);
    for (int i = 0; i < 0x3fff; i++) {
        pItem temp = hash->hashArray[i];
        while (temp) {
            pItem tdelete = temp;
            temp = temp->next_Hash;
            deleteItem(tdelete);
        }
        hash->hashArray[i] = NULL;
    }
    //printf("Hash\n");
    free(hash->hashArray);
    hash->hashArray = NULL;
    free(hash);
}

pItem getHashTop(pHash hash, int index) {
    check(hash != NULL);
    return hash->hashArray[index];
}

void setHashTop(pHash hash, int index, pItem newVal) {
    check(hash != NULL);
    hash->hashArray[index] = newVal;
}

pTable initTable() {
    pTable table = (pTable)malloc(sizeof(Table));
    check(table != NULL);
    table->hash = newHash();
    table->stack = newStack();
    return table;
};

void deleteTable(pTable table) {
    deleteHash(table->hash);
    table->hash = NULL;
    deleteStack(table->stack);
    table->stack = NULL;
    free(table);
};

pItem searchTableItem(pTable table, char* name) {
    unsigned hashCode = hash_pjw(name);
    // print_all(table);
    // printf("%d\n",hashCode);
    pItem temp = getHashTop(table->hash, hashCode);
    if (temp == NULL) return NULL;
    while (temp) {
        // printf("%s = %s\n",temp->field->name,name);
        if (!strcmp(temp->field->name, name)) return temp;
        temp = temp->next_Hash;
    }
    return NULL;
}

// 无冲突返回FALSE, 有冲突返回TRUE
// Done
int check_conflict(pTable table, pItem item) {
    pItem temp = searchTableItem(table, item->field->name);
    if (temp == NULL) return 0; 
    while (temp) {
        if (!strcmp(temp->field->name, item->field->name)) {
            // 重命名结构体的情况
            // printf("%p\n",item->field->type);
            if (item->field->type == NULL) // add maybe delete
            {
                return 0;
            }
            
            if (temp->field->type->kind == STRUCTURE || item->field->type->kind == STRUCTURE) 
                return 1;
            // 重命名同个域下变量的情况
            if (temp->symbolDepth == table->stack->curStackDepth) return 1;
        }
        temp = temp->next_Hash;
    }
    return 0;
}

//插入符号表
void insert_Item(pTable table, pItem item) {
    check(table != NULL && item != NULL);
    unsigned hashCode = hash_pjw(item->field->name); 
    pHash hash = table->hash;
    pStack stack = table->stack;
    item->next_Item = get_scope_stackhead(stack);
    insert_scope_stackhead(stack, item);

    item->next_Hash = getHashTop(hash, hashCode); 
    setHashTop(hash, hashCode, item);
}

void delete_Item(pTable table, pItem item) {
    check(table != NULL && item != NULL);
    unsigned hashCode = hash_pjw(item->field->name);
    if (item == getHashTop(table->hash, hashCode))
        setHashTop(table->hash, hashCode, item->next_Hash);
    else {
        pItem cur = getHashTop(table->hash, hashCode);
        pItem last = cur;
        while (cur != item) {
            last = cur;
            cur = cur->next_Hash;
        }
        last->next_Hash = cur->next_Hash;
    }
    deleteItem(item);
}

int isStructDef(pItem src) {
    if (src == NULL) return 0;
    if (src->field->type == NULL) return 0;
    if (src->field->type->kind != STRUCTURE) return 0;
    if (src->field->type->structure.structName) return 0; // TODO
    return 1;
}

void clear_scope_stack(pTable table) {
    check(table != NULL);
    pStack stack = table->stack;
    pItem temp = get_scope_stackhead(stack);
    while (temp) {
        pItem tDelete = temp;
        temp = temp->next_Item;
        delete_Item(table, tDelete);
    }
    insert_scope_stackhead(stack, NULL);
    leave_scope(stack);
}


// Stack functions
pStack newStack() {
    pStack p = (pStack)malloc(sizeof(Stack));
    if(p == NULL){
        printf("Error1 \n");
        exit(0);
    };
    p->stackArray = (pItem*)malloc(sizeof(pItem) * 0x3fff);
    if(p->stackArray == NULL){
        printf("Error2 \n");
        exit(0);
    };
    for (int i = 0; i < 0x3fff; i++) {
        p->stackArray[i] = NULL;
    }
    p->curStackDepth = 0;
    return p;
}

void deleteStack(pStack stack) {
    if(stack == NULL){
        printf("Error5 \n");
        exit(0);
    };
    //printf("Stack\n");
    free(stack->stackArray);
    stack->stackArray = NULL;
    stack->curStackDepth = 0;
    free(stack);
}

void enter_scope(pStack stack) {
    if(stack == NULL){
        printf("Error4 \n");
        exit(0);
    };
    stack->curStackDepth++;
}

void leave_scope(pStack stack) {
    if(stack == NULL){
        printf("Error11 \n");
        exit(0);
    };
    stack->curStackDepth--;
}

pItem get_scope_stackhead(pStack stack) {
    if(stack == NULL){
        printf("Error Get\n");
        exit(0);
    };
    return stack->stackArray[stack->curStackDepth];
    // return p == NULL ? NULL : p->stackArray[p->curStackDepth];
}

void insert_scope_stackhead(pStack stack, pItem newVal) {
    if(stack == NULL){
        printf("Error set\n");
        exit(0);
    };
    stack->stackArray[stack->curStackDepth] = newVal;
}

// Global function
void sementic_process(treeNode node) {
    if (node == NULL){
        return;
    }
    // printf("%s\n",node->name);
    // if((!strcmp(node->name, "ExtDef")|| (!strcmp(node->name, "STRUCTSpecifier"))
    if (!strcmp(node->name, "ExtDef")) {
        // ExtDefList : ExtDef ExtDefList
        ExtDef(node);
    } 
    sementic_process(node->first_son);
    sementic_process(node->next_bro);
}

// Generate symbol table functions
void ExtDef(treeNode node) {

    pType specifierType = Specifier(node->first_son);
    // printf("%p",specifierType);
    char* secondName = node->first_son->next_bro->name;
    // ExtDef -> Specifier ExtDecList SEMI
    if (!strcmp(secondName, "ExtDecList")) {
        ExtDecList(node->first_son->next_bro, specifierType);
    }
    // ExtDef -> Specifier FunDec CompSt
    // if (!strcmp(secondName, "FunDec")) {
    //     FunDec(node->first_son->next_bro, specifierType);
    // }
    if (!strcmp(secondName, "FunDec")) {
        FunDec(node->first_son->next_bro, specifierType);
        CompSt(node->first_son->next_bro->next_bro, specifierType);
    }
    if (specifierType) {
        deleteType(specifierType);
    }
}

// Done

void ExtDecList(treeNode node, pType specifier) {
    check(node != NULL);
    treeNode tmp = node;
    while (tmp) {
        pItem item = VarDec(tmp->first_son, specifier);
        if (check_conflict(table, item)) {
            char msg[100] = {0};
            sprintf(msg, "Redefined variable \"%s\".", item->field->name);
            Error(REDEF_VAR, tmp->lineno, msg);
            deleteItem(item);
        } 
        else {
            insert_Item(table, item);
        }

        if (tmp->first_son != NULL && tmp->first_son->next_bro != NULL && tmp->next_bro->next_bro) {
            tmp = tmp->next_bro->next_bro->first_son;
        } else {
            break;
        }
    }
}

pType Specifier(treeNode node) {
    if(node == NULL){
        printf("Specifier Error!\n");
        return;
    }
    treeNode t = node->first_son;
    if (!strcmp(t->name, "TYPE")) {
        if (!strcmp(t->id, "float")) {
            return newType(BASIC, FLOAT_TYPE);
        } 
        else {
            return newType(BASIC, INT_TYPE);
        }
    }
    else {
        // 非TYPE 即STRUCT
        return StructSpecifier(t);
    }
}

pType StructSpecifier(treeNode node) {
    if(node == NULL){
        printf("StructSpecifier Error\n");
        exit(0);
    };
    pType returnType = NULL;
    treeNode tmp = node->first_son->next_bro;
    //StructSpecifier : STRUCT OptTag LC DefList RC
    if (strcmp(tmp->name, "Tag")) { // Not Tag
        pItem structItem =newItem(table->stack->curStackDepth,newFieldList("", newType(STRUCTURE, NULL, NULL)));
        if (!strcmp(tmp->name, "OptTag")) { //if STRUCT OptTag
            setFieldListName(structItem->field, tmp->first_son->id);
            tmp = tmp->next_bro;// LC
        }
        else { // 匿名结构体
            // TODO
        }
        // Deflist
        if (!strcmp(tmp->next_bro->name, "DefList")) {
            DefList(tmp->next_bro, structItem);
        }

        if (check_conflict(table, structItem)) { 
            char msg[100] = {0};
            sprintf(msg, "Duplicated name \"%s\".", structItem->field->name);
            Error(DUPLICATED_NAME, node->lineno, msg);
            deleteItem(structItem);
        } 
        else {
            returnType = newType(STRUCTURE, newString(structItem->field->name),copyFieldList(structItem->field->type->structure.field));

            if (!strcmp(node->first_son->next_bro->name, "OptTag")) {
                insert_Item(table, structItem);
            }
            else { // TODO
                deleteItem(structItem);
            }
        }

     //结束
    }
    // Stuct Tag <- struct complex;
    else {
        
        pItem structItem = searchTableItem(table, tmp->first_son->id);
        if (structItem == NULL || !isStructDef(structItem)) {
            // 没有这个结构体 or 结构体名称被占用 
            // if(structItem == NULL){
            //     printf("debug1\n");
            // }
            char msg[100] = {0};
            sprintf(msg, "Undefined structure \"%s\".", tmp->first_son->id);
            Error(UNDEF_STRUCT, node->lineno, msg);
        } 
        else
            returnType = newType(STRUCTURE, newString(structItem->field->name),copyFieldList(structItem->field->type->structure.field));
    }
    return returnType;
}

pItem VarDec(treeNode node, pType specifier) {
    check(node != NULL);
    // VarDec -> ID
    //         | VarDec LB INT RB
    treeNode id = node;
    while (id->first_son) id = id->first_son;
    pItem p = newItem(table->stack->curStackDepth, newFieldList(id->id, NULL));
    // 得到最内层 ID
    // VarDec -> ID  int num;
    if (!strcmp(node->first_son->name, "ID")) {
        p->field->type = copyType(specifier);
    }
    // VarDec -> VarDec LB INT RB  num[2][3];
    else {
        treeNode varDec = node->first_son;
        pType temp = specifier;

        while (varDec->next_bro) {
            p->field->type =newType(ARRAY, copyType(temp),varDec->next_bro->next_bro->INT);
            temp = p->field->type;
            varDec = varDec->first_son;
        }
    }
    return p;
}

// Done

void FunDec(treeNode node, pType returnType) {
    check(node != NULL);
    // FunDec -> ID LP VarList RP
    //         | ID LP RP
    pItem p =newItem(table->stack->curStackDepth,newFieldList(node->first_son->id,newType(FUNCTION, 0, NULL, copyType(returnType))));

    // FunDec -> ID LP VarList RP
    if (!strcmp(node->first_son->next_bro->next_bro->name, "VarList")) {
        VarList(node->first_son->next_bro->next_bro, p);
    }

    // FunDec -> ID LP RP don't need process

    // check redefine
    if (check_conflict(table, p)) {
        char msg[100] = {0};
        sprintf(msg, "Redefined function \"%s\".", p->field->name);
        Error(REDEF_FUNC, node->lineno, msg);
        deleteItem(p);
        p = NULL;
    } else {
        insert_Item(table, p);
    }
}

void VarList(treeNode node, pItem func) {
    check(node != NULL);
    // VarList -> ParamDec COMMA VarList
    //          | ParamDec
    enter_scope(table->stack);
    int argc = 0;
    treeNode temp = node->first_son;
    pFieldList cur = NULL;

    // VarList -> ParamDec
    pFieldList paramDec = ParamDec(temp);
    func->field->type->function.argv = copyFieldList(paramDec);
    cur = func->field->type->function.argv;
    argc++;

    // VarList -> ParamDec COMMA VarList
    while (temp->next_bro) {
        temp = temp->next_bro->next_bro->first_son;
        paramDec = ParamDec(temp);
        if (paramDec) {
            cur->next = copyFieldList(paramDec);
            cur = cur->next;
            argc++;
        }
    }

    func->field->type->function.argc = argc;

    leave_scope(table->stack);
}

pFieldList ParamDec(treeNode node) {
    check(node != NULL);
    // ParamDec -> Specifier VarDec
    pType specifierType = Specifier(node->first_son);
    pItem p = VarDec(node->first_son->next_bro, specifierType);
    if (specifierType) deleteType(specifierType);
    if (check_conflict(table, p)) {
        char msg[100] = {0};
        sprintf(msg, "Redefined variable \"%s\".", p->field->name);
        Error(REDEF_VAR, node->lineno, msg);
        deleteItem(p);
        return NULL;
    } else {
        insert_Item(table, p);
        return p->field;
    }
}

void CompSt(treeNode node, pType returnType) {
    check(node != NULL);
    // CompSt -> LC DefList StmtList RC
    // printTree(node, 0);
    enter_scope(table->stack);
    // printf("%p",node->first_son);
    treeNode temp = node->first_son->next_bro;
    if (!strcmp(temp->name, "DefList")) {
        DefList(temp, NULL);
        temp = temp->next_bro;
    }
    if (!strcmp(temp->name, "StmtList")) {
        StmtList(temp, returnType);
    }
    clear_scope_stack(table);
}

void StmtList(treeNode node, pType returnType) {
    // check(node != NULL);
    // StmtList -> Stmt StmtList
    //           | e
    // printTree(node, 0);
    while (node) {
        Stmt(node->first_son, returnType);
        node = node->first_son->next_bro;
    }
}

void Stmt(treeNode node, pType returnType) {
    check(node != NULL);
    // Stmt -> Exp SEMI
    //       | CompSt
    //       | RETURN Exp SEMI
    //       | IF LP Exp RP Stmt
    //       | IF LP Exp RP Stmt ELSE Stmt
    //       | WHILE LP Exp RP Stmt
    // printTree(node, 0);

    pType expType = NULL;
    // Stmt -> Exp SEMI
    if (!strcmp(node->first_son->name, "Exp")) expType = Exp(node->first_son);

    // Stmt -> CompSt
    else if (!strcmp(node->first_son->name, "CompSt"))
        CompSt(node->first_son, returnType);

    // Stmt -> RETURN Exp SEMI
    else if (!strcmp(node->first_son->name, "RETURN")) {
        expType = Exp(node->first_son->next_bro);

        // check return type
        if (!checkType(returnType, expType))
            Error(TYPE_MISMATCH_RETURN, node->lineno,
                   "Type mismatched for return.");
    }

    // Stmt -> IF LP Exp RP Stmt
    // Stmt -> IF LP Exp RP Stmt ELSE Stmt
    else if (!strcmp(node->first_son->name, "IF")) {
        treeNode stmt = node->first_son->next_bro->next_bro->next_bro->next_bro;
        expType = Exp(node->first_son->next_bro->next_bro);
        Stmt(stmt, returnType);
        // Stmt -> IF LP Exp RP Stmt ELSE Stmt
        if (stmt->next_bro != NULL) Stmt(stmt->next_bro->next_bro, returnType);
    }

    // Stmt -> WHILE LP Exp RP Stmt
    else if (!strcmp(node->first_son->name, "WHILE")) {
        expType = Exp(node->first_son->next_bro->next_bro);
        Stmt(node->first_son->next_bro->next_bro->next_bro->next_bro, returnType);
    }

    if (expType) deleteType(expType);
}

void DefList(treeNode node, pItem structInfo) {
    // DefList -> Def DefList
    //          | /*empty*/ 
    // printf("mark1\n\n");
    while (node) { // get Deflist
        Def(node->first_son, structInfo);
        node = node->first_son->next_bro;
    }
}

void Def(treeNode node, pItem structInfo) {
    check(node != NULL);
    // Def -> Specifier DecList SEMI
    pType dectype = Specifier(node->first_son);
    DecList(node->first_son->next_bro, dectype, structInfo);
    if (dectype) deleteType(dectype);
}

void DecList(treeNode node, pType specifier, pItem structInfo) {
    check(node != NULL);
    treeNode temp = node;
    while (temp) {
        Dec(temp->first_son, specifier, structInfo);
        if (temp->first_son->next_bro)
            temp = temp->first_son->next_bro->next_bro; // Dec COMMA DecList
        else
            break;
    }
}

void Dec(treeNode node, pType specifier, pItem structInfo) {
    check(node != NULL);
    // Dec -> VarDec
    //      | VarDec ASSIGNOP Exp

    // Dec -> VarDec
    if (node->first_son->next_bro == NULL) {
        if (structInfo != NULL) { // if 进入结构体判断 
            // 结构体内，将VarDec返回的Item中的filedList
            // Copy判断是否重定义，无错则到结构体链表尾 
            pItem decitem = VarDec(node->first_son, specifier);
            pFieldList payload = decitem->field;
            pFieldList structField = structInfo->field->type->structure.field;
            pFieldList last = NULL;
            while (structField != NULL) {
                // then we have to check
                if (!strcmp(payload->name, structField->name)) {
                    //出现重定义，报错
                    char msg[100] = {0};
                    sprintf(msg, "Redefined field \"%s\".",decitem->field->name);
                    Error(REDEF_FEILD, node->lineno, msg);
                    deleteItem(decitem);
                    return;
                } 
                else {
                    last = structField;
                    structField = structField->next;
                }
            }

            if (last != NULL) {
                last->next = copyFieldList(decitem->field);
            } 
            else {
                structInfo->field->type->structure.field = copyFieldList(decitem->field);
            }
            deleteItem(decitem);
            // 临时变量可以free了
        } 
        else {
            // 非结构体内，判断返回的item有无冲突，无冲突放入表中，有冲突报错delete
            
            pItem decitem = VarDec(node->first_son, specifier);
            if (check_conflict(table, decitem)) {
                //出现冲突，报错
                char msg[100] = {0};
                sprintf(msg, "Redefined variable \"%s\".",
                        decitem->field->name);
                Error(REDEF_VAR, node->lineno, msg);
                deleteItem(decitem);
            } else {
                insert_Item(table, decitem);
            }
        }
    }
    // Dec -> VarDec ASSIGNOP Exp
    else {
        if (structInfo != NULL) {
            // 结构体内不能赋值，报错
            Error(REDEF_FEILD, node->lineno,"Illegal initialize variable in struct.");
        } else {
            // 判断赋值类型是否相符
            //如果成功，注册该符号
            pItem decitem = VarDec(node->first_son, specifier);
            pType exptype = Exp(node->first_son->next_bro->next_bro);
            if (check_conflict(table, decitem)) {
                //出现冲突，报错
                char msg[100] = {0};
                sprintf(msg, "Redefined variable \"%s\".",
                        decitem->field->name);
                Error(REDEF_VAR, node->lineno, msg);
                deleteItem(decitem);
                return;
            }
            // if (!checkType(decitem->field->type, exptype)) {
            //     //类型不相符
            //     //报错
            //     Error(TYPE_MISMATCH_ASSIGN, node->lineno,"Type mismatched for assignment.");
            //     deleteItem(decitem);
            //     if (exptype) deleteType(exptype);

            // }
            // printf("%d\n",decitem->field->type->kind);
            // printf("%p\n",decitem->field->type);
            if (!checkType(decitem->field->type, exptype) || (decitem->field->type && decitem->field->type->kind == ARRAY)) {
                //报错，对非basic类型赋值
                // printf("debug1\n");
                Error(TYPE_MISMATCH_ASSIGN, node->lineno, "Type mismatched for assignment_.");
                deleteItem(decitem);
            } 
            else {
                // printf("debug1\n");
                insert_Item(table, decitem);
            }
            if (exptype) deleteType(exptype);
        }
    }
}

pType Exp(treeNode node) {
    check(node != NULL);
    treeNode t = node->first_son;
    //  print_all(table);
    //二值运算
    if (!strcmp(t->name, "Exp")) {
        // 基本数学运算符
        // 分类讨论 
        if (strcmp(t->next_bro->name, "LB") && strcmp(t->next_bro->name, "DOT")) {
            // 不是 main(1) main.s的形式
            pType p1 = Exp(t);
            pType p2 = Exp(t->next_bro->next_bro);
            pType returnType = NULL;

            // Exp -> Exp ASSIGNOP Exp
            if (!strcmp(t->next_bro->name, "ASSIGNOP")) {
                //检查左值
                treeNode tchild = t->first_son;

                if (!strcmp(tchild->name, "FLOAT") ||
                    !strcmp(tchild->name, "INT")) {
                    //报错， 左值不能是常数s
                    Error(LEFT_ASSIGN, t->lineno,"The left-hand side of an assignment must be avariable.");

                } 
                // else if (!strcmp(tchild->name, "ID") && !strcmp(tchild->next_bro->name, "LP")){
                //     Error(TYPE_MISMATCH_ASSIGN, t->lineno,"Type mismatched for assignment.");
                // }
                else if (!strcmp(tchild->name, "ID") ||
                           !strcmp(tchild->next_bro->name, "LB") ||
                           !strcmp(tchild->next_bro->name, "DOT")) {
                            // 接受 s= s[1]= or s.s=
                    if(tchild->next_bro!=NULL &&!strcmp(tchild->next_bro->name, "LP")){
                        Error(LEFT_ASSIGN, t->lineno,"Type mismatched for assignment.");
                    }
                    if (!checkType(p1, p2)) {
                        //报错，类型不匹配
                        Error(TYPE_MISMATCH_ASSIGN, t->lineno,"Type mismatched for assignment.");
                    } 
                    else
                        returnType = copyType(p1);
                } 
                else {
                    //报错，没遇见过的情况
                    Error(LEFT_ASSIGN, t->lineno,
                           "The left-hand side of an assignment must be "
                           "avariable.");
                }

            }
            // Exp -> Exp AND Exp
            //      | Exp OR Exp
            //      | Exp RELOP Exp
            //      | Exp PLUS Exp
            //      | Exp MINUS Exp
            //      | Exp STAR Exp
            //      | Exp DIV Exp
            else {
                if (p1 && p2 && (p1->kind == ARRAY || p2->kind == ARRAY)) {
                    //报错，涉及数组，结构体运算
                    Error(TYPE_MISMATCH_OP, t->lineno,
                           "Type mismatched for operands.");
                } 
                else if (!checkType(p1, p2)) {
                    //报错，类型不匹配
                    Error(TYPE_MISMATCH_OP, t->lineno,
                           "Type mismatched for operands.");
                } 
                else {
                    if (p1 && p2) {
                        returnType = copyType(p1);
                    }
                }
            }

            if (p1) deleteType(p1);
            if (p2) deleteType(p2);
            return returnType;
        }
        // 下面处理数组和结构体
        else {
            // Exp -> Exp LB Exp RB
            if (!strcmp(t->next_bro->name, "LB")) {
                //数组
                pType p1 = Exp(t);
                pType p2 = Exp(t->next_bro->next_bro);
                pType returnType = NULL;

                if (p1 == NULL) {
                    return;
                } 
                else if (p1 && p1->kind != ARRAY) {
                    //报错，非数组kind使用[] -> a[]
                    char msg[100] = {0};
                    // sprintf(msg, "\"%s\" is not an array.", t->first_son->id);
                    sprintf(msg, "use a none-array object.");
                    Error(NOT_A_ARRAY, t->lineno, msg);
                } 
                else if (!p2 || p2->kind != BASIC ||
                           p2->basic != INT_TYPE) {
                    //报错，不用int索引[] -> a[1.5]
                    char msg[100] = {0};
                    sprintf(msg, "input is not an INT.",
                            t->next_bro->next_bro->first_son->name);
                    Error(NOT_A_INT, t->lineno, msg);
                } 
                else {
                    returnType = copyType(p1->array.elem);
                }
                if (p1) deleteType(p1);
                if (p2) deleteType(p2);
                return returnType;
            }
            // Exp -> Exp DOT ID
            else {
                pType p1 = Exp(t);
                pType returnType = NULL;
                if (!p1 || p1->kind != STRUCTURE ||
                    !p1->structure.structName) {
                    //报错，对非结构体使用.运算符
                    Error(ILLEGAL_DOT_USE, t->lineno, "Illegal use of \".\".");
                    if (p1) deleteType(p1);
                } 
                else {
                    treeNode ref_id = t->next_bro->next_bro;
                    pFieldList structfield = p1->structure.field;
                    while (structfield != NULL) {
                        if (!strcmp(structfield->name, ref_id->id)) {
                            break;
                        }
                        structfield = structfield->next;
                    }
                    if (structfield == NULL) {
                        //报错，没有可以匹配的域名
                        printf("Error type %d at Line %d: %s.\n", 14, t->lineno,"Non-existent field");
                        ;
                    } 
                    else {
                        returnType = copyType(structfield->type);
                    }
                }
                if (p1) deleteType(p1);
                return returnType;
            }
        }
    }
    // Exp -> MINUS Exp
    //      | NOT Exp
    else if (!strcmp(t->name, "MINUS") || !strcmp(t->name, "NOT")) {
        pType p1 = Exp(t->next_bro);
        pType returnType = NULL;
        if (!p1 || p1->kind != BASIC) {
            //报错，数组结构体不支持运算
            printf("Error type %d at Line %d: %s.\n", 7, t->lineno,
                   "TYPE_MISMATCH_OP");
        } 
        else {
            returnType = copyType(p1);
        }
        if (p1) deleteType(p1);
        return returnType;
    } 
    // LP Exp RP
    else if (!strcmp(t->name, "LP")) {
        return Exp(t->next_bro);
    }
    // Exp -> ID LP Args RP
    //		| ID LP RP
    else if (!strcmp(t->name, "ID") && t->next_bro) {
        pItem funcInfo = searchTableItem(table, t->id);

        // function not find
        if (funcInfo == NULL) {
            char msg[100] = {0};
            sprintf(msg, "Undefined function \"%s\".", t->id);
            Error(UNDEF_FUNC, node->lineno, msg);
            return NULL;
        } 
        else if (funcInfo->field->type->kind != FUNCTION) {
            char msg[100] = {0};
            sprintf(msg, "\"i\" is not a function.", t->id);
            Error(NOT_A_FUNC, node->lineno, msg);
            return NULL;
        }
        // Exp -> ID LP Args RP
        else if (!strcmp(t->next_bro->next_bro->name, "Args")) {
            Args(t->next_bro->next_bro, funcInfo);
            return copyType(funcInfo->field->type->function.returnType);
        }
        // Exp -> ID LP RP
        else {
            if (funcInfo->field->type->function.argc != 0) {
                char msg[100] = {0};
                sprintf(msg,
                        "too few arguments to function \"%s\", except %d args.",
                        funcInfo->field->name,
                        funcInfo->field->type->function.argc);
                Error(FUNC_AGRC_MISMATCH, node->lineno, msg);
            }
            return copyType(funcInfo->field->type->function.returnType);
        }
    }
    // Exp -> ID
    else if (!strcmp(t->name, "ID")) {
        pItem tp = searchTableItem(table, t->id);
        if (tp == NULL || isStructDef(tp)) {
            char msg[100] = {0};
            sprintf(msg, "Undefined variable \"%s\".", t->id);
            Error(UNDEF_VAR, t->lineno, msg);
            return NULL;
        } 
        else {
            // 有定义且不是struct
            return copyType(tp->field->type);
        }
    } else {
        // Exp -> FLOAT
        if (!strcmp(t->name, "FLOAT")) {
            return newType(BASIC, FLOAT_TYPE);
        }
        // Exp -> INT
        else {
            return newType(BASIC, INT_TYPE);
        }
    }
}

void Args(treeNode node, pItem funcInfo) {
    check(node != NULL);
    // Args -> Exp COMMA Args
    //       | Exp
    treeNode temp = node;
    pFieldList arg = funcInfo->field->type->function.argv;
    while (temp) {
        if (arg == NULL) {
            char msg[100] = {0};
            sprintf(
                msg, "mismatch arguments to function \"%s\", except %d args.",
                funcInfo->field->name, funcInfo->field->type->function.argc);
            Error(FUNC_AGRC_MISMATCH, node->lineno, msg);
            break;
        }
        pType realType = Exp(temp->first_son);
        if (!checkType(realType, arg->type)) {
            char msg[100] = {0};
            sprintf(msg, "Function \"%s\" is not applicable for arguments.",
                    funcInfo->field->name);
            Error(FUNC_AGRC_MISMATCH, node->lineno, msg);
            if (realType) deleteType(realType);
            return;
        }
        if (realType) deleteType(realType);
        arg = arg->next;
        if (temp->first_son->next_bro) {
            temp = temp->first_son->next_bro->next_bro;
        } 
        else {
            break;
        }
    }
    if (arg != NULL) {
        char msg[100] = {0};
        sprintf(msg, "mismatch arguments to function \"%s\", except %d args.",
                funcInfo->field->name, funcInfo->field->type->function.argc);
        Error(FUNC_AGRC_MISMATCH, node->lineno, msg);
    }
}


int main(int argc, char** argv){
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f){
        printf("File Open Error!");
        return 1;
    }
    is_wrong = 0;
    yyrestart(f);
    // yydebug=1;
    yyparse();
    return 0;
}