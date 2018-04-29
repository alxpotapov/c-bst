find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}
    ../src
)
if (UNIX)
    add_definitions(-DBOOST_TEST_DYN_LINK)
endif (UNIX)
add_executable(BstTest node_test.cpp tree_test.cpp)
target_link_libraries(BstTest
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

set_property(TARGET BstTest PROPERTY CXX_STANDARD 11)
