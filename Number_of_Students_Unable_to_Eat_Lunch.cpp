/*
Code Explanation:
The code defines a class named Solution which contains a member function countStudents that takes two input vectors: students representing the preferences of 
students and sandwiches representing the available sandwiches.

1. The code initializes a few variables:
left: This variable will be used to iterate through the students' queue.
size: Initially set to the number of students, it keeps track of the original size of the students' queue.
curr_size: This variable tracks the current size of the students' queue.
The code enters a do-while loop that executes the following steps until the size of the students' queue (curr_size) remains the same as the previous iteration:
a. The variable size is updated to the current size of the students' queue.
b. The variable left is set to 0, indicating the start of the students' queue.

2. Within the loop, a while loop is used to iterate through the students' queue:
a. It checks if the student at the left index has a preference for the type of sandwich at index 0 in the sandwiches vector.
b. If the condition is satisfied, it means the student's preferred sandwich is available, so the code removes that student from the queue 
(students.erase(students.begin() + left);) and also removes the corresponding sandwich from the available sandwiches (sandwiches.erase(sandwiches.begin() + 0);).
c. The continue statement is used to skip the rest of the loop's logic and proceed to the next iteration.

3. After the inner while loop completes, the variable curr_size is updated to the new size of the students' queue.

4. The outer do-while loop continues until the size of the students' queue (curr_size) remains the same as the previous iteration. This loop essentially simulates 
the process of students eating their preferred sandwiches until no more changes can be made.

5. Finally, the function returns the size of the students' queue, which represents the number of students who were unable to eat their preferred sandwiches.
 
Time Complexity (T.C.):
In the worst case, each student is removed from the queue once, resulting in a time complexity of O(n^2), where n is the initial number of students.

Space Complexity (S.C.):
It uses extra space to store the left index, the size variable, and the curr_size variable. Additionally, it modifies the students and sandwiches
vectors in place. Overall, the space complexity is O(1) or constant, apart from the input vectors.
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int left = 0;
        int size = students.size();
        int curr_size = size;
      
        do {
            size = students.size();
            left = 0;

            while(left < students.size())
            {
                if(students[left] == sandwiches[0])
                {
                    students.erase(students.begin() + left);
                    sandwiches.erase(sandwiches.begin() + 0);
                    continue;
                }

                ++left;
            }

            curr_size = students.size();
        }
        while(curr_size < size);

        return students.size();
    }
};


/* 

Sure! Here's a C++ code that solves the "Number of Students Unable to Eat Lunch" problem with O(n) time complexity and O(1) space complexity:

cpp
Copy code
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0}; // Count of students with preference 0 and 1
        int n = students.size();

        for (int student : students) {
            ++count[student]; // Counting students with each preference
        }

        for (int i = 0; i < n; ++i) {
            if (count[sandwiches[i]] > 0) {
                --count[sandwiches[i]]; // A student with preference found, decrement count
            } else {
                return n - i; // Return remaining students unable to eat
            }
        }

        return 0; // All students ate their preferred sandwiches
    }
};
Explanation:

1. The code defines a class Solution with the countStudents function that takes the students and sandwiches vectors as input.

2. It initializes an array count with two elements to keep track of the count of students with preferences 0 and 1.

3. It iterates through the students vector and increments the appropriate count in the count array based on each student's preference.

4. Then, it iterates through the sandwiches vector and checks if there is a student with the corresponding preference. If found, it decrements the count for that preference. If not found, it returns the count of remaining students unable to eat.

5. If all students are able to eat their preferred sandwiches, the function returns 0.

Time Complexity:
The solution iterates through both the students and sandwiches vectors once, resulting in a linear time complexity of O(n), where n is the number of students (or sandwiches).

Space Complexity:
The solution uses a constant amount of extra space for the count array, regardless of the input size. Therefore, the space complexity is O(1).

This code provides an efficient solution to the problem with optimal time and space complexity.
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0}; // Count of students with preference 0 and 1
        int n = students.size();

        for (int student : students) {
            ++count[student]; // Counting students with each preference
        }

        for (int i = 0; i < n; ++i) {
            if (count[sandwiches[i]] > 0) {
                --count[sandwiches[i]]; // A student with preference found, decrement count
            } else {
                return n - i; // Return remaining students unable to eat
            }
        }

        return 0; // All students ate their preferred sandwiches
    }
};
