cmake_minimum_required(VERSION 3.30)

project(The_Machine C CXX)

include(FetchContent)
FetchContent_Declare(
    Simpleton-Engine
    GIT_REPOSITORY "https://github.com/hghpublic/indianakernick-Simpleton-Engine.git"
    GIT_TAG dev/0
)
FetchContent_MakeAvailable(Simpleton-Engine)

set(target The_Machine)
add_executable(${target})

add_subdirectory("The Machine")

target_compile_features(${target} PRIVATE cxx_std_26)
target_link_libraries(${target} PRIVATE Simpleton-Engine)


find_package(EnTT CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE EnTT::EnTT)
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE SDL2::SDL2)
find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE SDL2_image::SDL2_image)
# find_package(SDL2_mixer CONFIG REQUIRED)
# target_link_libraries(${target} PRIVATE SDL2_mixer::SDL2_mixer)
# find_package(SDL2_ttf CONFIG REQUIRED)
# target_link_libraries(${target} PRIVATE SDL2_ttf::SDL2_ttf)
find_package(glm CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE glm::glm)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(${target} PRIVATE nlohmann_json::nlohmann_json)
find_package(OpenGL REQUIRED)
target_link_libraries(${target} PRIVATE OpenGL::GL)
find_package(GLEW REQUIRED)
target_link_libraries(${target} PRIVATE GLEW::GLEW)
find_package(Stb REQUIRED)
target_include_directories(${target} PRIVATE ${Stb_INCLUDE_DIR})

target_sources(${target} PRIVATE ${Stb_INCLUDE_DIR}/stb_vorbis.c)


# copy Resources

add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
        "${CMAKE_CURRENT_SOURCE_DIR}/The Machine/Resources"
        $<TARGET_FILE_DIR:${target}>/Resources)