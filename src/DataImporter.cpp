#include "DataImporter.h"
#include <string>
#include <vector>
#include <fstream>

// temp
#include <iostream>

using namespace std;

// ----------------------- Constructor -----------------------
DataImporter::DataImporter(string CsvFile) {
    this->CsvFile = CsvFile;
}

// ------------------------- Mutators ------------------------
// void DataImporter::setExistingSensors(string sensorID) {
//     existingSensors.push_back(sensorID);
// }

// void DataImporter::setSensors(SensorData* sensor) {
//     v_sensors.push_back(sensor);
// }

// ------------------------ Accessors ---------------------------
// vector<string> DataImporter::getExistingSensors() {
//     return existingSensors;
// }

// -------------------------- Other ----------------------------
/**
 * @brief checks if a sensor is unique using the sensor's ID
 * 
 * @param sensorID the sensor ID that you are checking
 * @return true if the sensor has not been seen before
 * @return false if the sensor has been read from at least once before
 */
bool DataImporter::isSensorUnique(string sensorID) {
    for (int i = 0; i < existingSensors.size(); i++) {
        if (existingSensors[i] != sensorID) {
            return true;
        }
    }
    return false;
}

bool DataImporter::string_to_bool(string s) {
    return s == "true";
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
    double tempCo = 0;
    double tempHumidity = 0;
    bool tempLight = 0;
    double tempLpg = 0;
    bool tempMotion = 0;
    double tempSmoke = 0;
    double tempTempF = 0; // temporary temperature lol
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
        sensor->setDeviceID(tempDevice); // may change later so we don't have to call this everytime
        sensor->setTs(tempTs);

        commaLocation = tempLine.find(',');
        tempCo = stod(tempLine.substr(0, commaLocation));
        sensor->setCo(tempCo);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());
        
        commaLocation = tempLine.find(',');
        tempHumidity = stod(tempLine.substr(0, commaLocation));
        sensor->setHumidity(tempHumidity);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempLight = string_to_bool(tempLine.substr(0, commaLocation));
        sensor->setLight(tempLight);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempLpg = stod(tempLine.substr(0, commaLocation));
        sensor->setLpg(tempLpg);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempMotion = string_to_bool(tempLine.substr(0, commaLocation));
        sensor->setMotion(tempMotion);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempSmoke = stod(tempLine.substr(0, commaLocation));
        sensor->setSmoke(tempSmoke);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());

        commaLocation = tempLine.find(',');
        tempTempF = stod(tempLine.substr(0, commaLocation));
        sensor->setTempF(tempTempF);
        tempLine = tempLine.substr(commaLocation+1, tempLine.length());
    }
    
    iFile.close();
}

void DataImporter::test_output(int index) {
    int sensorIndex = index;
    SensorData *sensor = v_sensors[sensorIndex];
    cout << sensor->getDeviceID();
    for (int i = 0; i < sensor->getTs().size(); i++) {
        cout << sensor->getTs()[i];
    }
}