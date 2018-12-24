#include<stdio.h>
#include<stdlib.h>
struct car
{
    int oper;
    float key;
    float mil;
    float size;
	float mil1;
	float per;
    
};

//struct car cars[6];

int main(int argc, char* argv[])
{	
	int i,n,type;
	float fueleff,fuelleft,size,mil,per;
	FILE *in=fopen(argv[1],"r");
	fscanf(in,"%d",&n);
	struct car *cars = malloc(sizeof(struct car) * n);

	
	
	
	for(i=0;i<n;i++)
		{
		fscanf(in,"%d %f %f",&type,&fueleff,&fuelleft);
		cars[i].oper=type;cars[i].key=fueleff;cars[i].mil=fuelleft;
		
		if(type==2)
			{
			fscanf(in,"%f",&size);
            cars[i].size=size;
			cars[i].mil1=0;
			cars[i].per=0;
			}

		else if(type==3)
			{
			fscanf(in,"%f %f %f" ,&size,&mil,&per);
            cars[i].size=size;
			cars[i].mil1=mil;
			cars[i].per=per;
			}
        else
            {
            cars[i].size=0;
			cars[i].mil1=0;
			cars[i].per=0;
			}		
		}
	for(i=0;i<n;i++)
		{
		if(cars[i].oper==1)
			printf("Car %d: range=%f\n",i+1,(cars[i].key*cars[i].mil));
		else if(cars[i].oper==2)
			{
			printf("Car %d: range=%f\n",i+1,((cars[i].mil*cars[i].size*10)/cars[i].key));
			}
		else
			{
			printf("Car %d: range=%f\n",i+1,((cars[i].mil1*cars[i].size*10)/cars[i].per)+(cars[i].key*cars[i].mil));
			}		
		}
	return 0;
}
