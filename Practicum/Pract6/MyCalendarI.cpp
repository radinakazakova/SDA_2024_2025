//Може и без отделна функция за inersection

class MyCalendar {
    vector<pair<int,int>> events;

    bool intersect(int firstStart, int firstEnd, int secStart, int secEnd)
    {
        return (firstStart < secEnd && secStart < firstEnd);
    }
public:
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {

        int size = events.size();
        for(int i = 0; i < size; i++)
        {
            if(intersect(events[i].first, events[i].second, startTime, endTime))
                return false;
        }

        events.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
