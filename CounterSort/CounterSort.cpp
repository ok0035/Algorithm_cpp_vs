//ī���� ����
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

//����
void swap(int *a, int *b);
void showResult(int arr[], int size);
void makeRandomArr(int *base, int n, int min, int max);//min~max ������ ������ �� n���� �����
void counterSort(int *base, int n);

int main(void)
{
	int* arr = new int[20];

	srand((unsigned)time(NULL));

	makeRandomArr(arr, 20, 1, 10);//1~10 ������ ������ ���� 100�� ����
	showResult(arr, 20);//���� �� ���� ���
	counterSort(arr, 20);//��� ����
	showResult(arr, 20);//���� �� ���� ���

	delete arr;

	return 0;
}

void makeRandomArr(int *base, int n, int min, int max)
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		base[i] = rand() % (max - min + 1) + min;//min~max ������ ������ �� �߻�
	}
}

void counterSort(int *base, int size)
{
	int carr[10] = { 0 }; //���� ������ ���� �Ŀ� �ε��� ǥ�� ���
	int index;
	int value;

	int *temp = new int[size];

	for (int i = 0; i<size; i++)
	{
		index = base[i] - 1;//������ ��-1
		carr[index]++;     //������ ���� 1 ����  
	}
	for (int i = 0; i<10; i++)//������ ���� ���
	{
		cout << i+1 << " : " << carr[i] << "��" << endl;
	}

	cout << endl;

	carr[0]--;//�� ���� ������ ������ 1 ����(�� �ڿ� �ִ� 0�� ��ġ�� �ε����� �ǹ�)
	for (int i = 1; i<10; i++)
	{
		carr[i] += carr[i - 1];//�� �ڿ� �ִ� i���� ��ġ�� �ε����� ���
	}

	for (int i = size - 1; i >= 0; i--)
	{
		value = base[i] - 1;//�ε����� ����
		temp[carr[value]] = base[i]; //���� �ε��� ǥ�� �����Ͽ� ��ġ
		carr[value]--;//�ε��� ǥ�� ��� �� 1 ����
	}

	memcpy(base, temp, sizeof(int)*size);//�޸� ����

	delete temp;
}

//����
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//��� ���
void showResult(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%2d ", arr[i]);
	}
	cout << endl << endl;

}
