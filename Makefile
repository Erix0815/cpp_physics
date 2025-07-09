@PHONY: test

ini:
	@mkdir -p bin
	@cmake -B bin

clean:
	@git clean -fXd

fmt:
	@find src/ -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

test: ini
	@make -sC bin cpp-physics_test
	./bin/cpp-physics_test

build: ini
	$(info "make build" not implemented yet)

doc:
	doxygen Doxyfile
