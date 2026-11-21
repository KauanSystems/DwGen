# cmake/config/CMakeLists.txt

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${HEADER_PROG}.in"
    "${CMAKE_BINARY_DIR}/${FILE_NAME}/${HEADER_NAME}"
    @ONLY
)

file(READ "${WORDLIST_FILE}" WORDLIST_CONTENT)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${HEADER_PROG_II}.in"
    "${CMAKE_BINARY_DIR}/${FILE_NAME}/${HEADER_NAME_II}"
    @ONLY
)
