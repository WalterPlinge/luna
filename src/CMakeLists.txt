set(INCLUDE_DIR ../include/luna)
set(HEADER_FILES
	${INCLUDE_DIR}/files.hh
	${INCLUDE_DIR}/strings.hh
	${INCLUDE_DIR}/timer.hh
)
set(SOURCE_FILES
	files.cc
	strings.cc
	timer.cc
)

add_library(luna
	STATIC
		${HEADER_FILES}
		${SOURCE_FILES}
)

target_include_directories(luna
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)

target_compile_features(luna
	PUBLIC
		cxx_std_17
)

source_group(TREE
	${PROJECT_SOURCE_DIR}/include
	PREFIX "Luna"
	FILES ${HEADER_FILES}
)
