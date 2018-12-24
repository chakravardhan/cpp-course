#include<stdio.h>
struct car
{
    int oper[6];
    float key[6];
    float mil[6];
    float size[6];
	float mil1[6];
	float per[6];
    
};

struct car cars[6];

int main()
{	
	int i,n,type,*b;
	float fueleff,fuelleft,**a,size,mil,per;
	FILE *in=fopen("input.txt","r");
	fscanf(in,"%d",&n);
	
	
	
	for(i=0;i<n;i++)
		{
		fscanf(in,"%d %f %f",&type,&fueleff,&fuelleft);
		cars[i].oper[i]=type;cars[i].key[i]=fueleff;cars[i].mil[i]=fuelleft;
		
		if(type==2)
			{
			fscanf(in,"%f",&size);
            cars[i].size[i]=size;
			cars[i].mil1[i]=0;
			cars[i].per[i]=0;
			}

		else if(type==3)
			{
			fscanf(in,"%f %f %f" ,&size,&mil,&per);
            cars[i].size[i]=size;
			cars[i].mil1[i]=mil;
			cars[i].per[i]=per;
			}
        else
            {
            cars[i].size[i]=0;
			cars[i].mil1[i]=0;
			cars[i].per[i]=0;
			}		
		}
	for(i=0;i<n;i++)
		{
		if(cars[i].oper[i]==1)
			printf("Car %d: range=%f\n",i+1,(cars[i].key[i]*cars[i].mil[i]));
		else if(cars[i].oper[i]==2)
			{
			printf("Car %d: range=%f\n",i+1,((cars[i].mil[i]*cars[i].size[i]*10)/cars[i].key[i]));
			}
		else
			{
			printf("Car %d: range=%f\n",i+1,((cars[i].mil1[i]*cars[i].size[i]*10)/cars[i].per[i])+(cars[i].key[i]*cars[i].mil[i]));
			}		
		}
	return 0;
}
