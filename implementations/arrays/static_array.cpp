#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class StaticArray {

    public:

        StaticArray(int size, string dtype){
            if (dtype == "int"){

                this->arr = new int[size];
            }
            else {
                this->arr = new int[size];
            }
            
            this->current_pointer = -1;

            this->size = size;
        }

        void append(int val){
            if (this->current_pointer < this->size){
                this->arr[++this->current_pointer] = val;
            }
        }

        void insert_at(int index, int val){
            int* new_arr = new int[this->size + 1];

            int counter = 0;

            for (int i = 0 ; i < this->size + 1; i++){
                if (i == index){
                    new_arr[i] = val;
                }
                else{
                    new_arr[i] = this->arr[counter];
                    counter++;
                }
            }

            delete [] this->arr;

            this->arr = new_arr;

            this->size += 1;
        }

        int pop_at(int index){
            int* new_arr = new int[this->size - 1];

            int counter = 0;

            int to_be_returned = -1;

            for (int i = 0; i < this->size; i++){
                if (i != index){
                    new_arr[counter] = this->arr[i];
                    counter++;
                }
                else
                    to_be_returned = this->arr[i];
            }

            delete [] this->arr;

            this->arr = new_arr;

            this->size -= 1;

            return to_be_returned;
        }

        void print(){
            for(int i = 0; i < this->size; i++){
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }

        ~StaticArray(){
            delete [] this->arr;
        }
    
    private:
        int *arr;
        int current_pointer;
        int size;

};

int main(){
    
    StaticArray arr = StaticArray(5, "int");

    arr.append(5);
    arr.append(7);
    arr.print();
    arr.insert_at(1, 6);
    arr.print();

    arr.pop_at(2);
    arr.print();

}
