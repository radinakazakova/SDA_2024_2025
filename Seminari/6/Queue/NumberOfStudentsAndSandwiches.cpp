class Solution {
public:
    queue<int> sandwichesQ;
    queue<int> studentsQ;
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        for(auto s: students) {
            studentsQ.push(s);
        }
        for(auto s: sandwiches) {
            sandwichesQ.push(s);
        }
        
        while(true){
            size_t preIterSize = studentsQ.size();

            for(int i = 0; i < preIterSize; i++){ //въртим за подредбата на първото queue студенти
                if(sandwichesQ.front() == studentsQ.front() )
                {
                    studentsQ.pop();
                    sandwichesQ.pop();
                }
                else
                {
                    int student = studentsQ.front();
                    studentsQ.pop();
                    studentsQ.push(student);
                }
            }
            
            if(studentsQ.size() == preIterSize) //ако броят на студентите не се е променил (никой не е взел сандвич), значи край
            {
                return preIterSize;
            }
        }
        return 0; //всички са взели
    }
};
