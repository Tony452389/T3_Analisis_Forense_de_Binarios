rule Comportamiento_Sospechoso
{
    meta:
        descripcion = "Detecta el malware escolar por strings unicas"
        autor = "Sergio Pedro Sepúlveda Rodríguez"
        fecha = "2026-04-09"

    strings:
        $s1 = "MAGIC: edu-malware-sim" ascii wide nocase
        $s2 = "Connecting to remote host..." ascii wide nocase
        $s3 = "Loading enctyped payload..." ascii wide nocase
        $s4 = "connect_to_server" ascii wide nocase
        $s5 = "disable_firewall" ascii wide nocase
        $s6 = "admin_login=true" ascii wide nocase

    condition:
        $any of them
}