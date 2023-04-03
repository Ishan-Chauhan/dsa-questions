class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int c=0;
        sort(people.begin(),people.end());
        int a=0,b=people.size()-1;
        while(people[b]==limit)
        {
            b--;
            c++;
        }
        while(a<=b)
        {
            if(people[a]+people[b]<=limit)
            {
                c++;
                a++;
                b--;
            }
            else
            {
                c++;
                b--;
            }
        }
        return c;
    }
};