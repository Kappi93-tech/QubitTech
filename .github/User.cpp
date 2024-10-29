#include <iostream>
#include "User.h"

User::User(int id, const std::string& name, int age, const std::string& email)
    : id(id), name(name), age(age), email(email) {}

std::string User::getTableName() const {
    return "users";
}

std::map<std::string, std::string> User::getFields() const {
    return {
        {"id", std::to_string(id)},
        {"name", name},
        {"age", std::to_string(age)},
        {"email", email}
    };
}
