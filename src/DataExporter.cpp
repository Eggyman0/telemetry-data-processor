#include "DataExporter.h"
#include "SensorMetrics.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Constructor
DataExporter::DataExporter(vector<SensorData*> &v_sensors, vector<int> tsID) {
    this->v_sensors = v_sensors;
    this->tsID = tsID;
}

/**
 * @brief switch case statement to easily get a metric from a specified sensor object
 * 
 * @param metric name of specific metric you want data from
 * @param sensorIndex used to get data from a specific sensor object from v_sensors
 * @return const vector<string>&
 */
const vector<string>& DataExporter::getSpecificMetric(SensorMetrics metric, int sensorIndex) const {
    switch (metric) {
        case SensorMetrics::CO:
            return v_sensors[sensorIndex]->getCo();
        case SensorMetrics::HUMIDITY:
            return v_sensors[sensorIndex]->getHumidity();
        case SensorMetrics::LIGHT:
            return v_sensors[sensorIndex]->getLight();
        case SensorMetrics::LPG:
            return v_sensors[sensorIndex]->getLpg();
        case SensorMetrics::MOTION:
            return v_sensors[sensorIndex]->getMotion();
        case SensorMetrics::SMOKE:
            return v_sensors[sensorIndex]->getSmoke();
        case SensorMetrics::TEMP:
            return v_sensors[sensorIndex]->getTempF(); // will change to tempC later
    }
    static const std::vector<std::string> empty;
    return empty;
}

/**
 * @brief creates and writes to a new csv file that only contains the specified metric
 * 
 * @param metric the type of data that was read from the original dataset such as co, light, temp, etc.
 * @param fileName name of the file that will be created
 */
void DataExporter::exportMetric(SensorMetrics metric, string fileName) {
    fstream csvFile;
    string filePath = "exported_data/" + fileName;
    csvFile.open(filePath, ios::out);

    if (csvFile.is_open() == false) {
        cout << "File could not be created\n";
        cout << "File path error: " << filePath;
        return;
    }

    // set header row
    csvFile << "\"Timestamp\",";
    for (int n = 0; n < v_sensors.size(); n++) {
        csvFile << v_sensors[n]->getDeviceID();
        if (n == v_sensors.size() - 1) {
            csvFile << '\n';
        } else {
            csvFile << ',';
        }
    }
    
    vector<bool> wasDataSent(v_sensors.size());
    vector<int> sensorIndexTracker;
    
    // sensorIndexTracker used to check if an element of data has been written in the csv
    for (int i = 0; i < v_sensors.size(); i++) {
        sensorIndexTracker.push_back(0);
    }
    
    // Outputs the metric data corresponding to each timestamp in standard csv format with quotation marks
    for (int tsIndex = 0; tsIndex < tsID.size(); tsIndex++) {
        for (int sensorIndex = 0; sensorIndex < v_sensors.size(); sensorIndex++) {
            if (tsID[tsIndex] == sensorIndex) {
                wasDataSent[sensorIndex] = true;
                csvFile << v_sensors[sensorIndex]->getTs()[sensorIndexTracker[sensorIndex]] << ",";
            } else {
                wasDataSent[sensorIndex] = false;
            }
        }

        for (int i = 0; i < v_sensors.size(); i++) {
            if (wasDataSent[i]) {
                csvFile << getSpecificMetric(metric, i)[sensorIndexTracker[i]];
                sensorIndexTracker[i]++;
            } else {
                csvFile << "\"\"";
            }
            
            if (i == v_sensors.size() - 1) {
                csvFile << '\n';
            } else {
                csvFile << ',';
            }
        }
    }

    csvFile.close();
    cout << "A file has been finished writing\n";
}

/**
 * @brief calls writeCsv() multiple times for all metrics listed in SensorMetrics.h
 * 
 */
void DataExporter::exportAllMetrics() {
    exportMetric(SensorMetrics::CO, "co_measurement.csv");
    exportMetric(SensorMetrics::HUMIDITY, "humidity_measurement.csv");
    exportMetric(SensorMetrics::LIGHT, "light_measurement.csv");
    exportMetric(SensorMetrics::LPG, "lpg_measurement.csv");
    exportMetric(SensorMetrics::MOTION, "motion_measurement.csv");
    exportMetric(SensorMetrics::SMOKE, "smoke_measurement.csv");
    exportMetric(SensorMetrics::TEMP, "temp_measurement.csv");
}