//#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void print_time_now() {
	// ���� ��¥/�ð��� �����ϴ� ������ now ����
	time_t now;
	// ���� ��¥/�ð��� �����ϴ� ����ü t
	struct tm t;
	char buff[100];
	// time : 1970�� 1�� 1�� 0�ú��� ������� ����� �ð�
	time(&now);
	// localtime : now�ð��� ����ü t�� �����ϸ�, ����� �ð��� ����ؼ�
	// ����ü �����鿡 ���� �������ִ� �Լ�
	localtime_s(&t, &now);

	//strftime
	//buff : ��¥ ������ ������ ���ڿ� �迭
	//%Y: ��, %m : ��, %d : ��, %H : ��, %M : ��, %p : AM/PM, %a: ����
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p (%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%Y", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%y", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%x", &t);
	puts(buff);

	//printf(asctime(&t));

	printf("���� �ð�: %d�� %d�� %d�� %d�� %d�� %d��\n",
		t.tm_year+1900, t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}


//�ð� ���� �׽�Ʈ
void calc_time() {
	time_t now;
	// t_now : ���� ��¥/�ð��� �����ϴ� ����ü
	// t_calc : ����� ��¥/�ð��� �����ϴ� ����ü
	struct tm t_now, t_calc;
	time(&now); // 1970��~ ����� �ð� ����
	localtime_s(&t_now, &now); //����ü�� ��¥/�ð����� ����
	t_calc = t_now;
	t_calc.tm_mon += 5; // ���� �� +5�� ����
	t_calc.tm_hour += 10; // ���� �� + 1�ð� ����

	mktime(&t_calc); //��Ȯ�� �ð��� ��������. ���ϸ� 28�� �̷��� �Ѿ
	printf("���� �ð�: %d�� %d�� %d�� %d�� %d�� %d��\n",
		t_now.tm_year + 1900, t_now.tm_mon + 1, t_now.tm_mday, t_now.tm_hour, t_now.tm_min, t_now.tm_sec);
	printf("���� �ð�: %d�� %d�� %d�� %d�� %d�� %d��\n",
		t_calc.tm_year + 1900, t_calc.tm_mon + 1, t_calc.tm_mday, t_calc.tm_hour, t_calc.tm_min, t_calc.tm_sec);


}





void Main220830() {
	//print_time_now();
	calc_time();



}

