---
title: Polynomial Taylor Shift(平行移動)
documentation_of: ./poly/poly_taylor_shift.hpp
---
$N-1$次多項式$f(x)$に対して、$g(x) = f(x + c)$を${\cal O}(N \log N)$で求める。

<!-- $g(x) = f(x+c) = \sum_{i = 0}^{N-1}f_i (x+c)^i$
$ = \sum_{i = 0}^{N-1}f_i \sum_{j=0}^{j} \binom{i}{j}x^j c^{i-j} $
$=\sum_{0\leq j\leq i<N} (f_i i!)\frac{x^j}{j!}\frac{c^{i-j}}{(i-j)!} $
$ =\sum_{j=0}^{N-1}\frac{x^j}{j!}\sum_{i = 0}^{N-1-j} (f_{i+j}(i+j)!)\frac{c^i}{i!} $ -->
