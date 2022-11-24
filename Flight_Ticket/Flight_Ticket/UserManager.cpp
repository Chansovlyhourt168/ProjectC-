#pragma once

#include <iostream>
#include "User.cpp"

class UserManager {
private:
	User users[10];
	int count = 0;
public:
	UserManager() {
		User user1("user", "123", "ADMIN");
		User user2("normal", "123", "NORMAL");
		users[count++] = user1;
		users[count++] = user2;
	}
	void addUser(User user) {
		users[count] = user;
		count++;
	}
	void viewUser() {
		cout << "Username\tPassword\tType\n";
		for (int i = 0; i < count; i++) {
			users[i].outputUser();
		}
	}
	int findUserByName(string name) {
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return i;
			}
		}
		return -1;
	}
	User* getUserByName(string name) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == name) {
				return &users[i];
			}
		}
		return user;
	}
	void editUser(string name) {
		string role;
		int found = findUserByName(name);
		if (found != -1) {
			cout << "Enter new role: ";
			cin >> role;
			users[found].setType(role);
			cout << "User has been edited" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	void deleteUser(string name) {
		int found = findUserByName(name);
		if (found != -1) {
			for (int i = found; i < count; i++) {
				users[i] = users[i + 1];
			}
			count--;
			cout << "User has been deleted" << endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	User* authenticateUser(string username, string password) {
		User* user = nullptr;
		for (int i = 0; i < count; i++) {
			if (users[i].getUsername() == username && users[i].getPassword() == password) {
				return &users[i];
			}
		}
		return user;
	}
};