# src/CMakeLists.txt

include_directories(include)

add_definitions( -DINSTALL_DIRECTORY=\"${CMAKE_SOURCE_DIR}\" )

add_executable(recepy-exe
    include/mainwindow.h
    include/recepy.h
    include/cookingmenubar.hpp
    include/qcookbook.hpp
    include/cookbooklocationdialog.hpp
    include/qrecepy.hpp
    main.cpp
    mainwindow.cpp
    recepy.cpp
    cookingmenubar.cpp
    cookbooklocationdialog.cpp
    qcookbook.cpp
    qrecepy.cpp
    mainwindow.ui
)

target_link_libraries(recepy-exe PRIVATE Qt5::Widgets)

