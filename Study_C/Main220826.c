#include <stdio.h>
#include <stdlib.h>
#include <math.h>

union 공용 {
	char ch; //1byte
	short sNum; // 8byte
	int iNum; // 4byte
};


typedef struct bit {
	//int a : 35; //4byte를 벗어나서 오류
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 7;
}BITFIELD;


//원 하나의 중심점 좌표값을 나타내는 구조체
typedef struct _Circle {
	int xPos;
	int yPos;
	int radius;
}Circle;

//원 구조체의 정보를 출력하는 함수
void print_information(Circle circle) {
	printf("원의 좌표 : (%d, %d)\n", circle.xPos, circle.yPos);
	printf("원의 반지름 : %d\n", circle.radius);
}

void change_Value(Circle* ptr1, Circle* ptr2) {
	int tmp = ptr1->xPos;
	ptr1->xPos = ptr2->xPos;
	ptr2->xPos = tmp;

	tmp = ptr1->yPos;
	ptr1->yPos = ptr2->yPos;
	ptr2->yPos = tmp;

	tmp = ptr1->radius;
	ptr1->radius = ptr2->radius;
	ptr2->radius = tmp;
}


//두 개의 Circle 구조체를 매개변수로 받아
//두 원이 곂치는지 확인하는 함수 'check_circle'
//를 완성하세요. 곂치면 1, 곂치지않으면 0을 반환
//반환해서 main에서 출력.

int check_circle(Circle circle1, Circle circle2) {
	int sum = circle1.radius + circle2.radius;
	int x = circle1.xPos - circle2.xPos;
	int y = circle1.yPos - circle2.yPos;
	double diagonal = sqrt(x * x + y * y); //대각선의 길이 = (x의 거리 제곱 + y의 거리 제곱)의 제곱근

	//반지름의 합이 두 점 사이의 거리와 같다면
	if (sum == diagonal) {
		printf("두 원이 맞닿아 있습니다.\n");
		return -1;
	}
	//두 점이 반지름 길이의 합보다 더 떨어져있다면
	else if (sum < diagonal) {
		printf("두 원이 떨어져 있습니다.\n");
		return 0;
	}
	else {
		printf("두 원이 곂쳐있습니다.\n");
		return 1;
	}
}


void Main220826() {

	union 공용 share;
	share.iNum = 0b1111111111111110111111111111111;
	printf("ch : %d\n", share.ch);
	printf("sNum : %d\n", share.sNum);
	printf("iNum : %d\n", share.iNum);

	printf("ch : %p\n", &share.ch);
	printf("sNum : %p\n", &share.sNum);
	printf("iNum : %p\n", &share.iNum);
	//공용체이기 떄문에 같은 주소를 사용함




	//BITFIELD bit = {1, 15, 255};
	//printf("a : %d\n", bit.a);
	//printf("b : %d\n", bit.b);
	//printf("c : %d\n", bit.c);
	//printf("크기 : %d\n", sizeof(bit)); 




	//Circle c1 = { 5, 13, 3 };
	//Circle c2 = { 3, 15, 5 };

	//print_information(c1);
	//print_information(c2);
	//change_Value(&c1, &c2);
	//print_information(c1);
	//print_information(c2);

	//check_circle(c1, c2);


}