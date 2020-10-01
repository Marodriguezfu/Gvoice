cmake_minimum_required(VERSION 3.10)
project(Prueba2)

set(EXECUTABLE Prueba2)
set(MSYS_PATH C:/msys64)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)

IF(WIN32)
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

    set(SRC_OPENFRAMEWORK_ADDON_GUI
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxBaseGui.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxButton.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxColorPicker.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxGuiGroup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxInputField.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxPanel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxSlider.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxSliderGroup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/windows/openFramework/addons/ofxGui/src/ofxToggle.cpp
            )

    add_executable(${EXECUTABLE} main.cpp ofApp.cpp ${SRC_OPENFRAMEWORK_ADDON_GUI})

    target_compile_options(${EXECUTABLE} PRIVATE "-mwindows")

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
ELSEIF(APPLE)
    add_compile_definitions(__MACOSX_CORE__)

    add_compile_options("-Os")
    add_compile_options("-fexceptions")
    add_compile_options("-fpascal-strings")
    add_compile_options("-mmacosx-version-min=10.9")
    add_compile_options("-x")
    add_compile_options("objective-c++")
    add_compile_options("-mtune=native")
    add_compile_options("-MMD")
    add_compile_options("-MP")

    set(SRC_OPENFRAMEWORK_ADDON_GUI
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxBaseGui.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxButton.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxColorPicker.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxGuiGroup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxInputField.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxPanel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxSlider.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxSliderGroup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src/ofxToggle.cpp
            )

    add_executable(${EXECUTABLE} main.cpp ofApp.cpp ${SRC_OPENFRAMEWORK_ADDON_GUI})

    target_link_directories(${EXECUTABLE} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworksCompiled/lib/osx
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/fmodex/lib/osx
            )

    target_include_directories(${EXECUTABLE} PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/FreeImage/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/boost/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/boost/include/boost
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/cairo/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/cairo/include/cairo
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/curl/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/curl/include/curl
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/fmodex/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/include/freetype2
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/include/freetype2/freetype
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/include/freetype2/freetype/config
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/include/freetype2/freetype/internal
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/include/freetype2/freetype/internal/services
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glew/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glew/include/GL
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glfw/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glfw/include/GLFW
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include/glm
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include/glm/ext
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include/glm/simd
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include/glm/detail
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include/glm/gtc
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glm/include/glm/gtx
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/json/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/pugixml/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/rtAudio/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/tess2/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/uriparser/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/uriparser/include/uriparser
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/utf8/include
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/utf8/include/utf8
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/3d
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/video
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/types
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/app
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/utils
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/math
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/gl
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/communication
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/events
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/graphics
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/openFrameworks/sound

            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/addons/ofxGui/src
            )

    target_link_libraries(${EXECUTABLE} PRIVATE
            libopenFrameworks.a
            "-framework Accelerate"
            "-framework QTKit"
            "-framework AGL"
            "-framework ApplicationServices"
            "-framework AudioToolbox"
            "-framework CoreAudio"
            "-framework CoreFoundation"
            "-framework CoreServices"
            "-framework OpenGL"
            "-framework IOKit"
            "-framework Cocoa"
            "-framework CoreVideo"
            "-framework AVFoundation"
            "-framework CoreMedia"
            "-framework QuartzCore"
            "-framework Security"
            "-framework LDAP"
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/FreeImage/lib/osx/freeimage.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/FreeImage/lib/osx/freeimage.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/boost/lib/osx/boost_system.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/boost/lib/osx/boost_filesystem.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/cairo/lib/osx/cairo-script-interpreter.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/cairo/lib/osx/cairo.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/cairo/lib/osx/png.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/cairo/lib/osx/pixman-1.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/curl/lib/osx/curl.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/freetype/lib/osx/freetype.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glew/lib/osx/glew.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/glfw/lib/osx/glfw3.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/pugixml/lib/osx/pugixml.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/rtAudio/lib/osx/rtaudio.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/tess2/lib/osx/tess2.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/uriparser/lib/osx/uriparser.a
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/macos/openFramework/libs/fmodex/lib/osx/libfmodex.dylib
            -lobjc
            )

    SET_TARGET_PROPERTIES(${EXECUTABLE} PROPERTIES MACOSX_BUNDLE TRUE)

    add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${PROJECT_SOURCE_DIR}/lib/macos/openFramework/libs/fmodex/lib/osx/libfmodex.dylib"
            $<TARGET_FILE_DIR:${EXECUTABLE}>)
