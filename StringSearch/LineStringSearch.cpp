#include<iostream>
#include<string>
using namespace std;

void searchString(char* str, char* search);

int main() {

	char* str = "asdfghjklzxcvbnmababcabababab";
	char* search;
	char buffer[30];
	search = buffer;

	cout << "�˻��� ������ �Է��ϼ��� : ";
	cin >> search;

	searchString(str, search);

}

void searchString(char* str, char* search) {
	int strSize = strlen(str);
	int searchStrSize = strlen(search);
	int searchResultCount = 0;
	string searchResult = "";

	for (int i = 0; i < (strSize - (searchStrSize-1)); i++) {
		
		int strIndex = i;
		int j = 0;
		int cnt =  0;
		int flag = 0;

		while (str[strIndex] == search[j]) {
			
			//cout << strIndex << " ";
			searchResult += str[strIndex];

			cnt++;
			j++;
			strIndex++;

			if (cnt == searchStrSize) break;
		}

		if (cnt == searchStrSize) {
			cout << searchResult << endl;
			searchResult = "";
			searchResultCount++;
		}
		else {
			searchResult = "";
			//cout << cnt << " " << searchStrSize << endl;
		}
	}

	cout << "�˻��� ���� ���� : " << searchResultCount << endl;
}
