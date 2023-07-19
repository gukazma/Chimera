if (NOT PRECOMPILED_HEADERS_ENABLED)
    return()
endif()

set(TARGET_NAME ${PROJECT_NAME}CommonPrecompiledHeaders)
if (WIN32)
    list(APPEND PRECOMPILED_HEADERS
        <windows.h>
        <wrl.h>
    )
endif()

list(APPEND PRECOMPILED_HEADERS
    # containers
    <iterator>
    <set>
    <unordered_set>
    <map>
    <unordered_map>
    <list>
    <vector>
)

add_library(${TARGET_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Chimera/PrecompiledHeaders.cpp
)
add_library(${PROJECT_NAME}::CommonPrecompiledHeaders ALIAS ${TARGET_NAME})

target_link_libraries(${TARGET_NAME}
    PUBLIC
        ${PRECOMPILED_LIBS}
)
target_include_directories(${TARGET_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Inlcude]
)
# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")
target_precompile_headers(${TARGET_NAME}
    PUBLIC
        ${PRECOMPILED_HEADERS}
)

set_target_properties(${TARGET_NAME}
    PROPERTIES
        FOLDER Modules/Common
)