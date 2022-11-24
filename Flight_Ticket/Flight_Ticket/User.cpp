#pragma once
#include <iostream>
using namespace std;

class User {
private:
    string username;
    string password;
    string type;
public:
    User() :username("Unknown"), password("Unknown"), type("Unknown") {}
    User(string username, string password, string type) :username(username), password(password), type(type) {}
    ~User() {

    }
    void setUsername(string username) {
        this->username = username;
    }
    string getUsername() {
        return username;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getPassword() {
        return password;
    }
    void setType(string type) {
        this->type = type;
    }
    string getType() {
        return type;
    }
    void inputUser() {
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        cout << "Enter type ( ADMIN or NORMAL ) : ";
        cin >> type;
    }
    void outputUser() {
        /*cout << "Username : " << username;
        cout << "\nType : " << type;*/
        cout << username << "\t\t" << password << "\t\t" << type << endl;
    }
};