# Static Analysis Overview — team_sample.exe

## 1. Introducción

El presente documento describe el análisis estático realizado sobre el ejecutable **team_sample.exe**, desarrollado como parte del proyecto académico *T3_Analisis_Forense_de_Binarios*.

El objetivo del análisis estático es identificar características internas del binario sin necesidad de ejecutarlo, permitiendo inferir su comportamiento mediante la inspección de cadenas embebidas, funciones importadas y estructura interna del archivo PE (Portable Executable).

Este análisis constituye la primera etapa del proceso forense, previo al análisis dinámico, ingeniería inversa y detección mediante herramientas especializadas.

---

## 2. Metodología

El análisis estático fue realizado utilizando herramientas desarrolladas en Python y la librería **pefile**, permitiendo la automatización del proceso de extracción de información relevante.

Las siguientes actividades fueron realizadas:
- Extracción de cadenas ASCII desde el binario.
- Identificación de funciones importadas y bibliotecas utilizadas.
- Análisis de las secciones internas del archivo PE.
- Identificación de posibles indicadores de comportamiento sospechoso.
- Formulación de una hipótesis inicial del comportamiento del binario.

El ejecutable analizado fue compilado utilizando **Microsoft Visual Studio 2026**, lo cual se evidenció mediante la presencia de rutas de depuración (*.pdb*) dentro de las cadenas extraídas.

---

## 3. Análisis de Cadenas (Strings)

La extracción de cadenas fue realizada mediante un script desarrollado en Python, el cual permitió identificar cadenas ASCII embebidas dentro del ejecutable **team_sample.exe**.

Como resultado del análisis se obtuvieron:
- **338 cadenas ASCII**
- **0 cadenas Unicode**

La ausencia de cadenas Unicode sugiere que el programa utiliza principalmente funciones basadas en caracteres ASCII, tales como aquellas terminadas en la letra **A** dentro de la API de Windows.

---

### 3.1 Cadenas Indicativas de Comportamiento Sospechoso

Durante el análisis se identificaron diversas cadenas que simulan comportamientos típicamente asociados con software malicioso o actividades sospechosas:
- MAGIC: edu-malware-sim
- Connecting to remote host...
- Initializing system scan...
- Loading enctypted payload...

- connect_to_server
- disable_firewall
- admin_login=true
- upload_data

Estas cadenas sugieren la simulación de actividades como:
- Comunicación remota con sistemas externos
- Inicialización de procesos de escaneo
- Manipulación de configuraciones de seguridad
- Transferencia de información

Este tipo de indicadores es comúnmente utilizado en simulaciones educativas de malware.

---

### 3.2 Cadenas Relacionadas con Manejo de Archivos

Se identificaron cadenas que sugieren la creación y escritura de archivos dentro del sistema:
- dummy.txt
- Execution log created
- System scan complete
- Dummy file created at:
- Failed to create dummy file, Error code:

Estas cadenas indican que el programa probablemente realiza operaciones de escritura en disco, posiblemente generando archivos temporales como parte de su ejecución.

---

### 3.3 Cadenas Relacionadas con Ejecución de Procesos

Se detectaron cadenas que sugieren la ejecución de programas externos:
- calc.exe
- Execution Complete
- Warning
- Debugger detected!

La presencia de la cadena **calc.exe** indica que el programa probablemente ejecuta un proceso externo del sistema operativo, lo cual es una técnica frecuentemente utilizada en ejemplos educativos de análisis de malware.

---

### 3.4 Cadenas Relacionadas con Autenticación

Durante el análisis se identificaron cadenas que indican la existencia de mecanismos de validación de contraseña:
- Enter password:
- QAttx1se234
- Access granted!
- Access Denied
- Invalid password!

La presencia de estas cadenas sugiere que el programa implementa un sistema de autenticación interna antes de ejecutar ciertas acciones.

Es especialmente relevante la cadena **"QAttx1se234"**, la cual podría representar una contraseña almacenada de forma codificada dentro del binario.

---

### 3.5 Artefactos del Entorno de Desarrollo

Se identificó la siguiente cadena asociada al entorno de compilación:
- C:\Users\vboxuser\Documents\Repositorios PAC\T3_Analisis_Forense_de_Binarios\bin\dev\team_sample.pdb

La presencia de un archivo **.pdb** sugiere que el ejecutable fue compilado en un entorno de desarrollo basado en **Microsoft Visual Studio**, permitiendo inferir información sobre el origen del binario.

Este tipo de artefactos puede ser útil en investigaciones forenses reales para identificar entornos de desarrollo utilizados por los creadores del software.

---

## 4. Análisis de Funciones Importadas (Imports)

El análisis de funciones importadas fue realizado utilizando la librería **pefile**, permitiendo identificar las bibliotecas dinámicas (DLL) utilizadas por el ejecutable **team_sample.exe**.

Como resultado, se identificaron las siguientes bibliotecas:
- KERNEL32.dll
- USER32.dll
- MSVCP140.dll
- VCRUNTIME140_1.dll
- VCRUNTIME140.dll
- api-ms-win-crt-heap-l1-1-0.dll
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-locale-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll

