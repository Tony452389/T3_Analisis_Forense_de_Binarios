# Informe de Ingeniería Inversa — team_sample.exe
**Herramienta:** Ghidra  
**Archivo analizado:** team_sample.exe

---

## 1. Localización de la Función Principal

Tras analizar el punto de entrada (`entry`), se identificó que la lógica principal del programa no reside en las funciones estándar de inicio (`_start`, `mainCRTStartup`), sino en la función `FUN_140001b80`, renombrada como **`main_logic`** para facilitar el análisis.

**Evidencia:** Ghidra_main_identificacion.png, Ghidra_main_renombramiento.png

**Dirección base:** `0x140001b80`

**Justificación:**
- La función contiene las cadenas de texto interactivas del programa: `"Connecting to remote host..."`, `"Loading encrypted data..."`, `"MAGIC: edu-malware-sim"`.
- Realiza todas las llamadas críticas a la API de Windows: `IsDebuggerPresent`, `WinExec`, `MessageBoxA`, `Sleep`.
- Es referenciada desde `FUN_140000299c` y `0x14000080cc`, confirmando que es el núcleo de ejecución.
- El árbol de símbolos (Symbol Tree) muestra que `main_logic` contiene las variables locales `local_10`, `local_18`, y `local_30`, que estructuran el flujo del programa.

**Prototipo reconstruido (Ghidra decompiler):**
```c
undefined8 main_logic(undefined8 param_1, undefined8 param_2, undefined8 param_3)
```

---

## 2. Reconstrucción de Estructura de Datos

Se identificó el uso de una estructura dinámica referenciada como `local_30` a lo largo de `main_logic`.

### Variables locales identificadas

| Variable    | Tipo inferido          | Descripción                                      |
|-------------|------------------------|--------------------------------------------------|
| `local_10`  | `ulonglong`            | Valor derivado de `DAT_140007040` (XOR cookie)   |
| `local_18`  | `ulonglong`            | Contador/tamaño; comparado contra `0xf` y `0xfff`|
| `local_30`  | `void *[3]`            | Estructura de contexto/sesión con punteros heap  |
| `auStack_58`| `undefined1[8]`        | Buffer auxiliar en stack                         |
| `auStack_50`| `undefined1[32]`       | Buffer auxiliar secundario                       |

### Estructura de Contexto: `SESSION_CTX` (nombre propuesto)

```c
typedef struct _SESSION_CTX {
    void   *pBuffer;      // local_30[0] — buffer heap principal, liberado con free()
    void   *pData;        // local_30[1] — puntero a datos procesados
    void   *pExtra;       // local_30[2] — uso secundario / alineación
} SESSION_CTX;
```

**Ciclo de vida:**
1. **Inicialización:** `FUN_1400020e0((longlong *)local_30, pcVar4, param_3)` — asigna y llena los buffers.
2. **Validación:** `FUN_140002140(local_30)` — verifica integridad del contexto; retorna un char.
3. **Liberación:** `free(local_30[0])` — libera `pBuffer` al finalizar la ejecución (gestión manual de memoria).

**Lógica adicional de local_18:**
```c
if (0xf < local_18) {
    _Memory = local_30[0];
    // Si local_18 supera 0xfff, recalcula punteros internos
    if ((0xfff < local_18 + 1) && ...)
        pcVar4 = (code *)swi(0x29);  // Excepción de desbordamiento
    _Memory = (void *)(*pcVar4)(5);
    free(_Memory);
}
```
Esto indica una estrategia de gestión dinámica con **Small String Optimization (SSO)** o manejo de buffers de tamaño variable.

---

## 3. Flujo de Ejecución Documentado

**Evidencia:** Ghidra_antidebug_IsDebuggerPresent.png, Ghidra_flujo_payload_ejecucion.png, Ghidra_flujo_memoria_liberacion.png

El programa sigue una secuencia diseñada para simular un comportamiento malicioso con técnicas de evasión:

