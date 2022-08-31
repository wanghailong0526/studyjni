# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("studyjni")
set(CMAKE_BUILD_TYPE Debug)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libugbraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
# 1.第一个参数 生成的库名字
# 2.第二个参数 shared_动态库 a_静态库
# 3.第三个参数 源文件
#
# 编译一个目录中所有源文件
# 查找所有源码 并拼接到路径列表
# aux_source_directory(${CMAKE_HOME_DIRECTORY}/src/api SRC_LIST)
# aux_source_directory(${CMAKE_HOME_DIRECTORY}/src/core CORE_SRC_LIST)
# list(APPEND SRC_LIST ${CORE_SRC_LIST})
# add_library(native-lib SHARED ${SRC_LIST})

add_library( # Sets the name of the library.
        # 生成的so库名称，此处生成的so文件名称是libnative-lib.so
        studyjni

        # Sets the library as a shared library.
        # STATIC：静态库，是目标文件的归档文件，在链接其它目标的时候使用
        # SHARED：动态库，会被动态链接，在运行时被加载
        # MODULE：模块库，是不会被链接到其它目标中的插件，但是可能会在运行时使用dlopen-系列的函数动态链接
        SHARED

        # Provides a relative path to your source file(s).
        # 资源文件，可以多个，
        # 资源路径是相对路径，相对于本CMakeLists.txt所在目录
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#从系统查找依赖库
find_library( # Sets the name of the path variable.
        # android系统每个类型的库会存放一个特定的位置，而log库存放在log-lib中
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        # android系统在c环境下打log到logcat的库
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#第一个参数 是我们在add_library()生成的库
#第二个参数 是
#配置库的链接（依赖关系）
target_link_libraries( # Specifies the target library.
        # 目标库
        studyjni

        # Links the target library to the log library
        # included in the NDK.
        # 依赖于
        ${log-lib})