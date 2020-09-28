cmake_minimum_required(VERSION 3.10)
project(Prueba2)

set(EXECUTABLE Prueba2)
set(MSYS_PATH C:/msys64)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(_UNICODE)
add_compile_definitions(UNICODE)
add_compile_definitions(OF_SOUND_PLAYER_OPENAL)
add_compile_definitions(OF_USING_MPG123)

add_compile_options("-Os")
add_compile_options("-MMD")
add_compile_options("-MP")
add_compile_options("-mms-bitfields")
add_compile_options("-fexceptions")
add_compile_options("-march=native")
add_compile_options("-mtune=native")

set(SRC_ADDONS
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxBaseGui.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxButton.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxColorPicker.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxGuiGroup.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxInputField.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxLabel.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxPanel.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxSlider.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxSliderGroup.cpp
        C:/Users/Fernando/Downloads/of_v0.11.0_msys264_release/addons/ofxGui/src/ofxToggle.cpp
        )

add_executable(${EXECUTABLE} main.cpp ofApp.cpp ${SRC_ADDONS})

target_compile_options(${EXECUTABLE} PRIVATE "-mwindows")

IF(WIN32)
    target_link_directories(${EXECUTABLE} PRIVATE
            ${MSYS_PATH}/mingw64/lib
            ${MSYS_PATH}/mingw64/bin
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworksCompiled/lib/msys2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/kiss/lib/msys2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/pugixml/lib/msys2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/rtAudio/lib/msys2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/tess2/lib/msys2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/uriparser/lib/msys2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/videoInput/lib/msys2
            )

    target_include_directories(${EXECUTABLE} PRIVATE
            ${MSYS_PATH}/mingw64/include/cairo
            ${MSYS_PATH}/mingw64/include
            ${MSYS_PATH}/mingw64/include/pixman-1
            ${MSYS_PATH}/mingw64/include/freetype2
            ${MSYS_PATH}/mingw64/include/harfbuzz
            ${MSYS_PATH}/mingw64/include/glib-2.0
            ${MSYS_PATH}/mingw64/lib/glib-2.0/include
            ${MSYS_PATH}/mingw64/include/libpng16
            ${MSYS_PATH}/mingw64/include/AL
            ${MSYS_PATH}/mingw64/include/opus

            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include/glm
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include/glm/detail
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include/glm/ext
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include/glm/gtc
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include/glm/gtx
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/glm/include/glm/simd
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/json/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/kiss/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/pugixml/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/rtAudio/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/tess2/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/uriparser/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/uriparser/include/uriparser
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/utf8/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/utf8/include/utf8
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/videoInput/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/3d
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/app
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/communication
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/events
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/gl
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/graphics
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/math
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/sound
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/types
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/utils
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/libs/openFrameworks/video
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src
            )
ELSE()

ENDIF()

target_link_libraries(${EXECUTABLE} PRIVATE
        libopenFrameworks.a
        libkiss.a
        pugixml.a
        librtaudio.a
        libtess2.a
        liburiparser.a
        libvideoinput.a
        cairo
        z
        ssl
        crypto
        glew32
        glfw3
        curl
        openal
        sndfile
        mpg123
        ksuser
        opengl32
        gdi32
        msimg32
        glu32
        dsound
        winmm
        strmiids
        uuid
        ole32
        oleaut32
        setupapi
        wsock32
        ws2_32
        Iphlpapi
        Comdlg32
        freeimage
        boost_filesystem-mt
        boost_system-mt
        freetype
        cairo
        pthread
        )