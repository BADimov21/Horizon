#include "dataAccess.h"

void DataAccess::addAccount(const std::string& username, const std::string& password) const {
    std::ofstream file("../data/accounts.csv", std::ios_base::app);
    file << username << ',' << password << "\n";
}

void DataAccess::addDigitalWill(const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& username, const std::string& will) const {
    std::ofstream file("../data/digitalWills.csv", std::ios_base::app);
    file << username << ',' << password << ',' << names << ',' << id << ',' << address << ',' << will << "\n";
}