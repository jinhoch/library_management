#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "book.h"




int main() {

	init_malloc();  //초기 용량 동적메모리할당(초기 도서 20개 저장가능 용량)

	char menu_select = 'y'; //메뉴 선택 번호 초기화

	while (menu_select != '0') { // 0 입력 될때 까지 무한루프
		menu_print();
		printf("\n\n어떤 메뉴 선택하시겠습니까? (0 : 종료) : [");
		menu_select = _getche();
		printf("]\n");
		if (menu_select == '1') keyboar_add(); //도서 키보드 추가
		else if (menu_select == '2') book_delete(); //도서 삭제
		else if (menu_select == '3') book_sort(); //도서 정렬
		else if (menu_select == '4') book_search(); //도서 검색
		else if (menu_select == '5') load(); //파일 로드
		else if (menu_select == '6') save(); //파일 저장 
		else if (menu_select == '7') print_status_booklist(); //도서 확인
		else {
			continue;
		}
	}





	//동적 메모리 할당 프로그램 끝나기전 모두 free

	//string_malloc_copy() 함수로 동적 할당한 title 과 author free
	for (int i = 0; i < n; i++) {
		free(booklist[i]->title);
		free(booklist[i]->author);
	}
	//(_stBook*)malloc(sizeof(_stBook)) 으로 동적 할당한 도서 구조체 free
	for (int i = 0; i < capacity; i++) {
		free(booklist[i]);
	}
	//(_stBook**)malloc(capacity * sizeof(_stBook*)) 으로 동적 할당한 포인터 배열 free
	free(booklist);


	return 0;
}
