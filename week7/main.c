#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
int N;

void print_board(int board[][N], int evenodd_mode) {
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(board[i][j] == 0){
	printf(" . \t");
      }else{
	if(evenodd_mode){
	  if(board[i][j]%3 != 0){
	    printf("\e[41m");
	  } else {
	    printf("\e[42m");
	  }
	}else{
	  if(board[i][j] == 2){
	    printf("\e[7m");
	  } else if (board[i][j] == 4){
	    printf("\e[41m");
	  } else if (board[i][j] == 8){
	    printf("\e[42m");
	  } else if (board[i][j] == 16){
	    printf("\e[44m");
	  } else if (board[i][j] == 32){
	    printf("\e[45m");
	  } else if (board[i][j] == 64){
	    printf("\e[46m");
	  } else if (board[i][j] == 128){
	    printf("\e[41;1m");
	  } else if (board[i][j] == 256){
	    printf("\e[42;1m");
	  } else if (board[i][j] == 512){
	    printf("\e[44;1m");
	  } else if (board[i][j] == 1024){
	    printf("\e[45;1m");
	  } else if (board[i][j] == 2048){
	    printf("\e[46;1m");
	  } else {
	    printf("\e[100m");
	  }
	}
	printf(" %d ",board[i][j]);
	printf("\e[m");
	printf("\t");
      }
    }
    printf("\r\n");
  }
}

int move_tile_x_plus(int board[][N], int board_flag[][N], int x, int y){
  if(board[y][x] != 0){
    for(int i = x; i < N-1; ++i){
      if(board[y][i+1] == 0){
	board[y][i+1] = board[y][i];
	board[y][i] = 0;
      }
      if(board[y][i+1] == board[y][i] && board_flag[y][i] != 1 && board_flag[y][i+1] != 1){
	board[y][i+1] = board[y][i]*2;
	board_flag[y][i+1] = 1;
	board[y][i] = 0;
      }
    }
  }
  return 0;
}

int move_tile_x_minus(int board[][N], int board_flag[][N], int x, int y){
  if(board[y][x] != 0){
    for(int i = x; i > 0; --i){
      if(board[y][i-1] == 0){
	board[y][i-1] = board[y][i];
	board[y][i] = 0;
      }
      if(board[y][i-1] == board[y][i] && board_flag[y][i] != 1 && board_flag[y][i-1] != 1){
	board[y][i-1] = board[y][i]*2;
	board_flag[y][i-1] = 1;
	board[y][i] = 0;
      }
    }
  }
  return 0;
}

int move_tile_y_plus(int board[][N], int board_flag[][N], int x, int y){
  if(board[y][x] != 0){
    for(int i = y; i < N-1; ++i){
      if(board[i+1][x] == 0){
	board[i+1][x] = board[i][x];
	board[i][x] = 0;
      }
      if(board[i+1][x] == board[i][x] && board_flag[i][x] != 1 && board_flag[i+1][x] != 1){
	board[i+1][x] = board[i][x]*2;
	board_flag[i+1][x] = 1;
	board[i][x] = 0;
      }
    }
  }
  return 0;
}

int move_tile_y_minus(int board[][N], int board_flag[][N], int x, int y){
  if(board[y][x] != 0){
    for(int i = y; i > 0; --i){
      if(board[i-1][x] == 0){
	board[i-1][x] = board[i][x];
	board[i][x] = 0;
      }
      if(board[i-1][x] == board[i][x] && board_flag[i][x] != 1 && board_flag[i-1][x] != 1){
	board[i-1][x] = board[i][x]*2;
	board_flag[i-1][x] = 1;
	board[i][x] = 0;
      }
    }
  }
  return 0;
}

int main (int argc, char *argv[]) {
    N = 4;
  
    srand((unsigned int)time(NULL));
    printf("Press any key to conitnue\n");
    int c;
    
    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる
    
    int evenodd_mode = 0;
    for(int i = 0; i < argc - 1; ++i){
      if(!(strcmp(argv[i+1],"-evenodd"))){
	evenodd_mode = 1;
      }
      if(atoi(argv[i+1]) != 0){
	N = atoi(argv[i+1]);
      }
    }

    int board[N][N];
    int board_flag[N][N];
    int max2 = 0;
    int max3 = 0;

    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
	if(rand()/2147483647.0 < 0.15){
	  board[i][j] = 2;
	} else if (rand()/2147483647.0 < 0.30){
	  if(evenodd_mode){
	    board[i][j] = 3;
	  } else {
	    board[i][j] = 0;
	  }
	} else {
	  board[i][j] = 0;
	}
      }
    }
          
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
	board_flag[i][j] = 0;
      }
    }
    
    system("clear");
    printf("Press '.' to close\r\n");
    print_board(board, evenodd_mode);
    
    while((c = getchar()) != '.') {
        system("clear");
        printf("Press '.' to close\r\n");

	if(c == 'C'){
	  for(int j = 0; j < N; ++j){
	    for(int i = N-1; -1 < i; --i){
	      move_tile_x_plus(board,board_flag,i,j);
	    }
	  }
	}

	if(c == 'B'){
	  for(int j = 0; j < N; ++j){
	    for(int i = N-1; -1 < i; --i){
	      move_tile_y_plus(board,board_flag,j,i);
	    }
	  }
	}

	if(c == 'D'){
	  for(int j = 0; j < N; ++j){
	    for(int i = 0; i < N; ++i){
	      move_tile_x_minus(board,board_flag,i,j);
	    }
	  }
	}

	if(c == 'A'){
	  for(int j = 0; j < N; ++j){
	    for(int i = 0; i < N; ++i){
	      move_tile_y_minus(board,board_flag,j,i);
	    }
	  }
	}
	
	for(int i = 0; i < N; ++i){
	  for(int j = 0; j < N; ++j){
	    if(board_flag[i][j] == 1){
	      board_flag[i][j] = 0;
	    }
	  }
	}

	if(c=='A' || c=='B' || c=='C' || c=='D'){
	  for(int i = 0; i < N; ++i){
	    for(int j = 0; j < N; ++j){
	      if(board[i][j] == 0){
		if(rand()/2147483647.0 < 0.15){
		  board[i][j]=2;
		} else if (rand()/214783647.0 < 0.3){
		  if(evenodd_mode == 1){
		    board[i][j] = 3;
		  }
		}
	      }
	    }
	  }
	}

	for(int i = 0; i < N; ++i){
	  for(int j = 0; j < N; ++j){
	    if(board[i][j] % 3 != 0 && board[i][j] >= max2){
	      max2 = board[i][j];
	    } else if (board[i][j] % 3 == 0 && board[i][j] > max3){
	      max3 = board[i][j];
	    }
	  }
	}
	
	print_board(board,evenodd_mode);
	
	printf("You pressed '%c'\r\n", c);
	if(evenodd_mode){
	  printf("Max of multiples of 2:\t%d\r\nMax of multiples of 3:\t%d\r\nYour current score:\t%d\r\n", max2,max3,max2+max3);
	} else {
	  printf("your current score: %d\r\n",max2);
	}
	/*上下左右*/
    }
    
    
    system("/bin/stty cooked");  // 後始末

    return 0;
}
