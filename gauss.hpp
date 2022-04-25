#pragma once

#include <iostream>
#include <cmath>

 const int n = 10;
using namespace std;

void gauss_(long double a[n][n], long double b[n], long double x[n])
{
	long double eps = 1e-15;
	for(int k=0;k<n-1;k++)
	{
		if(fabs(a[k][k])<eps)
		{
			cout<<"Divide by Zero at "<<k<<endl;
			break;
		}
		for(int i=k+1;i<n;i++)
		{
			long double factor = a[i][k]/a[k][k];
			for(int j=k;j<n;j++)
            {
				a[i][j] -= factor*a[k][j];
            }
			    b[i] -= factor*b[k];
            
		}
    }
	x[n-1] = b[n-1]/a[n-1][n-1];
	for(int i=n-2;i>=0;i--)
	{
		long double sum = 0.e0;
		for(int j=i+1;j<n;j++)
        {
			sum += a[i][j]*x[j];
		    x[i]=(b[i]-sum)/a[i][i];
        }
	}
  
  
}

long double height_(long double t, long double a[n]){
	long double result = 0;
	for (int r = 0; r < n; r++)
	{
		result = result + a[r]*pow(t,r);
	}
	return result;
}

long double velocity_(long double t, long double a[n]){
	long double result = 0;
	for (int r = 1; r < n; r++)
	{
		result = result + r*a[r]*pow(t,r-1);
	}
	return result;
}

long double acceleration_(long double t, long double a[n]){
	long double result = 0;
	for (int r = 2; r < n; r++)
	{
		result = result + r*(r-1)*a[r]*pow(t,r-2);
	}
	return result;
}