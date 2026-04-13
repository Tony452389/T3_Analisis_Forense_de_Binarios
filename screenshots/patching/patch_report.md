# Reporte de Patching

- **Objetivo:** Desactivar la apertura de calc.exe.
- **Dirección:** `0x004079aa`.
- **Cambio:** Se reemplazó la instrucción `call` por `NOP`.
- **Resultado:** Éxito. El programa corre sin abrir la calculadora.