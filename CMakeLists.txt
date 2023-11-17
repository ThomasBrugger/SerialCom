cmake_minimum_required(VERSION 2.8.3)
project(serial)

include_directories("${CMAKE_SOURCE_DIR}/ThirdParty/serial)")

## Sources
set(serial_SRCS
    ThirdParty/serial/src/serial.cc
    ThirdParty/serial/include/serial/serial.h
    ThirdParty/serial/include/serial/v8stdint.h
)

if(APPLE)
    # If OSX
    list(APPEND serial_SRCS ThirdParty/serial/src/impl/unix.cc)
    list(APPEND serial_SRCS ThirdParty/serial/src/impl/list_ports/list_ports_osx.cc)
elseif(UNIX)
    # If unix
    list(APPEND serial_SRCS ThirdParty/serial/src/impl/unix.cc)
    list(APPEND serial_SRCS ThirdParty/serial/src/impl/list_ports/list_ports_linux.cc)
else()
    # If windows
    list(APPEND serial_SRCS ThirdParty/serial/src/impl/win.cc)
    list(APPEND serial_SRCS ThirdParty/serial/src/impl/list_ports/list_ports_win.cc)
endif()

## Add serial library
add_library(${PROJECT_NAME} ${serial_SRCS})

if(APPLE)
    target_link_libraries(${PROJECT_NAME} ${FOUNDATION_LIBRARY} ${IOKIT_LIBRARY})
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} rt pthread)
else()
    target_link_libraries(${PROJECT_NAME} setupapi)
endif()

# Include directories for the serial library
target_include_directories(${PROJECT_NAME} PUBLIC ThirdParty/serial/include)

## Uncomment for example
set(main_src
	main.cpp
    	controller.cpp
    	controller.h
	serialDriver.cpp
	serialDriver.h
	utilities.h
	view.h
	view.cpp
)

add_executable(SerialCOM ${main_src})
add_dependencies(SerialCOM ${PROJECT_NAME})
target_link_libraries(SerialCOM ${PROJECT_NAME})

## Include headers
include_directories(include)

## Install executable
install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION /build
    LIBRARY DESTINATION /build}
    RUNTIME DESTINATION /build}
)

## Install headers
install(FILES include/serial/serial.h include/serial/v8stdint.h
  DESTINATION /build)

