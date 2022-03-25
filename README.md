# Algoritmos

Codigo creado en Netbeans con plugins para c++

quickSort2_log   ordena de mayor a menor
quickSort1_log   ordena de menor a mayor
insertionSort    ordena de menor a mayor

Para cada demostración se toman distintos array con un tamaño con incremento fijo (especificado por parámetro) y se muestran sus diferencias en 4 columnas:
Cantidad de Elementos - Diferencia de tiempos - Diferencia en el log, n o n^2 - Diferencia entre las diferencias

Dando a ver una clara similitud entre los incrementos de los algoritmos con los de la función a comparar.

Si el arreglo ya estaba ordenado 
quickSort tiene un comportamiento O(n^2) y insertionSort tiene un comportamiento O(n)

freetext: para cada texto a buscar realiza una busqueda O(logn) en un arbol binario balanceado, de no encontrarlo en el arbol busca en el archivo con el Algoritmo Knuth-Morris-Pratt (Knuth–Morris–Pratt algorithm) O(n) e inserta el resultado en el arbol asegurando una segunda busqueda O(logn).

Comparando la diferencia de tiempos de la primera busqueda con los de la segunda, se ve un comportamiento O(n) y luego O(logn) respectivamente.
