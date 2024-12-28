add_executable(caps2lctrl)

set_target_properties(
	caps2lctrl PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

set_target_properties(
    caps2lctrl PROPERTIES
    CXX_SCAN_FOR_MODULES OFF
)
target_sources(
    caps2lctrl PUBLIC
    main.cpp
)

target_include_directories(
    caps2lctrl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
	caps2lctrl PUBLIC
    app_common_options
    win_registry
)
