#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "StringFunc.h"
#pragma warning(disable:4996)

//���� ���� ���� �Լ�. ������ ���� ������ ������ ���� �ƴϰ� ������ ���� �ּҷ� �� ��.
char* StrLTrim(char* pstr) {
	char* ptr = pstr;
	while (*ptr) {
		if (!isspace(*ptr)) {
			return ptr;
		}
		ptr++;
	}
	//���ʿ� �μ��� ���� pstr�� ��������� while���� ���� �ȵ� �׷� ���
	return (char*)"";
}

//������ ���� ���� �Լ�. ������ ������ ������ ������ ��.
char* StrRTrim(char* pstr) {
	char* start = pstr;
	//pstr�� ���ڿ����� NULL���ڱ��� �̵�
	while (*pstr) {
		pstr++;
	}
	//NULL�ٷ� �� ���ڷ� �̵�
	pstr--;
	//NULL�ٷ� �� ���ں��� �� ù ���ڱ��� �̵� == �����ʿ��� �������� ����ȸ
	while (pstr >= start) {
		//���� pstr�� �ִ� ��ġ�� ���鹮�ڰ� �ƴ϶��
		if (!isspace(*pstr)) {
			*++pstr = '\0'; //�ش� ���� ������ġ�� NULL���� ����ִ´�.
			return start; //������
		}
		pstr--;
	}
	//������� �Դٴ� ���� ���ڿ��� ���� �����̶�� ��
	//���ڿ��� �ּҸ� return
	return (char*)"";
}

//���� ���� ���� �Լ�
char* StrTrim(char* pstr) {
	char* ptr = StrLTrim(pstr);
	return StrRTrim(ptr);
}

//�޾ƿ� string��ü�� ���� ������ ������� �Լ�
char* LTrim(char* string) {
	int index = 0;
	for (int i = 0; i < 20; i++) {
		//if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t') {
		if (!isspace(string[i])) {
			index = i;
			break;
		}
	}
	for (int i = index; i < 20; i++) {
		string[i - index] = string[i];
	}
	return string;
}

//�޾ƿ� string�� ���� ������ ����� ���ο� ���ڿ��� ��ȯ�ϴ� �Լ�
char* LTrimStr(char* string) {
	int index = 0;
	for (int i = 0; i < 20; i++) {
		//if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t') {
		if (!isspace (string[i])) {
			index = i;
			break;
		}
	}
	char* newString = (char*)calloc(strlen(string) - index + 1, sizeof(char));
	for (int i = index; i < 20; i++) {
		newString[i - index] = string[i];
	}
	return newString;
}

//�Ű������� ���� ���ڿ����� ���ڵ鸸 �����ϴ� �Լ�
char* number_in_str(char* ori) {
	char* str = (char*)malloc(sizeof(ori));
	char* pstr = str;
	//original(���� ���ڿ�)�� NULL���ڱ��� �̵��ϸ鼭 �ݺ�
	while (*ori) {
		if (isdigit(*ori)) { // original ���ڿ����� ���� �����ִ� ���ڰ� �����ΰ�?
			*pstr++ = *ori; //*str�� �ƴ϶� *pstr�� ����ϴ� ���� => *str�� �ϸ� NULL���� ��ȯ�ϴ� �� �˰ڴµ� ��?
		}
		ori++; //original �̵�
	}
	//�������� NULL���� ����
	*pstr = '\0';
	//���ڸ� ������ ���ڿ��� ���� �ּҸ� return
	return str;
}


//ori���ڿ����� oldChar ���ڸ� newChar���ڷ� �����ϴ� �Լ�
char* StrReplace(char* ori, char oldChar, char newChar) {
	//newS�� ori���ڿ����� ���ڰ� ����� ���ο� ���ڿ�
	char* newS = (char*)calloc(strlen(ori) + 1, sizeof(char));
	char* pstr = newS; //newS�� �����ּҸ� �����ϴ� �����ͺ��� pstr;

	while (*ori) {
		if (*ori == oldChar) { //���� ���� ���ڰ� ���� �����ϰ� ���� ���ڶ�� �Ѵٸ�
			//���ο� ���ڿ����� ������ ���ڸ� �־���
			*newS += newChar;
		}
		else { // �����ϰ� ���� ���ڰ� �ƴ϶�� ���ο� ���ڿ����� �״�� �־��ش�.
			*newS = *ori;
		}
		newS++;
		ori++;
	}

	//���� ����(���� ������ �����) ���ڿ��� �����ּҸ� ��ȯ
	return pstr;
}

