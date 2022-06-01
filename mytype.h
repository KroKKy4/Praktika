#pragma once
typedef struct cars
{
	char* car_number;
	int fuel;
	int mileage;
	int tuning;
	int speed;
	int beautiful;
	int safety;
	int drifting;
	int driving_skills;
} bmw_m8;

bmw_m8* Constructor(char* car_number, int fuel, int mileage, int tuning, int safety,int drifting,int driving_skills);

void Volume_of_engine(bmw_m8 bmw);

void tuning(bmw_m8 bmw);

void Refuel(bmw_m8 bmw);

void race(bmw_m8 bmw);

void drifting(bmw_m8 bmw);

bmw_m8* Destructor(bmw_m8 bmw);

