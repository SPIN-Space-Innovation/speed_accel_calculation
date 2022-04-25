#include <iostream>
#include <cmath>
#include "gauss.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){

    //ΥΠΟΡΟΥΤΙΝΑ ΠΟΥ ΔΙΑΒΑΖΕΙ ΚΑΙ ΑΠΟΘΗΚΕΥΕΙ ΤΑ ΔΕΔΟΜΕΝΑ ΑΠΟ ΤΟ CSV ΑΡΧΕΙΟ ΚΑΙ ΤΑ ΑΠΟΘΗΚΕΥΕΙ
    ifstream file("altimeter_flight2.csv");
    string line;
    string sval1, sval2;
    long double val1,val2;
    int N = 10000;
    long double xi[N];
    long double yi[N];
    int DIM = 0;
    long double height_max = 0;

    if(!file.is_open()){
        cout<<"problem!"<<endl;
    }
         while(getline(file,line))
         {
          stringstream ss(line);
           getline(ss,sval1,','); 
           val1 = stod(sval1);
           getline(ss,sval2,','); 
           getline(ss,sval2,',');
           val2 = stod(sval2);
           if(val2/100>20 ){
               xi[DIM] = ((double(int(val1)%1336531))/1000);
               yi[DIM] = (val2/100);
               if (DIM>5 && height_max < yi[DIM]){
                   height_max = yi[DIM];
               }
               DIM = DIM + 1;
            }
            if(height_max - yi[DIM-1] > 1){
                       break;
            }
         }
    
    file.close();
    cout<<"DIM = "<<DIM<<"\n";
    

    long double t[DIM]; 
    long double h[DIM];
    t[0] = xi[0];
    h[0] = yi[0];
    int e = 1;
    for (int u = 1; u < DIM; u++)
    {
        if (yi[u] != yi[u-1])
        {
            t[e] = xi[u];
            h[e] = yi[u];
            //cout<<"t"<<u<<" = "<<t[e]<<"  h"<<u<<" = "<<h[e]<<"\n";
            e = e+1;
        }
        else{
            if(u != DIM-1){
            t[e] = xi[u];
            h[e] = yi[u] + (yi[u+1] - yi[u-1])*(xi[u] - xi[u-1])/(xi[u+1] - xi[u-1]);
            e = e+1;
            }
        }  
    }
    DIM = e - 1;
    cout<<"DIM = "<<DIM<<"\n";
    
    
    long double A[n][n];
    long double coef[n];
    long double B[n];
    long double h2[DIM];
    long double velocity[DIM];
    long double acceleration[DIM];
    
    int i = 0;
    
    while (i < DIM){
        if(i%n == n - 1)
        {
            B[i%n] = h[i];
            for (int j = 0; j < n; j++)
            {
                A[i%n][j] = pow(t[i],j);
            };
            gauss_(A,B,coef);
            
            for (int m = 0; m < n; m++)
            {
                h2[i - n+1 + m] = height_(t[i-n+1+m],coef);
                velocity[i - n+1 + m] = velocity_(t[i-n+1+m],coef);
                acceleration[i - n+1 + m] = acceleration_(t[i-n+1+m],coef);

                cout<<"t"<<i-n+1+m<<" = "<<t[i-n+1+m]<<"   h"<<i-n+1+m<<" = "<<h[i-n+1+m]<<"   h"<<i-n+1+m<<" = "<<h2[i-n+1+m]<<"   u"<<i-n+1+m<<" = "<<velocity[i-n+1+m]<<"   a"<<i-n+1+m<<" = "<<acceleration[i-n+1+m]<<"\n";
            }
            
        }else
        {
             B[i%n] = h[i];
             for (int j = 0; j < n; j++)
             {
                 A[i%n][j] = pow(t[i],j);
             }
        }
        i = i + 1;
    }
    return 0;
}