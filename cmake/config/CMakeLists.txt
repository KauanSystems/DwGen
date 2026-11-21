# cmake/config/CMakeLists.txt

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${HEADER_PROG}.in"
    "${CMAKE_BINARY_DIR}/${FILE_NAME}/${HEADER_NAME}"
    @ONLY
)
