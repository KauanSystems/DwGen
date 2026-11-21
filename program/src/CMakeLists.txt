# program/src/CMakeLists.txt

set(LIB_COMM "${PROJECT_NAME}_Command")

add_library(${LIB_COMM} OBJECT # <---  IMPORTANT  --->
	command/registry/registry.cpp
	command/commands/help/help.cpp
	command/commands/logo/logo.cpp
	command/commands/version/version.cpp
	command/commands/creator/creator.cpp
	command/commands/manifest/manifest.cpp
	command/commands/system/system.cpp
	command/commands/generate/generate.cpp
)

add_library(${PROJECT_NAME}::Command ALIAS ${LIB_COMM})

target_include_directories(${LIB_COMM}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/program/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/program/include/command/registry>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/program/include/command/commands/manifest>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/generate>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/compare>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/export>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/core/include/verify>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/${FILE_NAME}>
        $<INSTALL_INTERFACE:include>
)
