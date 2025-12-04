#ifndef HUB_H
#define HUB_H

#include <string>
#include <vector>
#include "SensorData.h"
#include "DataImporter.h"
#include "DataExporter.h"
#include "DataConversion.h"

class Hub {
    private:
        DataImporter* importer;
        DataExporter* exporter;
        DataConversion* converter;
        vector<SensorData*> v_sensors;
        vector<int> tsID;
        bool doesFileExist = false;
    public:
        Hub();
        ~Hub();
        void convertTemperatures();
        void convertTimeStamps();
        void startReading(string CsvFile);
        void startExporting();
};

#endif