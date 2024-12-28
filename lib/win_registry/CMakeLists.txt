add_library(win_registry)

target_include_directories(
    win_registry PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(
    win_registry PRIVATE
    CregHandler.cpp
    CregAdmin.cpp
)

target_link_libraries(
    win_registry PUBLIC
    win_common_options
    utility
)
