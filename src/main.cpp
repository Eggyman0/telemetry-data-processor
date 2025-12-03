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
    // test code
    DataImporter test1("iot_telemetry_data.csv");
    test1.readCsv();
    for (int n = 0; n < 3; n++) {
        test1.test_output(n);
    }

    return 0;
}