#pragma once

#include <iostream>
#include <cmath>

 const int n = 615;
const int dim_ = 9; /* ΒΑΛΕ 6,7,8*/

using namespace std;

void gauss_(long double a[dim_+1][dim_+1], long double b[dim_+1], long double x[dim_+1])
{
	long double eps = 1e-15;
	for(int k=0;k<dim_+1-1;k++)
	{
		if(fabs(a[k][k])<eps)
		{
			cout<<"Divide by Zero at "<<k<<endl;
			break;
		}
		for(int i=k+1;i<dim_+1;i++)
		{
			long double factor = a[i][k]/a[k][k];
			for(int j=k;j<dim_+1;j++)
            {
				a[i][j] -= factor*a[k][j];
            }
			    b[i] -= factor*b[k];
            
		}
    }
	x[dim_+1-1] = b[dim_+1-1]/a[dim_+1-1][dim_+1-1];
	for(int i=dim_+1-2;i>=0;i--)
	{
		long double sum = 0.e0;
		for(int j=i+1;j<dim_+1;j++)
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

void least_square_pol(long double x_[n], long double y_[n], long double x_ls_[n], long double der_1st_x_ls_[n], long double der_2nd_x_ls_[n]){
   long double X_[dim_+1][dim_+1];
   long double a_[dim_+1];
   long double b_[dim_+1];

    for (int i = 0; i < dim_+1; ++i) {
        b_[i] = 0;
        for (int k = 0; k < n; ++k) {
            b_[i] = b_[i] + y_[k]*pow(x_[k],i);
        }
        //cout<<"b"<<i<<" = "<<b_[i]<<"\n";
        for (int j = 0; j < dim_+1; ++j) {
            X_[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                    X_[i][j] = X_[i][j] + pow(x_[k],j+i);
            }
           // cout<<"X"<<i<<j<<" = "<<X_[i][j]<<"\n";
        }
    }

    gauss_(X_,b_,a_);
    for (int i = 0; i < n; ++i) {
        x_ls_[i] = 0;
        der_1st_x_ls_[i] = 0;
        der_2nd_x_ls_[i] = 0;
        for (int j = 0; j < dim_+1; ++j) {
            x_ls_[i] = x_ls_[i] + a_[j]*pow(x_[i],j);
        }
        for (int j = 1; j < dim_+1; ++j) {
            der_1st_x_ls_[i] = der_1st_x_ls_[i] + j*a_[j]*pow(x_[i],j-1);
        }
        for (int j = 2; j < dim_+1; ++j) {
            der_2nd_x_ls_[i] = der_2nd_x_ls_[i] + j*(j-1)*a_[j]*pow(x_[i],j-2);
        }
    }
}