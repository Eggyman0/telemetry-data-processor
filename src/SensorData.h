// SENSORDATA_H
#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <string>
#include <vector>

using namespace std;

class SensorData {
    private:
        vector<string> ts;
        vector<string> dateTime;
        string deviceID;
        vector<string> co;
        vector<string> humidity;
        vector<string> light;
        vector<string> lpg;
        vector<string> motion;
        vector<string> smoke;
        vector<string> tempF;
        vector<string> tempC;
    public:
        // Constructor
        SensorData();

        // Accessors
        const vector<string>& getTs();
        const vector<string>& getDateTime();
        const string& getDeviceID();
        const vector<string>& getCo();
        const vector<string>& getHumidity();
        const vector<string>& getLight();
        const vector<string>& getLpg();
        const vector<string>& getMotion();
        const vector<string>& getSmoke();
        const vector<string>& getTempF();
        const vector<string>& getTempC();

        // Mutators
        void setTs(string ts);
        void setDateTime(string dateTime);
        void setDeviceID(string ID);
        void setCo(string co);
        void setHumidity(string humidity);
        void setLight(string light);
        void setLpg(string lpg);
        void setMotion(string motion);
        void setSmoke(string smoke);
        void setTempF(string tempF);
        void setTempC(string tempC);
};

#endif