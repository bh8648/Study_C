#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct TestStruct {
	int test;
	double a;
};


//����� ���� �� �ִ� �Ӽ��鿡 ���ؼ� �����ϴ� ����ü
typedef struct _Person {
	char name[30]; //����� �̸� �Ӽ��� ���� ����
	int age; // ����� ���� �Ӽ��� ���� ����
}Person;

//��ǥ �����Ϳ� ���� ����ü
struct point { //��
	int x;
	int y;
};

//������ ������ �г����� �پ ���ǵ� ����ü 
typedef struct test {
	int x;
	int y;
} TS;


void Main220825_1() {
	struct TestStruct t;
	t.test = 10;
	printf("%d\n", t.test);

	//����ü�� ����Ͽ� ���� �����͸� ����
	Person p1;
	strcpy_s(p1.name, 9, "ȫ�浿");
	p1.age = 10;

	//����ü�� ����Ͽ� ���� �����͸� ����
	Person p2;
	strcpy_s(p2.name, 9, "�蹫��");
	p2.age = 30;

	//����ü ���
	printf("p1�� �̸� : %s\n", p1.name);
	printf("p2�� �̸� : %s\n", p2.name);


	//����ü ���� ������ ���ÿ� ��������� ���� �ʱ�ȭ �ϴ� ���
	Person p3 = { "�ڻ���", 35 };


	//����ü���� ��ҷμ� �����ϴ� �迭 p4
	//struct _Person p4[5] = {p1, p2, p3};
	struct _Person p4[5] = {
		{"�׽�Ʈ1", 10},
		p2,
		{"�׽�Ʈ3", 30}
	};

	for (int i = 0; i < 3; i++) {
		printf("�̸� : %s\n", p4[i].name);
	}

	//�迭�� �̿��� ����ü ���
	printf("p1�� �̸� : %s\n", p4[0].name);
	printf("p2�� �̸� : %s\n", p4[1].name);
	printf("p3�� �̸� : %s\n", p4[2].name);


	typedef int INT;
	INT number1 = 10;
	int number2 = 20;
	typedef int* PINT;
	PINT ptr = &number1;
	printf("%d\n", *ptr);

	typedef const char* String;
	String s = "test";


	// 1,3 ��ġ�� ������ ��
	struct point point1 = { 1,3 };
	//����ü �̸� point�� POINT��� �г������� ����
	typedef struct point POINT;
	//3,5 ��ġ�� ������ ��
	POINT point2 = { 3, 5 };

	typedef TS TTTT;
	TS test = { 1,1 };
	TTTT test2 = { 2,2 };
	struct test test3 = { 3,3 };



}


