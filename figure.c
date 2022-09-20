#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "figure.h"
#define M_PI

struct RightParallelepiped
{
	double Height;
	double FirstRib;
	double SecondRib;
	int ThirdRib;
	int Radius;
};

RightParallelepiped* FileConstructor(FILE* f) 
{
	RightParallelepiped* obj = (RightParallelepiped*)malloc(sizeof(RightParallelepiped));
	if (!obj)
	{
		return NULL;
	}

	fscanf_s(f, "%lf", &obj->Height);
	fscanf_s(f, "%lf", &obj->FirstRib);
	fscanf_s(f, "%lf", &obj->SecondRib);
	fscanf_s(f, "%d", &obj->ThirdRib);
	fscanf_s(f, "%d", &obj->Radius);

	return obj;
}

RightParallelepiped* Constructor()
{
	RightParallelepiped* obj = (RightParallelepiped*)malloc(sizeof(RightParallelepiped));
	if (!obj)
	{
		return NULL;
	}

	printf("Enter values of the parallelepiped\n");

	printf("Height of the parallelepiped: ");
	scanf_s("%lf", &obj->Height);

	printf("1st rib of the parallelepiped: ");
	scanf_s("%lf", &obj->FirstRib);
	
	printf("2nd rib of the parallelepiped: ");
	scanf_s("%lf", &obj->FirstRib);
	
	printf("3rd rib of the parallelepiped ");
	scanf_s("%d", &obj->ThirdRib);

	printf("The radius of the parallelepiped ");
	scanf_s("%d", &obj->Radius);
	
	return obj;
}

void ParallelepipedPrint(RightParallelepiped* Object)
{
	printf("Height - %lf\n", Object->Height);
	printf("First rib - %lf\n", Object->FirstRib);
	printf("Second rib - %lf\n", Object->SecondRib);
	printf("Third rib - %d\n", Object->ThirdRib);
	printf("Radius - %d\n", Object->Radius);
}

void ParallelepipedPrintFile(FILE* f, RightParallelepiped* Object)
{
	printf("Height - %lf\n", Object->Height);
	printf("First rib - %lf\n", Object->FirstRib);
	printf("Second rib - %lf\n", Object->SecondRib);
	printf("Third rib - %d\n", Object->ThirdRib);
	printf("Radius - %d\n", Object->Radius);
}

void MemDestructor(RightParallelepiped* Object)
{
	free(Object);
}

double AreaOfAllSurface(RightParallelepiped* Object)
{
	return  2.0 * (Object->FirstRib * Object->SecondRib + Object->SecondRib * Object->ThirdRib + Object->FirstRib * Object->ThirdRib);                                                         
}

double VolumeOfParallelepiped(RightParallelepiped* Object)
{
	return (Object->FirstRib * Object->SecondRib * Object->ThirdRib);
}

double Diagonal(RightParallelepiped* Object)
{
	return sqrtf(pow(Object->FirstRib, 2) + pow(Object->SecondRib, 2) + pow(Object->ThirdRib, 2), 2);
}

double AreaOfSideSurface(RightParallelepiped* Object)
{
	return   2.0 * (Object->FirstRib * Object->ThirdRib + Object->SecondRib * Object->ThirdRib);                                      
}

double VolumeOfSphere(RightParallelepiped* Object)
{
	return (4.0 * (pow(Object->Radius, 2)) * 3.14);
}

double Height(RightParallelepiped* Object)
{
	return Object->Height;
}

double FirtsRib(RightParallelepiped* Object)
{
	return Object->FirstRib;
}

double SecondRib(RightParallelepiped* Object)
{
	return Object->SecondRib;
}

double ThirdRib(RightParallelepiped* Object)
{
	return Object->ThirdRib;
}

double Radius(RightParallelepiped* Object)
{
	return Object->Radius;
}
