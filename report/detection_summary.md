Detection Summary

Nombre de la Amenaza: Suspicious C2 Communication – team_sample.exe
Tipo: Command & Control (C2) 
Nivel de Criticidad: Crítico

Host afectado:
DESKTOP-7F3K2L (Windows 11 Pro)

Proceso detectado:
C:\Program Files\System\team_sample.exe

Hora de detección:
13/04/2026 - 02:18 AM

Actividad:
Conexiones periódicas cada 60 segundos al centro de comando
Creación de archivos

Método de detección:
Análisis de comportamiento de red / IDS (Sistema de Detección de Intrusos)

Descripción de la Amenaza:
El proceso presenta un comportamiento de Command & Control consistente con malware de acceso remoto.
Es probable que el equipo esté intentando establecer comunicación persistente con un servidor controlado por un atacante externo.

Acciones tomadas:
Bloqueo de tráfico de red
Proceso boqueado
Creación de reglas YARA

Status:
Contenido
