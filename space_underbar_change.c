#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"



void Underbar_to_space(char* str)
{
	int len = strlen(str), i;

	for (i = 0; i < len; i++)
	{
		if (str[i] == '_')
			str[i] = ' ';
	}
}

void Space_to_underbar(char* str)
{
	int len = strlen(str), i;

	for (i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			str[i] = '_';
	}
}