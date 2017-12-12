#include<iostream>
using namespace std;

void merge(int* arr, int left, int right);
void mergeSort(int* arr, int left, int right);
void showResult(int* arr, int size);

int main() {

	int* arr = new int[10]{ 334, 6, 4, 2, 3, 1, 5, 117, 12, 34 };

	mergeSort(arr, 0, 10 - 1);
	showResult(arr, 10);
}


//합치기
void merge(int* arr, int start, int end) {

	if (start < end) {

		int mid = start + ((end - start) / 2);
		int left = start;
		int right = mid + 1;
		int tempSize = end - start + 1;
		int* temp = new int[tempSize] {0};
		int i = 0;

		while (left <= mid && right <= end) {

			if (arr[left] < arr[right])
				temp[i++] = arr[left++];
			else
				temp[i++] = arr[right++];

		}

		cout << endl;

		while (left <= mid)
			temp[i++] = arr[left++];

		while (right <= end)
			temp[i++] = arr[right++];

		showResult(temp, tempSize);

		for (int i = 0; i < tempSize; i++) {
			arr[start + i] = temp[i];
		}

		delete temp;

	}

}

//나누기
void mergeSort(int* arr, int start, int end) {

	if (start >= end) return;

	int mid = start + ((end - start) / 2);

	cout << endl << "미드 : " << mid << endl;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	merge(arr, start, end);

}

void showResult(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}