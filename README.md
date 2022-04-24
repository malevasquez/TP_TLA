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

Deberia obtener el resultado correcto de evaluar el programa anterior: `122318`.

## Gramatica

Instrucciones obligatorias indicando el comienzo y fin del programa:
```
start
// Codigo
end
```
Cabe aclarar que cada fin de linea del cuerpo debe ser finalizada con el delimitador `;`.

Declaracion y Asignacion de variables:

Music++ acepta los siguientes tipos de datos:
* string
* integer
* chord
* note

Para declarar una variable:
* string [variable];
* integer [variable];
* chord [variable];
* note [variable];

Para asignar

* string [variable] is [valor];
* integer [variable] is [valor];
* chord [variable] is [valor];
* note [variable] is [valor];

o

* [variable] is [valor];

Instrucciones para imprimir en pantalla las distintas variables:
Para imprimir un string (texto) se utiliza simplemente la funcion print.
Si se quiere imprimir simultaneamente varios acordes, se usa la funcion print_to_chord, tomando como argumentos las notas que forman dichos acordes.

Instrucciones para reproducir el sonido de notas y acordes:
Para reproducir los sonidos de una nota o acorde, se utilizan las funciones reproduce_note y reproduce_chord, respectivamente.

Instruccion para realizar ciclos do-while y condicionales if-else.
Para realizar un ciclo, se utiliza la siguiente sintaxis:
compute
print "hola mundo";
while ( 2 greater_than 1);

Similarmente, para realizar una instruccion condicional se utiliza la siguiente sintaxis:
if ( 2 greater_than 1)
then
print "greater"
else
print "lower"
end_if

Instrucciones para realizar operaciones aritméticas
* integer variable1 is num1 sum num2;
* integer variable2 is num1 minux num2;
* integer variable3 is num1 times num2;
* integer variable4 is num1 by num2;
donde num1 y num2 pueden ser variables del tipo integer o números enteros.

Instrucciones para realizar operaciones lógicas
* var1 greater_than var2
* var1 lower_than var2
* var1 equals var2
* var1 not_equals var2
* var1 and var2
* var1 or var2
* not var1
tal que el resultado de esta operación debe ser verdadero o falso.