#ifndef STUDENTMANAGER_H 
#define STUDENTMANAGER_H

#include "student.h"
#include <list>

using namespace std;

class StudentManager{
    private:
        list <Student> students; 

    public:
        void loadFile();

        void saveToFile();

        void addStudent(const Student& student);

        bool updateById(int id, const Student& updateStudent);

        bool deleteById(int id);

        Student* findById(int id);

        Student* findByName(const string& name);

        void sortByGPA();

        void sortByName();

        void displayStudents();
};      

#endif
