#include <iostream>
#include <straing>
#include <vector>

using namespace std;

int main() {

    string s = "(()(";

    bool answer = false;
    vector<char> comp;

    cout << s.size() << endl;

    for (int i = 0; i < s.size(); i++)
    {
        if (comp.empty())
        {
            comp.push_back(s[i]);

        }
        else if ((comp.back() == '(') && s[i] == ')')
        {
            comp.pop_back();
        }
        else {
            comp.push_back(s[i]);
        }

    }

    if (comp.empty()) {
        answer = true;
    }


    cout << answer << endl;



}