/*
    You are given a data structure of employee information, which includes the employee's unique id, 
    his importance value and his direct subordinates' id.

    For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3.
    They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], 
    and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also 
    a subordinate of employee 1, the relationship is not direct.

    Now given the employee information of a company, and an employee id, you need to return the total importance 
    value of this employee and all his subordinates.

    Example 1:
    Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
    Output: 11

    Explanation:
    Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
    Note:
    One employee has at most one direct leader and may have several subordinates.
    The maximum number of employees won't exceed 2000.
*/
#include <LeetCodeUtil.h>
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
    Employee(int id, int importance, vector<int> subordinates) {
        this->id = id;
        this->importance = importance;
        this->subordinates = subordinates;
    }
};
// BFS
// class Solution {
// public:
//     int getImportance(vector<Employee*> employees, int id) {
//         unordered_map<int, Employee*> es; // 员工id -> 员工
//         for (auto e : employees) {
//             es.emplace(e->id, e);
//         }
//         int importance = 0;
//         queue<int> ids;
//         ids.push(id);
//         while (!ids.empty()) {
//             int i = ids.front();
//             ids.pop();
//             Employee *e = es[i];
//             importance += e->importance;
//             for (const auto& susubordinate : e->subordinates) {
//                 ids.push(susubordinate);
//             }
//         }
//         return importance;
//     }
// };
// DFS
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> es; // 员工id -> 员工
        for (auto e : employees) {
            es.emplace(e->id, e);
        }
        return DFS(id, es);
    }
private:
    int DFS(int id, unordered_map<int, Employee*>& es) {
        Employee* e = es[id];
        int sum = e->importance;
        for (int rid : e->subordinates) {
            sum += DFS(rid, es);
        }
        return sum;
    }
};
int main(int argc, char const *argv[]) {
    vector<Employee*> employees;
    employees.push_back(new Employee(1, 5, {2, 3}));
    employees.push_back(new Employee(2, 3, {}));
    employees.push_back(new Employee(3, 3, {}));
    cout << Solution().getImportance(employees, 1) << endl;
    return 0;
}
