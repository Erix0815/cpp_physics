all: clean fmt doc build test demo

build:
	@mkdir -p bin
	@cmake -B bin
	@make -sC bin all

clean:
	@git clean -fXd

fmt:
	@find src/ -iname '*.h' -o -iname '*.c' -o -iname '*.hpp' -o -iname '*.cpp' | xargs clang-format -i

test: build
	@make -sC bin test

demo: build
	./bin/src/demo/cpp-physics_demo

doc:
	@doxygen Doxyfile
