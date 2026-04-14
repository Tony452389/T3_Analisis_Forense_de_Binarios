
# T3 – Análisis Forense de Binarios

## Descripción General

Este repositorio contiene el desarrollo completo de la **Tarea 3 – Análisis Forense de Binarios**, cuyo objetivo es analizar un ejecutable diseñado para simular comportamientos comúnmente observados en software sospechoso.

El proyecto incluye:

- Desarrollo de un binario educativo en C++
- Análisis estático mediante herramientas especializadas
- Análisis mediante ingeniería inversa
- Identificación de capacidades con FLARE CAPA
- Creación de reglas YARA para detección
- Técnicas de debugging y patching
- Documentación completa del proceso

Este repositorio está organizado para facilitar la revisión técnica y académica del trabajo realizado.

---

## ⚠️ Aviso Importante

Este repositorio contiene un **binario educativo diseñado únicamente con fines académicos**.

El ejecutable:

- **NO es malware real**
- **NO contiene código malicioso**
- **NO realiza conexiones reales**
- **NO modifica configuraciones críticas del sistema**

El programa simula comportamientos típicos utilizados en análisis forense y seguridad informática.

Se recomienda ejecutar el binario **únicamente en entornos controlados**, como:

- Máquinas virtuales
- Entornos de laboratorio
- Sistemas de prueba

---

## Objetivo del Proyecto

El objetivo principal fue aplicar técnicas de análisis forense de binarios para:

- Identificar comportamiento interno de un ejecutable
- Analizar funciones y cadenas relevantes
- Estudiar mecanismos de detección de debugger
- Simular manipulación de archivos y procesos
- Implementar técnicas básicas de patching
- Crear reglas YARA para detección basada en patrones

---

## Características del Binario Analizado

Archivo principal:

    bin/final/team_sample.exe

Características:

- Formato: Portable Executable (PE)
- Arquitectura: x64
- Lenguaje: C++
- Plataforma objetivo: Windows
- Tipo: Simulación educativa

Comportamientos implementados:

- Escritura de archivos
- Ejecución de procesos externos
- Detección de debugger
- Simulación de operaciones del sistema
- Uso de API de Windows

---

## Estructura del Repositorio

    T3_Analisis_Forense_de_Binarios/

    ├── bin/
    │   ├── dev/
    │   │   ├── team_sample_v1.exe
    │   │   ├── team_sample_v2.exe
    │   │   └── team_sample_v3.exe
    │   │
    │   ├── final/
    |   │   └── team_sample.exe
    |   |
    |   └── pathced/
    |        └── team_sample_patched.exe
    │
    ├── deliverables/
    │   ├── static_overview.md
    │   ├── ghidra_notes.md
    │   ├── capa_report.txt
    │   └── team_report.md
    │
    ├── docs/
    │   ├── development_guides/
    │   │   ├── binary_plan.md
    │   │   ├── functions_design.md
    │   │   └── versions.md
    │   │
    │   ├── detection/
    │   │   └── team_rule.yara
    │   │
    │   └── team_workflow/
    │       └── workflow.md
    │
    ├── screenshots/
    │   ├── ghidra/
    │   ├── patching/
    |   ├── yara/
    │   └── static_analysis/
    │
    ├── src/
    │   └── team_sample/
    │
    └── static_analysis/
        ├── outputs/
        └── tools/

---

## Herramientas Utilizadas

Durante el desarrollo y análisis se utilizaron las siguientes herramientas:

### Desarrollo

- Visual Studio
- C++
- Windows API

### Análisis Estático

- Strings extraction
- PE analysis scripts
- Ghidra

### Análisis de Capacidades

- FLARE CAPA

### Debugging y Patching

- Debugger (según integrante)
- Herramientas de modificación binaria

### Detección

- YARA

---

## Flujo de Trabajo

El proyecto se desarrolló siguiendo un flujo estructurado:

1. Diseño del comportamiento del binario
2. Implementación en C++
3. Compilación y pruebas
4. Análisis estático
5. Ingeniería inversa con Ghidra
6. Identificación de capacidades con CAPA
7. Creación de reglas YARA
8. Debugging y patching
9. Integración del reporte final

---

## Resultados Obtenidos

Durante el análisis se identificaron:

- Uso de funciones de manipulación de archivos
- Ejecución de procesos externos
- Detección básica de debugger
- Cadenas simuladas relacionadas con actividades del sistema
- Patrones identificables mediante reglas YARA
- Comportamiento modificable mediante patching

---

## Entregables Principales

Los documentos principales del proyecto se encuentran en:

    deliverables/

Incluyen:

- static_overview.md  
  Resultados del análisis estático

- ghidra_notes.md  
  Resultados de ingeniería inversa

- capa_report.txt  
  Capacidades detectadas con CAPA

- team_report.md  
  Reporte técnico consolidado

---

## Evidencias Visuales

Las capturas utilizadas como evidencia se encuentran en:

    screenshots/

Organizadas por:

- Static analysis
- Ghidra
- Debugging
- Patching
- Yara

---

## Regla YARA

La regla de detección desarrollada se encuentra en:

    docs/detection/team_rule.yara

Esta regla permite identificar el binario mediante cadenas únicas presentes en el ejecutable.

---

## Limitaciones

Este proyecto fue desarrollado con fines educativos.

Algunas limitaciones incluyen:

- No se realizaron conexiones reales de red
- No se implementó persistencia real
- Algunas funcionalidades fueron simuladas mediante cadenas internas
- El análisis dinámico depende del entorno de ejecución

---

## Autores

Equipo de trabajo:

| Integrante                           | Rol Principal                                    |
| ------------------------------------ | ------------------------------------------------ |
| **Josue Israel Castro Aguilar**      | Desarrollo del binario y análisis estático       |
| **Marco Antonio Vargas Ruiz**        | Ingeniería inversa (Ghidra)                      |
| **Sergio Pedro Sepulveda Rodriguez** | Patching y debugging (Radare2 / Cutter / x64dbg) |
| **Ricardo Hervey Estrada Garcia**    | Detección (YARA / CAPA) y reporte final          |

---

## Licencia

Este proyecto fue desarrollado únicamente con fines académicos.

El contenido no debe utilizarse fuera de contextos educativos o de laboratorio.