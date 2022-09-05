
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#pragma warning(disable:4996)

//함수
//1. 기본 - 반환형(void) 매개변수 (x)

void func1() {
	for (int i = 0; i < 100; i++) {
		printf("t");
	}
	printf("\n");
}

//형태 2 - 반환형(void) 매개변수 (o)
void func2(int a, int b) {
	//지역변수 : 함수 안에서 만들어진 일반 변수들...
	printf("%d %d\n", a, b);
}

//형태 3 - 반환형(void가 아님) 매개변수 (x)
char* print_c() {
	char* a = malloc(3);
	return a;
}

//형태 4 - 반환형(void가 아님) 매개변수 (o)
int func4(int a, int b) {
	return a + b;
}


void func5(char* c /*char c[]*/) {

	//문자열 받는 방법은 두 가지다.
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

