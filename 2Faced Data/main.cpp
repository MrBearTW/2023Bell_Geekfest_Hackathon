#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "fakedata.h"

using namespace std; 

int main() {

    size_t count = 0;
    

    defaultSystem a("987.654.32.10");
    FakeData fake;

    bool flag = false;
    string password{};
    string realPassword = "abc123";

    string realIPadd = "123.456.78.90";
    string IP = a.getIpadd();

    size_t passwordCount = 0;
    passwordCount = a.getPasswordCount();

    do {

        cout << "Enter password: " << endl;
        cin >> password;
        if (strcmp(password.c_str(), realPassword.c_str()) != 0) {

            passwordCount++;

        }
    } while (passwordCount < 3);
    
    if (passwordCount >= 3) {
        
        count++;

        if (strcmp(IP.c_str(), realIPadd.c_str())) {
            count++;
        }
        if (!a.getDevice()) {
            count++;
        }
        if (!a.getMFA()) {
            count++;
        }
    }

    if (count >= 3) {
        fake.load("pesudo.txt");

        cout << endl << "2-FACED STRATEGY ENABLED" << endl;

        cout << "DISPLAYING \"FAKE DATA\" FOR DEMO PURPOSES ONLY" << endl; 
        cout << "NAME: " << fake.getName();
        cout << "PHONE: " << fake.getphone();
        cout << "EMAIL: " << fake.getEmail();
        cout << "ADDRESS: " << fake.getAddress();

       
        
    }

    return 0;
}
