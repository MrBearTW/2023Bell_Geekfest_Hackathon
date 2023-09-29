#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include "fakedata.h"

using namespace std;

int main()
{

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

    do
    {
        cout << "Enter password: " << endl;
        cin >> password;
        if (strcmp(password.c_str(), realPassword.c_str()) != 0)
        {
            passwordCount++;
        }
    } while (passwordCount < 3);

    if (passwordCount >= 3)
    {
        count++;

        if (strcmp(IP.c_str(), realIPadd.c_str()))
        {
            cout << "<<<<< SysLog >>>>> : NEW IP DETECTED" << endl;
            count++;
        }
        if (!a.getDevice())
        {
            cout << "<<<<< SysLog >>>>> : NEW DEVICE DETECTED" << endl;
            count++;
        }
        if (!a.getMFA())
        {
            cout << "<<<<< SysLog >>>>> : MFA NOT ENABLED" << endl;
            count++;
        }
    }

    if (count >= 3)
    {
        fake.load("pseudo.txt");

        cout << endl;
        cout << "<<<<< SysLog >>>>> : 2-FACED STRATEGY ENABLED" << endl;
        cout << "<<<<< SysLog >>>>> : DISABLE this account other database access" << endl;
        cout << "<<<<< SysLog >>>>> : Alert the system admin" << endl;
        cout << endl;
        cout << "<<<<< Fake data provide >>>>> : DISPLAYING \"FAKE DATA\" FOR DEMO PURPOSES ONLY" << endl;
        cout << "<<<<< Fake data provide >>>>> : NAME: " << fake.getName()<< endl;
        cout << "<<<<< Fake data provide >>>>> : PHONE: " << fake.getphone()<< endl;
        cout << "<<<<< Fake data provide >>>>> : EMAIL: " << fake.getEmail()<< endl;
        cout << "<<<<< Fake data provide >>>>> : ADDRESS: " << fake.getAddress()<< endl;
    }

    return 0;
}
