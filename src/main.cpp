// Code purely for testing ideas
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "SensorData.h"
#include "DataImporter.h"

using namespace std;

int main() 
{
    DataImporter test1("iot_telemetry_data.csv");
    test1.readCsv();
    // test1.test_output(1);

    // inheritance example from class
    // anything in bracket is any parameter not from parent
    // student::student(string name, float GPA, vector<string> courses) : person (name) { this->GPA=GPA; this->courses=courses; }

    // when comparing values from two objects
    // value > other.getValue();
    return 0;
}