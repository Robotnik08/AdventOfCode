#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


bool evaluate (string s) {
    string firstperson = s.substr(0, s.find(","));
    string secondperson = s.substr(s.find(",") + 1, s.length());

    int firststart = stoi(firstperson.substr(0, firstperson.find("-")));
    int firstend = stoi(firstperson.substr(firstperson.find("-") + 1, firstperson.length()));
    int secondstart = stoi(secondperson.substr(0, secondperson.find("-")));
    int secondend = stoi(secondperson.substr(secondperson.find("-") + 1, secondperson.length()));
    return (firststart >= secondstart && firstend <= secondend) || (secondstart >= firststart && secondend <= firstend);
}
bool evaluate2 (string s) {
    string firstperson = s.substr(0, s.find(","));
    string secondperson = s.substr(s.find(",") + 1, s.length());

    int firststart = stoi(firstperson.substr(0, firstperson.find("-")));
    int firstend = stoi(firstperson.substr(firstperson.find("-") + 1, firstperson.length()));
    int secondstart = stoi(secondperson.substr(0, secondperson.find("-")));
    int secondend = stoi(secondperson.substr(secondperson.find("-") + 1, secondperson.length()));

    return (firststart >= secondstart && firststart <= secondend) || (firstend <= secondend && firstend >= secondstart) || (secondstart >= firststart && secondstart <= firstend) || (secondend <= firstend && secondend >= firststart);
}

int main () {
    string line;
    ifstream input ("input.txt");
    vector<string> assignments;
    int sum1 = 0;
    int sum2 = 0;
    if (input.is_open()) {
        while (getline(input, line))
        {
            assignments.push_back(line);
        }
        input.close();
    }
    else {
        cout << "Error, Input not found.\n";
        return 0;
    }

    //part1
    for (int i = 0; i < assignments.size(); i++) {
        if (evaluate(assignments[i])) {
            sum1++;
        }
        if (evaluate2(assignments[i])) {
            sum2++;
        }
    }
    cout << "Result 1: " << sum1 << '\n';
    cout << "Result 2: " << sum2 << '\n';
    return 0;
}