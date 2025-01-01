#include <iostream>
#include <string.h>
using namespace std;

class Name
{
    char *fname;
    char *lname;
    char mname;

public:
    Name(const char *f, const char m, const char *l) : mname(m)
    {
        fname = new char[strlen(f) + 1];
        strcpy(fname, f);
        lname = new char[strlen(f) + 1];
        strcpy(lname, l);
    }

    Name(const Name &obj)
    {
        fname = new char[strlen(obj.fname) + 1];
        strcpy(fname, obj.fname);
        lname = new char[strlen(obj.lname) + 1];
        strcpy(lname, obj.lname);
        mname = obj.mname;
    }

    void operator=(const Name &n)
    {
        delete fname;
        delete lname;
        fname = new char[strlen(n.fname) + 1];
        strcpy(fname, n.fname);
        lname = new char[strlen(n.lname) + 1];
        strcpy(lname, n.lname);
        mname = n.mname;
    }
    ~Name()
    {
        delete fname;
        delete lname;
        cout << "Destructor called of Name" << endl;
    }

    void display()
    {
        cout << fname << " " << mname << " " << lname << endl;
    }
};

class FullName
{
    Name name;
    char *tittle;

public:
    FullName(const char *t, const char *f, const char m, const char *l) : name(f, m, l)
    {
        tittle = new char[strlen(t) + 1];
        strcpy(tittle, t);
    }
    FullName(const FullName &f) : name(f.name)
    {
        tittle = new char[strlen(f.tittle) + 1];
        strcpy(tittle, f.tittle);
    }

    void operator=(const FullName &f)
    {
        delete tittle;
        name = f.name;
        tittle = new char[strlen(f.tittle) + 1];
        strcpy(tittle, f.tittle);
    }

    void display()
    {
        cout << tittle << " ";
        name.display();
    }

    ~FullName()
    {
        delete tittle;
        cout << "Destrotor" << endl;
    }
};

int main()
{
    FullName obj("Mr", "Hamza", 'A', "mehmood");
    obj.display();
    cout << endl;
    FullName obj2{obj};
    obj2.display();
    return 0;
}