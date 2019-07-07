/* Array  ADT(abstract data-type)
author : Sourabh kumar
Implementing basic functionality of array.
The array is resizable i.e automatically make size = size*2 when full.
The array is created and maintained in heap not stack.
*/

#include <iostream>

using namespace std;

class Array
{
public:
	int *Ar;
	int size;
	int length;

	// array constructor 
	Array(int *A,int size,int length){
		this->Ar = A;
		this->size = size;
		this->length = length;
	}

	// print all the element present in the array
	void print_array(){
		cout << "---------------------------------"<<endl;
		cout <<"Array size : "<< size << endl;
		cout <<"Array length : "<< length << endl;
		cout << "elements of the array are : ";
		for (int i = 0; i < this->length; i++)
		{
			cout << this->Ar[i] << "  ";
		}
		cout<<endl;
		cout << "---------------------------------"<<endl;

	}

	// this method will resize the array to  size * 2
	void resize_array(int new_size,int old_size){
	int *temp = new int[new_size];

	for (int i = 0; i < old_size; i++)
	{
		temp[i] = this->Ar[i];
	}

	
	delete this->Ar;
	
	this->Ar = temp;

	temp = nullptr;
	this->size = new_size;
	}


	// append an element at the end of the array

	void append(int element){
    	if(this->length == this->size){
    		// resize the array 
    		resize_array(this->size * 2 ,this->size);
    		this->Ar[length] = element;
    		length ++;
		}
    	else{
    		this->Ar[length] = element;
    		length ++;
    	}
    }

    // insert the element at a given index

    void insert(int index,int element){
		// implement resize of array.
    	if(index >= 0 && index < length){
    	for(int i = length;i > index ; i--){
    		this->Ar[i] = this->Ar[i-1];
    	}
    	this->Ar[index] = element;
    	length ++;
    	}
    	else{
    		cout<<"Not a valid index"<<endl;
    	}
    	
    }

    // delete element from a given index

    void delete_el(int index){
		if(index >= 0 &&  index < length){
			int x = this->Ar[index];
			for (int i = index; i < length - 1; i++)
			{
				// shifting all the elements of the list.
				this->Ar[i] = this->Ar[i+1];

			}
			length --;
			
		}
	}

 	// Binary search for searching element in array

	int Binary_search_rec(int key,int h,int l){
		if(l <= h){
			int mid = (l+h)/2;
			if(key == this->Ar[mid])
				return mid;
			else if (key < this->Ar[mid])
				return Binary_search_rec(key,mid-1,l);
			else 
				return Binary_search_rec(key,h,mid + 1);
		}

		return -1;
	}

	// Get :  returns element at given index.
	int get(int index){
		if(index >=0 && index < length)
			return this->Ar[index];
		return -1;
	}

	// Set : replace the element at the given index.

	void set(int index,int x){
		if(index >= 0 && index < length)
			this->Ar[index] = x;
	}

	// Max : returns max element present in the array.
	int max(){
		int max = this->Ar[0];
		for(int i = 1;i< length;i++){
			if(this->Ar[i] > max)
				max = this->Ar[i];
		}
		return max;
	}

	// Min :
	int min(){
		int min = this->Ar[0];
		for(int i = 1;i< length;i++){
			if(this->Ar[i] < min)
				min = this->Ar[i];
		}
		return min;
	}

	// sum : returns sum of all the elements in the array.
    //  can be implemented using recursion.
	int sum(){
		int total = 0;
		for (int i = 0; i < length; i++)
			total += this->Ar[i];
		return total;
	}

	// Avg : 
	int avg(){
		int total = 0;
		for (int i = 0; i < length; i++)
			total += this->Ar[i];
		return (total/length);
	}

	// Reverse Array : 
	// For this we can use an Auxillary array or just swap using 2 index var. 
	void reverse_array(){
		
		for(int i = 0 ,j = length -1; i<j ; i++ , j--){
			int temp = this->Ar[i];
			this->Ar[i] = this->Ar[j];
			this->Ar[j] = temp;
			}
	}

	// rotate the array in a given direction.
	void rotate(string dir){
		if(dir == "left"){
			// rotate the array to the left.
			int Oth_el = this->Ar[0];
			for(int i = 0; i<length;i++){
				this->Ar[i] = this->Ar[i+1];
			}
			this->Ar[length-1] = Oth_el;  
		}
		else if(dir == "right")
		{
			// rotate the array to the right.
			int last_el = this->Ar[length -1];
			for(int i = length -1 ; i >= 0;i--){
				this->Ar[i] = this->Ar[i-1];
			}
			this->Ar[0] = last_el;
		}
	}

	// insert element in sorted list

	void insert_sorted_array(int el){
		if(is_sorted()){
			if(this->length == this->size)
				resize_array(this->size * 2,this->size);
			int i = length - 1;
			while(this->Ar[i] > el){
				this->Ar[i+1] = this->Ar[i];
				i--;
			}
			this->Ar[i+1] = el;
			this->length ++;
		}
		else{
			cout << "Array not sorted !!"<<endl;
		}
	}

	// check if the list is sorted or not
	bool is_sorted(){
		for(int i = 0;i < this->length -1 ;i++){
			if(this->Ar[i] > this->Ar[i+1])
				return false;
		}
		return true;
	}

};


int main(int argc, char const *argv[])
{
	
	Array a(new int[3],3,0);
	a.append(12);
	a.append(17);
	a.append(19);
	//a.append(19);
	a.print_array();

	/* a.insert(0,99);
	a.print_array();

	a.delete_el(0);
	a.print_array();

	cout << "element found at index : "<<a.Binary_search_rec(19,a.length,0)<<endl;
	cout << a.get(3)<<endl;
	a.set(0,1000);
	a.print_array();

	a.reverse_array();
	a.print_array();

	cout << "max and min element in array are :  (max) "<<a.max()<<"  (min) "<<a.min()<<""<<endl;

	cout << "sum of all el is "<<a.sum()<<endl;
	cout << "avg of all el is "<<a.avg()<<endl;

	cout << " rotate the array to left "<<endl;
	a.rotate("left");
	a.print_array();
	cout << " rotate the array to right "<<endl;
	a.rotate("right");
	a.print_array(); */

	a.insert_sorted_array(15);
	//a.insert_sorted_array(16);
	//a.insert_sorted_array(99);

	a.print_array();

	return 0;
}