#include "DataConversion.h"
#include <string>
#include <vector>
#include <ctime>
using namespace std;


DataConversion::DataConversion() {
}

string DataConversion::removeQuotations(string& inQuote) const {
    return inQuote.substr(1, inQuote.length() - 1);
}

void DataConversion::addQuotations(string& noQuote) {
    noQuote = '\"' + noQuote + '\"';
}

vector<string> DataConversion::toCelsius(vector<string>& tempF) {
    vector<string> tempC;
    tempC.reserve(tempF.size());
    for (size_t i = 0; i < tempF.size(); i++) {
        string noQuote = removeQuotations(tempF[i]);
        double tempF_double = stod(noQuote);
        // calculate temperature in celsius using double type
        double tempC_double = ((tempF_double - 32) * (5.0 / 9.0));
        // convert back to string and push back to temp C vector
        noQuote = to_string(tempC_double);
        addQuotations(noQuote);
        tempC.push_back(noQuote);
    }
    return tempC;
}

vector<string> DataConversion::epochToDateTime(vector<string>& ts) {
    vector<string> dateTime;
    dateTime.reserve(ts.size());
    for (size_t i = 0; i < ts.size(); i++) {      
        string noQuote = removeQuotations(ts[i]);
        double seconds = stod(noQuote);

        time_t sec = static_cast<time_t>(seconds); // convert double to time_t
        struct tm* timeinfo = gmtime(&sec);
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

        noQuote = string(buffer);
        addQuotations(noQuote);
        dateTime.push_back(noQuote);
    }
    
    return dateTime;
}