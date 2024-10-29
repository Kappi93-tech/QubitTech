#include "Entity.h"
#include "SQLBuilder.h"

std::string Entity::insertSQL() const {
    SQLBuilder builder;
    std::map<std::string, std::string> fields = getFields();
    std::vector<std::string> columns;
    std::vector<std::string> values;

    for (const auto& [column, value] : fields) {
        columns.push_back(column);
        values.push_back(value);
    }

    return builder.insertInto(getTableName(), columns)
                  .values(values)
                  .getQuery();
}

std::string Entity::updateSQL() const {
    SQLBuilder builder;
    std::map<std::string, std::string> fields = getFields();
    std::string setClause;
    std::string id;

    for (const auto& [column, value] : fields) {
        if (column == "id") {
            id = value;
        } else {
            setClause += column + " = '" + value + "', ";
        }
    }
    setClause = setClause.substr(0, setClause.size() - 2); // Remove trailing comma

    return builder.update(getTableName())
                  .set(setClause)
                  .where("id = " + id)
                  .getQuery();
}

std::string Entity::deleteSQL() const {
    SQLBuilder builder;
    std::map<std::string, std::string> fields = getFields();
    std::string id = fields.at("id");

    return builder.deleteFrom(getTableName())
                  .where("id = " + id)
                  .getQuery();
}

std::string Entity::selectSQL(const std::string& tableName, const std::string& id) {
    SQLBuilder builder;
    return builder.select({"*"})
                  .from(tableName)
                  .where("id = " + id)
                  .getQuery();
}

