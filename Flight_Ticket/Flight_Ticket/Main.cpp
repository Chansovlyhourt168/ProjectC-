#include <iostream>
#include "RunApp.cpp"
#include "User.cpp"
#include "UserManager.cpp"

using namespace std;

int main()
{
	RunApp run;
	UserManager userManager;
	string username;
	string password;
	int op=0;
	enum op{EXIT,ADMIN,USER};
	run.app();
	/*do {
		cout << "======================" << endl;
		cout << "	Login" << endl;
		cout << "Enter username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

		User* user = userManager.authenticateUser(username, password);
		if (user != nullptr) {
			if (user->getType() == "ADMIN") {
				run.user();
			}
			else if (user->getType() == "NORMAL") {
				run.app();
			}
		}
		else {
			cout << "Invalid user" << endl;
		}
	} while (true);*/
	return 0;
}