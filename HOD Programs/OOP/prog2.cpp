#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int roll;
    float marks;
    static string UniName;
    static int count;

public:
    Student(string n, int r, float m)
    {
        name = n;
        roll = r;
        marks = m;
        count++;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << marks << endl;
        cout << "University: " << UniName << endl;
        cout << "Count: " << count << endl;
    }

    static void setUniName(string n)
    {
        UniName = n;
    }
    static int getCount()
    {
        return count;
    }
};

string Student::UniName;
int Student::count = 0;

int main()
{
    Student::setUniName("ACUK");
    Student s1("Ali", 1, 90);
    s1.display();
    cout << endl;
    Student s2("Ahmed", 2, 85);
    s2.display();
    cout << endl;
    Student s3("Asad", 3, 80);
    s3.display();
    return 0;
}