#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

enum DEPARTMENT_TYPE {
    DEFAULT=0,
    SALES,
    CUSTOMER_SERVICE,
    PRODUCTION,
    HUMAN_RESOURCES,
    ACCOUNTING,
    RESEARCH_AND_DEVELOPMENT
};

// Helper function to convert DEPARTMENT_TYPE to c-string
const char* deptToString(DEPARTMENT_TYPE d) {
    switch(d) {
        case DEFAULT: return "DEFAULT";
        case SALES: return "SALES";
        case CUSTOMER_SERVICE: return "CUSTOMER SERVICE";
        case PRODUCTION: return "PRODUCTION";
        case HUMAN_RESOURCES: return "HUMAN RESOURCES";
        case ACCOUNTING: return "ACCOUNTING";
        case RESEARCH_AND_DEVELOPMENT: return "RESEARCH AND DEVELOPMENT";
    }
    return "DEFAULT";
}
class employee {
private:
    int aID;
    char* full_name;
    DEPARTMENT_TYPE department;

    static int counter; // Static counter

public:
    // Default constructor
    employee() {
        aID = 0;
        full_name = nullptr;
        department = DEFAULT;
        counter++;
    }

    // Parametrized constructor
    employee(int id, const char* name, DEPARTMENT_TYPE dept) {
        aID = id;
        if (name != nullptr) {
            full_name = new char[strlen(name)+1];
            strcpy(full_name, name);
        } else {
            full_name = nullptr;
        }
        department = dept;
        counter++;
    }

    // Destructor
    ~employee() {
        if (full_name != nullptr) {
            delete[] full_name;
        }
        counter--;
    }

    // Copy constructor and assignment operator
    employee(const employee& other) {
        aID = other.aID;
        department = other.department;
        if (other.full_name != nullptr) {
            full_name = new char[strlen(other.full_name)+1];
            strcpy(full_name, other.full_name);
        } else {
            full_name = nullptr;
        }
        counter++;
    }

    employee& operator=(const employee& other) {
        if (this == &other) return *this;
        if (full_name) delete[] full_name;
        aID = other.aID;
        department = other.department;
        if (other.full_name != nullptr) {
            full_name = new char[strlen(other.full_name)+1];
            strcpy(full_name, other.full_name);
        } else {
            full_name = nullptr;
        }
        return *this;
    }

    // Accessors
    int getAID() const { return aID; }
    const char* getFullName() const { return full_name; }
    DEPARTMENT_TYPE getDepartment() const { return department; }

    // Mutators
    void setAID(int id) { aID = id; }
    void setFullName(const char* name) {
        if (full_name) delete[] full_name;
        if (name != nullptr) {
            full_name = new char[strlen(name)+1];
            strcpy(full_name, name);
        } else {
            full_name = nullptr;
        }
    }
    void setDepartment(DEPARTMENT_TYPE d) { department = d; }

    static int getCounter() { return counter; }

    // print method
    void print() const {
        cout << "Employee Object State: " << endl;
        cout << "aID: " << (aID > 0 ? to_string(aID) : "0") << endl;
        cout << "Full Name: " << (full_name ? full_name : "NONAME") << endl;
        cout << "Department: " << deptToString(department) << endl;
        cout << "Counter: " << counter << endl;
    }

    // friend function to print data members
    friend void printEmployee(const employee& emp) {
        cout << emp.aID << " "
             << (emp.full_name ? emp.full_name : "NONAME") << " "
             << deptToString(emp.department) << " "
             << "Counter: " << employee::counter << endl;
    }
};

int employee::counter = 0; // static counter
class address {
private:
    int aID;
    int street_number;
    char* street_name;
    char* city;
    char* state_abbrev;
    int zip_code;

    static int counter;

public:
    // Default constructor
    address() {
        aID = 0;
        street_number = 0;
        street_name = nullptr;
        city = nullptr;
        state_abbrev = nullptr;
        zip_code = 0;
    }

