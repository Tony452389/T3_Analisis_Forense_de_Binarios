# Binary Versions Strategy — team_sample.exe

Proyecto: T3_Analisis_Forense_de_Binarios

---

# 1. Objetivo

Definir la estrategia de versiones del binario durante el desarrollo y la generación de la versión final utilizada para análisis forense.

Las versiones intermedias se utilizarán únicamente para desarrollo interno.

La versión final será utilizada por el equipo para análisis.

---

# 2. Versiones de Desarrollo (Internas)

Estas versiones se utilizarán para pruebas y validación incremental del comportamiento del binario.

No serán utilizadas para análisis oficial.

---

## Version 1 — Base Behavior

Nombre:

team_sample_v1.exe

Funciones incluidas:

* printSuspiciousStrings()
* launchCalculator()
* performDelay()
* createDummyFile()
* showFinalMessage()

Objetivo:

Validar el funcionamiento básico del binario.

---

## Version 2 — Conditional Logic

Nombre:

team_sample_v2.exe

Funciones añadidas:

* checkDebugger()
* requestPassword()
* validatePassword()

Objetivo:

Introducir flujo condicional y lógica de validación.

---

## Version 3 — Hidden Logic

Nombre:

team_sample_v3.exe

Funciones añadidas:

* decodeHiddenString()

Objetivo:

Introducir ocultamiento básico de información.

---

# 3. Versión Final Oficial

Nombre:

team_sample.exe

Ubicación:

bin/final/

Esta versión incluirá todas las funciones implementadas.

Será compilada en modo:

Release

Será utilizada por:

* Ingeniería inversa
* Debugging
* Patching
* Creación de reglas YARA
* Identificación con CAPA

Esta versión no deberá modificarse después de su publicación.

---

# 4. Política de Congelamiento (Freeze Policy)

Una vez generada la versión final:

team_sample.exe

No se permitirán modificaciones adicionales al código.

Todos los análisis se realizarán sobre esta versión única.

---

# 5. Notas Importantes

El desarrollo del binario será realizado por un único responsable.

Las versiones internas serán utilizadas únicamente para pruebas.

El equipo trabajará exclusivamente con la versión final.
