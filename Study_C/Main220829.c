#define _CRT_SECURE_NO_WARNNINGS
#include <stdio.h>

//������ (���� �빮�ڷ� �ϴ� ���� �Ϲ���..)
typedef enum DayOfWeek {
	SUNDAY = 0,
	MONDAY = 1
}WEEK;


typedef struct _Person {
	char name[30]; //����� �̸� // 30byte
	unsigned int age; // 4byte
} Person;


//file�� stream�̶�� �Ѵ�.
// stream�� Ư¡ 1) stream�� �ܹ����̴�.(�аų� ���ų�.)
// �б� : ���� -> ���α׷�
// ���� : ���α׷� -> ����
// stream�� Ư¡ 2) queue�� ���� ����
// FIFO

//void putc_test() {
//	FILE* fp = NULL;
//	//fp = fopen("testFile", "wt");
//	//fopen_s(&fp, "..\\..\\testFile.txt", "at"); ����� ����
//	//fopen_s(&fp, "C:\Users\bh864\Desktop\Study_C\Study_C\\testFile.txt", "at"); �������
//	fopen_s(&fp, "testFile.txt", "at"); // ��� ������ �����ָ� ���� ��ġ�� ���� ����
//	//fp�� NULL�̶�� ���� ������ ���� ���ߴٴ� �ǹ���
//	if (fp == NULL) {
//		printf("Error : ������ �� �� �����ϴ�.\n");
//		return;
//	}
//	
//	printf("testFile.txt ������ ���������� �������ϴ�.\n");
//
//	//fp �ּ��� ��ġ(������ ��ġ)�� 't'��� ���ڸ� write
//	fputc('p', fp);
//	fputc('r', fp);
//	fputc('o', fp);
//	fputc('g', fp);
//	fputc('r', fp);
//	fputc('a', fp);
//	fputc('m', fp);
//
//	puts("���� ���Ⱑ �Ϸ�Ǿ����ϴ�.");
//}

void putc_test() {
	FILE* fp = NULL;
	//fp = fopen("testFile", "wt");
	//fopen_s(&fp, "..\\..\\testFile.txt", "at"); ����� ����
	//fopen_s(&fp, "C:\Users\bh864\Desktop\Study_C\Study_C\\testFile.txt", "at"); �������
	fopen_s(&fp, "testFile.txt", "rt"); // ��� ������ �����ָ� ���� ��ġ�� ���� ����
	//fp�� NULL�̶�� ���� ������ ���� ���ߴٴ� �ǹ���
	if (fp == NULL) {
		printf("Error : ������ �� �� �����ϴ�.\n");
		return;
	}
	printf("testFile.txt ������ ���������� �������ϴ�.\n");

	//char c = fgetc(fp);
	//c = fgetc(fp);
	//printf("%c", c); //fgetc*(fp)�� �� �� �ϸ� p, �� �� �ϸ� r�� ����. ������ �������� while�� ���

	//EOF�� end of file. ��, ������ ��. ������ ���̸� 0�� �ƴ� ���� ��ȯ. ������ ���� �ƴϸ� 0�� ��ȯ
	while (!feof(fp)) {
		printf("%d\n", feof(fp));
		printf("%c", fgetc(fp));
	}

	//������ �ݾ��� -> ���α׷��� ������ �����ϰ� �Ҵ���� �޸𸮸� ����. �޸� ������ ���ϸ� �������� �Ҵ� ���� �� ó�� �޸𸮰� ��� ��������
	fclose(fp);

	//puts("���� ���Ⱑ �Ϸ�Ǿ����ϴ�.");
}

//������ �� �� �ִ��� ������ üũ�ؼ� ���¸� ��ȯ�ϴ� �Լ�
int file_open_check(FILE** fp, const char* fileName, const char* mode) {
	fopen_s(fp, fileName, mode); // ��� ������ �����ָ� ���� ��ġ�� ���� ����
	//fp�� NULL�̶�� ���� ������ ���� ���ߴٴ� �ǹ���
	if (*fp == NULL) {
		printf("Error : ������ �� �� �����ϴ�.\n");
		return 0;
	}
	printf("'%s' ������ ���������� �������ϴ�.\n", fileName);
	return 1;
}

//���Ͽ� ���ڿ� ���� (fputs, fprintf)
void file_write_string() {
	FILE* fp = NULL;
	fopen_s(&fp, "���ڿ�����.txt", "wt");
	/*fputs("�׽�Ʈ ���ڿ��Դϴ�.\n", fp);
	char* string = "���ο� ���ڿ��Դϴ�.";
	fprintf(fp, "%s\n", string);*/

	int a = 34;
	int b = 100;
	int sum = a + b;
	fprintf(fp, "�հ� : %d\n", sum);

	//������ �ݾ���
	fclose(fp);

}

//���Ͽ� ���� ���ڿ� �б�
void file_read_string() {
	FILE* fp = NULL;
	char string[1024]; //���� ���ڿ��� ������ �������迭
	fopen_s(&fp, "���ڿ�����.txt", "rt");
	
	while (1) {
		//�� ���� �ִ� 1MB(1024byte)������ ���� �� ����. (stack�� 1MB������ ����)
		if (!fgets(string, 1024, fp)) { // stream���� ���� ������ buffer�� ����
			if (feof(fp)) {
				break;
			}
		}
		printf(string);
	}

	//������ �ݾ���
	fclose(fp);
}


