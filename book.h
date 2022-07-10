#ifndef __BOOK_H__
#define __BOOK_H__

#define INIT_CAPACITY 20    //초기 할당 도서 개수 그리고 만약 꽉차서 용량 realloc으로 늘려야할때 이 단위로 증설함
//즉 20->40->60-> ... 이런 방식으로 증설


typedef struct {
	char year;
	char month;
	char day;
}_stDate;

typedef struct {
	char* title;
	int price;
	char* author;
	int page;
	_stDate date;
} _stBook;



_stBook** booklist; //동적 할당한 구조체의 주소를 담을 포인터 배열을 동적 할당 하기위해서 이중 포인터 사용
int capacity;		//도서 저장 할 수 있는 개수
int n;				//저장된 도서개수




void init_malloc();
void print_status_booklist();
void booklist_reallocate();
void add(char* title, int price, char* author, int page, int year, int month, int day);
void keyboar_add();
void load();
int search(char* name);
void book_search();
void book_delete();
void book_sort();
void menu_print();
void save();
char* string_malloc_copy(char* string);
int read_line(char* str, int limit);
void Underbar_to_space(char* str);
void Space_to_underbar(char* str);
int string_to_int(char* s);
int my_pow(int a);


#endif