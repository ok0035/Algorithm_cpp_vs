#include<iostream>
#include<string>
using namespace std;

void searchString(char* str, char* search);
int getPattern(const char* str);

int main() {

	char* str = "abcdabcdabee";
	char* search;
	char buffer[30];
	search = buffer;

	cout << "�˻��� ������ �Է��ϼ��� : ";
	cin >> search;

	//cout << strlen(search);

	searchString(str, search);

}

int getPattern(const char* str) {
	
	int halfSize = strlen(str) / 2;
	int endSize = strlen(str);
	int preEnd = halfSize;
	int sufStart = halfSize;

	char* preFix = "";
	char* sufFix = "";

	int pa = 1;
	int flag = 0;

	while (1) {

		cout << "prefix : ";
		for (int i = 0; i < preEnd; i++) {

			preFix += str[i];
			cout << str[i];
		}

		cout << endl << "sufFix : ";

		for (int j = (endSize - preEnd); j < endSize; j++) {

			sufFix += str[j];
			cout << str[j];

		}

		cout << endl;

		if (preFix == sufFix) {
			pa = strlen(preFix);
			flag = 1;
			cout << "�߰�" << flag << endl;
			cout << "=============================================================================" << endl;
			//printf("���� : %s", &preFix);
			break;
		}
		else if (preEnd <= 1 || sufStart > halfSize) {
			flag = 1;
			cout << "�������" << endl;
			cout << "=============================================================================" << endl;
			break;
		}
		else {
			preEnd--;
			sufFix++;
			preFix = "";
			sufFix = "";
			cout << "���� �ܰ��" << endl;

		}
		//cout << flag;

		if (flag == 1) break;
		
	}
	if (pa == 0) pa = 1;
	return pa;
}

void searchString(char* str, char* search) {
	int strSize = strlen(str);
	int searchStrSize = strlen(search);
	int searchResultCount = 0;

	int pa = getPattern(search);

	string searchResult = "";

	int i = 0;

	while(i < (strSize - (searchStrSize - 1)) ) {

		int strIndex = i;
		int j = 0;
		int cnt = 0;
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
			cout << "��ġ�ϴ� �˻� ��� ã�� : " << searchResult << endl;
			searchResult = "";
			searchResultCount++;
		}
		else {
			cout << searchResult.c_str() << endl;
			pa = getPattern(searchResult.c_str());
			cout << "���ϰ� ���� ���� : " << pa << endl;
			searchResult = "";
			//cout << cnt << " " << searchStrSize << endl;
		}

		i += pa;
		//cout << pa;
	}

	cout << "�˻��� ���� ���� : " << searchResultCount << endl;
}
