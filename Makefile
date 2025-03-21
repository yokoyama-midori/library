# プリコンパイル
CXX = g++ -std=c++20 -g -fsanitize=undefined,address -I//home/y_midori/cp/library -DLOCAL

all: template.hpp.gch

template.hpp.gch: template.hpp
	$(CXX) -x c++-header template.hpp -o template.hpp.gch

clean:
	rm -f template.hpp.gch

empty:
	git commit --allow-empty -m"empty commit"

.PHONY: all clean

resolve:
	competitive-verifier oj-resolve --config .verify-helper/config.toml > .competitive-verifier/verify_file.json

verify:resolve
	competitive-verifier verify --verify-json .competitive-verifier/verify_file.json --prev-result .competitive-verifier/result.json --output .competitive-verifier/result.json

docs:.competitive-verifier/verify_file.json .competitive-verifier/result.json
	competitive-verifier docs --verify-json .competitive-verifier/verify_file.json .competitive-verifier/result.json

serve:docs
	cd .competitive-verifier/_jekyll && bundle exec jekyll serve --incremental --livereload
