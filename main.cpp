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
#include <unordered_map>
#include <ctime>
#include <chrono>
#include <bits/stdc++.h> 
#include <math.h> 

//#include "HackerRank.h"
//#include "Noticia.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "Arbol.h"

using namespace std;

class Archivo{
private:
    string dir;
    string texto;
public:
    Archivo(string dir){
        this->dir = dir;
        this->texto = "";
        
        ifstream archivo(dir);

        string linea;
        while(getline(archivo, linea)){
            this->texto += linea;
        }
    }
    
    string getTexto() const {
        return texto;
    }

};

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
 *  t = "abcd"   tamaño 4
 *  "a"         1
 *  "b"         
 *  "c"
 *  "d"         
 *  "ab"        2
 *  "bc"        
 *  "cd"        
 *  "abc"       3
 *  "bcd"
 *  "abcd"      4
***************************************/     
void agregarSubStr(Arbol* a, string t){
    int tam = t.size();
    for (int i = 1; i <= tam; i++) { // i: tamaño del sub string a generar
        for (int j = 0; i+j-1 < tam; j++)
            a->insertarHijo(t.substr(j, i));
    }
}

void pruebaQuickSort_log(int inc, int cant){
    double_t tiempoAnt = -1;
    double_t tiempoAct;
    
    double_t logAnt = -1;
    double_t logAct;
    
    int tam = inc;
    
    cout << "QuickSort O(log(n))\nElementos   -   Tiempo   -   Log   -   Diferencia\n";
    for (int i = 0; i < cant; i++) {
        int *arr = new int[tam];
        generarArreglo(arr, tam, tam);
        
        auto inicio = chrono::steady_clock::now();
        //quickSort1_log(arr, tam, 0);
        quickSort2_log(arr, 0, tam-1);
        
        auto fin = chrono::steady_clock::now();
        auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
        
        tiempoAct = ((double_t)tiempo.count()/(double_t)1000000000);
        logAct = log(tam);
        if(tiempoAnt >= 0){
            double_t tiempoDif = abs((tiempoAct - tiempoAnt));
            double_t logDif = abs((logAct - logAnt));
            double_t dif = abs(logDif - tiempoDif);
            cout << tam-inc << " " << tam << ": " << to_string(tiempoDif);
            cout << " : " << to_string(logDif) << " : " << to_string(dif) << endl;
        }
        
        tiempoAnt = tiempoAct;
        logAnt = logAct;
        tam += inc;
    }
    cout << endl;
}

void pruebaQuickSort_NN(int inc, int cant){
    double_t tiempoAnt = -1;
    double_t tiempoAct;
    
    double_t nnAnt = -1;
    double_t nnAct;
    
    int tam = inc;
    double_t tamComp;  // tamaño para comparar el n^2
    
    cout << "QuickSort O(n^2)\nElementos   -   Tiempo   -   n^2   -   Diferencia\n";
    for (int i = 0; i < cant; i++) {
        int *arr = new int[tam];
        generarArreglo(arr, tam, tam);
        
        quickSort1_log(arr, tam, 0);
        
        auto inicio = chrono::steady_clock::now();
        quickSort2_log(arr, 0, tam-1);
        
        auto fin = chrono::steady_clock::now();
        auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
        
        tiempoAct = ((double_t)tiempo.count()/(double_t)1000000000);
        tamComp = (double_t)tam/inc;
        nnAct = tamComp*tamComp;
        if(tiempoAnt >= 0){
            double_t tiempoDif = abs((tiempoAct - tiempoAnt));
            double_t logDif = abs((nnAct - nnAnt));
            double_t dif = abs(logDif - tiempoDif);
            cout << tam-inc << " " << tam << ": " << to_string(tiempoDif);
            cout << " : " << to_string(logDif) << " : " << to_string(dif) << endl;
        }
        
        tiempoAnt = tiempoAct;
        nnAnt = nnAct;
        tam += inc;
    }
    cout << endl;
}

