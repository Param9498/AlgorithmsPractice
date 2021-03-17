#include <iostream>
using namespace std;

int main(){
    int fish = 5;

    cout<<"The address of the variable fish using ampersand is : "<<&fish<<endl;
    
    int *fishpointer;

    fishpointer = &fish;
    
    cout<<"The address of the variable fish using pointers is : "<<fishpointer<<endl;

    cout<<"The value at the pointer is : "<<*fishpointer<<endl;


} 
