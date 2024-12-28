add_library(win_process)

target_include_directories(
    win_process PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(
    win_process PRIVATE
    CprocExec.cpp
    CprocPipe.cpp
)

target_link_libraries(
    win_process PUBLIC
    win_common_options
    utility
)
