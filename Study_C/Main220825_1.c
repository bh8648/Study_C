#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct TestStruct {
	int test;
	double a;
};


//사람이 가질 수 있는 속성들에 대해서 정의하는 구조체
typedef struct _Person {
	char name[30]; //사람의 이름 속성에 대한 변수
	int age; // 사람의 나이 속성에 대한 변수
}Person;

//좌표 데이터에 관한 구조체
struct point { //점
	int x;
	int y;
};

//정의할 때부터 닉네임이 붙어서 정의된 구조체 
typedef struct test {
	int x;
	int y;
} TS;


void Main220825_1() {
	struct TestStruct t;
	t.test = 10;
	printf("%d\n", t.test);

	//구조체를 사용하여 실제 데이터를 생성
	Person p1;
	strcpy_s(p1.name, 9, "홍길동");
	p1.age = 10;

	//구조체를 사용하여 실제 데이터를 생성
	Person p2;
	strcpy_s(p2.name, 9, "김무무");
	p2.age = 30;

	//구조체 출력
	printf("p1의 이름 : %s\n", p1.name);
	printf("p2의 이름 : %s\n", p2.name);


	//구조체 변수 생성과 동시에 멤버변수의 값을 초기화 하는 방법
	Person p3 = { "박사장", 35 };


	//구조체들을 요소로서 저장하는 배열 p4
	//struct _Person p4[5] = {p1, p2, p3};
	struct _Person p4[5] = {
		{"테스트1", 10},
		p2,
		{"테스트3", 30}
	};

	for (int i = 0; i < 3; i++) {
		printf("이름 : %s\n", p4[i].name);
	}

	//배열을 이용한 구조체 출력
	printf("p1의 이름 : %s\n", p4[0].name);
	printf("p2의 이름 : %s\n", p4[1].name);
	printf("p3의 이름 : %s\n", p4[2].name);


	typedef int INT;
	INT number1 = 10;
	int number2 = 20;
	typedef int* PINT;
	PINT ptr = &number1;
	printf("%d\n", *ptr);

	typedef const char* String;
	String s = "test";


	// 1,3 위치를 가지는 점
	struct point point1 = { 1,3 };
	//구조체 이름 point를 POINT라는 닉네임으로 설정
	typedef struct point POINT;
	//3,5 위치를 가지는 점
	POINT point2 = { 3, 5 };

	typedef TS TTTT;
	TS test = { 1,1 };
	TTTT test2 = { 2,2 };
	struct test test3 = { 3,3 };



}


