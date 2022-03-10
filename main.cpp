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

//#include "HackerRank.h"
//#include "Noticia.h"

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
*/

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


/*
 * 
 */
int main(int argc, char** argv) {
    /*
    vector<int> a = TripletsOpt({17, 28, 30}, {99, 28, 30});
    cout << a[0] << " " << a[1] << endl;
    
    a = TripletsOpt({5, 6, 7}, {3, 6, 10});
    cout << a[0] << " " << a[1] << "\n\n";
    
    cout << timeConversionOpt("07:05:45PM") << endl;
    cout << timeConversionOpt("12:08:37AM") << "\n\n";
    
    cout << birthdayOpt({1, 2, 1, 3, 2}, 3, 2) << endl;
    cout << birthdayOpt({4}, 4, 1) << "\n\n";
    
    minion_gameOpt("BANANA");
    minion_gameOpt("AKHDOWHDOQIIUOUIOUIOUIOAUAAIUOJDQWMDASNDOIAHJWIIOUIOAUANJKHFUIYHUWFWKJNVNJDKHIUHIKJM");
    
    cout << endl << cipherOpt(2, "1110001") << endl;
    cout << cipherOpt(3, "1110011011") << "\n\n";
     */
     
    /*
    vector<Noticia*> noticias;
    
    string fecha = "2/3/2022";
    noticias.push_back(new NoticiaPaper("Noticia Paper", fecha, "Reportero A", "archivo"));
    noticias.push_back(new NoticiaDigital("Noticia Digital", fecha, "Reportero B"));
    noticias.push_back(new NoticiaRadio("Noticia Radio",fecha, "Reportero C", "audio"));
    
    for (Noticia* n : noticias) {
        cout << n -> getInfo() << "\n\n";
    }
    */
    
    int arr[] = {10, 24, 31, 8, 15, 11, 27, 9};
    int tam = sizeof(arr) / sizeof(arr[0]);
    
    cout << buscarInt(arr, tam, 27) << "\n\n";
    
    return 0;
}

