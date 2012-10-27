/* POKUS HOVNO Jen takovy test jestli to vazne funguje tak jak nam tvrdili :).
Vsechno co tu mam bude v realu vypadat jinak, ale zakladni pointa je takovahle,
aspon tak to chapu ja. Pro lepsi predstavu jak to bude vypadat kouknete na link
z changelogu. Jakekoliv pripominky mi hned piste, Matej.
-podle LL tabulky pro vstupy eol a function od prog niz(jen par ponoreni)
-kazda funkce je jeden neterminal, ma switch(token) a pak se vetvi dal,to
je ten rekurzivni sestup
*/
#include <stdio.h>
#include <stdlib.h>

//neterminaly
#define EOL 1   //ted natvrdo, pak nakou tabulku bokem na to
#define FUNCTION 2

//oznaceni typu
#define T_ID -1
#define T_NT -2
typedef struct{
  int value;
  int type;
}Tto;

Tto token;

Tto getNextToken(int value,int type)
{//zavolam si o token, ted natvrdo co chci
  Tto a;
  a.value=value;
  a.type=type;
  return a;
}

int prog()
{//neterminal prog
  switch(token.value)
  {//moznosti vstupu
    case EOL:
    case FUNCTION:st_list();break;
    //eol a function maj v tabulce oba pravidlo 1, tzn oba zavolaji st_list
    //pravidlo 1:prog->st_list
  }
}

int st_list()
{//neterminal st_list
  switch(token.value)
  {
    case EOL:
    case FUNCTION:stat();break;
    //eol a function maj v tabulce oba pravidlo 2, tzn oba zavolaji stat
    //pravidlo 2:st_list->stat eol st_list
  }
}

int stat()
{
  Tto n;
  switch(token.value)
  {//neterminal stat
    case EOL: printf("EOL");break;//ted muzu rict ze je to konkretne eol bo 10: Stat->ε
    case FUNCTION://potrebuju dalsi token bo 4:Stat->function id ( Params ) eol St_list end
                n=getNextToken(333,T_ID);
                if((n.type)==T_ID) printf("FUNCTION %d",n.value);
                //kdyz je typu ID(T_ID) je to ok a muze jet dal(to uz tu nemam)
                else printf("mas to blbe");//jinak je syntaxe blbe
                break;
  }
}

int main()
{//T_NT mam ted extra pro neterminaly kdyz si delam tokeny rucne
  token = getNextToken(FUNCTION,T_NT);
  prog();
}

