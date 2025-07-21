add_library(cpp-physics
	matrix/matrix.cpp
	
)
target_include_directories(cpp-physics PUBLIC
	./matrix/
)
set(PUBLIC_HEADERS
	matrix/matrix.hpp
)
set_target_properties(cpp-physics PROPERTIES
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "cpp-physics.hpp;${PUBLIC_HEADERS}"
)

include(GNUInstallDirs)
install(TARGETS cpp-physics
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cpp-physics
)
