set(TARGET_NAME "${PROJECT_NAME}Vulkan")

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE HPP_FILES "*.hpp")
file(GLOB_RECURSE CPP_FILES "*.cpp")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${HPP_FILES} ${CPP_FILES})

add_library(${TARGET_NAME} STATIC ${HEADER_FILES} ${CPP_FILES} ${HEADER_FILES} ${HPP_FILES})
add_library(${PROJECT_NAME}::Vulkan ALIAS ${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Modules/Graphics)

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

# Link dependencies    
target_link_libraries(${TARGET_NAME} 
    PUBLIC
    glfw
    Vulkan::Vulkan
          )

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
)

if(PRECOMPILED_HEADERS_ENABLED)
    target_precompile_headers(${TARGET_NAME} REUSE_FROM ${PROJECT_NAME}CommonPrecompiledHeaders)
    target_link_libraries(${TARGET_NAME} 
        PUBLIC
            ${PROJECT_NAME}CommonPrecompiledHeaders
          )
endif()