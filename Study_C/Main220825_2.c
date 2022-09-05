#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Person {
	char name[20];
	int age;
	int* num;
	int numbers[2];
} Person;

//���������� �����ϰ� �ִ� å�� ������ �Ӽ��� ���� ����ü
typedef struct _Book {
	char title[30]; // å ����
	int price; // å�� ����
} Book;

//�������� �Ӽ����� �����ϰ� �ִ� Library��� �̸��� ����ü
// Library��� ����ü�� Lib��� �г����� ������
typedef struct Library {
	char name[30]; // �������� �̸�
	Book book[100]; //å ����ü�� �����ϴ� ����ü �迭
}Lib;


//å�� ������ �����ϴ� �Լ�
Book book_info_init() {
	Book book = { "test test", 20000 };
	return book;
}

//�������� �ִ� å ������ ���
void print_book_info(Lib library) {
	printf(" << '%s'�� �ִ� å �����Դϴ�. >> \n", library.name);
	printf("å�̸� : %s / å ����: %d\n", library.book[0].title, library.book[0].price);

}


void Main220825_2() {

	Person person = { "�̸�", 10, NULL, {1, 2} };

	Book book1 = { "C Programming test", 20000 };
	Book book2 = { "Java test", 10000 };
	Book book3 = { "C++ test", 30000 };
	Book book4 = { "python test", 25000 };

	//���� ������ ����
	Lib lib1 = { "�뱸 �߱� ������" };
	lib1.book[0] = book_info_init();
	lib1.book[1] = book2;

	Lib lib2 = { "�뱸 ���� ������" };
	lib2.book[0] = book3;
	lib2.book[1] = book4;

	print_book_info(lib1);
	print_book_info(lib2);



	//�Ʒ����� ����ü�� �ʱ�ȭ�������� ��������� ������� �ʴ� �� ������ ������ ����

	int number = 4;
	Person p1 = { "ȫ�浿", 10, &number };
	printf("Person : %d byte\n", sizeof(Person));
	printf("number : %d\n", *p1.num);
	Person* ptr = &p1;

	//*ptr.name �̰� &p1�̶�� �ּҰ� ���� ������� name�� �������� ���ϹǷ� �̷��� �ȵ�
	//�Ʒ��� �� ����� ��� ���� �����.
	printf("number : %d\n", *(*ptr).num);
	printf("number : %d\n", *ptr->num);
	printf("�̸� : %s / ���� : %d\n", p1.name, p1.age);
	printf("�̸� : %s / ���� : %d\n", (*ptr).name, (*ptr).age);
	printf("�̸� : %s / ���� : %d\n", ptr->name, ptr->age);



}