    // Parametrized constructor
    address(int id, int sn, const char* sname, const char* c, const char* st, int zip) {
        aID = id;
        street_number = sn;
        if (sname) {
            street_name = new char[strlen(sname) + 1];
            strcpy(street_name, sname);
        }
        else {
            street_name = nullptr;
        }
        if (c) {
            city = new char[strlen(c) + 1];
            strcpy(city, c);
        }
        else {
            city = nullptr;
        }
        if (st) {
            state_abbrev = new char[strlen(st) + 1];
            strcpy(state_abbrev, st);
        }
        else {
            state_abbrev = nullptr;
        }
        zip_code = zip;
    }

    // Destructor
    ~address() {
        if (street_name) delete[] street_name;
        if (city) delete[] city;
        if (state_abbrev) delete[] state_abbrev;
    }

    // Copy constructor and assignment operator
    address(const address& other) {
        aID = other.aID;
        street_number = other.street_number;
        zip_code = other.zip_code;

        if (other.street_name) {
            street_name = new char[strlen(other.street_name) + 1];
            strcpy(street_name, other.street_name);
        }
        else {
            street_name = nullptr;
        }

        if (other.city) {
            city = new char[strlen(other.city) + 1];
            strcpy(city, other.city);
        }
        else {
            city = nullptr;
        }

        if (other.state_abbrev) {
            state_abbrev = new char[strlen(other.state_abbrev) + 1];
            strcpy(state_abbrev, other.state_abbrev);
        }
        else {
            state_abbrev = nullptr;
        }

    }

    address& operator=(const address& other) {
        if (this == &other) return *this;
        if (street_name) delete[] street_name;
        if (city) delete[] city;
        if (state_abbrev) delete[] state_abbrev;

        aID = other.aID;
        street_number = other.street_number;
        zip_code = other.zip_code;

        if (other.street_name) {
            street_name = new char[strlen(other.street_name) + 1];
            strcpy(street_name, other.street_name);
        }
        else {
            street_name = nullptr;
        }

        if (other.city) {
            city = new char[strlen(other.city) + 1];
            strcpy(city, other.city);
        }
        else {
            city = nullptr;
        }

        if (other.state_abbrev) {
            state_abbrev = new char[strlen(other.state_abbrev) + 1];
            strcpy(state_abbrev, other.state_abbrev);
        }
        else {
            state_abbrev = nullptr;
        }

        return *this;
    }

    // Accessors
    int getAID() const { return aID; }
    int getStreetNumber() const { return street_number; }
    const char* getStreetName() const { return street_name; }
    const char* getCity() const { return city; }
    const char* getStateAbbrev() const { return state_abbrev; }
    int getZipCode() const { return zip_code; }

    // Mutators
    void setAID(int id) { aID = id; }
    void setStreetNumber(int sn) { street_number = sn; }
    void setStreetName(const char* s) {
        if (street_name) delete[] street_name;
        if (s) {
            street_name = new char[strlen(s) + 1];
            strcpy(street_name, s);
        }
        else {
            street_name = nullptr;
        }
    }
    void setCity(const char* c) {
        if (city) delete[] city;
        if (c) {
            city = new char[strlen(c) + 1];
            strcpy(city, c);
        }
        else {
            city = nullptr;
        }
    }
    void setStateAbbrev(const char* st) {
        if (state_abbrev) delete[] state_abbrev;
        if (st) {
            state_abbrev = new char[strlen(st) + 1];
            strcpy(state_abbrev, st);
        }
        else {
            state_abbrev = nullptr;
        }
    }
    void setZipCode(int zip) { zip_code = zip; }

    static int getCounter() { return counter; }
    static void incrementCounter() { counter++; }
    static void decrementCounter() { if(counter>0) counter--; }

    void print() const {
        cout << "Address Object State:" << endl;
        cout << "aID: " << (aID > 0 ? to_string(aID) : "0") << endl;
        cout << "Street Number: " << (street_number > 0 ? to_string(street_number) : "0") << endl;
        cout << "Street Name: " << (street_name ? street_name : "NONAME") << endl;
        cout << "City: " << (city ? city : "NONAME") << endl;
        cout << "State: " << (state_abbrev ? state_abbrev : " ") << endl;
        cout << "Zip: " << (zip_code > 0 ? to_string(zip_code) : "0") << endl;
        cout << "Counter: " << counter << endl;
    }

