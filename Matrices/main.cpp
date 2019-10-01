/*
 Author : Sourabh kumar
 about : Matrix implementation.
 */

#include <iostream>

using namespace std;

// Base class for all type of matrices.
class Matrix{
public:
    int *A;
    int rows;
    int cols;
    ~Matrix(){
        // Matrix object will be destroyed.
    }
};

// diagonal matrix.
class DiagonalMatrix : public Matrix{
public:
    DiagonalMatrix(){
        A = new int [10]();
        rows = 10;
        cols = 10;
    }
    DiagonalMatrix(int i,int j){
        A = new int[i]();
        rows = i;
        cols = j;
    }
    void set(int i,int j,int x){
        if(i == j){
            A[i-1] =  x;
        }
    }
    int get(int i,int j){
        if(i == j){
            return A[i-1];
        }
        else
            return -1;
    }
    void display(){
        int i,j;
        for(i = 0; i<rows ; i++){
            for(j = 0; j<rows ; j++){
                if(i == j)
                    cout << A[i]<< " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
    ~DiagonalMatrix(){
        // DiagonalMatrix object will be destroyed.
    }
};

// Lower Triangular matrix
class LowerTriangularMatrix : public Matrix {
private:
    bool rowMajor;
public:
    LowerTriangularMatrix(int i,int j,bool rowMajor = true){
        // we have to calculate size of 1-D array.
        if(i != j)
            cout << "Not a valid shape for lower triangular matrix"<<endl;
        else {
        int n = (i*(i+1))/2;
        A = new int[n]();
        rows = i;
        cols = j;
        this->rowMajor = rowMajor;
        }
        }
    
    void set(int i,int j,int x){
        // row or column major
            if(rowMajor){
                // store the element in row major form.
                // calc the index using row major formulae.
                if(i >= j)
                    A[(i*(i-1)/2) + j-1] = x;
            }
            else{
                // store the element in column major form.
                // calc the index using column major formulae.
                if(i >= j)
                    A[((rows * (j-1)) - ((j-2)*(j-1))/2) + (i-j)] = x;
                
            }
        
    }
    
    int get(int i,int j){
        if(i >= j){
            if(this->rowMajor){
                  int index  = ((i*(i-1))/2) + (j-1);
                  return A[index];
            }
            else
            {
                    int index = ((rows * (j-1)) - ((j-2)*(j-1))/2) + (i-j);
                    return A[index];
            }
        }
        else
            return 0;
    }
    
    void display(){
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if(i >= j){
                    // see if the matrix is stored in row or column major form.
                    if(this->rowMajor){
                        // index calc
                        int index  = ((i*(i-1))/2) + (j-1);
                        cout << A[index] << " ";
                    }
                    else{
                        // index calc for column major.
                         int index = ((rows * (j-1)) - ((j-2)*(j-1))/2) + (i-j);
                        cout << A[index] << " ";
                    }
                }
                else{
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
};

// Upper Triangular matrix.
class UpperTriangularMatrix : public Matrix{
private:
    bool rowMajor;
public:
    UpperTriangularMatrix(int i,int j,bool rowMajor){
        // we have to calculate size of 1-D array.
        if(i != j)
            cout << "Not a valid shape for Upper triangular matrix"<<endl;
        else {
        int n = (i*(i+1))/2;
        A = new int[n]();
        rows = i;
        cols = j;
        this->rowMajor = rowMajor;
        }
        
    }
    
    void set(int i,int j,int x){
        // row or column major
            if(rowMajor){
                // store the element in row major form.
                // calc the index using row major formulae.
                if(i <= j)
                    A[((rows * (i-1)) - ((i-2)*(i-1))/2) + (j-i)] = x;
            }
            else{
                // store the element in column major form.
                // calc the index using column major formulae.
                if(i <= j)
                    A[j*(j-1) / 2 + (i-1)] = x;
                
            }
        
    }
    
    int get(int i,int j){
        if(i <= j){
            if(this->rowMajor){
                  int index  = ((rows * (i-1)) - ((i-2)*(i-1))/2) + (j-i);
                  return A[index];
            }
            else
            {
                    int index = j*(j-1) / 2 + (i-1);
                    return A[index];
            }
        }
        else
            return 0;
    }
    
    void display(){
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if(i <= j){
                    // see if the matrix is stored in row or column major form.
                    if(this->rowMajor){
                        // index calc
                        int index  = ((rows * (i-1)) - ((i-2)*(i-1))/2) + (j-i);
                        cout << A[index] << " ";
                    }
                    else{
                        // index calc for column major.
                         int index = j*(j-1) / 2 + (i-1);
                        cout << A[index] << " ";
                    }
                }
                else{
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
    
};


// Symmetric matrix:
class SymmetricMatrix : public Matrix{
  
    // this class will reperesent symmetric matrix.
    // as we have seen we can reperesent symmetric matrix using 1-D array.
public:
        SymmetricMatrix(int i,int j){
            // we have to calculate size of 1-D array.
            if(i != j)
                cout << "Not a valid shape for Symmetric  matrix"<<endl;
            else {
            int n = (i*(i+1))/2; // size of the array.
            A = new int[n]();
            rows = i;
            cols = j;
            }
            
        }
        
        void set(int i,int j,int x){
                    // store the element in row major form.
                    if(i >= j)
                        A[(i*(i-1)/2) + j-1] = x;

            }
        
        int get(int i,int j){
            
                 int index  = ((i*(i-1))/2) + (j-1);
                 return A[index];
            }
        
        void display(){
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= cols; j++) {
                    if(i >= j){
                        // see if the matrix is stored in row or column major form.
                        
                            // index calc
                            int index  = ((i*(i-1))/2) + (j-1);
                            cout << A[index] << " ";
                        
                    }
                    else{
                        cout << get(j, i) << " ";
                    }
                }
                cout << endl;
            }
        }

};

// Tri-diagonal matrix:
class TriDiagonalMatrix : public Matrix{
  
    // this module will implement tri-diagonal matrix.
    public:
    TriDiagonalMatrix(int i,int j){
        // we have to calculate size of 1-D array.
        if(i != j)
            cout << "Not a valid shape for Tri-diagonal matrix"<<endl;
        else {
        int n = (3*i) - 2; // size of the array.
        A = new int[n]();
        rows = i;
        cols = j;
        }
        
    }
    
    void set(int i,int j,int x){
                // store the element in diagonal form.
                // we have to calculate index for all 3 cases.
                if(i - j  == 1) // lower diagonal
                    A[i-1] = x;
                else if(i - j == 0) // main diagonal
                    A[(rows - 1) + i-1] = x;
                else if(i - j  == -1) // upper diagonal
                    A[2*rows - 1 + i-1] = x;

        }
    
    int get(int i,int j){
        if(i - j  == 1) // lower diagonal
            return A[i-1];
        else if(i - j == 0) // main diagonal
            return A[(rows - 1) + i-1];
        else if(i - j  == -1) // upper diagonal
            return A[(2*rows - 1) + i-1];
        else
            return -1;
        
    }
    
    void display(){
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if(i - j == 1)
                    cout << A[i-1] << " ";
                else if(i - j == 0)
                    cout << A[(rows - 1) + i-1] << " ";
                else if(i - j == -1)
                    cout << A[2*rows - 1 + i-1] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }

    
};

// Toeplitz matrix.
class ToeplitzMatrix : public Matrix{
  
    // this module will implement tri-diagonal matrix.
    public:
    ToeplitzMatrix(int i,int j){
        // we have to calculate size of 1-D array.
        if(i != j)
            cout << "Not a valid shape for Toeplitz matrix"<<endl;
        else {
        int n = (2*i) - 1; // size of the array.
        A = new int[n]();
        rows = i;
        cols = j;
        }
        
    }
    
    void set(int i,int j,int x){
                // store the element in diagonal form.
                
                if(i  <= j) // elements are in upper triangular part.
                    A[j-i] = x;
                else if(i > j) // elements are in lower triagnular part.
                    A[rows + (i - j - 1)] = x;
        }
    
    int get(int i,int j){
        if(i  <= j) // elements are in upper triangular part.
            return A[j-i];
        else if(i > j) // elements are in lower triagnular part.
            return A[rows + (i - j - 1)];
        else
            return -1;
        
    }
    
    void display(){
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if(i  <= j) // elements are in upper triangular part.
                    cout << A[j-i] << " ";
                else if(i > j) // elements are in lower triagnular part.
                    cout << A[rows + (i - j - 1)] << " ";
                else
                    cout << get(i - 1, j - 1) << " ";
            }
            cout << endl;
        }
    }

    
};

int main(int argc, char const *argv[])
{
    /*
    DiagonalMatrix d(3,3);
    d.set(1,1,12);
    d.set(2,2,13);
    d.set(3,3,14);
    //d.display();
    
    // test LowerTriangular matrix
    int d1 , d2;
    cout << "Enter the dimension for lower triangular matrix : "<<endl;
    cin >> d1;
    LowerTriangularMatrix l(d1,d1,false);
    int x;
    cout << "Enter the elements for lower triangular matrix : "<<endl;
    for (int i = 1; i <= d1; i++) {
        for (int j =1; j <= d1; j++) {
            cin >> x;
            l.set(i, j,x);
        }
    }
    
    l.display();

    // test UpperTriangular matrix.
    cout << "Enter the dimension for upper triangular matrix : "<<endl;
    cin >> d2;
    UpperTriangularMatrix u(d2,d2,false);
    int y;
    cout << "Enter the elements for upper triangular matrix : "<<endl;
    for (int i =1; i<= d2; i++) {
        for (int j =1; j<= d2; j++) {
            cin >> y;
            u.set(i, j, y);
        }
    }
    u.display();
    
    */
    
//    int d1;
//    cout << "Enter the dimension for Symmetric triangular matrix : "<<endl;
//    cin >> d1;
//    SymmetricMatrix s(d1,d1);
//    int x;
//    cout << "Enter the elements for Symmetric  matrix : "<<endl;
//    for (int i = 1; i <= d1; i++) {
//        for (int j =1; j <= d1; j++) {
//            cin >> x;
//            s.set(i, j,x);
//        }
//    }
//
//    s.display();

//    int d1;
//    cout << "Enter the dimension for tri-diagonal matrix : "<<endl;
//    cin >> d1;
//    TriDiagonalMatrix td(d1,d1);
//    int x;
//    cout << "Enter the elements for tri-diagonal  matrix : "<<endl;
//    for (int i = 1; i <= d1; i++) {
//        for (int j = 1; j <= d1; j++) {
//            cin >> x;
//            td.set(i, j,x);
//        }
//    }
//    cout << " ========================="<<endl;
//    td.display();

    int d1;
    cout << "Enter the dimension for toeplitz matrix : "<<endl;
    cin >> d1;
    TriDiagonalMatrix t(d1,d1);
    int x;
    cout << "Enter the elements for toeplitz  matrix : "<<endl;
    for (int i = 1; i <= d1; i++) {
        for (int j = 1; j <= d1; j++) {
            cin >> x;
            t.set(i, j,x);
        }
    }
    cout << " ========================="<<endl;
    t.display();

    return 0;
}
