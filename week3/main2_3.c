#include <stdio.h>
#include <stdlib.h>

/* 自由に編集してください */

int main() {
    int x = 0;
    int y = 0;
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
        // キーボード入力の処理
        if (c == '\n') {
            continue;
        } else if (c == 'k') {
            ++x;
        }
        if (c == '\n') {
          continue;
        } else if (c == 'k') {
	  if (x < 5){++temp_x;}
        } else if (c == 'i') {
	  if (y > 0){--temp_y;}
	} else if (c == 'j') {
	  if (x > 0){--temp_x;}
	} else if (c == 'm') {
	  if (y < 4){++temp_y;}
	}

	//盤面チェック
	if (board[temp_y][temp_x] == 'x'){
	  temp_x = x;
	  temp_y = y;
	} else {
	  x = temp_x;
	  y = temp_y;
	  if (board[y][x] - '0' > 0 && board[y][x] - '0' < 10){
	    point += board[y][x] - '0';
	  }
	}

        system("clear");  // これは画面を綺麗にする関数です

        // 自分の位置の描画
        board[y][x] = 'o';

        // ボードの表示
        for (int n = 0; n < 5; ++n) {
           printf("%s\n", board[n]);
        }

        // 得点の表示
        printf("point: %d\n", point);  // !!!! ここでpointを表示

        // 自分の位置を背景に戻す
        board[y][x] = '-';
    }
    
    return 0;
}
