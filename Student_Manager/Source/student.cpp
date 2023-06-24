#include "../Header/student.h"

int Student::nextId = 1;

Student::Student (string name, string gender, int age, float math, float physics, float chemistry)
      : name(name), gender(gender), age(age), math(math), physics(physics), chemistry(chemistry) {
      id = nextId;
      nextId++;
}

int Student::getId() const {
    return id;
}

void Student::setId(int newId) {
    id = newId;
}

string Student::getName() const {
    return name;
}

void Student::setName(const string& newname) {
    name = newname;
}

string Student::getGender() const {
    return gender;
}

void Student::setGender(string newgender) {
    gender = newgender;
}

int Student::getAge() const {
    return age;
}

void Student::setAge(int newAge) {
    age = newAge;
}

float Student::getMathScore() const {
            return math;
        }

void Student::setMathScore(float mathScore) {
    math = mathScore;
    getGPA();
}

float Student::getPhysicsScore() const {
    return physics;
}

void Student::setPhysicsScore(float physicsScore) {
    physics = physicsScore;
    getGPA();
}

float Student::getChemistryScore() const {
    return chemistry;
}

void Student::setChemistryScore(float chemistryScore) {
    chemistry = chemistryScore;
    getGPA();
}

float Student::getGPA() const {
    return (math + physics + chemistry) / 3;
}
        
string Student::getPerformance() const {
    float gpa = getGPA();
    if (gpa >= 8)
        return "Giỏi";
    else if (gpa >= 6.5)
        return "Khá";
    else if (gpa >= 5)
        return "Trung bình";
    else
        return "Yếu";
}
