#include "mytype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	bmw_m8* bmw = Constructor("228", 50, 25000, 0, 100, 0, 1);
	bmw_m8* Constructor(char* car_number, int fuel, int mileage, int tuning, int safety, int drifting, int driving_skills);
	Volume_of_engine(*bmw);

	tuning(*bmw);

	Refuel(*bmw);

	race(*bmw);

	drifting(*bmw);

	Destructor(*bmw);
}
