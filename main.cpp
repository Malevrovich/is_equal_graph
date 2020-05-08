#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool Check(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs, const vector<int>& mask){
	for(size_t i = 0; i != lhs.size(); i++){
		for(size_t k = 0; k != lhs.size(); k++){
			if(lhs[i][k] != rhs[mask[i]][mask[k]]){
				return false;
			}
		}
	}
	return true;
}

bool nextStep(vector<int>& mask){
	int i;
	for(i = mask.size()-2; i != -1; i--){
		if(mask[i] < mask[i+1]){
			break;
		}
	}
	if(i == -1){
		return false;
	}

	int k;
	for(k = mask.size()-1; k != -1; k--){
		if(mask[k] > mask[i]){
			break;
		}
	}
	iter_swap(mask.begin() + i, mask.begin() + k);
	reverse(mask.begin() + i + 1, mask.end());
	return true;
}

bool isEqual(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs){
	if(lhs.size() != rhs.size()){
		return false;
	}

	vector<int> mask(lhs.size());
	for(int i = 0; i != mask.size(); i++){
		mask[i] = i;
	}

	while(nextStep(mask)){
		if(Check(lhs, rhs, mask)){
			return true;
		}
	}

	return false;
}

void Read(vector<vector<int>>& g, iostream& s){
	int size;
	s >> size;
	g.resize(size);
	for(auto& i: g){
		i.resize(size);
	}

	for(int i = 0; i != size; i++){
		for(int k = 0; k != size; k++){
			s >> g[i][k];
		}
	}
}

int main(){
	fstream first("first.txt");
	fstream second("second.txt");

	vector<vector<int>> lhs;
	vector<vector<int>> rhs;


	Read(lhs, first);
	Read(rhs, second);

	cout << boolalpha;
	cout << "Is equal?" << endl;
	cout << isEqual(lhs, rhs) << endl;

	return 0;
}
