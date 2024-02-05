set(TARGET_NAME VisualizeSfmData)

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE HPP_FILES "*.hpp")
file(GLOB_RECURSE CPP_FILES "*.cpp")


source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${CPP_HEAD_FILES} ${CPP_SOUCE_FILES})

add_executable(${TARGET_NAME} ${HEADER_FILES} ${HPP_FILES} ${CPP_FILES})
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Apps)
target_link_libraries(${TARGET_NAME} PRIVATE
OpenMVG::openMVG_geometry
OpenMVG::openMVG_linearProgramming
OpenMVG::openMVG_multiview
OpenMVG::openMVG_numeric
OpenMVG::openMVG_features
OpenMVG::openMVG_image
OpenMVG::openMVG_matching
OpenMVG::openMVG_sfm
OpenMVG::openMVG_stlplus
OpenMVG::OpenMVG
rerun_sdk
vlsift
)
target_include_directories(
${TARGET_NAME}
PUBLIC
${CMAKE_SOURCE_DIR}/Modules
)
