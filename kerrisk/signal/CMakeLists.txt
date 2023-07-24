cmake_minimum_required(VERSION 3.16)

project(sigset)
set(CMAKE_CXX_STANDARD 20)
set(SIG_SENDER "sig_sndr")
set(SIG_RECEIVER "sig_recv")

include_directories(siglib)
link_directories(PUBLIC "build/siglib/")
add_subdirectory(siglib)
link_libraries(-lsiglib)

# Signal sender
add_executable(${SIG_SENDER} sig_sndr.cpp)
# Signal recevier   

