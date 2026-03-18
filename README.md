# Git Projekt Parkhaus

Dieses Repository beschäftigt sich mit der Idee eine Parkhaus zu Simulieren. 
Dabei wird ermittelt, ob eine Erweiterung des Parkhauses empfohlen wird. 

Der Verwender dieser Simulation kann durch eine Eingabe der

- Anzahl der Stellplätze
- Maximalen Parkdauer
- Simulationsdauer
- Ankunftswahrsheinlichkeit neuer Fahrzeuge
- Eingabe eines Zufalls-Seeds

die Ergebnisse der Simulation beeinflussen. 

Während der Simulation, sowie zum Schluss werden die Daten ausgegeben. 

Zum Schluss wird eine Tabelle, ein Säulen- und Balkendiagramm, sowie die Maximalwerte der Simulation ausgegeben.


*IMPORTANT INFORMATION*

- Damit die Datein in Codespaces kompilieren, muss am Ende des Kompilierbefehls -lm stehen.
- Damit die Formatierung erhalten bleibt, verwenden Sie bitte keine Eingabewerte mit mehr als 8 Stellen.
- Die Endstatistik wird aufgrund von Formatierungsgründen erst ab 10 Simulationsschritten ausgegeben.

# Befehle:
- Simulation
  - Compile:  gcc -o simulate testing/simulate.c src/parameter.c src/cars.c src/parking_garage.c src/queue.c src/statistics.c -lm
  - Ausführen:  ./simulate

- Debugging / Testing
  - Compile:  gcc -o debug -DDEBUG testing/test.c testing/test_statistics.c testing/test_queue.c testing/test_parking_garage.c testing/test_cars.c src/cars.c src/parameter.c src/parking_garage.c src/queue.c src/statistics.c -lm
  - Ausführen:  ./debug
