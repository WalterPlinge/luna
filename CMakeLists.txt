cmake_minimum_required(VERSION 3.14)
project(luna LANGUAGES CXX)

set(inc include/luna)
set(src
	${inc}/files.hh
	${inc}/strings.hh
	${inc}/timer.hh
)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME}
	INTERFACE
		${src}
)

target_include_directories(${PROJECT_NAME}
	INTERFACE
		${PROJECT_SOURCE_DIR}/include
)

target_compile_features(${PROJECT_NAME}
	INTERFACE
		cxx_std_17
)

target_link_options(${PROJECT_NAME}
	INTERFACE
		cxx_std_17
)
