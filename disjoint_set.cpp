

#include<bits/stdc++.h>
using namespace std;

int find(int i)

{

	if (parent[i] == i) {

		return i;
	}
	else {

		return find(parent[i]);
	}
}
