#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "StringFunc.h"
#pragma warning(disable:4996)

//왼쪽 공백 제거 함수. 실제로 왼쪽 공백을 제거한 것은 아니고 공백이 없는 주소로 간 것.
char* StrLTrim(char* pstr) {
	char* ptr = pstr;
	while (*ptr) {
		if (!isspace(*ptr)) {
			return ptr;
		}
		ptr++;
	}
	//애초에 인수로 받은 pstr이 비어있으면 while문이 실행 안됨 그럴 경우
	return (char*)"";
}

//오른쪽 공백 제거 함수. 실제로 오른쪽 공백을 제거한 것.
char* StrRTrim(char* pstr) {
	char* start = pstr;
	//pstr을 문자열에서 NULL문자까지 이동
	while (*pstr) {
		pstr++;
	}
	//NULL바로 전 문자로 이동
	pstr--;
	//NULL바로 전 문자부터 맨 첫 문자까지 이동 == 오른쪽에서 왼쪽으로 역순회
	while (pstr >= start) {
		//현재 pstr이 있는 위치가 공백문자가 아니라면
		if (!isspace(*pstr)) {
			*++pstr = '\0'; //해당 문자 다음위치에 NULL값을 집어넣는다.
			return start; //끝낸다
		}
		pstr--;
	}
	//여기까지 왔다는 것은 문자열이 전부 공백이라는 뜻
	//빈문자열의 주소를 return
	return (char*)"";
}

//양쪽 공백 제거 함수
char* StrTrim(char* pstr) {
	char* ptr = StrLTrim(pstr);
	return StrRTrim(ptr);
}

//받아온 string자체의 왼쪽 공백이 사라지는 함수
char* LTrim(char* string) {
	int index = 0;
	for (int i = 0; i < 20; i++) {
		//if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t') {
		if (!isspace(string[i])) {
			index = i;
			break;
		}
	}
	for (int i = index; i < 20; i++) {
		string[i - index] = string[i];
	}
	return string;
}

//받아온 string의 왼쪽 공백이 사라진 새로운 문자열을 반환하는 함수
char* LTrimStr(char* string) {
	int index = 0;
	for (int i = 0; i < 20; i++) {
		//if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t') {
		if (!isspace (string[i])) {
			index = i;
			break;
		}
	}
	char* newString = (char*)calloc(strlen(string) - index + 1, sizeof(char));
	for (int i = index; i < 20; i++) {
		newString[i - index] = string[i];
	}
	return newString;
}

//매개변수로 받은 문자열에서 숫자들만 추출하는 함수
char* number_in_str(char* ori) {
	char* str = (char*)malloc(sizeof(ori));
	char* pstr = str;
	//original(원래 문자열)의 NULL문자까지 이동하면서 반복
	while (*ori) {
		if (isdigit(*ori)) { // original 문자열에서 현재 보고있는 숫자가 숫자인가?
			*pstr++ = *ori; //*str이 아니라 *pstr을 사용하는 이유 => *str로 하면 NULL값을 반환하는 건 알겠는데 왜?
		}
		ori++; //original 이동
	}
	//마지막에 NULL문자 삽입
	*pstr = '\0';
	//숫자만 저장한 문자열의 시작 주소를 return
	return str;
}


//ori문자열에서 oldChar 문자를 newChar문자로 변경하는 함수
char* StrReplace(char* ori, char oldChar, char newChar) {
	//newS는 ori문자열에서 문자가 변경된 새로운 문자열
	char* newS = (char*)calloc(strlen(ori) + 1, sizeof(char));
	char* pstr = newS; //newS의 시작주소를 저장하는 포인터변수 pstr;

	while (*ori) {
		if (*ori == oldChar) { //만약 현재 문자가 내가 변경하고 싶은 문자라고 한다면
			//새로운 문자열에게 변경할 문자를 넣어줌
			*newS += newChar;
		}
		else { // 변경하고 싶은 문자가 아니라면 새로운 문자열에게 그대로 넣어준다.
			*newS = *ori;
		}
		newS++;
		ori++;
	}

	//새로 만든(안의 내용은 변경됨) 문자열의 시작주소를 반환
	return pstr;
}

