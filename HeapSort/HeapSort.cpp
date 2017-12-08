#include<iostream>
using namespace std;

typedef struct Heap {
	int size;
	int * element;
}heap_t;

void heapify(heap_t * heap, int idx);
void showResult(int arr[], int size);

int main() {

	int * arr = new int[9]{ 0,6,2,8,9,4,5,9,7 };
	heap_t heap;

	heap.size = sizeof arr / sizeof arr[0];
	heap.element = arr;

	heapify(&heap, 1);

	showResult(arr, heap.size);

	return 0;
}

void heapify(heap_t * heap, int idx) {

	int temp = idx;
	int * arr = heap->element;

	if (heap->size == idx * 2) return;

	if (heap->size == idx * 2) {
		if (arr[idx] < arr[idx * 2]) temp = idx * 2;
	}
	else {
		if (arr[idx * 2] > arr[idx * 2 + 1]) {
			if (arr[idx] < arr[idx * 2])
				temp = idx * 2;
		}
		else {
			if (arr[idx] < arr[idx * 2 + 1])
				temp = idx * 2 + 1;

		}
	}

	if (temp != idx) {
		swap(&heap->element[idx], &heap->element[temp]);
		heapify(heap, temp);
	}

}

//스왑
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//결과 출력
void showResult(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}