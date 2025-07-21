add_library(cpp-physics
	matrix/matrix.cpp
	math/math.cpp
	
)
target_include_directories(cpp-physics PUBLIC
	./matrix/
	./math/
)
set(PUBLIC_HEADERS
	matrix/matrix.hpp
	math/math.hpp
)
set_target_properties(cpp-physics PROPERTIES
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "cpp-physics.hpp;${PUBLIC_HEADERS}"
)

include(GNUInstallDirs)
install(TARGETS cpp-physics
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp-physics
)
