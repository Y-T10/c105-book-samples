add_library(win_common_options INTERFACE)


target_compile_options(win_common_options INTERFACE -Wall)
set_target_properties(win_common_options PROPERTIES CXX_SCAN_FOR_MODULES OFF)
target_compile_features(win_common_options INTERFACE cxx_std_23)

target_compile_definitions(
    win_common_options INTERFACE
    -DSTRICT
    -DNOMIMAX
)

add_subdirectory(win_registry)
add_subdirectory(win_process)
add_subdirectory(utility)
