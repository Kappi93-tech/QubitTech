//HERE NO ONLINE DATABASE INCLUDED
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>   // For system()
#include "json.hpp" // Include your header file
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}
using namespace std;


int main() {
    // Declare variables for user input
    string name;
    string age;  // Changed to string
    bool isStudent;  // Boolean to store student status
    string gradesCount;  // Changed to string

       setColor(10, 0);  // 10 is green, 0 is black background

    cout << "WELCOME TO JSON PARSE LIBRARY," << std::endl;
    Sleep(1000);
    system("cls");
    // Get user input
     cout << "JSON HEADER HAD STARTED...., please wait" << std::endl;
    Sleep(2000);
    system("cls");
    setColor(7, 0);

    cout << "\n\n\t\tDetails to be parsed \n\n\n\t\tEnter name: ";
    getline(cin, name);

    cout << "\n\n\t\tEnter age: ";  // Still string input
    getline(cin, age);

    // Loop until the user enters '1' or '0' for student confirmation
    string studentInput;
    do {
        cout << "Is the person a student? (1 for yes, 0 for no): ";
        getline(cin, studentInput);

        // Check if the input is either "1" or "0"
        if (studentInput != "1" && studentInput != "0") {
            cout << "Invalid input! Please enter 1 for yes or 0 for no." << endl;
        }
    } while (studentInput != "1" && studentInput != "0");

    // Convert the input to boolean
    isStudent = (studentInput == "1");
Sleep(1000);
    system("cls");
    cout << "\n\n\t\tHow many grades do you want to enter? ";
    getline(cin, gradesCount);

    JsonArray grades;

    // Convert gradesCount string to integer for looping
    int gradesCountInt = stoi(gradesCount);
    for (int i = 0; i < gradesCountInt; ++i) {
        string grade;
        cout << "Enter grade " << (i + 1) << ": ";
        getline(cin, grade);  // Accept grades as strings
        grades.push_back(JsonValue(grade));  // Store grade as a string
    }

    // Create a JSON object with the user inputs
    JsonObject obj = createJsonObject({
        {"name", name},
        {"age", age},  // Age stored as string
        {"isStudent", isStudent ? "student" : "not student"},  // Display as "student" or "not student"
        {"grades", grades}
    });

    // Create a JSON value from the object
    JsonValue jsonValue(obj);

    cout << "Connecting to database, but for this no database initialization," << std::endl;
    Sleep(1000);
    system("cls");
    // Get user input
     cout << "JSON HEADER HAD COMPLETED...., please wait" << std::endl;
    Sleep(2000);
    system("cls");
    setColor(7, 0);
         cout << "JSON HEADER HAD COMPLETED." << std::endl;
    // Print the JSON string
    cout << "Generated JSON: " << jsonStringify(jsonValue) << endl;

    return 0;
}




//HERE ONLINE DATABASE WORK BUT Error linker file =================== =========== =============       ==============
/*#include <iostream>
#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include "json.hpp"  // Include the json.hpp file

using json = nlohmann::json; // Using the nlohmann namespace for convenience
using namespace std;

int main() {
    // MySQL connection setup
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    // Replace these with your online database credentials
    string host = "https://www.phpmyadmin.co/db_structure.php?server=1&db=sql7740097"; // e.g., "mysql.example.com"
    string user = "sql7740097";     // Your MySQL username
    string password = "2rT7wLncrA";  // Your MySQL password
    string db_name = "sql7740097";   // Your database name

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        // Connect to the online MySQL database
        con = driver->connect(host, user, password);

        // Connect to the specified database
        con->setSchema(db_name);

        // JSON object to hold student data
        json studentData;

        // Get user input
        cout << "Enter name: ";
        string name;
        getline(cin, name);

        cout << "Enter age: ";
        int age;
        cin >> age;

        cout << "Is the person a student? (1 for yes, 0 for no): ";
        bool isStudent;
        cin >> isStudent;

        cout << "How many grades do you want to enter? ";
        int gradesCount;
        cin >> gradesCount;

        // Create a JSON object for student data
        studentData["name"] = name;
        studentData["age"] = age;
        studentData["isStudent"] = isStudent;

        // Create an array for grades
        json gradesArray = json::array();

        // Get grades input
        for (int i = 0; i < gradesCount; ++i) {
            int grade;
            cout << "Enter grade " << (i + 1) << ": ";
            cin >> grade;
            gradesArray.push_back(grade); // Add the grade to the array
        }

        // Add grades to the student JSON object
        studentData["grades"] = gradesArray;

        // Prepare SQL statements
        sql::PreparedStatement *pstmt;

        // Insert student into Students table
        pstmt = con->prepareStatement("INSERT INTO Students (name, age, isStudent) VALUES (?, ?, ?)");
        pstmt->setString(1, studentData["name"]);
        pstmt->setInt(2, studentData["age"]);
        pstmt->setBoolean(3, studentData["isStudent"]);
        pstmt->executeUpdate();

        // Get the last inserted student id
        int student_id = con->insert_id();

        // Insert grades into Grades table
        pstmt = con->prepareStatement("INSERT INTO Grades (student_id, grade) VALUES (?, ?)");

        for (auto& grade : studentData["grades"]) {
            pstmt->setInt(1, student_id);
            pstmt->setInt(2, grade);
            pstmt->executeUpdate();
        }

        cout << "Student and grades inserted successfully." << endl;

        delete pstmt;
        delete con;
    } catch (sql::SQLException &e) {
        cout << "SQL error: " << e.what() << endl;
    } catch (json::exception& e) {
        cout << "JSON error: " << e.what() << endl;
    }

    return 0;
}
*/
