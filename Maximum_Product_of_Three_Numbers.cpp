/*
Here's how the solution works step by step:

Sorting the Array: The solution starts by sorting the nums array in ascending order using the sort function from the C++ Standard Library. Sorting the array helps 
in identifying the largest and smallest elements efficiently.

Calculating Maximum Product: Once the array is sorted, the solution calculates the maximum product in two possible scenarios:
The product of the last three elements (which are the largest elements) in the sorted array: nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1].
The product of the first two elements (which are the smallest elements) and the last element in the sorted array: nums[0] * nums[1] * nums[nums.size() - 1].
Returning Maximum Result: The solution then returns the maximum of the two calculated products, which represents the maximum product of three numbers that can be obtained from the given array.

Time Complexity:
The most time-consuming operation in this solution is the sorting step. Sorting an array of n elements using the sort function typically takes O(n log n) time 
complexity in the average and worst case. After sorting, the subsequent operations involve constant-time comparisons and multiplications. So, the overall time 
complexity of the solution is dominated by the sorting step and is O(n log n).

Space Complexity:
The sorting operation doesn't require additional space usage beyond the input array. Therefore, the space complexity of this solution is O(1), indicating constant 
space usage regardless of the input array size.

In summary:
Time Complexity: O(n log n) - Dominated by the sorting step.
Space Complexity: O(1) - Constant space complexity due to no additional space usage beyond the input array.
*/


/*
Here's how the solution works step by step:

Base Case Handling: Similar to the previous solution, the code starts by checking if the size of the nums array is 3. If so, it directly returns the product of the
three elements since there are no other choices.

Initialization: The solution initializes six variables similar to the previous solution, max1, max2, max3, min1, min2, and min3, to keep track of the largest and
smallest numbers encountered during iteration. They are initialized with appropriate extreme values using INT_MIN and INT_MAX.

Looping Through the Array: The code iterates through the nums array, just like the previous solution, to update the max and min variables accordingly.

Updating Maximum Values: For each element nums[i], it checks whether the element is greater than the current max1. If so, it updates the max3, max2, and max1
variables accordingly. If the element is not greater than max1 but is greater than max2, it updates max3 and max2. Similarly, if the element is not greater than
either max1 or max2 but is greater than max3, it updates only max3.

Updating Minimum Values: Similar to the maximum values, the solution updates the minimum values based on comparisons with the current min1, min2, and min3.

Calculating Result: After iterating through the array, the solution calculates the maximum product by considering two possibilities:
The product of the three largest numbers (max1 * max2 * max3).
The product of two smallest numbers and the largest number (min1 * min2 * max1).
Returning Maximum Result: The maximum product among the two calculated possibilities is returned as the final result.

Time Complexity:
The time complexity of this solution is mainly determined by the loop that iterates through the nums array. Similar to the previous solution, this loop iterates 
through all the elements of the array once. Inside the loop, there are constant-time operations for comparisons and updates of the max and min variables.
Therefore, as in the previous solution, the dominant factor in the time complexity is the loop itself, which contributes a linear time complexity of O(n), where n 
is the number of elements in the nums array.

Space Complexity:
The space complexity of the solution, similar to the previous one, is primarily determined by the variables used to keep track of the max and min values. These 
variables are constant in number, and their memory usage does not change with the input size. The solution uses six integer variables (max1, max2, max3, min1, min2, 
min3) to track the maximum and minimum values encountered during the iteration. Therefore, the space complexity remains constant, or O(1), since the amount of memory 
used by the algorithm does not depend on the size of the input array.

To summarize:
Time Complexity: O(n) - Linear time complexity due to the single loop iterating through the input array.
Space Complexity: O(1) - Constant space complexity due to the fixed number of variables used, regardless of the input array size.
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3) return nums[0] * nums[1] * nums[2];

        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3) {
                max3 = nums[i];
            }

            if(nums[i] < min1) {
                min3 = min2;
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2) {
                min3 = min2;
                min2 = nums[i];
            }
            else if(nums[i] < min3) {
                min3 = nums[i];
            }
        }

        int res = max1 * max2 * max3;

        return max(res, min1 * min2 * max1);
    }
};
