//phone.h
#ifndef PHONE_H
#define PHONE_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Phone
{
	protected:
		string mFirstName;
		string mCountry;
	
	public:
		Phone()
		{
			mFirstName="";
			mCountry="";
		}
		Phone(string Name,string Country)
		{
			mFirstName=Name;
			mCountry=Country;
		}
		virtual void printStats()
		{
			cout<<"Name:"<<mFirstName<<endl;
			cout<<"Country:"<<mCountry<<endl;
		} 
		virtual void printStats1()
		{
			cout<<"Country:"<<mCountry<<endl;
		}
		void display1()
		{
			cout<<"Name:"<<mFirstName<<endl;
			cout<<"Country:"<<mCountry<<endl;
		}
			
};

class SmartPhone: public Phone
{
	private:
		int i;
	protected:
		string mFirstName;
		string mCountry;
		string mmodel;
		string mmanufacture;
		string mmodelname;
		string mmodem;
		int mnomodems;
		long int mimei[5]; 
	
	
	public:
	
		SmartPhone(string Name,string Country,string model,string manufacture,string modelname,string modem,int nomodems,long int arr[]):Phone(Name,Country)
		{	
			mmodel=model;
			mmanufacture=manufacture;
			mmodelname=modelname;
			mmodem=modem;
			mnomodems=nomodems;
			for(i=0;i<mnomodems;i++)
			{
				mimei[i]=arr[i];
			}		
		}
		void printStats()
		{		
			Phone::printStats();
			cout<<"model:"<<mmodel<<endl;
			cout<<"manufacture name:"<<mmanufacture<<endl;
			cout<<"model name:"<<mmodelname<<endl;
			cout<<"modem:"<<mmodem<<endl;
			cout<<"nomodems:"<<mnomodems<<endl;
			for(i=0;i<mnomodems;i++)
			{
				cout<<"imei"<<i+1<<":"<<mimei[i]<<endl;
			}		
		}	
		
		void printStats1()
		{
			Phone::printStats1();
			cout<<"manufacture name:"<<mmanufacture<<endl;
		}		
		
		void display2()
		{
			cout<<"modem:"<<mmodem<<endl;
		}	
		
			
		
};

class Feature: public Phone
{
	protected:
		string mFirstName;
		string mCountry;
		string mmodel;
		string mmodem;
		int mnomodems;
		long int mimei;
	
	public:
		Feature()
		{
			mmodel="";
			mmodem="";
			mnomodems=0;
			mimei=0;
		}
		Feature(string Name,string Country,string model,string modem,int nomodems,long int imei):Phone(Name,Country)
		{
			mmodel=model;
			mmodem=modem;
			mnomodems=nomodems;
			mimei=imei;
		}
		void printStats()
		{
			Phone::printStats();
			cout<<"model:"<<mmodel<<endl;
			cout<<"modem:"<<mmodem<<endl;
			cout<<"nomodems:"<<mnomodems<<endl;
			cout<<"imei:"<<mimei<<endl;
		}
		
		void display()
		{
			cout<<mnomodems<<endl;
		}
			
		
};


#endif
