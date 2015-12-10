#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main(int argc, char *argv[]) {
	int calcs = 0;
	int calcs2 = 0;

	ifstream file("inputday2.txt");

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

		if (lwh.size() > 1) {
			int lw = lwh[0] * lwh[1];
			int wh = lwh[1] * lwh[2];
			int lh = lwh[2] * lwh[0];

			calcs += (2 * lw + 2 * wh + 2 * lh);

			vector<int> lwwhlh = { lw, wh, lh };
			int s = lw;
			for (int &x : lwwhlh) {
				if (x < s) {
					s = x;
					}
				}
			calcs += s;

			int side1 = lwh[0] * 2 + lwh[1] * 2;
			int side2 = lwh[1] * 2 + lwh[2] * 2;
			int side3 = lwh[2] * 2 + lwh[0] * 2;
			int small_side = side1;

			vector<int> sides = { side1, side2, side3 };
			for (int &s : sides){
				if (s < small_side){
					small_side = s;
					}
				}

			calcs2 += (small_side+(lwh[0]*lwh[1]*lwh[2]));

		}
		}
	cout << "Star 1: " << calcs << endl;
	cout << "Star 2: " << calcs2 << endl;
	file.close();
}