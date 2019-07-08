// Implementation of generic Array ADT.

/*
author : sourabh
about : 1. implementation of resizable array i.e automatically becomes size = size * 2 when full.
		2. can store any type of data i.e int,float,char,string etc.
 
*/

#include <iostream>

using namespace std;

template <class T>

class Array{
private:
	T *Ar;
	int length;
	int size;
	void resize_array(int new_size,int old_size);
public:
	Array(int sz){
		size = sz;
		length = 0;
		Ar = new T [size];
	}

	Array(){
		Ar = new T[10];
		size = 10;
		length = 0;
	}

	~Array(){
		delete [] Ar;
	}

	void append(T element);

	void print_array(bool all = false);
	void insert(int index,T element);
	void delete_el(int index);
	int  search(T key);
	bool is_sorted();
	int linear_search(T key);
	int binary_search(T key,int h,int l);
	void set(int index,T x);
	int get(int index);
	int max();
	int min();
	int sum();
	int avg();
	void reverse_array(bool useAux);
	void rotate(string dir);
	void insert_sorted_array(T el);

};

template<class T>
int Array<T>::linear_search(T key){
	if (length > 0)	
	{
		for (int i = 0; i < length; i++)
		{
			if(key == Ar[i])
				return i;
		}
	}
	return -1;
}


template<class T>
bool Array<T>::is_sorted(){
	for(int i = 0;i < length -1 ;i++){
			if(Ar[i] > Ar[i+1])
				return false;
		}
		return true;
}

template <class T>
void Array<T>:: append(T element){
    	if(length == size){
    		// resize the array 
    		resize_array(size * 2 ,size);
    		Ar[length] = element;
    		length ++;
		}
    	else{
    		Ar[length] = element;
    		length ++;
    	}
    }
template <class T>
void Array<T>:: resize_array(int new_size,int old_size){
	T *temp = new T[new_size];

	for (int i = 0; i < old_size; i++)
	{
		temp[i] = Ar[i];
	}

	
	delete Ar;
	
	Ar = temp;

	temp = nullptr;
	size = new_size;
	}

template<class T>
void Array<T>:: print_array(bool all){
	if(length >= 1){
		if(all){
			cout << "size  :"<<size<<endl;
			cout << "length:"<<length<<endl;
			cout << "Array : ";
		for (int i = 0; i < length; i++)
		{
			cout << Ar[i]<<" ";
		}
		cout << endl;
		}
		else{
			cout << "Array : ";
		for (int i = 0; i < length; i++)
		{
			cout << Ar[i]<<" ";
		}
		cout << endl;
		}
	}
}

template<class T>
void Array<T>::insert(int index,T element){
	if(index >= 0 && index < length){
		if (length == size)
			resize_array(size *2 ,size);
    	for(int i = length;i > index ; i--){
    		Ar[i] = Ar[i-1];
    	}
    	Ar[index] = element;
    	length ++;
    	}
    	else{
    		cout<<"Not a valid index"<<endl;
    	}
}

template<class T>
void Array<T>::delete_el(int index){
	if(index >= 0 &&  index < length){
			int x = Ar[index];
			for (int i = index; i < length - 1; i++)
			{
				// shifting all the elements of the list.
				Ar[i] = Ar[i+1];

			}
			length --;
			
		}
		else
		{
			cout << "Not a valid index !!"<<endl;
		}
}

template<class T>
int  Array<T>::binary_search(T key,int h,int l){
	while(l <= h){
			int mid = (l+h)/2;
			if(key == Ar[mid])
				return mid;
			else if(key < Ar[mid])
				h = mid -1 ;
			else 
				l = mid + 1;
		}
		return -1;
}

template<class T>
int  Array<T>::search(T key){
	T result;
	if(is_sorted())
		result = binary_search(key,length,0);
	else
		result = linear_search(key);
	return result;
}

template<class T>
int  Array<T>::get(int index){
		if(index >=0 && index < length)
			return Ar[index];
	return -1;
	}

	// Set : replace the element at the given index.

template<class T>
void  Array<T>::set(int index,T x){
		if(index >= 0 && index < length)
			Ar[index] = x;
	}

	// Max : returns max element present in the array.
