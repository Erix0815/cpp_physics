# c_physics_engine

A custom physics engine written in C/C++

<a href="">
  <img alt="GitHub branch check runs" src="https://img.shields.io/github/check-runs/Erix0815/cpp_physics/main?nameFilter=build&logo=cmake&logoSize=auto&label=Build-check"></a>
<a href="https://erix0815.github.io/cpp_physics/">
  <img alt="Website" src="https://img.shields.io/website?url=https%3A%2F%2Ferix0815.github.io%2Fcpp_physics%2F&up_message=online&down_message=offline&logo=doxygen&logoSize=auto&label=GH-Pages"></a>

## Requirements

- `cmake` for compiling
- `make` unless you want to type the shell-commands
- `gcc` / `clang` / possibly any other compiler
- `gdb` for debugging
- `clang-format` & `clang-tidy` to make the code look nice
- `doxygen` in case you want documentation

*tested only under windows with wsl and ubuntu-latest, so no promises :)*

## Makefile

- `make clean`: delete files ignored by git
- `make fmt`: format all code
- `make test`: build and execute all unittests

- `make doc`: generate documantation
- `make build`: build the lib
- `make demo`: build and run the current demo
