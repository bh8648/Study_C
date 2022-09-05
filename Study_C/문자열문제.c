#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"StringFunc.h"
#include<ctype.h>
#pragma warning (disable : 4996)

void 문제1() {

	//문제1

	// 1) @의 위치를 찾은다음
	// 2) 처음부터 해당 위치까지 문자열을 *id에 저장
	// 3) 찾은 위치(@의 위치)+1부터 끝까지 *addr에 저장

	char c[] = "Program@koreait.com";
	char* id = c;
	char* addr = c;

	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == '@') {
			c[i] = '\0';
			addr = &c[i + 1];
			break;
		}
	}
	printf("id : %s\n", id);
	printf("addr : %s\n", addr);


	//strtok를 써서 하고싶다...
	//char* result = strtok(c, '@');
	//
	//for (int i = 0; i < 2; i++) {
	//	printf("%s.\n", result);
	//	result = strtok(NULL, '@');
	//}

	//char* id = c;
	//char* addr = strchr(c, '@');
	//addr = '\0';
	//addr++;
}


void 문제2() {

	//int count = 1;
	//char s[] = "C language";
	//int index = strlen(s) - count;
	//printf("%s", &s[index]);
	//s[index] = '\0';
	//printf("%s", &s);


	//StrRight로 카운트만큼 문자열을 추출한 다음
	//Insert 함수로 0번째 인덱스에 집어넣기

	int count = 3;
	char c[] = "This is test";

	char* result1 = StrLeft(c, strlen(c) - count);
	char* result2 = StrRight(c, count);
	char* result3 = Insert(result1, 0, result2);
	//메모리 할당의 부족. insert에 realloc을 해서 용량을 늘려도 괜찮게 만들어줘야 함

	printf("%d만큼 회전 결과: %s\n", count, result3);

}


void 문제3() {

	//Replace를 사용
	//void Replace(char* ori, char* oldStr, char* newStr);

	char c[100] = "one4sevenzero5";
	Replace(c, "one", "1");
	Replace(c, "two", "2");
	Replace(c, "three", "3");
	Replace(c, "four", "4");
	Replace(c, "five", "5");
	Replace(c, "six", "6");
	Replace(c, "seven", "7");
	Replace(c, "eight", "8");
	Replace(c, "nine", "9");
	Replace(c, "zero", "0");

	printf("%s\n", c);

	//int result = atoi("c") + 100;
	//printf("결과 : %d\n", result);

}




void 문자열문제Main() {

	//문제1();

	//문제2();//혼자 실행하면 괜찮은데 문제1과 함께 실행하면 오류뜸 => 메모리 할당 문제. insert에서 realloc을 추가해야 함

	//문제3();


}

