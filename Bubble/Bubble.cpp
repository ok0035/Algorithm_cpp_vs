#include<iostream>
#include<time.h>
using namespace std;

void swap(int*, int*);
void bubble(int arr[], int size);
void showResult(int arr[], int size);

int main() {

	int arrSize;

	cout << "�Է��� ���� ������ �Է��ϼ��� : ";
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

//��������
void bubble(int arr[], int size) {

	int min = arr[0];
	double startClock = clock();

	//cout << "������ ������ : " << endl << endl;

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

	cout << "����ð�(Clock - StartClock) : " << clock() - startClock << endl << "���ĿϷ�" << endl << endl;
}

//����
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//��� ���
void showResult(int arr[], int size) {

	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}