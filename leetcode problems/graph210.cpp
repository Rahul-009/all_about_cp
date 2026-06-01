// Leetcode 
// Problem => Course Schedule II
// Link => https://leetcode.com/problems/$problem_name$/description/


// solution 1 | DFS + stack |
class Solution {
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state, stack<int> &st){
        state[node] = 1; // visiting | for cycle detection

        for(int nei: adj[node]){
            if(state[nei] == 1){
                return false;
            }

            if(state[nei] == 0){
                if(!dfs(nei, adj, state, st))
                    return false;
            }
        }

        state[node] = 2; // visited

        st.push(node);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto &p: prerequisites ){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);
        stack<int> st;

        for(int i=0; i<numCourses; i++){
            if(state[i] == 0){
                if(!dfs(i, adj, state, st)){
                    return {};
                }
            }
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};


// Solution 2 | kahn's algorithm | O(V+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // making graph | calc indegree
        for(auto &p: prerequisites){
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // init q with indegree 0 nodes
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> order;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            order.push_back(node);

            for(int nei: graph[node]){
                indegree[nei]--;

                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        // cycle detected
        if(order.size() != numCourses){
            return {};
        }

        return order;
    }
};


// solution 3 | DFS + vector 
class Solution {
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &state, vector<int> &order){
        state[node] = 1; // visiting | for cycle detection

        for(int nei: adj[node]){
            if(state[nei] == 1){
                return false;
            }

            if(state[nei] == 0){
                if(!dfs(nei, adj, state, order))
                    return false;
            }
        }

        state[node] = 2; // visited

        order.push_back(node);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto &p: prerequisites ){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> order;

        for(int i=0; i<numCourses; i++){
            if(state[i] == 0){
                if(!dfs(i, adj, state, order)){
                    return {};
                }
            }
        }

        reverse(order.begin(), order.end());

        return order;
    }
};
