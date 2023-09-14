// Roster-App.cpp 

#include "Course.h"

int main()
{
    Course c1("CSCI2", 3, new string[4]{ "123", "456", "789" });

    //cout << "c1 " << c1.toSring() << endl;

    //===================================
    
    Course c2 = c1;
    
    // Course c2(c1);

    //===================================


    //cout << "c2 " << c2.toSring() << endl;

    //cout << "After changing course name\n";
    //c1.setCname("CSCI101");
    //c1.removeStudent("123");

    cout << "c1 " << c1.toSring() << endl;
    cout << "c2 " << c2.toSring() << endl;

    //if (c1.addStudent("777"))
    //    cout << "c1 " << c1.toSring() << endl;
    //else
    //    cout << "Course c1 is full" << endl;

    //c2.setScounter(4);
    //cout << "c2 " << c2.toSring() << endl;





    std::cout << "All done!\n";
}

