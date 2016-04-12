/*
Author: Landon Baxter
Date: 1/19/2016
CSCI2270
Recitation 2
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//ifstream -> input file stream
//ofstream -> output file stream
//sstream -> string stream. Allows string to be parsed. Reads a string character by character
//.good() will return true if there are no errors, false if errors are encountered
struct car{
    string model;
    string make;
    string year;
};

int main()
{
    ifstream inFile; //instance inFile created
    string data;
    car carData[10];
    inFile.open("structtext.txt");
    int index = 0;
    if(inFile.good()) {
        while(getline(inFile, data)){
            stringstream ss(data);          //Convert the string "data" -- the current line -- to a stringstream called ss
            ss >> carData[index].make;      //Space is delimiter for string stream. In this case, the string is read up until a space is met. This string is stored as the "make" of the car. Next time "ss >>" is used, the next word in the line will be stored.
            ss >> carData[index].model;     //Whenever "ss >>" is used, it'll store the next set of characters into the pointed variable. here, ss >> is used a second time, so the "model" of the car is stored.
            ss >> carData[index].year;
            index++;
        }
        inFile.close();
    }
    else
        cout << "file failed to open" << endl;


    for(int i = 0; i < 10; i++){
        cout << "make: " << carData[i].make << " model: " << carData[i].model << " year: " << carData[i].year << endl;
    }

    return 0;
}
