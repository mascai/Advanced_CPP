#include<bits/stdc++.h>

#define EPS 300


using namespace std;

/*
* Implement structure
* Input: Ordered vector of time_stamps
* Output: Number of events for the last 5 minutes
*/
class EventManager {
public:
    // add event to queue
    void Add(const int time) {
        Adjust(time);
        data_.push(time);
    }
    // count number
    int Count(const int time) {
        Adjust(time);
        return data_.size();
    }
private:
    void Adjust(const int time) {
        while ((not data_.empty()) and data_.front() <= time - EPS) {
            data_.pop();
        }
    }
private:
    queue<int> data_;
};


int main() {
   // pass
}
