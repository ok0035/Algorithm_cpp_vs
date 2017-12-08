#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void selection(int integerArr[], int arrSize);
void swap(int *a, int *b);
int minimum(int start, int end, int arr[]);

int main() {

	int arrSize;

	cin >> arrSize;

	int * integerArr =  new int[arrSize];

	//srand((unsigned int)time(NULL));

	for (int i = arrSize-1; i >= 0; i--) {
		integerArr[i] = i;
	}
	cout << endl;

	selection(integerArr, arrSize);

	return 0;
}

void selection(int integerArr[], int arrSize) {
	
	int min, minIndex;
	int isMin = 0;

	double startClock = clock();

	for (int i = 0; i < arrSize-1; i++) {

		min = integerArr[i];

		for (int k = i + 1; k < arrSize; k++) {
			if (min > integerArr[k]) {
				min = integerArr[k];
				minIndex = k;
				isMin = 1;
			}
		}

		if (isMin == 1) {
			swap(integerArr[i], integerArr[minIndex]);
			isMin = 0;
		}

	}

	//for (int m = 0; m < arrSize; m++) {
	//	cout << integerArr[m] << endl;
	//}

	cout << endl<< endl;

	cout << "수행시간(Clock - StartClock) : " << clock() - startClock << endl << endl << "정렬완료" << endl << endl;
}

//스왑
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;
	
}

//나중에 써도 좋을듯
int minimum(int start, int end, int arr[]) {

	int min = arr[start];

	for (int i = start + 1; i < end; i++) {
		if (min > arr[i]) min = arr[i];
	}
	return min;
}