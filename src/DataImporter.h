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
    public:
        // -------------- Constructor ---------------
        DataImporter(string CsvFile);

        // ---------------- Mutators -----------------
        // void setExistingSensors(string sensorID);
        // void setSensors(SensorData* sensor);

        // --------------- Accessors -----------------
        // vector<string> getExistingSensors();

        // ----------------- Other ------------------
        bool isSensorUnique(string sensorID);
        void readCsv();
        void test_output(int index);
};

#endif