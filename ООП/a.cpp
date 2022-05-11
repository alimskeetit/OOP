#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	int course;
	int group;
	Student(int course, int group) {};
};

Student::Student(int course, int group): course(course),  group(group) {};
int main() {
	Student student(1, 1);
}