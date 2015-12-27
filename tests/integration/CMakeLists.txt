macro (CreateExampleExe base_name)
    add_executable(${base_name} "${base_name}.cc")
    qt5_use_modules(${base_name} Core Widgets)
    target_link_libraries(${base_name}
        ${GTEST_LIBRARIES}
        ${GROUPLISTWIDGET_LIBRARY})
endmacro()

CreateExampleExe(example_01)
CreateExampleExe(example_02)
CreateExampleExe(example_03)
