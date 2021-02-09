#include <iostream>
#include <fstream>
#include "customErrorClass.h"

using namespace std;

/*
**    Author: Jacob Garza
**    Function Purpose: 
**        Runs the program
**    Function Output: Depends how you use this program, prints numbers and sorts them
**    Side Effects: Many
*/
int main(int argc, char *argv[])
{
    string line;
    ifstream inputFile;
    inputFile.open("input-small.dat");

    if (!inputFile.is_open())
    {
        //TODO: Throw exception
        exit(-1);
    }

    while (getline(inputFile, line))
    {
        cout << line << endl;
    }

    return 0;
}