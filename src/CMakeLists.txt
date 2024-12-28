add_library(app_common_options INTERFACE)

target_compile_options(app_common_options INTERFACE -Wall)
set_target_properties(app_common_options PROPERTIES CXX_SCAN_FOR_MODULES OFF)
target_compile_features(app_common_options INTERFACE cxx_std_23)

target_compile_definitions(
    app_common_options INTERFACE
    win_common_options
)

add_subdirectory(caps2lctrl)