//ori 문자열에서 oldStr 문자열을 찾아서 newStr문자열으로 변경하는 함수
void Replace(char* ori, char* oldStr, char* newStr) {
	char* pstr = ori;
	char* pstrOld = strdup(ori);
	//char* pstrOld = (char*)malloc(sizeof(char) * 100);
	//char* pstrOldFree = pstrOld; // free()를 위한 포인터 저장
	////문자열을 위한 메모리 할당. 내부적으로 malloc을 사용함. => free에 의해 해제되어야 함
	//while (*ori) {
	//   *pstrOld = *ori;
	//   ori++;
	//   pstrOld++;
	//}
	//pstrOld = pstrOldFree;
	char* pos = strstr(pstrOld, oldStr); // 바꿀 대상(문자열) 위치 검색

	// NULL 문자가 나올 때까지 반복
	while (pos) {
		//pstrOld(기존문자열)를 변경할 문자열이 나오기 전 위치까지 pstr(빈 공간)에 복사
		//변경할 문자열의 위치에 NULL문자를 대입
		strncpy(pstr, pstrOld, pos - pstrOld);
		*(pstr + (pos - pstrOld)) = '\0';
		//pstr의 위치에 newStr(변경할문자열)을 연결한다
		//pstr의 위치를 마지막 위치로 이동한다.
		strcat(pstr, newStr);
		pstr = pstr + (pos - pstrOld) + strlen(newStr);

		//다음으로 일치하는 문자열을 검색하기 위해 pstrOld포인터 위치를 변경
		//pstrOld위치부터 변경할 문자열을 재검색해서 위치를 받아옴
		pstrOld = pos + strlen(oldStr);
		pos = strstr(pstrOld, oldStr);

		//만약 더 이상 일치하는 문자열이 없다면
		if (pos == NULL) {
			strcat(pstr, pstrOld);
		}
	}
	// 할당받은 메모리를 해제한다.
	//free(pstrOldFree);
}


//ori문자열에서 ch문자를 제거하는 함수
char* Remove(char* ori, char ch) {
	char* pstr = ori; //원래 문자열의 시작주소 저장
	char* pstrOld = strdup(ori); // 문자열 복사 (힙 영역)
	char* pstrNew; //새로운 문자열

	//pstrOld(복사된 문자열)에서 ch문자를 찾아서 그 위치로 이동
	pstrNew = strchr(pstrOld, ch);

	while (pstrNew) {
		//pstr에 pstrOld의 찾은 문자 앞까지 복사한다.
		strncpy(pstr, pstrOld, pstrNew - pstrOld);
		//마지막에 NULL 삽입
		*(pstr + (pstrNew - pstrOld)) = '\0';
		//pstr은 NULL으로 이동해서 다음 문자열을 더할 수 있도록 대기
		pstr += pstrNew - pstrOld;

		//기존 문자열에서 내가 찾은 문자(ch) 앞 문자로 이동
		pstrOld = pstrNew + 1;
		// 기존 남은 문자열에서 뒷부분에 ch가 있는지 검사해서 이동함
		pstrNew = strchr(pstrOld, ch);
		//만약 남은 부분에서 ch를 검색했는데 없었다면
		if (pstrNew == NULL) {
			//남은 부분 전부를 pstr에 복사하고 끝낸다.
			strcat(pstr, pstrOld);
		}
	}
	//여기까지 왔다는 것은 (while문 종료) ch문이 더 이상 발견되지 않았다는 뜻
	printf("제거된 ori : %s", ori);
	return ori;
}


