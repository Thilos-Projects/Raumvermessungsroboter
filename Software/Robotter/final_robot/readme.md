# Setupinformationen:

* Entwicklungsboard: DOIT ESP32 DEVKIT V1

* Core Debug Level: None

* Flash Frequenzy: 80 Mhz

* Upload Speed: 921600

* Serial Monitor: 115200


# Code Architektur:

* Header Programm: es werden keine .cpp verwendet, sondern nur .h

* Interrupts: Management Über Eventssystem

* Libraries: Manuell eingebunden im libs Ordner. Gemeinsamer include durch lib_include.h


* Komponenten: Komponente wenn möglich als eigenständige Klasse -> Bsp. Motoren, Bodenabstandsmesser...

Kapselung der Komponenten in Gruppen

1. Grundkomponenten / Basics: Motoren, Bodenabstandsmesser, Ultraschallsensor, Laserentfernungsmesser, Maussensor, Akkustand, WiFi, LEDs, PIN-API, Lidar-Poty, SD Karte, Entladeschutz

2. Komponentenkombiation: Fahrwerk (1 Seite) -> Motor + Bodenabstandsmesser, Lidarsystem -> Laserentfernungsmesser + Lidar Poty + Motor, Abschaltung -> Akuustand + Entladeschutz, Debughandler -> LEDs + Serielle Schnittstelle

3. Hauptkomponenten: Fahrkontrolle --> 2 Fahrwerke + Ultraschallsensor + Maussensor, Datenkontrolle --> SD Karte, Lidarkontrolle --> Lidarsystem, API-Schnittstelle --> WiFi + Pinne 

# Code Style

* Dokumentation auf Deutsch
* Code auf Englisch