//ori ���ڿ����� oldStr ���ڿ��� ã�Ƽ� newStr���ڿ����� �����ϴ� �Լ�
void Replace(char* ori, char* oldStr, char* newStr) {
	char* pstr = ori;
	char* pstrOld = strdup(ori);
	//char* pstrOld = (char*)malloc(sizeof(char) * 100);
	//char* pstrOldFree = pstrOld; // free()�� ���� ������ ����
	////���ڿ��� ���� �޸� �Ҵ�. ���������� malloc�� �����. => free�� ���� �����Ǿ�� ��
	//while (*ori) {
	//   *pstrOld = *ori;
	//   ori++;
	//   pstrOld++;
	//}
	//pstrOld = pstrOldFree;
	char* pos = strstr(pstrOld, oldStr); // �ٲ� ���(���ڿ�) ��ġ �˻�

	// NULL ���ڰ� ���� ������ �ݺ�
	while (pos) {
		//pstrOld(�������ڿ�)�� ������ ���ڿ��� ������ �� ��ġ���� pstr(�� ����)�� ����
		//������ ���ڿ��� ��ġ�� NULL���ڸ� ����
		strncpy(pstr, pstrOld, pos - pstrOld);
		*(pstr + (pos - pstrOld)) = '\0';
		//pstr�� ��ġ�� newStr(�����ҹ��ڿ�)�� �����Ѵ�
		//pstr�� ��ġ�� ������ ��ġ�� �̵��Ѵ�.
		strcat(pstr, newStr);
		pstr = pstr + (pos - pstrOld) + strlen(newStr);

		//�������� ��ġ�ϴ� ���ڿ��� �˻��ϱ� ���� pstrOld������ ��ġ�� ����
		//pstrOld��ġ���� ������ ���ڿ��� ��˻��ؼ� ��ġ�� �޾ƿ�
		pstrOld = pos + strlen(oldStr);
		pos = strstr(pstrOld, oldStr);

		//���� �� �̻� ��ġ�ϴ� ���ڿ��� ���ٸ�
		if (pos == NULL) {
			strcat(pstr, pstrOld);
		}
	}
	// �Ҵ���� �޸𸮸� �����Ѵ�.
	//free(pstrOldFree);
}


//ori���ڿ����� ch���ڸ� �����ϴ� �Լ�
char* Remove(char* ori, char ch) {
	char* pstr = ori; //���� ���ڿ��� �����ּ� ����
	char* pstrOld = strdup(ori); // ���ڿ� ���� (�� ����)
	char* pstrNew; //���ο� ���ڿ�

	//pstrOld(����� ���ڿ�)���� ch���ڸ� ã�Ƽ� �� ��ġ�� �̵�
	pstrNew = strchr(pstrOld, ch);

	while (pstrNew) {
		//pstr�� pstrOld�� ã�� ���� �ձ��� �����Ѵ�.
		strncpy(pstr, pstrOld, pstrNew - pstrOld);
		//�������� NULL ����
		*(pstr + (pstrNew - pstrOld)) = '\0';
		//pstr�� NULL���� �̵��ؼ� ���� ���ڿ��� ���� �� �ֵ��� ���
		pstr += pstrNew - pstrOld;

		//���� ���ڿ����� ���� ã�� ����(ch) �� ���ڷ� �̵�
		pstrOld = pstrNew + 1;
		// ���� ���� ���ڿ����� �޺κп� ch�� �ִ��� �˻��ؼ� �̵���
		pstrNew = strchr(pstrOld, ch);
		//���� ���� �κп��� ch�� �˻��ߴµ� �����ٸ�
		if (pstrNew == NULL) {
			//���� �κ� ���θ� pstr�� �����ϰ� ������.
			strcat(pstr, pstrOld);
		}
	}
	//������� �Դٴ� ���� (while�� ����) ch���� �� �̻� �߰ߵ��� �ʾҴٴ� ��
	printf("���ŵ� ori : %s", ori);
	return ori;
}


