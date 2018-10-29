#include <stdio.h> 
#include <stdio.h> 
#include <string.h> 
#define RANGE 255 

// Ordena um vetor de char
void countSort(char array[]) 
{ 
    // Cria o vetor final
    char output[strlen(array)]; 
  
    // Cria o vetor count 
    // para guardar a 
    // quantidade de cada letra 
    int count[RANGE + 1], i; 

    // Inicializa o vetor count
    // com valor 0
    for (i = 0; i < RANGE; ++i) {
    	count[i] = 0;  
    }
    // memset(count, 0, sizeof(count)); 
  
    // Conta a quantidade de 
    // cada letra
    for(i = 0; array[i]; ++i) {
        count[array[i]]++; 
    }

    // for (int i = 0; i < RANGE; ++i) {
    // 	printf("%d -> %d ", i, count[i]);    	
    // }
    // printf("\n");
  
    // Muda o vetor count para que  
    // passua o lugar exato de 
    // cada letra no vetor final
    for (i = 1; i <= RANGE; ++i) {
        count[i] += count[i-1]; 
        // printf("%d -> %d ", i, count[i]);
    }
  
    // Cria o vetor final com as letras ordenadas
    for (i = 0; array[i]; ++i) { 
        output[count[array[i]]-1] = array[i]; 
        count[array[i]]--; 
    } 
  
    // Copia o vetor final para o vetor original
    for (i = 0; array[i]; ++i) {
        array[i] = output[i]; 
    }
} 
  
int main() 
{ 
    char array[999];// = "413412535645747674563234";
	scanf("%s",&array);
  
    countSort(array); 
  
    printf("\nVetor ordenado\n%s\n", array); 
    return 0; 
} 

// Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
// Auxiliary Space: O(n+k)

// Points to be noted:
// 1. Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
// 2. It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
// 3. It is often used as a sub-routine to another sorting algorithm like radix sort.
// 4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
// 5. Counting sort can be extended to work for negative inputs also.