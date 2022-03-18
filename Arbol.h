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

class Nodo{
public:
    Nodo *izq = NULL;
    Nodo *der = NULL;
    
    string str = "";
    size_t hash = NULL;
    
    int cant = 1;
};

class Arbol{
private:
    hash<string> hasher;
    
    Nodo *raiz;
    
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
            return 0;
        if(nodo->hash == hash)
            return nodo;
        
        if(nodo->hash > hash)
            return buscarAux(nodo->izq, hash);
        else
            return buscarAux(nodo->der, hash);
    }
public:
    void insertarHijo(string str){
        Nodo* n = new Nodo();
        
        n->str = str;
        n->hash = hasher(str);
        
        if(raiz != NULL)
            insertarHijo(raiz, n);
        else
            raiz = n;
    }
    
    Nodo* buscar(string str){
        return buscarAux(raiz, hasher(str));
    }
};



#endif /* ARBOL_H */

