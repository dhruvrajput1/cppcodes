#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

};

class Compare {
public:

    bool operator() (Point p1, Point p2) {
        if(p1.x == p2.x) {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    }

};

int countRectangles(vector<Point> coords) {

    int n = coords.size();

    // insert all points in set
    set<Point, Compare> s; // we use comparator because set is a tree like data structure, we have to instruct it whether data will go to LST or RST

    for(auto p : coords) {
        s.insert(p);
    }

    // run 2 loops
    int ans = 0;

    for(auto it = s.begin(); it != prev(s.end()); it++) {
        for(auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;

            if(p2.x == p1.x or p2.y == p1.y) { // because we want diagonally opposite points as p1 and p2
                continue;
            }

            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);

            if(s.find(p3) != s.end() and s.find(p4) != s.end()) { // means we've founded p3 and p4 in our set
                ans++;
            }
        }
    }

    return ans/2;

}

int main() {

    int m; cin>>m;

    vector<Point> coords;

    while(m--) {
        int x, y;
        cin>>x>>y;


        Point p(x, y);
        coords.push_back(p);

    }

    cout<<countRectangles(coords)<<endl;


    return 0;
}