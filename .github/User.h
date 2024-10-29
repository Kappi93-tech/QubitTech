#ifndef USER_H
#define USER_H

#include "Entity.h"

class User : public Entity {
private:
    int id;
    std::string name;
    int age;
    std::string email;

public:
    User(int id, const std::string& name, int age, const std::string& email);
    std::string getTableName() const override;
    std::map<std::string, std::string> getFields() const override;
};

#endif // USER_H

