#define _CRT_SECURE_NO_WARNNINGS
#include <stdio.h>

//열거형 (전부 대문자로 하는 것이 일반적..)
typedef enum DayOfWeek {
	SUNDAY = 0,
	MONDAY = 1
}WEEK;


typedef struct _Person {
	char name[30]; //사람의 이름 // 30byte
	unsigned int age; // 4byte
} Person;


//file은 stream이라고도 한다.
// stream의 특징 1) stream은 단방향이다.(읽거나 쓰거나.)
// 읽기 : 파일 -> 프로그램
// 쓰기 : 프로그램 -> 파일
// stream의 특징 2) queue와 같은 구조
// FIFO

//void putc_test() {
//	FILE* fp = NULL;
//	//fp = fopen("testFile", "wt");
//	//fopen_s(&fp, "..\\..\\testFile.txt", "at"); 상대경로 설정
//	//fopen_s(&fp, "C:\Users\bh864\Desktop\Study_C\Study_C\\testFile.txt", "at"); 직접경로
//	fopen_s(&fp, "testFile.txt", "at"); // 경로 설정을 안해주면 현재 위치에 파일 생성
//	//fp가 NULL이라는 것은 파일을 열지 못했다는 의미임
//	if (fp == NULL) {
//		printf("Error : 파일을 열 수 없습니다.\n");
//		return;
//	}
//	
//	printf("testFile.txt 파일을 성공적으로 열었습니다.\n");
//
//	//fp 주소의 위치(파일의 위치)에 't'라는 문자를 write
//	fputc('p', fp);
//	fputc('r', fp);
//	fputc('o', fp);
//	fputc('g', fp);
//	fputc('r', fp);
//	fputc('a', fp);
//	fputc('m', fp);
//
//	puts("문자 쓰기가 완료되었습니다.");
//}

void putc_test() {
	FILE* fp = NULL;
	//fp = fopen("testFile", "wt");
	//fopen_s(&fp, "..\\..\\testFile.txt", "at"); 상대경로 설정
	//fopen_s(&fp, "C:\Users\bh864\Desktop\Study_C\Study_C\\testFile.txt", "at"); 직접경로
	fopen_s(&fp, "testFile.txt", "rt"); // 경로 설정을 안해주면 현재 위치에 파일 생성
	//fp가 NULL이라는 것은 파일을 열지 못했다는 의미임
	if (fp == NULL) {
		printf("Error : 파일을 열 수 없습니다.\n");
		return;
	}
	printf("testFile.txt 파일을 성공적으로 열었습니다.\n");

	//char c = fgetc(fp);
	//c = fgetc(fp);
	//printf("%c", c); //fgetc*(fp)를 한 번 하면 p, 두 번 하면 r이 나옴. 끝까지 읽으려면 while문 사용

	//EOF는 end of file. 즉, 파일의 끝. 파일의 끝이면 0이 아닌 것을 반환. 파일의 끝이 아니면 0을 반환
	while (!feof(fp)) {
		printf("%d\n", feof(fp));
		printf("%c", fgetc(fp));
	}

	//파일을 닫아줌 -> 프로그램과 연결을 종료하고 할당받은 메모리를 해제. 메모리 해제를 안하면 힙영역에 할당 받은 것 처럼 메모리가 계속 남아있음
	fclose(fp);

	//puts("문자 쓰기가 완료되었습니다.");
}

//파일을 열 수 있는지 없는지 체크해서 상태를 반환하는 함수
int file_open_check(FILE** fp, const char* fileName, const char* mode) {
	fopen_s(fp, fileName, mode); // 경로 설정을 안해주면 현재 위치에 파일 생성
	//fp가 NULL이라는 것은 파일을 열지 못했다는 의미임
	if (*fp == NULL) {
		printf("Error : 파일을 열 수 없습니다.\n");
		return 0;
	}
	printf("'%s' 파일을 성공적으로 열었습니다.\n", fileName);
	return 1;
}

//파일에 문자열 쓰기 (fputs, fprintf)
void file_write_string() {
	FILE* fp = NULL;
	fopen_s(&fp, "문자열쓰기.txt", "wt");
	/*fputs("테스트 문자열입니다.\n", fp);
	char* string = "새로운 문자열입니다.";
	fprintf(fp, "%s\n", string);*/

	int a = 34;
	int b = 100;
	int sum = a + b;
	fprintf(fp, "합계 : %d\n", sum);

	//파일을 닫아줌
	fclose(fp);

}

//파일에 적힌 문자열 읽기
void file_read_string() {
	FILE* fp = NULL;
	char string[1024]; //읽은 문자열을 저장할 문자형배열
	fopen_s(&fp, "문자열쓰기.txt", "rt");
	
	while (1) {
		//한 번에 최대 1MB(1024byte)까지만 읽을 수 있음. (stack도 1MB까지만 가능)
		if (!fgets(string, 1024, fp)) { // stream에서 읽은 내용을 buffer에 저장
			if (feof(fp)) {
				break;
			}
		}
		printf(string);
	}

	//파일을 닫아줌
	fclose(fp);
}


// 두 숫자를 입력받아, 두 숫자의 합계를 파일에 저장하는 함수를 만드세요.
//그리고 해당 파일을 읽어서 내용을 전부 출력하세요.
//파일의 내용은 다음과 같이 되어야 한다.
// 입력받은 두 숫자 : 54, 100
// 두 숫자의 합계 : 154

