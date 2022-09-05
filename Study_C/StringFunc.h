#pragma once


//왼쪽 공백 제거 함수
char* StrLTrim(char* pstr);
//받아온 string자체의 왼쪽 공백이 사라지는 함수
char* LTrim(char* string);
//받아온 string의 왼쪽 공백이 사라진 새로운 문자열을 반환하는 함수
char* LTrimStr(char* string);
//오른쪽 공백 제거 함수
char* StrRTrim(char* pstr);
//양쪽 공백 제거 함수
char* StrTrim(char* pstr);
//매개변수로 받은 문자열에서 숫자들만 추출하는 함수
char* number_in_str(char* ori);
//ori문자열에서 oldChar 문자를 newChar문자로 변경하는 함수
char* StrReplace(char* ori, char oldChar, char newChar);
//ori 문자열에서 oldStr 문자열을 찾아서 newStr문자열으로 변경하는 함수
void Replace(char* ori, char* oldStr, char* newStr);
//ori문자열에서 ch문자를 제거하는 함수
char* Remove(char* ori, char ch);
//내가 원하는 문자열을 원하는 위치에 삽입하는 함수
//ori : 내가 삽입할 원래 문자열, pos : 삽입할 인덱스 위치, inStr: 삽입할 문자열
char* Insert(char* ori, int pos, char* inStr);
//왼쪽에서 내가 원하는 길이까지 문자열을 추출하는 함수
char* StrLeft(char* ori, int length);
//오른쪽에서 내가 원하는 길이까지 문자열을 추출하는 함수
char* StrRight(char* ori, int length);


