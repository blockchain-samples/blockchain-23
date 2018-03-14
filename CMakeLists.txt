cmake_minimum_required( VERSION 3.10.2 )

message( "\nWIN32=${WIN32}" )
message( "UNIX=${UNIX}" )
message( "\nMINGW=${MINGW}" )
message( "MSVC=${MSVC}" )
message( "CMAKE_COMPILER_IS_GNUCXX=${CMAKE_COMPILER_IS_GNUCXX}" )
message( "\nCMAKE_GENERATOR=${CMAKE_GENERATOR}" )
message( "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}" )
message( "\nCMAKE_C_COMPILER=${CMAKE_C_COMPILER}" )
message( "CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}\n" )

set( CMAKE_CXX_STANDARD          17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS        OFF )

add_definitions( "-DUNICODE" "-D_UNICODE" )

if( CMAKE_GENERATOR MATCHES "MinGW Makefiles" OR CMAKE_GENERATOR MATCHES "Unix Makefiles" )
    add_compile_options( "-Wall" "-Wextra" "-Wshadow" "-pedantic" "-m64" "-march=x86-64" "-mfpmath=sse" )
    #add_compile_options( "-flto"/"-fno-lto" "-Wl,--strip-all" "-fverbose-asm" "-masm=intel" )
    #add_compile_options( "-static" "-static-libgcc" "-static-libstdc++" "-shared-libgcc" )
elseif( CMAKE_GENERATOR MATCHES "Visual Studio 15 2017 Win64" )
    add_compile_options( "/W4" )
endif()

file( GLOB SOURCE "source/*.cpp" )
add_executable( "blockchain" ${SOURCE} )
