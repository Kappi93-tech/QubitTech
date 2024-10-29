#ifndef SQLBUILDER_H
#define SQLBUILDER_H

#include <string>
#include <vector>

class SQLBuilder {
private:
    std::string query;

public:
    SQLBuilder& select(const std::vector<std::string>& columns);
    SQLBuilder& from(const std::string& table);
    SQLBuilder& where(const std::string& condition);
    SQLBuilder& insertInto(const std::string& table, const std::vector<std::string>& columns);
    SQLBuilder& values(const std::vector<std::string>& vals);
    SQLBuilder& update(const std::string& table);
    SQLBuilder& set(const std::string& assignments);
    SQLBuilder& deleteFrom(const std::string& table);
    std::string getQuery() const;
};

#endif // SQLBUILDER_H