void pruebaInsertionSort_NN(int inc, int cant){
    double_t tiempoAnt = -1;
    double_t tiempoAct;
    
    double_t nnAnt = -1;
    double_t nnAct;
    
    int tam = inc;
    double_t tamComp;  // tamaño para comparar el n^2
    
    cout << "InsertionSort O(n^2)\nElementos   -   Tiempo   -   n^2   -   Diferencia\n";
    for (int i = 0; i < cant; i++) {
        int *arr = new int[tam];
        generarArreglo(arr, tam, tam);
        
        auto inicio = chrono::steady_clock::now();
        insertionSort(arr, tam);
        
        auto fin = chrono::steady_clock::now();
        auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
        
        tiempoAct = ((double_t)tiempo.count()/(double_t)1000000000);
        tamComp = (double_t)tam/inc;
        nnAct = tamComp*tamComp;
        
        if(tiempoAnt >= 0){
            double_t tiempoDif = abs((tiempoAct - tiempoAnt));
            double_t nnDif = abs((nnAct - nnAnt));
            double_t dif = abs(nnDif - tiempoDif);
            cout << tam-inc << " " << tam << ": " << to_string(tiempoDif);
            cout << " : " << to_string(nnDif) << " : " << to_string(dif) << endl;
        }
        
        tiempoAnt = tiempoAct;
        nnAnt = nnAct;
        tam += inc;
    }
    cout << endl;
}

void pruebaInsertionSort_N(int inc, int cant){
    double_t tiempoAnt = -1;
    double_t tiempoAct;
    
    double_t nAnt = -1;
    double_t nAct;
    
    int tam = inc;
    
    cout << "InsertionSort O(n)\nElementos   -   Tiempo   -   n   -   Diferencia\n";
    for (int i = 0; i < cant; i++) {
        int *arr = new int[tam];
        generarArreglo(arr, tam, tam);
        
        quickSort1_log(arr, tam, 0);
        
        auto inicio = chrono::steady_clock::now();
        insertionSort(arr, tam);
        
        auto fin = chrono::steady_clock::now();
        auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
        
        tiempoAct = ((double_t)tiempo.count()/(double_t)1000000000);
        nAct = (double_t)tam;
        if(tiempoAnt >= 0){
            double_t tiempoDif = abs((tiempoAct - tiempoAnt));
            double_t logDif = abs((nAct - nAnt));
            double_t dif = abs(logDif - tiempoDif);
            cout << tam-inc << " " << tam << ": " << to_string(tiempoDif);
            cout << " : " << to_string(logDif) << " : " << to_string(dif) << endl;
        }
        
        tiempoAnt = tiempoAct;
        nAnt = nAct;
        tam += inc;
    }
    cout << endl;
}

/*
 * 
 */
int main(int argc, char** argv) {
    Archivo *archivo = new Archivo("archivo.txt");
    string t = archivo->getTexto();
    string p = ".";
    
    
    Arbol* a = new Arbol(t);
    
    //agregarSubStr(a, t);
    
    char entrada;
    Nodo *nodoB;
    
    pruebaQuickSort_log(500000, 10);
    pruebaQuickSort_NN(5000, 10);
    
    pruebaInsertionSort_NN(10000, 10);
    pruebaInsertionSort_N(500000, 10);
    
    double_t tiempoAnt = 0;
    while(true){
        cout << "Arbol Binario  \nPrimera busqueda O(n) Segunda Busqueda O(Log(n))\n\n";
        cout << "1. Buscar \n";
        cout << "2. Balanceo \n";
        cout << "L. Limpiar Consola \n";
        cout << "S. Salir \n\n";

        cout << ">>> ";
        cin >> entrada;
        entrada = toupper(entrada);
        if(entrada == 'L')
            system("clear");
        else if(entrada == 'S')
            break;
        
        else if(entrada == '1'){
            cout << ">>> ";
            cin >> p;
            
            auto inicio = chrono::steady_clock::now();
            nodoB = a->buscar(p);
            auto fin = chrono::steady_clock::now();

            auto tiempo = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);
            if(nodoB != NULL)
                cout << "Aparece: " << nodoB->cant << endl;
            else
                cout << "Aparece: " << 0 << endl;
            if(tiempoAnt == 0)
                cout << "Tiempo: " + to_string((double_t)tiempo.count()/1000000000) + "s";
            else{
                cout << "Tiempo: " + to_string((double_t)tiempo.count()/1000000000) + "s\n";
                cout << "Tiempo de la Busqueda Anterior: " + to_string(tiempoAnt) + "s\n";
                cout << "Diferencia: " + to_string(abs(((double_t)tiempo.count()/1000000000) - tiempoAnt));
            }
            tiempoAnt = (double_t)tiempo.count()/1000000000;
            
            cout << "\n\n\n";
        }
        else if(entrada == '2'){
            cout << "El balanceo del arbol es de: " << a->comprobarBalanceo() << "\n\n";
        }
                
    }
    
    return 0;
}

