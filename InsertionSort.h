/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   InsertionSort.h
 * Author: Josue Alvarez M
 *
 * Created on 24 de marzo de 2022, 20:25
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

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

#endif /* INSERTIONSORT_H */