```
INICIO
  │
  ├─► Inicialización de stack cookie (GS_OFFSET / DAT_140007040 XOR auStack_58)
  │
  ├─► Banner en consola:
  │     "MAGIC: edu-malware-sim"
  │     "Connecting to remote host..."
  │     "Initializing system..."
  │     "Loading encrypted data..."
  │
  ├─► FUN_1400001d10()           ← Inicialización interna desconocida
  │
  ├─► IsDebuggerPresent()        ← Anti-análisis
  │     │
  │     ├─ [BVar1 != 0] Depurador detectado:
  │     │       JZ → LAB_140001c5e
  │     │       MessageBoxA("Debugger detected!", "Warning", 0x30)
  │     │       return 0;
  │     │
  │     └─ [BVar1 == 0] Sin depurador → continúa payload
  │
  ├─► FUN_1400020e0(local_30, pcVar4, param_3)   ← Init SESSION_CTX
  │
  ├─► FUN_140002140(local_30) → uVar3            ← Validación de contexto
  │
  ├─► if ((char)uVar3 != '\0'):   ← Validación exitosa
  │     ├─ WinExec("calc.exe", 5)
  │     ├─ Sleep(5000)
  │     ├─ FUN_1400011d0()
  │     └─ MessageBoxA(0, "Execution Complete", "team_sample", 0x40)
  │
  ├─► Gestión de memoria (free según tamaño local_18)
  │
  └─► __security_check_cookie → RET
```

**Etiquetas de salto identificadas:**

| Etiqueta         | Dirección      | Propósito                                 |
|------------------|----------------|-------------------------------------------|
| `LAB_140001c5e`  | `0x140001c5e`  | Rama de detección de depurador            |
| `LAB_140001cb6`  | `0x140001cb6`  | Salto si `uVar3 == '\0'` (validación falla)|
| `LAB_140001cf8`  | —              | Rutina de liberación de memoria           |

---

## 4. Llamadas a API Relevantes

**Evidencia:** Ghidra_antidebug_IsDebuggerPresent.png, Ghidra_flujo_memoria_liberacion.png

| API                  | Biblioteca        | Dirección importada | Propósito                                                       |
|----------------------|-------------------|---------------------|-----------------------------------------------------------------|
| `IsDebuggerPresent`  | `KERNEL32.DLL`    | `0x000058ea`        | Anti-análisis: detecta si el proceso está siendo depurado       |
| `WinExec`            | `KERNEL32.DLL`    | `0x000059e0`        | Ejecución de proceso externo (`calc.exe` con nShow=5)           |
| `Sleep`              | `KERNEL32.DLL`    | `0x000059d8`        | Retraso de 5000 ms (evasión por temporización)                  |
| `MessageBoxA`        | `USER32.DLL`      | `0x0000590c`        | Diálogos de éxito (`Execution Complete`) y error (`Debugger detected!`) |

**Detalles de llamada (ensamblador):**

```asm
; IsDebuggerPresent
140001c24  CALL  qword ptr [->KERNEL32.DLL::IsDebuggerPresent]
140001c2a  TEST  EAX, EAX
140001c2c  JZ    LAB_140001c5e        ; si EAX==0 → no hay depurador

; WinExec("calc.exe", 5)
140001c7c  LEA   param_1, [s_calc.exe_140004590]
140001c83  CALL  qword ptr [->KERNEL32.DLL::WinExec]

; Sleep(5000 ms = 0x1388)
140001c89  MOV   param_1, 0x1388
140001c8e  CALL  qword ptr [->KERNEL32.DLL::Sleep]

; MessageBoxA — "Execution Complete"
140001c9f  LEA   param_3, [s_team_sample_1400045a0]    ; "team_sample"
140001ca6  LEA   param_2, [s_Execution_Complete_...]   ; "Execution Complete"
140001caf  CALL  qword ptr [->USER32.DLL::MessageBoxA]
```

---

## 5. Hallazgos Adicionales — Análisis de Strings

**Evidencia:** Ghidra_strings_capacidades_latentes.png

