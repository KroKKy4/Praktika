#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "figure.h"
#include "baza.h"

struct Base
{
	RightParallelepiped** arr;
	int ObjNum;
};

void InputStdin(Base* base) //Incoming Item Validation
{
    int ans = 0;

    do
    {
        base->ObjNum++;
        base->arr = (RightParallelepiped**)realloc(base->arr, base->ObjNum * sizeof(RightParallelepiped*));
        if (!base->arr) //Verification
        {
            printf("Memory is NULL");
            exit(1);
        }

        RightParallelepiped* Parallelepiped = Constructor();
        base->arr[base->ObjNum - 1] = Parallelepiped;
        printf("input again?\n");
        scanf_s("%d", &ans);
    } while (ans == 'Y');
}

void InputFile(FILE* f, Base* base) // Reads information from the input.txt file, filling in the data.
{
    char str[128] = { "0" };
    fseek(f, 0L, SEEK_END);
    int end = ftell(f);
    fseek(f, 0L, SEEK_SET);
    int pointer = ftell(f);
    while (pointer != end)
    {
        base->ObjNum++;
        base->arr = (RightParallelepiped**)realloc(base->arr, base->ObjNum * sizeof(RightParallelepiped*));
        if (!base->arr)
        {
            printf("Memory is NULL");
            exit(1);
        }
        RightParallelepiped* Parallelepiped = FileConstructor(f);
        base->arr[base->ObjNum - 1] = Parallelepiped;
        pointer = ftell(f);
    }
}

void BasePrintStdout(Base* base)
{
    for (int i = 0; i < base->ObjNum; i++)
    {
        printf("Parallelepiped #%d:\n", i + 1);
        ParallelepipedPrint(base->arr[i]);
        printf("\n");
    }
}

void BasePrintFile(Base* base) //Outputting information to a file out.txt
{
    FILE* output = fopen("output.txt", "w");
    for (int i = 0; i < base->ObjNum; i++)
    {
        fprintf(output, "Parallelepiped #%d:\n", i + 1);
        ParallelepipedPrintFile(output, base->arr[i]);
        fprintf(output, "\n");
    }
    fclose(output);
}

Base* BaseConstructor() //Constructor for base of figure
{
    Base* base = (Base*)malloc(sizeof(Base));
    if (!base)
    {
        printf("Memory is NULL");
        exit(1);
    }

    base->ObjNum = 0;
    base->arr = (RightParallelepiped**)malloc(sizeof(RightParallelepiped*));
    if (!base->arr)
    {
        printf("Memory is NULL");
        exit(1);
    }

    return base;
}

void qsortRecursive(RightParallelepiped** arr, int KeyNumber, int size)
{
    int i = 0;
    int j = size - 1;
    double mid = 0.0f;
    int midAng = 0;
    RightParallelepiped* tmp = NULL;
    switch (KeyNumber)
    {
    case 1:
        mid = Height(arr[j / 2]);

        do
        {
            while (Height(arr[i]) < mid)
                i++;
            while (Height(arr[j]) > mid)
                j--;

            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);

        if (j > 0)
            qsortRecursive(arr, KeyNumber, j + 1);
        if (i < size)
            qsortRecursive(&arr[i], KeyNumber, size - i);
        break;
    case 2:
        mid = FirstRib(arr[j / 2]);

        do
        {
            while (FirstRib(arr[i]) < mid)
                i++;
            while (FirstRib(arr[j]) > mid)
                j--;

            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);

        if (j > 0)
            qsortRecursive(arr, KeyNumber, j + 1);
        if (i < size)
            qsortRecursive(&arr[i], KeyNumber, size - i);

        break;
    case 3:
        mid = SecondRib(arr[j / 2]);

        do
        {
            while (SecondRib(arr[i]) < mid)
                i++;
            while (SecondRib(arr[j]) > mid)
                j--;

            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);

        if (j > 0)
            qsortRecursive(arr, KeyNumber, j + 1);
        if (i < size)
            qsortRecursive(&arr[i], KeyNumber, size - i);

        break;
    case 4:
        mid = ThirdRib(arr[j / 2]);

        do
        {
            while (ThirdRib(arr[i]) < mid)
                i++;
            while (ThirdRib(arr[j]) > mid)
                j--;

            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);

        if (j > 0)
            qsortRecursive(arr, KeyNumber, j + 1);
        if (i < size)
            qsortRecursive(&arr[i], KeyNumber, size - i);

        break;

    case 5:
        mid = Radius(arr[j / 2]);

        do
        {
            while (Radius(arr[i]) < mid)
                i++;
            while (Radius(arr[j]) > mid)
                j--;

            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
                j--;
            }
        } while (i <= j);

        if (j > 0)
            qsortRecursive(arr, KeyNumber, j + 1);
        if (i < size)
            qsortRecursive(&arr[i], KeyNumber, size - i);

        break;
  
    }
}

