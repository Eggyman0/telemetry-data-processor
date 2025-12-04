#include "Hub.h"
#include <string>
#include <vector>
#include <iostream>

Hub::Hub()
{
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
}

void Hub::startExporting() {
    if (doesFileExist) {
        exporter = new DataExporter(v_sensors, tsID);
        exporter->exportAllMetrics();
        cout << "Finished writing all files\n";
    } else {
        cout << "File failed to import or has not been imported yet\n";
    }
}