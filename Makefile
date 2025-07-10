@PHONY: clean fmt doc ini test 

ini:
	@mkdir -p build
	@cmake -B build

build:
	@make -sC build cpp-physics_lib

clean:
	@git clean -fXd

fmt:
	@find src/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

test: build
	@make -sC build cpp-physics_test
	./build/src/test/cpp-physics_test

doc:
	doxygen Doxyfile
