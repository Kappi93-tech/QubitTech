#ifndef JSON_HPP
#define JSON_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <typeinfo>

// Forward declaration of JsonValue class
class JsonValue;

using JsonObject = std::map<std::string, JsonValue>;
using JsonArray = std::vector<JsonValue>;

// Enum to identify the type of JsonValue
enum JsonType {
    JsonNull,
    JsonBool,
    JsonInt,
    JsonDouble,
    JsonString,
    JsonObjectType,
    JsonArrayType
};

class JsonValue {
public:
    JsonValue() : type(JsonNull) {}
    JsonValue(bool b) : type(JsonBool), boolValue(b) {}
    JsonValue(int i) : type(JsonInt), intValue(i) {}
    JsonValue(double d) : type(JsonDouble), doubleValue(d) {}
    JsonValue(const std::string& str) : type(JsonString), stringValue(str) {}
    JsonValue(const JsonObject& obj) : type(JsonObjectType), objectValue(obj) {}
    JsonValue(const JsonArray& arr) : type(JsonArrayType), arrayValue(arr) {}

    JsonType getType() const { return type; }

    bool isNull() const { return type == JsonNull; }
    bool isBool() const { return type == JsonBool; }
    bool isInt() const { return type == JsonInt; }
    bool isDouble() const { return type == JsonDouble; }
    bool isString() const { return type == JsonString; }
    bool isObject() const { return type == JsonObjectType; }
    bool isArray() const { return type == JsonArrayType; }

    bool getBool() const {
        if (type != JsonBool) throw std::runtime_error("Not a boolean");
        return boolValue;
    }

    int getInt() const {
        if (type != JsonInt) throw std::runtime_error("Not an integer");
        return intValue;
    }

    double getDouble() const {
        if (type != JsonDouble) throw std::runtime_error("Not a double");
        return doubleValue;
    }

    const std::string& getString() const {
        if (type != JsonString) throw std::runtime_error("Not a string");
        return stringValue;
    }

    const JsonObject& getObject() const {
        if (type != JsonObjectType) throw std::runtime_error("Not an object");
        return objectValue;
    }

    const JsonArray& getArray() const {
        if (type != JsonArrayType) throw std::runtime_error("Not an array");
        return arrayValue;
    }

private:
    JsonType type;
    bool boolValue;
    int intValue;
    double doubleValue;
    std::string stringValue;
    JsonObject objectValue;
    JsonArray arrayValue;
};

// Function to create a JSON string from JsonValue
std::string jsonStringify(const JsonValue& value);

// Function to create a JSON object from an initializer list
JsonObject createJsonObject(const std::initializer_list<std::pair<const std::string, JsonValue>>& init) {
    return JsonObject(init);
}

// Function to create a JSON array from an initializer list
JsonArray createJsonArray(const std::initializer_list<JsonValue>& init) {
    return JsonArray(init);
}

// Implementation for jsonStringify function
std::string jsonStringify(const JsonValue& value) {
    switch (value.getType()) {
        case JsonNull: return "null";
        case JsonBool: return value.getBool() ? "true" : "false";
        case JsonInt: return std::to_string(value.getInt());
        case JsonDouble: return std::to_string(value.getDouble());
        case JsonString: return "\"" + value.getString() + "\"";
        case JsonObjectType: {
            std::string result = "{";
            const auto& obj = value.getObject();
            for (auto it = obj.begin(); it != obj.end(); ++it) {
                if (it != obj.begin()) result += ",";
                result += "\"" + it->first + "\":" + jsonStringify(it->second);
            }
            result += "}";
            return result;
        }
        case JsonArrayType: {
            std::string result = "[";
            const auto& arr = value.getArray();
            for (size_t i = 0; i < arr.size(); ++i) {
                if (i > 0) result += ",";
                result += jsonStringify(arr[i]);
            }
            result += "]";
            return result;
        }
        default: return "{}"; // Default empty JSON object for demonstration
    }
}

#endif // JSON_HPP
