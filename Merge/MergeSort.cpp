#include<iostream>
using namespace std;

void MergeSort(int DataSet[], int StartIndex, int EndIndex);
void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex);

int main() {

	int DataSet[] = { 334, 6, 4, 2, 3, 1, 5, 117, 12, 34 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	
	MergeSort(DataSet, 0, 10 - 1);

	for (int i = 0; i < 10; i++) {
		cout << DataSet[i] << " ";
	}
	cout << endl;

	return 0;
}

void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex) {

	int i;
	int LeftIndex = StartIndex; // 배열 기준점의 왼쪽 인덱스
	int RightIndex = MiddleIndex; // 배열 기준점의 오른쪽 인덱스
	int DestIndex = 0;

	//정렬될 공간만큼 메모리 할당
	int * Destination = new int[EndIndex - StartIndex + 1];

	while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex) {
		
		if (DataSet[LeftIndex] < DataSet[RightIndex]) {
			Destination[DestIndex] = DataSet[LeftIndex];
			LeftIndex++;
		}
		else {
			Destination[DestIndex] = DataSet[RightIndex];
			RightIndex++;
		}

		DestIndex++;
	}

	while (LeftIndex <= MiddleIndex)
		Destination[DestIndex++] = DataSet[LeftIndex++];

	while (RightIndex <= EndIndex)
		Destination[DestIndex++] = DataSet[RightIndex++];

	DestIndex = 0;
	for (i = StartIndex; i <= EndIndex; i++) {
		DataSet[i] = Destination[DestIndex++];
	}

	//메모리해제
	free(Destination);
}

void MergeSort(int DataSet[], int StartIndex, int EndIndex) {
	int MiddleIndex;
	
	if (EndIndex - StartIndex < 1)
		return;

	//절반으로 나누기 위해 중간 위치 찾기
	MiddleIndex = (StartIndex + EndIndex) / 2;

	//알고리즘 1-2 과정, 계속 나누기
	MergeSort(DataSet, StartIndex, MiddleIndex);
	MergeSort(DataSet, MiddleIndex + 1, EndIndex);

	//병합
	Merge(DataSet, StartIndex, MiddleIndex, EndIndex);
}
