

#include <stdio.h>
#include <malloc.h>


#define DIESEL 1
#define ELECTRIC 2
#define HYBRID 3

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

struct car {
	int ctype;
	union {
		DCar *dcar;
		ECar *ecar;
		HCar *hcar;
	} carData;
};

typedef struct car Car;

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

void addCar(Car *car) {
	int cartype;
	scanf("%d", &cartype);
	car->ctype = cartype;
	
	float deff, dfuel, efficiency, remCharge, bsize;
	switch (cartype) {
	case DIESEL:

		scanf("%f %f", &deff, &dfuel);
		DCar *dcar = (DCar *)malloc(sizeof(DCar));
		addDCar(dcar, deff, dfuel);
		car->carData.dcar = dcar;
		break;
	
	case ELECTRIC:

		scanf("%f %f %f", &efficiency, &remCharge, &bsize);
		ECar *ecar = (ECar *)malloc(sizeof(ECar));
		addECar(ecar, efficiency, remCharge, bsize);
		car->carData.ecar = ecar;
		break;
	
	case HYBRID:
		
		scanf("%f %f %f %f %f", &deff, &dfuel, &efficiency, &remCharge, &bsize);
		HCar *hcar = (HCar *)malloc(sizeof(HCar));
		addHCar(hcar, deff, dfuel, efficiency, remCharge, bsize);
		car->carData.hcar = hcar;
		break;
	
	default:
		printf("Oops - wrong car type\n");
		return;
		break;
	}
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


double getCarRange(Car *car) {
	double range;
	switch (car->ctype) {
	case DIESEL:
		range = getDCarRange(car->carData.dcar);
		break;
	case ELECTRIC:
		range = getECarRange(car->carData.ecar);
		break;
	case HYBRID:
		range = getHCarRange(car->carData.hcar);
		break;
	default:
		printf("Oops - wrong car type\n");
		range = -1.0;
		break;
	}
	return range;

}


int main(int argc, char* argv[])
{
	Car *cars;
	int numCars;

	scanf("%d", &numCars);
	cars = (Car *)malloc(numCars*sizeof(Car));

	int i;
	for (i = 0; i < numCars; i++) {
		addCar(&cars[i]);     /* also can be:     addCar(cars+i); */
	}

	for (i = 0; i < numCars; i++) {	
		double range = getCarRange(cars + i);
		printf("Car%d: %.2f\n", i, range);
	}

	return 0;
}

