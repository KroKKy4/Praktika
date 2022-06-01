#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mytype.h"


typedef struct cars bmw_m8;

bmw_m8* Constructor(char* car_number, int fuel, int mileage, int tuning, int drifting, int safety,int driving_skills) // пользователь записывает всю информацию о машине
{
	bmw_m8* bmw = malloc(sizeof(bmw_m8));
	if (!bmw)
		return NULL;

	if (fuel > 50)
		bmw->fuel = 50;
	else
		bmw->fuel = fuel;

	if (mileage)
		bmw->mileage;

	if (!tuning)
		bmw->speed = 100;
	else
		bmw->speed = 300;

	if (drifting == 1)
		bmw->safety = bmw->safety - 10;


	int slen = strlen(car_number);
	bmw->car_number = malloc(slen * sizeof(char));
	if (!bmw->car_number)
	{
		perror("Invalid car number");
		free(bmw);
		return NULL;
	}

	int i = 0;

	for (; i < slen; i++)
	{
		bmw->car_number[i] = car_number[i];

	}

	bmw->car_number[i] = '\0';

	return bmw;

}

void Volume_of_engine(bmw_m8 bmw)
{
	int mark_of_engine = 0;
	float volume = 0;
	scanf_s("%c", &volume);


	if (volume < 1) {
		printf("Weak car");
		mark_of_engine = 1;
	}

	if (volume > 1 && volume <= 2) {
		printf("Average car");
		mark_of_engine = 2;
	}
	if (volume > 2 && volume <= 3.5) {
		printf("Nice car");
		mark_of_engine = 3;
	}
	if (volume > 3.5 && volume <= 4.5) {
		printf("Very nice car");
		mark_of_engine = 4;
	}
	if (volume > 4.5) {
		printf("Amazing car");
		mark_of_engine = 5;
	}
	printf("\n");

}


void Refuel(bmw_m8 bmw,int fuel)
{
	bmw.fuel = 50;
	printf("Fuel is full.\n");
}



void tuning(int mark_of_engine, bmw_m8 bmw,int speed,int mileage,int beautiful,int safety)
{

	int ans = 0;
	printf("You want to make a tuning on your car?\n Print 1 if ans is yes, else 2");
	scanf_s("%d", &ans);
	printf("\n");


	if (ans == 1)
	{
		srand(time(NULL));

		printf_s("Print 'M' if you want more speed,'W' if you want new weels,'B' if you want new car brakes, or 'S' we can do rabdom customize");
		printf("\n");

		char probably_tuning = '\0';
		scanf_s("%c", &probably_tuning);

		if (probably_tuning == 'M')
		{
			printf("Good choise\n");
			bmw.speed = bmw.speed + 30;
			bmw.mileage = bmw.mileage - 10000;

		}

		if (probably_tuning == 'W')
		{
			printf("Good choise\n");
			bmw.beautiful = bmw.beautiful * 2;

		}

		if (probably_tuning == 'B')
		{
			printf("Good choise\n");
			bmw.safety = bmw.safety + 50;


		}

		if (probably_tuning == 'S')
		{
			printf("Surprise!!!\n");
			bmw.safety = bmw.safety + 25;
			bmw.speed = bmw.speed + 15;
			bmw.mileage = bmw.mileage - 8000;
		}
		else 
			printf("It`s your choise\n");

	}

}



void race(bmw_m8 bmw,int fuel,int mileage,int safety) {

	srand(time(NULL));
	printf("You see Volga. Let's destroy it.\n");

	bmw_m8* volga = Constructor("Volga", 228, 30, 350000, 0, 0, 0);
	char action = '\0';

	while (bmw.fuel > 0 && volga->fuel > 0) {

		printf("You on crossroad, wanna to make a competiton?\nPrint 'Y' if yes, else 'N'");
		scanf_s("%c", &action);

		if (action == 'Y')
		{
			int P_action = rand() % 2;

			if (P_action == 1)
			{
				bmw.fuel = bmw.fuel - 5;
				bmw.mileage = bmw.mileage + 5;
				bmw.safety = bmw.safety + 10;
				volga->fuel = volga->fuel - 10;
				volga->mileage = volga->mileage + 8;
				volga->safety = volga->safety - 5;
				print("You win\n");

			}
			else
			{
				bmw.fuel = bmw.fuel - 10;
				bmw.mileage = bmw.mileage + 10;
				bmw.safety = bmw.safety - 10;
				volga->fuel = volga->fuel - 5;
				volga->mileage = volga->mileage + 5;
				volga->safety = volga->safety + 5;
				print("You loose\n");
			}

		}
		else
			printf("No problems\n");
	
	}


}

void drifting(bmw_m8* bmw,int driving_skills,int safety) {

	if (driving_skills == 0) {

		printf("don`t drift please\n");
		bmw->safety = bmw->safety - 100;

	}
	if (driving_skills == 1) {

		printf("drift very accurate\n");
		bmw->safety = bmw->safety - 50;
	}
	if (driving_skills == 2) {

		printf("show your skills!!!\n");
		bmw->safety;
	}


}



bmw_m8* Destructor(bmw_m8* bmw)
{
	free(bmw->mileage);
	free(bmw->car_number);
	free(bmw->fuel);
	free(bmw->speed);
	free(bmw->beautiful);
	free(bmw->safety);
	free(bmw->drifting);
	free(bmw->driving_skills);
	free(bmw);
	return NULL;
}
