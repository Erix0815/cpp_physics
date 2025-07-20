# cpp_physics

A custom physics engine written in C++

<a href="">
  <img alt="GitHub branch check runs" src="https://img.shields.io/github/check-runs/Erix0815/cpp_physics/main?nameFilter=build&logo=cmake&logoSize=auto&label=Unittests"></a>
<a href="https://erix0815.github.io/cpp_physics/">
  <img alt="Website" src="https://img.shields.io/website?url=https%3A%2F%2Ferix0815.github.io%2Fcpp_physics%2F&up_message=online&down_message=offline&logo=github&logoSize=auto&label=GH-Pages"></a>

## Requirements

- `cmake` & `make`
- a C++ compiler (`gcc` / `clang` / ... )
- `clang-format` & `clang-tidy`
- `doxygen`

## Makefile

| target|usage                          |
|------:|:------------------------------|
|  `all`|`clean fmt doc build test demo`|
| `demo`|build and run the current demo |
| `test`|build and execute all unittests|
|`build`|build the lib                  |
|  `doc`|generate documantation         |
|  `fmt`|format all code                |
|`clean`|delete files ignored by git    |
