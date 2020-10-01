# Proyecto con Open Framework

## Compilación de biblioteca
### Windows
1. Descargar Open Framework
[Descargar Open Framework](https://openframeworks.cc/versions/v0.11.0/of_v0.11.0_msys264_release.zip)
2. Descomprimir carpeta
3. Abrir MSYS2 MinGW - 64 bits
4. Abrir la ubicación de OpenFramework e ir a la carpeta
``` bash
cd <OpenFrameword>/scripts/msys2
```
5. Ejecutar el comando de instalación de dependencias, cada vez que pida confirmación aceptar
``` bash 
./install_dependencies.sh
```
### MacOS

### Linux


## Configuración ambiente y compilación
### Linea de comandos
1. Crear carpeta donde construir y entrar a la carpeta
``` bash
mkdir build
cd build
```
2. Generar proyecto y especificar la ruta donde se encuentra el archivo `CMakeLists` 
``` bash
cmake ..
```
3. Si no se quiere el proyecto por defecto, puede consultar el proyectos disponibles con `cmake --help`, y para generar un proyecto diferente usar la bandera `-G`
``` bash
cmake .. -G "Unix Makefiles"
```
4. Construir proyecto con cmake, indicando la ruta donde se encuentra el proyecto generado
``` bash
cmake --build .
```
O construir usando el proyecto generado directamente. En caso de Makefile:
``` bash
make
```

### CLion

1. Abrir el CMakeLists.txt como proyecto
2. Configurar el ToolChain con MinGW
3. La compilación y depuración es nativa

### Visual Studio

1. En el archivo `CMakeSettings.json` se encuentra la configuración de MinGW
2. En `CMakeSettings.json` cambiar la variable `TOOLSET_VERSION` con la versión de gcc. Para conocer la versión de gcc usar
``` bash
g++ --version
```
3. Abrir el `CMakeLists.txt` como proyecto en Visual Studio
4. Ya se puede compilar normalmente, pero no se puede depurar
5. Seleccione el objetivo o elemento de inicio
6. Para configurar la depuración, haga clic en el menu `Debug > Debug and Launch Settings for ${activeDebugTarget}`
7. Copie y pegue el contenido del archivo `launch.vs.json` del proyecto en el archivo que genero Visual Studio. La variable `projectTarget` debe ser el mismo valor que genero Visual Studio, y en la variable `miDebuggerPath` configure la ruta donde se encuentra el depurador `gdb.exe`
8. Ya puede empezar a depurar desde Visual Studio

#### Nueva configuración de depuración
1. Para configurar la depuración, haga clic en el menu `Debug > Debug and Launch Settings for ${activeDebugTarget}`
2. En el explorar de soluciones, click en `Alternar vistas`, seleccionar `Vistas de destinos de CMake`
3. Abrir el proyecto correspondiente. Click derecho sobre el `ejecutable` y `Agregar configuración de depuración`
4. Volver a la vista del proyecto
5. Click derecho en el `CMakeLists.txt` y seleccionar `Agregar configuración de depuración`
6. Elegir `Start C/C++ for MinGW (gdb)`
7. Modificar la variable `projectTarget` y debe coincidir con la configuración que se genero en el paso 3
7. Modificar la variable `miDebuggerPath` y cocolar la ruta absoluta de `gdb.exe`
8. Cambiar el nombre de la configuración se se desea. Se debe actualizar automáticamente en visual para seleccionar la depuración.

   
Para más información visite: [Depuración cmake en Visual Studio](https://docs.microsoft.com/en-us/cpp/build/configure-cmake-debugging-sessions?view=vs-2019)