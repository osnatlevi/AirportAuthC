#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "General.h"



char* getStrExactName(const char* msg)
{
	char* str;
	char temp[MAX_STR_LEN];
	printf("%s\t", msg);
	myGets(temp, MAX_STR_LEN,stdin);

	str = getDynStr(temp);
	return str;
}

char* getDynStr(char* str)
{
	char* theStr;
	theStr = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (!theStr)
		return NULL;

	strcpy(theStr, str);
	return theStr;
}



char*  myGets(char* buffer, int size, FILE* fp)
{
	if (buffer != NULL && size > 0)
	{
		if (fgets(buffer, size, fp))
		{
			buffer[strcspn(buffer, "\n")] = '\0';
			return buffer;
		}
		buffer[0] = '\0';
	}
	return NULL;
}

char**	splitCharsToWords(char* str, int* pCount, int* pTotalLength)
{
	char temp[255];
	char* delimiters = " ";
	char* word;
	int count = 0;

	strcpy(temp, str);
	char** wordsArray = NULL;
	*pTotalLength = 0;

	word = strtok(temp, delimiters);
	while (word != NULL)
	{
		wordsArray = (char**)realloc(wordsArray,(count + 1)*sizeof(char*));
		if (!wordsArray)
			return 0;
		wordsArray[count] = getDynStr(word);
		count++;
		*pTotalLength += (int)strlen(word);
		word = strtok(NULL, delimiters);
	}
	*pCount = count;
	return wordsArray;
}

char* combineString(const char* str, ...)
{
	va_list list;
	char* theStr = NULL;
	int strLength = 0;
	int length;

	va_start(list, str);
	const char* tempStr = str;
	while (tempStr != NULL)
	{
		length = (int)strlen(tempStr);
		theStr = (char*)realloc(theStr, (strLength + length + 2) * sizeof(char));
		if (!theStr)
			return NULL;

		if (strLength == 0) {
			strcpy(theStr, "_");
			strcat(theStr, tempStr);
			strLength = length + 1;
		}
		else {
			strcat(theStr, "_");
			strcat(theStr, tempStr);
			strLength += length + 1;
		}
		tempStr = va_arg(list, const char*);
	}

	va_end(list);
	return theStr;
}

void	printStr(const void* str)
{
	puts(str);
}

void	freePtr(void* str)
{
	free(str);
}



void generalArrayFunction(void* arr, int size, int typeSize, void(*func)(void* element))
{
	for (int i = 0; i < size; i++)
		func((char*)(arr)+i*typeSize);

}
