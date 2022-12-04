#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
    string line;
    string secondcomp;
    ifstream input ("input.txt");
    vector<string> backpacks;
    int sum = 0;
    int sum2 = 0;
    char target = 'A';
    if (input.is_open()) {
        while (getline(input, line))
        {
            backpacks.push_back(line);
        }
        input.close();
    }
    else {
        cout << "Error, Input not found.\n";
        system("PAUSE");
        return 0;
    }
    for (int i = 0; i < backpacks.size(); i++) {
        //part1
        line = backpacks[i].substr(0, backpacks[i].length()/2);
        secondcomp = backpacks[i].substr(backpacks[i].length()/2, backpacks[i].length());
        for (int j = 0; j < line.length(); j++) {
            if (secondcomp.find(line.at(j)) < 100) {
                if (!isupper(line.at(j))) {
                    sum += stoi(string(1, line.at(j)), 0, 36) - 9;
                    break;
                }
                sum += stoi(string(1, line.at(j)), 0, 36) + 17;
                break;
            }
        }
        //part2
        if (i % 3 == 0) {
            for (int k = 0; k < backpacks[i + 1].length(); k++) {
                if (backpacks[i].find(backpacks[i + 1].at(k)) < 100) {
                    target = backpacks[i + 1].at(k);
                    if (backpacks[i + 2].find(target) < 100) {
                        if (!isupper(target)) {
                            sum2 += stoi(string(1, target), 0, 36) - 9;
                            break;
                        }
                        sum2 += stoi(string(1, target), 0, 36) + 17;
                        break;
                    }
                }
            }
        }
    }
    cout << "Result 1: " << sum;
    cout << "\nResult 2: " << sum2 << '\n';

    system("PAUSE");
    return 0;

}
