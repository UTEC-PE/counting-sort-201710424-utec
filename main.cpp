#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main() {
    int numbers[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);

    return 0;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    int max = numbers[0];
    int tempArray[size]; //se crea un tempArray q sera una copia del numbers original
    //for para encontrar el valor maximo y llenar el tempArray
    for (int i = 0; i < size; i++) {
      if (max<numbers[i]) {
        max=numbers[i];
      }
      tempArray[i]=numbers[i];
    }
    max++; //se suma uno al max para trabajar mejor la creación de arrays
    int countArray[max] = {}; //se inicializa el array de conteo
    //se cuenta las apariciones de los elementos
    for (int i = 0; i < size; i++) {
      int j = numbers[i];
      countArray[j]++;
    }
    //se realiza la acomulación de las apariciones en el countArray
    for (int i = 1; i < max;i++){
      countArray[i] = countArray[i] + countArray[i-1];
    }
    //se realiza el reordenamiento teniendo como base el tempArray
    for (int i = 0; i < size; i++) {
      numbers[countArray[tempArray[i]]-1]=tempArray[i];
      countArray[tempArray[i]]=countArray[tempArray[i]]-1;
    }
}
