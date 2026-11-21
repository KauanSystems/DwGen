# core/CMakeLists.txt

set(LIB_COMM "${PROJECT_NAME}_Core")

add_library(${LIB_COMM} OBJECT # <---  IMPORTANT  --->
	src/compare/compare.cpp
	src/generate/generator.cpp
	src/export/export.cpp
	src/verify/verify.cpp
)

add_library(${PROJECT_NAME}::Core ALIAS ${LIB_COMM})

target_include_directories(${LIB_COMM}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/program/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/generate>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/compare>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/export>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/verify>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/${FILE_NAME}>
        $<INSTALL_INTERFACE:include>
)
