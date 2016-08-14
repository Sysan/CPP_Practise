// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define safeFree(p) saferFree((void**)&(p))

typedef int(*funcptr)(int);

using namespace std;

struct Person
{
	char * name;
	char * address;
	int age;
} person;

int* allocateArray(int size, int value) {
	int* arr = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++) {
		arr[i] = value;
	}
	return arr;
}

void allocateArray(int* ptr, int size, int value) {
	if (ptr != NULL) {
		for (int i = 0; i < size; i++) {
			*(ptr++) = value;
		}
	}
}

void allocateArray(int **ptr, int size, int value) {
	*ptr = (int*)malloc(size * sizeof(int));
	if (*ptr != NULL) {
		for (int i = 0; i < size; i++) {
			*((*ptr) + i) = value;
		}
	}
}

void saferFree(void **ptr) {
	if (ptr != NULL&&*ptr != NULL) {
		free(*ptr);
		*ptr = NULL;
	}
}

int square(int num) {
	return num*num;
}

int add(int num1, int num2) {
	return num1 + num2;
}

int sub(int num1, int num2) {
	return num1 - num2;
}

typedef int(*fptrOperation)(int, int);

int compute(fptrOperation operation, int num1, int num2) {
	return operation(num1, num2);
}

fptrOperation select(char opcode) {
	switch (opcode)
	{
	case '+':return add;
	case '-':return sub;
	}
}

int evaluate(char opcode, int num1, int num2) {
	fptrOperation operation = select(opcode);
	return operation(num1, num2);
}

typedef int(*operation)(int, int);
operation operations[128] = { NULL };

void initializeOperationsArray() {
	operations['+'] = add;
	operations['-'] = sub;
}

int evaluateArray(char opcode, int num1, int num2) {
	fptrOperation operation;
	operation = operations[opcode];
	if (operation == NULL) {
		return 0;
	}
	else {
		return operation(num1, num2);
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	int num = 5;
	void *pv = &num;
	printf("%p\n", pv);

	const int limit = 900;

	const int * ptr = &limit;

	cout << ptr << endl;

	ptr = &num;

	int const * ppp = &limit;

	person.address = "shanghai";
	person.name = "Sophia";
	person.age = 21;

	int *pi = (int*)malloc(sizeof(int));
	*pi = 5;
	printf("*pi: %d\n", *pi);
	free(pi);

	int * pii = NULL;
	__try
	{
		pii = (int*)malloc(sizeof(int));
		*pii = 7;
	}
	__finally {
		free(pii);
	}

	int* hehePtr = allocateArray(5, 45);
	for (int i = 0; i < 5; i++) {
		cout << hehePtr[i] << endl;
	}
	free(hehePtr);

	int* snowmanPtr = (int*)malloc(5 * sizeof(int));
	allocateArray(snowmanPtr, 5, 75);
	for (int i = 0; i < 5; i++) {
		cout << snowmanPtr[i] << endl;
	}
	free(snowmanPtr);

	int* annaPtr = NULL;
	allocateArray(&annaPtr, 5, 88);
	for (int i = 0; i < 5; i++) {
		cout << annaPtr[i] << endl;
	}
	cout << annaPtr << endl;
	safeFree(annaPtr);
	cout << annaPtr << endl;

	int(*fptr1)(int);
	fptr1 = square;
	cout << "5 squared is " << fptr1(5) << endl;

	funcptr fptr2 = square;
	cout << "7 squared is " << fptr2(7) << endl;

	cout << compute(add, 1, 2) << " " << compute(sub, 55, 33) << endl;


	initializeOperationsArray();
	printf("%d\n", evaluateArray('+', 5, 6));
	printf("%d\n", evaluateArray('-', 5, 6));
	printf("%d\n", evaluateArray('*', 5, 6));
	return 0;
}

void raiiExample() {


}