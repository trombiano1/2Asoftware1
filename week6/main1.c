#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 手札は5枚
#define N 5

// 関数は自由に追加してください

typedef struct card {
    char suit;   // 's': spades, 'h': hearts, 'd': diams, 'c': clubs
    int number;  // 1, 2, 3, ..., 13
} Card;



void print_all_card(Card cards[]) {
    // 手札を表示する関数
    for (int i = 0; i < N; ++i) {
        printf("[%c %d] ", cards[i].suit, cards[i].number);
    }
    printf("\n");
}

int compare_suit(char the_suit){
  if(the_suit == 's'){return 0;}
  if(the_suit == 'h'){return 100;}
  if(the_suit == 'd'){return 200;}
  if(the_suit == 'c'){return 300;}
  return 4;
}

void sort_card(Card cards[]) {
    // ここで、手役をソートする
  for (int i = 0; i < N; ++i){
    for(int j = 0; j < N-1-i; ++j){
      char temp_suit;
      int temp_number;
      if(compare_suit(cards[j].suit)+cards[j].number < compare_suit(cards[j+1].suit)+cards[j+1].number){
      }else{
	temp_suit = cards[j].suit;
	temp_number = cards[j].number;
	cards[j].suit = cards[j+1].suit;
	cards[j].number = cards[j+1].number;
	cards[j+1].suit = temp_suit;
	cards[j+1].number = temp_number;
      }
    }
  }
}

int under_13(int n){
  if(n > 12){
    return n-13;
  }else{
    return n;
  }
}

int check_hand(Card cards[]) {
    // ここで、手役を判定し、結果をreturnする
    // たとえばone pairと判定したら、1をreturnする。straightと判定したら、4をreturnする
  int numbers[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  for(int i = 0; i < N; ++i){
    numbers[cards[i].number-1]++;
  }


  int pair_number = 0;
  int one_pair = 0;
  int two_pair = 0;
  int tree_of_a_kind = 0;
  int four_of_a_kind = 0;
  int straight = 0;
  int royal_straight = 0;
  int flush = 0;
  int full_house = 0;
  int straight_flush = 0;
  int royal_straight_flush = 0;

  /*pair, tree, four*/
  for(int i = 0; i < 13; ++i){
    if(numbers[i] > 1){
      pair_number++;
    }
    if(numbers[i] == 3){
      tree_of_a_kind++;
    }
    if(numbers[i] == 4){
      four_of_a_kind++;
    }
  }
  if(pair_number == 1){one_pair = 1;}
  if(pair_number == 2){two_pair = 1;}
  
  /*straight*/
  int temp = 0;
  for(int i = 0; i < 13; ++i){
    temp = 1;
    for(int j = 0; j < 5; ++j){
      if(numbers[under_13(i+j)] != 1){
	temp = 0;
	break;
      }
    }
    if(temp == 1){
      straight = 1;
    }
    if(temp == 1 && i == 9){
      royal_straight = 1;
    }
  }
  
  /*flush*/
  int black = 1;
  int red = 1;
  for(int i = 0; i < 5; ++i){
    if(cards[i].suit != 's' && cards[i].suit != 'c'){
      black = 0;
    }
    if(cards[i].suit != 'h' && cards[i].suit != 'd'){
      red = 0;
    }
  }
  flush = 1- (1-black) * (1-red);

  /*full_house, straight_flush, royal_straight_flush*/
  full_house =  two_pair * tree_of_a_kind;
  straight_flush = straight * flush;
  royal_straight_flush = straight_flush * royal_straight;
  
  /*
  for(int i = 0; i < 5; ++i){
    for(int j = i+1; j < 5; ++j){
      printf("%d,%d\n",cards[i].number,cards[j].number);
    }
    }*/
  if(royal_straight_flush){
    return 9;
  }else if(straight_flush){
    return 8;
  }else if(four_of_a_kind){
    return 7;
  }else if(full_house){
    return 6;
  }else if(flush){
    return 5;
  }else if(straight){
    return 4;
  }else if(tree_of_a_kind){
    return 3;
  }else if(two_pair){
    return 2;
  }else if(one_pair){
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Error. argc must be 6\n");
        return -1;
    }
    Card cards[N];  // 手札

    // ここで、argvから手札を読み込みcardsに入れる
    for(int i = 0; i < N; ++i){
      cards[i].suit=*argv[1+i];
      cards[i].number=atoi(argv[1+i]+1);
    }
    // ここから下は編集しない
    print_all_card(cards);
    sort_card(cards);
    print_all_card(cards);
    int result = check_hand(cards);

    printf("My hand: ");
    if (result == 0) {
        printf("Not sure\n");
    } else if (result == 1) {
        printf("One pair!\n");
    } else if (result == 2) {
        printf("Two pair!\n");
    } else if (result == 3) {
        printf("Three of a kind!\n");
    } else if (result == 4) {
        printf("Straight!\n");
    } else if (result == 5) {
        printf("Flush!\n");
    } else if (result == 6) {
        printf("Full house!\n");
    } else if (result == 7) {
        printf("Four of a kind!\n");
    } else if (result == 8) {
        printf("Straight flush!\n");
    } else if (result == 9) {
        printf("Royal straight flush!\n");
    } else {
        printf("Error\n");
    }
}
