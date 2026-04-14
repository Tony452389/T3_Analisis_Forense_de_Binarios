# Reporte de Patching

Binario: team_sample.exe
Objetivo: Desactivar la apertura automática de calc.exe

DETALLES TÉCNICOS:

    Dirección de memoria: 0x004079aa

    Instrucción original: CALL (Invocación a WinExec)

    Instrucción de parche: 90 90 90 90 90 (NOP - No Operation)

PROCEDIMIENTO:

    Se identificó la dirección del CALL mediante el análisis estático en Ghidra.

    Se utilizó un editor hexadecimal para reemplazar los bytes del CALL por instrucciones NOP.

    Se validó que el tamaño del archivo permaneciera idéntico para no corromper la estructura del ejecutable.

RESULTADO:
El parche fue exitoso. Al ejecutar el binario modificado, el programa continúa su flujo normal, crea el archivo dummy.txt, pero ignora completamente la ejecución de la calculadora.