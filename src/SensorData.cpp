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

vector<string> SensorData::getCo() {
    return co;
}

vector<string> SensorData::getHumidity() {
    return humidity;
}

vector<string> SensorData::getLight() {
    return light;
}

vector<string> SensorData::getLpg() {
    return lpg;
}

vector<string> SensorData::getMotion() {
    return motion;
}

vector<string> SensorData::getSmoke() {
    return smoke;
}

vector<string> SensorData::getTempF() {
    return tempF;
}

vector<string> SensorData::getTempC() {
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

void SensorData::setCo(string co) {
    this->co.push_back(co);
}

void SensorData::setHumidity(string humidity) {
    this->humidity.push_back(humidity);
}

void SensorData::setLight(string light) {
    this->light.push_back(light);
}

void SensorData::setLpg(string lpg) {
    this->lpg.push_back(lpg);
}
void SensorData::setMotion(string motion) {
    this->motion.push_back(motion);
}

void SensorData::setSmoke(string smoke) {
    this->smoke.push_back(smoke);
}

void SensorData::setTempF(string tempF) {
    this->tempF.push_back(tempF);
}

void SensorData::setTempC(string tempC) {
    this->tempC.push_back(tempC);
}