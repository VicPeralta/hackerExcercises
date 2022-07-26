cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(hackerRank VERSION 1.0 LANGUAGES CXX DESCRIPTION "HackerRank Challenges")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_executable(betweenArrays src/betweenArrays.cpp)
add_executable(countingValleys src/countingValleys.cpp)
add_executable(dayProgrammer src/dayProgrammer.cpp)
add_executable(diagonal-difference src/diagonal-difference.cpp)
add_executable(divisibleSumPairs src/divisibleSumPairs.cpp)
add_executable(drawingBook src/drawingBook.cpp)
add_executable(electronicShop src/electronicShop.cpp)
add_executable(magicSquare src/magicSquare.cpp)
add_executable(main src/main.cpp)
add_executable(migratoryBirds src/migratoryBirds.cpp)
add_executable(permutation src/permutation.cpp)
add_executable(sockMerchant src/sockMerchant.cpp)
add_executable(subArrayDivision src/subArrayDivision.cpp)
add_executable(TaumAndBday src/TaumAndBday.cpp)
add_executable(bubbleSort src/bubbleSort.cpp)
add_executable(decorator src/decorator.cpp)
add_executable(decrypt src/decrypt_message.cpp)
add_executable(encryp src/encrypt_message.cpp)
add_executable(shortest src/shortest_path.cpp)
add_executable(islands src/numberOfIslands.cpp)
add_executable(containers src/container-water.cpp)
add_executable(quickSort src/quickSort.cpp)