#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string fullName;
    string personID;
    string mail;

public:
    Person(string n, string id, string m) {
        fullName = n;
        personID = id;
        mail = m;
    }

    void showInfo() {
        cout << "Name: " << fullName << endl;
        cout << "ID: " << personID << endl;
        cout << "Email: " << mail << endl;
    }
};
//STUDENT
class Student : public Person {
protected:
    string registerNum;

public:
    Student(string n, string id, string m, string rollNum) : Person(n, id, m) {
        registerNum = rollNum;
    }

    void uploadAssignment() {
        cout << fullName << " (" << registerNum << ") has uploaded lab assignment after the deadline." << endl;
    }

    string getRegisterNum() {
        return registerNum;
    }
};
//TEACHERR
class Teacher : public Person {
private:
    string sub;

public:
    Teacher(string n, string id, string m, string subject) : Person(n, id, m) {
        sub = subject;
    }

    void giveLabTask() {
        cout << "Sir " << fullName << " gave lab work for " << sub << "." << endl;
    }

    void weeklySummary() {
        cout << "Sir " << fullName << " submitted weekly summary with one student missing." << endl;
    }
};
//LAB ENGINEER
class LabInstructor : public Person {
protected:
    int totalLabHrs;

public:
    LabInstructor(string n, string id, string m, int hrs) : Person(n, id, m) {
        totalLabHrs = hrs;
    }

    void startLab() {
        cout << "Lab Instructor " << fullName << " started Lab 30 Minutes Late." << endl;
    }

    void checkAssignment() {
        cout << "Lab Instructor " << fullName << " checked only half of the lab submissions." << endl;
    }
};
//TA
class TeachingAssistant {
private:
    Student sPart;
    LabInstructor lPart;

public:
    TeachingAssistant(Student s, LabInstructor L) : sPart(s), lPart(L) {}

    void assistStudents() {
        cout << sPart.getRegisterNum() << " TA helped with explaining the assignment during TA Session but forgot to update attendance." << endl;
    }

    void markSubmissions() {
        cout << sPart.getRegisterNum() << " TA has marked some assignments but missed few of them." << endl;
    }

    void submitOwnAssignment() {
        sPart.uploadAssignment();
    }
};

int main() {
    Teacher courseTeacher("Sir Zulqurnain", "z020", "muhammad.zulqarnain@nu.edu.pk", "CS1004 OOP ");
    LabInstructor labSir("Sir Hamza Raziq Khan", "Hk23", "hamza.raziq@nu.edu.pk", 3);
    Student MuhammadYasir("Muhammad Yasir", "24P-0725", "p240725@pwr.nu.edu.pk", "24P-0725");
    TeachingAssistant ta(MuhammadYasir, labSir);

    cout << "--------- FAST NUCES PWR CAMPUS Course Simulation System--------" << endl;

    labSir.startLab();
    courseTeacher.giveLabTask();
    ta.assistStudents();
    MuhammadYasir.uploadAssignment();
    ta.markSubmissions();
    labSir.checkAssignment();
    courseTeacher.weeklySummary();

    cout << "\n\nSimulation End" << endl;

    return 0;
}
