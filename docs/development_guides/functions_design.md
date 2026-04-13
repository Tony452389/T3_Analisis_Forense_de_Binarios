# Functions Design — team_sample.exe

Proyecto: T3_Analisis_Forense_de_Binarios

---

# 1. Objetivo

Definir la estructura lógica del binario antes de implementar el código en C++ usando Visual Studio.

Este documento describe:

* Las funciones del programa
* El propósito de cada función
* Entradas y salidas
* Lógica interna
* Pseudocódigo conceptual

Este archivo servirá como base directa para el desarrollo del código del binario.

---

# 2. Arquitectura General

El programa estará dividido en funciones independientes para facilitar:

* Ingeniería inversa
* Debugging
* Patching
* Análisis estático y dinámico

Estructura principal:

main()

├── printSuspiciousStrings()
├── checkDebugger()
├── requestPassword()
├── validatePassword()
├── launchCalculator()
├── performDelay()
├── decodeHiddenString()
├── createDummyFile()
├── showFinalMessage()

---

# 3. Diseño de Funciones

---

# 3.1 main()

## Propósito

Controlar el flujo general de ejecución del programa.

## Entradas

Ninguna

## Salidas

Código de salida del programa.

## Pseudocódigo

Inicio del programa

Llamar printSuspiciousStrings()

Si checkDebugger() == TRUE
 Mostrar "Debugger detected"
 Terminar programa

password = requestPassword()

Si validatePassword(password) == FALSE
 Mostrar "Access Denied"
 Terminar programa

Llamar launchCalculator()

Llamar performDelay()

Llamar decodeHiddenString()

Llamar createDummyFile()

Llamar showFinalMessage()

Fin del programa

---

# 3.2 printSuspiciousStrings()

## Propósito

Mostrar cadenas sospechosas que puedan ser detectadas durante análisis estático o mediante reglas YARA.

## Entradas

Ninguna

## Salidas

Salida por consola.

## Strings sugeridas

"MAGIC: edu-malware-sim"
"Connecting to remote host..."
"Initializing system scan..."
"Loading encrypted payload..."

## Pseudocódigo

Mostrar string 1
Mostrar string 2
Mostrar string 3
Mostrar string 4

---

# 3.3 checkDebugger()

## Propósito

Detectar si el programa está siendo ejecutado bajo un debugger.

## Entradas

Ninguna

## Salidas

TRUE → Debugger detectado
FALSE → No detectado

## API de Windows utilizada

IsDebuggerPresent()

## Pseudocódigo

Si IsDebuggerPresent() == TRUE
 Retornar TRUE

Retornar FALSE

---

# 3.4 requestPassword()

## Propósito

Solicitar al usuario que ingrese una contraseña.

## Entradas

Ninguna

## Salidas

Cadena ingresada por el usuario.

## Pseudocódigo

Mostrar:

"Enter password:"

Leer entrada del usuario

Retornar entrada

---

# 3.5 validatePassword(password)

## Propósito

Comparar la contraseña ingresada con una contraseña interna.

## Entradas

password (string)

## Salidas

TRUE → Contraseña correcta
FALSE → Contraseña incorrecta

## Contraseña interna sugerida

"forensic123"

## Pseudocódigo

Si password == contraseña_interna
 Retornar TRUE

Retornar FALSE

---

# 3.6 launchCalculator()

## Propósito

Abrir la calculadora de Windows para simular la ejecución de un proceso externo.

## API de Windows utilizada

WinExec()

## Comportamiento

Ejecutar:

WinExec("calc.exe", SW_SHOW)

## Pseudocódigo

Ejecutar calculadora usando WinExec

---

# 3.7 performDelay()

## Propósito

Introducir una pausa que pueda ser observada durante debugging.

## API de Windows utilizada

Sleep()

## Tiempo sugerido

1500 milisegundos

## Pseudocódigo

Sleep(1500)

---

