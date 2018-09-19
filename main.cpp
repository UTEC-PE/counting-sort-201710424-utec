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
    int max = (*max_element(numbers,numbers+size)) + 1;
    int countArray[max] = {};
    for (int i = 0; i < size; i++) {
      int j = numbers[i];
      countArray[j]++;
    }
    for (int i = 1; i < max;i++){
      countArray[i] = countArray[i] + countArray[i-1];
    }
    int tempArray[size];
    for (int i = 0; i < size; i++) {
      tempArray[i]=numbers[i];
    }
    for (int i = 0; i < size; i++) {
      numbers[countArray[tempArray[i]]-1]=tempArray[i];
      countArray[tempArray[i]]=countArray[tempArray[i]]-1;
    }
}
