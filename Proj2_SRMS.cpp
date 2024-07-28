#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {

                                    //Required fields for the Database
    string name;
    int roll_number , year ;
    string course;

};

vector<Student> students ;

void AddStudent() {
    Student s ;

    cout << "Enter name: " ;
    cin >> s.name ;

    cout << "Enter roll number: " ;
    cin >> s.roll_number ;

    cout << "Enter course: " ;
    cin >> s.course ;

    cout << "Enter Year: " ;
    cin >> s.year ; 

    students.push_back(s) ;
    cout << "Student added successfully!" << endl ;
}

void dispStudents() 
{
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }
    cout << "Student Records:\n";
    for (const Student& s : students) 
    {
        cout << "Name: " << s.name << ", Roll Number: " << s.roll_number << ", Course: " << s.course << endl;
    }
}

void searchStudent(int roll_number) 
{
    for (const Student& s : students) 
    {
        if (s.roll_number == roll_number) 
        {
            cout << "Student found:\n";
            cout << "Name: " << s.name << ", Roll Number: " << s.roll_number << ", Course: " << s.course << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void updateStudent(int roll_number) 
{
    for (Student& s : students) 
    {
        if (s.roll_number == roll_number) 
        {
            cout << "Enter new Name: ";
            cin >> s.name;
            cout << "Enter new Course: ";
            cin >> s.course;
            cout << "Student updated successfully!" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void deleteStudent (int roll_number) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll_number == roll_number) {
            students.erase(it);
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

int main() {
    int choice;
    do {
        cout << "\nStudent Record Management System\n";                         //Listing Choices
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddStudent();
                break;

            case 2:
                dispStudents();
                break;

            case 3: {
                int roll_number;
                cout << "Enter roll number to search: ";
                cin >> roll_number;
                searchStudent(roll_number);
                break;
            }

            case 4: {
                int roll_number;
                cout << "Enter roll number to update: ";
                cin >> roll_number;
                updateStudent(roll_number);
                break;
            }

            case 5: {
                int roll_number;
                cout << "Enter roll number to delete: ";
                cin >> roll_number;
                deleteStudent(roll_number);
                break;
            }

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
