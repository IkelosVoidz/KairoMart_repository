Respecte al programa:

IMPORTANT!! Hem fet molt poc control de eror de input es a dir si les posibles opcions son 1 2 3 o 0 i es fica un 4 petara el programa. No ens ha donat temps de implementar-ho i tampoc era 
el focus de la practica.


FUNCIONAMENT:

El nostre programa simula una cursa de forma mitjanament real . Després de definir com a mínim un concursant amb el seu vehicle  i personatge es pot aplicar un Input a cada vehicle 
que es mou n caselles depenent de la seva velocitat actual, que augmenta en 1 unitat cada torn que s’acceleri en la mateixa direcció i disminueix en 1 cada torn que es canviï de direcció.

En el cas que es canviï de direcció es preguntarà si es vol fer el gir Derrapant o girant normal 
(el resultat és el mateix, però es calcula de formes diferents). Les caselles que es mou amb el gir també depenen de la velocitat actual

A més cada vehicle té una velocitat màxima diferent
Caval : 2
Bigue : 3
Quadrigue : 4

Els vehicles poden col·lidir entre si , si això ocorre els dos vehicles involucrats en la col·lisió entraran en un estat de penalització, 
en el que no es podran moure per N torns, determinat pel seu valor de resistència

Cavall : 2
Bigue : 1
Quadrigue : 1

Els vehicles poden moure’s per les caselles del circuit marcades en 0, i 2 (els dosos representen la meta) . 
La cursa és en el sentit contrari de les agulles del rellotge , i cada vegada que es passi per la meta per la seva esquerra se sumarà 1 volta. I es restarà una volta si es passa per la dreta.

Finalment, si un Vehicle fa un total de voltes determinades per la cursa aquell vehicle guanya la cursa i s’indica a través de text.
