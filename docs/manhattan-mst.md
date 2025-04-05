---
title: マンハッタン距離での最小全域木(となる辺の候補)
documentation_of: ./geometry/manhattan-mst.hpp
---

## 概要
2次元格子点上の$N$点を頂点とし、頂点間のマンハッタン距離を重みとするグラフの最小全域木について$O(N)$本の辺の候補を$O(N \log N)$で計算する。

<!-- ## 説明
$||sp||$で点$s,p$間のマンハッタン距離$|s_x-p_x|+|s_y-p_y|$を表すとします。点$s$と結ばれる可能性のある点はどのような点でしょうか？点sを通り$x$軸,$y$軸に平行な直線、及びそれらに$45$度なす2直線の4つの直線を引き平面を8個の領域に分けます。(論文とは異なり各領域は境界を含むとします。)  
このとき各領域$R$は次の条件を満たします。  
任意の$p,q\in R$について$||pq||\le \max(||sp||,||sq||)$  
TODO 等号は$||sp||=||sq||=||pq||$のとき

<details><summary>証明</summary>
対称性から1つの領域のみについて示せばよいです。
その領域として北北東のもの、すなわち$x\ge x_s , x-y\le x_s-y_s$をとります。また$x_p \le x_q$を仮定してよいです。$y_p \le y_p$のとき$||sq|| = ||sp||+||pq||\ge ||pq||$なのでよいです。$x_p \ge x_q$のとき  
$ ||pq|| = (x_q-x_p) + (y_p-y_q) = (x_q-y_q)+(y_p-x_p) $  
$\le (x_s-y_s)+(y_p-x_p) =-(x_p-x_s)+(y_p-y_s)\le(x_p-x_s)+(y_p-y_s)=||sp||$となります。
</details> -->


## 参考
Hai Zhou, Narendra Shenoy, and William Nicholls. 2001. Efficient minimum spanning tree construction without Delaunay triangulation.



