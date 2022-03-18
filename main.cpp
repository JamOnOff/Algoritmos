/* 
 * File:   main.cpp
 * Author: Josue Alvarez M
 *
 * Created on 25 de febrero de 2022, 17:32
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <array>
#include <list>
#include <random>
#include <math.h>

#include <ctime>
#include <chrono>
#include <bits/stdc++.h> 

//#include "HackerRank.h"
//#include "Noticia.h"
#include "Arbol.h"

using namespace std;

/*
void generarArreglo(int* arr, int tam, int rango){
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, rango);
    
    for (int i = 0; i < tam; i++) 
        arr[i] = distrib(gen);
}

void imprimirArreglo(int* arr, int tam){
    for (int i = 0; i < tam; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int buscarInt(int* arr, int tam, int num){
   while(tam >= 0){//n+1
       if(arr[tam] == num)//2(n+1)
           return tam + 1; // 1
       tam--; // 2(n+1)
   }
   
   return 0;
}
//f(1) = 5(n + 1) + 1 = 11
//O(c) = constante

//f(n) = 5(n + 1) + 1
//O(n) = lineal



void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

void burbuja(int *arr, int tam){
    for (int i = tam; i > 0; i--) {
        for (int j = 0; j < tam-1; j++) {
            if(arr[j] > arr[j + 1]){
                // intercambia el j con el j+1
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

*/




/**************************************
        Función agregarSubStr
 *  Separa el string entrante en todos 
 *  los posibles sub strings y los agrega al arbol.
 *  
 *  a:  Arbol a insertar los substrings.
 *  t:  Texto a insertar en el arbol.
 * 
 *  O(n^2)
 * 
 *  t = "abc"   tamaño 3
 *  "a"         1
 *  "b"         
 *  "c"         
 *  "ab"        2
 *  "bc"        
 *  "abc"       3
 * 
***************************************/     
void agregarSubStr(Arbol* a, string t){
    int tam = t.size();
    
    for (int i = 1; i <= tam; i++) { // i: tamaño del sub string a generar
        string str = "";
        for (int j = 0; j < tam; j++) {
            str += t[j]; // Agrega el char al substring 
            
            if(str.size() == i){ // Si el sub string ya tiene el tamaño i este se inserta en el albol
                a->insertarHijo(str); // inserta en el arbol
                str = str.substr(1, i); // quita el primer char del string
            }
        }
    }
}

/**************************************
              función LPS  O(n)
***************************************/          
void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i = 1;
    while (i < txt.length()){
        if(txt[i] == txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len == 0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

/**************************************
              función KMP(Knuth Morris Pratt)  O(n)
***************************************/  
int KMP(string pattern,string text){
    int cant = 0;
    
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);
    
    //O(n)
    lps_func(pattern,Lps); // This function constructs the Lps array.
    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} // If there is a match continue.
        if (j == m) { 
            cant++;
                                  // and update j as Lps of last matched character.
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  // If there is a mismatch
            if (j == 0)          // if j becomes 0 then simply increment the index i
                i++;
            else
                j = Lps[j - 1];  //Update j as Lps of last matched character
        }
    }
    
    return cant;
}


/*
 * 
 */
int main(int argc, char** argv) {
    string t = "En ciencias de la computación, un árbol binario es una estructura de datos en la cual cada nodo puede tener un hijo izquierdo y un hijo derecho. "
            "No pueden tener más de dos hijos (de ahí el nombre 'binario'). Si algún hijo tiene como referencia a null, es decir que no almacena ningún dato, "
            "entonces este es llamado un nodo externo. En el caso contrario el hijo es llamado un nodo interno. "
            "Usos comunes de los árboles binarios son los árboles binarios de búsqueda, los montículos binarios y Codificación de Huffman."
            ""
            "En ciencias de la computación, un árbol binario es una estructura de datos en la cual cada nodo puede tener un hijo izquierdo y un hijo derecho. "
            "No pueden tener más de dos hijos (de ahí el nombre 'binario'). Si algún hijo tiene como referencia a null, es decir que no almacena ningún dato, "
            "entonces este es llamado un nodo externo. En el caso contrario el hijo es llamado un nodo interno. "
            "Usos comunes de los árboles binarios son los árboles binarios de búsqueda, los montículos binarios y Codificación de Huffman."
            ""
            "En ciencias de la computación, un árbol binario es una estructura de datos en la cual cada nodo puede tener un hijo izquierdo y un hijo derecho. "
            "No pueden tener más de dos hijos (de ahí el nombre 'binario'). Si algún hijo tiene como referencia a null, es decir que no almacena ningún dato, "
            "entonces este es llamado un nodo externo. En el caso contrario el hijo es llamado un nodo interno. "
            "Usos comunes de los árboles binarios son los árboles binarios de búsqueda, los montículos binarios y Codificación de Huffman."
            ""
            "En ciencias de la computación, un árbol binario es una estructura de datos en la cual cada nodo puede tener un hijo izquierdo y un hijo derecho. "
            "No pueden tener más de dos hijos (de ahí el nombre 'binario'). Si algún hijo tiene como referencia a null, es decir que no almacena ningún dato, "
            "entonces este es llamado un nodo externo. En el caso contrario el hijo es llamado un nodo interno. "
            "Usos comunes de los árboles binarios son los árboles binarios de búsqueda, los montículos binarios y Codificación de Huffman.";
    string p = "e";
    
    Arbol* a = new Arbol();
    
    //Generar substrings e insertarlos al Arbol
    cout << "Generar substrings e insertarlas al Arbol  O(n^2 + n*log(n))\n";
    auto inicio = chrono::steady_clock::now();
    agregarSubStr(a, t);
    auto fin = chrono::steady_clock::now();
    auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
    cout << "Tiempo: " + to_string((double_t)tiempo.count()/1000000000) + "s\n\n\n";
    
    
    //Arbol Binario
    int busquedas = 100;
    Nodo *nodoB;
    cout << "Arbol Binario O(Log(n))\nBusquedas: " << busquedas << endl;
    inicio = chrono::steady_clock::now();
    for (int i = 0; i < busquedas; i++) {
        nodoB = a->buscar(p);
    }
    fin = chrono::steady_clock::now();
    
    tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
    if(nodoB != 0)
        cout << "Aparece: " << nodoB->cant << endl;
    else
        cout << "Aparece: " << 0 << endl;
    cout << "Tiempo: " + to_string((double_t)tiempo.count()/1000000000) + "s\n\n\n";
    
    
    //Algoritmo KMP(Knuth Morris Pratt)
    busquedas = 1;
    int cant;
    cout << "Algoritmo KMP(Knuth Morris Pratt) O(2n)\nBusquedas: " << busquedas << "\n";
    inicio = chrono::steady_clock::now();
    for (int i = 0; i < busquedas; i++) {
        cant = KMP(p, t);
    }
    fin = chrono::steady_clock::now();
    
    cout << "Aparece: " << cant << "\n";
    tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
    cout << "Tiempo: " + to_string((double_t)tiempo.count()/1000000000) + "s\n\n\n";
    
    return 0;
}

