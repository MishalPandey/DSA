#include <iostream>
using namespace std;

int qb[10000000];

int FibMemoized(int n){
    if(n==0 || n==1){
        return n;
    }
    if(qb[n]!=0){
        return qb[n];
    }

    int fibnm1= FibMemoized(n-1);
    int fibnm2= FibMemoized(n-2);
    int fibn= fibnm1+ fibnm2;
    qb[n]= fibn;
    return fibn;

}

int main(){
    int n;
    cin>>n;
    cout<<FibMemoized(n)<<endl;
    return 0;
}
