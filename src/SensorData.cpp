#include <cstdlib>
#include <string>
#include <vector>
#include "SensorData.h"

using namespace std;

// -------------------- Constructor --------------------------------
SensorData::SensorData() 
{
}

// -------------------- Accessor Functions --------------------------
vector<string> SensorData::getTs() {
    return ts;
}

vector<string> SensorData::getDateTime() {
    return dateTime;
}

string SensorData::getDeviceID() {
    return deviceID;
}

vector<double> SensorData::getCo() {
    return co;
}

vector<double> SensorData::getHumidity() {
    return humidity;
}

vector<bool> SensorData::getLight() {
    return light;
}

vector<double> SensorData::getLpg() {
    return lpg;
}

vector<bool> SensorData::getMotion() {
    return motion;
}

vector<double> SensorData::getSmoke() {
    return smoke;
}

vector<double> SensorData::getTempF() {
    return tempF;
}

vector<double> SensorData::getTempC() {
    return tempC;
}

// ------------------------ Mutators -------------------------------
void SensorData::setTs(string ts) {
    this->ts.push_back(ts);
}

void SensorData::setDateTime(string dateTime) {
    this->dateTime.push_back(dateTime);
}


void SensorData::setDeviceID(string ID) {
    deviceID = ID;
}

void SensorData::setCo(double co) {
    this->co.push_back(co);
}

void SensorData::setHumidity(double humidity) {
    this->humidity.push_back(humidity);
}

void SensorData::setLight(bool light) {
    this->light.push_back(light);
}

void SensorData::setLpg(double lpg) {
    this->lpg.push_back(lpg);
}
void SensorData::setMotion(bool motion) {
    this->motion.push_back(motion);
}

void SensorData::setSmoke(double smoke) {
    this->smoke.push_back(smoke);
}

void SensorData::setTempF(double tempF) {
    this->tempF.push_back(tempF);
}

void SensorData::setTempC(double tempC) {
    this->tempC.push_back(tempC);
}