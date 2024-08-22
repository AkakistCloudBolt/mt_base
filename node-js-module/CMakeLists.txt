

cmake_minimum_required (VERSION 3.16)

project (node)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_definitions(-DNODE_WANT_INTERNALS)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/tools
    /usr/local/include/node 
    ${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/src
    ${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/deps/v8/include/
)
ADD_SUBDIRECTORY(service)

add_executable(embedtest
    embedtest.cc
    node-v20.16.0/out/Release/obj/gen/node_snapshot.cc
)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/)
target_link_libraries(embedtest 
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libnode.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libada.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libbase64.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libbase64_neon64.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libbrotli.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libcares.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libgtest.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libgtest_main.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libhistogram.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libllhttp.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libnghttp2.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libnghttp3.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libngtcp2.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libopenssl.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libsimdutf.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libtorque_base.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libuv.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libuvwasi.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_base_without_compiler.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_compiler.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_init.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_initializers.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_libbase.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_libplatform.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_snapshot.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_turboshaft.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_zlib.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicudata.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicui18n.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicutools.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicuucx.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib_adler32_simd.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib_arm_crc32.a
${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib_inflate_chunk_simd.a

#    node-v20.16.0/out/Release/libuv.a
#    node-v20.16.0/out/Release/libv8_init.a
#    node-v20.16.0/out/Release/libnode.a
#    node-v20.16.0/out/Release/libllhttp.a
#    node-v20.16.0/out/Release/libicuucx.a
#    node-v20.16.0/out/Release/libuvwasi.a
#    node-v20.16.0/out/Release/libnghttp2.a
#    node-v20.16.0/out/Release/libzlib.a
#    node-v20.16.0/out/Release/libv8_zlib.a
#    node-v20.16.0/out/Release/libopenssl.a
    )