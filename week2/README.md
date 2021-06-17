# week2の宿題

- 締切：**2020/10/14 23:59**
- 注意：全ての課題について、`stdio.h`と`stdilib.h`以外は`include`しないでください。
- 「発展課題」は、ボーナスです。解かなくても大丈夫です。解いた場合、加点があります。


## 宿題1：数字の逆転

### やるべきこと
- `main1.c`を改造し、次のプログラムを書いてください
- 2桁の整数の入力に対して、10の桁と1の桁を逆転させる
- 例：`21`の入力に対し、`12`を返す
  

### 実行コマンドと想定出力
```bash
$ gcc main1.c -o main1
$ ./main1 21
12
```

### 発展課題
桁数が2桁ではなく任意の桁の場合でも逆転出来るようにしてください。例：
```bash
$ ./main1 38349
94383
```


## 宿題2：市松模様

### やるべきこと
- `main2.c`を改造し、次のプログラムを書いてください
- 整数`n`が入力されたとき、一辺の長さが`n`である、市松模様を書いてください。市松模様は「A」と「B」を並べることで表現します。
- 例1：`4`の入力に対し、
  ```
  ABAB
  BABA
  ABAB
  BABA
  ```
  を返す
- 例2：`5`の入力に対し、
  ```
  ABABA
  BABAB
  ABABA
  BABAB
  ABABA
  ```
  を返す
  

### 実行コマンドと想定出力
```bash
$ gcc main2.c -o main2
$ ./main2 4
ABAB
BABA
ABAB
BABA
```




## 宿題3：自然対数の底の近似

### やるべきこと
- 自然対数の底「e」は、以下の式で表現されます
  
  <a href="https://www.codecogs.com/eqnedit.php?latex=e&space;=&space;1&space;&plus;&space;\frac{1}{1!}&space;&plus;&space;\frac{1}{2!}&space;&plus;&space;\frac{1}{3!}&space;&plus;&space;\cdots" target="_blank"><img src="https://latex.codecogs.com/gif.latex?e&space;=&space;1&space;&plus;&space;\frac{1}{1!}&space;&plus;&space;\frac{1}{2!}&space;&plus;&space;\frac{1}{3!}&space;&plus;&space;\cdots" title="e = 1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \cdots" /></a>

- ここで、`main3.c`を改造し、整数nの入力に対し以下を計算することでeを近似してください

  <a href="https://www.codecogs.com/eqnedit.php?latex=1&space;&plus;&space;\frac{1}{1!}&space;&plus;&space;\frac{1}{2!}&space;&plus;&space;\frac{1}{3!}&space;&plus;&space;\cdots&space;&plus;&space;\frac{1}{n!}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?1&space;&plus;&space;\frac{1}{1!}&space;&plus;&space;\frac{1}{2!}&space;&plus;&space;\frac{1}{3!}&space;&plus;&space;\cdots&space;&plus;&space;\frac{1}{n!}" title="1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \cdots + \frac{1}{n!}" /></a>

- 例1：`3`の入力に対し、`2.666667`を返す
- 例2：`6`の入力に対し、`2.718056`を返す

### 実行コマンドと想定出力
```bash
$ gcc main3.c -o main3
$ ./main3 3
2.666667
```

### 発展課題
- `main3_advanced.c`を改造し、次のようなプログラムを書いてください。
- 課題3で求めた処理を関数化し、`n`に対してeを近似する関数を`e(n)`とします。
- ある小数epsilonの入力に対し、正解との誤差がepsilon以下となる最小の`n`を求めてください。すなわち、|2.7182818284 - e(n)| < epsilon となる、最小のnを求めてください。
- 例：`0.1`の入力に対し、`3`
```bash
$ ./main3_advanced 0.1 
3
```