El análisis de la sección de strings (139 items en total) en Ghidra revela cadenas adicionales que **no son ejecutadas** en el flujo principal documentado, lo que indica la existencia de módulos latentes o funcionalidades deshabilitadas:

| Dirección      | String                        | Categoría                       |
|----------------|-------------------------------|---------------------------------|
| `0x140004438`  | `Execution log cr...`         | Logging / persistencia          |
| `0x140004468`  | `Dummy file crea...`          | Creación de archivos falsos     |
| `0x140004480`  | `Failed to create ...`        | Manejo de errores               |
| `0x140004528`  | `connect_to_server`           | Comunicación remota             |
| `0x140004540`  | `disable_firewall`            | Evasión de defensas             |
| `0x140004558`  | `admin_login=true`            | Escalación de privilegios       |
| `0x140004570`  | `upload_data`                 | Exfiltración de datos           |
| `0x140004610`  | `Access granted!`             | Resultado de autenticación      |
| `0x140004620`  | `Access Denied`               | Resultado de autenticación      |
| `0x140004630`  | `Invalid password!`           | Control de acceso               |
| `0x1400045e8`  | `Enter password:`             | Interacción con usuario (oculta)|
| `0x140004b4`   | `RSDS`                        | Debug symbol header             |
| `0x140004b6c`  | `C:\Users\vboxus...`          | Ruta de compilación (PDB path)  |

**Observaciones clave:**

- La ruta PDB (`C:\Users\vboxus...`) confirma que fue compilado en una **máquina virtual VirtualBox**, típico de entornos de desarrollo/prueba de malware.
- Las strings `disable_firewall`, `admin_login=true` y `upload_data` apuntan a capacidades de **evasión, persistencia y exfiltración** no activadas en esta muestra.
- La presencia de `connect_to_server` y `Enter password:` sugiere un **módulo de C2 (Command & Control)** o autenticación remota deshabilitado.
- La cadena `MAGIC: edu-malware-sim` confirma que es una **simulación educativa de malware**, no una amenaza real en producción.

**Conclusión:**  El binario es una simulación controlada de malware con arquitectura modular. Desde una perspectiva estática, el ejecutable contiene un conjunto amplio de capacidades: evasión de defensas perimetrales (disable_firewall), autenticación remota (admin_login=true, Enter password:), exfiltración de datos (upload_data) y comunicación con infraestructura externa (connect_to_server). Sin embargo, en el análisis dinámico del flujo de ejecución principal, únicamente se activan las rutinas de anti-debugging mediante IsDebuggerPresent y el lanzamiento de calc.exe como payload benigno de demostración. Las cadenas latentes están compiladas en la sección .rdata del PE pero no cuentan con referencias cruzadas activas (XREF) desde ninguna función del flujo principal, lo que indica que corresponden a módulos inactivos o condicionalmente ejecutables según parámetros externos no presentes en esta muestra. La ruta PDB y la cadena MAGIC: edu-malware-sim corroboran que se trata de un binario de propósito educativo, diseñado para replicar el comportamiento y las técnicas de evasión de malware real en un entorno controlado.

---

## 6. Resumen de Evidencias

| Captura                                  | Contenido documentado                                         |
|------------------------------------------|---------------------------------------------------------------|
| Ghidra_main_identificacion.png           | Función `main_logic` renombrada en Symbol Tree + decompiler   |
| Ghidra_main_renombramiento.png           | Vista completa de `FUN_140001b80` en listing y decompiler     |
| Ghidra_antidebug_IsDebuggerPresent.png   | Bloque `IsDebuggerPresent` + salto condicional anti-debug     |
| Ghidra_flujo_payload_ejecucion.png       | Bloque payload: `WinExec`, `Sleep`, `MessageBoxA`             |
| Ghidra_flujo_memoria_liberacion.png      | Bloque payload completo con código de liberación de memoria   |
| Ghidra_strings_capacidades_latentes.png  | Defined Strings — 139 items con strings latentes              |
