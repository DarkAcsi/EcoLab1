/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"


int _cdecl IntCompare(const void* _a, const void* _b) {
	int a = *(int *)_a;
	int b = *(int *)_b;
	return (a > b) - (a < b);
}

int _cdecl FloatCompare(const void* _a, const void* _b) {
	float a = *(float *)_a;
	float b = *(float *)_b;
	return (a > b) - (a < b);
}

int _cdecl DoubleCompare(const void* _a, const void* _b) {
	double a = *(double *)_a;
	double b = *(double *)_b;
	return (a > b) - (a < b);
}

int _cdecl CharCompare(const void* _a, const void* _b) {
	char a = *(char *)_a;
	char b = *(char *)_b;
	return (a > b) - (a < b);
}

void IntPrintArray(void *base, int n) {
	int* arr = (int *)base;
	int i = 0;
	for (; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void FloatPrintArray(void *base, int n) {
	float* arr = (float *)base;
	int i = 0;
	for (; i < n; i++)
		printf(".3f ", arr[i]);
	printf("\n");
}

void DoublePrintArray(void *base, int n) {
	double* arr = (double *)base;
	int i = 0;
	for (; i < n; i++)
		printf("%.3f ", arr[i]);
	printf("\n");
}

void CharPrintArray(void *base, int n) {
	char* arr = (char *)base;
	int i = 0;
	for (; i < n; i++)
		printf("%c ", arr[i]);
	printf("\n");
}

void IntTest(IEcoLab1 *pIEcoLab1, IEcoMemoryAllocator1 *pIMem, int n){
	int i;
	clock_t start_ms;
	double time_ms;
	clock_t start_qs;
	double time_qs;
	int* arr;

	int* array_ms = (int *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(int));
	int* array_qs = (int *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(int));

	srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++){
        array_ms[i] = rand()%100;
		array_qs[i] = array_ms[i];
    }

	start_ms = clock();
	arr = (int *)pIEcoLab1->pVTbl->MergeSort(pIEcoLab1, array_ms, sizeof(int), n, IntCompare);
    time_ms = ((double) (clock() - start_ms));
    printf("Time Merge Sort: %f ms\n", time_ms);

	start_qs = clock();
	qsort(array_qs, n, sizeof(int), IntCompare);
    time_qs = ((double) (clock() - start_qs));
    printf("Time Quick Sort: %f ms\n", time_qs);


	pIMem->pVTbl->Free(pIMem, array_ms);
	pIMem->pVTbl->Free(pIMem, array_qs);
}

void FloatTest(IEcoLab1 *pIEcoLab1, IEcoMemoryAllocator1 *pIMem, int n){
	int i;
	clock_t start_ms;
	double time_ms;
	clock_t start_qs;
	double time_qs;
	float* arr;

	float* array_ms = (float *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(float));
	float* array_qs = (float *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(float));

	srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++){
        array_ms[i] = (float)rand()/(float)(RAND_MAX/3.0f);
		array_qs[i] = array_ms[i];
    }

	start_ms = clock();
	arr = (float *)pIEcoLab1->pVTbl->MergeSort(pIEcoLab1, array_ms, sizeof(float), n, FloatCompare);
    time_ms = ((double) (clock() - start_ms));
    printf("Time Merge Sort: %f ms\n", time_ms);

	start_qs = clock();
	qsort(array_qs, n, sizeof(float), FloatCompare);
    time_qs = ((double) (clock() - start_qs));
    printf("Time Quick Sort: %f ms\n", time_qs);


	pIMem->pVTbl->Free(pIMem, array_ms);
	pIMem->pVTbl->Free(pIMem, array_qs);
}

void DoubleTest(IEcoLab1 *pIEcoLab1, IEcoMemoryAllocator1 *pIMem, int n){
	int i;
	clock_t start_ms;
	double time_ms;
	clock_t start_qs;
	double time_qs;
	double* arr;

	double* array_ms = (double *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(double));
	double* array_qs = (double *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(double));

	srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++){
        array_ms[i] = (double)rand() / 119;
		array_qs[i] = array_ms[i];
    }

	start_ms = clock();
	arr = (double *)pIEcoLab1->pVTbl->MergeSort(pIEcoLab1, array_ms, sizeof(double), n, DoubleCompare);
    time_ms = ((double) (clock() - start_ms));
    printf("Time Merge Sort: %f ms\n", time_ms);

	start_qs = clock();
	qsort(array_qs, n, sizeof(double), DoubleCompare);
    time_qs = ((double) (clock() - start_qs));
    printf("Time Quick Sort: %f ms\n", time_qs);


	pIMem->pVTbl->Free(pIMem, array_ms);
	pIMem->pVTbl->Free(pIMem, array_qs);
}

void CharTest(IEcoLab1 *pIEcoLab1, IEcoMemoryAllocator1 *pIMem, int n){
	int i;
	clock_t start_ms;
	double time_ms;
	clock_t start_qs;
	double time_qs;
	char* arr;

	char* array_ms = (char *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(char));
	char* array_qs = (char *)pIMem->pVTbl->Alloc(pIMem, n * sizeof(char));

	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/.,?><1234567890-=_+!@#$%^&()`~";
	srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++){
		int key = rand() % (int) (sizeof charset - 1);
        array_ms[i] = charset[key];
		array_qs[i] = array_ms[i];
    }

	start_ms = clock();
	arr = (char *)pIEcoLab1->pVTbl->MergeSort(pIEcoLab1, array_ms, sizeof(char), n, CharCompare);
    time_ms = ((double) (clock() - start_ms));
    printf("Time Merge Sort: %f ms\n", time_ms);

	start_qs = clock();
	qsort(array_qs, n, sizeof(char), CharCompare);
    time_qs = ((double) (clock() - start_qs));
    printf("Time Quick Sort: %f ms\n", time_qs);


	pIMem->pVTbl->Free(pIMem, array_ms);
	pIMem->pVTbl->Free(pIMem, array_qs);
}



// Lab2

void TestComponents(IEcoLab1 *pIEcoLab1){

    IEcoCalculatorX* pIX = 0;
    IEcoCalculatorY* pIY = 0;
    int16_t a = 10000;
    int16_t b = 200;

    pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, &pIX);
    pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, &pIY);

    printf("Addition: %d\n", pIX->pVTbl->Addition(pIX, a, b));
    printf("Subtraction: %d\n", pIX->pVTbl->Subtraction(pIX, a, b));
    printf("Multiplication: %d\n", pIY->pVTbl->Multiplication(pIY, a, b));
    printf("Division: %d\n", pIY->pVTbl->Division(pIY, a, b));

}

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    char_t* name = 0;
    char_t* copyName = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;
    /* lab2 */


    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Выделение блока памяти */

    /* Заполнение блока памяти */


    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

//	printf("n: 100\n");
//	DoubleTest(pIEcoLab1, pIMem, 100);
//	printf("n: 1000\n");
//	DoubleTest(pIEcoLab1, pIMem, 1000);
//	printf("n: 10000\n");
//	DoubleTest(pIEcoLab1, pIMem, 10000);
//	printf("n: 100000\n");
//	DoubleTest(pIEcoLab1, pIMem, 100000);
//	printf("n: 1000000\n");
//	DoubleTest(pIEcoLab1, pIMem, 1000000);
//	printf("n: 10000000\n");
//	DoubleTest(pIEcoLab1, pIMem, 10000000);
//	printf("\n");

    TestComponents(pIEcoLab1);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

