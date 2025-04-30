# onefunc
関数型言語を実装しよう

https://knowledge.infiniteloop.co.jp/open.knowledge/view/24081

- レジスタ一個
- 関数スタック一個(もはやスタックと言えないのでEIPかも)
- 説明の簡略のため全部グローバル変数
- コールスタックを持たないためにガベコレを行なえないので、なんか考える
- 副作用で無理矢理計算と再帰に近い処理するのでインタプリタからパーサーとコンパイル処理を説明する予定
- アセンブラの話をするためにトークン分割と一対一対応の関数を定義する

## レジスタってやつ
https://knowledge.infiniteloop.co.jp/open.knowledge/view/24081
## 関数を格納するっていう方法
https://knowledge.infiniteloop.co.jp/open.knowledge/view/24121
## 格納したら実行出来るっていう話
https://knowledge.infiniteloop.co.jp/open.knowledge/view/24190
## バイトコードにしてみる準備ってやつ
https://knowledge.infiniteloop.co.jp/open.knowledge/view/24278
## 型ってやつを考えるために邪悪なconvert関数を生やすってやつ
https://knowledge.infiniteloop.co.jp/open.knowledge/view/24442

## バイトコードをJITによって動的にネイティブコードへするドキュメント
https://gcc.gnu.org/onlinedocs/jit/
