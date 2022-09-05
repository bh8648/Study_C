#include<stdio.h>

void assignment1() {
	//문제1 for문을 사용하여 "*"을 입력 받은 개수 만큼 출력한다.
	int num;
	printf("1이상 100이하의 숫자를 입력하세요 >> ");
	scanf_s("%d", & num, sizeof(num));
	if (num < 1 || num > 100) {
		printf("다시 실행하세요");
	}
	else {
		for (int i = 0; i < num; i++) {
			printf("*");

		}
	}
}

void assignment2() {
	//문제 2 : 규칙을 유추한 뒤 별 찍기를 통해 투명한 다이아몬드를 만든다.
	int num; //입력받을 숫자
	printf("1이상 100이하의 숫자를 입력하세요 >> ");
	scanf_s("%d", &num, sizeof(num));
	int new_num = num; //입력받은 숫자를 이용할 변수
	//만약 입력받은 숫자가 범위 밖이면 실행종료.
	if (num < 1 || num > 100) {
		printf("다시 실행하세요");
	}
	//입력받은 숫자가 정상 범위라면 실행.
	else {
		//첫 번째 while문 시작. (입력받은 숫자*2의 수 만큼 "*"을 출력 후, 입력받은 숫자가 1이 될 때까지 1씩 감소)
		int space = 0; // 공백의 개수
		while (new_num != 0) {
			int count = 0; // 줄을 바꾸는 변수
			int space_location = 0; // 공백을 넣을 위치를 찾는 변수
			for (int i = 0; i < new_num * 2; i++) {
				printf("*");
				count++;
				space_location++;
				if (space_location == new_num) {
					for (int i = 0; i < space; i++) {
						printf(" ");
					}
				}
				if (count == new_num * 2) {
					printf("\n");
				}
			}
			new_num--;
			space += 2;
		}
		// 두 번재 while문 시작
		while (new_num != num+1) {
			int count = 0; // 줄을 바꾸는 변수
			int space_location = 0; // 공백을 넣을 위치를 찾는 변수
			for (int i = 0; i < new_num*2; i++) {
				printf("*");
				count++;
				space_location++;
				if (space_location == new_num) {
					for (int i = 0; i < space; i++) {
						printf(" ");
					}
				}
				if (count == new_num*2) {
					printf("\n");
				}	
			}
			new_num++;
			space -= 2;
		}		
	}
}

void MEMOmain() {

	//assignment1();
	//assignment2();
	
	printf("hello");

}