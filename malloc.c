#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"


void init_malloc() {

	capacity = INIT_CAPACITY;
	n = 0;
	booklist = (_stBook**)malloc(capacity * sizeof(_stBook*));

	if (booklist == NULL) {
		printf("booklist malloc 실패\n");
		return;
	}

	for (int i = 0; i < capacity; i++) {

		booklist[i] = (_stBook*)malloc(sizeof(_stBook));

		if (booklist[i] == NULL) {
			printf("booklist[i + 1] malloc 실패\n");
			return;
		}

		booklist[i]->author = string_malloc_copy("...");
		booklist[i]->title = string_malloc_copy("...");
		booklist[i]->price = 0;
		booklist[i]->page = 0;
		booklist[i]->date.year = 0;
		booklist[i]->date.month = 0;
		booklist[i]->date.day = 0;
	}

}


char* string_malloc_copy(char* string) {

	char* p;
	p = (char*)malloc(strlen(string) + 1);
	if (p != NULL) {
		strcpy(p, string);
	}
	return p;
}



void booklist_reallocate() {



	int capacity_tmp = capacity;
	capacity += INIT_CAPACITY;
	printf("메모리 재할당 합니다 %d -> %d \n", capacity_tmp, capacity);

	_stBook** tmp = (_stBook**)malloc(capacity * sizeof(_stBook*));
	if (tmp == NULL) {
		printf("tmp malloc 실패\n");
		return;
	}



	for (int i = 0; i < capacity_tmp; i++) {
		tmp[i] = booklist[i];
	}

	for (int i = capacity_tmp; i < capacity; i++) {

		tmp[i] = (_stBook*)malloc(sizeof(_stBook));

		if (tmp[i] == NULL) {
			printf("tmp[i + 1] malloc 실패\n");
			return;
		}

		tmp[i]->author = string_malloc_copy("...");
		tmp[i]->title = string_malloc_copy("...");
		tmp[i]->price = 0;
		tmp[i]->page = 0;
		tmp[i]->date.year = 0;
		tmp[i]->date.month = 0;
		tmp[i]->date.day = 0;
	}



	free(booklist); // 옮긴 후에 이전 포인터 배열은 더이상 쓰지 않게되므로 할당 해제 해주어야한다.

	booklist = tmp;



}