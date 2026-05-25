/*Leetcode ps- 1871. Jump Game VII
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.*/

/*
    APPROACH: Breadth-First Search (BFS) with a Sliding Window Optimization
    problem:
    If we just check every possible jump from every index, our jump ranges will overlap 
    heavily. For example, jumping from index 2 might check indices 5 to 10, and jumping 
    from index 3 might check 6 to 11. Checking 6 to 10 twice wastes time and causes a 
    Time Limit Exceeded (TLE) error.

    The Solution: "maxreached"
    We use a queue to keep track of where we are (BFS), and a variable called 'maxreached' 
    to remember the absolute furthest index we have ever checked. This guarantees we 
    never look at the same index twice!
    
    1. Early Exit: 
       If the last character in the string is '1', we can never land on it. Return false immediately.

    2. Initialization:
       - Create a queue 'q' to hold the indices we successfully land on. Push the starting point (0).
       - Create 'maxreached' and set it to 0. This tracks the furthest index we've explored.

    3. The BFS Loop (While the queue has indices to process):
       - Pop the current index ('cur') from the front of the queue.
       - If 'cur' is the last index, we made it! Return true.

    4. Calculating the Jump Window:
       - 'start': Where should we start checking for the next jump? 
         Normally, it's 'cur + minJump'. BUT, if we've already checked past that point in a 
         previous loop, we start at 'maxreached + 1'. This is the magic step that prevents TLE!
       - 'end': What is the absolute furthest we can jump?
         It's 'cur + maxJump', but we cap it at the end of the string (n-1) so we don't go out of bounds.

    5. Exploring the Window:
       - Loop from 'start' to 'end'.
       - If we find a '0', it's a valid landing spot! Add that index to the queue.
       - Inside this loop, if we ever add the final index to the queue, return true immediately (fast exit).

    6. Update Progress:
       - After the loop, update 'maxreached' to be the 'end' of the window we just checked.
       
    7. Failure:
       - If the queue runs empty and we never reached the end, return false.
*/


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] != '0') return false;

        //using bfs
        queue<int> q;
        q.push(0);//starts at q so push q
        int maxreached=0;//tracks the biggest index visited
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if(cur == n-1) return true;//reached enda
            int start = max(cur+minJump , maxreached+1);
            int end = min(cur+maxJump,n-1);
            for(int i= start;i<=end;i++){
               if(s[i]=='0') {
                q.push(i);
                if( i== n-1) return true;
               }
            }
            maxreached=max(maxreached,end);
        }
        return false;
    }
};
