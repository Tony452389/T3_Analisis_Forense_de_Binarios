# Binario Principal — Plan de Diseño

Proyecto: T3_Analisis_Forense_de_Binarios

---

# 1. Objetivo del Binario

El objetivo del binario principal es generar un ejecutable educativo con comportamiento "sospechoso" controlado, diseñado para ser utilizado en actividades de:

* Análisis estático
* Ingeniería inversa (Ghidra)
* Debugging (x64dbg)
* Patching (Radare2 / Cutter)
* Detección mediante YARA
* Identificación de capacidades mediante CAPA

El binario será desarrollado en **C++ usando Visual Studio**, compilado para **Windows 10 x64**, y diseñado intencionalmente para incluir múltiples comportamientos observables.

Este binario es **benigno y educativo**, y no realiza actividades maliciosas reales.

---

# 2. Filosofía de Diseño

El binario debe:

* Simular comportamiento típico de malware
* Ser completamente seguro y controlado
* Permitir análisis técnico detallado
* Ser modificable mediante patching
* Generar artefactos detectables

Debe contener:

* Múltiples funciones independientes
* Strings visibles y codificadas
* Uso de APIs Windows
* Branches condicionales
* Actividad observable en sistema

Se prioriza:

* Claridad estructural
* Observabilidad técnica
* Compatibilidad con herramientas forenses

---

# 3. Comportamientos Planeados

El binario incluirá múltiples módulos funcionales diseñados para análisis técnico.

---

# 3.1 Impresión de Strings Sospechosas

## Objetivo

Simular comportamiento típico observable en malware.

## Comportamiento

El binario mostrará múltiples mensajes sospechosos en consola.

## Strings sugeridas

"MAGIC: edu-malware-sim"
"Connecting to remote host..."
"Initializing system scan..."
"Loading encrypted payload..."

## Valor técnico

* Detectables mediante YARA
* Visibles en análisis estático
* Útiles para ingeniería inversa

---

# 3.2 Verificación de Debugger

## Objetivo

Detectar si el binario está siendo analizado en tiempo real.

## API utilizada

IsDebuggerPresent()

## Comportamiento

Si se detecta debugger:

Mostrar:

"Debugger detected"

Finalizar ejecución.

## Valor técnico

* Permite bypass mediante patching
* Genera flujo condicional interesante

---

# 3.3 Verificación de Contraseña

## Objetivo

Crear lógica condicional parcheable.

## Comportamiento

El programa solicitará contraseña al usuario.

Ejemplo:

Enter password:

Comparará con una contraseña interna:

"forensic123"

Si correcta:

"Access Granted"

Si incorrecta:

"Access Denied"

Terminar ejecución.

## Valor técnico

* Comparaciones visibles en assembly
* Punto ideal para patching

---

# 3.4 Apertura de Calculadora

## Objetivo

Simular ejecución de procesos externos.

## API utilizada

WinExec()

## Comportamiento

Ejecutar:

WinExec("calc.exe", SW_SHOW)

## Valor técnico

* Comportamiento requerido por la tarea
* Detectable por CAPA

---

# 3.5 Delay Programado

## Objetivo

Permitir observación en debugging.

## API utilizada

Sleep()

## Tiempo sugerido

1500 ms

## Comportamiento

Sleep(1500)

## Valor técnico

* Punto ideal para breakpoints
* Fácil identificación en análisis dinámico

---

# 3.6 Decodificación de String Oculta

## Objetivo

Simular ocultamiento de información.

## Comportamiento

El binario contendrá un arreglo de bytes codificado.

Ejemplo:

Encoded:

72 65 76 65 72 73 65

Decoded:

"reverse"

La decodificación se realizará en tiempo de ejecución.

## Valor técnico

* Función interesante para reversing
* Identificable en debugging

---

# 3.7 Creación de Archivo Temporal

## Objetivo

Generar evidencia observable en sistema.

## APIs utilizadas

CreateFileA()
WriteFile()
CloseHandle()

## Ruta del archivo

El archivo será creado en el directorio temporal del sistema:

%TEMP%\dummy.txt

Ejemplo de ruta real:

C:\Users\vboxuser\AppData\Local\Temp\dummy.txt

## Contenido del archivo

