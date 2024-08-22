cmake_minimum_required (VERSION 3.0)


add_executable(nodejs-mtnode 
#            nodejs.cpp
            nodejsService.cpp
	    nodejsService.h
	    embed_nodejs.cc
	    node_main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/../node-v20.16.0/out/Release/obj/gen/node_snapshot.cc

           )
link_directories(/Users/sergejbelalov/mt_base/node-js-module/node-v20.16.0/out/Release )


set(obj ${CMAKE_CURRENT_SOURCE_DIR}/../node-v20.16.0/out/Release/obj)
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


target_link_libraries(nodejs-mtnode
${NODE_A}

megatron-main
megatron-core
zsingle

megatron-core pthread
)

install(TARGETS nodejs-mtnode DESTINATION ${PLUGIN_TARGET_DIR})


