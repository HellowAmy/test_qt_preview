
project(hellowd)

# C++ 11 版本
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# 添加 -fPIC 编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")


# == Qt 配置 ==
# Qt 模块
set(PRO_QT_PACK
    Core
    Gui
    Widgets
)

# Qt 模块
set(PRO_QT_MODULE 
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# Qt 开启自动编译
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Qt 模块查找
find_package(Qt5 COMPONENTS ${PRO_QT_PACK} REQUIRED)

# Qt 库路径
set(CMAKE_PREFIX_PATH $ENV{Qt5_DIR})
# == Qt 配置 ==



set(PRE_NAME_1 test_lib_login)
set(PRE_NAME_2 test_lib_main)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)

set(PRE_SRC1 src/wid_login/wid_login.cpp)
set(PRE_SRC2 src/wid_main/wid_main.cpp)

add_library(${PRE_NAME_1} SHARED ${PRE_SRC1})
add_library(${PRE_NAME_2} SHARED ${PRE_SRC2})



# 链接库
target_link_libraries(${PRE_NAME_1} ${PRO_QT_MODULE})
target_link_libraries(${PRE_NAME_2} ${PRO_QT_MODULE})

