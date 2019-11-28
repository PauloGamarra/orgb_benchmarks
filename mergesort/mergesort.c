#include<stdlib.h> 
#include<stdio.h> 
#include<time.h> 
#define SIZE 5000

// Combina os dois subarrays arr[l..m], arr[m+1...r]
void merge(int arr[], int l, int m, int r){ 

    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* cria arrays temporários */
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 

    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* combina os arrays temporários em arr[l..r]*/
    i = 0; // Indice inicial do primeiro subarray 
    j = 0; // Indice inicial do segundo subarray  
    k = l; // Indice inicial do merged subarray 
    while (i < n1 && j < n2){ 

        if (L[i] <= R[j]){ 

            arr[k] = L[i]; 
            i++; 
        } 
        else{ 

            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copia elementos que sobraram de L[]*/
    while (i < n1){ 

        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copia elementos que sobraram de R[]*/
    while (j < n2){ 

        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r){ 

    if (l < r){ 

        // (l+r)/2, cuidando overflow 
        int m = l+(r-l)/2; 
  
        // Sort  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
int main(){

    int i, arr[SIZE]; 
    
    srand(time(0)); 

  
    for(int i = 0; i < SIZE; i++) 
         arr[i] = rand();
    
    mergeSort(arr, 0, SIZE - 1); 

    printf("Array Size: %d", SIZE);

    return 0; 
} 

