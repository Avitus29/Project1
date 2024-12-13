#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
struct Student {
    int ID;
    string name,course,year;

    void display() const{
        cout<<"ID:"<< ID <<"\n Name:" << name <<"\nCourse:"<<course<<"\nYear:"<<year<<"\n\n";
    }
};
void addStudent();
void readStudents();
void updateStudents();
void deleteStudents();

vector<Student> loadStudents();
void saveStudents(const vector<Student>& students);

const string filename ="students.txt";

int main() {
    int choice;

    do{
        cout<<"\n------STUDENT MANAGEMENT----\n";
        cout<<"1.Add Student\n";
        cout<<"2.Read Student\n";
        cout<<"3.Update Student\n";
        cout<<"4.Delete Student\n";
        cout<<"5.Exit\n";
        cout<<"Enter the choice:";
        cin>>choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                readStudents();
                break;
            case 3:
                updateStudents();
                break;
            case 4:
                deleteStudents();
                break;
            case 5:
                cout<<"Exiting...........\n";
                break;
        }
    } while (choice !=5);
    return 0;
}

void addStudent() {
    vector<Student> students = loadStudents();
    Student s;

    cout<<"Enter the Student ID:";
    cin >>s.ID;
    cin.ignore();
    cout<<"Enter the Student Name:";
    getline(cin, s.name);
    cout<<"Enter the course taken by student:";
    getline(cin,s.course);
    cout<<"Enter the academic year of student:";
    getline(cin,s.year);

    students.push_back(s);
    saveStudents(students);
    cout<<"Student added successfully!\n";
}

void readStudents() {
    vector<Student> students =loadStudents();

    if(students.empty()) {
        cout<<"No students found.\n";
    }else{
        cout<<"\n----Students List----";
        for(const auto& s:students) {
            s.display();
        }
    }
}
void updateStudents() {
    vector<Student> students = loadStudents();
    int ID;
    bool found =false;

    cout<<"Enter Student ID to update:";
    cin>>ID;

    for (auto& s : students) {
        if (s.ID == ID) {
            found=true;
            cin.ignore();
            cout<<"Enter  Student New Name:";
            getline(cin,s.name);
            cout<<"Enter the new id of student:";
            cin>>s.ID;

            saveStudents(students);
            cout<<"Student succesfully updated!\n";
            break;
        }
    }
    if (!found) {
        cout<<"Student with ID"<<ID<<"not found.\n";
    }
}

void deleteStudent() {
    vector<Student> students =loadStudents();
    int ID;
    bool found =false;

    cout<<"Enter Student ID to delete:";
    cin>>ID;

    for (auto it =students.begin(); it !=students.end(); ++it) {
        if (it->ID == ID) {
            found = true;
            students.erase(it);
            saveStudents(students);
            cout<<"Student Deleted!..\n";
            break;
        }
    }
}