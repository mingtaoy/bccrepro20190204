cmake_minimum_required(VERSION 3.13)
project(bccrepro)
include(FindPkgConfig)


pkg_check_modules(
    BCC REQUIRED IMPORTED_TARGET libbcc
)

add_executable(
    bccrepro
    main.cc
)

target_link_libraries(
    bccrepro
    PkgConfig::BCC
)
