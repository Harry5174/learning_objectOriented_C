#if !defined (USERMANAGER_H)
#define USERMANAGER_H

#include "user.h"

#include <vector>
#include <stdexcept>

class UserManager {
    private:
        std::vector<User> users;
    public:
        UserManager();

        //getting users
        std::vector<User>& getUsers();
        
        //methods
        void loadUsers();
        void saveUsers();
        void createUserFile();
        
        bool authenticateUser(const std::string& username, const std::string& password) const;
        bool userExists(const std::string& username) const;
        bool userExistsInFile(const std::string& username) const ;

        void changePassword(const std::string& userName, const std::string& password);

        void addUser(const User& user);
        void displayUsers();
};

#endif