# src/CMakeLists.txt

include_directories(include)

add_definitions( -DINSTALL_DIRECTORY=\"${CMAKE_SOURCE_DIR}\" )

add_executable(recepy-exe
    main.cpp
    mainwindow.cpp
    include/mainwindow.h
    include/recepy.h
    recepy.cpp
    include/cookingmenubar.hpp
    cookingmenubar.cpp
    cookbooklocationdialog.cpp
    include/cookbooklocationdialog.hpp
    qcookbook.cpp
    include/qcookbook.hpp
    mainwindow.ui
)

target_link_libraries(recepy-exe PRIVATE Qt5::Widgets)