template<class T>
int  Array<T>::max(){
		int max = Ar[0];
		for(int i = 1;i< length;i++){
			if(Ar[i] > max)
				max = Ar[i];
		}
		return max;
	}

	// Min :
template<class T>
int  Array<T>::min(){
		int min = Ar[0];
		for(int i = 1;i< length;i++){
			if(Ar[i] < min)
				min = Ar[i];
		}
		return min;
	}

	// sum : returns sum of all the elements in the array.
    //  can be implemented using recursion.
template<class T>
int  Array<T>::sum(){
		int total = 0;
		for (int i = 0; i < length; i++)
			total += Ar[i];
		return total;
	}

	// Avg : 
template<class T>
int  Array<T>::avg(){
		int total = 0;
		for (int i = 0; i < length; i++)
			total += Ar[i];
		return (total/length);
	}

template<class T>
void  Array<T>::reverse_array(bool useAux){
		if(!useAux){
			for(int i = 0 ,j = length -1; i<j ; i++ , j--){
				T temp = Ar[i];
				Ar[i] = Ar[j];
				Ar[j] = temp;
			}

		}
		else{
			T *aux_array;
			aux_array = new T[size];
			for(int i = length - 1 ,j = 0 ; i >=0 ; i--,j++){
				aux_array[j] = Ar[i];
			}

			for(int i = 0 ;i < length ; i++){
				Ar[i] = aux_array[i];
			}
		
		}
	}

template<class T>
void  Array<T>::rotate(string dir){
		if(dir == "left"){
			// rotate the array to the left.
			T Oth_el = Ar[0];
			for(int i = 0; i<length;i++){
				Ar[i] = Ar[i+1];
			}
			Ar[length-1] = Oth_el;  
		}
		else if(dir == "right")
		{
			// rotate the array to the right.
			T last_el = Ar[length -1];
			for(int i = length -1 ; i >= 0;i--){
				Ar[i] = Ar[i-1];
			}
			Ar[0] = last_el;
		}
	}

template<class T>
void  Array<T>::insert_sorted_array(T el){
		if(is_sorted()){
			if(length == size)
				resize_array(size * 2,size);
			int i = length - 1;
			while(Ar[i] > el){
				Ar[i+1] = Ar[i];
				i--;
			}
			Ar[i+1] = el;
			length++;
		}
		else{
			cout << "Array not sorted !!"<<endl;
		}
	}


int main(int argc, char const *argv[])
{
	// testing the code.

	/*Array<int> ar(1);
	ar.append(12);
	ar.insert(0,100);
	ar.insert(0,99);
	ar.insert(1,101);
	ar.insert(2,104);
	ar.delete_el(0);
	ar.print_array(true);
	cout << ar.search(12)<<endl;
	cout << ar.get(0)<<endl;
	ar.set(0,999);
	ar.print_array();
	cout << ar.min()<<endl;
	cout << ar.max()<<endl;
	cout << ar.sum()<<endl;
	cout << ar.avg()<<endl;
	ar.print_array();
	cout << "reversing the array ::"<<endl;
	ar.reverse_array(false);
	ar.print_array();
	ar.reverse_array(true);
	ar.print_array();
	cout << "rotating the array ::"<<endl;
	ar.rotate("left");
	ar.print_array();
	ar.rotate("right");
	ar.print_array();


	ar.insert_sorted_array(12);


	cout << "new array ::"<<endl;

	Array<int> a1;

	a1.append(1);
	a1.append(12);
	a1.append(13);
	a1.append(14);
	a1.print_array();
	a1.insert_sorted_array(4);
	a1.print_array(); */

	Array<char> name(10);

	name.append('S');
	name.append('o');
	name.append('u');
	name.append('r');
	name.append('a');
	name.append('b');
	name.append('h');
	name.print_array();
	name.reverse_array(false);
	name.print_array();
	name.rotate("left");
	name.print_array();
	name.rotate("right");
	name.print_array();
	cout << (char)name.min()<<endl;
	cout << (char)name.max()<<endl;

	Array<string> fruits;
	fruits.append("banana");
	fruits.append("apple");
	fruits.print_array();

	return 0;
}
