// Code purely for testing ideas
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Hub.h"

//test
#include "DataConversion.h"

using namespace std;

int main() 
{
    string fileName = "iot_telemetry_data.csv";
    
    Hub test;
    test.startReading(fileName);
    test.startExporting();
    
    return 0;
}