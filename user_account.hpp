#include <iostream>
#include <string>

/********************
Program    - Account Login & Registration
Maintainer - C.Holmes
File       - Program Header
Version    - 0
    - Release Notes:
        - Version 0   - class structure for admin data created 
        - Version 0.1 - class structure for user data created
********************/

// Class for holding user data
class User {
    public:
    std::string username;
    std::string password;

    // Creators
    void setUser(std::string i) {
        username = i;
    };

    void setPassword(std::string i) {
        password = i;
    };

    // Accessors
    std::string getUser() const {
        std::cout << username <<std::endl;
        return username;
    };
};

// Class for holding admin user data and program functions 
class adminUser {
    private:
    std::string adminUsername;
    std::string adminPassword;

    public:
    void adminLogin();
    void userLogin(std::vector<User> users);
    User userRegistration(std::vector<User> users, User &object);
    void testCaseUsers(std::vector<User> users, std::string un, std::string pwd);
};