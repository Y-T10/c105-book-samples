# 『Windows でadmin 実行』サンプルコードリポジトリ
## 概要
C105にて頒布した冊子『Windows でadmin 実行』に掲載されているコードのリポジトリです．
記事中のコードに加え、自作ライブラリも掲載しています．

## ビルド方法
このリポジトリを手元にクローンします．

```bash
git clone https://github.com/Y-T10/c105-book-samples.git
```

`CMake`を用いて下記の通りにコマンドを実行します．

```bash
cd c105-book-sample
cmake -S ./ -B build
cmake --build build
```

実行後、`c105-book-sample/bin`内にプログラムが生成されます．
