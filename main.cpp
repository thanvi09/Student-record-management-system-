#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    string dept;
    int perf; // performance percentage
};

const int MAX_STUDENTS = 100;

void addStudent(Student s[], int &n) {
    if (n >= MAX_STUDENTS) {
        cout << "Cannot add more students.\n";
        return;
    }
    cout << "Enter roll number: ";
    cin >> s[n].roll;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, s[n].name);
    cout << "Enter department: ";
    getline(cin, s[n].dept);
    cout << "Enter performance (0-100): ";
    cin >> s[n].perf;

    n++;
    cout << "Student added successfully.\n";
}

void displayAll(const Student s[], int n) {
    if (n == 0) {
        cout << "No records to display.\n";
        return;
    }
    cout << "\n--- All Student Records ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Roll: " << s[i].roll
             << ", Name: " << s[i].name
             << ", Dept: " << s[i].dept
             << ", Performance: " << s[i].perf << "%\n";
    }
}

int findIndexByRoll(const Student s[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) return i;
    }
    return -1;
}

void searchStudent(const Student s[], int n) {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;
    int idx = findIndexByRoll(s, n, roll);
    if (idx == -1) {
        cout << "Student not found.\n";
    } else {
        cout << "Found: Roll: " << s[idx].roll
             << ", Name: " << s[idx].name
             << ", Dept: " << s[idx].dept
             << ", Performance: " << s[idx].perf << "%\n";
    }
}

void updateStudent(Student s[], int n) {
    int roll;
    cout << "Enter roll number to update: ";
    cin >> roll;
    int idx = findIndexByRoll(s, n, roll);
    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter new name (old: " << s[idx].name << "): ";
    cin.ignore();
    getline(cin, s[idx].name);

    cout << "Enter new department (old: " << s[idx].dept << "): ";
    getline(cin, s[idx].dept);

    cout << "Enter new performance (old: " << s[idx].perf << "): ";
    cin >> s[idx].perf;

    cout << "Record updated.\n";
}

void deleteStudent(Student s[], int &n) {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;
    int idx = findIndexByRoll(s, n, roll);
    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }
    // shift left
    for (int i = idx; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    n--;
    cout << "Record deleted.\n";
}

void showPerformanceSummary(const Student s[], int n) {
    if (n == 0) {
        cout << "No records.\n";
        return;
    }
    int total = 0;
    int high = s[0].perf;
    int low = s[0].perf;

    for (int i = 0; i < n; i++) {
        total += s[i].perf;
        if (s[i].perf > high) high = s[i].perf;
        if (s[i].perf < low)  low = s[i].perf;
    }

    double avg = (double)total / n;
    cout << "\n--- Performance Summary ---\n";
    cout << "Average Performance: " << avg << "%\n";
    cout << "Highest Performance: " << high << "%\n";
    cout << "Lowest Performance : " << low  << "%\n";
}

int main() {
    Student s[MAX_STUDENTS];
    int n = 0;
    int choice;

    do {
        cout << "\n===== Student Record Management (C++) =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student (by roll)\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Performance Summary\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(s, n); break;
            case 2: displayAll(s, n); break;
            case 3: searchStudent(s, n); break;
            case 4: updateStudent(s, n); break;
            case 5: deleteStudent(s, n); break;
            case 6: showPerformanceSummary(s, n); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
