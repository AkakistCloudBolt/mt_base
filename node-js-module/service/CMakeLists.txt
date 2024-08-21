cmake_minimum_required (VERSION 3.0)


add_library(core-nodejs SHARED
            nodejs.cpp
            nodejsService.cpp
	    nodejsService.h
           )

target_link_libraries(core-nodejs megatron-core pthread)

install(TARGETS core-nodejs DESTINATION ${PLUGIN_TARGET_DIR})


