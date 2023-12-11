#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> counter;
int n, t;
int a[100001], x[100001];


int main(){
	
	cin >> n >> t;

	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++)
		counter[a[i]]++;

	for (int i=0; i<t; i++)
		cin >> x[i];

	for (int i=0; i<t; i++)
		if (counter.count(x[i])){
			cout << counter[x[i]]<<endl;
		}
		else {
			cout <<"0"<<endl;
		}



	return 0;
}