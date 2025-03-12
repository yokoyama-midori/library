---
title: 最大独立集合
documentation_of: ./graph/maximum-independent-set.hpp
---

rem : 未決定頂点集合  
cur : 採用する頂点集合  
nbd[i]&rem : iと隣接する未決定頂点集合  
degが1以下ならその頂点を採用して損しない  
そのような頂点がなくなったらdeg最大の頂点を使うor使わないで分岐  

## LINK
- <https://maspypy.github.io/library/graph/maximum_independent_set.hpp>
- <https://yukicoder.me/problems/no/382>
