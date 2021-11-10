#include <bits/stdc++.h>
using namespace std;
const double gam = 100.0;
const double n=100.0;
const double h=1.0/(n+1);
const double pi=3.14159265359;

int main(){
    vector<vector<double> >A(n,vector<double>(n,0));
    vector<vector<double> >L(n,vector<double>(n,0));
    vector<vector<double> >U(n,vector<double>(n,0));
    vector<double>v(n,0);
    vector<double>ans_v(n,0);
    vector<double>b(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                A[i][j]=gam+2.0/(h*h);
            }else if(abs(i-j)==1){
                if(i<j)U[i][j]=-1.0/(h*h);
                if(i>j)L[i][j]=-1.0/(h*h);
                A[i][j]=-1.0/(h*h);
            }else{
                A[i][j]=0.0;
            }
        }
        b[i]=(i+1)*h*sin((i+1)*h*pi);
    }
    //int cnt=0;
    while(1){
        for(int i=0;i<n;i++){
            double tmp=0.0;
            for(int j=0;j<n;j++){
                if(i!=j)tmp+=A[i][j]*v[j];
            }
            ans_v[i]=(1.0/A[i][i])*(b[i]-tmp);
        }
        double mx=0.0;
        for(int i=0;i<n;i++){
            mx=max(mx,abs(ans_v[i]-v[i]));
        }
        if(mx<10e-6)break;
        for(int i=0;i<n;i++){
            v[i]=ans_v[i];
        }
        //cnt++;
    }
    for(int i=0;i<n;i++){
        cout<<ans_v[i]<<" ";
    }
}