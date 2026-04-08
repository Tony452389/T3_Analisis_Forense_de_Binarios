# T3_Analisis_Forense_de_Binarios

## 📌 Descripción

Este repositorio contiene el desarrollo completo de la **Tarea 3: Análisis Forense de Binarios**, cuyo objetivo es realizar un análisis integral de un binario educativo utilizando técnicas de análisis estático, ingeniería inversa, patching, debugging dinámico y detección.

El binario fue diseñado para simular comportamientos típicos de software sospechoso con fines educativos, permitiendo a los integrantes del equipo aplicar herramientas reales utilizadas en análisis forense y reverse engineering.

---

## 🎯 Objetivo del Proyecto

Desarrollar y analizar un binario educativo que permita aplicar técnicas reales de análisis forense digital, incluyendo:

* Análisis estático del ejecutable
* Ingeniería inversa mediante Ghidra
* Patching del binario
* Debugging dinámico
* Creación de reglas YARA
* Clasificación funcional mediante CAPA
* Documentación técnica profesional

---

## 👥 Integrantes del Equipo

| Integrante                           | Rol Principal                                    |
| ------------------------------------ | ------------------------------------------------ |
| **Josue Israel Castro Aguilar**      | Desarrollo del binario y análisis estático       |
| **Marco Antonio Vargas Ruiz**        | Ingeniería inversa (Ghidra)                      |
| **Sergio Pedro Sepulveda Rodriguez** | Patching y debugging (Radare2 / Cutter / x64dbg) |
| **Ricardo Hervey Estrada Garcia**    | Detección (YARA / CAPA) y reporte final          |

---

## 🧠 Descripción General del Binario

El binario desarrollado simula múltiples comportamientos sospechosos comúnmente observados en software malicioso educativo.

Entre sus funcionalidades principales se incluyen:

* Impresión de cadenas sospechosas
* Generación de cadenas señuelo
* Detección de debugger mediante API del sistema
* Solicitud y validación de contraseña oculta
* Ejecución de procesos del sistema
* Implementación de retrasos intencionales
* Creación de archivos en directorios temporales
* Presentación de mensajes mediante interfaz gráfica

Estas acciones fueron diseñadas para facilitar su análisis mediante herramientas de ingeniería inversa y análisis forense.

---

## 🧩 Estructura del Repositorio

```text
T3_Analisis_Forense_de_Binarios/

├── src/
│   └── team_sample/
│       ├── main.cpp
│       ├── suspicious.cpp
│       ├── suspicious.h
│       ├── file_ops.cpp
│       ├── file_ops.h
│       ├── system.cpp
│       ├── system.h
│       ├── team_sample.slnx
│       ├── team_sample.vcxproj
│       └── team_sample.vcxproj.filters
│
├── bin/
│   ├── dev/
│   │   ├── team_sample_v1.exe
│   │   ├── team_sample_v2.exe
│   │   └── team_sample_v3.exe
│   │
│   └── final/
│       └── team_sample.exe
│
├── analysis/
│   └── (documentación del análisis estático)
│
├── docs/
│   ├── workflow.md
│   ├── disclaimer.md
│   └── binary/
│       ├── binary_plan.md
│       ├── functions_design.md
│       └── versions.md
│
├── outputs/
│   └── (resultados generados por herramientas)
│
├── report/
│   └── (reporte final del equipo)
│
├── rules/
│   └── (reglas YARA)
│
├── screenshots/
│   ├── ghidra/
│   ├── patching/
│   └── debugging/
│
├── README.md
└── .gitignore
```

---

## 🛠️ Herramientas Utilizadas

Las herramientas empleadas en este proyecto incluyen:

### Desarrollo

* Visual Studio 2026
* Lenguaje C++
* Windows API

### Análisis Estático

* Python 3
* pefile
* strings

### Ingeniería Inversa

* Ghidra

### Patching y Debugging

* Radare2
* Cutter
* x64dbg

### Detección

* YARA
* CAPA

### Control de Versiones

* Git
* GitHub

---

## ⚙️ Requisitos para Compilación

Para compilar el proyecto desde el código fuente:

1. Abrir el archivo:

```text
src/team_sample/team_sample.slnx
```

2. Compilar la solución en Visual Studio.

3. Ejecutar el programa generado.

---

## 📦 Versiones del Binario

Las versiones intermedias del binario se encuentran en:

```text
bin/dev/
```

Mientras que la versión final utilizada para el análisis se encuentra en:

```text
bin/final/team_sample.exe
```

---

## 📌 Uso del Binario

El archivo principal para análisis es:

```text
bin/final/team_sample.exe
```

Este archivo será utilizado por las herramientas del equipo para:

* Ingeniería inversa
* Debugging
* Creación de reglas YARA
* Clasificación CAPA

---

## ⚠️ Advertencia de Seguridad

Este repositorio contiene un binario educativo diseñado con fines académicos.

Aunque el ejecutable no contiene malware real, su comportamiento simulado puede generar alertas por parte de sistemas antivirus o herramientas de seguridad.

Se recomienda ejecutar el binario únicamente en:

* Entornos virtualizados
* Máquinas virtuales controladas
* Ambientes de laboratorio

Consultar:

```text
docs/disclaimer.md
```

para información adicional.

---

## 📊 Estado del Proyecto

🟢 Binario final generado
🟢 Estructura del repositorio completa
🟡 Análisis en progreso
🟡 Ingeniería inversa pendiente
🟡 Generación de reglas YARA pendiente
🟡 Reporte final en desarrollo

---

## 📝 Notas

Este proyecto forma parte de un ejercicio académico orientado a la práctica de análisis forense de binarios y simulación de comportamiento sospechoso controlado.

Todos los elementos contenidos en este repositorio tienen fines educativos exclusivamente.