ELSE()
    add_compile_definitions(GCC_HAS_REGEX)
    add_compile_definitions(OF_USING_GTK)
    add_compile_definitions(_REENTRANT)

    add_compile_options("-O3")
    add_compile_options("-mtune=native")
    add_compile_options("-MMD")
    add_compile_options("-MP")

    set(SRC_OPENFRAMEWORK_ADDON_GUI
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxBaseGui.cpp
	    ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxButton.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxColorPicker.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxGuiGroup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxInputField.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxLabel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxPanel.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxSlider.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxSliderGroup.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src/ofxToggle.cpp
            )

    add_executable(${EXECUTABLE} main.cpp ofApp.cpp ${SRC_OPENFRAMEWORK_ADDON_GUI})

    target_link_directories(${EXECUTABLE} PRIVATE
            	${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/fmodex/lib/linux64
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworksCompiled/lib/linux64
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/kiss/lib/linux64
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/tess2/lib/linux64
            )

    target_include_directories(${EXECUTABLE} PRIVATE
		/usr/include/gstreamer-1.0 
		/usr/include/orc-0.4 
		/usr/include/gstreamer-1.0 
		/usr/include/AL 
		/usr/include/x86_64-linux-gnu 
		/usr/include/rtaudio 
		/usr/include/alsa 
		/usr/include/gtk-3.0 
		/usr/include/at-spi2-atk/2.0 
		/usr/include/at-spi-2.0 
		/usr/include/dbus-1.0 
		/usr/lib/x86_64-linux-gnu/dbus-1.0/include 
		/usr/include/gtk-3.0 
		/usr/include/gio-unix-2.0 
		/usr/include/cairo 
		/usr/include/libdrm 
		/usr/include/pango-1.0 
		/usr/include/harfbuzz 
		/usr/include/pango-1.0 
		/usr/include/fribidi 
		/usr/include/atk-1.0 
		/usr/include/cairo 
		/usr/include/pixman-1 
		/usr/include/freetype2 
		/usr/include/libpng16 
		/usr/include/gdk-pixbuf-2.0 
		/usr/include/libmount 
		/usr/include/blkid 
		/usr/include/uuid 
		/usr/include/glib-2.0 
		/usr/lib/x86_64-linux-gnu/glib-2.0/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/fmodex/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include/glm 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include/glm/gtx
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include/glm/simd 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include/glm/detail 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include/glm/gtc 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/glm/include/glm/ext 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/json/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/kiss/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/pugixml/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/tess2/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/utf8/include 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/utf8/include/utf8 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/utils 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/gl 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/math 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/sound 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/types 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/events 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/graphics 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/3d 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/app 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/video 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/libs/openFrameworks/communication 
		${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/openFramework/addons/ofxGui/src
            )

    target_link_libraries(${EXECUTABLE} PRIVATE
	libopenFrameworks.a   
	-lfmodex 
	libkiss.a 
	libtess2.a   
	-lz 
	-lgstapp-1.0 
	-lgstvideo-1.0 
	-lgstbase-1.0 
	-lgstreamer-1.0 
	-ludev 
	-lfontconfig 
	-lfreetype 
	-lsndfile 
	-lopenal 
	-lcurl 
	-lglfw 
	-lrtaudio 
	-lpulse-simple 
	-lpulse 
	-lasound 
	-lGLEW 
	-lGLU 
	-lGL 
	-lgtk-3 
	-lgdk-3 
	-lpangocairo-1.0 
	-lpango-1.0 
	-latk-1.0 
	-lcairo-gobject 
	-lcairo 
	-lgdk_pixbuf-2.0 
	-lgio-2.0 
	-lgobject-2.0 
	-lglib-2.0 
	-lglut 
	-lX11 
	-lXrandr 
	-lXxf86vm 
	-lXi 
	-lXcursor 
	-ldl 
	-lpthread 
	-lfreeimage 
	-lboost_filesystem 
	-lboost_system 
	-lpugixml 
	-luriparser 
	-lXinerama
            )

ENDIF()

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/data"
        $<TARGET_FILE_DIR:${EXECUTABLE}>/data)
