#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class JobSeq {
    public:
    struct Job {
        int id;
        int deadline;
        int profit;
    };

    static int comp(Job max, Job min) {
        return max.profit > min.profit;
    }

    pair<int, int> JobScheduleing(Job jobs[], int n) {
        sort(jobs, jobs + n, comp);
        int profit = 0;
        int maxTime = 0;
        int jobDone = 0;
        for (int i = 0; i < n; i++) {
            // knowing maximum deadline
                maxTime = max(maxTime, jobs[i].deadline);
        }
        vector<int> timeSlots(maxTime + 1, -1);
        for (int i = 0; i < n; i++) {
            Job currJob = jobs[i];
            for (int k = currJob.deadline; k > 0; k--) {
                if (timeSlots[k] == -1) {
                    timeSlots[k] = currJob.id;
                    profit += currJob.profit;
                    jobDone++;
                    break;
                }
            }
        }
        return { jobDone, profit };
    }
};

int main() {
    JobSeq jobSeq;

    JobSeq::Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30},{2, 4, 20}, {1, 1, 10}, {5, 1, 40}, {5, 1, 70} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    pair<int, int> result = jobSeq.JobScheduleing(jobs, n);

    cout << "Number of jobs scheduled--> " << result.first << endl;
    cout << "Total profit gained--> " << result.second << endl;

    cout << "Job Sequence: ";
    for (int i = 0; i <= result.first; i++) {
        if (i > 0) cout << " ---> ";
        cout << jobs[i].id;
    }
    cout << endl;

    return 0;
}
