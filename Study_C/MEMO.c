#include<stdio.h>

void assignment1() {
	//����1 for���� ����Ͽ� "*"�� �Է� ���� ���� ��ŭ ����Ѵ�.
	int num;
	printf("1�̻� 100������ ���ڸ� �Է��ϼ��� >> ");
	scanf_s("%d", & num, sizeof(num));
	if (num < 1 || num > 100) {
		printf("�ٽ� �����ϼ���");
	}
	else {
		for (int i = 0; i < num; i++) {
			printf("*");

		}
	}
}

void assignment2() {
	//���� 2 : ��Ģ�� ������ �� �� ��⸦ ���� ������ ���̾Ƹ�带 �����.
	int num; //�Է¹��� ����
	printf("1�̻� 100������ ���ڸ� �Է��ϼ��� >> ");
	scanf_s("%d", &num, sizeof(num));
	int new_num = num; //�Է¹��� ���ڸ� �̿��� ����
	//���� �Է¹��� ���ڰ� ���� ���̸� ��������.
	if (num < 1 || num > 100) {
		printf("�ٽ� �����ϼ���");
	}
	//�Է¹��� ���ڰ� ���� ������� ����.
	else {
		//ù ��° while�� ����. (�Է¹��� ����*2�� �� ��ŭ "*"�� ��� ��, �Է¹��� ���ڰ� 1�� �� ������ 1�� ����)
		int space = 0; // ������ ����
		while (new_num != 0) {
			int count = 0; // ���� �ٲٴ� ����
			int space_location = 0; // ������ ���� ��ġ�� ã�� ����
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
		// �� ���� while�� ����
		while (new_num != num+1) {
			int count = 0; // ���� �ٲٴ� ����
			int space_location = 0; // ������ ���� ��ġ�� ã�� ����
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