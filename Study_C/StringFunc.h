#pragma once


//���� ���� ���� �Լ�
char* StrLTrim(char* pstr);
//�޾ƿ� string��ü�� ���� ������ ������� �Լ�
char* LTrim(char* string);
//�޾ƿ� string�� ���� ������ ����� ���ο� ���ڿ��� ��ȯ�ϴ� �Լ�
char* LTrimStr(char* string);
//������ ���� ���� �Լ�
char* StrRTrim(char* pstr);
//���� ���� ���� �Լ�
char* StrTrim(char* pstr);
//�Ű������� ���� ���ڿ����� ���ڵ鸸 �����ϴ� �Լ�
char* number_in_str(char* ori);
//ori���ڿ����� oldChar ���ڸ� newChar���ڷ� �����ϴ� �Լ�
char* StrReplace(char* ori, char oldChar, char newChar);
//ori ���ڿ����� oldStr ���ڿ��� ã�Ƽ� newStr���ڿ����� �����ϴ� �Լ�
void Replace(char* ori, char* oldStr, char* newStr);
//ori���ڿ����� ch���ڸ� �����ϴ� �Լ�
char* Remove(char* ori, char ch);
//���� ���ϴ� ���ڿ��� ���ϴ� ��ġ�� �����ϴ� �Լ�
//ori : ���� ������ ���� ���ڿ�, pos : ������ �ε��� ��ġ, inStr: ������ ���ڿ�
char* Insert(char* ori, int pos, char* inStr);
//���ʿ��� ���� ���ϴ� ���̱��� ���ڿ��� �����ϴ� �Լ�
char* StrLeft(char* ori, int length);
//�����ʿ��� ���� ���ϴ� ���̱��� ���ڿ��� �����ϴ� �Լ�
char* StrRight(char* ori, int length);


