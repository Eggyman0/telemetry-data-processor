// Code purely for testing ideas
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Hub.h"

using namespace std;

int main() 
{
    string fileName = "iot_telemetry_data.csv";
    // test code
    // DataImporter test1("iot_telemetry_data.csv");
    // test1.readCsv();
    // for (int n = 0; n < 3; n++) {
    //     test1.test_output(n);
    // }
    Hub test;
    test.startReading(fileName);
    test.startExporting();

    return 0;
}