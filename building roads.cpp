// link : https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>

using namespace std;

vector<int> s;
vector<int> p;

int findSet(int i){
	if(p[i] == i)	return i;
	else	return p[i] = findSet(p[i]);
}

void makeSet(int a){
	p[a] = a;
	s[a] = 1;
}

void createUnion(int a, int b){
	a = findSet(a);
	b = findSet(b);

	if(a != b){
		if(s[b] > s[a]){
			swap(a, b);
		}
		p[b] = a;
		s[a] += s[b];
	}
}

int main(){
	int n, m;
	cin >>n>>m;
	int from, to;
	for(int i = 0;i<n + 1;i++){
		p.push_back(-1);
		s.push_back(0);
	}
	for(int i = 1;i<=n;i++){
		makeSet(i);
	}
	for(int i = 0;i<m;i++){
		cin >>from>>to;
		createUnion(from ,to);
	}
	for(int i = 1;i<p.size();i++){
		p[i] = findSet(p[i]);
	}
	set<int> a(p.begin(), p.end());
	int result = a.size() - 2 ;
	cout <<result<<endl;
	if(result > 0){
		vector<int> printer(a.begin(), a.end());
		printer.erase(printer.begin());
		for(int i = 0;i<printer.size() - 1;i++){
			cout <<printer[i]<<' '<<printer[i + 1]<<endl;
		}
	}
	return 0;
}

