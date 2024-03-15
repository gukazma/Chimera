set(TARGET_NAME "ImageListing")

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE HPP_FILES "*.hpp")
file(GLOB_RECURSE CPP_FILES "*.cpp")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${HPP_FILES} ${CPP_FILES})

add_executable(${TARGET_NAME} ${HEADER_FILES} ${CPP_FILES} ${HEADER_FILES} ${HPP_FILES})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

# Link dependencies    
target_link_libraries(${TARGET_NAME} 
    PUBLIC
Boost::system
Boost::filesystem
Boost::dynamic_linking
Boost::thread
OpenMVG::openMVG_geometry
OpenMVG::openMVG_linearProgramming
OpenMVG::openMVG_multiview
OpenMVG::openMVG_numeric
OpenMVG::openMVG_features
OpenMVG::openMVG_image
OpenMVG::openMVG_matching
OpenMVG::openMVG_system
OpenMVG::openMVG_sfm
OpenMVG::openMVG_exif
vlsift
spdlog::spdlog
          )

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
)

set_target_properties(${TARGET_NAME}
    PROPERTIES
        FOLDER Apps/SFM
)