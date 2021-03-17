#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

double sum_of_array(double a[], int len_of_array);
double add_1_to_first_element(double a[]);
double** combinations_of_2(double a[], int len_of_array);

class Timer {
    public:
        clock_t start;
        clock_t end;
        void start_time(){
            start = clock();
        }
        void print_time_taken(string s = ""){
            if (s != ""){
                cout << fixed ;
                cout << "Execution time taken by " << s << " is : " << (double) (clock() - start) / CLOCKS_PER_SEC << setprecision(5) << endl;
            }
            else {
                cout << fixed ;
                cout << "Execution time taken is : " << (double) (clock()- start) / CLOCKS_PER_SEC << setprecision(5) << endl;     
            }
        }
};

int main(){
    
    Timer t;

    int array_lengths[5] = {10, 100, 1000, 10000, 20000};
    int n = sizeof(array_lengths)/sizeof(array_lengths[0]);

    for(int i = 0; i < n; i++){
        cout << i << endl;
        int len_of_array = array_lengths[i];    
        cout << "Length of Array: " << len_of_array  << endl;
        double array[len_of_array];

        for(int j = 0; j < len_of_array; j++){
            array[j] = (double)rand() / RAND_MAX;
        }
        
        t.start_time();

        add_1_to_first_element(array);

        t.print_time_taken("add_1_to_first_element");



        t.start_time();
        
        sum_of_array(array, len_of_array);

        t.print_time_taken("sum_of_array");

        t.start_time();

        double** out = combinations_of_2(array, len_of_array);

        t.print_time_taken("combinations_of_2");

        cout << out[0][0] << ", " << out[0][1] << endl;

    }

}

double add_1_to_first_element(double a[]){
    return a[0] + 1;
}

double sum_of_array(double a[], int len_of_array){
    
    double total = 0.0; 
    for(int i = 0; i < len_of_array; i ++){
        total += a[i];
    }
    return total;
}

double** combinations_of_2(double a[], int len_of_array){
    int n = (len_of_array * (len_of_array - 1) / 2);
    double **two_d = new double * [n];
    for ( size_t i = 0; i < n; i++ ) two_d[i] = new double [2];
    int curr_count = 0;
    for(int i = 0; i < len_of_array - 1; i++){
        for(int j = i + 1; j < len_of_array; j++){
            two_d[curr_count][0] = a[i];
            two_d[curr_count][1] = a[j];
            curr_count++;    
        }
    }
    return two_d;
}
