# Reporte de Patching

Binario: team_sample.exe  
Objetivo: Desactivar la ejecución automática del proceso **calc.exe**

---

## Detalles Técnicos

**Dirección de memoria modificada:**  
0x004079aa  

**Instrucción original:**  
CALL a la función **WinExec**, responsable de ejecutar el proceso externo **calc.exe**.

**Instrucción aplicada (parche):**  
90 90 90 90 90  
(NOP - No Operation)

Se reemplazaron **5 bytes consecutivos** correspondientes a la instrucción CALL original.  
El uso de instrucciones **NOP (0x90)** permitió neutralizar la llamada sin alterar la alineación del código ni modificar el tamaño del archivo ejecutable.

---

## Procedimiento

1. Se identificó la instrucción CALL responsable de la ejecución de **calc.exe** mediante análisis estático utilizando **Ghidra**.

2. Se localizó la dirección **0x004079aa**, correspondiente al punto crítico donde se realizaba la llamada a **WinExec**.

3. Se utilizó un editor hexadecimal para reemplazar los bytes originales de la instrucción CALL por cinco instrucciones **NOP (0x90)**.

4. Se verificó que el tamaño total del archivo permaneciera idéntico, evitando la corrupción de la estructura interna del ejecutable.

5. Posteriormente, se ejecutó el binario modificado en el entorno de debugging para validar el comportamiento tras la modificación.

---

## Resultado

El parche fue aplicado exitosamente.

Después de la modificación:

- El programa continúa su flujo normal de ejecución.
- La llamada a **WinExec** es omitida.
- El proceso **calc.exe** ya no es ejecutado.
- El programa genera correctamente el archivo **dummy.txt**, confirmando que el flujo principal permanece funcional.

---

## Verificación

La verificación del parche se realizó mediante:

- Ejecución del binario modificado en el entorno de debugging.
- Observación del flujo de ejecución sobre instrucciones **NOP**.
- Confirmación de la ausencia de ejecución del proceso **calc.exe**.
- Validación del comportamiento esperado del programa tras la modificación.