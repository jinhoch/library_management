#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "book.h"




int main() {

	init_malloc();  //�ʱ� �뷮 �����޸��Ҵ�(�ʱ� ���� 20�� ���尡�� �뷮)

	char menu_select = 'y'; //�޴� ���� ��ȣ �ʱ�ȭ

	while (menu_select != '0') { // 0 �Է� �ɶ� ���� ���ѷ���
		menu_print();
		printf("\n\n� �޴� �����Ͻðڽ��ϱ�? (0 : ����) : [");
		menu_select = _getche();
		printf("]\n");
		if (menu_select == '1') keyboar_add(); //���� Ű���� �߰�
		else if (menu_select == '2') book_delete(); //���� ����
		else if (menu_select == '3') book_sort(); //���� ����
		else if (menu_select == '4') book_search(); //���� �˻�
		else if (menu_select == '5') load(); //���� �ε�
		else if (menu_select == '6') save(); //���� ���� 
		else if (menu_select == '7') print_status_booklist(); //���� Ȯ��
		else {
			continue;
		}
	}





	//���� �޸� �Ҵ� ���α׷� �������� ��� free

	//string_malloc_copy() �Լ��� ���� �Ҵ��� title �� author free
	for (int i = 0; i < n; i++) {
		free(booklist[i]->title);
		free(booklist[i]->author);
	}
	//(_stBook*)malloc(sizeof(_stBook)) ���� ���� �Ҵ��� ���� ����ü free
	for (int i = 0; i < capacity; i++) {
		free(booklist[i]);
	}
	//(_stBook**)malloc(capacity * sizeof(_stBook*)) ���� ���� �Ҵ��� ������ �迭 free
	free(booklist);


	return 0;
}
