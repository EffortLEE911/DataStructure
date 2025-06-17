#include <iostream>
#include <vector>

using namespace std;

class Student {
public:

    string name;
    int age;

    Student(string spaceX, int tesla)
    {
        this->name = spaceX;
        this->age = tesla;
    }
};

int main() 
{
    vector<Student> vec;

    Student kim("±è¿µÈñ", 20);

    Student hong("È«±æµ¿",25);

    Student  kang("°­È£µ¿", 30);

    vec.push_back(kim);
    vec.push_back(hong);
    vec.push_back(kang);

    cout << vec[0].name << endl;
    cout << vec[1].name << endl;
    cout << vec[2].name << endl;


  


}