//내가 원하는 문자열을 원하는 위치에 삽입하는 함수
//ori : 내가 삽입할 원래 문자열, pos : 삽입할 인덱스 위치, inStr: 삽입할 문자열
char* Insert(char* ori, int pos, char* inStr) {
	//원래 문자열을 복사해서 시작위치를 저장
	char* pstr = strdup(ori);
	//pos위치까지의 문자열을 ori에 복사한다.
	strncpy(ori, pstr, pos);
	ori[pos] = '\0';

	//realloc을 해줘야 함. ori에 inStr을 이어주면 다시 용량이 늘어나니까.

	//원래 문자열에 삽입할 문자열을 이어준다.
	strcat(ori, inStr);
	//남은 부분을 전부 ori에 이어준다.
	strcat(ori, pstr + pos);
	return ori;
}



//왼쪽에서 내가 원하는 길이까지 문자열을 추출하는 함수
char* StrLeft(char* ori, int length) {
	//원래 문자열의 길이를 구한다.
	int oriLength = strlen(ori);
	//추출하고 싶은 문자열 길이가 0 이하거나 원래 문자열 길이보다 길다면
	if (length <= 0 || oriLength <= length) {
		//원래 문자열을 반환하고 끝낸다.
		return ori;
	}
	char* pstr = (char*)calloc(length + 1, sizeof(char));
	for (int i = 0; i < length; i++) {
		pstr[i] = ori[i];
	}
	return pstr;
}

//오른쪽에서 내가 원하는 길이까지 문자열을 추출하는 함수
char* StrRight(char* ori, int length) {
	//원래 문자열의 길이를 구한다.
	int oriLength = strlen(ori);
	//추출하고 싶은 문자열 길이가 0 이하거나 원래 문자열 길이보다 길다면
	if (length <= 0 || oriLength <= length) {
		//원래 문자열을 반환하고 끝낸다.
		return ori;
	}

	//아래는 원래 strdup()이 할 일인데 그냥 풀어서 하면 이렇게 됨.
	char* pstr = (char*)calloc(length + 1, sizeof(char));
	for (int i = 0; i < oriLength - length; i++) {
		//pstr[0] = ori[10 - 4 + 0 = 6]
		//pstr[1] = ori[7]
		//pstr[2] = ori[8] ... 반복
		pstr[i] = ori[oriLength - length + i];
	}


	return pstr;
}


//테스트용 메인
void StringFuncMain() {


	//char* result = StrRight("Left Right", 4);
	//printf("result:%s", result);


	//char* result = StrLeft("Left Right", 4);
	//printf("result:%s", result);


	////특정 위치에 삽입 테스트
	//char string[100] = "This is [] test";
	//Insert(string, 9, "insert");
	//printf("삽입된 문자열 : %s", string);


	//문자열에서 문자 제거하기 테스트
	//char string[] = "010-1234-5678";
	//Remove(string, '-');
	////Remove(string, '-', 1); 이런 모양은 함수 내에서 카운트 변수를 만든다음 찾을 때마다 카운트를 증가시킴


	//문자열 변경하기 테스트
	//char string[100] = "app test application";
	//Replace(string, "app", "phone");
	//Replace("app test application", "app", "phone");


	//문자 변경하기 테스트
	//char * result = StrReplace("This is test", 't', 'o');
	//printf("변경된 문자열 : %s\n", result);


	//숫자만 추출하기 테스트
	//char* result = number_in_str("a5b6c7d1234");
	//printf("%s\n", result);


	//왼쪽 공백 제거 테스트
	//char string[30] = "\t\t\t\n Test String";
	//printf("변환 전의 string:%s\n", string);
	//printf("새로 만들어진 string:%s\n", LTrimStr(string)); //string이 아니라 새로 만들었음
	//printf("변환 전의 string:%s\n", string); //string은 안바뀜


	//printf("변환 후의 string:%s\n", LTrim(string)); //string 자체를 바꿈
	//printf("변환 전의 string:%s\n", string); // string 자체가 바뀜


	//char* ptr = StrLTrim(string);
	//printf("%s\n", ptr);
}

//메모리 단편화