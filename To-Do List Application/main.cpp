#include <iostream>
#include <fstream>

using namespace std;

int getCount();
void clearTaskList();
void addTask();
void deleteTask(const string& fileName, int lineNo);
void viewTask();

int main() {
    cout << "Welcome to your To-Do List:" << endl;
    cout << "What do you want to do?" << endl;
    cout << "Type 1 - add Task | 2 - Delete Task | 3 - View Task List | 4 - Delete whole list" << endl;
    int input, lineNo;
    cin >> input;
    switch(input) {
        case 1:
            addTask();
            break;
        case 2:
            cout << "Enter line no to delete:" << endl;
            cin >> lineNo;
            deleteTask("To-DoList.txt", lineNo);
            lineNo = 0;
            break;
        case 3:
            viewTask();
            break;
        case 4:
            clearTaskList();
            cout << "Task List Deleted" << endl;
            break;
    }
    return 0;
}

void clearTaskList() {
    ofstream myFiles("To-DoList.txt");
    if (myFiles.is_open()) {
        myFiles << "";
    } else {
        cout << "Unble to open file!!!" << endl;
    }
    myFiles.close();
}

int getCount() {
    int count = 0;
    string line;
    ifstream myFiles("To-DoList.txt");
    if (myFiles.is_open()) {
        while (getline(myFiles, line)) {
            count++;
        }
    } else {
        cout << "Unble to open file!!!" << endl;
    }
    myFiles.close();
    return count;
}

void addTask() {
    string input;
    int nextCount = getCount() + 1; 
    ofstream myFiles("To-DoList.txt", ios::app);
    if (myFiles.is_open()) {
        cout << "Enter task to add:" << endl;
        cin.ignore();
        getline(cin, input);
        myFiles << nextCount << " " << input << endl;
        cout << "Task added!" << endl;
    } else {
        cout << "Unable to open file!!!" << endl;
    }
    myFiles.close();
}

void deleteTask(const string& fileName, int lineNo) {
    string line;
    int count;
    ifstream myFiles(fileName);
    ofstream tempFile("temp.txt");
    if (!myFiles.is_open()) {
        cout << "Unable to open file!!!" << endl;
    }
    if (!tempFile.is_open()) {
        cout << "Unable to open file!!!" << endl;
    }
    while (getline(myFiles, line)) {
        count++;
        if (count != lineNo)
        {
            tempFile << line << endl;
        }
    }
    myFiles.close();
    tempFile.close();
    remove(fileName.c_str());
    rename("temp.txt", fileName.c_str());
}

void viewTask() {
    string line;
    ifstream myFiles("To-DoList.txt");
    if (myFiles.is_open()) {
        while (getline(myFiles, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Unable to open file!!!" << endl;
    }
    myFiles.close();
}