// �� ���ڸ� �Է¹޾�, �� ������ �հ踦 ���Ͽ� �����ϴ� �Լ��� ���弼��.
//�׸��� �ش� ������ �о ������ ���� ����ϼ���.
//������ ������ ������ ���� �Ǿ�� �Ѵ�.
// �Է¹��� �� ���� : 54, 100
// �� ������ �հ� : 154

void save_sum() {
	FILE* fp;
	fopen_s(&fp,"�հ�.txt", "wt");
	int a, b;
	printf("�� ���� ���ڸ� �Է��ϼ��� >> ");
	scanf_s("%d %d", &a, &b);
	fprintf(fp, "�Է¹��� �� ���� : %d, %d\n", a, b);
	fprintf(fp, "�� ������ �հ� : %d", a+b);

	fclose(fp);
}

//void save_sum() {
//	//������ ���� �κ�
//	FILE* fp;
//	fopen_s(&fp, "�հ�.txt", "wt");
//	// �� ���ڸ� �Է¹޴� �κ�
//	int num1, num2;// �Է¹��� �� ����.
//	puts("���� �� ���ڸ� ������� �Է��ϼ��� >> ");
//	scanf_s("%d %d", &num1, &num2);
//	//���Ͽ� ������ write
//	fprintf(fp, "�Է¹��� �� ���� : %d, %d\n", num1, num2);
//	fprintf(fp, "�� ������ �հ� : %d\n", num1 + num2);
//	fclose(fp);
//}

void print_sum() {
	FILE* file;
	fopen_s(&file, "�հ�.txt", "rt");
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
	//file_open_check�� 1�̸� ���� 0�̸� �����̹Ƿ� not������ ���� ������ ���� ���ϸ� �ٷ� ����
	if (!file_open_check(&file, fileName, "wb")) {
		return;
	}
	int number = 2022;
	double pi = 3.141592;
	//number�������ּ��� ����, int�� ũ�⸸ŭ, 1��, file�� write�ϰڴ�.
	fwrite(&number, sizeof(int), 1, file);
	fwrite(&pi, sizeof(double), 1, file);
	printf("'%s' ���� ���� �Ϸ�\n", fileName);
	//���ϴݱ�
	fclose(file);
}

void file_read_binary() {
	FILE* file = NULL;
	char* fileName = "data.dat";
	//file_open_check�� 1�̸� ���� 0�̸� �����̹Ƿ� not������ ���� ������ ���� ���ϸ� �ٷ� ����
	if (!file_open_check(&file, fileName, "rb")) {
		return;
	}
	int inumber;
	double dnumber;
	fread(&inumber, sizeof(int), 1, file);
	fread(&dnumber, sizeof(double), 1, file);
	printf("'%s' ���� �б� �Ϸ�\n", fileName);
	printf("inumber : %d\n", inumber);
	printf("dnumber : %lf\n", dnumber);

	//���� �ݱ�
	fclose(file);
}


void file_save_struct() {
	FILE* file = NULL;
	char* fileName = "person.dat"; // ���ϸ�
	if (!file_open_check(&file, fileName, "wb")) {
		return;
	}
	//p1,p2,p3��� ������ ����ü�� ����� ��������� �ʱ�ȭ ���� ��
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
	char* fileName = "person.dat"; // ���ϸ�
	if (!file_open_check(&file, fileName, "rb")) {
		return;
	}
	//p1�̶�� ����ü �����͸� ������ ������ �ϳ� ���� �� 3�� �ݺ����� ���
	for (int i = 1; i < 4; i++) {
		Person p1;
		fread(&p1, sizeof(Person), 1, file);
		printf("p%d�� �������Դϴ�.\n", i);
		printf("name : %s / age : %d\n", p1.name, p1.age);
	}

	//fwrite(&p2, sizeof(Person), 1, file);
	//fwrite(&p3, sizeof(Person), 1, file);

	fclose(file);
}

void image_copy() {
	FILE* oriFile = NULL; // ������ ������ �������� ����
	FILE* newFile = NULL; // �ٿ��ֱ��� ����
	//���� ������(������ ����) rb ���� open
	if (!file_open_check(&oriFile, "17bfcf4970d14219b.jpg", "rb")) {
		return;
	}
	if (!file_open_check(&newFile, "New17bfcf4970d14219b.jpg", "wb")) {
		return;
	}
	//���� ������ ������ �д´�.
	while (!feof(oriFile)) {
		char c;
		//oriFile���� 1byte��ŭ �о c�� �����Ѵ�.
		fread(&c, 1, 1, oriFile);
		//���� 1byte��(c) newFile�� ����.
		fwrite(&c, 1, 1, newFile);
	}
	puts("���� ���簡 �Ϸ�Ǿ����ϴ�.");
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
	//WEEK week; // ������ ���� week
	//week = SUNDAY;
	//int result = week + 1;
	//if (week + 1 == MONDAY) {
	//	//���� ���� ���� ����
	//}
	//printf("%d", result);


}









