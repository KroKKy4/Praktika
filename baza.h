#pragma once
struct Base;
typedef struct Base Base;

Base* BaseConstructor();

void InputStdin(Base* base);

void InputFile(FILE* f, Base* base);

void BasePrintStdout(Base* base);

void BasePrintFile(Base* base);

void qsortRecursive(RightParallelepiped** arr, int KeyNumber, int size);

void QuickSortMain(Base* base);

int BinarySearchStdout(RightParallelepiped** arr, int KeyNumber, int size, double value, int point);

int BinarySearchFile(FILE* output, RightParallelepiped** arr, int KeyNumber, int size, double value, int point);

void BinarySearchMain(Base* base);

int* SearchMultipleKeys(Base* base);

void SearchMultipleKeysMain(Base* base);

void DeleteMultipleKeys(Base* base);

void swap(RightParallelepiped** p1, RightParallelepiped** p2);

void DeleteLast(Base* base);

void DeleteKey(Base* base);
