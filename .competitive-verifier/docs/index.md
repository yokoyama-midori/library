![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/yokoyama-midori/library) [![yokoyama-midori](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2Fyokoyama-midori)](https://codeforces.com/profile/yokoyama-midori)  
C++20による競技プログラミング用ライブラリ  
[competitive-verifier](https://competitive-verifier.github.io/competitive-verifier/)により自動でテスト、デプロイされています

## メモ
### C++ジャッジ環境(C++20以降,gcc)  
2025/05/05時点

| オンラインジャッジ                                                        | C++20     | C++23     | ライブラリ                                                      | 備考                                         |
| ------------------------------------------------------------------------- | --------- | --------- | --------------------------------------------------------------- | -------------------------------------------- |
| [AtCoder](https://img.atcoder.jp/file/language-update/language-list.html) | gcc12.2   | gcc12.2   | AC Library 1.5.1, Boost 1.82.0, GMP 6.2.1, Eigen 3.4.0-2ubuntu2 | 言語アップデートでC++23(gcc~~14.2.0~~ 15.1.0)になる予定 |
| yukicoder                                                                 | なし      | gcc13.3.0 | AC Library (version?), Boost 1.87.0                             |                                              |
| Codeforces                                                                | gcc13.2   | gcc14.2   | -                                                               |                                              |
| [CodeChef](https://www.codechef.com/wiki/list-compilers)                  | gcc13.2   | なし      | -                                                               |                                              |
| [AIZU ONLINE JUDGEv2](https://onlinejudge.u-aizu.ac.jp/system_info)       | gcc11.4.1 | gcc11.4.1 | -                                                               | 新しいサイトを使う                           |
| [Library Checker](https://judge.yosupo.jp/help)                           | gcc14.2   | gcc14.2   | AC Library 1.5.1                                                |                                              |

__gnu_pbds::treeはどれも使える  
ChefでC++23が使えないので当面C++20を使う  
std::bit_widthはgcc13.1(?)で返り値がintになった。それ以前は符号なしの返り値なので注意  

<!-- ### リロードしても更新が反映されないとき(Google Chrome)
下のどれかを行う。下にいく方が永続的
- ハードリロード(ctrl+shift+R)する
- F12&rarr;アプリケーション&rarr;ストレージ&rarr;サイトデータを消去
- .competitive-verifier/docs/static/_includes/head-custom2.htmlに

```
<meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate">
<meta http-equiv="Pragma" content="no-cache">
<meta http-equiv="Expires" content="0">
```

を追加。[参考](https://deepwiki.com/search/github-pages-pages-httplast-mo_8bb989be-7fd6-45ac-8023-5f3c01c5d512) 

3つ目に関してはGitHub Pagesでは無理っぽい
https://github.com/yokoyama-midori/library/commit/5907237b9c5e0affdfcd901c92a1ed84d249621e
は効果あるけどページの遷移でガタつく
-->