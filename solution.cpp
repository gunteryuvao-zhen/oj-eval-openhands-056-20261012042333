#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int l, r;
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<Interval> activities;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            
            int deleted_count = 0;
            vector<Interval> to_delete;
            
            // Find all intervals that overlap with [l, r]
            // Two intervals [a,b] and [c,d] overlap if: a <= d && c <= b
            for (auto it = activities.begin(); it != activities.end(); ++it) {
                if (it->l <= r && l <= it->r) {
                    to_delete.push_back(*it);
                }
            }
            
            // Delete all overlapping intervals
            for (const auto& interval : to_delete) {
                activities.erase(interval);
                deleted_count++;
            }
            
            // Add the new interval
            activities.insert({l, r});
            
            cout << deleted_count << "\n";
        } else if (op == 'B') {
            cout << activities.size() << "\n";
        }
    }
    
    return 0;
}