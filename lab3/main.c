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
    node->id == NULL;
    strcpy(node->name,name);
    if(type != 5){ // !
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
    assert(table != NULL);
    table->hash = newHash();
    table->stack = newStack();

    // 添加read和write函数
    pItem readFun = newItem(
        0, newFieldList(newString("read"),
                        newType(FUNCTION, 0, NULL, newType(BASIC, INT_TYPE))));

    pItem writeFun = newItem(
        0, newFieldList(newString("write"),
                        newType(FUNCTION, 1,
                                newFieldList("arg1", newType(BASIC, INT_TYPE)),
                                newType(BASIC, INT_TYPE))));

    insert_Item(table, readFun);
    insert_Item(table, writeFun);

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
        p->field->isArg = 1;
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
            insert_Item(table, decitem);
            // Edit: 为lab3结构体分析做处理
            // deleteItem(decitem);
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

// func for lab3 
boolean interError = FALSE;
pInterCodeList interCodeList;

// Operand func
pOperand newOperand(int kind, ...) {
    pOperand p = (pOperand)malloc(sizeof(Operand));
    assert(p != NULL);
    p->kind = kind;
    va_list vaList;
    assert(kind >= 0 && kind < 6);
    va_start(vaList, 1);
    switch (kind) {
        case OP_CONSTANT:
            p->value = va_arg(vaList, int);
            break;
        case OP_VARIABLE:
        case OP_ADDRESS:
        case OP_LABEL:
        case OP_FUNCTION:
        case OP_RELOP:
            p->name = va_arg(vaList, char*);
            break;  
    }

    // p->isAddr = FALSE;

    return p;
}

void setOperand(pOperand p, int kind, void* val) {
    assert(p != NULL);
    assert(kind >= 0 && kind < 6);
    p->kind = kind;
    switch (kind) {
        case OP_CONSTANT:
            p->value = (int)val;
            break;
        case OP_VARIABLE:
        case OP_ADDRESS:
        case OP_LABEL:
        case OP_FUNCTION:
        case OP_RELOP:
            if (p->name) free(p->name);
            p->name = (char*)val;
            break;
    }
}

void deleteOperand(pOperand p) {
    if (p == NULL) return;
    assert(p->kind >= 0 && p->kind < 6);
    switch (p->kind) {
        case OP_CONSTANT:
            break;
        case OP_VARIABLE:
        case OP_ADDRESS:
        case OP_LABEL:
        case OP_FUNCTION:
        case OP_RELOP:
            if (p->name) {
                free(p->name);
                p->name = NULL;
            }
            break;
    }
    free(p);
}

void printOp(FILE* fp, pOperand op) {
    assert(op != NULL);
    if (fp == NULL) {
        switch (op->kind) {
            case OP_CONSTANT:
                printf("#%d", op->value);
                break;
            case OP_VARIABLE:
            case OP_ADDRESS:
            case OP_LABEL:
            case OP_FUNCTION:
            case OP_RELOP:
                printf("%s", op->name);
                break;
        }
    } else {
        switch (op->kind) {
            case OP_CONSTANT:
                fprintf(fp, "#%d", op->value);
                break;
            case OP_VARIABLE:
            case OP_ADDRESS:
            case OP_LABEL:
            case OP_FUNCTION:
            case OP_RELOP:
                fprintf(fp, "%s", op->name);
                break;
        }
    }
}

// InterCode func
pInterCode newInterCode(int kind, ...) {
    pInterCode p = (pInterCode)malloc(sizeof(InterCode));
    assert(p != NULL);
    p->kind = kind;
    va_list vaList;
    assert(kind >= 0 && kind < 19);
    switch (kind) {
        case IR_LABEL:
        case IR_FUNCTION:
        case IR_GOTO:
        case IR_RETURN:
        case IR_ARG:
        case IR_PARAM:
        case IR_READ:
        case IR_WRITE:
            va_start(vaList, 1);
            p->oneOp.op = va_arg(vaList, pOperand);
            break;
        case IR_ASSIGN:
        case IR_GET_ADDR:
        case IR_READ_ADDR:
        case IR_WRITE_ADDR:
        case IR_CALL:
            va_start(vaList, 2);
            p->assign.left = va_arg(vaList, pOperand);
            p->assign.right = va_arg(vaList, pOperand);
            break;
        case IR_ADD:
        case IR_SUB:
        case IR_MUL:
        case IR_DIV:
            va_start(vaList, 3);
            p->binOp.result = va_arg(vaList, pOperand);
            p->binOp.op1 = va_arg(vaList, pOperand);
            p->binOp.op2 = va_arg(vaList, pOperand);
            break;
        case IR_DEC:
            va_start(vaList, 2);
            p->dec.op = va_arg(vaList, pOperand);
            p->dec.size = va_arg(vaList, int);
            break;
        case IR_IF_GOTO:
            va_start(vaList, 4);
            p->ifGoto.x = va_arg(vaList, pOperand);
            p->ifGoto.relop = va_arg(vaList, pOperand);
            p->ifGoto.y = va_arg(vaList, pOperand);
            p->ifGoto.z = va_arg(vaList, pOperand);
    }
    return p;
}

void deleteInterCode(pInterCode p) {
    assert(p != NULL);
    assert(p->kind >= 0 && p->kind < 19);
    switch (p->kind) {
        case IR_LABEL:
        case IR_FUNCTION:
        case IR_GOTO:
        case IR_RETURN:
        case IR_ARG:
        case IR_PARAM:
        case IR_READ:
        case IR_WRITE:
            deleteOperand(p->oneOp.op);
            break;
        case IR_ASSIGN:
        case IR_GET_ADDR:
        case IR_READ_ADDR:
        case IR_WRITE_ADDR:
        case IR_CALL:
            deleteOperand(p->assign.left);
            deleteOperand(p->assign.right);
            break;
        case IR_ADD:
        case IR_SUB:
        case IR_MUL:
        case IR_DIV:
            deleteOperand(p->binOp.result);
            deleteOperand(p->binOp.op1);
            deleteOperand(p->binOp.op2);
            break;
        case IR_DEC:
            deleteOperand(p->dec.op);
            break;
        case IR_IF_GOTO:
            deleteOperand(p->ifGoto.x);
            deleteOperand(p->ifGoto.relop);
            deleteOperand(p->ifGoto.y);
            deleteOperand(p->ifGoto.z);
    }
    free(p);
}

void printInterCode(FILE* fp, pInterCodeList interCodeList) {
    for (pInterCodes cur = interCodeList->head; cur != NULL; cur = cur->next) {
        assert(cur->code->kind >= 0 && cur->code->kind < 19);
        if (fp == NULL) {
            switch (cur->code->kind) {
                case IR_LABEL:
                    printf("LABEL ");
                    printOp(fp, cur->code->oneOp.op);
                    printf(" :");
                    break;
                case IR_FUNCTION:
                    printf("FUNCTION ");
                    printOp(fp, cur->code->oneOp.op);
                    printf(" :");
                    break;
                case IR_ASSIGN:
                    printOp(fp, cur->code->assign.left);
                    printf(" := ");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_ADD:
                    printOp(fp, cur->code->binOp.result);
                    printf(" := ");
                    printOp(fp, cur->code->binOp.op1);
                    printf(" + ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_SUB:
                    printOp(fp, cur->code->binOp.result);
                    printf(" := ");
                    printOp(fp, cur->code->binOp.op1);
                    printf(" - ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_MUL:
                    printOp(fp, cur->code->binOp.result);
                    printf(" := ");
                    printOp(fp, cur->code->binOp.op1);
                    printf(" * ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_DIV:
                    printOp(fp, cur->code->binOp.result);
                    printf(" := ");
                    printOp(fp, cur->code->binOp.op1);
                    printf(" / ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_GET_ADDR:
                    printOp(fp, cur->code->assign.left);
                    printf(" := &");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_READ_ADDR:
                    printOp(fp, cur->code->assign.left);
                    printf(" := *");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_WRITE_ADDR:
                    printf("*");
                    printOp(fp, cur->code->assign.left);
                    printf(" := ");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_GOTO:
                    printf("GOTO ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_IF_GOTO:
                    printf("IF ");
                    printOp(fp, cur->code->ifGoto.x);
                    printf(" ");
                    printOp(fp, cur->code->ifGoto.relop);
                    printf(" ");
                    printOp(fp, cur->code->ifGoto.y);
                    printf(" GOTO ");
                    printOp(fp, cur->code->ifGoto.z);
                    break;
                case IR_RETURN:
                    printf("RETURN ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_DEC:
                    printf("DEC ");
                    printOp(fp, cur->code->dec.op);
                    printf(" ");
                    printf("%d", cur->code->dec.size);
                    break;
                case IR_ARG:
                    printf("ARG ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_CALL:
                    printOp(fp, cur->code->assign.left);
                    printf(" := CALL ");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_PARAM:
                    printf("PARAM ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_READ:
                    printf("READ ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_WRITE:
                    printf("WRITE ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
            }
            printf("\n");
        } else {
            switch (cur->code->kind) {
                case IR_LABEL:
                    fprintf(fp, "LABEL ");
                    printOp(fp, cur->code->oneOp.op);
                    fprintf(fp, " :");
                    break;
                case IR_FUNCTION:
                    fprintf(fp, "FUNCTION ");
                    printOp(fp, cur->code->oneOp.op);
                    fprintf(fp, " :");
                    break;
                case IR_ASSIGN:
                    printOp(fp, cur->code->assign.left);
                    fprintf(fp, " := ");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_ADD:
                    printOp(fp, cur->code->binOp.result);
                    fprintf(fp, " := ");
                    printOp(fp, cur->code->binOp.op1);
                    fprintf(fp, " + ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_SUB:
                    printOp(fp, cur->code->binOp.result);
                    fprintf(fp, " := ");
                    printOp(fp, cur->code->binOp.op1);
                    fprintf(fp, " - ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_MUL:
                    printOp(fp, cur->code->binOp.result);
                    fprintf(fp, " := ");
                    printOp(fp, cur->code->binOp.op1);
                    fprintf(fp, " * ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_DIV:
                    printOp(fp, cur->code->binOp.result);
                    fprintf(fp, " := ");
                    printOp(fp, cur->code->binOp.op1);
                    fprintf(fp, " / ");
                    printOp(fp, cur->code->binOp.op2);
                    break;
                case IR_GET_ADDR:
                    printOp(fp, cur->code->assign.left);
                    fprintf(fp, " := &");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_READ_ADDR:
                    printOp(fp, cur->code->assign.left);
                    fprintf(fp, " := *");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_WRITE_ADDR:
                    fprintf(fp, "*");
                    printOp(fp, cur->code->assign.left);
                    fprintf(fp, " := ");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_GOTO:
                    fprintf(fp, "GOTO ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_IF_GOTO:
                    fprintf(fp, "IF ");
                    printOp(fp, cur->code->ifGoto.x);
                    fprintf(fp, " ");
                    printOp(fp, cur->code->ifGoto.relop);
                    fprintf(fp, " ");
                    printOp(fp, cur->code->ifGoto.y);
                    fprintf(fp, " GOTO ");
                    printOp(fp, cur->code->ifGoto.z);
                    break;
                case IR_RETURN:
                    fprintf(fp, "RETURN ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_DEC:
                    fprintf(fp, "DEC ");
                    printOp(fp, cur->code->dec.op);
                    fprintf(fp, " ");
                    fprintf(fp, "%d", cur->code->dec.size);
                    break;
                case IR_ARG:
                    fprintf(fp, "ARG ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_CALL:
                    printOp(fp, cur->code->assign.left);
                    fprintf(fp, " := CALL ");
                    printOp(fp, cur->code->assign.right);
                    break;
                case IR_PARAM:
                    fprintf(fp, "PARAM ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_READ:
                    fprintf(fp, "READ ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
                case IR_WRITE:
                    fprintf(fp, "WRITE ");
                    printOp(fp, cur->code->oneOp.op);
                    break;
            }
            fprintf(fp, "\n");
        }
    }
}

// InterCodes func
pInterCodes newInterCodes(pInterCode code) {
    pInterCodes p = (pInterCodes)malloc(sizeof(InterCodes));
    assert(p != NULL);
    p->code = code;
    p->prev = NULL;
    p->next = NULL;
}

void deleteInterCodes(pInterCodes p) {
    assert(p != NULL);
    deleteInterCode(p->code);
    free(p);
}

// Arg and ArgList func
pArg newArg(pOperand op) {
    pArg p = (pArg)malloc(sizeof(Arg));
    assert(p != NULL);
    p->op = op;
    p->next = NULL;
}

pArgList newArgList() {
    pArgList p = (pArgList)malloc(sizeof(ArgList));
    assert(p != NULL);
    p->head = NULL;
    p->cur = NULL;
}

void deleteArg(pArg p) {
    assert(p != NULL);
    deleteOperand(p->op);
    free(p);
}

void deleteArgList(pArgList p) {
    assert(p != NULL);
    pArg q = p->head;
    while (q) {
        pArg temp = q;
        q = q->next;
        deleteArg(temp);
    }
    free(p);
}

void addArg(pArgList argList, pArg arg) {
    if (argList->head == NULL) {
        argList->head = arg;
        argList->cur = arg;
    } else {
        argList->cur->next = arg;
        argList->cur = arg;
    }
}

// InterCodeList func
pInterCodeList newInterCodeList() {
    pInterCodeList p = (pInterCodeList)malloc(sizeof(InterCodeList));
    p->head = NULL;
    p->cur = NULL;
    p->lastArrayName = NULL;
    p->tempVarNum = 1;
    p->labelNum = 1;
}

void deleteInterCodeList(pInterCodeList p) {
    assert(p != NULL);
    pInterCodes q = p->head;
    while (q) {
        pInterCodes temp = q;
        q = q->next;
        deleteInterCodes(temp);
    }
    free(p);
}

void addInterCode(pInterCodeList interCodeList, pInterCodes newCode) {
    if (interCodeList->head == NULL) {
        interCodeList->head = newCode;
        interCodeList->cur = newCode;
    } 
    else {
        interCodeList->cur->next = newCode;
        newCode->prev = interCodeList->cur;
        interCodeList->cur = newCode;
    }
}

// traverse func
pOperand newTemp() {
    // printf("newTemp() tempVal:%d\n", interCodeList->tempVarNum);
    char tName[10] = {0};
    sprintf(tName, "t%d", interCodeList->tempVarNum);
    interCodeList->tempVarNum++;
    pOperand temp = newOperand(OP_VARIABLE, newString(tName));
    return temp;
}

pOperand newLabel() {
    char lName[10] = {0};
    sprintf(lName, "label%d", interCodeList->labelNum);
    interCodeList->labelNum++;
    pOperand temp = newOperand(OP_LABEL, newString(lName));
    return temp;
}

int getSize(pType type) {
    if (type == NULL)
        return 0;
    else if (type->kind == BASIC)
        return 4;
    else if (type->kind == ARRAY)
        return type->array.size * getSize(type->array.elem);
    else if (type->kind == STRUCTURE) {
        int size = 0;
        pFieldList temp = type->structure.field;
        while (temp) {
            size += getSize(temp->type);
            temp = temp->tail;
        }
        return size;
    }
    return 0;
}

void genInterCodes(treeNode node) {
    if (node == NULL) return;
    if (!strcmp(node->name, "ExtDefList"))
        translateExtDefList(node);
    else {
        genInterCodes(node->first_son);
        genInterCodes(node->next_bro);
    }
}

void genInterCode(int kind, ...) {
    va_list vaList;
    pOperand temp = NULL;
    pOperand result = NULL, op1 = NULL, op2 = NULL, relop = NULL;
    int size = 0;
    pInterCodes newCode = NULL;
    assert(kind >= 0 && kind < 19);
    switch (kind) {
        case IR_LABEL:
        case IR_FUNCTION:
        case IR_GOTO:
        case IR_RETURN:
        case IR_ARG:
        case IR_PARAM:
        case IR_READ:
        case IR_WRITE:
            va_start(vaList, 1);
            op1 = va_arg(vaList, pOperand);
            if (op1->kind == OP_ADDRESS) {
                temp = newTemp();
                genInterCode(IR_READ_ADDR, temp, op1);
                op1 = temp;
            }
            newCode = newInterCodes(newInterCode(kind, op1));
            addInterCode(interCodeList, newCode);
            break;
        case IR_ASSIGN:
        case IR_GET_ADDR:
        case IR_READ_ADDR:
        case IR_WRITE_ADDR:
        case IR_CALL:
            va_start(vaList, 2);
            op1 = va_arg(vaList, pOperand);
            op2 = va_arg(vaList, pOperand);
            if (kind == IR_ASSIGN && (op1->kind == OP_ADDRESS || op2->kind == OP_ADDRESS)) {
                if (op1->kind == OP_ADDRESS && op2->kind != OP_ADDRESS)
                    genInterCode(IR_WRITE_ADDR, op1, op2);
                else if (op2->kind == OP_ADDRESS && op1->kind != OP_ADDRESS)
                    genInterCode(IR_READ_ADDR, op1, op2);
                else {
                    temp = newTemp();
                    genInterCode(IR_READ_ADDR, temp, op2);
                    genInterCode(IR_WRITE_ADDR, op1, temp);
                }
            } 
            else {
                newCode = newInterCodes(newInterCode(kind, op1, op2));
                addInterCode(interCodeList, newCode);
            }
            break;
        case IR_ADD:
        case IR_SUB:
        case IR_MUL:
        case IR_DIV:
            va_start(vaList, 3);
            result = va_arg(vaList, pOperand);
            op1 = va_arg(vaList, pOperand);
            op2 = va_arg(vaList, pOperand);
            if (op1->kind == OP_ADDRESS) {
                temp = newTemp();
                genInterCode(IR_READ_ADDR, temp, op1);
                op1 = temp;
            }
            if (op2->kind == OP_ADDRESS) {
                temp = newTemp();
                genInterCode(IR_READ_ADDR, temp, op2);
                op2 = temp;
            }
            newCode = newInterCodes(newInterCode(kind, result, op1, op2));
            addInterCode(interCodeList, newCode);
            break;
        case IR_DEC:
            // TODO:
            va_start(vaList, 2);
            op1 = va_arg(vaList, pOperand);
            size = va_arg(vaList, int);
            newCode = newInterCodes(newInterCode(kind, op1, size));
            addInterCode(interCodeList, newCode);
            break;
        case IR_IF_GOTO:
            // TODO:
            va_start(vaList, 4);
            result = va_arg(vaList, pOperand);
            relop = va_arg(vaList, pOperand);
            op1 = va_arg(vaList, pOperand);
            op2 = va_arg(vaList, pOperand);
            newCode =
                newInterCodes(newInterCode(kind, result, relop, op1, op2));
            addInterCode(interCodeList, newCode);
            break;
    }
}
void translateExtDefList(treeNode node) {
    // ExtDefList -> ExtDef ExtDefList
    //             | e
    while (node) {
        translateExtDef(node->first_son);
        node = node->first_son->next_bro;
    }
}

void translateExtDef(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // ExtDef -> Specifier ExtDecList SEMI
    //         | Specifier SEMI
    //         | Specifier FunDec CompSt

    // 因为没有全局变量使用，
    // ExtDecList不涉及中间代码生成，类型声明也不涉及，所以
    // lab3 只需要处理FunDec和CompSt
    if (!strcmp(node->first_son->next_bro->name, "FunDec")) {
        translateFunDec(node->first_son->next_bro);
        translateCompSt(node->first_son->next_bro->next_bro);
    }
}

// Done
void translateFunDec(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // FunDec -> ID LP VarList RP
    //         | ID LP RP
    genInterCode(IR_FUNCTION,newOperand(OP_FUNCTION, newString(node->first_son->id)));
    // pInterCodes func = newInterCodes(newInterCode(
    //     IR_FUNCTION, newOperand(OP_FUNCTION, newString(node->first_son->id))));
    // addInterCode(interCodeList, func);

    pItem funcItem = searchTableItem(table, node->first_son->id);
    pFieldList temp = funcItem->field->type->function.argv;
    while (temp) {
        genInterCode(IR_PARAM, newOperand(OP_VARIABLE, newString(temp->name)));
        // pInterCodes arg = newInterCodes(newInterCode(
        //     IR_PARAM, newOperand(OP_VARIABLE, newString(temp->name))));
        // addInterCode(interCodeList, arg);
        temp = temp->tail;
    }
}

// Done
void translateCompSt(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // CompSt -> LC DefList StmtList RC
    treeNode temp = node->first_son->next_bro;
    if (!strcmp(temp->name, "DefList")) {
        translateDefList(temp);
        temp = temp->next;
    }
    if (!strcmp(temp->name, "StmtList")) {
        translateStmtList(temp);
    }
}

void translateDefList(treeNode node) {
    if (interError) return;
    // DefList -> Def DefList
    //          | e
    while (node) {
        translateDef(node->first_son);
        node = node->first_son->next_bro;
    }
}

void translateDef(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // Def -> Specifier DecList SEMI
    translateDecList(node->first_son->next);
}

void translateDecList(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // DecList -> Dec
    //          | Dec COMMA DecList
    treeNode temp = node;
    while (temp) {
        translateDec(temp->first_son);
        if (temp->first_son->next_bro)
            temp = temp->first_son->next_bro->next_bro;
        else
            break;
    }
}

void translateDec(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // Dec -> VarDec
    //      | VarDec ASSIGNOP Exp

    // Dec -> VarDec
    if (node->first_son->next_bro == NULL) {
        translateVarDec(node->first_son, NULL);
    }
    // Dec -> VarDec ASSIGNOP Exp
    else {
        pOperand t1 = newTemp();
        translateVarDec(node->first_son, t1);
        pOperand t2 = newTemp();
        translateExp(node->first_son->next_bro->next_bro, t2);
        genInterCode(IR_ASSIGN, t1, t2);
    }
}

void translateVarDec(treeNode node, pOperand place) {
    assert(node != NULL);
    if (interError) return;
    // VarDec -> ID
    //         | VarDec LB INT RB

    //  VarDec -> ID
    if (!strcmp(node->first_son->name, "ID")) {
        pItem temp = searchTableItem(table, node->first_son->id);
        pType type = temp->field->type;
        if (type->kind == BASIC) {
            // 基本类型不用额外操作
            // 临时变量转正 end
            if (place) {
                interCodeList->tempVarNum--;
                setOperand(place, OP_VARIABLE,(void*)newString(temp->field->name));
            }
        } 
        else if (type->kind == ARRAY) {
            // 二维以上数组不支持翻译
            if (type->array.elem->kind == ARRAY) {
                interError = TRUE;
                printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
                return;
            } 
            else {
                // 为数组预留空间 
                genInterCode(IR_DEC,newOperand(OP_VARIABLE, newString(temp->field->name)),getSize(type));
            }
        } 
        else if (type->kind == STRUCTURE) {
            // 选做1
            // 为结构体预留空间 
            genInterCode(IR_DEC,newOperand(OP_VARIABLE, newString(temp->field->name)),getSize(type));
        }
    } 
    else {
        // VarDec -> VarDec LB INT RB
        // 后面部分在lab2中已经处理
        translateVarDec(node->first_son, place);
    }
}

void translateStmtList(treeNode node) {
    if (interError) return;
    // StmtList -> Stmt StmtList
    //           | e
    while (node) {
        translateStmt(node->first_son);
        node = node->first_son->next;
    }
}

void translateStmt(treeNode node) {
    assert(node != NULL);
    if (interError) return;
    // Stmt -> Exp SEMI
    //       | CompSt
    //       | RETURN Exp SEMI
    //       | IF LP Exp RP Stmt
    //       | IF LP Exp RP Stmt ELSE Stmt
    //       | WHILE LP Exp RP Stmt

    // Stmt -> Exp SEMI

    if (!strcmp(node->first_son->name, "Exp")) {
        translateExp(node->first_son, NULL);
    }

    // Stmt -> CompSt
    else if (!strcmp(node->first_son->name, "CompSt")) {
        translateCompSt(node->first_son);
    }

    // Stmt -> RETURN Exp SEMI
    else if (!strcmp(node->first_son->name, "RETURN")) {
        pOperand t1 = newTemp();
        translateExp(node->first_son->next, t1);
        genInterCode(IR_RETURN, t1);
    }

    // Stmt -> IF LP Exp RP Stmt
    else if (!strcmp(node->first_son->name, "IF")) {
        treeNode exp = node->first_son->next->next;
        treeNode stmt = exp->next->next;
        pOperand label1 = newLabel();
        pOperand label2 = newLabel();
        // if Exp goto lable 1
        // goto lable 2
        // lable 1
        // Stmt
        // Lable 2

        translateCond(exp, label1, label2);
        genInterCode(IR_LABEL, label1);
        translateStmt(stmt);
        if (stmt->next == NULL) {
            genInterCode(IR_LABEL, label2);
        }
        // Stmt -> IF LP Exp RP Stmt ELSE Stmt
        else {
            pOperand label3 = newLabel();
            genInterCode(IR_GOTO, label3); 
            // if Exp goto lable 1
            // goto label 2
            // lable 1
            // Stmt
            // Goto lable3
            // lable 2
            // Stmt
            // Goto lable3
            // XXX
            genInterCode(IR_LABEL, label2);
            translateStmt(stmt->next->next);
            genInterCode(IR_LABEL, label3);
        }

    }

    // Stmt -> WHILE LP Exp RP Stmt
    else if (!strcmp(node->first_son->name, "WHILE")) {
        pOperand label1 = newLabel();
        pOperand label2 = newLabel();
        pOperand label3 = newLabel();
        // lable 1
        // if Exp goto lable 2
        // goto lable 3
        // lable 2
        // Stmt
        // goto lable 1
        // lable 3
        genInterCode(IR_LABEL, label1);
        translateCond(node->first_son->next->next, label2, label3);
        genInterCode(IR_LABEL, label2);
        translateStmt(node->first_son->next->next->next->next);
        genInterCode(IR_GOTO, label1);
        genInterCode(IR_LABEL, label3);
    }
}

void translateExp(treeNode node, pOperand place) {
    assert(node != NULL);
    if (interError) return;
    // Exp -> Exp ASSIGNOP Exp
    //      | Exp AND Exp
    //      | Exp OR Exp
    //      | Exp RELOP Exp
    //      | Exp PLUS Exp
    //      | Exp MINUS Exp
    //      | Exp STAR Exp
    //      | Exp DIV Exp

    //      | MINUS Exp
    //      | NOT Exp
    //      | LP Exp RP

    //      | ID LP Args RP
    //      | ID LP RP
    //      | Exp LB Exp RB
    //      | Exp DOT ID
    //      | ID
    //      | INT
    //      | FLOAT

    // Exp -> LP Exp RP exp: (x)
    if (!strcmp(node->first_son->name, "LP"))
        translateExp(node->first_son->next_bro, place);

    else if (!strcmp(node->first_son->name, "Exp") ||!strcmp(node->first_son->name, "NOT")) {
        // 条件表达式 和 基本表达式
        if (strcmp(node->first_son->next_bro->name, "LB") &&
            strcmp(node->first_son->next_bro->name, "DOT")) {
            // 处理如下表达式 和条件跳转相关
            // Exp -> Exp AND Exp
            //      | Exp OR Exp
            //      | Exp RELOP Exp
            //      | NOT Exp
            if (!strcmp(node->first_son->next_bro->name, "AND") ||
                !strcmp(node->first_son->next_bro->name, "OR") ||
                !strcmp(node->first_son->next_bro->name, "RELOP") ||
                !strcmp(node->first_son->next_bro, "NOT")) {
                pOperand label1 = newLabel();
                pOperand label2 = newLabel();
                pOperand true_num = newOperand(OP_CONSTANT, 1);
                pOperand false_num = newOperand(OP_CONSTANT, 0);
                genInterCode(IR_ASSIGN, place, false_num);
                translateCond(node, label1, label2);
                genInterCode(IR_LABEL, label1);
                genInterCode(IR_ASSIGN, place, true_num);
            } 
            else {
                // Exp -> Exp ASSIGNOP Exp
                if (!strcmp(node->first_son->next_bro->name, "ASSIGNOP")) {
                    pOperand t2 = newTemp();
                    translateExp(node->first_son->next_bro->next_bro, t2);
                    pOperand t1 = newTemp();
                    translateExp(node->first_son, t1);
                    genInterCode(IR_ASSIGN, t1, t2);
                } 
                else {
                    pOperand t1 = newTemp();
                    translateExp(node->first_son, t1);
                    pOperand t2 = newTemp();
                    translateExp(node->first_son->next->next, t2);
                    // Exp -> Exp PLUS Exp
                    if (!strcmp(node->first_son->next->name, "PLUS")) {
                        genInterCode(IR_ADD, place, t1, t2);
                    }
                    // Exp -> Exp MINUS Exp
                    else if (!strcmp(node->first_son->next->name, "MINUS")) {
                        genInterCode(IR_SUB, place, t1, t2);
                    }
                    // Exp -> Exp STAR Exp
                    else if (!strcmp(node->first_son->next->name, "STAR")) {
                        genInterCode(IR_MUL, place, t1, t2);
                    }
                    // Exp -> Exp DIV Exp
                    else if (!strcmp(node->first_son->next->name, "DIV")) {
                        genInterCode(IR_DIV, place, t1, t2);
                    }
                }
            }

        }
        // 数组和结构体访问
        else {
            // Exp -> Exp LB Exp RB
            // a[1]
            if (!strcmp(node->first_son->next->name, "LB")) {
                //数组
                if (node->first_son->first_son->next &&!strcmp(node->first_son->first_son->next, "LB")) {
                    //出现多维数组则报错
                    interError = TRUE;
                    printf("Cannot translate: Code contains variables of multi-dimensional array type or parameters of array type.\n");
                    return;
                } 
                else {
                    // 
                    pOperand idx = newTemp();
                    translateExp(node->first_son->next->next, idx);
                    pOperand base = newTemp();
                    translateExp(node->first_son, base);

                    pOperand width;
                    pOperand offset = newTemp();
                    pOperand target;
                    // 只处理Exp1 = Exp DOT ID -> a.a[],和 Exp1 = ID -> a[] 的情况
                    // 我们让前一种情况将ID作为name回填进place返回到这里的base处，在语义分析时将结构体变量也填进表（因为假设无重名），这样两种情况都可以查表得到
                    pItem item = searchTableItem(table, base->name);
                    assert(item->field->type->kind == ARRAY);
                    width = newOperand(OP_CONSTANT, getSize(item->field->type->array.elem));
                    genInterCode(IR_MUL, offset, idx, width);

                    // 如果是ID[Exp],
                    // 则需要对ID取址，如果前面是结构体内访问，则会返回一个地址类型，不需要再取址
                    if (base->kind == OP_VARIABLE) {
                        // printf("非结构体数组访问\n");
                        target = newTemp();
                        genInterCode(IR_GET_ADDR, target, base);
                    } else {
                        // printf("结构体数组访问\n");
                        target = base;
                    }
                    genInterCode(IR_ADD, place, target, offset);
                    place->kind = OP_ADDRESS;
                    // 记录下变量名，后续处理用
                    interCodeList->lastArrayName = base->name;
                }
            }
            // Exp -> Exp DOT ID
            else {
                //结构体
                pOperand temp = newTemp();
                translateExp(node->first_son, temp);
                // 两种情况，Exp直接为一个变量，则需要先取址，若Exp为数组或者多层结构体访问或结构体形参，则target会被填成地址，可以直接用。
                pOperand target;

                if (temp->kind == OP_ADDRESS) {
                    target = newOperand(temp->kind, temp->name);
                    // target->isAddr = TRUE;
                } 
                else {
                    target = newTemp();
                    genInterCode(IR_GET_ADDR, target, temp);
                }

                pOperand id = newOperand(OP_VARIABLE, newString(node->first_son->next->next->id));
                int offset = 0;
                pItem item = searchTableItem(table, temp->name);
                //结构体数组
                //这里temp是临时变量，如果查不到表，则需要用处理数组时候记录下的数组名查表
                if (item == NULL) {
                    item = searchTableItem(table, interCodeList->lastArrayName);
                }

                pFieldList tmp;
                // 结构体数组,不支持高维
                if (item->field->type->kind == ARRAY) {
                    tmp = item->field->type->array.elem->structure.field;
                }
                // 一般结构体
                else {
                    tmp = item->field->type->structure.field;
                }
                // 遍历获得offset
                while (tmp) {
                    if (!strcmp(tmp->name, id->name)) break;
                    offset += getSize(tmp->type);
                    tmp = tmp->tail;
                }

                pOperand tOffset = newOperand(OP_CONSTANT, offset);
                if (place) {
                    genInterCode(IR_ADD, place, target, tOffset);
                    // 为了处理结构体里的数组把id名通过place回传给上层
                    setOperand(place, OP_ADDRESS, (void*)newString(id->name));
                    // place->isAddr = TRUE;
                }
            }
        }
    }
    //单目运算符
    // Exp -> MINUS Exp
    else if (!strcmp(node->first_son->name, "MINUS")) {
        pOperand t1 = newTemp();
        translateExp(node->first_son->next, t1);
        pOperand zero = newOperand(OP_CONSTANT, 0);
        genInterCode(IR_SUB, place, zero, t1);
    }
    // // Exp -> NOT Exp
    // else if (!strcmp(node->first_son->name, "NOT")) {
    //     pOperand label1 = newLabel();
    //     pOperand label2 = newLabel();
    //     pOperand true_num = newOperand(OP_CONSTANT, 1);
    //     pOperand false_num = newOperand(OP_CONSTANT, 0);
    //     genInterCode(IR_ASSIGN, place, false_num);
    //     translateCond(node, label1, label2);
    //     genInterCode(IR_LABEL, label1);
    //     genInterCode(IR_ASSIGN, place, true_num);
    // }
    // Exp -> ID LP Args RP
    //		| ID LP RP
    else if (!strcmp(node->first_son->name, "ID") && node->first_son->next) {
        pOperand funcTemp = newOperand(OP_FUNCTION, newString(node->first_son->id));
        // Exp -> ID LP Args RP
        if (!strcmp(node->first_son->next->next->name, "Args")) {
            // 处理参数
            pArgList argList = newArgList();
            translateArgs(node->first_son->next->next, argList);
            if (!strcmp(node->first_son->id, "write")) {
                // write 特殊处理
                genInterCode(IR_WRITE, argList->head->op);
            } 
            else {
                // 正确性已经在lab2检验过了
                pArg argTemp = argList->head;
                while (argTemp) {
                    if (argTemp->op == OP_VARIABLE) {
                        pItem item = searchTableItem(table, argTemp->op->name);

                        // 结构体作为参数需要传址
                        if (item && item->field->type->kind == STRUCTURE) {
                            pOperand varTemp = newTemp();
                            genInterCode(IR_GET_ADDR, varTemp, argTemp->op);
                            pOperand varTempCopy =newOperand(OP_ADDRESS, varTemp->name);
                            // copy 为 temp的地址变量 
                            // varTempCopy->isAddr = TRUE;
                            genInterCode(IR_ARG, varTempCopy);
                        }
                        // 3.2数组传参 TODO
                    }
                    // 一般参数直接传值
                    else {
                        genInterCode(IR_ARG, argTemp->op);
                    }
                    argTemp = argTemp->next;
                }
                // 如果有占位则赋值给占位
                if (place) {
                    genInterCode(IR_CALL, place, funcTemp);
                } 
                else {
                    pOperand temp = newTemp();
                    genInterCode(IR_CALL, temp, funcTemp);
                }
            }
        }
        // Exp -> ID LP RP
        else {
            if (!strcmp(node->first_son->id, "read")) {
                genInterCode(IR_READ, place);
            } else {
                
                if (place) {
                    genInterCode(IR_CALL, place, funcTemp);
                } else {
                    pOperand temp = newTemp();
                    genInterCode(IR_CALL, temp, funcTemp);
                }
            }
        }
    }
    // Exp -> ID
    else if (!strcmp(node->first_son->name, "ID")) {
        pItem item = searchTableItem(table, node->first_son->id);
        // 根据讲义，因为结构体不允许赋值，结构体做形参时是传址的方式
        // 因此结构体情况将place赋值为ADDRESS
        interCodeList->tempVarNum--;
        if (item->field->isArg && item->field->type->kind == STRUCTURE) {
            setOperand(place, OP_ADDRESS, (void*)newString(node->first_son->id));
            // place->isAddr = TRUE;
        }
        // 非结构体参数情况都当做变量处理
        else {
            setOperand(place, OP_VARIABLE, (void*)newString(node->first_son->id));
        }

        // pOperand t1 = newOperand(OP_VARIABLE, id_name->field->name);
        // genInterCode(IR_ASSIGN, place, t1);
    } else {
        // 无浮点数常数
        // 只处理 Exp -> INT
        interCodeList->tempVarNum--;
        setOperand(place, OP_CONSTANT, (void*)atoi(node->first_son->id));
        // pOperand t1 = newOperand(OP_CONSTANT, node->first_son->id);
        // genInterCode(IR_ASSIGN, place, t1);
    }
}

void translateCond(treeNode node, pOperand labelTrue, pOperand labelFalse) {
    assert(node != NULL);
    if (interError) return;
    // Exp -> Exp AND Exp
    //      | Exp OR Exp
    //      | Exp RELOP Exp
    //      | NOT Exp

    // Exp -> NOT Exp
    if (!strcmp(node->first_son->name, "NOT")) {
        translateCond(node->first_son->next_bro, labelFalse, labelTrue);
    }
    // Exp -> Exp RELOP Exp
    else if (!strcmp(node->first_son->next_bro->name, "RELOP")) {
        pOperand t1 = newTemp();
        pOperand t2 = newTemp();
        translateExp(node->first_son, t1);
        translateExp(node->first_son->next_bro->next_bro, t2);

        pOperand relop = newOperand(OP_RELOP, newString(node->first_son->next->id));

        if (t1->kind == OP_ADDRESS) {
            pOperand temp = newTemp();
            genInterCode(IR_READ_ADDR, temp, t1);
            t1 = temp;
        }
        if (t2->kind == OP_ADDRESS) {
            pOperand temp = newTemp();
            genInterCode(IR_READ_ADDR, temp, t2);
            t2 = temp;
        }

        genInterCode(IR_IF_GOTO, t1, relop, t2, labelTrue);
        genInterCode(IR_GOTO, labelFalse);
    }
    // Exp -> Exp AND Exp
    else if (!strcmp(node->first_son->next->name, "AND")) {
        pOperand label1 = newLabel();
        translateCond(node->first_son, label1, labelFalse);
        genInterCode(IR_LABEL, label1);
        translateCond(node->first_son->next->next, labelTrue, labelFalse);
    }
    // Exp -> Exp OR Exp
    else if (!strcmp(node->first_son->next->name, "OR")) {
        pOperand label1 = newLabel();
        translateCond(node->first_son, labelTrue, label1);
        genInterCode(IR_LABEL, label1);
        translateCond(node->first_son->next->next, labelTrue, labelFalse);
    }
    // 其他情况下进入Cond
    // Exp -> int,float...
    // 默认为 Exp != 0 
    else {
        pOperand t1 = newTemp();
        translateExp(node, t1);
        pOperand t2 = newOperand(OP_CONSTANT, 0);
        pOperand relop = newOperand(OP_RELOP, newString("!="));

        if (t1->kind == OP_ADDRESS) {
            pOperand temp = newTemp();
            genInterCode(IR_READ_ADDR, temp, t1);
            t1 = temp;
        }
        genInterCode(IR_IF_GOTO, t1, relop, t2, labelTrue);
        genInterCode(IR_GOTO, labelFalse);
    }
}

void translateArgs(treeNode node, pArgList argList) {
    assert(node != NULL);
    assert(argList != NULL);
    if (interError) return;
    // Args -> Exp COMMA Args
    //       | Exp

    // Args -> Exp
    pArg temp = newArg(newTemp());
    translateExp(node->first_son, temp->op);

    if (temp->op->kind == OP_VARIABLE) {
        pItem item = searchTableItem(table, temp->op->name);
        if (item && item->field->type->kind == ARRAY) {
            // 暂不接受数组传参
            // TODO 
            interError = TRUE;
            printf(
                "Cannot translate: Code containsvariables of "
                "multi-dimensional array type or parameters of array "
                "type.\n");
            return;
        }
    }
    addArg(argList, temp);

    // Args -> Exp COMMA Args
    if (node->first_son->next != NULL) {
        translateArgs(node->first_son->next->next, argList);
    }
}




int main(int argc, char** argv){
    if (argc <= 2) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f){
        printf("File Open Error!");
        return 1;
    }
    FILE* fw = fopen(argv[2], "wt+");
    if (!fw) {
        perror(argv[2]);
        return 1;
    }
    is_wrong = 0;
    yyrestart(f);
    // yydebug=1;
    yyparse();
    return 0;
}