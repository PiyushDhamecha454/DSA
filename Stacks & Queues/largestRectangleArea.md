# Explanation and Intuition of the Algorithm

The problem at hand is to find the largest rectangle that can be formed in a histogram given the heights of the bars. The histogram is represented as an array of integers, where each integer corresponds to the height of a bar with a width of 1. The goal is to find the maximum rectangular area that can be enclosed within these bars.
Problem Restatement

Given an array of bar heights, heights = [2, 1, 5, 6, 2, 3], we need to find the largest rectangular area that can be formed using contiguous bars.
Intuitive Approach

### Brute Force Approach:
1. One naive way to solve this problem is to consider every possible rectangle.
2. For each bar, expand to the left and right to find the maximum rectangle that uses this bar as the smallest height.
3. Calculate the area for each of these rectangles and keep track of the maximum area found.
4. This approach results in a time complexity of O(n2)O(n2), which is inefficient for large inputs.

### Optimal Approach:
Instead of looking at every possible rectangle, use a stack-based approach to efficiently find the largest rectangle area. This method has a time complexity of O(n)O(n), making it much more suitable for larger datasets.

## Stack-Based Approach Explanation

The stack-based approach allows us to efficiently calculate the largest rectangle area by leveraging the following key observations:

**Rectangle Boundaries** : For each bar in the histogram, if this bar is the smallest (in height) within a certain range, it determines the height of the rectangle that can be formed using it. The width of this rectangle extends from the nearest smaller bar to the left to the nearest smaller bar to the right.

**Maintaining Order with a Stack** : The stack helps maintain indices of bars in increasing order of heights. When we encounter a bar that is shorter than the bar at the top of the stack, it means we can't extend the rectangle formed by the top of the stack anymore.

**Calculating Areas** : When a shorter bar is encountered, we pop the stack, use the popped bar as the shortest bar (height) of the rectangle, and calculate the possible area. This process continues until the stack is empty or the current bar is taller than the bar at the top of the stack.

Detailed Steps of the Algorithm

    Initialization:
        Use a stack to store the indices of bars.

        Initialize m (the maximum area) to 0.

    Iterate Over Each Bar:
        For each bar heights[i]:
            If the current bar is shorter than the bar at the index stored in the top of the
            stack, start popping from the stack to calculate areas.

            For each popped element, compute the area of the rectangle where this bar is the
            shortest.

            Push the current index onto the stack.

    Final Processing:
        After iterating through all the bars, the stack may still contain some indices. These
        indices are processed by considering the right boundary as the end of the histogram.

    Compute Maximum Area:
        The helper function getMax is called to compute the area of the largest rectangle using
        the bar at the popped index as the height. It updates the maximum area m.

Intuition with an Example

Consider heights = [2, 1, 5, 6, 2, 3]. We use the stack to track indices:

    Index 0 (heights[0] = 2):
        Stack is empty, push 0.
        Stack: [0]

    Index 1 (heights[1] = 1):
        Current bar is shorter than heights[s.top()] (1 < 2), so we start popping.
        Pop 0, calculate area with height 2, width 1 → area = 2 * 1 = 2.
        Update m = max(0, 2) = 2.
        Push 1.
        Stack: [1]
        Maximum Area (m): 2

    Index 2 (heights[2] = 5):
        Current bar is taller than heights[s.top()] (5 > 1), push 2.
        Stack: [1, 2]
        Maximum Area (m): 2

    Index 3 (heights[3] = 6):
        Current bar is taller than heights[s.top()] (6 > 5), push 3.
        Stack: [1, 2, 3]
        Maximum Area (m): 2

    Index 4 (heights[4] = 2):
        Current bar is shorter than heights[s.top()] (2 < 6), so we start popping.
        Pop 3, calculate area with height 6, width 1 → area = 6 * 1 = 6.
        Update m = max(2, 6) = 6.
        Pop 2, calculate area with height 5, width 2 → area = 5 * 2 = 10.
        Update m = max(6, 10) = 10.
        Push 4.
        Stack: [1, 4]
        Maximum Area (m): 10

    Index 5 (heights[5] = 3):
        Current bar is taller than heights[s.top()] (3 > 2), push 5.
        Stack: [1, 4, 5]
        Maximum Area (m): 10

    End of Array (i = 6):
        Process remaining bars in the stack.
        Pop 5, calculate area with height 3, width 1 → area = 3 * 1 = 3.
        Update m = max(10, 3) = 10.
        Pop 4, calculate area with height 2, width 4 → area = 2 * 4 = 8.
        Update m = max(10, 8) = 10.
        Pop 1, calculate area with height 1, width 6 → area = 1 * 6 = 6.
        Update m = max(10, 6) = 10.
        Stack: []

### ***Final Result*** : Maximum Area (m): 10

## Conclusion :
#### 1. The stack-based approach effectively reduces the time complexity to O(n)O(n) by only iterating over the bars once and using the stack to track potential rectangles' heights and indices.
#### 2. It maintains a monotonic increasing order of bar heights in the stack, allowing efficient area calculations whenever a shorter bar is encountered.
#### 3. This algorithm efficiently finds the largest rectangle area in a histogram by strategically using the stack to handle height comparisons and area calculations.