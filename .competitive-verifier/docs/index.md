![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/yokoyama-midori/library) [![yokoyama-midori](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fcodeforces%2Fjson%2Fyokoyama-midori)](https://codeforces.com/profile/yokoyama-midori)  
C++20による競技プログラミング用ライブラリ  
[competitive-verifier](https://competitive-verifier.github.io/competitive-verifier/)により自動でテスト、デプロイされています

## メモ
### C++ジャッジ環境(C++20以降,GCC)  
2025/11/11 更新

| オンラインジャッジ                                                        | C++20      | C++23      | ライブラリ                                                                                                                                                                              | 備考                                                                            |
| ------------------------------------------------------------------------- | ---------- | ---------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| [AtCoder](https://img.atcoder.jp/file/language-update/language-list.html) | なし       | GCC 15.2.0 | Abseil 20250512.1,  AC Library 1.6, Boost 1.88.0, Eigen 3.4.0, GMP 6.3.0, immer 0.8.1, libtorch 2.8.0, LightGBM 4.6.0, OR-Tools 9.14, Range-v3 0.12.0, unordered_dense 4.5.0, Z3 4.15.0 | https://uni-kakurenbo.github.io/AtCoder-Language-Update_2024-11_CXX23_proposal/ |
| yukicoder                                                                 | なし       | GCC 13.3.0 | AC Library (version?), Boost 1.87.0                                                                                                                                                     |                                                                                 |
| Codeforces                                                                | GCC 13.2   | GCC 14.2   | -                                                                                                                                                                                       |                                                                                 |
| [CodeChef](https://www.codechef.com/wiki/list-compilers)                  | GCC 13.2   | なし       | -                                                                                                                                                                                       |                                                                                 |
| [AIZU ONLINE JUDGEv2](https://onlinejudge.u-aizu.ac.jp/system_info)       | GCC 11.4.1 | GCC 11.4.1 | -                                                                                                                                                                                       | 新しいサイトを使う                                                              |
| [Library Checker](https://judge.yosupo.jp/help)                           | GCC 14.2   | GCC 14.2   | AC Library 1.5.1                                                                                                                                                                        |                                                                                 |

__gnu_pbds::treeはどれも使える  
ChefでC++23が使えないので当面C++20を使う  
std::bit_widthはGCC 13.1(?)で返り値がintになった。それ以前は符号なしの返り値なので注意  

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
や、やっぱり↑でもだめだな
-->

7日間テストしてないと、次のテストで全てのテストケースが実行されるっぽい（？）
https://deepwiki.com/search/competitiveverifierverify-test_2cd05edc-ee37-4951-adb0-1ef37202cb25