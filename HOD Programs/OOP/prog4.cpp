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

    Name &operator=(const Name &n)
    {
        delete fname;
        delete lname;
        fname = new char[strlen(n.fname) + 1];
        strcpy(fname, n.fname);
        lname = new char[strlen(n.lname) + 1];
        strcpy(lname, n.lname);
        mname = n.mname;

        return *this;
    }
    ~Name()
    {
        delete fname;
        delete lname;
        cout << "Destructor called of Name" << endl;
    }

    void display() const
    {
        cout << fname << " " << mname << " " << lname << endl;
    }
};

class FullName : public Name
{

    char *tittle;

public:
    FullName(const char *t, const char *f, const char m, const char *l) : Name(f, m, l)
    {
        tittle = new char[strlen(t) + 1];
        strcpy(tittle, t);
    }
    FullName(const FullName &f) : Name(f)
    {
        tittle = new char[strlen(f.tittle) + 1];
        strcpy(tittle, f.tittle);
    }

    FullName &operator=(const FullName &f)
    {
        if (&f == this)
        {
            return *this;
        }
        delete tittle;
        Name::operator=(f);
        tittle = new char[strlen(f.tittle) + 1];
        strcpy(tittle, f.tittle);

        return *this;
    }

    void display() const override
    {
        cout << tittle << " ";
        Name::display();
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
    FullName obj2{obj};
    obj2.display();
    return 0;
}