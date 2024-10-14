cmake_minimum_required(VERSION 3.10)
project(SeparateProjects)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# List of source files
set(SOURCE_FILES
    A.cpp
    B.cpp
    C.cpp
    D.cpp
    E.cpp
    F.cpp
    G.cpp
    H.cpp
    I.cpp
    I2.cpp
    J.cpp
    K.cpp
    L.cpp
)

# Create a separate executable for each source file
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the file name without extension
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)

    # Add executable
    add_executable(${FILE_NAME} ${SOURCE_FILE})

    # You can add any additional configurations for each executable here
    # For example, linking libraries:
    # target_link_libraries(${FILE_NAME} some_library)
endforeach()
