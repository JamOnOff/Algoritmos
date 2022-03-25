/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   HackerRank.h
 * Author: Josue Alvarez M
 *
 * Created on 2 de marzo de 2022, 18:10
 */

#ifndef HACKERRANK_H
#define HACKERRANK_H

using namespace std;

vector<int> Triplets(vector<int> a, vector<int> b){
    vector<int> puntos = {0, 0};
    
    for (int i = 0; i < 3; i++) {
        if(a[i] > b[i])
            puntos[0]++;
        else if(a[i] < b[i])
            puntos[1]++;
    }

    return puntos;
}
vector<int> TripletsOpt(vector<int> a, vector<int> b){
    int puntosA = 0;
    int puntosB = 0;
    
    int a0 = a[0];
    int a1 = a[1];
    int a2 = a[2];
    
    int b0 = b[0];
    int b1 = b[1];
    int b2 = b[2];
    
    
    int n;
    if(a0 != b0){
        n = (a0 - b0) / abs(a0 - b0); 
        puntosA += n + 1;                   
        puntosB += n - 1;                   
    }
    if(a1 != b1){
        n = (a1 - b1) / abs(a1 - b1);
        puntosA += n + 1;        
        puntosB += n - 1;
    }
    if(a2 != b2){
        n = (a2 - b2) / abs(a2 - b2);
        puntosA += n + 1;
        puntosB += n - 1;
    }
    
    return {puntosA / 2, abs(puntosB / 2)};
}

string timeConversion(string s) {
    int hora = stoi(s.substr(0, 2));
    string minYseg = s.substr(2, 6);
    
    if(s[8] == 'P' && hora < 12)
        hora += 12;
    else if(s[8] == 'A' && hora == 12)
        hora = 0;
    
    if(hora < 10)
        return '0' + to_string(hora) + minYseg;
    
    return to_string(hora) + minYseg;
}
string timeConversionOpt(string s) {
    int hora = stoi(s.substr(0, 2));
    string minYseg = s.substr(2, 6);
    
    int amOpm = (int(s[8]) - int('A'))/15; // 0: es am, 1: es pm
    
    // Son las 12am
    hora *= (amOpm + (1 - (hora/12)) + 1)/2; // 1 - (hora/12) -> 1: no son las 12, 0: son las 12
    if(hora < 12)
        hora += 12*amOpm;
   
    if(hora < 10)
        return '0' + to_string(hora) + minYseg;
    
    return to_string(hora) + minYseg;
}

int birthday(vector<int> s, int d, int m) {
    int grupos = 0;
    int suma = 0;
    int cantidad = 0;
    
    for (int i = 0; i < s.size(); i++) {
        suma = s[i];
        cantidad = 1;
        for (int j = i+1; j < s.size(); j++) {
            suma += s[j];
            cantidad++;
            
            if(suma == d && cantidad == m)
                grupos++;
            if(suma >= d || cantidad >= m)
                break;
        }
    }
    return grupos;
}
int birthdayOpt(vector<int> s, int d, int m) {
    int grupos = 0;
    int suma = 0;
    int cantidad = 0;
    
    int pos = s.size() - 1; // se recorre desde el ultimo elemento
    int posPrimero = pos; // posicion del primer valor sumado
    
    while(pos >= 0){
        suma += s[pos];
        cantidad++;
        
        if(suma == d)
            grupos += cantidad / m; // cantidad / m  1: cantidad == m 0: cantidad < m (cantidad no sera > a m)
        
        if(suma >= d || cantidad >= m){
            suma -= s[posPrimero];
            cantidad--;
            
            posPrimero--;
        }
        
        pos--;
    }
    
    return grupos;
}

void minion_game(string s){
    int puntaje[2] = {0, 0};
    
    char c;
    int pos;
    
    for (int i = 0; i < s.size(); i++) {
        c = s[i];
        pos = 1;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') // es una vocal
            pos = 0;
        
        puntaje[pos] += s.size() - i;
    }
    
    if(puntaje[0] > puntaje[1])
        cout << "Kevin " << puntaje[0] << endl;
    else if(puntaje[0] < puntaje[1])
        cout << "Stuart " << puntaje[1] << endl;
    else
        cout << "Draw" << endl;
}
void minion_gameOpt(string s){
    int puntajeK, puntajeS, posS;
    
    char c;
    
    int tam = s.size();
    
    while(posS < tam){
        c = s[posS];
        
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') // es una vocal
            puntajeK += tam - posS;
        else // es una consonante
            puntajeS += tam - posS;
        
        posS++;
    }
    
    
    if(puntajeK > puntajeS)
        cout << "Kevin " << puntajeK << endl;
    else if(puntajeK < puntajeS)
        cout << "Stuart " << puntajeS << endl;
    else
        cout << "Draw" << endl;
}

string cipherOpt(int k, string s) {
    string resultado = "";
    resultado += s[0];
    
    k--;
    int tam = s.size() - k;
    
    int pos = 1;
    int posR = 0;
    
    int b;
    while(tam > 1){
        if(k > 0){
            b = s[pos - 1] - '0';
            k--;
        }
        else{
            b = (s[pos - 1] - '0') ^ (resultado[posR] - '0');
            posR++;
        }
        
        resultado += (b ^ (s[pos] - '0')) + '0';
        
        pos++;
        tam--;
    }
    return resultado;
}

#endif /* HACKERRANK_H */

