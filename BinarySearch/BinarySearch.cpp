#include<iostream>
using namespace std;

void binarySearch(int* arr, int left, int right, int searchValue);

int main() {

	int size = 10;
	int left = 0;
	int right = 9;

	int* arr = new int[size] { 1,7,11,12,14,23,67,139,672,871 };
	int searchValue = 67;

	binarySearch(arr, left, right, searchValue);
}

void binarySearch(int* arr, int left, int right, int searchValue) {

	int key = 9;
	int endOfArr = 9;

	while (arr[key] != searchValue) {

		key /= 2;

		if (arr[key] == searchValue) break;
		else if (arr[key] < searchValue) {
			left = key;
			right = endOfArr;
			key = left + ((right - left) / 2);

		}
		else if (arr[key] > searchValue) {

			left = 0;
			right = key;
			key = left + ((right - left) / 2);
		}

	}

	cout << "SearchValue : " << arr[key] << endl;

}
