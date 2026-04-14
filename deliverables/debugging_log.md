# Log de Debugging

Herramienta: x64dbg (x32)  
Metodología: Análisis de flujo paso a paso  

---

## Bitácora de Sesión

### 1. Carga del Binario

Se cargó el binario **team_sample.exe** en el entorno de depuración utilizando x64dbg.

Se avanzó con la ejecución (F9) hasta alcanzar el **Entry Point**, verificando la correcta carga de módulos del sistema, incluyendo **KERNEL32.DLL**.

---

### 2. Identificación del Punto Crítico

Se estableció un breakpoint en la dirección **0x004079aa**, correspondiente a una instrucción relacionada con la ejecución de un proceso externo mediante la función **WinExec**.

Este punto fue seleccionado debido a que representaba la llamada responsable de lanzar el proceso **calc.exe**.

---

### 3. Inspección del Flujo de Ejecución

Durante la ejecución paso a paso (F8), se observó que el registro **EIP (Instruction Pointer)** alcanzó la dirección objetivo definida en el breakpoint.

Se confirmó que la ejecución se encontraba en la zona donde posteriormente se aplicaría el parche.

---

### 4. Ejecución Tras el Parche

Después de aplicar el parche (reemplazo por instrucciones **NOP**), se ejecutó nuevamente el binario.

Durante la ejecución paso a paso (F8), el debugger recorrió los bytes **0x90 (NOP)**, evitando la llamada a la función **WinExec**.

Como resultado:

- El programa continuó su ejecución normal  
- No se realizó la llamada a **calc.exe**  
- No se produjo salto a subrutinas externas  

---

### 5. Verificación de Estabilidad

Se verificó el comportamiento de la pila durante la ejecución.

El registro **ESP (Stack Pointer)** se mantuvo alineado correctamente, confirmando que el parche no generó corrupción en la pila ni inestabilidad del programa.

---

## Hallazgos

- El parche previene la ejecución del proceso hijo **calc.exe**.

- El binario finaliza con código de retorno **0x0 (Success)**.

- Se confirma la creación del archivo **dummy.txt**, utilizado como archivo de prueba generado durante la ejecución del programa.