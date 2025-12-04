#include "Hub.h"
#include <string>
#include <vector>
#include <iostream>

Hub::Hub()
{
}

void Hub::convertTemperatures() {
    converter =  new DataConversion();
    for (size_t i = 0; i < v_sensors.size(); i++) {
        vector<string> tempF = v_sensors[i]->getTempF();
        vector<string> tempC = converter->toCelsius(tempF);
        for (size_t j = 0; j < tempF.size(); j++) {
            v_sensors[i]->setTempC(tempC[j]);
        }
    }
    delete converter;
}

void Hub::convertTimeStamps() {
    converter = new DataConversion();
    for (size_t i = 0; i < v_sensors.size(); i++) {
        vector<string> timeStamps = v_sensors[i]->getTs();
        vector<string> dateTimes = converter->epochToDateTime(timeStamps);
        for (size_t j = 0; j < timeStamps.size(); j++) {
            v_sensors[i]->setDateTime(dateTimes[j]);
        }
    }
    delete converter;
}

void Hub::startReading(string CsvFile) {
    // Creates DataImporter object and then calls the file read method
    importer = new DataImporter(CsvFile);
    doesFileExist = true;

    importer->readCsv();
    tsID = importer->getTSID(); // create a copy of the tsID vector for the Hub

    // Assigns sensors created by DataImporter to a vector in the Hub class
    // This allows the hub to grant access to the data from SensorData objects
    v_sensors = importer->getSensorPtr();

    // conversions / processing
    convertTemperatures();
    convertTimeStamps();

    cout << "Processing completed\n";
}

void Hub::startExporting() {
    if (doesFileExist) {
        exporter = new DataExporter(v_sensors, tsID);
        exporter->exportAllMetrics();
        cout << "All files have been written\n";
    } else {
        cout << "File failed to import or has not been imported yet\n";
    }
}

Hub::~Hub() {
    delete importer;
    delete exporter;
}