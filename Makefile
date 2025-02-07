# プリコンパイル
CXX = g++ -std=c++20 -g -fsanitize=undefined,address -DLOCAL

all: template.hpp.gch

template.hpp.gch: template.hpp
	$(CXX) -x c++-header template.hpp -o template.hpp.gch

clean:
	rm -f template.hpp.gch

serve:
	oj-verify docs
	cd .verify-helper/markdown/ && bundle exec jekyll serve --incremental

.PHONY: all clean
