#include <stdio.h>

/*
  関数は自由に追加してください
*/

char make_uppercase(char n){
  return n+'A'-'a';
}

int main(int argc, char *argv[])
{
    char *name = argv[1];
    printf("%c",make_uppercase(name[0]));
    int underbar_flag = 0;
    for (int i = 1; name[i] != '\0'; ++i){
      if(underbar_flag == 1){
	printf("%c",name[i]);
      }else if(name[i]=='_'){
	underbar_flag = 1;
	printf(". ");
	printf("%c",make_uppercase(name[i+1]));
	i++;
      }
    }
    printf("\n");

}