void QuickSortMain(Base* base)
{
    int ans = 0;
    printf("Basing on which parameter do you wanna sort figures?\n");
    printf("1)Height\n 2)First Rib\n 3)Second Rib 4)Third Rib\n 5)Radius\n");
    scanf_s("%d\n", &ans);
    qsortRecursive(base->arr, ans, base->ObjNum);
}

int BinarySearchStdout(RightParallelepiped** arr, int KeyNumber, int size, double value, int point)
{

    int i = size / 2;

    double mid = 0.0f;
    if (size == 0)
    {
        printf("There is no such element!\n");
        return -1;
    }

    switch (KeyNumber)
    {
    case 1:
        mid = Height(arr[i]);

        if (value < mid)
        {

            BinarySearchStdout(arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchStdout(&arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    case 2:
        mid = FirstRib(arr[i]);

        if (value < mid)
        {
            BinarySearchStdout(arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchStdout(&arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    case 3:
        mid = SecondRib(arr[i]);

        if (value < mid)
        {
            BinarySearchStdout(arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchStdout(&arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    case 4:
        mid = ThirdRib(arr[i]);

        if (value < mid)
        {
            BinarySearchStdout(arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchStdout(&arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;
    case 5:
        mid = Radius(arr[i]);

        if (value < mid)
        {
            BinarySearchStdout(arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchStdout(&arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    }
    return -1;
}

int BinarySearchFile(FILE* output, RightParallelepiped** arr, int KeyNumber, int size, double value, int point)
{
    int i = size / 2;
    double mid = 0.0f;
    if (size == 0)
    {
        fprintf(output, "There is no such element!\n");
        return -1;
    }

    switch (KeyNumber)
    {
    case 1:
        mid = Height(arr[i]);

        if (value < mid)
        {

            BinarySearchFile(output, arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchFile(output, &arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    case 2:
        mid = FirstRib(arr[i]);

        if (value < mid)
        {

            BinarySearchFile(output, arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchFile(output, &arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    case 3:
        mid = SecondRib(arr[i]);

        if (value < mid)
        {

            BinarySearchFile(output, arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchFile(output, &arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    case 4:
        mid = ThirdRib(arr[i]);

        if (value < mid)
        {

            BinarySearchFile(output, arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchFile(output, &arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;
    case 5:
        mid = Radius(arr[i]);

        if (value < mid)
        {

            BinarySearchFile(output, arr, KeyNumber, i, value, point - 1);
        }
        else if (value > mid)
        {
            BinarySearchFile(output, &arr[i + 1], KeyNumber, size - i - 1, value, point + 1);
        }
        else
        {
            return point;
        }
        break;

    }

    return -1;
}

void BinarySearchMain(Base* base)
{
    int ans = 0;
    double value = 0;
    printf("What do you wanna find in Parallelepiped?\n");
    printf("1)Height\n 2)First Rib\n 3)Second Rib 4)Third Rib\n 5)Radius\n");
    scanf_s("%d", &ans);
    qsortRecursive(base->arr, ans, base->ObjNum);
    printf("What's the value of the chosen parameter?\n");
    scanf_s("%lf", &value);

    printf("If you wanna output the result in file, then type 1, else type 0.\n");
    int InputOrFile = 0;
    scanf_s("%d", &InputOrFile);
    if (InputOrFile)
    {
        FILE* output = fopen("output.txt", "w");
        int pointer = BinarySearchFile(output, base->arr, ans, base->ObjNum, value, (base->ObjNum / 2));
        if (pointer != -1)
        {
            fprintf(output, "The element was found:\n");
            ParallelepipedPrintFile(output, base->arr[pointer]);
            fprintf(output, "\n");
            fclose(output);
        }
    }
    else
    {
        int pointer = BinarySearchStdout(base->arr, ans, base->ObjNum, value, (base->ObjNum / 2));
        if (pointer != -1)
        {
            printf("The element was found:\n");
            ParallelepipedPrint(base->arr[pointer]);
            printf("\n");
        }

    }

}

int* SearchMultipleKeys(Base* base)
{
    int* PointersArray = (int*)malloc(base->ObjNum * sizeof(int));
    if (!PointersArray)
    {
        printf("Memory is NULL");
        exit(1);
    }

    RightParallelepiped** KeyArray = (RightParallelepiped**)malloc(base->ObjNum * sizeof(RightParallelepiped*));
    if (!KeyArray)
    {
        printf("Memory is NULL");
        exit(1);
    }

    int ans = 0;
    double value = 0;
    int size = base->ObjNum;
    int k = 0;

    for (size_t i = 0; i < size; i++)
    {
        KeyArray[i] = base->arr[i];
        PointersArray[i] = i;
    }

    do
    {
        k = 0;
        printf("What do you wanna find in Parallelepiped? Or press 0\n");
        printf("1)Height\n 2)First Rib\n 3)Second Rib 4)Third Rib\n 5)Radius\n");
        scanf_s("%d", &ans);
        if (!ans)
        {
            break;
        }
        qsortRecursive(base->arr, ans, size);
        qsortRecursive(KeyArray, ans, size);

        printf("What's the value of the chosen parameter?\n");
        scanf_s("%lf", &value);
        for (int i = 0; i < size; i++)
        {
            switch (ans)
            {
            case 1:
                if (value == Height(KeyArray[i]))
                {
                    KeyArray[k] = KeyArray[i];
                    PointersArray[k] = PointersArray[i];
                    k++;
                }
                break;
            case 2:
                if (FirstRib(KeyArray[i]) == value)
                {
                    KeyArray[k] = KeyArray[i];
                    PointersArray[k] = PointersArray[i];
                    k++;
                }
                break;
            case 3:
                if (SecondRib(KeyArray[i]) == value)
                {
                    KeyArray[k] = KeyArray[i];
                    PointersArray[k] = PointersArray[i];
                    k++;
                }
                break;
            case 4:
                if (ThirdRib(KeyArray[i]) == value)
                {
                    KeyArray[k] = KeyArray[i];
                    PointersArray[k] = PointersArray[i];
                    k++;
                }
                break;
            case 5:
                if (Radius(KeyArray[i]) == value)
                {
                    KeyArray[k] = KeyArray[i];
                    PointersArray[k] = PointersArray[i];
                    k++;
                }
                break;
            }

        }
        for (size_t i = k; i < size; i++)
        {
            PointersArray[i] = -1;
        }
        size = k;

    } while (ans != 0);

    if (PointersArray[0] == -1)
    {
        printf("Nothing\n");
        return;
    }
    free(KeyArray);
    return PointersArray;
}

void SearchMultipleKeysMain(Base* base)
{
    int* PointersArray = (int*)malloc(base->ObjNum * sizeof(int));
    if (!PointersArray)
    {
        printf("Memory is NULL");
        exit(1);
    }

    PointersArray = SearchMultipleKeys(base);
    printf("If you wanna output the result in file, then type 1, else 0.\n");
    int InputOrFile = 0;
    scanf_s("%d", &InputOrFile);
    if (InputOrFile)
    {
        FILE* output = fopen("output.txt", "w");
        for (int i = 0; PointersArray[i] != -1; i++)
        {
            int index = PointersArray[i];
            ParallelepipedPrintFile(output, base->arr[index]);
            fprintf(output, "\n");
        }
        fclose(output);

    }
    else
    {
        for (int i = 0; PointersArray[i] != -1; i++)
        {
            int index = PointersArray[i];
            ParallelepipedPrint(base->arr[index]);
            printf("\n");
        }
    }
    free(PointersArray);
    return;
}

void DeleteMultipleKeys(Base* base)
{
    int ans = 0;
    double value = 0;
    printf("Starting a deleting by multiple keys\n");

    int* PointerArray = SearchMultipleKeys(base);
    size_t i = 0;
    for (; PointerArray[i] != -1; i++)
    {
        swap(&base->arr[PointerArray[i]], &base->arr[base->ObjNum - 1 - i]);
    }
    for (size_t j = 0; j < i; j++)
    {
        DeleteLast(base);
    }
    printf("The object was successfully deleted.\n");

}

void DeleteLast(Base* base)
{
    MemDestructor(base->arr[base->ObjNum - 1]);
    base->ObjNum--;
    base->arr = (RightParallelepiped**)realloc(base->arr, base->ObjNum * sizeof(RightParallelepiped*));
}

void swap(RightParallelepiped** p1, RightParallelepiped** p2)
{
    RightParallelepiped* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void DeleteKey(Base* base)
{
    int ans = 0;
    double value = 0;
    printf("What do you wanna find in Parallelepiped?");
    printf("1)Height\n 2)First Rib\n 3)Second Rib 4)Third Rib\n 5)Radius\n");
    scanf_s("%d", &ans);
    qsortRecursive(base->arr, ans, base->ObjNum);
    printf("What's the value of the chosen parameter?\n");
    scanf_s("%lf", &value);

    int pointer = BinarySearchStdout(base->arr, ans, base->ObjNum, value, (base->ObjNum / 2));
    swap(&base->arr[pointer], &base->arr[base->ObjNum - 1]);
    DeleteLast(base);
    printf("Deleted.\n");
}
