#ifndef HUB_H
#define HUB_H

#include <string>
#include <vector>
#include "SensorData.h"
#include "DataImporter.h"
#include "DataExporter.h"

class Hub {
    private:
        DataImporter* importer;
        DataExporter* exporter;
        vector<SensorData*> v_sensors;
        vector<int> tsID;
        // DataConversion converter
        bool doesFileExist = false;
    public:
        Hub();
        void startReading(string CsvFile);
        // void convertTemperatures
        // void convertTimeStamps
        void startExporting();
};

#endif