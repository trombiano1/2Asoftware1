#include <stdio.h>
#include <stdlib.h>

/* 自由に編集してください */

int main() {
    int x = 0;
    int y = 0;

    char board[5][6] = {
        "-----",
        "-----",
        "-----",
        "-----",
        "-----"
    };

    for(int c = 0; c != EOF; c = getchar()) {
        // キーボード入力の処理
        if (c == '\n') {
            continue;
        } else if (c == 'k') {
	  if (x < 4){++x;}
        } else if (c == 'i') {
	  if (y > 0){--y;}
	} else if (c == 'j') {
	  if (x > 0){--x;}
	} else if (c == 'm') {
	  if (y < 4){++y;}
	}

        system("clear");  // これは画面を綺麗にする関数です

        // 自分の位置の描画
        board[y][x] = 'o';

        // ボードの表示
        for (int n = 0; n < 5; ++n) {
           printf("%s\n", board[n]);
        }

        // 自分の位置を背景に戻す
        board[y][x] = '-';
    }
    
    return 0;
}
