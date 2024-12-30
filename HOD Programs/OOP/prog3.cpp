#include <iostream>
#include <string.h>
using namespace std;

class Name
{
protected:
    char *fname;
    char *lname;
    char mname;

public:
    Name(char *f, char *l, char m)
    {
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
        lname = new char[strlen(l) + 1];
        strcpy(lname, l);
        mname = m;
    }

    void display()
    {
        cout << fname << " " << mname << " " << lname << endl;
    }

    ~Name()
    {
        delete fname;
        delete lname;
        cout << "Destructor called of Name" << endl;
    }
};

class FullName : public Name
{
    char *title; // Mr., Mrs., Dr., etc

public:
    FullName(char *f, char *l, char m, char *t) : Name(f, l, m)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    void display()
    {
        cout << title << " ";
        Name::display();
    }

    void setFname(char *f)
    {
        delete fname;
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
    }
    void setTitle(char *t)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    ~FullName()
    {
        delete title;
        cout << "Destructor called of Full Name" << endl;
    }
};

int main()
{
    FullName f1("John", "Doe", 'M', "Mr.");
    f1.display();
    f1.setTitle("Dr.");
    f1.setFname("Hamza");
    f1.display();
    return 0;
}