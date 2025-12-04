#ifndef DATACONVERSION_H
#define DATACONVERSION_H
#include <string>
#include <vector>

using namespace std;

class DataConversion {
    public:
        DataConversion();
        string removeQuotations(string& inQuote) const;
        void addQuotations(string& noQuote);
        vector<string> toCelsius(vector<string>& tempF);
        vector<string> epochToDateTime(vector<string>& ts);
};

#endif