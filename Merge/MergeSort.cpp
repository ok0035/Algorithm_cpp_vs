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
	int LeftIndex = StartIndex; // �迭 �������� ���� �ε���
	int RightIndex = MiddleIndex; // �迭 �������� ������ �ε���
	int DestIndex = 0;

	//���ĵ� ������ŭ �޸� �Ҵ�
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

	//�޸�����
	free(Destination);
}

void MergeSort(int DataSet[], int StartIndex, int EndIndex) {
	int MiddleIndex;
	
	if (EndIndex - StartIndex < 1)
		return;

	//�������� ������ ���� �߰� ��ġ ã��
	MiddleIndex = (StartIndex + EndIndex) / 2;

	//�˰��� 1-2 ����, ��� ������
	MergeSort(DataSet, StartIndex, MiddleIndex);
	MergeSort(DataSet, MiddleIndex + 1, EndIndex);

	//����
	Merge(DataSet, StartIndex, MiddleIndex, EndIndex);
}
