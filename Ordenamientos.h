/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Ordenamientos.h
 * Author: Josue Alvarez M
 *
 * Created on 20 de marzo de 2022, 19:40
 */

#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

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

void insertionSort(int *arr, int tam){
    for (int i = 0; i < tam; i++) {
        int num = arr[i];
        
        int j = i-1;
        while(j >= 0 && arr[j] > num){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = num;
    }
}

void cambiar(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int quickSort2_logDividir(int arr[], int menor, int mayor)
{
    int pivote = arr[mayor];
    int i = (menor - 1);

    for (int j = menor; j <= mayor- 1; j++)
    {
        if (arr[j] > pivote)
        {
            i++;
            cambiar(&arr[i], &arr[j]);
        }
    }
    cambiar(&arr[i + 1], &arr[mayor]);
    return (i + 1);
}

void quickSort2_log(int arr[], int menor, int mayor)
{
    while (menor < mayor)
    {
        int pi = quickSort2_logDividir(arr, menor, mayor);

        if (pi - menor < mayor - pi){
            quickSort2_log(arr, menor, pi - 1);
            menor = pi + 1;
        }
        else{
            quickSort2_log(arr, pi + 1, mayor);
            mayor = pi - 1;
        }
    }
}

int quickSort1_logDividir(int *arr, int tam, int p, int posIni){
    if(tam - posIni < 2)
        return -1;
    else if(tam - posIni == 2){
        if(arr[posIni] > arr[posIni+1]){
            int aux = arr[posIni];
            arr[posIni] = arr[posIni+1];
            arr[posIni+1] = aux;
        }
        return -1;
    }
    
    int pivote = arr[p];
    
    int menor = posIni;
    int mayor = tam-1;
    
    while(menor < mayor){
        if(arr[mayor] <= pivote && arr[menor] >= pivote){
            int aux = arr[menor];
            arr[menor] = arr[mayor];
            arr[mayor] = aux;

            menor++;
            mayor--;

            continue;
        }
        if(arr[menor] < pivote)
            menor++;
        if(arr[mayor] > pivote)
            mayor--;
    }
    if(mayor == menor){
        if(arr[mayor] <= pivote)
            return mayor;
        else
            return mayor-1;
    }
    return mayor;
}

void quickSort1_logProc(int *arr, int tam, int p, int posIni, int tipo){
    int c = quickSort1_logDividir(arr, tam, p, posIni); // centro
    
    if(c > 0){
        if(tipo == 0){ // pivote fijo (en el medio)
            quickSort1_logProc(arr, c+1, posIni + (c - posIni)/2, posIni, tipo);
            quickSort1_logProc(arr, tam, c + ((tam - 1 - c)/2), c+1, tipo);
        }
    }
}

void quickSort1_log(int *arr, int tam, int tipo){
    if(tipo == 0) // pivote fijo (en el medio)
        quickSort1_logProc(arr, tam, (tam - 1)/2, 0, tipo);
}
#endif /* ORDENAMIENTOS_H */

