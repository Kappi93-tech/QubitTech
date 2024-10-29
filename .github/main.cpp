#include <iostream>
#include "User.h"

int main() {
    User newUser(0, "John Doe", 30, "john.doe@example.com");

    // Generate INSERT SQL
    std::string insertQuery = newUser.insertSQL();
    std::cout << "INSERT SQL: " << insertQuery << std::endl;

    // Generate UPDATE SQL
    User existingUser(1, "John Doe", 31, "john.doe@example.com"); //May use user inputs
    std::string updateQuery = existingUser.updateSQL();
    std::cout << "UPDATE SQL: " << updateQuery << std::endl;

    // Generate DELETE SQL
    std::string deleteQuery = existingUser.deleteSQL();
    std::cout << "DELETE SQL: " << deleteQuery << std::endl;

    // Generate SELECT SQL
    std::string selectQuery = User::selectSQL("users", "1");
    std::cout << "SELECT SQL: " << selectQuery << std::endl;

    return 0;
}
