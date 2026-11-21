# program/CMakeLists.txt

set(NAME "${PROJECT_NAME}")

add_executable(${NAME}
    src/main.cpp
)

target_include_directories(${NAME}
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${NAME} PRIVATE
        ${PROJECT_NAME}::Command
        ${PROJECT_NAME}::Core
)

add_subdirectory(src)
