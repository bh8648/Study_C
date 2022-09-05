#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void strcpy_test() {
	char c[20] = "CCCCCCCCCC";
	char* message = "python";
	//message 주소의 값을 c의 주소에 복사
	//char* addr = strcpy_s(c,20, message);

	//복사가 완료된 위치의 주소를 반환
	//char* addr = strcpy(c, message);
	char* addr = strncpy(c, message, 2);
	printf("c : %s\n", c);
	printf("addr : %s\n", addr);
}

void strlen_test() {
	int length = strlen("This is test");
	printf("길이 : %d\n", length);
}


void strcat_test() {
	char dest[30] = "C program";
	char* source = "test";
	strcat(dest, source); //dest의 공간이 충분히 남아 있어야 함. 처음에 멀록사용 // dest 위치에는 문자열 사용 불가, source는 문자열 바로 집어넣기 가능
	printf("%s\n", dest);
	printf("%s\n", source);

}

void strcmp_test() {
	char s1[20] = "Aaa";
	char s2[20] = "aaa";
	//char s1[20] = "1";
	//char s2[20] = "1";
	int result;
	//result = strcmp(s1, s2); //s1이 s2보다 작으면 -1, 같으면 0, 크면 1 반환 //가장 앞이 중요
	//result = strncmp(s1, s2, 2); //원하는 숫자만큼 문자를 비교
	result = stricmp(s1, s2); //대소문자 구분 없이 비교함

	printf("result : %d\n", result);

}


//버블정렬
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

	printf("정렬된 결과를 출력합니다 >> ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

}


void string_sort(char strings[][20]) {
	int isSorted = 1; //원래는 정령이 되어 있다고 판단
	int length = 5; //strings의 요소의 개수
	while (1) {
		isSorted = 1;
		for (int i = 0; i < length - 1; i++) {
			//두 문자열을 비교했을 때, 1이 나오면 교환해야 한다. *왼쪽이 더 크다는 뜻이므로)
			if (strcmp(strings[i], strings[i + 1]) == 1) {
				printf("s[%d]: %s\n", i, strings[i]);
				//두 문자열의 교환작업
				char tmp[20];
				strcpy(tmp, strings[i]);
				strcpy(strings[i], strings[i + 1]);
				strcpy(strings[i + 1], tmp);
				isSorted = 0; //교환을 한번이라도 했다면 작업을 계속해야 함.
			}
		}
		printf("sorted: %d\n", isSorted);
		//isSorted가 1이라는 것은 정렬이 끝났다는 얘기
		if (isSorted) {
			break;
		}
		length--;
	}

	for (int i = 0; i < 5; i++) {
		printf("%s ", strings[i]);
	}
}




//문자 검색 테스트
void strchr_test() {
	char string[20] = "apple";
	//char* chaddr = strchr(string, 'p');
	char* chaddr = strrchr(string, 'p'); //오른쪽부터 찾음
	printf("찾은 위치 : %s\n", chaddr);
	printf("찾은 위치 : %p\n", chaddr);
	printf("l의 위치 : %p\n", &string[2]);

	//chaddr = strpbrk(string, "abcd"); //strpbrk : a나 b나 c나 d중에 일치하는 것부터 출력
	//chaddr = strpbrk(string, "pa"); //strpbrk : ap를 하든 pa를 하든 a부터 찾는다.
	chaddr = strpbrk(string, "ap"); //strpbrk : ap를 하든 pa를 하든 a부터 찾는다.
	printf("찾은 문자부터 : %s\n", chaddr);
}

void strcspn_test() {
	char s[20] = "C Programming";
	int index = strcspn(s, "gram"); //3이 나옴. 왜? g, r, a, m 중에 가장 먼저 나오는게 r이고 r이 3번째 위치에 있어서.
	printf("찾은 문자의 위치 : %d\n", index);




	char* addr = strstr(s, "gram");
	//char* addr = strstr(s, "C pro");
	//char* addr = strstr(s, "Cpro");
	printf("찾은 문자열의 위치부터~: %s\n", addr);
}



void strtok_test() {
	char s[20] = "This is test";
	char* separate = "ti";
	char* result = strtok(s, separate);

	printf("분리된 문자열 : %s\n", result);

	while (result) {
		result = strtok(NULL, separate);
		printf("분리된 문자열 : %s\n", result);
	}
}

//UpperCase, LowerCase //대문자, 소문자

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
	int result = atoi("abc1234"); //이러면 0나옴
	printf("%d\n", result);


	//scanf는 띄어쓰기로 넣을 문자열을 구분함

	//char c[30], c2[40];
	//scanf("%s %s", c, c2);
	//printf("전달받은 문자열 : %s\n", c);
	//printf("전달받은 문자열 : %s\n", c2);


	//gets는 띄어쓰기를 포함한 입력을 저장함
	char c[20];
	puts("입력1 : >> "); //puts는 줄바꿈이 자동적으로 들어가있다.
	gets_s(c, sizeof(char) * 20);
	//rewind(stdin) 필요하면 써야 함. 지금은 아니지만
	printf("입력2 : >> ");
	gets_s(c, sizeof(char) * 20);

	//puts(c); //문자열을 입력하면 바로 출력
	//puts("testestets"); //문자열을 입력하면 바로 출력

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


