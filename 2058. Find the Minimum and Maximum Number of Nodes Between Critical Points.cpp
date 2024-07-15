/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {

        vector<int> result = {-1, -1};
        if (!head || !head->next)
        {
            return result;
        }
        vector<int> critical_points;
        ListNode *prev = NULL;
        ListNode *current = head;
        int index = 0;
        while (current)
        {
            ListNode *next_node = current->next;
            if (prev && next_node)
            {

                if (prev->val < current->val && current->val > next_node->val)
                    critical_points.push_back(index);
                if (prev->val > current->val && current->val < next_node->val)
                    critical_points.push_back(index);
            }
            prev = current;
            current = next_node;
            index++;
        }
        if (critical_points.size() < 2)
            return result;

        int min_distance = INT_MAX;
        int max_distance = INT_MIN;
        for (int i = 1; i < critical_points.size(); i++)
        {
            int distance = critical_points[i] - critical_points[i - 1];
            if (distance < min_distance)
                min_distance = distance;
            if (distance > max_distance)
                max_distance = distance;
        }
        result[0] = min_distance;
        result[1] = max_distance;
        return result;
    }
};