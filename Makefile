@PHONY: clean fmt doc ini test 

ini:
	@mkdir -p bin
	@cmake -B bin

build:
	@make -sC bin cpp-physics_lib

clean:
	@git clean -fXd

fmt:
	@find src/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

build-test:
	@make -sC bin cpp-physics_test

test: build-test
	./bin/src/test/cpp-physics_test

doc:
	doxygen Doxyfile
