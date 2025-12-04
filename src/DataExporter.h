#ifndef DATAEXPORTER_H
#define DATAEXPORTER_H

#include <string>
#include <vector>
#include "SensorData.h"
#include "SensorMetrics.h"

class DataExporter {
    private:
        vector<SensorData*> v_sensors;
        vector<int> tsID;
    public:
        DataExporter(vector<SensorData*> &v_sensors, vector<int> tsID);
        const vector<string>& getSpecificMetric(SensorMetrics metric, int sensorIndex) const;
        void exportMetric(SensorMetrics metric, string fileName);
        void exportAllMetrics();
};

#endif