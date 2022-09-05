#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void strcpy_test() {
	char c[20] = "CCCCCCCCCC";
	char* message = "python";
	//message �ּ��� ���� c�� �ּҿ� ����
	//char* addr = strcpy_s(c,20, message);

	//���簡 �Ϸ�� ��ġ�� �ּҸ� ��ȯ
	//char* addr = strcpy(c, message);
	char* addr = strncpy(c, message, 2);
	printf("c : %s\n", c);
	printf("addr : %s\n", addr);
}

void strlen_test() {
	int length = strlen("This is test");
	printf("���� : %d\n", length);
}


void strcat_test() {
	char dest[30] = "C program";
	char* source = "test";
	strcat(dest, source); //dest�� ������ ����� ���� �־�� ��. ó���� �ַϻ�� // dest ��ġ���� ���ڿ� ��� �Ұ�, source�� ���ڿ� �ٷ� ����ֱ� ����
	printf("%s\n", dest);
	printf("%s\n", source);

}

void strcmp_test() {
	char s1[20] = "Aaa";
	char s2[20] = "aaa";
	//char s1[20] = "1";
	//char s2[20] = "1";
	int result;
	//result = strcmp(s1, s2); //s1�� s2���� ������ -1, ������ 0, ũ�� 1 ��ȯ //���� ���� �߿�
	//result = strncmp(s1, s2, 2); //���ϴ� ���ڸ�ŭ ���ڸ� ��
	result = stricmp(s1, s2); //��ҹ��� ���� ���� ����

	printf("result : %d\n", result);

}


//��������
void bubble_sort() {
	int arr[] = { 4, 2, 66, 90, 5 };
	int length = (sizeof(arr) / sizeof(int));

	while (1) {
		int isSorted = 1;
		for (int i = 0; i < length - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				isSorted = 0;
			}
		}
		length--;
		if (isSorted) {
			break;
		}
	}

	printf("���ĵ� ����� ����մϴ� >> ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

}


void string_sort(char strings[][20]) {
	int isSorted = 1; //������ ������ �Ǿ� �ִٰ� �Ǵ�
	int length = 5; //strings�� ����� ����
	while (1) {
		isSorted = 1;
		for (int i = 0; i < length - 1; i++) {
			//�� ���ڿ��� ������ ��, 1�� ������ ��ȯ�ؾ� �Ѵ�. *������ �� ũ�ٴ� ���̹Ƿ�)
			if (strcmp(strings[i], strings[i + 1]) == 1) {
				printf("s[%d]: %s\n", i, strings[i]);
				//�� ���ڿ��� ��ȯ�۾�
				char tmp[20];
				strcpy(tmp, strings[i]);
				strcpy(strings[i], strings[i + 1]);
				strcpy(strings[i + 1], tmp);
				isSorted = 0; //��ȯ�� �ѹ��̶� �ߴٸ� �۾��� ����ؾ� ��.
			}
		}
		printf("sorted: %d\n", isSorted);
		//isSorted�� 1�̶�� ���� ������ �����ٴ� ���
		if (isSorted) {
			break;
		}
		length--;
	}

	for (int i = 0; i < 5; i++) {
		printf("%s ", strings[i]);
	}
}




//���� �˻� �׽�Ʈ
void strchr_test() {
	char string[20] = "apple";
	//char* chaddr = strchr(string, 'p');
	char* chaddr = strrchr(string, 'p'); //�����ʺ��� ã��
	printf("ã�� ��ġ : %s\n", chaddr);
	printf("ã�� ��ġ : %p\n", chaddr);
	printf("l�� ��ġ : %p\n", &string[2]);

	//chaddr = strpbrk(string, "abcd"); //strpbrk : a�� b�� c�� d�߿� ��ġ�ϴ� �ͺ��� ���
	//chaddr = strpbrk(string, "pa"); //strpbrk : ap�� �ϵ� pa�� �ϵ� a���� ã�´�.
	chaddr = strpbrk(string, "ap"); //strpbrk : ap�� �ϵ� pa�� �ϵ� a���� ã�´�.
	printf("ã�� ���ں��� : %s\n", chaddr);
}

void strcspn_test() {
	char s[20] = "C Programming";
	int index = strcspn(s, "gram"); //3�� ����. ��? g, r, a, m �߿� ���� ���� �����°� r�̰� r�� 3��° ��ġ�� �־.
	printf("ã�� ������ ��ġ : %d\n", index);




	char* addr = strstr(s, "gram");
	//char* addr = strstr(s, "C pro");
	//char* addr = strstr(s, "Cpro");
	printf("ã�� ���ڿ��� ��ġ����~: %s\n", addr);
}



void strtok_test() {
	char s[20] = "This is test";
	char* separate = "ti";
	char* result = strtok(s, separate);

	printf("�и��� ���ڿ� : %s\n", result);

	while (result) {
		result = strtok(NULL, separate);
		printf("�и��� ���ڿ� : %s\n", result);
	}
}

//UpperCase, LowerCase //�빮��, �ҹ���

void ULcase_test() {
	char string[40] = "C Programming";

	//strupr(string);
	//char* resultU = string;
	char* resultU = strupr(string);
	printf("%s\n", resultU);
	printf("%s\n", string);

	//strlwr(string);
	//char* resultL = string;
	char* resultL = strlwr(string);
	printf("%s\n", resultL);
	printf("%s\n", string);

	strset(&string[8], 'z');
	printf("strset : %s\n", string);
}


void etc_test() {
	char string[20] = "test program";
	strrev(string);
	printf("%s\n", string);

	//int result = atoi("1234");
	//int result = atoi("1234-13");
	//int result = atoi("1234+13");
	//int result = atoi("1234abcd");
	int result = atoi("abc1234"); //�̷��� 0����
	printf("%d\n", result);


	//scanf�� ����� ���� ���ڿ��� ������

	//char c[30], c2[40];
	//scanf("%s %s", c, c2);
	//printf("���޹��� ���ڿ� : %s\n", c);
	//printf("���޹��� ���ڿ� : %s\n", c2);


	//gets�� ���⸦ ������ �Է��� ������
	char c[20];
	puts("�Է�1 : >> "); //puts�� �ٹٲ��� �ڵ������� ���ִ�.
	gets_s(c, sizeof(char) * 20);
	//rewind(stdin) �ʿ��ϸ� ��� ��. ������ �ƴ�����
	printf("�Է�2 : >> ");
	gets_s(c, sizeof(char) * 20);

	//puts(c); //���ڿ��� �Է��ϸ� �ٷ� ���
	//puts("testestets"); //���ڿ��� �Է��ϸ� �ٷ� ���

}



void MyStringMain() {

	//strcpy_test();
	//strlen_test();
	//strcat_test();
	//strcmp_test();

	//bubble_sort();

	/*char strings[][20] = { "apple", "melon", "banana", "grape", "cherry"};
	string_sort(strings);*/

	//strchr_test();
	//strcspn_test();
	//strtok_test();
	//ULcase_test();

	//etc_test();



}


