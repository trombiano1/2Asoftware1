#include <stdio.h>
#include <stdlib.h>

/* 自由に編集してください */

int main() {
    int x[30];
    int y[30];
    for(int i = 0; i < sizeof(x)/sizeof(x[0]); i++){
      x[i] = -1;
    }
    for(int i = 0; i < sizeof(y)/sizeof(y[0]); i++){
      y[i] = -1;
    }
    x[0] = 0;
    y[0] = 0;
    int temp_x = 0;
    int temp_y = 0;
    int point = 0;  // !!!!! ここでpointを宣言

    char board[5][6] = {
        "-1---",
        "---x-",
        "-x---",
        "---1-",
        "x-1x-"
    };

    for(int c = 0; c != EOF; c = getchar()) {
        temp_x = -1;
        temp_y = -1;
        // キーボード入力の処理
        if (c == '\n') {
            continue;
        } else if (c == 'k') {
	  if (x[0] < 4){
	    temp_x = x[0] + 1;
	    temp_y=y[0];
	  }
        } else if (c == 'i') {
	  if (y[0] > 0){
	    temp_y = y[0] - 1;
	    temp_x=x[0];
	  }
	} else if (c == 'j') {
	  if (x[0] > 0){
	    temp_x = x[0] - 1;
	    temp_y = y[0];
	  }
	} else if (c == 'm') {
	  if (y[0] < 4){
	    temp_y = y[0] + 1;
	    temp_x = x[0];
	  }
	}

	//盤面チェック
	if (board[temp_y][temp_x] == 'x' || board[temp_y][temp_x] == 'o'){
	  temp_x = -1;
	  temp_y = -1;
	} else {
	  if(temp_x != -1 && temp_y != -1){
	    if (board[temp_y][temp_x] - '0' > 0 && board[temp_y][temp_x] - '0' < 10){
	      point += board[temp_y][temp_x] - '0';
	    }
	    for(int j = point; j > -1; j--){
	      x[j] = x[j-1];
	      y[j] = y[j-1];
	    }
	    x[0] = temp_x;
	    y[0] = temp_y;
	  }
	}

        system("clear");  // これは画面を綺麗にする関数です

	// 自分の位置の描画
	for(int j = point; j > -1; j--){
	  board[y[j]][x[j]] = 'o';
	}
	// ボードの表示
        for (int n = 0; n < 5; ++n) {
           printf("%s\n", board[n]);
        }

        // 得点の表示
        printf("point: %d\n", point);// !!!! ここでpointを表示

        // 自分の位置を背景に戻す
        for(int j=point; j > -1; j--){
	  board[y[j]][x[j]] = '-';
	}
    }
    
    return 0;
}
