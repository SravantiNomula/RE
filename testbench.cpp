#include <iostream>
#include<cmath>

using namespace std;
void logisticRegression(double x[], int y[], double slope = 1, double intercept = 0);

int main() 
	{
		double A[10]={15,86,19,85,18,89,2,94,7,98};
		   int B[10]={0,1,0,1,0,1,0,1,0,1};

// create a dataset with inputs and labels
// for values [0, 20), assign label 0
// for values [80,100) assign label 1

		
// kick off our simple logisticRegression!

		logisticRegression(A, B, 1 ,0);
		return 0;
}
