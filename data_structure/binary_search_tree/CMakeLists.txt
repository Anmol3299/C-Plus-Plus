# cmake version to be required
cmake_minimum_required( VERSION 3.0.0 )

# project name
project( bst VERSION 0.1.0)

# flags
# Tell compiler to use C++ 17 features
set(CMAKE_CXX_STANDARD 17)

# target
add_executable( bst ./main.cpp )