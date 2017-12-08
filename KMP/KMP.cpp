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

	cout << "검색할 내용을 입력하세요 : ";
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
			cout << "발견" << flag << endl;
			cout << "=============================================================================" << endl;
			//printf("패턴 : %s", &preFix);
			break;
		}
		else if (preEnd <= 1 || sufStart > halfSize) {
			flag = 1;
			cout << "결과없음" << endl;
			cout << "=============================================================================" << endl;
			break;
		}
		else {
			preEnd--;
			sufFix++;
			preFix = "";
			sufFix = "";
			cout << "다음 단계로" << endl;

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
			cout << "일치하는 검색 결과 찾음 : " << searchResult << endl;
			searchResult = "";
			searchResultCount++;
		}
		else {
			cout << searchResult.c_str() << endl;
			pa = getPattern(searchResult.c_str());
			cout << "패턴과 패턴 사이 : " << pa << endl;
			searchResult = "";
			//cout << cnt << " " << searchStrSize << endl;
		}

		i += pa;
		//cout << pa;
	}

	cout << "검색된 패턴 갯수 : " << searchResultCount << endl;
}
