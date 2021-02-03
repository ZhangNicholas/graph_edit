cmake_minimum_required(VERSION 3.5)

if($ENV{TRAVIS_BUILD_NUMBER})
	project(graph_edit VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project(graph_edit VERSION 0.0.1)
endif()

set(CMAKE_CXX_STANDARD 14)
find_package(GTest REQUIRED)

set(SOURCES
	main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/arc.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/controller.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/factory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/graphic_primitive.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/model.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/point.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/view.cpp
)

# Main target
add_executable(graph_edit ${SOURCES})

add_executable(
	tests
	test/graph_edit_test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/arc.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/controller.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/factory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/graphic_primitive.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/model.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/point.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/view.cpp
)

set_target_properties(graph_edit tests PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(
	graph_edit
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/interfaces"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/headers"
)

target_include_directories(
	tests
	PRIVATE ${GTEST_INCLUDE_DIRS}
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/sources"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/interfaces"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/headers"
)

target_link_libraries(
	tests PRIVATE
	${GTEST_BOTH_LIBRARIES}
)

if (MSVC)
	# @see https://github.com/google/googletest/blob/master/googletest/README.md
	# Visual Studio Dynamic vs Static Runtimes
	#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

	target_compile_options(
		graph_edit PRIVATE
		/WX
	)
	target_compile_options(
	tests PRIVATE
	/WX
	)
else ()
	target_compile_options(
		graph_edit PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(
		tests PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()

install(TARGETS graph_edit RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT cnickol@gmail.com)

include(CPack)

enable_testing()

add_test(tests tests) 