#ifndef __BOOK_H__
#define __BOOK_H__

#define INIT_CAPACITY 20    //�ʱ� �Ҵ� ���� ���� �׸��� ���� ������ �뷮 realloc���� �÷����Ҷ� �� ������ ������
//�� 20->40->60-> ... �̷� ������� ����


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



_stBook** booklist; //���� �Ҵ��� ����ü�� �ּҸ� ���� ������ �迭�� ���� �Ҵ� �ϱ����ؼ� ���� ������ ���
int capacity;		//���� ���� �� �� �ִ� ����
int n;				//����� ��������




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