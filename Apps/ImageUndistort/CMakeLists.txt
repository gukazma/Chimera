set(TARGET_NAME ImageUndistort)

find_package(Qt5 COMPONENTS Core Widgets Gui OpenGL REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB_RECURSE HEADER_FILES "*.hh")
file(GLOB_RECURSE HPP_FILES "*.hpp")
file(GLOB_RECURSE CPP_FILES "*.cc")
file(GLOB_RECURSE UI_SOUCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

QT5_WRAP_CPP(MOC_SOURCES 
${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.hh
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${CPP_HEAD_FILES} ${CPP_SOUCE_FILES})

add_executable(${TARGET_NAME} ${HEADER_FILES} ${HPP_FILES} ${CPP_FILES} ${MOC_SOURCES})
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Apps)
target_link_libraries(${TARGET_NAME} PRIVATE
Qt5::Core
Qt5::Gui
Qt5::Widgets
Qt5::OpenGL
OpenMVG::openMVG_geometry
OpenMVG::openMVG_linearProgramming
OpenMVG::openMVG_multiview
OpenMVG::openMVG_numeric
OpenMVG::openMVG_features
OpenMVG::openMVG_image
OpenMVG::openMVG_matching
vlsift
OpenMP::OpenMP_CXX
)

if(MSVC)
message("Finding windeployqt")
find_program(DEPLOYQT_EXECUTABLE windeployqt)
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
  COMMAND ${DEPLOYQT_EXECUTABLE} ${CMAKE_BINARY_DIR}/bin/${TARGET_NAME}.exe
  COMMENT "Deploying qt dependencies after build..."
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

set_target_properties(${TARGET_NAME} PROPERTIES
LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
)
endif()