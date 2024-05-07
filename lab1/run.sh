flex lexical.l
if [["$2" = "d"]];
then
    bison -d -t syntax.y
else
    bison -d syntax.y
fi
flex lexical.l
gcc main.c syntax.tab.c -lfl -o parser&&./parser $1