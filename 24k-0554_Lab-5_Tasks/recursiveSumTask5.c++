#include <iostream>
using namespace std;
int Sum(int n){
    if(n>=0 && n<=9){return n;}
    return Sum(n%10+Sum(n/10));
}
int main(){
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    cout<<"Sum of All digits until single digit: "<<Sum(n)<<endl;
}