Estas bibliotecas pueden clasificarse en tres categorías principales: bibliotecas del sistema operativo, bibliotecas del runtime de C++ y bibliotecas del Universal C Runtime (UCRT).

---

### 4.1 Bibliotecas del Sistema Operativo

Las siguientes bibliotecas corresponden a funciones principales del sistema operativo Windows:
- KERNEL32.dll
- USER32.dll

Estas bibliotecas contienen funciones críticas utilizadas por el programa, incluyendo:
- **CreateFileA** — Creación de archivos en el sistema.
- **WriteFile** — Escritura de datos en archivos.
- **CloseHandle** — Cierre de manejadores de archivos.
- **Sleep** — Introducción de retardos en la ejecución.
- **WinExec** — Ejecución de programas externos.
- **IsDebuggerPresent** — Detección de entornos de depuración.
- **MessageBoxA** — Despliegue de mensajes visuales al usuario.

La presencia de estas funciones confirma la capacidad del programa para interactuar con el sistema operativo, crear archivos, ejecutar procesos y detectar herramientas de análisis.

---

### 4.2 Bibliotecas del Runtime de C++

Las siguientes bibliotecas corresponden al entorno de ejecución del lenguaje C++:
- MSVCP140.dll
- VCRUNTIME140_1.dll
- VCRUNTIME140.dll

Estas bibliotecas indican que el programa fue compilado utilizando **Microsoft Visual Studio**, lo cual coincide con la presencia de símbolos de depuración (*.pdb*) identificados durante el análisis de cadenas.

---

### 4.3 Bibliotecas del Universal C Runtime (UCRT)

Las siguientes bibliotecas corresponden a componentes del runtime estándar de C:
- api-ms-win-crt-heap-l1-1-0.dll
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-locale-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll

Estas bibliotecas proporcionan funcionalidades básicas como:
- Manejo de memoria
- Operaciones matemáticas
- Manipulación de cadenas
- Entrada y salida estándar

Su presencia es común en programas desarrollados en C y C++.

---

## 5. Análisis de Secciones del Archivo PE

El análisis de las secciones internas del ejecutable **team_sample.exe** fue realizado utilizando la librería **pefile**, permitiendo identificar la estructura interna del archivo Portable Executable (PE).

Como resultado del análisis se identificaron **seis secciones principales**, las cuales son comunes en ejecutables desarrollados en lenguaje C++ bajo sistemas Windows.

Las secciones detectadas fueron:
- .text
- .rdata
- .data
- .pdata
- .rsrc
- .reloc

Cada una de estas secciones cumple una función específica dentro del ejecutable.

---

### 5.1 Sección .text

La sección **.text** contiene las instrucciones ejecutables del programa.

Esta sección almacena el código máquina correspondiente a las funciones principales del ejecutable, incluyendo la lógica de interacción con el usuario, validación de contraseña, detección de debugger y creación de archivos.

Las características de esta sección indican que posee permisos de ejecución, lo cual es consistente con su función principal de contener el código del programa.

---

### 5.2 Sección .rdata

La sección **.rdata** contiene datos de solo lectura utilizados durante la ejecución del programa.

Dentro de esta sección se almacenan principalmente:
- Cadenas de texto (strings)
- Constantes utilizadas por el programa
- Referencias a funciones importadas

Durante el análisis de cadenas se identificó una gran cantidad de strings relevantes que probablemente residen en esta sección, incluyendo nombres de archivos, mensajes al usuario y cadenas simulando comportamiento sospechoso.

---

### 5.3 Sección .data

La sección **.data** contiene variables globales que pueden ser modificadas durante la ejecución del programa.

Esta sección almacena datos que requieren escritura durante la ejecución, como buffers y variables utilizadas en operaciones internas del programa.

Su presencia es normal en programas que utilizan variables globales o estructuras dinámicas.

---

### 5.4 Sección .pdata

La sección **.pdata** contiene información relacionada con el manejo de excepciones del programa.

Esta sección es común en programas compilados con compiladores modernos de C++, ya que almacena metadatos necesarios para el manejo de excepciones y control de errores en tiempo de ejecución.

La presencia de esta sección coincide con el uso de librerías estándar del lenguaje C++.

---

### 5.5 Sección .rsrc

La sección **.rsrc** contiene recursos utilizados por el programa.

Estos recursos pueden incluir:
- Iconos
- Información de versión
- Metadatos del programa
- Configuraciones internas

En programas simples, esta sección suele contener información mínima necesaria para la correcta identificación del ejecutable por parte del sistema operativo.

---

### 5.6 Sección .reloc

La sección **.reloc** contiene información de relocalización del programa.

Esta sección permite que el ejecutable pueda ser cargado en diferentes direcciones de memoria sin afectar su funcionamiento, facilitando mecanismos modernos de protección como **ASLR (Address Space Layout Randomization)**.

La presencia de esta sección es común en ejecutables modernos y no representa comportamiento sospechoso por sí misma.

---

## 6. Hipótesis Inicial del Comportamiento del Binario

Con base en la información obtenida durante el análisis de cadenas, funciones importadas y estructura interna del archivo PE, fue posible inferir el comportamiento general del ejecutable **team_sample.exe** sin necesidad de ejecutarlo.

