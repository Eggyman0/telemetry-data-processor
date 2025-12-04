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
const vector<string>& SensorData::getTs() {
    return ts;
}

const vector<string>& SensorData::getDateTime() {
    return dateTime;
}

const string& SensorData::getDeviceID() {
    return deviceID;
}

const vector<string>& SensorData::getCo() {
    return co;
}

const vector<string>& SensorData::getHumidity() {
    return humidity;
}

const vector<string>& SensorData::getLight() {
    return light;
}

const vector<string>& SensorData::getLpg() {
    return lpg;
}

const vector<string>& SensorData::getMotion() {
    return motion;
}

const vector<string>& SensorData::getSmoke() {
    return smoke;
}

const vector<string>& SensorData::getTempF() {
    return tempF;
}

const vector<string>& SensorData::getTempC() {
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