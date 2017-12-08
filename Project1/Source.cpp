#include <iostream>
using namespace std;
const int M = 19;
const int K = 17;

void Print(int a[], int N)
{
	int k;
	for (k = 0; k < N; k++)
	{
		cout << a[k] << " ";
	}
	cout << endl;
}

void main()
{
	int i;
	int index = 0;
	int a[K] = { 1,19,5,1,18,3,8,9,14,7,5,24,1,13,16,12,5 };
	int HashTable[M];
	for (i = 0; i<M; i++)
	{
		HashTable[i] = -1;
	}
	int Hash[K];
	for (i = 0; i<K; i++)
	{
		Hash[i] = a[i] % M;
		//cout << Hash[i] << " ";
	}
	cout << endl;

	for (i = 0; i < K; i++)
	{

		if (HashTable[Hash[i]] == -1)
			HashTable[Hash[i]] = a[i];
		else {
			index = Hash[i];
			while (HashTable[index] != -1)
			{
				index++;
			}
			HashTable[index] = a[i];
		}
	}
	Print(HashTable, M);
}