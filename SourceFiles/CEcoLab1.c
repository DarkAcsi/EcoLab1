﻿/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "IdEcoCalculatorC.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorA.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */

int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1 *me, /* in */ const UGUID *riid, /* out */ void **ppv) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoLab1)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *) pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *) pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoCalculatorX) && pCMe->m_pInnerUnknown != 0) {
        return pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
    } else if (IsEqualUGUID(riid, &IID_IEcoCalculatorY) && pCMe->m_pInnerUnknown != 0) {
        return pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
    } else if (IsEqualUGUID(riid, &IID_IEcoCalculatorX)) {
        *ppv = &pCMe->m_pVTblIX;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *) pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoCalculatorY)) {
        *ppv = &pCMe->m_pVTblIY;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*) pCMe);
    } else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1 *me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;

    /* Проверка указателя */
    if (me == 0) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1 *me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;

    /* Проверка указателя */
    if (me == 0) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoLab1((IEcoLab1 *) pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */

char *ECOCALLMETHOD MergeSort1(CEcoLab1 *pCMe, void *base, int pos, int end,
                               int (__cdecl *compare)(const void *, const void *)) {

    char *arr = (char *) base;
    char *arr1, *arr2;
    int i = 0, j = 0, ind = 0;
    int n = end - pos;
    int s_part = n - n / 2;
    char *new_arr = (char *) pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(char));

    if (n != 1) {
        arr1 = MergeSort1(pCMe, base, pos, pos + n / 2, compare);
        arr2 = MergeSort1(pCMe, base, pos + n / 2, end, compare);
    } else {
        new_arr[0] = arr[pos];
        return new_arr;
    }

    for (; (ind < n) && (i != n / 2) && (j != s_part); ind++) {
        if (compare(&arr1[i], &arr2[j]) < 0) {
            new_arr[ind] = arr1[i++];
        } else {
            new_arr[ind] = arr2[j++];
        }
    }
    if (i != n / 2) {
        for (; ind < n; ind++) {
            new_arr[ind] = arr1[i++];
        }
    } else {
        for (; ind < n; ind++) {
            new_arr[ind] = arr2[j++];
        }
    }

    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, arr1);
    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, arr2);
    return new_arr;
}

int *ECOCALLMETHOD MergeSort4(CEcoLab1 *pCMe, void *base, int pos, int end,
                              int (__cdecl *compare)(const void *, const void *)) {

    int *arr = (int *) base;
    int *arr1, *arr2;
    int i = 0, j = 0, ind = 0;
    int n = end - pos;
    int s_part = n - n / 2;
    int *new_arr = (int *) pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(int));

    if (n != 1) {
        arr1 = MergeSort4(pCMe, base, pos, pos + n / 2, compare);
        arr2 = MergeSort4(pCMe, base, pos + n / 2, end, compare);
    } else {
        new_arr[0] = arr[pos];
        return new_arr;
    }

    for (; (ind < n) && (i != n / 2) && (j != s_part); ind++) {
        if (compare(&arr1[i], &arr2[j]) < 0) {
            new_arr[ind] = arr1[i++];
        } else {
            new_arr[ind] = arr2[j++];
        }
    }
    if (i != n / 2) {
        for (; ind < n; ind++) {
            new_arr[ind] = arr1[i++];
        }
    } else {
        for (; ind < n; ind++) {
            new_arr[ind] = arr2[j++];
        }
    }

    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, arr1);
    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, arr2);
    return new_arr;
}

double *ECOCALLMETHOD MergeSort8(CEcoLab1 *pCMe, void *base, int pos, int end,
                                 int (__cdecl *compare)(const void *, const void *)) {

    double *arr = (double *) base;
    double *arr1, *arr2;
    int i = 0, j = 0, ind = 0;
    int n = end - pos;
    int s_part = n - n / 2;
    double *new_arr = (double *) pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, n * sizeof(double));

    if (n != 1) {
        arr1 = MergeSort8(pCMe, base, pos, pos + n / 2, compare);
        arr2 = MergeSort8(pCMe, base, pos + n / 2, end, compare);
    } else {
        new_arr[0] = arr[pos];
        return new_arr;
    }

    for (; (ind < n) && (i != n / 2) && (j != s_part); ind++) {
        if (compare(&arr1[i], &arr2[j]) < 0) {
            new_arr[ind] = arr1[i++];
        } else {
            new_arr[ind] = arr2[j++];
        }
    }
    if (i != n / 2) {
        for (; ind < n; ind++) {
            new_arr[ind] = arr1[i++];
        }
    } else {
        for (; ind < n; ind++) {
            new_arr[ind] = arr2[j++];
        }
    }

    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, arr1);
    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, arr2);
    return new_arr;
}


