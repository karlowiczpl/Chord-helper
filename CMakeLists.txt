cmake_minimum_required(VERSION 3.27)
project(akordy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(source
        source/Scales.cpp
        source/Scales.h
        source/helperFunction.cpp
        source/data/scaleData.h
)
set(widgets
        widgets/mainwindow.h
        widgets/mainwindow.cpp
        widgets/note.cpp
        widgets/note.h
        widgets/circularLayout.cpp
        widgets/circularLayout.h
        widgets/keyboard.cpp
        widgets/keyboard.h
        source/data/scaleData.cpp
        widgets/legend.cpp
        widgets/legend.h
)

add_executable(akordy main.cpp ${source}  ${widgets})

target_link_libraries(akordy
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

