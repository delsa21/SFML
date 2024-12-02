cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(ACT15)

# Establecer la versión de C++
set(CMAKE_CXX_STANDARD 17)

# Incluir los directorios de encabezados
include_directories(include)

# Agregar los archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Añadir ejecutable
add_executable(main ${SOURCES})

# Buscar SFML y vincularlo
find_package(SFML 2.6.2 COMPONENTS system window graphics audio REQUIRED)
target_link_libraries(main sfml-system sfml-window sfml-graphics sfml-audio)

# Copiar la fuente al directorio de construcción
file(COPY ${CMAKE_SOURCE_DIR}/assets/fonts/arial.ttf DESTINATION ${CMAKE_BINARY_DIR}/assets/fonts)

include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1)
