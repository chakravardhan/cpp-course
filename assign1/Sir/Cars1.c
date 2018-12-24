
#include <stdio.h>

#define MAXCARS 100

struct d_car {
	float efficiency;
	float fuel;
};

struct e_car {
	float efficiency;
	float charge;
};

#define BATTERY_SIZE 100.0

struct d_car dcars[MAXCARS];
struct e_car ecars[MAXCARS];

void addDCar(int carIndex, float efficiency, float fuel_level) {
	dcars[carIndex].efficiency = efficiency;
	dcars[carIndex].fuel = fuel_level;
}

void addECar(int carIndex, float efficiency, float remCharge) {
	ecars[carIndex].efficiency = efficiency;
	ecars[carIndex].charge = remCharge;
}

double getDCarRange(int dcar) {
	return dcars[dcar].efficiency * dcars[dcar].fuel;
}

double getECarRange(int ecar) {
	return (BATTERY_SIZE * 1000.0/ecars[ecar].efficiency) * (ecars[ecar].charge / 100.0);
}

int main(int argc, char* argv[])
{
	int  carType[MAXCARS];
	
	int numCars, num_dcars, num_ecars;

	scanf("%d", &numCars);
	num_dcars = num_ecars = 0;

	int i;
	int ctype;
	for (i = 0; i < numCars; i++) {
		
		scanf("%d", &ctype);
		carType[i] = ctype;
		if (ctype == 1) {
			float efficiency, fuel_level;
			scanf("%f %f", &efficiency, &fuel_level);
			addDCar(num_dcars, efficiency, fuel_level);
			num_dcars++;
		}
		else if (ctype == 2) {
			float efficiency, remCharge;
			scanf("%f %f", &efficiency, &remCharge);
			addECar(num_ecars, efficiency, remCharge);
			num_ecars++;
		}
		else {
			printf("Oops - wrong car type\n"); 
			return 1;
		}
	}

	int dcar = 0, ecar = 0;
	for (i = 0; i < numCars; i++) {
		ctype = carType[i];
		double range;
		if (ctype == 1) {
			range = getDCarRange(dcar);
			dcar++;
		}
		else if (ctype == 2) {
			range = getECarRange(ecar);
			ecar++;
		}
		else {
			printf("Oops - wrong car type\n");
			return 1;
		}
		printf("Car%d: %.2f\n", i, range);
	}

	return 0;
}

