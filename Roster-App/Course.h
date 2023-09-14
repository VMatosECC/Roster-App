#pragma once
#include <iostream>
#include <string>
#include <sstream>;
using namespace std;

class Course
{
private:
    
    //Data Members
    string  cname;
    string* roster;
    int     scounter;

public:
    const int MAX = 4;

    //Mutators ----------------------------------------------
    void setCname(string cNameValue) {
        cname = cNameValue;
    }

    void setRoster(string* rosterValue) {
        roster = rosterValue;
    }

    void setScounter(int sCounterValue) {
        scounter = sCounterValue;
    }

    //Accessors ---------------------------------------------
    string  getCname()    { return cname; }
    string* getRoster()   { return roster; }
    int     getScounter() { return scounter; }

    //Constructors --------------------------------------------------------------
    Course(string cNameValue, int sCounterValue, string* rosterValue) {
        setCname(cNameValue);
        setScounter(sCounterValue);
        setRoster(rosterValue);
    }

    Course() {
        setCname("CS_NONE");
        setScounter(0);
        setRoster(nullptr);
    }

    //copy-constructor
    Course(const Course& other) {

        *this = other;


        //setCname(other.cname);
        //setScounter(other.scounter);

        //this->roster = new string[MAX];
        //for (int i = 0; i < other.scounter; i++) {
        //    this->roster[i] = other.roster[i];
        //}

    }

    //Destructor
    ~Course() {
        cout << "\nDELETING ...\n";
        cout << this->toSring() << endl;

        delete[] roster;
    }




    void operator= (const Course& other) {
        setCname(other.cname);
        setScounter(other.scounter);

        this->roster = new string[MAX];
        for (int i = 0; i < other.scounter; i++) {
            this->roster[i] = other.roster[i];
        }
    }


    //User-Defined Methods -----------------------------------------------------
    string toSring() {
        stringstream sout;

        sout << this << " Course [Name: " << getCname()
            << ", Student Count: " << getScounter()
            << ", Roster-address: " << roster
            << ", ID: { ";
        for (int i = 0; i < getScounter(); i++)
        {
            //sout << *(roster + i) << ", ";
            sout << roster[i] << ", ";
        }
        sout << " } ]";
        return sout.str();
    }

    bool addStudent(string sId) {
        if (getScounter() >= MAX)  return false;
        roster[scounter++] = sId;
        return true;
    }

    bool removeStudent(string sId) {
        int pos = -1;
        //find student
        for (int i = 0; i < getScounter(); i++) {
            if (roster[i] == sId) { pos = i; break; }
        }

        if (pos == -1) return false;

        //shift-left ids 
        for (int i = pos; i < getScounter() - 1; i++) {
            roster[i] = roster[i + 1];
        }
        setScounter(getScounter() - 1);
        return true;
    }
};

