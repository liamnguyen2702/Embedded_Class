#include "../Header/student.h"
#include "../Header/studentmanager.h"
#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

void StudentManager::loadFile() {
    ifstream file("student.txt");
    if(file.is_open()){
        int id;
        string name;
        string gender;
        int age;
        float math;
        float physics;
        float chemistry;

        while (file >> id) {
            file.ignore();

            getline(file, name, ' ');
            getline(file, gender, ' ');
               
            file >> age >> math >> physics >> chemistry;
                    
            Student student(name, gender, age, math, physics, chemistry);
            student.setId(id);
            students.push_back(student);
            }
                file.close();
            }
        }

void StudentManager::saveToFile() {
    ofstream file("student.txt");
    if(file.is_open()) {
        for (const auto& student: students){
            file << student.getId() << " ";
            file << student.getName() << " ";
            file << student.getGender() << " ";
            file << student.getAge() << " ";
            file << student.getMathScore() << " ";
            file << student.getPhysicsScore() << " ";
            file << student.getChemistryScore() << endl;
        }
        file.close();
    }
}

void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
    saveToFile();
}

bool StudentManager::updateById(int id, const Student& updateStudent) {
    Student* foundStudent = findById(id);
    if (foundStudent != nullptr) {
        foundStudent->setName(updateStudent.getName());
        foundStudent->setGender(updateStudent.getGender());
        foundStudent->setAge(updateStudent.getAge());
        foundStudent->setMathScore(updateStudent.getMathScore());
        foundStudent->setPhysicsScore(updateStudent.getPhysicsScore());
        foundStudent->setChemistryScore(updateStudent.getChemistryScore());

        saveToFile();
        return true;
    }
    
    return false;
}

bool StudentManager::deleteById(int id) {
    for (auto it = students.begin(); it != students.end(); ++it ) {
        if (it -> getId() == id) {
            students.erase(it);
            saveToFile();
            return true;
        }
    }
    
    return false;
}

Student* StudentManager::findById(int id) {
    for (auto& student : students) {
        if (student.getId() == id) {
        return &student;
        }
    }
    
    return nullptr;
}

Student* StudentManager::findByName(const string& name){
    for (auto& student : students){
        if (student.getName() == name)
            return &student;
    }
    
    return nullptr;
}

void StudentManager::sortByGPA(){
    students.sort([](const Student& a, const Student& b) 
    {return a.getGPA() < b.getGPA();});
}

void StudentManager::sortByName(){
    students.sort([](const Student& a, const Student& b)
    {return a.getName() < b.getName();});
}

void StudentManager::displayStudents() {
    for (const auto& student : students) {
        cout << "ID: " << student.getId() << endl;
        cout << "Name: " << student.getName() << endl;
        cout << "Gender: " << student.getGender() << endl;
        cout << "Age: " << student.getAge() << endl;
        cout << "Math Score: " << student.getMathScore() << endl;
        cout << "Physics Score: " << student.getPhysicsScore() << endl;
        cout << "Chemistry Score: " << student.getChemistryScore() << endl;
        cout << "GPA: " << student.getGPA() << endl;
        cout << "Academic Performance: " << student.getPerformance() << endl;
        cout << "----------------------" << endl;
    }
}
