qt_add_executable(qdstest
    "${CMAKE_CURRENT_LIST_DIR}/dsop.cc"
    "${CMAKE_CURRENT_LIST_DIR}/dsop.hh"
    "${CMAKE_CURRENT_LIST_DIR}/main.cc"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_compile_features(qdstest PRIVATE cxx_std_20)
target_link_libraries(qdstest PRIVATE Qt6::Core)
target_include_directories(qdstest PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(qdstest PRIVATE "$ENV{LIBRARIES_DIR}/eigen/include")
target_precompile_headers(qdstest PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
