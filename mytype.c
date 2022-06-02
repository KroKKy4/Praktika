#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mytype.h"


typedef struct cars bmw_m8;

bmw_m8* Constructor(char* car_number, int fuel, int mileage, int tuning, int drifting, int safety, int driving_skills) // пользователь записывает всю информацию о машине
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

void Volume_of_engine(bmw_m8 bmw,int volume)
{
	int mark_of_engine = 0;
	scanf_s("%d", &volume);


	if (volume < 1) {
		printf("Weak car");
		mark_of_engine = 1;
	}

	if (volume > 1 && volume <= 2) {
		printf("Average car");
		mark_of_engine = 2;
	}
	if (volume > 2 && volume <= 4) {
		printf("Nice car");
		mark_of_engine = 3;
	}
	if (volume > 4 && volume <= 5) {
		printf("Very nice car");
		mark_of_engine = 4;
	}
	if (volume > 6) {
		printf("Amazing car");
		mark_of_engine = 5;
	}
	printf("\n");

}


void Refuel(bmw_m8 bmw, int fuel)
{
	bmw.fuel = 50;
	printf("Fuel is full.\n");
	printf("\n");
}



void tuning(int mark_of_engine, bmw_m8 bmw, int speed, int mileage, int beautiful, int safety)
{

	int ans = 1;
	printf("You want to make a tuning on your car?\n");
	printf("Print 1 if ans is yes, else 2 "); 
	scanf_s("%d", &ans);
	printf("\n");
	printf_s("Print '1' if you want more speed,'2' if you want new weels,'3' if you want new car brakes, or '4' we can do random customize");
	printf("\n");

	int probably_tuning = 0;
	scanf_s("%d", &probably_tuning);
	if (ans == 1)
	{
		

		if (probably_tuning == 1)
		{
			printf("Good choise\n");
			bmw.speed = bmw.speed + 30;
			bmw.mileage = bmw.mileage - 10000;

		}

		if (probably_tuning == 2)
		{
			printf("Good choise\n");
			bmw.beautiful = bmw.beautiful * 2;

		}

		if (probably_tuning == 3)
		{
			printf("Good choise\n");
			bmw.safety = bmw.safety + 50;


		}

		if (probably_tuning == 4)
		{
			printf("Surprise!!!\n");
			bmw.safety = bmw.safety + 25;
			bmw.speed = bmw.speed + 15;
			bmw.mileage = bmw.mileage - 8000;
		}
		

	}
	else
		printf("It`s your choise\n");
	printf("\n");

}



void race(bmw_m8 bmw, int fuel, int mileage, int safety) {

	srand(time(NULL));
	printf("You see Volga. Let's destroy it.\n");

	bmw_m8* volga = Constructor("Volga", 228, 30, 350000, 0, 0, 0);
	int action = 0;

	printf("You on crossroad, wanna to make a competiton?");
	printf("\n");
	printf("'1' if yes, else '2'");
	printf("\n");
	scanf_s("%d", &action);

	while (bmw.fuel > 0 && volga->fuel > 0) {

		if (action == 1)
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
				printf("You win\n");
				bmw.fuel = 0;

			}
			else
			{
				bmw.fuel = bmw.fuel - 10;
				bmw.mileage = bmw.mileage + 10;
				bmw.safety = bmw.safety - 10;
				volga->fuel = volga->fuel - 5;
				volga->mileage = volga->mileage + 5;
				volga->safety = volga->safety + 5;
				printf("You lose\n");
				volga->fuel = 0;
			}

		}
		else {
			printf("No problems\n");
			bmw.fuel = 0;
			volga->fuel = 0;

		}
		printf("\n");
			
		
	}


}

void drifting(bmw_m8* bmw, int driving_skills, int safety) {

	int skills = 0;
	printf("enter your driving skills, 0 - newbie, 1 - middle, 2 - pro");
	printf("\n");
	scanf_s("%d", &skills);

	if (skills == 0) {

		printf("don`t drift please");
		printf("\n");
		bmw->safety = bmw->safety - 100;

	}
	if (skills == 1) {

		printf("drift very accurate\n");
		printf("\n");
		bmw->safety = bmw->safety - 50;
	}
	if (skills == 2) {

		printf("show your skills!!!\n");
		printf("\n");
		bmw->safety;
	}

	printf("\n");
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
