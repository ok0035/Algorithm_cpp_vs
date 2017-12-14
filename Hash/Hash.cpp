#include<iostream>
using namespace std;

int getHash(int key, int size);
int* getHashTable();
void searchValue(int* arr, int val);
void showResult(int* arr, int size);
int hashTableSize = 19;

int main() {

	int searchVal;

	int* hashTable = getHashTable();

	cout << "검색할 값을 입력하세요 : ";
	cin >> searchVal;

	searchValue(hashTable, searchVal);

}

void searchValue(int* arr, int val) {

	int index = getHash(val, hashTableSize);

	if (arr[index] == val) {
		cout << "결과를 찾았습니다! -> HashTable[" << index << "] = " << arr[index] << "\n" << endl;
	}

	else {
		int term = 1;
		int hash = index += term;

		while (1) {
			if (hash >= hashTableSize) {
				cout << "결과 없음" << endl;
				break;
			}

			if (arr[hash] == val) {
				cout << "결과를 찾았습니다! -> HashTable[" << hash << "] = " << arr[hash] << "\n" << endl;
				break;
			}
			else {
				hash += term;
			}
		}

	}
}

int* getHashTable() {

	int valueSize = 17;
	int* hashTable = new int[hashTableSize];
	int valueArray[] = { 1, 19, 5, 1, 18, 3, 8, 9, 14, 7, 5, 24, 1, 13, 16, 12, 5 };

	for (int i = 0; i < hashTableSize; i++) {
		hashTable[i] = -1; // 초기화
	}

	for (int i = 0; i < valueSize; i++) {

		int cnt = getHash(valueArray[i], hashTableSize);

		if (hashTable[cnt] == -1) {
			hashTable[cnt] = valueArray[i];
		}
		else {
			cnt++;

			while (1) {
				if (cnt >= hashTableSize) {
					cnt -= hashTableSize;
				}

				if (hashTable[cnt] == -1) {
					hashTable[cnt] = valueArray[i];
					break;
				}
				else {
					cnt++;
				}
			}
		}
	}

	cout << "HashTable : ";
	showResult(hashTable, hashTableSize);

	return hashTable;
}

int getHash(int key, int size) {

	int hashValue = key % size;

	return hashValue;
}

void showResult(int* arr, int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}