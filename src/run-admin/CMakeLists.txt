add_executable(run-admin)

set_target_properties(
	run-admin PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

set_target_properties(
    run-admin PROPERTIES
    CXX_SCAN_FOR_MODULES OFF
)
target_sources(
    run-admin PUBLIC
    main.cpp
)

target_include_directories(
    run-admin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(
	run-admin PUBLIC
    app_common_options
    win_process
)
