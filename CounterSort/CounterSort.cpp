#include<iostream>
#include<time.h>
#include<memory.h>
using namespace std;

void showResult(int* arr, int size);
void countingSort(int* arr, int size, int max);
int* makeRandomArr(int size, int max);

int main() {

	int size = 20;
	int max = 10;
	int* arr;

	arr = makeRandomArr(size, max);
	countingSort(arr, size, max);

}

void countingSort(int* arr, int size, int max) {

	int index = 0;
	int* carr = new int[max] {0};
	int* temp = new int[size] {0};
	carr[0] = -1; // 1 base => 0 base

	showResult(arr, size);

	for (int i = 0; i < size; i++) {
		index = arr[i] - 1;
		carr[index]++;
	}

	for (int i = 1; i < max; i++) {
		carr[i] += carr[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		index = arr[i] - 1;

		cout << carr[index] << " ";
		temp[carr[index]] = arr[i];
		carr[index]--;

	}
	cout << endl;

	memcpy(arr, temp, sizeof(int) * size);
	showResult(arr, size);

	delete temp;

}

int * makeRandomArr(int size, int max)
{
	int* arr = new int[size] {0};
	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % max) + 1;
	}

	return arr;
}


void showResult(int* arr, int size) {
	cout << "========================================================" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "========================================================" << endl;
}
