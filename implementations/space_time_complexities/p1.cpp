#include <iostream>
#include<cstdio>
#include<iomanip>

using namespace std;

int main(){
    clock_t start = clock();
    
    for(long i = 0; i <= 1000000000; i++){
    }
    double time_taken = (double)(clock() - start)/CLOCKS_PER_SEC;
    cout << fixed;
    cout << time_taken << setprecision(15) << endl;
}
