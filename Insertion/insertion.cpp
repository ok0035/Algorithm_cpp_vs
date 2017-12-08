#include<iostream>
#include<time.h>
using namespace std;

void swap(int*, int*);
void insertion(int arr[], int size);
void showResult(int arr[], int size);
void insertValue(int* arr, int toPos, int fromPos);

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

	insertion(integerArr, arrSize);

	return 0;

}

//삽입정렬
void insertion(int arr[], int size) {

	int min = arr[0];
	double startClock = clock();
	int key;

	//cout << "정렬할 데이터 : " << endl << endl;

	//showResult(arr, size);
	cout << endl;


	for (int i = 1; i < size; i++) {

		key = -1;

		for (int k = i-1; k >= 0; k--)
			if (arr[i] < arr[k]) key = k;

		if (key != -1) {
			insertValue(arr, key, i);
		}

		//showResult(arr, size);

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
