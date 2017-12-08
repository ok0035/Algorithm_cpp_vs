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
	아래는 랜덤한 값을 받을 때 사용.
	과제를 위해 주석처리
	*/

	int arrSize;

	cout << "입력할 숫자 개수를 입력하세요 : ";
	cin >> arrSize;

	int * integerArr = new int[arrSize];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < arrSize; i++) {
		integerArr[i] = rand() % 100;
	}

	shell(integerArr, arrSize);

	//역순 데이터를 만들고 싶을 때 사용하면 됨.
	//for (int i = arrSize - 1; i >= 0; i--) {
	//	integerArr[arrSize - i -1] = i;
	//}


	return 0;

}

//쉘정렬
void shell(int arr[], int size) {

	int min = arr[0];
	int h = 0;
	double startClock = clock();

	cout << "정렬할 데이터 : " ;
	showResult(arr, size);
	cout << "N(배열사이즈) : " << size << endl;
	cout << "h(간격) : ";

	for (h = 0; h < size; h = 3 * h + 1)
		cout << h << " ";

	cout << endl << "==========================================================================" << endl <<endl;

	h = h / 3; // for문을 빠져나오면서 값이 한번 더 증가되기 때문에 나누어준다.

	while (h > 0) {
		insertion(arr, size, h); // 배열, 배열 사이즈, 간격(step)
		h = h / 3;
		cout << endl;
	}

	cout << endl;
	cout << "수행시간(Clock - StartClock) : " << clock() - startClock << endl << "정렬완료 : ";
	showResult(arr, size);


}

//삽입정렬 => 원래 삽입정렬과 다른 점은 step을 추가하여 배열을 간격에 따라 정렬 할 수 있게 만든 것입니다.
void insertion(int* arr, int size, int step) {
	int subListFlag = 0;

	for (int k = 0; k < step; k++) {

		int flag = 0;

		if (subListFlag == 0) {
			cout << "서브리스트 / h(간격) = " << step << endl << endl;
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

			//i보다 index가 낮은 값들 중에 i보다 큰 값을 찾고 index를 저장합니다.
			for (int k = i - step; k >= 0; k -= step)
				if (arr[i] < arr[k]) key = k;

			//만약 -1이라면 i보다 큰 값이 없는 것이므로 삽입할 필요가 없습니다.
			if (key != -1) {
				cout << "   ==>>   (a[" << i << "] = " << arr[i] << ") => (a[" << key << "] = " << arr[key] << ")" << endl;
				insertStepValue(arr, key, i, step);
				
			}
			
		}
		
	}

	//결과 출력 함수입니다.
	cout << endl;
	showResult(arr, size);

}

//스왑
void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

//인덱스로 배열에 값 삽입 => fromPos에 있는 값을 toPos로 넣어줍니다.
void insertValue(int *arr, int toPos, int fromPos) {

	int temp = *(arr + (int)fromPos);

	//fromPos에 있던 원래 값을 temp에 저장했으므로 그 공간을 앞의 값들로 채워줍니다.
	for (int i = fromPos; i > toPos; i--)
		*(arr + (int)i) = *(arr + (int)(i - 1));

	//fromPos가 있는 곳으로 한칸씩 밀렸기 때문에 toPos에 fromPos에 있던 값을 넣어줍니다.
	*(arr + (int)toPos) = temp;

}

//쉘 정렬에서 사용하는 함수로 insertValue에서 step 매개변수를 추가하였습니다.
void insertStepValue(int *arr, int toPos, int fromPos, int step) {

	int temp = *(arr + (int)fromPos);

	//fromPos에 있던 원래 값을 temp에 저장했으므로 그 공간을 앞의 값들로 채워줍니다.
	for (int i = fromPos; i > toPos; i-=step)
		*(arr + (int)i) = *(arr + (int)(i - step));

	//fromPos가 있는 곳으로 한칸씩 밀렸기 때문에 toPos에 fromPos에 있던 값을 넣어줍니다.
	*(arr + (int)toPos) = temp;

}

//결과 출력
void showResult(int arr[], int size) {

	cout << "a[i] : ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

}
