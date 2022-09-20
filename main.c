#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "figure.h"
#include "baza.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	Base* base = BaseConstructor();
	BasePrintStdout(base);
	DeleteMultipleKeys(base);
	BasePrintStdout(base);

	return 0;
}
