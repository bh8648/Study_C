#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Person {
	char name[20];
	int age;
	int* num;
	int numbers[2];
} Person;

//도서관에서 구비하고 있는 책이 가지는 속성에 대한 구조체
typedef struct _Book {
	char title[30]; // 책 제목
	int price; // 책의 가격
} Book;

//도서관의 속성들을 정의하고 있는 Library라는 이름의 구조체
// Library라는 구조체에 Lib라는 닉네임을 설정함
typedef struct Library {
	char name[30]; // 도서관의 이름
	Book book[100]; //책 구조체를 저장하는 구조체 배열
}Lib;


//책의 정보를 설정하는 함수
Book book_info_init() {
	Book book = { "test test", 20000 };
	return book;
}

//도서관에 있는 책 정보를 출력
void print_book_info(Lib library) {
	printf(" << '%s'에 있는 책 정보입니다. >> \n", library.name);
	printf("책이름 : %s / 책 가격: %d\n", library.book[0].title, library.book[0].price);

}


void Main220825_2() {

	Person person = { "이름", 10, NULL, {1, 2} };

	Book book1 = { "C Programming test", 20000 };
	Book book2 = { "Java test", 10000 };
	Book book3 = { "C++ test", 30000 };
	Book book4 = { "python test", 25000 };

	//실제 도서관 생성
	Lib lib1 = { "대구 중구 도서관" };
	lib1.book[0] = book_info_init();
	lib1.book[1] = book2;

	Lib lib2 = { "대구 동구 도서관" };
	lib2.book[0] = book3;
	lib2.book[1] = book4;

	print_book_info(lib1);
	print_book_info(lib2);



	//아래에서 구조체의 초기화되지않은 멤버변수를 사용하지 않는 한 오류는 터지지 않음

	int number = 4;
	Person p1 = { "홍길동", 10, &number };
	printf("Person : %d byte\n", sizeof(Person));
	printf("number : %d\n", *p1.num);
	Person* ptr = &p1;

	//*ptr.name 이건 &p1이라는 주소가 가진 멤버변수 name의 실제값을 말하므로 이러면 안됨
	//아래의 세 방식은 모두 같은 결과다.
	printf("number : %d\n", *(*ptr).num);
	printf("number : %d\n", *ptr->num);
	printf("이름 : %s / 나이 : %d\n", p1.name, p1.age);
	printf("이름 : %s / 나이 : %d\n", (*ptr).name, (*ptr).age);
	printf("이름 : %s / 나이 : %d\n", ptr->name, ptr->age);



}