# 3.8 decodeHiddenString()

## Propósito

Decodificar una cadena almacenada en forma codificada dentro del binario.

## Entradas

Arreglo de bytes codificados.

## Salidas

Cadena decodificada mostrada en pantalla.

## Ejemplo de datos codificados

72 65 76 65 72 73 65

## Resultado decodificado

"reverse"

## Pseudocódigo

Recorrer arreglo codificado

Aplicar método de decodificación

Guardar resultado

Mostrar cadena decodificada

---

# 3.9 createDummyFile()

## Propósito

Crear un archivo temporal para generar evidencia observable en el sistema.

## APIs de Windows utilizadas

CreateFileA()
WriteFile()
CloseHandle()

## Ubicación del archivo

El archivo será creado dentro del directorio temporal del sistema.

Ruta dinámica:

%TEMP%\dummy.txt

Ejemplo de ruta real:

C:\Users\vboxuser\AppData\Local\Temp\dummy.txt

## Contenido del archivo

"Execution log created"
"System scan complete"

## Pseudocódigo

Obtener ruta del directorio TEMP

Agregar nombre:

"dummy.txt"

Crear archivo

Escribir contenido

Cerrar archivo

---

# 3.10 showFinalMessage()

## Propósito

Mostrar un mensaje final indicando que la ejecución fue completada correctamente.

## API de Windows utilizada

MessageBoxA()

## Mensaje sugerido

"Execution Complete"

## Pseudocódigo

Mostrar ventana MessageBox con el mensaje:

"Execution Complete"

---

# 4. Funciones Diseñadas para Análisis

Las siguientes funciones serán críticas para el análisis forense:

* checkDebugger()
* validatePassword()
* decodeHiddenString()
* createDummyFile()

Estas funciones deben mantenerse separadas para facilitar la ingeniería inversa.

---

# 5. Funciones Diseñadas para Patching

Las siguientes funciones están diseñadas como objetivos ideales para patching:

validatePassword()
checkDebugger()

Ejemplos posibles:

Cambiar:

JE → JNE

Forzar:

Return TRUE

---

# 6. Variables Globales Sugeridas

Estas variables facilitarán la inspección en memoria.

internal_password = "forensic123"

encoded_string = {72,65,76,65,72,73,65}

---

# 7. Orden Real de Ejecución

1 → printSuspiciousStrings()

2 → checkDebugger()

Si debugger detectado:

Mostrar mensaje
Terminar ejecución

3 → requestPassword()

4 → validatePassword()

Si contraseña incorrecta:

Mostrar "Access Denied"
Terminar ejecución

5 → launchCalculator()

6 → performDelay()

7 → decodeHiddenString()

8 → createDummyFile()

9 → showFinalMessage()

---

# 8. Nivel de Complejidad

Complejidad objetivo:

Media a Media-Alta

El binario debe permitir:

* Análisis estático
* Debugging dinámico
* Patching
* Creación de reglas YARA
* Identificación de capacidades con CAPA

Sin volverse:

* Demasiado simple
* Excesivamente complejo

---

# 9. Versión Inicial del Binario

Nombre del ejecutable:

team_sample.exe

Incluirá inicialmente:

printSuspiciousStrings()
launchCalculator()
performDelay()
createDummyFile()

---

# 10. Versión Avanzada del Binario

Versiones posteriores podrán incluir:

checkDebugger()
validatePassword()
decodeHiddenString()

Extensiones opcionales:

Creación de mutex
Escritura en registro
Simulación de red

---

# 11. Notas de Desarrollo

Lenguaje:

C++

Compilador:

Visual Studio

Plataforma:

Windows 10 x64

Tipo de aplicación:

Console Application

---

# 12. Notas de Implementación

Este documento define la lógica funcional del binario antes de comenzar la implementación en código.

Cualquier modificación funcional deberá actualizarse también en:

docs/binary/binary_plan.md
