
#include <stdio.h>

#define MAXCARS 100

struct d_car {
	float efficiency;
	float fuel;
};

typedef struct d_car DCar;

struct e_car {
	float efficiency;
	float charge;
	float bat_size;
};

typedef struct e_car ECar;

struct h_car {
	struct d_car dcar;
	struct e_car ecar;
};

typedef struct h_car HCar;

DCar dcars[MAXCARS];
ECar ecars[MAXCARS];
HCar hcars[MAXCARS];

void addDCar(DCar *car, float efficiency, float fuel_level) {
	car->efficiency = efficiency;
	car->fuel = fuel_level;
}

void addECar(ECar *car, float efficiency, float remCharge, float size) {
	car->efficiency = efficiency;
	car->charge = remCharge;
	car->bat_size = size;
}

void addHCar(HCar *car, float dEff, float dFuel, float efficiency, float remCharge, float size) {
	addDCar(&(car->dcar), dEff, dFuel);
	addECar(&(car->ecar), efficiency, remCharge, size);
}


double getDCarRange(DCar *car) {
	return car->efficiency * car->fuel;
}

double getECarRange(ECar *car) {
	return (car->bat_size * 1000.0/car->efficiency) * (car->charge / 100.0);
}

double getHCarRange(HCar *car) {
	return (getDCarRange(&(car->dcar)) + getECarRange(&(car->ecar)));
}


int main(int argc, char* argv[])
{
	int  carType[MAXCARS];
	
	int numCars, num_dcars, num_ecars, num_hcars;

	scanf("%d", &numCars);
	num_dcars = num_ecars = num_hcars = 0;

	int i;
	int ctype;
	for (i = 0; i < numCars; i++) {
		
		scanf("%d", &ctype);
		carType[i] = ctype;
		if (ctype == 1) {
			float efficiency, fuel_level;
			scanf("%f %f", &efficiency, &fuel_level);
			addDCar(&dcars[num_dcars], efficiency, fuel_level);
			num_dcars++;
		}
		else if (ctype == 2) {
			float efficiency, remCharge, bsize;
			scanf("%f %f %f", &efficiency, &remCharge, &bsize);
			addECar(&ecars[num_ecars], efficiency, remCharge, bsize);
			num_ecars++;
		}
		else if (ctype == 3) {
			float deff, dfuel, efficiency, remCharge, bsize;
			scanf("%f %f %f %f %f", &deff, &dfuel, &efficiency, &remCharge, &bsize);
			addHCar(&hcars[num_hcars],deff, dfuel, efficiency, remCharge, bsize);
			num_hcars++;
		}
		else {
			printf("Oops - wrong car type\n"); 
			return 1;
		}
	}

	int dcar = 0, ecar = 0, hcar = 0;
	for (i = 0; i < numCars; i++) {
		ctype = carType[i];
		double range;
		if (ctype == 1) {
			range = getDCarRange(&dcars[dcar]);
			dcar++;
		}
		else if (ctype == 2) {
			range = getECarRange(&ecars[ecar]);
			ecar++;
		}
		else if (ctype == 3) {
			range = getHCarRange(&hcars[hcar]);
			hcar++;
		}
		else {
			printf("Oops - wrong car type\n");
			return 1;
		}
		printf("Car%d: %.2f\n", i, range);
	}

	return 0;
}

