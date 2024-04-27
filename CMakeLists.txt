cmake_minimum_required(VERSION 3.5)

project(GuideMe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Qml Quick REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS UiTools)


set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GuideMe
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        file_management.h
        file_management.cpp
        .gitignore CMakeLists.txt CMakeLists.txt.user
        build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/transportation_data.txt
        editingfunctionalities.cpp
        editingfunctionalities.h
        editorialOptions.h
        editorialOptions.cpp
        editorialOptions.ui
        CSS_styling/PushButton.css
        gui_management.h
        gui_management.cpp
        CSS_styling/background.css
        CSS_styling/titleLabel.css
        Assets/aubergine_road.jpg
        citiesSelection.h citiesSelection.cpp citiesSelection.ui
        CSS_styling/textfields.css
        CSS_styling/normalLabels.css
        CSS_styling/warningLabel.css
        transportationdisplay.h transportationdisplay.cpp transportationdisplay.ui
        CSS_styling/transportationWidgets.css
        traversal.h traversal.cpp
        welcome.h welcome.cpp welcome.ui
        CSS_styling/welcometitle.css
        dataentry.h dataentry.cpp dataentry.ui


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GuideMe APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GuideMe SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(GuideMe
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(GuideMe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    Qt6::Qml
    Qt6::Quick
Qt6::Widgets Qt6::UiTools)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GuideMe)
endif()
set_target_properties(GuideMe PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GuideMe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GuideMe)
endif()
