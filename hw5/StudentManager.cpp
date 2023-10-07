#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class StudentManager {
private:
    unordered_map<int, pair<string, string>> students;

public:
    void insert(int ID, const string& name, const string& class_name) {
        students[ID] = make_pair(name, class_name);
    }

    void deleteStudent(int ID) {
        students.erase(ID);
    }

    string infor(int ID) {
        if (students.find(ID) != students.end()) {
            return students[ID].first + "," + students[ID].second;
        } else {
            return "NA,NA";
        }
    }
};

int main() {
    StudentManager manager;
    string res = "";
    int s;
    cin >> s;
	cin.ignore();
    while (s) {
        string operation;
        getline(cin, operation, '(');
        
        if (operation.find("Insert") == 0) {
            int ID;
            string name, class_name;
            cin >> ID;
            cin.ignore();
            getline(cin, name, ',');
            getline(cin, class_name, ')');
            manager.insert(ID, name, class_name);
		  
        } else if (operation.find("Delete") == 0) {
            int ID;
            cin >> ID;
            cin.ignore();
            manager.deleteStudent(ID);
        } else if (operation.find("Infor") == 0) {
            int ID;
            cin >> ID;
            cin.ignore();
            res += manager.infor(ID);
            res += "\n";
        }
        cin.ignore();
        s--;
    }
    cout << res;
    

    return 0;
}

