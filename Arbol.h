/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Josue Alvarez M
 *
 * Created on 17 de marzo de 2022, 17:05
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <string>
#include <unordered_map>

using namespace std;

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

class Nodo{
public:
    Nodo *izq = NULL;
    Nodo *der = NULL;
    
    string str = "";
    size_t hash = NULL;
    
    int cant = 1;
};

class Arbol{
public:
    Arbol(string str){
        this->texto = str;
        insertarHijo(str);
    }
    
    int comprobarBalanceo(){
        int profDer = 0;
        int profIzq = 0;
        
        if(raiz->der != NULL)
            profDer = balancearAux(raiz->der, 1);
        if(raiz->izq != NULL)
            profIzq = balancearAux(raiz->izq, 1);
        
        return profDer - profIzq;
    }
    
    void balancear(){
        int prof = comprobarBalanceo();
        while(prof > 1 || prof < -1){
            if(prof < -1)
                rotarDerecha1();
            else if(prof > 1)
                rotarIzquierda1();
            prof = comprobarBalanceo();
        }
    }
    
    void insertarHijo(string str){
        Nodo* n = new Nodo();
        
        n->str = str;
        n->hash = hasher(str);
        
        if(raiz != NULL){
            insertarHijo(raiz, n);
            balancear();
        }
        else
            raiz = n;
    }
    
    Nodo* buscar(string str){
        Nodo* n = buscarAux(raiz, hasher(str));
        
        if(n != NULL)
            return n;
        n = new Nodo();

        n->str = str;
        n->hash = hasher(str);
        n->cant = KMP(str, this->texto);

        if(raiz != NULL)
            insertarHijo(raiz, n);
        else
            raiz = n;
        
        balancear();
        
        return n;
    }
private:
    hash<string> hasher;
    
    Nodo *raiz;
    
    string texto;
    
    void rotarDerecha1(){
        Nodo *raizAnt = raiz;
        raiz = raiz->izq;

        if(raiz->der != NULL){
            raizAnt->izq = raiz->der;
        }

        raiz->der = raizAnt;
    }
    
    void rotarIzquierda1(){
        Nodo *raizAnt = raiz;
        raiz = raiz->der;

        if(raiz->izq != NULL){
            raizAnt->der = raiz->izq;
        }

        raiz->izq = raizAnt;
    }
    
    int balancearAux(Nodo* n, int prof){
        if(n->izq == NULL && n->der == NULL)
            return prof;
        
        int profDer = prof;
        int profIzq = prof;
        
        if(n->der != NULL)
            profDer = balancearAux(n->der, prof++);
        if(n->izq != NULL)
            profIzq = balancearAux(n->izq, prof++);
        
        if(profIzq > profDer)
            return profIzq;
        else
            return profDer;
    }
    
    void insertarHijo(Nodo *nodoR, Nodo *nodoN){
        if(nodoR->hash > nodoN->hash){
            if(nodoR->izq == NULL)
                nodoR->izq = nodoN;
            else
                insertarHijo(nodoR->izq, nodoN);
        }
        else if(nodoR->hash < nodoN->hash){
            if(nodoR->der == NULL)
                nodoR->der = nodoN;
            else
                insertarHijo(nodoR->der, nodoN);
        }
        else
            nodoR->cant++;
        
    }
    
    Nodo* buscarAux(Nodo *nodo, size_t hash){
        if(nodo == NULL)
            return NULL;
        if(nodo->hash == hash)
            return nodo;
        
        if(nodo->hash > hash)
            return buscarAux(nodo->izq, hash);
        else
            return buscarAux(nodo->der, hash);
    }
};

#endif /* ARBOL_H */

