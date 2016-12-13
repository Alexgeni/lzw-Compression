//============================================================================
// Name        : lzw.cpp
// Author      : Mohamed.shaaban
// Version     : 1.0
// Copyright   : This file has copy rights according to github licences
// Description : LZW compression in C++, Ansi-style
//============================================================================
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
	map<string,int> m;
	vector<int> v;
	string s = "ababbaabbaabba";
	int value=0;
	int size = s.size();
	for(int i=0;i<size;i++){
		string f(1,s[i]);
		if(m.find(f)==m.end()){
			m[f]=value++;
		}
	}
	for (int i = 0; i <size; i) {
		string t(1,s[i]);
		string old;
		while(true){
			if(m.find(t)==m.end()){
				v.push_back(m[old]);
				m[t]=value;
				cout<<value<<' '<<t<<endl;
				value++;
				break;
			}
			old=t;
			i++;
			if(i<size)
			t+=s[i];
			else{
				v.push_back(m[old]);
				break;
			}
		}

	}
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<endl;
	}

	return 0;
}
