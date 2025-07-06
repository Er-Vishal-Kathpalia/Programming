#include <bits/stdc++.h>
using namespace std;


/*
A number of cities are arranged on a graph that has been divided up like an ordinary Cartesian plane. Each city is located at an integral (x, y) coordinate intersection. City names and locations are given in the form of three arrays: c, x, and y, which are aligned by the index to provide the city name (c[i]), and its coordinates, (x[i], y[i]) Determine the name of the nearest city that shares either an x or a y coordinate with the queried city. If no other cities share an x or y coordinate, return 'NONE' If two cities have the same distance to the queried city, q[i], consider the one with an alphabetically shorter name (i.e. ` a * b' < ab * a' <^ prime abb) as the closest choice. The distance is the Manhattan distance, the absolute difference in x plus the absolute difference in y.

n=3;
c = ['c1','c2','c3']
x = [3,2,1]
y = [3,2,3]
q = ['c1','c2','c3']
*/

string findNearestCity(const vector<string>& c, const vector<int>& x, const vector<int>& y, const string& queryCity, const unordered_map<string, int>& cityIndex, const unordered_map<int, vector<int> >& x_map, const unordered_map<int, vector<int> >& y_map) {
    int idx = cityIndex.at(queryCity);
    int qx = x[idx], qy = y[idx];
   
    string nearestCity = "NONE";
    int minDistance = INT_MAX;
    
    if (x_map.count(qx)) {
        for (int i : x_map.at(qx)) {
            if (i != idx) {
                int distance = abs(qy - y[i]);
                if (distance < minDistance || (distance == minDistance && c[i] < nearestCity)) {
                    nearestCity = c[i];
                    minDistance = distance;
                }
            }
        }
    }
    
    if (y_map.count(qy)) {
        for (int i : y_map.at(qy)) {
            if (i != idx) {
                int distance = abs(qx - x[i]);
                if (distance < minDistance || (distance == minDistance && c[i] < nearestCity)) {
                    nearestCity = c[i];
                    minDistance = distance;
                }
            }
        }
    }
    
    return nearestCity;
}

vector<string> nearestCities(const vector<string>& c, const vector<int>& x, const vector<int>& y, const vector<string>& q) {
    
    int n = c.size();
    unordered_map<int, vector<int> > x_map, y_map;
    unordered_map<string, int> cityIndex;
    
    for (int i = 0; i < n; ++i) {
        x_map[x[i]].push_back(i);
        y_map[y[i]].push_back(i);
        cityIndex[c[i]] = i;
    }
    
    vector<string> result;
    for (const string& queryCity : q) {
        result.push_back(findNearestCity(c, x, y, queryCity, cityIndex, x_map, y_map));
    }
    
    return result;
}

int main(){


	int n;
	cin>>n;

	vector<string> c;
	vector<int> x;
	vector<int> y;
	vector<string> q;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		c.push_back(temp);
	}

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		x.push_back(temp);
	}

	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		y.push_back(temp);
	}

	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		q.push_back(temp);
	}

	vector<string> ans = nearestCities(c,x,y,q);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}