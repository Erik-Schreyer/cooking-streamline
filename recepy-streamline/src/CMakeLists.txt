# src/CMakeLists.txt

#lib/cmake/Qt5Widgets;/usr/local/Qt/5.14.2/gcc_64/lib/cmake/Qt5Multimedia
#set(CMAKE_PREFIX_PATH "/usr/local/Qt/5.14.2/gcc_64/lib/cmake/Qt5Multimedia")

find_package(Qt5Multimedia REQUIRED)

include_directories(include)

add_definitions( -DINSTALL_DIRECTORY=\"${CMAKE_SOURCE_DIR}\" )

add_executable(recepy-exe
    include/mainwindow.h
    include/recepy.h
    include/cookingmenubar.hpp
    include/qcookbook.hpp
    include/cookbooklocationdialog.hpp
    include/qrecepy.hpp
    include/qtimerstack.hpp
    include/qcookingtimer.hpp
    include/newrecepydialog.hpp
    main.cpp
    mainwindow.cpp
    recepy.cpp
    cookingmenubar.cpp
    cookbooklocationdialog.cpp
    qcookbook.cpp
    qrecepy.cpp
    qtimerstack.cpp
    qcookingtimer.cpp
    newrecepydialog.cpp
    mainwindow.ui
)

target_link_libraries(recepy-exe PRIVATE Qt5::Widgets)
target_link_libraries(recepy-exe PRIVATE Qt5::Multimedia)

