cmake_minimum_required(VERSION 3.21)

# set the project name
project(ca-utils)

# set the output directories
set (ProdDir "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ProdDir}/lib/static")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ProdDir}/lib/shared")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ProdDir}/bin")

include_directories(
    "."
    "include"
)

# to keep things clean keep the sources in groups
set (memstream
    "src/memstream/memstream_getc.c"
    "src/memstream/memstream_putc.c"
    "src/memstream/memstream_read.c"
    "src/memstream/memstream_write.c"
    "src/memstream/memstream_tell.c"
    "src/memstream/memstream_seek.c"
    "src/memstream/memstream_eof.c"
)

set (general 
    "src/filename.c"
    "src/drop_extension.c"
    "src/filesize.c"
)

# consolidate the groups
set (sources 
    ${general}
    ${memstream}
)

# generate the consolidated library
add_library (${PROJECT_NAME} ${sources})

