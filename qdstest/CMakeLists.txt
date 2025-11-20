if(WIN32)
    set(targetname qdstest)
else()
    set(targetname qdstest_app)
endif()

qt_add_executable(${targetname}
    "${CMAKE_CURRENT_LIST_DIR}/dsop.cc"
    "${CMAKE_CURRENT_LIST_DIR}/dsop.hh"
    "${CMAKE_CURRENT_LIST_DIR}/main.cc"
    "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
target_compile_features(${targetname} PRIVATE cxx_std_20)
target_link_libraries(${targetname} PRIVATE Qt6::Core)
target_include_directories(${targetname} PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(${targetname} PRIVATE "$ENV{LIBRARIES_DIR}/eigen/include")
target_precompile_headers(${targetname} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/pch.hh")
