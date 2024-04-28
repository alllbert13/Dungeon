#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

class Player;

using namespace std;

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string,string);
    // Object(const Object& other);
    /* pure virtual function */
    virtual void presentItem() = 0;
    virtual void takeItem(Player*) = 0;

    /* Set & Get function*/
    void setName(string);
    void setTag(string);
    string getName();
    string getTag();
};

#endif // OBJECT_H_INCLUDED
