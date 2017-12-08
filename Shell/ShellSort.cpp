#include<iostream>
#include<time.h>
#include<string>

using namespace std;

void swap(int*, int*);
void insertion(int* arr, int size, int step);
void shell(int arr[], int size);
void showResult(int arr[], int size);
void insertValue(int* arr, int toPos, int fromPos);
void insertStepValue(int *arr, int toPos, int fromPos, int step);

int main() {

	//int arrSize = 15;

	//int * integerArr = new int[arrSize] { 3, 14, 12, 4, 10, 13, 15, 5, 2, 7, 9, 6, 8, 11, 1 };

	//cout << endl;

	//shell(integerArr, arrSize);

	/*
	�Ʒ��� ������ ���� ���� �� ���.
	������ ���� �ּ�ó��
	*/

	int arrSize;

	cout << "�Է��� ���� ������ �Է��ϼ��� : ";
	cin >> arrSize;

	int * integerArr = new int[arrSize];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < arrSize; i++) {
		integerArr[i] = rand() % 100;
	}

	shell(integerArr, arrSize);

	//���� �����͸� ����� ���� �� ����ϸ� ��.
	//for (int i = arrSize - 1; i >= 0; i--) {
	//	integerArr[arrSize - i -1] = i;
	//}


	return 0;

}

//������
void shell(int arr[], int size) {

	int min = arr[0];
	int h = 0;
	double startClock = clock();

	cout << "������ ������ : " ;
	showResult(arr, size);
	cout << "N(�迭������) : " << size << endl;
	cout << "h(����) : ";

	for (h = 0; h < size; h = 3 * h + 1)
		cout << h << " ";

	cout << endl << "==========================================================================" << endl <<endl;

	h = h / 3; // for���� ���������鼭 ���� �ѹ� �� �����Ǳ� ������ �������ش�.

	while (h > 0) {
		insertion(arr, size, h); // �迭, �迭 ������, ����(step)
		h = h / 3;
		cout << endl;
	}

	cout << endl;
	cout << "����ð�(Clock - StartClock) : " << clock() - startClock << endl << "���ĿϷ� : ";
	showResult(arr, size);


}

//�������� => ���� �������İ� �ٸ� ���� step�� �߰��Ͽ� �迭�� ���ݿ� ���� ���� �� �� �ְ� ���� ���Դϴ�.
void insertion(int* arr, int size, int step) {
	int subListFlag = 0;

	for (int k = 0; k < step; k++) {

		int flag = 0;

		if (subListFlag == 0) {
			cout << "���긮��Ʈ / h(����) = " << step << endl << endl;
			subListFlag = 1;
		}

		for (int i = k; i < size; i += step) {
			if (i == k && (i + step) >= size) continue;
			else {
				cout << arr[i] << " ";
				flag = 1;
			}
		}

		if (flag == 1) cout << endl;

		for (int i = k; i < size; i += step) {

			int key = -1;

			//i���� index�� ���� ���� �߿� i���� ū ���� ã�� index�� �����մϴ�.
			for (int k = i - step; k >= 0; k -= step)
				if (arr[i] < arr[k]) key = k;

			//���� -1�̶�� i���� ū ���� ���� ���̹Ƿ� ������ �ʿ䰡 �����ϴ�.
			if (key != -1) {
				cout << "   ==>>   (a[" << i << "] = " << arr[i] << ") => (a[" << key << "] = " << arr[key] << ")" << endl;
				insertStepValue(arr, key, i, step);
				
			}
			
		}
		
	}

	//��� ��� �Լ��Դϴ�.
	cout << endl;
	showResult(arr, size);

}

//����
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//�ε����� �迭�� �� ���� => fromPos�� �ִ� ���� toPos�� �־��ݴϴ�.
void insertValue(int *arr, int toPos, int fromPos) {

	int temp = *(arr + (int)fromPos);

	//fromPos�� �ִ� ���� ���� temp�� ���������Ƿ� �� ������ ���� ����� ä���ݴϴ�.
	for (int i = fromPos; i > toPos; i--)
		*(arr + (int)i) = *(arr + (int)(i - 1));

	//fromPos�� �ִ� ������ ��ĭ�� �зȱ� ������ toPos�� fromPos�� �ִ� ���� �־��ݴϴ�.
	*(arr + (int)toPos) = temp;

}

//�� ���Ŀ��� ����ϴ� �Լ��� insertValue���� step �Ű������� �߰��Ͽ����ϴ�.
void insertStepValue(int *arr, int toPos, int fromPos, int step) {

	int temp = *(arr + (int)fromPos);

	//fromPos�� �ִ� ���� ���� temp�� ���������Ƿ� �� ������ ���� ����� ä���ݴϴ�.
	for (int i = fromPos; i > toPos; i-=step)
		*(arr + (int)i) = *(arr + (int)(i - step));

	//fromPos�� �ִ� ������ ��ĭ�� �зȱ� ������ toPos�� fromPos�� �ִ� ���� �־��ݴϴ�.
	*(arr + (int)toPos) = temp;

}

//��� ���
void showResult(int arr[], int size) {

	cout << "a[i] : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}