void save_sum() {
	FILE* fp;
	fopen_s(&fp,"합계.txt", "wt");
	int a, b;
	printf("두 개의 숫자를 입력하세요 >> ");
	scanf_s("%d %d", &a, &b);
	fprintf(fp, "입력받은 두 숫자 : %d, %d\n", a, b);
	fprintf(fp, "두 숫자의 합계 : %d", a+b);

	fclose(fp);
}

//void save_sum() {
//	//파일을 여는 부분
//	FILE* fp;
//	fopen_s(&fp, "합계.txt", "wt");
//	// 두 숫자를 입력받는 부분
//	int num1, num2;// 입력받을 두 숫자.
//	puts("더할 두 숫자를 순서대로 입력하세요 >> ");
//	scanf_s("%d %d", &num1, &num2);
//	//파일에 내용을 write
//	fprintf(fp, "입력받은 두 숫자 : %d, %d\n", num1, num2);
//	fprintf(fp, "두 숫자의 합계 : %d\n", num1 + num2);
//	fclose(fp);
//}

void print_sum() {
	FILE* file;
	fopen_s(&file, "합계.txt", "rt");
	char string[1024];
	while (1) {
		if (!fgets(string, 1024, file)) {
			if (feof(file)) {
				break;
			}
		}
		printf(string);
	}
	fclose(file);
}


void file_write_binary() {
	FILE* file = NULL;
	char* fileName = "data.dat";
	//file_open_check가 1이면 성공 0이면 실패이므로 not연산을 통해 파일을 오픈 못하면 바로 리턴
	if (!file_open_check(&file, fileName, "wb")) {
		return;
	}
	int number = 2022;
	double pi = 3.141592;
	//number데이터주소의 값을, int형 크기만큼, 1개, file에 write하겠다.
	fwrite(&number, sizeof(int), 1, file);
	fwrite(&pi, sizeof(double), 1, file);
	printf("'%s' 파일 쓰기 완료\n", fileName);
	//파일닫기
	fclose(file);
}

void file_read_binary() {
	FILE* file = NULL;
	char* fileName = "data.dat";
	//file_open_check가 1이면 성공 0이면 실패이므로 not연산을 통해 파일을 오픈 못하면 바로 리턴
	if (!file_open_check(&file, fileName, "rb")) {
		return;
	}
	int inumber;
	double dnumber;
	fread(&inumber, sizeof(int), 1, file);
	fread(&dnumber, sizeof(double), 1, file);
	printf("'%s' 파일 읽기 완료\n", fileName);
	printf("inumber : %d\n", inumber);
	printf("dnumber : %lf\n", dnumber);

	//파일 닫기
	fclose(file);
}


void file_save_struct() {
	FILE* file = NULL;
	char* fileName = "person.dat"; // 파일명
	if (!file_open_check(&file, fileName, "wb")) {
		return;
	}
	//p1,p2,p3라는 각각의 구조체를 만들고 멤버변수를 초기화 시켜 줌
	Person p1 = { "KIM", 25 };
	Person p2 = { "LEE", 24 };
	Person p3 = { "PARK", 17 };

	fwrite(&p1, sizeof(Person), 1, file);
	fwrite(&p2, sizeof(Person), 1, file);
	fwrite(&p3, sizeof(Person), 1, file);

	fclose(file);
}

void file_read_struct() {
	FILE* file = NULL;
	char* fileName = "person.dat"; // 파일명
	if (!file_open_check(&file, fileName, "rb")) {
		return;
	}
	//p1이라는 구조체 데이터를 저장할 변수를 하나 만든 후 3번 반복시켜 출력
	for (int i = 1; i < 4; i++) {
		Person p1;
		fread(&p1, sizeof(Person), 1, file);
		printf("p%d의 데이터입니다.\n", i);
		printf("name : %s / age : %d\n", p1.name, p1.age);
	}

	//fwrite(&p2, sizeof(Person), 1, file);
	//fwrite(&p3, sizeof(Person), 1, file);

	fclose(file);
}

void image_copy() {
	FILE* oriFile = NULL; // 파일을 복사할 오리지널 파일
	FILE* newFile = NULL; // 붙여넣기할 파일
	//읽을 파일을(복사할 파일) rb 모드로 open
	if (!file_open_check(&oriFile, "17bfcf4970d14219b.jpg", "rb")) {
		return;
	}
	if (!file_open_check(&newFile, "New17bfcf4970d14219b.jpg", "wb")) {
		return;
	}
	//원래 파일의 끝까지 읽는다.
	while (!feof(oriFile)) {
		char c;
		//oriFile에서 1byte만큼 읽어서 c에 저장한다.
		fread(&c, 1, 1, oriFile);
		//읽은 1byte를(c) newFile에 쓴다.
		fwrite(&c, 1, 1, newFile);
	}
	puts("파일 복사가 완료되었습니다.");
	fclose(oriFile);
	fclose(newFile);
}

void Main220829() {
	
	//image_copy();


	//file_save_struct();
	//file_read_struct();


	//file_write_binary();
	//file_read_binary();

	//save_sum();
	//print_sum();
	

	//putc_test();
	//file_write_string();
	//file_read_string();


	////enum DayOfWeek week;
	//WEEK week; // 열거형 변수 week
	//week = SUNDAY;
	//int result = week + 1;
	//if (week + 1 == MONDAY) {
	//	//쓰고 싶은 내용 가능
	//}
	//printf("%d", result);


}









