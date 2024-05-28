#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

    int start = 3;
    int end = 42;

    vector<int> arr {2, 5, 7};

    int mod = 100000;

    queue<pair<int, int>> q; // steps, node
    
    q.push({0, start});

    vector<int> dist (9999, 1e9);

    dist[start] = 0;

    while(!q.empty()) {
        int node = q.front().second;
        int steps = q.front().first;
        q.pop();

        for(auto it : arr) {
            int num = (it*node)%mod;
            if(steps + 1 < dist[num]) {
                dist[num] = steps + 1;
                if(num == end) {
                    cout<<steps + 1<<endl;
                    return 0;
                }
                q.push({steps + 1, num});
            }
        }
    }

    cout<<-1<<endl;

    return 0;
}