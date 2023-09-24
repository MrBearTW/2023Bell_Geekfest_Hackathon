#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include "fakedata.h"

using namespace std;

defaultSystem::defaultSystem(const string IP) {
    passwordCount=0;
    IPadd= IP;
    MFA = false;
    newDevice = false;

}

void FakeData::load(const char* filename) {

    int i = 0;
   
    ifstream file(filename);

    if (filename) {
        file.open(filename);
        while (file) {

            getline(file, name, ',');
            getline(file, phone, ',');
            getline(file, email, ',');
            getline(file, address, ',');
        }
        i++;
    }

    
}
void FakeData::display()
{
    cout << "NAME:" << name << endl << "PHONE:" << phone << endl << "E-MAIL" << email << endl << "ADDRESS:" << address << endl;
}
std::string FakeData::getName()
{
    return name;
}
std::string FakeData::getphone()
{
    return phone;
}
std::string FakeData::getEmail()
{
    return email;
}
std::string FakeData::getAddress()
{
    return address;
}
;

size_t defaultSystem::getPasswordCount() {
    return passwordCount; 
}

string defaultSystem::getIpadd()
{
    return IPadd;
}

bool defaultSystem::getDevice()
{
    return newDevice;
}

bool defaultSystem::getMFA()
{
    return MFA;
}