"Execution log created"
"System scan complete"

## Valor técnico

* Evidencia física observable
* Comportamiento típico de malware benigno

---

# 3.8 Mensaje Final

## Objetivo

Confirmar ejecución exitosa.

## API sugerida

MessageBoxA()

## Mensaje sugerido

"Execution Complete"

## Valor técnico

* Uso adicional de API Windows
* Visible en debugging

---

# 4. Flujo General del Programa

Inicio
↓
printSuspiciousStrings()
↓
checkDebugger()
↓
requestPassword()
↓
validatePassword()

Si incorrecta → Terminar

↓
launchCalculator()
↓
performDelay()
↓
decodeHiddenString()
↓
createDummyFile()
↓
showFinalMessage()
↓
Fin

---

# 5. Estructura de Funciones Planeadas

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

# 6. Strings Planeadas

Estas serán útiles para:

* YARA
* Ingeniería inversa
* Identificación en memoria

Strings visibles:

"Access Granted"
"Access Denied"
"Debugger detected"
"Execution Complete"
"System scan complete"

Strings codificadas:

"reverse"

También se podrán incluir:

Strings decoy (falsas)

Ejemplo:

"malware_payload_loaded"
"stealth_mode_enabled"

---

# 7. APIs de Windows Planeadas

Las siguientes APIs serán utilizadas:

WinExec
Sleep
CreateFileA
WriteFile
CloseHandle
MessageBoxA
IsDebuggerPresent
ExitProcess

---

# 8. Elementos Diseñados para Patching

Se incluirán:

* Comparación de contraseña
* Verificación de debugger
* Branches condicionales

Ejemplo conceptual:

JE → JNE

Esto permitirá bypass del flujo.

---

# 9. Elementos Diseñados para Debugging

Se incluirán:

* Sleep() identificable
* Comparaciones directas
* Variables visibles
* Puntos claros para breakpoint

---

# 10. Elementos Diseñados para YARA

Se incluirán:

* Strings únicas
* Strings sospechosas
* Secuencias reconocibles
* Ruta de archivo temporal

Ejemplo:

"ForensicTrainingSample_v1"

---

# 11. Elementos Diseñados para CAPA

Se incluirán comportamientos detectables:

* Process execution
* File writing
* Delay execution
* Anti-debugging
* String decoding

---

# 12. Complejidad Objetivo

Nivel esperado:

Media – Media Alta

Debe ser:

* Analizable en Ghidra
* Parcheable en Cutter
* Debuggable en x64dbg
* Detectable mediante YARA

Sin ser:

* Demasiado trivial
* Excesivamente complejo

---

# 13. Versión Inicial del Binario

Nombre del ejecutable:

team_sample.exe

Configuración:

Platform: Windows x64
Compiler: Visual Studio
Language: C++
Application Type: Console Application

---

# 14. Posibles Extensiones Futuras

Versiones posteriores podrían incluir:

* Comunicación simulada (fake network)
* Creación de mutex
* Escritura en registro
* Rutinas de auto-verificación
* Ofuscación básica

---

# 15. Entorno de Desarrollo

Sistema operativo:

Windows 10 x64 (Virtual Machine)

Usuario esperado:

vboxuser

Compilador:

Visual Studio (C++)

Repositorio:

Ubicado en entorno local de VM.

---

# 16. Cumplimiento de Requisitos de la Tarea

Este binario cumple explícitamente con los requisitos solicitados:

✔ Abrir calculadora
✔ Mostrar mensajes
✔ Crear archivo temporal
✔ Usar APIs Windows
✔ Simular comportamiento sospechoso
✔ Generar ejecutable funcional

Funciones requeridas:

WinExec → Abrir calculadora
Sleep → Delay
CreateFileA → Crear archivo
WriteFile → Escribir archivo

El ejecutable final será:

team_sample.exe

Este binario es:

✔ Benigno
✔ Educativo
✔ Diseñado para análisis forense
✔ Seguro para ejecución controlada

---

# 17. Notas Finales

Este documento define el comportamiento esperado del binario antes de su implementación.

El desarrollo del código se realizará posteriormente en Visual Studio, siguiendo la estructura lógica aquí definida.

Cualquier modificación funcional deberá registrarse en:

docs/workflow.md
