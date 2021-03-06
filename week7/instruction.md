# 2048 Game
J4-191150 藤田誠之

## 実行コマンド
````
$ gcc main.c
$ ./a.out 
````
でゲームが実行されます。上記のままだと4 x 4の通常モードでの実行になりますが、引数を与えることもできます。まず、整数をひとつ引数として与えると、盤の大きさを指定できます。例えば、
````
$ ./a.out 10
````
とすると、10 x 10の状態でゲームが始まります。また、後述するevenoddモードをオンにするには、`-evenodd`を引数として渡します。上記と組み合わせることも可能です。引数の順番は不問です。
````
$ ./a.out -evenodd 10
````
矢印キーで操作をします。また、画面下には得点が表示されます。

## evenoddモードについて
実行時に`-evenodd`というオプションをつけると、evenoddモードでのプレイが可能になります。<br>
通常モードでは最初に表示されるタイルは2のみですが、evenoddモードでは最初に表示されるタイルは2と3の２種類があります。プレイを進めていくにつれ、evenoddモードでは2の乗数と3の乗数のタイルが盤上に現れます。
2の乗数のタイルと3の乗数のタイルはそれぞれ独立には2048のルールに従って動きますが、互いに同じ数字になることはないため合成することもありません。<br>
最終的なスコアは、盤面が埋まった状態の時の3の乗数のうち最大のものと、2の乗数のうち最大のものの和となります。<br >
盤面の大きさを大きくすればするほど高い数字にたどり着くのが簡単になる一方、evenoddモードではすぐに盤面が埋まってしまいます。そのため、evenoddモードでは広めの盤面を使用した方が楽しいです。

## コードの説明
コードは全て`main.c`で完結しています。`main.c`には`print_board()`、`move_tile_x_plus`に類似したものが４種類、そして`main()`が関数として入っています。

### `main()`関数、`move_tile_x_plus()`関数
諸々を実行するmain()関数です。<br >
<br >
まず、`argv`を見て、盤面の大きさを変更するべきか、evenoddモードを有効にするべきかを確認します。その後、`rand()`関数で初期値のタイルの生成を決めています。<br>
`while`ループに入ってからは、キー操作によって分岐しています。コーナーケースに対応したプログラムを書こうとした結果、4つの関数を作ることとなってしまいました。<br >
マスの動かし方は工夫してあります。以下のようなケースに対応できるようなプログラムになっています。<br >
`. 4 2 2` → `. . 4 4`<br >
`. 2 2 2` → `. . 2 4`<br >
`4 4 2 2` → `. . 8 4`<br >
`4 2 2 4` → `. 4 4 4`<br >
例えば右向きのキーが押されたとき、各行ごとに盤面の右端のマスから左端のマスまで１マスずつ`move_tile_x_plus()`関数が実行されます。ここでマスの座標も受け渡されます。`move_tile_x_plus()`関数内では、受け取ったマスから右端までのマスを見て、次のマスが空いていれば１マス移動、空いておらず同じタイルがあれば１マス合成、ということをします。これを繰り返すことにより、上記のようなコーナーケースにも特別なコードを書かずに対応できるようになっています。また、このままこれを繰り返してしまうと１回のキープレスで以下のようなことが起こってしまいます。<br >
`. 4 2 2` → `. . 4 4` → `. . . 8`<br>
これを防ぐために、合成されたマスは`board_flag`という変数に記録され、それ以上合成されないようになっています。<br >
`move_tile_x_plus()`、`move_tile_x_minus()`、`move_tile_y_plus()`、`move_tile_y_minus()`の４つの関数は内容が似ているため、一つの関数にまとめることもできそうですか、`for`ループの巡る位置や順番が異なるため、4つの関数を使うこととなりました。

### `print_board()`関数
`print_board()`関数は`board`という引数を受け取り画面に表示します。画面の表示も工夫しました。<br >
まず、タイルによって色が異なるようにしました。通常モードではタイルによって色と文字の太さが異なるようになっています。また、evenoddモードでは2の乗数と3の乗数が別の色で表示されるようになっています。