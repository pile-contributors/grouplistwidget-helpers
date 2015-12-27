
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Will accumulate the source files
set(modules_testing_src "" CACHE INTERNAL "" )

#add_subdirectory (gui)
#add_subdirectory (io)
#add_subdirectory (logic)
#add_subdirectory (support)

if (modules_testing_src)
    list( REMOVE_DUPLICATES modules_testing_src )
    add_executable("internal-test"
        ${modules_testing_src}
    )
    qt5_use_modules("internal-test" Core Widgets)
    target_link_libraries ( "internal-test"
        ${GTEST_BOTH_LIBRARIES}
        lapbukmark
    )
    set ( props "${PROJECT_NAME_UPPER}_INTERNAL_TESTS=1")
    set_target_properties ( internal-test
        PROPERTIES COMPILE_DEFINITIONS "${props}"
    )
endif (modules_testing_src)

