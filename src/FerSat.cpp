#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    int n = stoi(argv[1]);
    vector <string> cnf;
    for (int i = 1; i <= n; i++) { // Every row has only one queen
        for (int j = 1; j <= n; j++) { // Every row has not more than one queen
            for (int k = j + 1; k <= n; k++)
                cnf.push_back("-" + to_string((i - 1) * n + j) + " -" + to_string((i - 1) * n + k) + " 0\n");
        }
        string temp;
        for (int j = 1; j <= n; j++) // Every row has at least one queen
            temp += to_string((i - 1) * n + j) + " ";
        cnf.push_back(temp + "0\n");
    }
    for (int i = 1; i <= n; i++) { // Every column has only one queen
        for (int j = 1; j <= n; j++) { // Every column has not more than one queen
            for (int k = j + 1; k <= n; k++)
                cnf.push_back("-" + to_string((j - 1) * n + i) + " -" + to_string((k - 1) * n + i) + " 0\n");
        }
        string temp;
        for (int j = 1; j <= n; j++) // Every column has at least one queen
            temp += to_string((j - 1) * n + i) + " ";
        cnf.push_back(temp + "0\n");
    }
    for (int i = 2; i < 2 * n - 1; i++) { // Every down-left to up-right diagonal has not more than one queen
        for (int j = max(1, i - n + 1); j <= min(n, i); j++) {
            for (int k = j + 1; k <= min(n, i); k++) {
                cnf.push_back("-" + to_string((i - j) * n + j) + " -" + to_string((i - k) * n + k) + " 0\n");
            }
        }
    }
    for (int i = 2; i < 2 * n - 1; i++) { // Every up-left to down-right diagonal has not more than one queen
        for (int j = max(1, n - i + 1); j <= min(n, 2 * n - i); j++) {
            for (int k = j + 1; k <= min(n, 2 * n - i); k++) {
                cnf.push_back("-" + to_string((j - 1) * n + j - (n - i)) + " -" + to_string((k - 1) * n + k - (n - i)) + " 0\n");
            }
        }
    }

    ofstream out("fer_to_sat.txt");

    out << "p cnf " << n * n << " " << cnf.size() << '\n';
    for (const auto& el : cnf)
        out << el;
    out.flush();

    system("minisat -verb=0 fer_to_sat.txt result.txt");

    ifstream in("result.txt");

    string res;
    in >> res;
    if (res == "UNSAT") {
        cout << "Can't place " << n << " queens\n";
        return 0;
    }
    vector <vector <int>> ans(n, vector <int>(n));
    for (int i = 0; i < n * n; i++) {
        int cell;
        in >> cell;
        if (--cell < 0)
            continue;
        ans[cell / n][cell % n] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (auto cell : ans[i])
            cout << cell;
        cout << '\n';

    }

    system("rm fer_to_sat.txt");
    system("rm result.txt");

    return 0;
}
