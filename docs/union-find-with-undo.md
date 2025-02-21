---
title: UndoつきUnion Find
documentation_of: ./data_structure/union-find-with-undo.hpp
---

## 問題例

- [ABC302 Ex - Ball Collector](https://atcoder.jp/contests/abc302/tasks/abc302_h)  
連結成分の辺の数と頂点数を持つ
- [ABC334 G - Christmas Color Grid 2](https://atcoder.jp/contests/abc334/tasks/abc334_g)  
分割統治+undoつきUF
- [JOI 2021/2022 二次予選 E - 交易計画 (Trade Plan)](https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e)  
同じ州間の辺のみ予め貼っておく。州$i,j$間のクエリに対してまとめて、辺追加→クエリ回答→辺削除 をおこなう。州はたくさんあるのでクエリとして存在するもののみに対して行う。各辺は高々1回しか追加・削除されない。
