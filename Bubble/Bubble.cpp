#include<iostream>
#include<time.h>
using namespace std;

void swap(int*, int*);
void bubble(int arr[], int size);
void showResult(int arr[], int size);

int main() {

	int arrSize;

	cout << "입력할 숫자 개수를 입력하세요 : ";
	cin >> arrSize;

	int * integerArr = new int[arrSize];

	//srand((unsigned int)time(NULL));

	//for (int i = 0; i < arrSize; i++) {
	//	integerArr[i] = rand() % 100;
	//}

	for (int i = arrSize - 1; i >= 0; i--) {
		integerArr[i] = i;
	}

	cout << endl;

	bubble(integerArr, arrSize);

	return 0;
}

//버블정렬
void bubble(int arr[], int size) {

	int min = arr[0];
	double startClock = clock();

	//cout << "정렬할 데이터 : " << endl << endl;

	//cout << "i = " << "0" << ", k = " << "0" << ", k+1 = " << "1" << " // ";
	//showResult(arr, size);
	//cout << endl;

	for (int i = 1; i <= size; i++) {

		for (int k = 0; k < size-1; k++) {

			if (arr[k] > arr[k + 1]) swap(arr[k], arr[k + 1]);

			//cout << "i = " << i << ", k = " << k << ", k+1 = " << k + 1 << " // ";
			//showResult(arr, size);
		}
	}

	cout << endl << endl;

	cout << "수행시간(Clock - StartClock) : " << clock() - startClock << endl << "정렬완료" << endl << endl;
}

//스왑
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//결과 출력
void showResult(int arr[], int size) {

	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}