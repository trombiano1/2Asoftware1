#include <stdio.h>
#define N 100


void my_strcpy(char *s1, const char *s2) {
    int i = 0;
    while ((s1[i] = s2[i]) != '\0') {
        ++i;
    }
}

int strlen1(const char *s) {
    int n = 0;
    for(; *s != '\0'; s++) {
        n++;
    }
    return n;
}

void replace(char *s, const char *old, const char *new) {
  char new_string[strlen1(old)*strlen1(s)];
  int inc = 0;
  // この関数を編集してください。必要に応じて、他の関数を作ってもいいです
  for(int i=0; *(s+i) != '\0'; i++) {
    for(int j=0; *(old+j) != '\0'; j++){
      if(*(s+i+j) != *(old+j)){
	new_string[inc] = *(s+i);
	inc++;
	break;
      }
      if(*(old+j+1) == '\0'){
	i += strlen1(old)-1;
	for(int k=0; k<strlen1(new); k++){
	  new_string[inc+k] = *(new+k);
	}
	inc += strlen1(new);
      }
    }
  }
  new_string[inc] = '\0';
  my_strcpy(s, new_string);
}

int main(int argc, char *argv[]) {
    // main関数は編集しないでください

    /*
      $ gcc main3.c -o main3
      $ ./main3 tokyo_univ tokyo kyoto
      とすると、
      s[N] = "tokyo_univ";
      old[N] = "tokyo";
      new[N] = "kyoto";
      と同じ意味になります
    */

    if (argc != 4) {
        printf("Error. Please put \"s\", \"old\", and \"new\" after a.out. For example: ./a.out tokyo_univ tokyo kyoto\n");
        return -1;
    }
    char s[N];
    char old[N];
    char new[N];
    my_strcpy(s, argv[1]);
    my_strcpy(old, argv[2]);
    my_strcpy(new, argv[3]);

    printf("s=\"%s\", old=\"%s\", new=\"%s\"\n", s, old, new);
    printf("Before: %s\n", s);
    replace(s, old, new);
    printf("After: %s\n", s);

}
