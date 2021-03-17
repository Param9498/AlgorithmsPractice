#include <iostream>
using namespace std;

void passByValue(int x);
void passByReference(int *x);

int main(){
    int a = 13;

    passByValue(a);
    cout<<a<<endl;

    passByReference(&a);
    cout<<a<<endl;
    
}

void passByValue(int x){

    x = 99;
}

void passByReference(int *x){
    *x = 66;
}
