#include <iostream>
#include <utility>
#include <sstream>
using namespace std;

bool read(double* array,  int size) {
  string mas;
  getline(cin, mas);
  istringstream stream(mas);
  for (int i = 0; i < size; i++) {
    if (!(stream >> array[i])) {
      return false;
    }
  }
  return true;
}
void shiftdown(double* array, int m, int size) {
  while (m <= size) {
    int l = 2 * m + 1;
    int r = 2 * m + 2;
    int maxchild = m;

    if (l <= size && array[l] > array[maxchild]) {
      maxchild = l;
    }
    if (r <= size && array[r] > array[maxchild]) {
      maxchild = r;
    }

    if (array[m]<array[maxchild]) {
      swap(array[m], array[maxchild]);
      m = maxchild;
     
    } else break;
  }
}
void heapSort(double* array, int size) {
  for (int m = (size / 2 - 1); m >= 0; m--) {
    shiftdown(array, m, size);
  }
  for (int m = size; m >= 1; m--) {
    swap(array[m], array[0]);
    shiftdown(array, 0, m-1); 
  }
}

void print_array(double* array, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
}
int main() {
  int size;
  string string;
  getline(cin, string);
  istringstream stream(string);
  if (!(stream >> size && (size > 0))) {
    cout << "An error has occured while reading numbers from line";
    return -1;
  }
  double* array = new double[size];
  if (read(array, size)) {
    heapSort(array, size - 1);
    print_array(array, size);

  }

  else {
    cout << "An error has occured while reading numbers from line";
  }
  delete[] array;
}
