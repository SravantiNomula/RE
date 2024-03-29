#include <iostream>
#include<cmath>

using namespace std;



double getElementLogisticCost(double &x, int &y, double &a, double &b);
double getLogisticCost(double x[], int y[], double a, double b, double &da, double &db);
void logisticRegression(double x[], int y[], double slope = 1, double intercept = 0);


double getElementLogisticCost(double &x, int &y, double &a, double &b)
	{
		double p = 1/(1+ exp(-(a*x+b)));
			if(y==1)
				{
					return -log(p);
				}
			else
				{
					return -log(1-p);
				}
	}


// slope:a
// intercept:b
// derivative of slope: da
// derivative of intercept: db






double getLogisticCost(double x[10], int y[10], double a, double b, double &da, double &db)
	{
		int n = 10;
		double cost=0;
		da = 0;
		db = 0;
			for(int i = 0; i<n;i++)
			{
				cost += getElementLogisticCost(x[i], y[i], a, b);
				double eaxb = exp(a*x[i]+b);
					if(y[i]==1)
						{
							da += -x[i]/(1+eaxb);
							db += -1/(1+eaxb);
						}
					else
						{
							da += x[i]*eaxb/(1+eaxb);
							db += eaxb/(1+eaxb);
						}
			}
		cost /= n;
		da /= n;
		db /=n;
		return cost;
	}
	
	
	
void logisticRegression(double x[10], int y[10], double slope , double intercept )
	{
		double lrate = 0.0005;
		double threshold = 0.001;
		int iter = 0;
			while(true)
				{
					double da = 0;
					double db = 0;
					double cost = getLogisticCost(x, y, slope, intercept, da, db);
					if(iter%500==0)
						{
							cout<<"Iter: "<<iter<< " cost = "<<cost<< " da = " << da << " db = "<<db<< endl;
						}
					iter++;
					if(abs(da) < threshold && abs(db) < threshold)
						{
							cout<<"p = 1/(1+exp(-("<<slope<<" * x + "<<intercept<<")))"<<endl;
							break;
						}
					slope -= lrate* da;
					intercept -= lrate * db;
				}
	}
	
	
	
