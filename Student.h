//
// Created by 许逸 on 2024/5/13.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

class Student {
    std::string name = "xuyi";
    int score = 0;
protected:
    [[nodiscard]] bool canFinishSchool() const {
        return this->score >= 60;
    }
public:
    explicit Student(const int _score) {
        this->score = _score;
    }

    Student();

    template <typename T>
    int getScore(T x);
    std::string getName();

    static bool isBad() {
        return false;
    }

    // Teacher是友元
    friend class Teacher;
};

class Teacher {
    static void teachStudent(const Student& s) {
        if (s.canFinishSchool()) {
            std::cout << "可以毕业" << std::endl;
        }
    }
};

template<typename T>
int Student::getScore(T x) {
    this->score += x;
    return this->score;
}

inline std::string Student::getName() {
    return this->name;
}

class BadStudent : public Student {
public:
    explicit BadStudent(const int _score)
        : Student(_score) {
    }

    BadStudent(const int _score, const std::string &_name): Student() {

    }

    static bool isBad() {
        return true;
    }
};

class classRoom {
    std::vector<Student> students;
public:
    explicit classRoom(const int number) {
        this->students.resize(number);
    }

    void addStudent(const Student &stu) {
        this->students.push_back(stu);
    }

    [[nodiscard]] int getStudentNumber() const {
        return static_cast<int>(this->students.size());
    }

    void removeLastStudent() {
        if (! this->students.empty()) {
            this->students.pop_back();
        }
    }
};

class classRoomUtils {
public:
    static classRoom* createClassRoomByNumber(const int number) {
        return new classRoom(number);
    }

    static classRoom* allBadStudentByNumber(const int number) {
        const auto ret = new classRoom(0);
        for (int i = 0; i < number; i++) {
            ret->addStudent(BadStudent(55));
        }
        return ret;
    }
};

#endif //STUDENT_H