#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"StringFunc.h"
#include<ctype.h>
#pragma warning (disable : 4996)

void ����1() {

	//����1

	// 1) @�� ��ġ�� ã������
	// 2) ó������ �ش� ��ġ���� ���ڿ��� *id�� ����
	// 3) ã�� ��ġ(@�� ��ġ)+1���� ������ *addr�� ����

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


	//strtok�� �Ἥ �ϰ�ʹ�...
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


void ����2() {

	//int count = 1;
	//char s[] = "C language";
	//int index = strlen(s) - count;
	//printf("%s", &s[index]);
	//s[index] = '\0';
	//printf("%s", &s);


	//StrRight�� ī��Ʈ��ŭ ���ڿ��� ������ ����
	//Insert �Լ��� 0��° �ε����� ����ֱ�

	int count = 3;
	char c[] = "This is test";

	char* result1 = StrLeft(c, strlen(c) - count);
	char* result2 = StrRight(c, count);
	char* result3 = Insert(result1, 0, result2);
	//�޸� �Ҵ��� ����. insert�� realloc�� �ؼ� �뷮�� �÷��� ������ �������� ��

	printf("%d��ŭ ȸ�� ���: %s\n", count, result3);

}


void ����3() {

	//Replace�� ���
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
	//printf("��� : %d\n", result);

}




void ���ڿ�����Main() {

	//����1();

	//����2();//ȥ�� �����ϸ� �������� ����1�� �Բ� �����ϸ� ������ => �޸� �Ҵ� ����. insert���� realloc�� �߰��ؾ� ��

	//����3();


}

