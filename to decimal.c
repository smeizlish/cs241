#include "getnum.c"

long num;

void main(){
  while ((ch = getchar()) != EOF){
    ungetc(ch, stdin);
    num = getnum();
    printf("%ld\n", num);
    ch = getchar();
    if (ch == EOF){
      break;
    }
    else if (isspace(ch)){
      ch = getchar();
      while (isspace(ch)){
        ch = getchar();
      }
      ungetc(ch, stdin);
    }
  }
}
