//#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void print_time_now() {
	// 현재 날짜/시간을 저장하는 목적의 now 변수
	time_t now;
	// 현재 날짜/시간을 저장하는 구조체 t
	struct tm t;
	char buff[100];
	// time : 1970년 1월 1일 0시부터 현재까지 경과된 시간
	time(&now);
	// localtime : now시간을 구조체 t에 전달하며, 경과된 시간을 계산해서
	// 구조체 변수들에 각각 저장해주는 함수
	localtime_s(&t, &now);

	//strftime
	//buff : 날짜 정보를 생성할 문자열 배열
	//%Y: 연, %m : 달, %d : 일, %H : 시, %M : 분, %p : AM/PM, %a: 요일
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p (%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%Y", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%y", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%x", &t);
	puts(buff);

	//printf(asctime(&t));

	printf("현재 시간: %d년 %d월 %d일 %d시 %d분 %d초\n",
		t.tm_year+1900, t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}


//시간 연산 테스트
void calc_time() {
	time_t now;
	// t_now : 현재 날짜/시간을 저장하는 구조체
	// t_calc : 계산한 날짜/시간을 저장하는 구조체
	struct tm t_now, t_calc;
	time(&now); // 1970년~ 경과한 시간 저장
	localtime_s(&t_now, &now); //구조체에 날짜/시간정보 저장
	t_calc = t_now;
	t_calc.tm_mon += 5; // 현재 월 +5월 저장
	t_calc.tm_hour += 10; // 현재 시 + 1시간 저장

	mktime(&t_calc); //정확한 시간을 연산해줌. 안하면 28시 이렇게 넘어감
	printf("현재 시간: %d년 %d월 %d일 %d시 %d분 %d초\n",
		t_now.tm_year + 1900, t_now.tm_mon + 1, t_now.tm_mday, t_now.tm_hour, t_now.tm_min, t_now.tm_sec);
	printf("현재 시간: %d년 %d월 %d일 %d시 %d분 %d초\n",
		t_calc.tm_year + 1900, t_calc.tm_mon + 1, t_calc.tm_mday, t_calc.tm_hour, t_calc.tm_min, t_calc.tm_sec);


}





void Main220830() {
	//print_time_now();
	calc_time();



}

