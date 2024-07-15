#include <vector>
#include <algorithm>

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int totalLen = m + n;
        int left = 0, right = m;

        while (left <= right)
        {
            int partitionX = (left + right) / 2;
            int partitionY = (totalLen + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX)
            {
                // Found the correct partition
                if (totalLen % 2 == 0)
                {
                    double leftMax = std::max(maxX, maxY);
                    double rightMin = std::min(minX, minY);
                    return (leftMax + rightMin) / 2.0;
                }
                else
                {
                    return std::max(maxX, maxY);
                }
            }
            else if (maxX > minY)
            {
                // Move left in nums1
                right = partitionX - 1;
            }
            else
            {
                // Move right in nums1
                left = partitionX + 1;
            }
        }

        return 0.0;
    }
};
