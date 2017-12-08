#include<iostream>
#include<time.h>
using namespace std;

void swap(int*, int*);
void insertion(int arr[], int size);
void showResult(int arr[], int size);
void insertValue(int* arr, int toPos, int fromPos);
void quick_sort(int* array, int start, int end);
void quick(int* array, int left, int right);

int main() {

	int arrSize;

	cout << "입력할 숫자 개수를 입력하세요 : ";
	cin >> arrSize;

	int * integerArr = new int[arrSize];

	srand((unsigned int)time(NULL));

	integerArr[0] = -1;
	for (int i = 1; i < arrSize; i++) {
		integerArr[i] = rand() % 100;
	}

	quick_sort(integerArr, 1, arrSize-1);
	showResult(integerArr, arrSize);

	return 0;
}

void quick_sort(int* array, int start, int end) {

	if (start >= end) return;

	int mid = (start + end) / 2;
	int pivot = array[mid];

	swap(&array[start], &array[mid]);

	int p = start + 1, q = end;

	while (1) {
		while (array[p] <= pivot) { p++; }
		while (array[q]>pivot) { q--; }

		if (p>q) break;

		swap(&array[p], &array[q]);
	}

	swap(&array[start], &array[q]);

	quick_sort(array, start, q - 1);
	quick_sort(array, q + 1, end);

}

void quick(int* array, int left, int right) {

	int i = left;
	int k = right;

}

//스왑
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//인덱스로 배열에 값 삽입
void insertValue(int *arr, int toPos, int fromPos) {

	int temp = *(arr + (int)fromPos);

	for (int i = fromPos; i > toPos; i--)
		*(arr + (int)i) = *(arr + (int)(i - 1));

	*(arr + (int)toPos) = temp;

}

//결과 출력
void showResult(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}