La evidencia obtenida sugiere que el binario sigue una secuencia lógica de ejecución que simula actividades típicamente asociadas con software malicioso en un entorno educativo.

---

### 6.1 Fase Inicial — Mensajes Simulados

Durante el inicio de ejecución, el programa parece desplegar mensajes con apariencia sospechosa, simulando actividades relacionadas con comunicación remota y análisis del sistema.

Esta inferencia se basa en la presencia de cadenas como:
- MAGIC: edu-malware-sim
- Connecting to remote host...
- Initializing system scan...
- Loading enctypted payload...

Estas cadenas sugieren la simulación de procesos típicos en software malicioso, como conexiones remotas o carga de componentes internos.

---

### 6.2 Detección de Entornos de Depuración

Se identificaron indicadores que sugieren la implementación de mecanismos básicos de detección de depuración.

Esto se sustenta en la presencia de:
- IsDebuggerPresent
- Debugger detected!

La función **IsDebuggerPresent**, importada desde **KERNEL32.dll**, indica que el programa puede verificar si se encuentra bajo análisis mediante herramientas de depuración.

Este comportamiento es común en software que intenta evitar el análisis dinámico.

---

### 6.3 Solicitud y Validación de Contraseña

Se detectaron múltiples cadenas relacionadas con autenticación, lo que sugiere que el programa solicita credenciales al usuario antes de continuar con su ejecución.

Las cadenas relevantes incluyen:
- Enter password:
- QAttx1se234
- Access granted!
- Access Denied
- Invalid password!

La presencia de una cadena aparentemente codificada (**QAttx1se234**) sugiere la existencia de un mecanismo interno de validación de contraseña.

Esto indica que ciertas funcionalidades del programa podrían estar condicionadas al ingreso correcto de credenciales.

---

### 6.4 Ejecución de Procesos Externos

La presencia de la cadena:
- calc.exe

junto con la función importada **WinExec**, sugiere que el programa ejecuta procesos externos del sistema operativo.

Esto indica que el programa posee la capacidad de iniciar aplicaciones externas durante su ejecución.

---

### 6.5 Introducción de Retardos en la Ejecución

Se identificó la función:
- Sleep

la cual permite introducir pausas en la ejecución del programa.

Este tipo de comportamiento puede utilizarse para simular actividad prolongada o para retrasar la ejecución de ciertas operaciones.

---

### 6.6 Creación de Archivos en el Sistema

Se identificaron indicadores claros de creación de archivos dentro del sistema operativo.

La evidencia incluye:
- dummy.txt
- Execution log created
- System scan complete
- Dummy file created at:

junto con funciones importadas como:
- CreateFileA
- WriteFile
- CloseHandle
- GetTempPathA

Esto sugiere que el programa genera archivos dentro del directorio temporal del sistema operativo, específicamente en rutas similares a:
- C:\Users<usuario>\AppData\Local\Temp\

La creación de archivos temporales es una actividad común tanto en software legítimo como en simulaciones educativas de malware.

---

### 6.7 Interacción Final con el Usuario

Se identificó el uso de la función:
- MessageBoxA

lo cual sugiere que el programa muestra mensajes visuales al usuario al finalizar su ejecución.

La presencia de cadenas como:
- Execution Complete
- Warning

indica la probable notificación del estado final del programa.

---

### 6.8 Flujo General Inferido del Programa

Con base en la evidencia recolectada, se propone el siguiente flujo general de ejecución:
1. Despliegue de mensajes simulando actividad del sistema.
2. Verificación de la presencia de herramientas de depuración.
3. Solicitud de contraseña al usuario.
4. Validación interna de credenciales.
5. Ejecución de un proceso externo (**calc.exe**).
6. Introducción de retardos mediante la función **Sleep**.
7. Creación de un archivo temporal (**dummy.txt**).
8. Despliegue de un mensaje final mediante **MessageBoxA**.

Este flujo es consistente con el comportamiento esperado de un binario educativo diseñado para simular actividades típicas observadas en análisis de malware.

---

## 7. Conclusión

El análisis estático del ejecutable **team_sample.exe** permitió identificar múltiples características internas relevantes sin necesidad de ejecutar el programa.

Mediante la extracción y análisis de cadenas, funciones importadas y estructura interna del archivo PE, fue posible inferir un comportamiento general consistente con un binario educativo diseñado para simular actividades sospechosas típicamente observadas en software malicioso.

Se identificaron indicadores claros de:
- Detección de entornos de depuración.
- Validación interna de credenciales.
- Ejecución de procesos externos.
- Introducción de retardos en la ejecución.
- Creación de archivos en el sistema.
- Interacción visual con el usuario.

Asimismo, la presencia de bibliotecas del runtime de C++ y archivos de depuración (*.pdb*) permitió inferir que el binario fue compilado utilizando **Microsoft Visual Studio 2026**.

En conjunto, los hallazgos obtenidos durante el análisis estático proporcionan una base sólida para continuar con las siguientes fases del análisis forense, incluyendo ingeniería inversa, debugging dinámico y generación de reglas de detección.