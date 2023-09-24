#pragma once

#include <string>


class defaultSystem {
    size_t passwordCount{};
    std::string IPadd="";
    bool MFA=false;
    bool newDevice=false;

public:

    defaultSystem(const std::string IPadd);
    size_t getPasswordCount();
    std::string getIpadd();
    bool getDevice();
    bool getMFA();
    
};

class FakeData {

    std::string name{};
    std::string phone{};
    std::string email{};
    std::string address{};

public:
    FakeData() = default;
    void load(const char* filename);
    void display();

    std::string getName();
    std::string getphone();
    std::string getEmail();
    std::string getAddress();

};
