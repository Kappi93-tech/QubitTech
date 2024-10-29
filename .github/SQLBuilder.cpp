#include "SQLBuilder.h"

SQLBuilder& SQLBuilder::select(const std::vector<std::string>& columns) {
    query += "SELECT ";
    for (const auto& col : columns) {
        query += col + ", ";
    }
    query = query.substr(0, query.size() - 2); // Remove last comma
    return *this;
}

SQLBuilder& SQLBuilder::from(const std::string& table) {
    query += " FROM " + table;
    return *this;
}

SQLBuilder& SQLBuilder::where(const std::string& condition) {
    query += " WHERE " + condition;
    return *this;
}

SQLBuilder& SQLBuilder::insertInto(const std::string& table, const std::vector<std::string>& columns) {
    query += "INSERT INTO " + table + " (";
    for (const auto& col : columns) {
        query += col + ", ";
    }
    query = query.substr(0, query.size() - 2) + ")";
    return *this;
}

SQLBuilder& SQLBuilder::values(const std::vector<std::string>& vals) {
    query += " VALUES (";
    for (const auto& val : vals) {
        query += "'" + val + "', ";
    }
    query = query.substr(0, query.size() - 2) + ")";
    return *this;
}

SQLBuilder& SQLBuilder::update(const std::string& table) {
    query += "UPDATE " + table;
    return *this;
}

SQLBuilder& SQLBuilder::set(const std::string& assignments) {
    query += " SET " + assignments;
    return *this;
}

SQLBuilder& SQLBuilder::deleteFrom(const std::string& table) {
    query += "DELETE FROM " + table;
    return *this;
}

std::string SQLBuilder::getQuery() const {
    return query + ";";
}

