#include <iostream>
#include "user_account.hpp"
#include "user_account.cpp"

/********************
Program    - Account Login & Registration
Maintainer - C.Holmes
File       - Main Program
Version    - 0
    - Release Notes:
        - Version 0   - Program Structure with option 1 Admin login feature created
        - Version 0.1 - Function for option 2 with user login feature created. usernames and password compared with test vector
        - Version 0.2 - Function for option 3 with user registration feature created. new usernames compared with existing (test names)
********************/

User testCaseUsers(User &object, std::string un, std::string pwd) {
    object.setUser(un);
    object.setPassword(pwd);
    return object;
}

int main (){

    // Create objects for admin and users
    adminUser adminEntrant;

    // Create test case users 
    // Create test object placeholder to storing test users to be passed into users vector
    User test_object;
    // Create object placeholder for storing users into users vector
    User object;
    // create vector of users
    const unsigned int N = 1;
    std::vector<User> users(N);

    // Create admin users in the users vector
    User object_zero;
    object_zero.setUser("admin");
    object_zero.setPassword("admin");
    users[0] = object_zero;

    // Append the users vector with some test users
    testCaseUsers(test_object, "harry", "let");
    users.push_back(test_object);
    testCaseUsers(test_object, "nona", "me");
    users.push_back(test_object);
    testCaseUsers(test_object, "millie", "in");
    users.push_back(test_object);
    testCaseUsers(test_object, "paula", "in");
    users.push_back(test_object);

    for ( auto i : users ) {
        std::cout << "User: " << i.username << std::endl;
    }
    
    // print the user interface and create user input options
        // option 1 - login as admin
        // option 2 - login as user
        // option 3 - Register as new user

    std::cout << "\n" << std::endl;
    std::cout << "_________________________" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Welcome to the login Page" << std::endl;
    std::cout << "_________________________" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "Options" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "| Enter 1 -> Login as Admin " << std::endl;
    std::cout << "| Enter 2 -> Login as User " << std::endl;
    std::cout << "| Enter 3 -> Register as New User " << std::endl;
    std::cout << "\n" << std::endl;
    
    // Variable declarations
    // variables for user inputs
    int option; 
    std::cin >> option;

    // switch case to handle the user input
    switch (option) {
        case 1:
            adminEntrant.adminLogin();
            break;
        case 2:
            adminEntrant.userLogin(users);
            break;
        case 3:
            adminEntrant.userRegistration(users, object);
            if (object.username.empty()) {
                break;
            } else {
                users.push_back(object);
            }
            break;
    }
    for ( auto i : users ) {
        std::cout << "User: " << i.username << std::endl;
    }
}