//���� ���ϴ� ���ڿ��� ���ϴ� ��ġ�� �����ϴ� �Լ�
//ori : ���� ������ ���� ���ڿ�, pos : ������ �ε��� ��ġ, inStr: ������ ���ڿ�
char* Insert(char* ori, int pos, char* inStr) {
	//���� ���ڿ��� �����ؼ� ������ġ�� ����
	char* pstr = strdup(ori);
	//pos��ġ������ ���ڿ��� ori�� �����Ѵ�.
	strncpy(ori, pstr, pos);
	ori[pos] = '\0';

	//realloc�� ����� ��. ori�� inStr�� �̾��ָ� �ٽ� �뷮�� �þ�ϱ�.

	//���� ���ڿ��� ������ ���ڿ��� �̾��ش�.
	strcat(ori, inStr);
	//���� �κ��� ���� ori�� �̾��ش�.
	strcat(ori, pstr + pos);
	return ori;
}



//���ʿ��� ���� ���ϴ� ���̱��� ���ڿ��� �����ϴ� �Լ�
char* StrLeft(char* ori, int length) {
	//���� ���ڿ��� ���̸� ���Ѵ�.
	int oriLength = strlen(ori);
	//�����ϰ� ���� ���ڿ� ���̰� 0 ���ϰų� ���� ���ڿ� ���̺��� ��ٸ�
	if (length <= 0 || oriLength <= length) {
		//���� ���ڿ��� ��ȯ�ϰ� ������.
		return ori;
	}
	char* pstr = (char*)calloc(length + 1, sizeof(char));
	for (int i = 0; i < length; i++) {
		pstr[i] = ori[i];
	}
	return pstr;
}

//�����ʿ��� ���� ���ϴ� ���̱��� ���ڿ��� �����ϴ� �Լ�
char* StrRight(char* ori, int length) {
	//���� ���ڿ��� ���̸� ���Ѵ�.
	int oriLength = strlen(ori);
	//�����ϰ� ���� ���ڿ� ���̰� 0 ���ϰų� ���� ���ڿ� ���̺��� ��ٸ�
	if (length <= 0 || oriLength <= length) {
		//���� ���ڿ��� ��ȯ�ϰ� ������.
		return ori;
	}

	//�Ʒ��� ���� strdup()�� �� ���ε� �׳� Ǯ� �ϸ� �̷��� ��.
	char* pstr = (char*)calloc(length + 1, sizeof(char));
	for (int i = 0; i < oriLength - length; i++) {
		//pstr[0] = ori[10 - 4 + 0 = 6]
		//pstr[1] = ori[7]
		//pstr[2] = ori[8] ... �ݺ�
		pstr[i] = ori[oriLength - length + i];
	}


	return pstr;
}


//�׽�Ʈ�� ����
void StringFuncMain() {


	//char* result = StrRight("Left Right", 4);
	//printf("result:%s", result);


	//char* result = StrLeft("Left Right", 4);
	//printf("result:%s", result);


	////Ư�� ��ġ�� ���� �׽�Ʈ
	//char string[100] = "This is [] test";
	//Insert(string, 9, "insert");
	//printf("���Ե� ���ڿ� : %s", string);


	//���ڿ����� ���� �����ϱ� �׽�Ʈ
	//char string[] = "010-1234-5678";
	//Remove(string, '-');
	////Remove(string, '-', 1); �̷� ����� �Լ� ������ ī��Ʈ ������ ������� ã�� ������ ī��Ʈ�� ������Ŵ


	//���ڿ� �����ϱ� �׽�Ʈ
	//char string[100] = "app test application";
	//Replace(string, "app", "phone");
	//Replace("app test application", "app", "phone");


	//���� �����ϱ� �׽�Ʈ
	//char * result = StrReplace("This is test", 't', 'o');
	//printf("����� ���ڿ� : %s\n", result);


	//���ڸ� �����ϱ� �׽�Ʈ
	//char* result = number_in_str("a5b6c7d1234");
	//printf("%s\n", result);


	//���� ���� ���� �׽�Ʈ
	//char string[30] = "\t\t\t\n Test String";
	//printf("��ȯ ���� string:%s\n", string);
	//printf("���� ������� string:%s\n", LTrimStr(string)); //string�� �ƴ϶� ���� �������
	//printf("��ȯ ���� string:%s\n", string); //string�� �ȹٲ�


	//printf("��ȯ ���� string:%s\n", LTrim(string)); //string ��ü�� �ٲ�
	//printf("��ȯ ���� string:%s\n", string); // string ��ü�� �ٲ�


	//char* ptr = StrLTrim(string);
	//printf("%s\n", ptr);
}

//�޸� ����ȭ