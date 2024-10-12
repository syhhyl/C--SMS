#include <iostream>
#include <vector>
#include <string>

struct student {
    std::string name;
    int age;
    float grade;

    void printInfo() const {
        std::cout << "name: " << name
                  << "age: " << age
                  << "grade: " << grade << std::endl;
    }
};

void addStudent(std::vector<student>& students, const std::string& name, int age, float grade) {
    student stu = {name, age, grade};
    students.push_back(stu);
    std::cout << "添加成功" << std::endl;
}

void displayStudents(const std::vector<student>& students) {
    if (students.empty()) {
        std::cout << "没有学生信息" << std::endl;
        return;
    }
    std::cout << "所有学生信息" << std::endl;
    for (const auto& student : students) {
        student.printInfo();
    }
}

void findStudentByName(std::vector<student>& students, std::string name) {
    for (const auto& student : students) {
        if (student.name == name) {
            std::cout << "找到学生信息" << std::endl;
            student.printInfo();
            return;
        }
    }

    std::cout << "未找到 name 为" << name << " 的学生" << std::endl;
}
int main()
{
    std::vector<student> students;
    int choice;

    do {
        std::cout << "学生管理系统" << std::endl;
        std::cout << "1. add" << std::endl;
        std::cout << "2. dis" << std::endl;
        std::cout << "3. fin" << std::endl;
        std::cout << "4. quit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            std::string addname;
            int age;
            float grade;
            std::cout << "enter name: ";
            std::cin >> addname;
            std::cout << "age: ";
            std::cin >> age;
            std::cout << "grade: ";
            std::cin >> grade;

            addStudent(students, addname, age, grade);
            break;
        }
        case 2:
            displayStudents(students);
            break;
        case 3:
        {
            std::cout << "enter name: " << std::endl;
            std::string name;
            std::cin >> name;
            findStudentByName(students, name);
            break;
        }
        case 4:
            std::cout << "退出系统" << std::endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
