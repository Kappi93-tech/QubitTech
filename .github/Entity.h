#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>

class Entity {
public:
    virtual ~Entity() {}

    virtual std::string getTableName() const = 0;
    virtual std::map<std::string, std::string> getFields() const = 0;

    std::string insertSQL() const;
    std::string updateSQL() const;
    std::string deleteSQL() const;
    static std::string selectSQL(const std::string& tableName, const std::string& id);
};

#endif // ENTITY_H

