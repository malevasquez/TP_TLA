Para este proyecto se utilizó como base el siguiente template: https://github.com/agustin-golmar/Flex-Bison-Compiler

# Trabajo Práctico Especial - Music++

## Autores
* Cupitó, Felipe
* Finucci Roca, Hernán
* Kim, Azul Candelaria
* Vásquez Currie, Malena

## Requerimientos

Para construir el compilador, se requieren las siguientes dependencias:

* [Bison v3.8.2](https://www.gnu.org/software/bison/)
* [CMake v3.22.2](https://cmake.org/)
* [Flex v2.6.4](https://github.com/westes/flex)
* [GCC v11.1.0](https://gcc.gnu.org/)
* [Make v4.3](https://www.gnu.org/software/make/)

Si en lugar de trabajar con un entorno _Linux_, se está construyendo el proyecto sobre un entorno _Microsoft Windows_, se debe instalar _Microsoft Visual Studio 2022_ con las extensiones para desarrollar aplicaciones en _C/C++_, así como también las herramientas requeridas, con excepción del compilador _GCC_ y la herramienta _Make_.

## Construcción

Para construir el proyecto por completo, ejecute en la raíz del repositorio el siguiente comando:

```bash
user@machine:path/ $ chmod 777 ./run.sh
user@machine:path/ $ ./run.sh
```

Si es que su versión de CMake es una anterior a la establecida en los requerimientos, modificar el archivo CMakeLists.txt.

##  Ejecucion

Para compilar un programa, primero cree un archivo vacío denominado `program` con una gramatica valida.


Luego, ejecute el compilador desde el directorio raíz del proyecto, inyectando el programa desde la entrada estándard:

```bash
user@machine:path/ $ cat Programs/program<number> | bin/Compiler
```

## Casos de uso
En la carpeta [`Programs`](./Programs), se encuentran los casos de uso pedidos por la cátedra.

