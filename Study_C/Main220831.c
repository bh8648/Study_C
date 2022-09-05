#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0


typedef enum _Boolean {
	False = 0,
	True = 1
}Boolean;

void UpDownGame() {
	srand((unsigned int)time(NULL));
	int randNum = rand() % 101 + 150;
	printf("난수 : %d\n", randNum);
	int count = 6;
	while (count > 0) {
		int ansNum;
		printf("숫자를 입력하세요 : ");
		scanf_s("%d", & ansNum, sizeof(int));
		if (ansNum > randNum) {
			printf("down\n");
			count -= 1;
			continue;
		}
		else if (ansNum < randNum) {
			printf("up\n");
			count -= 1;
			continue;
		}
		else {
			printf("성공!\n");
			break;
		}
	}
	if (count == 0) {
		printf("실패!\n");
	}
}

void save_day() {

	FILE* file; // 저장할 파일의 포인터
	char* fileName = "birth.txt"; //파일명
	fopen_s(&file, fileName, "wt"); // write text 모드로 파일을 연다.

	/////////현재 날짜 정보////////
	char* week[] = {"일", "월", "화", "수", "목", "금", "토"};
	time_t now; //지난 시간 정보를 저장하는 정수(초)
	struct tm t; // 날짜 정보를 저장하는 구조체
	time(&now); // 현재까지 지난 시간을 저장
	localtime_s(&t, &now); //구조체에 날짜정보를 설정
	fprintf(file, "현재 : %d년 %d월 %d일 %s요일\n", t.tm_year+1900, t.tm_mon+1, t.tm_mday, week[t.tm_wday]);

	/////////생일 날짜 정보////////
	int year, month, day;
	//puts("파일에 작성할 생일 정보를 입력하세요 >> ");
	printf("년(4자리) >> ");
	scanf_s("%d", &year);
	printf("월(2자리) >> ");
	scanf_s("%d", &month);
	printf("일(2자리) >> ");
	scanf_s("%d", &day);

	t.tm_year = year - 1900;
	t.tm_mon = month - 1; // a월
	t.tm_mday = day; // b일
	mktime(&t); //날짜 정보 계산

	fprintf(file, "생일 : %d년 %d월 %d일 %s요일\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, week[t.tm_wday]);

	printf("'%s'파일이 생성되었습니다!\n", fileName);
	fclose(file); //파일을 닫는다.
}

//2016년의 a월 b일.
//
char* programmers(int a, int b) {
	char* week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	//문자 4개를 저장하는 힙 영역을 할당받음
	char* answer = (char*)calloc(4, sizeof(char));
	// 날짜 정보를 저장
	struct tm t = {NULL}; // 가장 처음에 초기화 해주는게 중요함.
	t.tm_year += 2016 - 1900;
	t.tm_mon += a - 1; // a월
	t.tm_mday += b; // b일
	mktime(&t); //날짜 정보 계산
	for (int i = 0; i < 3; i++) {
		answer[i] = week[t.tm_wday][i];
	}
	return answer;
}


void Main220831() {
	//UpDownGame();
	save_day();
	//printf("%s\n", programmers(5, 24));

	bool check2 = true; // true는 0이 아닌 다른 값
	_Bool flag = false; // false는 0

	Boolean check = True;
	if (check) {
		printf("test\n");
	}
	
	
	time_t t = time(NULL);
	printf("%lld\n", t);
	// srand는 어떤 값을 받아 랜덤값을 정해주게 되는데, 계속 같은 값을 받으면 항상 같은 랜덤 값이 정해짐
	// 따라서, 계속해서 변화하는 시간값을 시드값으로 넣어줌
	srand((unsigned int)time(NULL)); // srand(씨앗값)
	//랜덤값을 100~150 사이로 만들려고 함. 100 150 포함
	int randNum = rand() % 51 + 100;
	printf("%d\n", randNum);
	

}