#include <string>

/********************
Program    - Account Login & Registration
Maintainer - C.Holmes
File       - Program Functions
Version    - 0
    - Release Notes:
        - Version 0   - Three main functions created
        - Version 0.1 - Updates for new user registration
********************/


// Function for admin login
void adminUser::adminLogin() {
    std::string inputUser; // variable to take in the username entered by the user
    std::string inputPwd; // variable to take in the password entered by the user

    adminUser::adminUsername= "admin";
    adminUser::adminPassword = "admin";
    
    std::cout << "Admin Login Request Submitted..." << std::endl;
    std::cout << "Enter Admin username:" << std::endl;
    std::cin >> inputUser;
    if (inputUser == adminUser::adminUsername) {
        std::cout << "Enter Admin Password" << std::endl;
        std::cin >> inputPwd;
        if (inputPwd == adminUser::adminPassword) {
            std::cout << "Login Successful" << std::endl;
            std::cout << "\n" << std::endl;
        } else {
            std::cout << "Incorrect Password" << std::endl;
        }
    } else {
        std::cout << "Incorrect Login" << std::endl;
    }
}

// Function for user Login
void adminUser::userLogin(std::vector<User> users) {

    // Create test users
    User object_one;
    object_one.setUser("usr");
    object_one.setPassword("test");
    users.push_back(object_one);

    std::string inputUser; // variable to take in the username entered by the user
    std::string inputPwd; // variable to take in the password entered by the user
    int count = 0;

    // enter username
    std::cout << "User Login Request Submitted..." << std::endl;
    std::cout << "Enter username:" << std::endl;
    std::cin >> inputUser;
    
    //std::cout << users.size() << std::endl; // --debug-- check size of vector

    for ( auto i : users )
    {
        //std::cout << inputUser << std::endl; // --debug-- check users
        if (inputUser == i.username) {
            std::cout << "user found" << std::endl;
            std::cout << "Enter password:" << std::endl;
            std::cin >> inputPwd;
            if (inputPwd == i.password) {
                std::cout << "Login Successful" << std::endl;
                std::cout << "\n" << std::endl;
            } else {
                std::cout << "Incorrect Password" << std::endl;
            }
        } else if (inputUser != i.username && count == users.size()-1) {
            std::cout << "user NOT found!" << std::endl;
            continue;
        }
        count = count + 1;
    }
}

// Function for new user registration
User adminUser::userRegistration(std::vector<User> users, User &object) {

    // Create test users
    // User object_one;
    // object_one.setUser("usr");
    // object_one.setPassword("test");
    // users.push_back(object_one);

    std::string inputUser; // variable to take in the username entered by the user
    std::string inputPwd; // variable to take in the password entered by the user

    std::cout << "New User Registration Request Submitted" << std::endl;

    //User newUser;

    std::cout << "Enter new username:" << std::endl;
    std::cin >> inputUser;
    bool flag = false;
    
    for ( auto i : users )
    {   
        if (inputUser == i.username){
            std::cout << "User already exists" << std::endl;
            flag = true;
            //break;
        } 
    }
    if (flag != true) {
        
        // Create new username
        object.setUser(inputUser);
        std::cout << "username accepted" <<std::endl;

        std::cout << "Enter new Password:" << std::endl;
        std::cin >> inputPwd;
        // Create new password
        object.setPassword(inputPwd);
        users.push_back(object);
        std::cout << "password accepted" << "\n" <<std::endl;
    }
    return object;
}