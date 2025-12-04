#include "DataImporter.h"
#include <string>
#include <vector>
#include <fstream>

// temp
#include <iostream>

using namespace std;

// Constructor
DataImporter::DataImporter(string CsvFile) {
    this->CsvFile = CsvFile;
}

/**
 * @brief accessor to vector of DataSensor pointers
 * 
 * @return vector<SensorData*> 
 */
vector<SensorData*> DataImporter::getSensorPtr() {
    return v_sensors;
}

/**
 * @brief accessor to vector of timestamp identifiers
 * 
 * @return vector<int> 
 */
vector<int> DataImporter::getTSID() {
    return tsID;
}

/**
 * @brief checks if a sensor is unique using the sensor's ID
 * 
 * @param sensorID the sensor ID that you are checking
 * @return true if the sensor has not been seen before
 * @return false if the sensor has been read from at least once before
 */
bool DataImporter::isSensorUnique(string sensorID) {
    for (int i = 0; i < existingSensors.size(); i++) {
        if (existingSensors[i] == sensorID) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Reads from the csv file that was given to the DataImporter object when it was constructed.
 * This function will create new SensorData objects when it reads a unique device ID.
 * Then, it will store whatever it reads within that line to the SensorData object that the ID corresponds to. (hopefully)
 */
void DataImporter::readCsv() {
    ifstream iFile; // create ifstream object iFile (input file)

    // temporary variables to store values of the current line when parsing through the csv file
    string tempLine = "";
    string tempTs = "";
    string tempDevice = "";
    string tempStr = "";
    int commaLocation = 0; // number corresponds to location of comma when reading file

    int sensorIndex = 0; // to keep track of which sensor's data you are reading at the moment

    iFile.open(CsvFile);
    getline(iFile, tempLine); // initially call getline to read through the first line since we don't need it

    while (getline(iFile, tempLine)) { // loop until there is no more lines to read
        commaLocation = tempLine.find(',');
        tempTs = tempLine.substr(0, commaLocation);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length()); // after saving the previous data, sets tempLine to the rest of the line after the comma
        
        commaLocation = tempLine.find(',');
        tempDevice = tempLine.substr(0, commaLocation);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());
        
        // checking if the device id is unique
        if (isSensorUnique(tempDevice)) {
            existingSensors.push_back(tempDevice); // add sensor to existing v_sensors vector
            v_sensors.push_back(new SensorData()); // create new SensorData object
        }

        // sets the index for the sensor you are reading data from
        // this lets the program know which SensorData object to use from the v_sensors vector
        for (int i = 0; i < existingSensors.size(); i++) {
            if (existingSensors[i] == tempDevice) { 
                sensorIndex = i;
            }
        }
        SensorData *sensor = v_sensors[sensorIndex];
        sensor->setDeviceID(tempDevice); // code may be a bit redundant but there has been no need to change so far
        sensor->setTs(tempTs);
        tsID.push_back(sensorIndex);

        commaLocation = tempLine.find(',');
        tempStr = tempLine.substr(0, commaLocation);
        sensor->setCo(tempStr);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());
        
        commaLocation = tempLine.find(',');
        tempStr = tempLine.substr(0, commaLocation);
        sensor->setHumidity(tempStr);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempStr = tempLine.substr(0, commaLocation);
        sensor->setLight(tempStr);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempStr = tempLine.substr(0, commaLocation);
        sensor->setLpg(tempStr);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempStr = tempLine.substr(0, commaLocation);
        sensor->setMotion(tempStr);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempStr = tempLine.substr(0, commaLocation);
        sensor->setSmoke(tempStr);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        sensor->setTempF(tempStr);
    }
    
    iFile.close();
    cout << "Finished file reading\n";
}

// only used for testing, not used in actual project
void DataImporter::test_output(int index) {
    int sensorIndex = index;
    SensorData *sensor = v_sensors[sensorIndex];
    cout << "Device ID: " << sensor->getDeviceID() << "\n";
    cout << "Number of Elements: " << sensor->getTs().size() << "\n";
}