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
    this->p_printArray();
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Reads a file into memory via numArr variable
**    Function Output: None
**    Side Effects: Sets the numArr to file contents
*/
void C_Numbers::readFile(char fileName[100]){
    this->p_readFile(fileName);
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Helper function for the public printArray function
**    Function Output: prints numbers to screen
**    Side Effects: None
*/
void C_Numbers::p_printArray(void){
    for (int numArrayIndex = 0; numArrayIndex < this->p_arraySize; numArrayIndex++) {
        cout << this->p_numArray[numArrayIndex] << endl;
    }
}

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Helper function for the public version
**    Function Output: None
**    Side Effects: None
*/
void C_Numbers::p_readFile(char fileName[100]){
    ifstream fileStream(fileName);

    if (fileStream.is_open()) {
        fileStream >> this->p_arraySize;

        //Create numArray
        p_numArray = new int[this->p_arraySize];

        //Loop through array size and fill array
        for (size_t numArrayIndex = 0; numArrayIndex < this->p_arraySize; numArrayIndex++) {
            fileStream >> p_numArray[numArrayIndex];
        }

        fileStream.close();
    }
    else {
        //TODO: Throw exception I think
    }
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
    
    char *filename = "input.dat";
    cNumbers.readFile(filename);
    cNumbers.printArray();
    
    return 0;
}