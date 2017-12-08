#include<iostream>
#include<time.h>
using namespace std;

void swap(int*, int*);
void insertion(int arr[], int size);
void showResult(int arr[], int size);
void insertValue(int* arr, int toPos, int fromPos);

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

	insertion(integerArr, arrSize);

	return 0;

}

//��������
void insertion(int arr[], int size) {

	int min = arr[0];
	double startClock = clock();
	int key;

	//cout << "������ ������ : " << endl << endl;

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
	cout << "����ð�(Clock - StartClock) : " << clock() - startClock << endl << "���ĿϷ�" << endl << endl;


}

//����
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//�ε����� �迭�� �� ����
void insertValue(int *arr, int toPos, int fromPos) {

	int temp = *(arr + (int)fromPos);

	for (int i = fromPos; i > toPos; i--)
		*(arr + (int)i) = *(arr + (int)(i - 1));

	*(arr + (int)toPos) = temp;

}

//��� ���
void showResult(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}