    // friend function
    friend void printAddress(const address& addr) {
        cout << addr.aID << " "
             << (addr.street_number > 0 ? to_string(addr.street_number).c_str() : "0") << " "
             << (addr.street_name ? addr.street_name : "NONAME") << " "
             << (addr.city ? addr.city : "NONAME") << " "
             << (addr.state_abbrev ? addr.state_abbrev : " ") << " "
             << (addr.zip_code > 0 ? to_string(addr.zip_code).c_str() : "0") << " "
             << "Counter: " << address::counter << endl;
    }
};

int address::counter = 0; // static counter
class record : public employee, public address {
public:
    record() : employee(), address() {
        
    }

    record(const employee &emp, const address &addr) : employee(emp), address(addr) {
        
        // Increment address counter each time a record is created with a valid address
        if (addr.getAID() == emp.getAID() && emp.getAID() != 0) {
            address::incrementCounter();
        }
    }

    ~record() {
        
    }
    
    int getAID() const { return employee::getAID(); }

    void print() const {
        // Prepare the street address with zero-padded street number
        std::string streetAddr = "NOSTREET";
        if (getStreetNumber() >= 0 && getStreetName()) {
            int num = getStreetNumber();
            char zeroPadded[5]; // 4 digits + null terminator

            // Extract digits
            int ones = num % 10;
            int tens = (num / 10) % 10;
            int hundreds = (num / 100) % 10;
            int thousands = (num / 1000) % 10;

            // Convert each digit to a character
            zeroPadded[0] = '0' + thousands;
            zeroPadded[1] = '0' + hundreds;
            zeroPadded[2] = '0' + tens;
            zeroPadded[3] = '0' + ones;
            zeroPadded[4] = '\0';

            streetAddr = zeroPadded;
            streetAddr += " ";
            streetAddr += getStreetName();
        }

        cout << left
             << setw(5) << (getAID() > 0 ? to_string(getAID()) : "0") << " "
             << setw(20) << (getFullName() ? getFullName() : "NONAME") << " "
             << setw(25) << streetAddr << " "
             << setw(25) << (getCity() ? getCity() : "NOCITY") << " "
             << setw(10) << (getStateAbbrev() ? getStateAbbrev() : "NOSTATE") << " "
             << setw(10) << (getZipCode() > 0 ? to_string(getZipCode()) : "0") << " "
             << setw(20) << deptToString(getDepartment()) << endl;
    }
};
bool readEmployees(const char* filepath, employee*& empArray, int &empCount) {
    ifstream fin(filepath);
    if(!fin) return false;

    empCount = 0;
    {
        int lineCount = 0;
        string line;
        while (getline(fin, line)) {
            lineCount++;
        }
        empCount = lineCount / 2;

        fin.clear();
        fin.seekg(0, ios::beg);
    }

    empArray = new employee[empCount];

    for (int i = 0; i < empCount; i++) {
        int id;
        fin >> id;
        fin.ignore(10000, ' ');
        string fullNameStr;
        {
            string remainder;
            getline(fin, remainder);
            fullNameStr = remainder;
        }

        int deptVal;
        fin >> deptVal;
        DEPARTMENT_TYPE d = DEFAULT;
        switch(deptVal) {
            case 1: d = SALES; break;
            case 2: d = CUSTOMER_SERVICE; break;
            case 3: d = PRODUCTION; break;
            case 4: d = HUMAN_RESOURCES; break;
            case 5: d = ACCOUNTING; break;
            case 6: d = RESEARCH_AND_DEVELOPMENT; break;
            default: d = DEFAULT; break;
        }

        empArray[i].setAID(id);
        empArray[i].setFullName(fullNameStr.c_str());
        empArray[i].setDepartment(d);
    }

    return true;
}

