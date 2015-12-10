#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
	int calcs = 0;

	ifstream file("hey.txt");

	string l;
	while (getline(file, l)) {
		string n;
		int cal = 1;
		vector<int> lwh;
		for (auto i = l.begin(); i != l.end(); ++i) {
			auto &x = *i;
			if (isdigit(x)){
				n += x;
				if (i == l.end()-1){
					lwh.push_back(stoi(n));
					}
				}
			else {
				//cout << n << endl;
				lwh.push_back(stoi(n));
				n = "";
				}
			}

		//print_vec(lwh, lwh.begin());
		cout << endl;

		if (lwh.size() > 1) {
			int lw = lwh[0] * lwh[1];
			int wh = lwh[1] * lwh[2];
			int lh = lwh[2] * lwh[0];
			vector<int> lwwhlh = { lw, wh, lh };

			calcs += (2 * lw + 2 * wh + 2 * lh);

			int s = INT_MAX;
			for (int &x : lwwhlh) {
				if (x < s) {
					s = x;
					}
				}
			calcs += s;

		}
		}
	cout << calcs << endl;
	file.close();
}