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
	printf("���� : %d\n", randNum);
	int count = 6;
	while (count > 0) {
		int ansNum;
		printf("���ڸ� �Է��ϼ��� : ");
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
			printf("����!\n");
			break;
		}
	}
	if (count == 0) {
		printf("����!\n");
	}
}

void save_day() {

	FILE* file; // ������ ������ ������
	char* fileName = "birth.txt"; //���ϸ�
	fopen_s(&file, fileName, "wt"); // write text ���� ������ ����.

	/////////���� ��¥ ����////////
	char* week[] = {"��", "��", "ȭ", "��", "��", "��", "��"};
	time_t now; //���� �ð� ������ �����ϴ� ����(��)
	struct tm t; // ��¥ ������ �����ϴ� ����ü
	time(&now); // ������� ���� �ð��� ����
	localtime_s(&t, &now); //����ü�� ��¥������ ����
	fprintf(file, "���� : %d�� %d�� %d�� %s����\n", t.tm_year+1900, t.tm_mon+1, t.tm_mday, week[t.tm_wday]);

	/////////���� ��¥ ����////////
	int year, month, day;
	//puts("���Ͽ� �ۼ��� ���� ������ �Է��ϼ��� >> ");
	printf("��(4�ڸ�) >> ");
	scanf_s("%d", &year);
	printf("��(2�ڸ�) >> ");
	scanf_s("%d", &month);
	printf("��(2�ڸ�) >> ");
	scanf_s("%d", &day);

	t.tm_year = year - 1900;
	t.tm_mon = month - 1; // a��
	t.tm_mday = day; // b��
	mktime(&t); //��¥ ���� ���

	fprintf(file, "���� : %d�� %d�� %d�� %s����\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, week[t.tm_wday]);

	printf("'%s'������ �����Ǿ����ϴ�!\n", fileName);
	fclose(file); //������ �ݴ´�.
}

//2016���� a�� b��.
//
char* programmers(int a, int b) {
	char* week[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	//���� 4���� �����ϴ� �� ������ �Ҵ����
	char* answer = (char*)calloc(4, sizeof(char));
	// ��¥ ������ ����
	struct tm t = {NULL}; // ���� ó���� �ʱ�ȭ ���ִ°� �߿���.
	t.tm_year += 2016 - 1900;
	t.tm_mon += a - 1; // a��
	t.tm_mday += b; // b��
	mktime(&t); //��¥ ���� ���
	for (int i = 0; i < 3; i++) {
		answer[i] = week[t.tm_wday][i];
	}
	return answer;
}


void Main220831() {
	//UpDownGame();
	save_day();
	//printf("%s\n", programmers(5, 24));

	bool check2 = true; // true�� 0�� �ƴ� �ٸ� ��
	_Bool flag = false; // false�� 0

	Boolean check = True;
	if (check) {
		printf("test\n");
	}
	
	
	time_t t = time(NULL);
	printf("%lld\n", t);
	// srand�� � ���� �޾� �������� �����ְ� �Ǵµ�, ��� ���� ���� ������ �׻� ���� ���� ���� ������
	// ����, ����ؼ� ��ȭ�ϴ� �ð����� �õ尪���� �־���
	srand((unsigned int)time(NULL)); // srand(���Ѱ�)
	//�������� 100~150 ���̷� ������� ��. 100 150 ����
	int randNum = rand() % 51 + 100;
	printf("%d\n", randNum);
	

}