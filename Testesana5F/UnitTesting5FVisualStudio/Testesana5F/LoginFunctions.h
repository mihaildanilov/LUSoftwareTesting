#pragma once
#include <fstream>
#include <iostream>
#include <regex> // e-pasta formāta pārbaudei
#include <string>

using namespace std;

bool isValidEmail(const string& email) {
    // Pārbada e-pasta formu
    regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailRegex);
}

bool isEmailInUsersFile(const string& email) {
    // Pārbauda e-pasta formu
    // Parasts teksta fails ar e-pastiem un parolēm tiek izmantots speciāli šim
    // kursam, lai vieglāk testēt
    ifstream usersFile("users.txt");
    string line;
    while (getline(usersFile, line)) {
        if (line.find(email) != string::npos) {
            usersFile.close();
            return true;
        }
    }
    usersFile.close();
    return false;
}

bool isPasswordCorrect(const string& email, const string& password) {
    // Paroles atbilstības pārbaude
    ifstream usersFile("users.txt");
    string line;
    while (getline(usersFile, line)) {
        if (line.find(email) != string::npos) {
            size_t pos = line.find(":");
            string storedPassword = line.substr(pos + 1);
            usersFile.close();
            return (password == storedPassword);
        }
    }
    usersFile.close();
    return false;
}