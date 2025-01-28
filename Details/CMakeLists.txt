project(Details LANGUAGES CXX)
add_library(details SHARED
    filter_details.h filter_details.cpp
    fluid_details.h fluid_details.cpp)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets )
target_link_libraries(details PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)  # Link Qt's Widgets and SQL modules





