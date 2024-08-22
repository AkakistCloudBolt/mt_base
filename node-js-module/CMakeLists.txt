

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
set(obj ${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/obj)
set(NODE_A
${obj}.target/deps/histogram/libhistogram.a 
${obj}.target/deps/uvwasi/libuvwasi.a 
${obj}.target/libnode.a 
${obj}.target/libnode_text_start.a 
${obj}.target/tools/v8_gypfiles/libv8_snapshot.a 
${obj}.target/tools/v8_gypfiles/libv8_libplatform.a 
${obj}.target/tools/icu/libicui18n.a 
${obj}.target/deps/zlib/libzlib.a 
${obj}.target/deps/llhttp/libllhttp.a 
${obj}.target/deps/cares/libcares.a 
${obj}.target/deps/uv/libuv.a 
${obj}.target/deps/nghttp2/libnghttp2.a 
${obj}.target/deps/brotli/libbrotli.a 
${obj}.target/deps/openssl/libopenssl.a 
${obj}.target/deps/ngtcp2/libngtcp2.a 
${obj}.target/deps/ngtcp2/libnghttp3.a 
${obj}.target/deps/base64/libbase64.a 
${obj}.target/deps/base64/libbase64_ssse3.a 
${obj}.target/deps/base64/libbase64_sse41.a 
${obj}.target/deps/base64/libbase64_sse42.a 
${obj}.target/deps/base64/libbase64_avx.a 
${obj}.target/deps/base64/libbase64_avx2.a 
${obj}.target/deps/base64/libbase64_avx512.a 
${obj}.target/deps/simdutf/libsimdutf.a 
${obj}.target/deps/ada/libada.a 
${obj}.target/tools/icu/libicuucx.a 
${obj}.target/tools/icu/libicudata.a 
${obj}.target/tools/v8_gypfiles/libv8_base_without_compiler.a 
${obj}.target/tools/v8_gypfiles/libv8_libbase.a 
${obj}.target/tools/v8_gypfiles/libv8_zlib.a 
${obj}.target/tools/v8_gypfiles/libv8_compiler.a 
${obj}.target/tools/v8_gypfiles/libv8_turboshaft.a 
${obj}.target/tools/v8_gypfiles/libv8_initializers.a 
${obj}.target/deps/zlib/libzlib_inflate_chunk_simd.a 
${obj}.target/deps/zlib/libzlib_adler32_simd.a
${obj}.target/tools/v8_gypfiles/libv8_compiler.a 



${obj}.target/deps/histogram/libhistogram.a 
${obj}.target/deps/uvwasi/libuvwasi.a 
${obj}.target/libnode.a 
${obj}.target/libnode_text_start.a 
${obj}.target/tools/v8_gypfiles/libv8_snapshot.a 
${obj}.target/tools/v8_gypfiles/libv8_libplatform.a 
${obj}.target/tools/icu/libicui18n.a 
${obj}.target/deps/zlib/libzlib.a 
${obj}.target/deps/llhttp/libllhttp.a 
${obj}.target/deps/cares/libcares.a 
${obj}.target/deps/uv/libuv.a 
${obj}.target/deps/nghttp2/libnghttp2.a 
${obj}.target/deps/brotli/libbrotli.a 
${obj}.target/deps/openssl/libopenssl.a 
${obj}.target/deps/ngtcp2/libngtcp2.a 
${obj}.target/deps/ngtcp2/libnghttp3.a 
${obj}.target/deps/base64/libbase64.a 
${obj}.target/deps/base64/libbase64_ssse3.a 
${obj}.target/deps/base64/libbase64_sse41.a 
${obj}.target/deps/base64/libbase64_sse42.a 
${obj}.target/deps/base64/libbase64_avx.a 
${obj}.target/deps/base64/libbase64_avx2.a 
${obj}.target/deps/base64/libbase64_avx512.a 
${obj}.target/deps/simdutf/libsimdutf.a 
${obj}.target/deps/ada/libada.a 
${obj}.target/tools/icu/libicuucx.a 
${obj}.target/tools/icu/libicudata.a 
${obj}.target/tools/v8_gypfiles/libv8_base_without_compiler.a 
${obj}.target/tools/v8_gypfiles/libv8_libbase.a 
${obj}.target/tools/v8_gypfiles/libv8_zlib.a 
${obj}.target/tools/v8_gypfiles/libv8_compiler.a 
${obj}.target/tools/v8_gypfiles/libv8_turboshaft.a 
${obj}.target/tools/v8_gypfiles/libv8_initializers.a 
${obj}.target/deps/zlib/libzlib_inflate_chunk_simd.a 
${obj}.target/deps/zlib/libzlib_adler32_simd.a
${obj}.target/tools/v8_gypfiles/libv8_compiler.a 


)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/)
target_link_libraries(embedtest 


${NODE_A}


#${obj}.target/tools/v8_gypfiles/libv8_base_without_compiler.a

#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libnode.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libada.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libbase64.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libbase64_neon64.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libbrotli.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libcares.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libgtest.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libgtest_main.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libhistogram.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libllhttp.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libnghttp2.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libnghttp3.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libngtcp2.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libopenssl.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libsimdutf.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libtorque_base.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libuv.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libuvwasi.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_base_without_compiler.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_compiler.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_init.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_initializers.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_libbase.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_libplatform.a

#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_snapshot.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_turboshaft.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libv8_zlib.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicudata.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicui18n.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicutools.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libicuucx.a

#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib_adler32_simd.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib_arm_crc32.a
#${CMAKE_CURRENT_SOURCE_DIR}/node-v20.16.0/out/Release/libzlib_inflate_chunk_simd.a

#uv
#z


    )