bool readAddresses(const char* filepath, address*& addrArray, int &addrCount) {
    ifstream fin(filepath);
    if(!fin) return false;

    // Count how many addresses

    {
        int lineCount = 0;
        string line;
        while (getline(fin, line)) {
            lineCount++;
        }
        addrCount = lineCount / 3;
        fin.clear();
        fin.seekg(0, ios::beg);
    }

    addrArray = new address[addrCount];

    for (int i = 0; i < addrCount; i++) {
        // aID street_number street_name...
        int id, sn;
        {
            fin >> id >> sn;
            fin.ignore(1, ' ');
            string streetNameLine;
            getline(fin, streetNameLine);

            // city
            string cityLine;
            getline(fin, cityLine);

            // state_abbrev zip_code
            string stateLine;
            int zip;
            fin >> stateLine >> zip;
            fin.ignore(10000, '\n');

            // Set address
            addrArray[i].setAID(id);
            addrArray[i].setStreetNumber(sn);
            addrArray[i].setStreetName(streetNameLine.c_str());
            addrArray[i].setCity(cityLine.c_str());
            addrArray[i].setStateAbbrev(stateLine.c_str());
            addrArray[i].setZipCode(zip);
        }
    }

    return true;
}
record* createRecords(employee* empArray, int empCount, address* addrArray, int addrCount, int &recCount) {
    recCount = empCount;
    record* recArray = new record[recCount];
    for (int i = 0; i < empCount; i++) {
        int id = empArray[i].getAID();
        // Search address
        int idx = -1;
        for (int j = 0; j < addrCount; j++) {
            if (addrArray[j].getAID() == id) {
                idx = j;
                break;
            }
        }

        if (idx != -1) {
            // Match found
            recArray[i] = record(empArray[i], addrArray[idx]);
        } else {
            // record with empty address
            address emptyAddress; // default
            recArray[i] = record(empArray[i], emptyAddress);
        }
    }
    return recArray;
}
int main() {
    char addressFilePath[256] = {0};
    char employeeFilePath[256] = {0};
    bool addressFileSet = false;
    bool employeeFileSet = false;
    bool filesRead = false;

    employee* empArray = nullptr;
    address* addrArray = nullptr;
    record* recArray = nullptr;

    int empCount = 0;
    int addrCount = 0;
    int recCount = 0;

    char option;
    do {
        // the additional menu under 'c'
        cout << "a.Enter address file fullpath\n";
        cout << "b.Enter employee file fullpath\n";
        cout << "c.Read files\n";
        if (filesRead) {
            cout << "        1.Print record by index\n";
        }
        cout << "d.Print data\n";
        cout << "e.Search:\n";
        cout << "f.Sort\n";
        cout << "g.Exit\n";

        cin >> option;
        switch (option){
            case 'a':{
                cout << "Enter the fullpath for addresses file: ";
                cin.ignore(10000, '\n');
                cin.getline(addressFilePath, 256);
                ifstream test(addressFilePath);
                if(!test) {
                    cout << "[ERROR] - File not found.\n";
                    addressFileSet = false;
                } else {
                    cout << "[SUCCESS] - Addresses file is readable ..." << endl;
                    addressFileSet = true;
                }
                break;
            }
            case 'b':{
                cout << "Enter the fullpath for employees file: ";
                cin.ignore(10000, '\n');
                cin.getline(employeeFilePath, 256);
                ifstream test(employeeFilePath);
                if(!test) {
                    cout << "[ERROR] - File not found.\n";
                    employeeFileSet = false;
                } else {
                    cout << "[SUCCESS] - Employees file is readable ..." << endl;
                    employeeFileSet = true;
                }
                break;
            }
            case 'c': {
                if (!filesRead) {
                    if (!addressFileSet || !employeeFileSet) {
                        cout << "[ERROR] - Enter file location first...\n";
                    } else {
                        if (readAddresses(addressFilePath, addrArray, addrCount) && readEmployees(employeeFilePath, empArray, empCount)) {
                            cout << "[SUCCESS] -  File reading is complete ...\n";
                            filesRead = true;
                            recArray = createRecords(empArray, empCount, addrArray, addrCount, recCount);
                        } else {
                            cout << "[ERROR] - Enter file location first...\n";
                        }
                    }
                } else {
                    // Ask for the index here
                    cout << "Enter the index: ";
                    int subChoice;
                    cin >> subChoice;
                    if (subChoice < 0 || subChoice >= recCount) {
                        cout << "[ERROR] -  Invalid index value ...\n";
                    } else {
                        cout << "ID    FULL NAME           STREET ADDRESS           CITY                     STATE       ZIP CODE    DEPARTMENT  \n";
                        recArray[subChoice].print();
                    }
                }
                break;
            }
            case 'd':{
                if (!filesRead) {
                    cout << "[ERROR] - Enter file location first...\n";
                } else {
                    cout << "ID    FULL NAME           STREET ADDRESS           CITY                     STATE       ZIP CODE    DEPARTMENT  \n";
                    for (int i = 0; i < recCount; i++) {
                        recArray[i].print();
                    }
                    cout << "There are " << addrCount << " addresses, and " << empCount << " employees\n";
                }
                break;
            }
            case 'e':{
                if (!filesRead) {
                    cout << "[ERROR] - Enter file location first...\n";
                    break;
                }
                cout << "        1. Address ID\n";
                cout << "        2. ZipCode\n";
                int sc;
                cin >> sc;
                if (sc == 1) {
                    cout << "Enter the ID: ";
                    int searchID;
                    cin >> searchID;
                    bool found = false;
                    cout << "ID    FULL NAME           STREET ADDRESS           CITY                     STATE       ZIP CODE    DEPARTMENT  \n";
                    for (int i = 0; i < recCount; i++) {
                        if (recArray[i].getAID() == searchID) {
                            recArray[i].print();
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "[ERROR] - No matching address ID found.\n";
                    }
                } else if (sc == 2) {
                    cout << "Enter the ZipCode: ";
                    int szip;
                    cin >> szip;
                    bool found = false;
                    cout << "ID    FULL NAME           STREET ADDRESS           CITY                     STATE       ZIP CODE    DEPARTMENT  \n";
                    for (int i = 0; i < recCount; i++) {
                        if (recArray[i].getZipCode() == szip) {
                            recArray[i].print();
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "[ERROR] - No matching zip code found.\n";
                    }
                } else {
                    cout << "[ERROR] - Invalid search option.\n";
                }
                break;
            }
            case 'f': {
                if (!filesRead) {
                    cout << "[ERROR] - Enter file location first...\n";
                    break;
                }
                cout << "        1. Address ID\n";
                cout << "        2. ZipCode\n";
                int so;
                cin >> so;
                if (so == 1) {
                    // Insertion sort by Address ID
                    for (int i = 1; i < recCount; i++) {
                        record key = recArray[i];
                        int keyAID = key.getAID();
                        int j = i - 1;
                        // Move elements of recArray[0..i-1], that are greater than keyAID, to one position ahead
                        // of their current position
                        while (j >= 0 && recArray[j].getAID() > keyAID) {
                            recArray[j + 1] = recArray[j];
                            j = j - 1;
                        }
                        recArray[j + 1] = key;
                    }
                } else if (so == 2) {
                    // Insertion sort by ZipCode
                    for (int i = 1; i < recCount; i++) {
                        record key = recArray[i];
                        int keyZip = key.getZipCode();
                        int j = i - 1;
                        while (j >= 0 && recArray[j].getZipCode() > keyZip) {
                            recArray[j + 1] = recArray[j];
                            j = j - 1;
                        }
                        recArray[j + 1] = key;
                    }
                } else {
                    cout << "[ERROR] - Invalid sort option.\n";
                }
                break;
            }

            case 'g':{
                cout << "Ending the program ...\n";
                break;
            }
            default:{
                cout << "Invalid option, try again!\n";
                break;
            }
        }
    } while (option != 'g' && option != 'G');

    if (empArray) delete[] empArray;
    if (addrArray) delete[] addrArray;
    if (recArray) delete[] recArray;

    return 0;
}
