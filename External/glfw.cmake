CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.3.8
    VERSION 3.3.8
    OPTIONS
        "BUILD_SHARED_LIBS OFF"
        "GLFW_BUILD_EXAMPLES OFF"
        "GLFW_BUILD_TESTS OFF"
        "GLFW_BUILD_DOCS OFF"
        "GLFW_INSTALL OFF"
)
set_target_properties(glfw PROPERTIES FOLDER External/glfw)
set_target_properties(update_mappings PROPERTIES FOLDER External/glfw)