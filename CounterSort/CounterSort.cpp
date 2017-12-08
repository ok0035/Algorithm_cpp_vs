//카운터 정렬
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

//스왑
void swap(int *a, int *b);
void showResult(int arr[], int size);
void makeRandomArr(int *base, int n, int min, int max);//min~max 사이의 랜덤한 값 n개를 만들기
void counterSort(int *base, int n);

int main(void)
{
	int* arr = new int[20];

	srand((unsigned)time(NULL));

	makeRandomArr(arr, 20, 1, 10);//1~10 사이의 랜덤한 수를 100개 생성
	showResult(arr, 20);//정렬 전 상태 출력
	counterSort(arr, 20);//계수 정렬
	showResult(arr, 20);//정렬 후 상태 출력

	delete arr;

	return 0;
}

void makeRandomArr(int *base, int n, int min, int max)
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		base[i] = rand() % (max - min + 1) + min;//min~max 사이의 랜덤한 수 발생
	}
}

void counterSort(int *base, int size)
{
	int carr[10] = { 0 }; //돗수 분포포 세기 후에 인덱스 표로 사용
	int index;
	int value;

	int *temp = new int[size];

	for (int i = 0; i<size; i++)
	{
		index = base[i] - 1;//원소의 값-1
		carr[index]++;     //돗수의 수를 1 증가  
	}
	for (int i = 0; i<10; i++)//돗수별 개수 출력
	{
		cout << i+1 << " : " << carr[i] << "개" << endl;
	}

	cout << endl;

	carr[0]--;//맨 앞의 돗수의 개수를 1 감소(맨 뒤에 있는 0을 배치할 인덱스를 의미)
	for (int i = 1; i<10; i++)
	{
		carr[i] += carr[i - 1];//맨 뒤에 있는 i값을 배치할 인덱스를 계산
	}

	for (int i = size - 1; i >= 0; i--)
	{
		value = base[i] - 1;//인덱스를 얻어옮
		temp[carr[value]] = base[i]; //값을 인덱스 표를 참고하여 배치
		carr[value]--;//인덱스 표의 요소 값 1 감소
	}

	memcpy(base, temp, sizeof(int)*size);//메모리 복사

	delete temp;
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
		printf("%2d ", arr[i]);
	}
	cout << endl << endl;

}
