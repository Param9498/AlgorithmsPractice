#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <class T>
class DynamicArray{
private:
	T* arr;
	int current_position;
	int size;
	int capacity;
	int GROWTH_FACTOR;

public:
	// 1. Constructor
	DynamicArray(int min_size = 1){

		this->arr = new T[min_size];

		this->capacity = min_size;
		this->size = 0;

		this->GROWTH_FACTOR = 2;
	}

	// 2. Destructor
	~DynamicArray(){
		delete [] this->arr;
	}

	// 3. Push
	void push(T value){
		if (this->size == this->capacity){
			int new_capacity = this->capacity * this->GROWTH_FACTOR;

			this->resize(new_capacity);
		}

		// Push the element to the end of array
		this->arr[size] = value;
		this->size += 1;

		// If array full then increase size of array
		if (this->size == this->capacity){
			int new_capacity = this->capacity * this->GROWTH_FACTOR;

			this->resize(new_capacity);
		}
	}

	// 4. Pop
	T pop(){
		T value = this->arr[this->size-1];
		this->arr[this->size-1] = 0;
		this->size--;

		return value;
	}

	// 5. Remove
	void remove(int index){

		if (index >= 0 && index < this->size){
			for(int i = index + 1; i < this->size; i++){
				this->arr[i-1] = this->arr[i];
			}
			this->arr[this->size-1] = 0;
			this->size--;
		}
	}

	// 6. Insert
	void insert(int index, T value){
		if (index >= 0 && index < this->size){
			for(int i = index; i < this->size; i++){
				this->arr[i+1] = this->arr[i];
			}
			this->arr[index] = value;
			this->size ++;
		}
		else {
			cerr << "INDEX OUT OF BOUNDS" << endl;
		}
		if (this->size == this->capacity){
			int new_capacity = this->capacity * this->GROWTH_FACTOR;
			this->resize(new_capacity);
		}
	}

	// 7. Replace
	void replace(int index, T value){
		if (index >= 0 && index < this->size){
			this->arr[index] = value;
		}
	}

	// 8. Resize
	void resize(int new_capacity){
		// Check if the new_capacity is bigger than previous capacity
		if (new_capacity >= this->size){
			
			T* new_array = new T[new_capacity];

			for (int i = 0; i < this->size; i++){
				new_array[i] = this->arr[i];
			}

			delete [] this->arr;

			this->arr = new_array;

			this->capacity = new_capacity;
		}
		else{
			cout << "New size cannot be smaller than the number of elements in the array " << endl;
		}
	}

	// 9. Printing Entire array;
	void print(){
		for (int i = 0; i < this->capacity; i++){
			cout << this->arr[i] << " ";
		}
		cout<<endl;
	}

	T get(int index){
		if (index >= 0 && index < this->size){
			return this->arr[index];
		}
		else{
			cout<<"NOT IN RANGE"<<endl;
		}
	}
};

int main(){

	DynamicArray<int> dynamic_arr(1);

	while(true){

		cout << "---------------------------------------------------" << endl;
		cout << "Choose from the following" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Remove" << endl;
		cout << "4. Insert" << endl;
		cout << "5. Replace" << endl;
		cout << "6. Resize" << endl;
		cout << "7. Print" << endl;
		cout << "8. Quit" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Please Enter your choice: " << endl;

		int choice = 7;
		cin >> choice;

		bool exit = false;
		int a, b;

		switch(choice) {
			case 1:
				cout<< "Array before operation : ";
				dynamic_arr.print();

				cout << "Enter element to be pushed: " << endl;
				
				cin >> a;
				dynamic_arr.push(a);

				cout<< "Array after operation : ";
				dynamic_arr.print();
				break;

			case 2:
				cout<< "Array before operation : ";
				dynamic_arr.print();

				dynamic_arr.pop();

				cout<< "Array after operation : ";
				dynamic_arr.print();
				break;

			case 3:
				cout<< "Array before operation : ";
				dynamic_arr.print();

				cout << "Enter index from which to remove: " << endl;
				
				cin >> a;

				dynamic_arr.remove(a);

				cout<< "Array after operation : ";
				dynamic_arr.print();
				break;

			case 4:
				cout<< "Array before operation : ";
				dynamic_arr.print();

				cout << "Enter index at which to insert: " << endl;
				
				cin >> a;

				cout << "Enter value to insert: " << endl;
				
				cin >> b;

				dynamic_arr.insert(a, b);
				
				cout<< "Array after operation : ";
				dynamic_arr.print();
				break;

			case 5:
				cout<< "Array before operation : ";
				dynamic_arr.print();

				cout << "Enter index at which to replace: " << endl;
				
				cin >> a;

				cout << "Enter value to replace with: " << endl;
				
				cin >> b;

				dynamic_arr.replace(a, b);
				
				cout<< "Array after operation : ";
				dynamic_arr.print();
				break;

			case 6:
				cout<< "Array before operation : ";
				dynamic_arr.print();

				cout << "Enter new size: " << endl;
				
				cin >> a;

				dynamic_arr.resize(a);
				
				cout<< "Array after operation : ";
				dynamic_arr.print();
				break;

			case 7:
				dynamic_arr.print();
				break;

			case 8:
				exit = true;

			default : 
				cout << "Wrong Choice";
			  	
		}

		if (exit == true){
			break;
		}
	}
	return 0;
}