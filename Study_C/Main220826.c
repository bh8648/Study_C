#include <stdio.h>
#include <stdlib.h>
#include <math.h>

union ���� {
	char ch; //1byte
	short sNum; // 8byte
	int iNum; // 4byte
};


typedef struct bit {
	//int a : 35; //4byte�� ����� ����
	unsigned int a : 1;
	unsigned int b : 3;
	unsigned int c : 7;
}BITFIELD;


//�� �ϳ��� �߽��� ��ǥ���� ��Ÿ���� ����ü
typedef struct _Circle {
	int xPos;
	int yPos;
	int radius;
}Circle;

//�� ����ü�� ������ ����ϴ� �Լ�
void print_information(Circle circle) {
	printf("���� ��ǥ : (%d, %d)\n", circle.xPos, circle.yPos);
	printf("���� ������ : %d\n", circle.radius);
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


//�� ���� Circle ����ü�� �Ű������� �޾�
//�� ���� ��ġ���� Ȯ���ϴ� �Լ� 'check_circle'
//�� �ϼ��ϼ���. ��ġ�� 1, ��ġ�������� 0�� ��ȯ
//��ȯ�ؼ� main���� ���.

int check_circle(Circle circle1, Circle circle2) {
	int sum = circle1.radius + circle2.radius;
	int x = circle1.xPos - circle2.xPos;
	int y = circle1.yPos - circle2.yPos;
	double diagonal = sqrt(x * x + y * y); //�밢���� ���� = (x�� �Ÿ� ���� + y�� �Ÿ� ����)�� ������

	//�������� ���� �� �� ������ �Ÿ��� ���ٸ�
	if (sum == diagonal) {
		printf("�� ���� �´�� �ֽ��ϴ�.\n");
		return -1;
	}
	//�� ���� ������ ������ �պ��� �� �������ִٸ�
	else if (sum < diagonal) {
		printf("�� ���� ������ �ֽ��ϴ�.\n");
		return 0;
	}
	else {
		printf("�� ���� �����ֽ��ϴ�.\n");
		return 1;
	}
}


void Main220826() {

	union ���� share;
	share.iNum = 0b1111111111111110111111111111111;
	printf("ch : %d\n", share.ch);
	printf("sNum : %d\n", share.sNum);
	printf("iNum : %d\n", share.iNum);

	printf("ch : %p\n", &share.ch);
	printf("sNum : %p\n", &share.sNum);
	printf("iNum : %p\n", &share.iNum);
	//����ü�̱� ������ ���� �ּҸ� �����




	//BITFIELD bit = {1, 15, 255};
	//printf("a : %d\n", bit.a);
	//printf("b : %d\n", bit.b);
	//printf("c : %d\n", bit.c);
	//printf("ũ�� : %d\n", sizeof(bit)); 




	//Circle c1 = { 5, 13, 3 };
	//Circle c2 = { 3, 15, 5 };

	//print_information(c1);
	//print_information(c2);
	//change_Value(&c1, &c2);
	//print_information(c1);
	//print_information(c2);

	//check_circle(c1, c2);


}