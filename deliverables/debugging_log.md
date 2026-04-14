# Log de Debugging

Herramienta: x64dbg (x32)
Metodología: Análisis de flujo paso a paso

BITÁCORA DE SESIÓN:

    Entry Point: Se cargó el binario y se avanzó con F9 hasta el punto de entrada principal. Se validó la carga de KERNEL32.DLL.

    Breakpoint: Se estableció un punto de interrupción en 0x004079aa.

    Inspección de Registros: Se observó que el registro EIP (puntero de instrucción) llegó a la zona parcheada.

    Ejecución del Parche: Al presionar F8, el debugger recorrió los bytes 0x90 (NOPs). El programa no saltó a ninguna subrutina externa.

    Verificación de Pila: Se confirmó que el registro ESP (Stack Pointer) no sufrió desalineación, manteniendo la estabilidad del programa.

HALLAZGOS:

    El parche previene la ejecución del proceso hijo.

    El binario finaliza con código de retorno 0x0 (Success).

    Se confirma la creación del archivo de persistencia dummy.txt en el directorio raíz del binario.