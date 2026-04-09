rule Comportamiento_Sospechoso
{
    meta:
        descripcion = "Detecta el malware escolar por hash exacto o string unica"
        autor = "Sergio Pedro Sepúlveda Rodríguez"
        fecha = "2026-04-09"

    strings:
        $magic = "MAGIC: edu-malware-sim" ascii wide nocase

    condition:
        $magic
}