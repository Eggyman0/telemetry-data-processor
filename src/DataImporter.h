#ifndef DATAIMPORTER_H
#define DAATAIMPORTER_H

#include <string>
#include <vector>
#include "SensorData.h"

class DataImporter {
    private:
        string CsvFile;
        vector<string> existingSensors; // keeps track of the unique ID of each sensor
        vector<SensorData*> v_sensors;
        vector<int> tsID; // identifier for which sensor sent data at a certain timestamp
    public:
        DataImporter(string CsvFile);

        vector<SensorData*> getSensorPtr();
        // vector<string> getAllTimeStamps();
        vector<int> getTSID();
        bool isSensorUnique(string sensorID);
        void readCsv();
        
        void test_output(int index);
};

#endif