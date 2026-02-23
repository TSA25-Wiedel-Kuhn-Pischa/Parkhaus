
/**

@brief Es wird in der Konsole ausgegeben, wie voll das Parkhaus in Prozent ist

Es wird die Anzahl der Belegten Parkplätze durch die Anazhl aller Parkplätze gerechnet und mit 100 multipliziert um einen 
Prozentwert zu erhalten. Danach wird dieser berecnete Wert Ausgegeben.

@param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
@param[in] all, Eingabe von der Anazhl aller Parkplätze 

@return Es wird eine void funktion, wodurch ein Rückgabewert nicht benötigt wird.
*/

Function Out_fullness(int occupied, int all)
(
    fullness = (occupied / all) * 100
    OUTPUT "fullness (Ausgabe des wertes der Variable) % der Parkplätze sind belegt"
)