void *ECOCALLMETHOD CEcoLab1_MergeSort(struct IEcoLab1 *me, void *base, size_t size, int n,
                                       int (__cdecl *compare)(const void *, const void *)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    if (size == 1) {
        base = MergeSort1(pCMe, base, 0, n, compare);
    } else if (size == 4) {
        base = MergeSort4(pCMe, base, 0, n, compare);
    } else {
        base = MergeSort8(pCMe, base, 0, n, compare);
    }

    return base;
}


/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1 *me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    IEcoInterfaceBus1 *pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1 *) pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **) &pIBus);

    /* Проверка указателей */
    if (me == 0) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1 *) pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
        CEcoLab1_QueryInterface,
        CEcoLab1_AddRef,
        CEcoLab1_Release,
        CEcoLab1_MergeSort,
};


/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown *pIUnkSystem, /* in */ IEcoUnknown *pIUnkOuter, /* out */
                                              IEcoLab1 **ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1 *pISys = 0;
    IEcoInterfaceBus1 *pIBus = 0;
    IEcoInterfaceBus1MemExt *pIMemExt = 0;
    IEcoMemoryAllocator1 *pIMem = 0;
    CEcoLab1 *pCMe = 0;

    UGUID *rcid = (UGUID *) &CID_EcoMemoryManager1;

    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **) &pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **) &pIBus);

    /* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void **) &pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID *) pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void **) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1 *) pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Получение компонентов калькулятора методом включения */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX,
                                          (void **) &pCMe->m_pIX);
    if (result != 0 || pCMe->m_pIX == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorC, 0,
                                              &IID_IEcoCalculatorX, (void **) &pCMe->m_pIX);
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY,
                                          (void **) &pCMe->m_pIY);
    if (result != 0 || pCMe->m_pIY == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0,
                                              &IID_IEcoCalculatorY, (void **) &pCMe->m_pIY);
    }
    pCMe->m_pVTblIX = (IEcoCalculatorXVTbl*)pCMe->m_pIX->pVTbl;
    pCMe->m_pVTblIY = (IEcoCalculatorYVTbl*)pCMe->m_pIY->pVTbl;


    /* Получение компонентов калькулятора методом агрегирования */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoUnknown,
                                          (void **) &pCMe->m_pInnerUnknown);
    if (result != 0 || pCMe->m_pInnerUnknown == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, 0, &IID_IEcoUnknown,
                                              (void **) &pCMe->m_pInnerUnknown);
    }
    if (result != 0 || pCMe->m_pInnerUnknown == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorC, 0, &IID_IEcoUnknown,
                                              (void **) &pCMe->m_pInnerUnknown);
    }
    if (result != 0 || pCMe->m_pInnerUnknown == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoUnknown,
                                              (void **) &pCMe->m_pInnerUnknown);
    }
    if (result != 0 || pCMe->m_pInnerUnknown == 0) {
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoUnknown,
                                              (void **) &pCMe->m_pInnerUnknown);
    }

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1 *) pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1 *pIEcoLab1) {
    CEcoLab1 *pCMe = (CEcoLab1 *) pIEcoLab1;
    IEcoMemoryAllocator1 *pIMem = 0;

    if (pIEcoLab1 != 0) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if (pCMe->m_Name != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        if (pCMe->m_pIX != 0) {
            pCMe->m_pIX->pVTbl->Release(pCMe->m_pIX);
        }
        if (pCMe->m_pIY != 0) {
            pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
        }

        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
