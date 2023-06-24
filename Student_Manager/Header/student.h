#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student{
    private:
        static int nextId;
        int id;
        string name;
        string gender;
        int age;
        float math;
        float physics;
        float chemistry;
    public: 

        Student (string name, string gender, int age, float math, float physics, float chemistry);

        int getId() const;

        void setId(int newId);

        string getName() const;

        void setName(const string& newname);

        string getGender() const;

        void setGender(string newgender);

        int getAge() const;

        void setAge(int newAge);

        float getMathScore() const;

        void setMathScore(float mathScore);

        float getPhysicsScore() const;

        void setPhysicsScore(float physicsScore);

        float getChemistryScore() const;

        void setChemistryScore(float chemistryScore);

        float getGPA() const;
        
        string getPerformance() const;
};

#endif //STUDENT_H
