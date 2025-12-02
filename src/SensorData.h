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
        vector<double> co;
        vector<double> humidity;
        vector<bool> light;
        vector<double> lpg;
        vector<bool> motion;
        vector<double> smoke;
        vector<double> tempF;
        vector<double> tempC;
    public:
        // Constructor
        SensorData();

        // Accessors
        vector<string> getTs();
        vector<string> getDateTime();
        string getDeviceID();
        vector<double> getCo();
        vector<double> getHumidity();
        vector<bool> getLight();
        vector<double> getLpg();
        vector<bool> getMotion();
        vector<double> getSmoke();
        vector<double> getTempF();
        vector<double> getTempC();

        // Mutators
        void setTs(string ts);
        void setDateTime(string dateTime);
        void setDeviceID(string ID);
        void setCo(double co);
        void setHumidity(double humidity);
        void setLight(bool light);
        void setLpg(double lpg);
        void setMotion(bool motion);
        void setSmoke(double smoke);
        void setTempF(double tempF);
        void setTempC(double tempC);
};

#endif