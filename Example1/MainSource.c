
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#pragma warning(disable:4996)

//�Լ�
//1. �⺻ - ��ȯ��(void) �Ű����� (x)

void func1() {
	for (int i = 0; i < 100; i++) {
		printf("t");
	}
	printf("\n");
}

//���� 2 - ��ȯ��(void) �Ű����� (o)
void func2(int a, int b) {
	//�������� : �Լ� �ȿ��� ������� �Ϲ� ������...
	printf("%d %d\n", a, b);
}

//���� 3 - ��ȯ��(void�� �ƴ�) �Ű����� (x)
char* print_c() {
	char* a = malloc(3);
	return a;
}

//���� 4 - ��ȯ��(void�� �ƴ�) �Ű����� (o)
int func4(int a, int b) {
	return a + b;
}


void func5(char* c /*char c[]*/) {

	//���ڿ� �޴� ����� �� ������.
	// 
	//char c[];
	//char* a;

	printf("%s\n", c);

}



void main() {
	//func1();
	//func2('a', 'b');
	//func2(1, 2);
	//char* c = print_c();
	//free(c);
	//func4(1, 2);
	func5("test");
	char c[] = "test";
	char* ptr = &c[0];
	*ptr = 'A';
	ptr++;
	*ptr = 'a';
	printf("%s\n", ptr);

	*(ptr + 1) = 'a';
	printf("%s\n", ptr);

	func5(c);

}

