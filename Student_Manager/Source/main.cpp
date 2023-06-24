#include <iostream>
#include "../Header/student.h"
#include "../Header/studentmanager.h"

int main()
{
    StudentManager studentManager;
    studentManager.loadFile();

    int option;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Find by Name" << endl;
        cout << "5. Sort by GPA" << endl;
        cout << "6. Sort by Name" << endl;
        cout << "7. Display Student list" << endl;
        cout << "8. Save to file" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> option;

        switch (option){
            case 1: {
                string name, gender;
                int age;
                float math, physics, chemistry;

                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter student gender: ";
                getline(cin, gender);

                cout << "Enter student age: ";
                cin >> age;
                
                cout << "Enter math score: ";
                cin >> math;
                
                cout << "Enter physics score: ";
                cin >> physics;
                
                cout << "Enter chemistry score: ";
                cin >> chemistry;

                Student newStudent (name, gender, age, math, physics, chemistry);
                studentManager.addStudent(newStudent);
                studentManager.saveToFile(); // 
                cout << "Student added successfully." << endl;
                break;
            }
            case 2: {
                int id;
                string name, gender;
                int age;
                float math, physics, chemistry;
                
                cout << "Enter student ID to update: ";
                cin >> id;
                
                Student* foundStudent = studentManager.findById(id);
                if (foundStudent == nullptr){
                    cout << "Student not found." << endl;
                    break;
                }

                cout << "Enter new student name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter new student gender: ";
                getline(cin, gender);

                cout << "Enter new student age: ";
                cin >> age;
                
                cout << "Enter new math score: ";
                cin >> math;
                
                cout << "Enter new physics score: ";
                cin >> physics;
                
                cout << "Enter new chemistry score: ";
                cin >> chemistry;

                Student updateStudent (name, gender, age, math, physics, chemistry);
                if (studentManager.updateById(id, updateStudent)){
                    studentManager.saveToFile(); // 
                    cout << "Student updated successfully." << endl;
                } else 
                    cout << "Student not found." << endl;
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                if (studentManager.deleteById(id)){
                    cout << "Student deleted successfully." << endl;
                    studentManager.saveToFile(); //
                } else 
                    cout << "Student not found." << endl;
                break;
            }
            case 4: {
                string name;
                cout << "Enter student name to search: ";
                cin.ignore();
                getline(cin, name);
                Student* foundStudent = studentManager.findByName(name);
                if (foundStudent != nullptr){
                    cout << "Student found: " << endl;
                    cout << "ID: " << foundStudent -> getId() << endl;
                    cout << "Name: " << foundStudent -> getName() << endl;
                    cout << "Gender: " << foundStudent -> getGender() << endl;
                    cout << "Age: " << foundStudent -> getAge() << endl;
                    cout << "Math Score: " << foundStudent -> getMathScore() << endl;
                    cout << "Physics Score: " << foundStudent -> getPhysicsScore() << endl;
                    cout << "Chemistry Score: " << foundStudent -> getChemistryScore() << endl;
                    cout << "GPA: " << foundStudent -> getGPA() << endl;
                    cout << "Avademic Performance: " << foundStudent -> getPerformance() << endl;
                    studentManager.saveToFile(); //
                }
                else 
                    cout << "Student not found." << endl;
                break;
            }
            case 5: {
                studentManager.sortByGPA();
                cout <<"Student sorted by GPA." << endl;
                studentManager.saveToFile(); // 
                break;
            }
            case 6: {
                studentManager.sortByName();
                cout << "Students sorted by name." << endl;
                studentManager.saveToFile(); //
                break;
            }
            case 7: {
                studentManager.displayStudents();
                studentManager.saveToFile(); //
                break;
            }
            case 8: {
                studentManager.saveToFile();
                cout << "Students list saved to file." << endl;
                break;
            }
            case 0: {
                cout << "Exiting program...." << endl;
                break;
            }
            default:{
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (option != 0);

    return 0;
}
