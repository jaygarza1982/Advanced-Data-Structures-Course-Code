#include <iostream>
#include <fstream>
#include "customErrorClass.h"

using namespace std;

class C_Numbers{
    public:
        
        C_Numbers();
        ~C_Numbers();
        void readFile(char[100]);
        void printArray();
        void sortArray();

    private:
        int *p_numArray;
        int p_arraySize;

        void p_readFile(char[100]);
        void p_printArray();
        void p_sortArray();
};

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Constructs a numbers class that sorts integers
**    Function Output: None
**    Side Effects: Sets numArray to NULL and arraySize to 0
*/
C_Numbers::C_Numbers(){
    this->p_numArray = NULL;
    this->p_arraySize = 0;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Destroys the C Numbers class
**    Function Output: None
**    Side Effects: Frees memory from numArray
*/
C_Numbers::~C_Numbers(){
    delete[] this->p_numArray;
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Prints the array to the screen
**    Function Output: void return but prints numArr
**    Side Effects: None
*/
void C_Numbers::printArray(void){

}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Reads a file into memory via numArr variable
**    Function Output: None
**    Side Effects: Sets the numArr to file contents
*/
void C_Numbers::readFile(char fileName[100]){

}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Helper function for the public printArray function
**    Function Output: prints numbers to screen
**    Side Effects: None
*/
void C_Numbers::p_printArray(void){

}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Helper function for the public version
**    Function Output: None
**    Side Effects: None
*/
void C_Numbers::p_readFile(char fileName[100]){
    
}


/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Runs the program
**    Function Output: Depends how you use this program, prints numbers and sorts them
**    Side Effects: Many
*/
int main(int argc, char *argv[]){

    C_Numbers cNumbers;
    
    cNumbers.readFile("input.dat");
    cNumbers.printArray();
    
    return 0;
}