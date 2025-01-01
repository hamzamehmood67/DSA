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
    char *title;

public:
    FullName(char *f, char *l, char m, char *t) : Name(f, l, m)
    {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    FullName(const FullName &f) : Name(f.fname, f.lname, f.mname)
    {
        title = new char[strlen(f.title) + 1];
        strcpy(title, f.title);
    }

    void operator=(const FullName &f)
    {
        delete fname;
        delete lname;
        delete title;
        fname = new char[strlen(f.fname) + 1];
        strcpy(fname, f.fname);
        lname = new char[strlen(f.lname) + 1];
        strcpy(lname, f.lname);
        mname = f.mname;
        title = new char[strlen(f.title) + 1];
        strcpy(title, f.title);
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
    FullName f2 = f1;
    f2.display();
    return 0;
}