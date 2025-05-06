// Write a JAVA program to read the marks obtained by students in an online examination of a
// particular subject. a)Find the minimum and maximum marks obtained in that subject Use the
// heap data structure. b) sort the marks in ascending order using heapsort .

import java.util.*;

public class Ass16 {

    // Heapify subtree rooted at index i (for max-heap)
    public static void heapify(int[] arr, int n, int i) {
        int largest = i;  // root
        int left = 2 * i + 1; // left child
        int right = 2 * i + 2; // right child

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            // Swap and continue heapifying
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    // Heap sort algorithm
    public static void heapSort(int[] arr) {
        int n = arr.length;

        // Build max-heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();
        int[] marks = new int[n];

        System.out.println("Enter marks of " + n + " students:");
        for (int i = 0; i < n; i++) {
            marks[i] = sc.nextInt();
        }

        // a) Min and Max using PriorityQueue
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for (int mark : marks) {
            minHeap.add(mark);
            maxHeap.add(mark);
        }

        System.out.println("\nMinimum Marks: " + minHeap.peek());
        System.out.println("Maximum Marks: " + maxHeap.peek());

        // b) Sorting using Heap Sort
        heapSort(marks);

        System.out.println("\nMarks in Ascending Order:");
        for (int mark : marks) {
            System.out.print(mark + " ");
        }

        sc.close();
    }
}

// Enter number of students: 6
// Enter marks of 6 students:
// 72 65 90 78 85 60


// Use these commands to compile and run the program:
// javac Ass16.java
// java Ass16

// ------------------------------------------------------------------------------------------------------------------


// This Java program does two things using **heap data structures**:

// ---

// ## ✅ Problem Summary

// **Input:** Marks obtained by students in an online exam
// **Tasks:**

// 1. Find the **minimum** and **maximum** marks using a heap
// 2. **Sort** all marks in **ascending order** using **Heap Sort**

// ---

// ## 🔍 Line-by-Line Breakdown

// ---

// ### 🔹 `heapify()` function

// ```java
// public static void heapify(int[] arr, int n, int i)
// ```

// This builds or repairs a **max heap** rooted at index `i`.
// In a max heap:

// * Parent is always **greater than** both children.

// ```java
// int largest = i;
// int left = 2 * i + 1;
// int right = 2 * i + 2;
// ```

// * Checks if left or right child is larger than current node `i`
// * If so, it **swaps** and **recursively heapifies** the affected subtree.

// ---

// ### 🔹 `heapSort()` function

// ```java
// public static void heapSort(int[] arr)
// ```

// This sorts the array in **ascending order** using **heap sort**, which works in two phases:

// 1. **Build a max heap** from the array.

//    ```java
//    for (int i = n/2 - 1; i >= 0; i--)
//        heapify(arr, n, i);
//    ```

// 2. **Extract the root (largest)** and place it at the end of the array:

//    ```java
//    for (int i = n - 1; i > 0; i--) {
//        swap(arr[0], arr[i]);
//        heapify(arr, i, 0);
//    }
//    ```

// This gives a **sorted array in ascending order**.

// ---

// ### 🔹 Main Method

// #### Step 1: Input

// ```java
// Scanner sc = new Scanner(System.in);
// System.out.print("Enter number of students: ");
// int n = sc.nextInt();
// int[] marks = new int[n];
// ```

// Reads number of students and stores their marks in an array.

// ---

// #### Step 2: Min and Max using Heaps

// ```java
// PriorityQueue<Integer> minHeap = new PriorityQueue<>();
// PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
// ```

// * `minHeap`: default priority queue (gives **min** element first)
// * `maxHeap`: reverse order (gives **max** element first)

// ```java
// for (int mark : marks) {
//     minHeap.add(mark);
//     maxHeap.add(mark);
// }
// ```

// ### Output:

// ```java
// System.out.println("Minimum Marks: " + minHeap.peek());
// System.out.println("Maximum Marks: " + maxHeap.peek());
// ```

// * `peek()` gives the top value of the heap without removing it

// ---

// #### Step 3: Sort using Heap Sort

// ```java
// heapSort(marks);
// ```

// Then print the sorted array.

// ---

// ## 🧪 Sample Run

// ```
// Enter number of students: 6
// Enter marks of 6 students:
// 72 65 90 78 85 60

// Minimum Marks: 60
// Maximum Marks: 90

// Marks in Ascending Order:
// 60 65 72 78 85 90
// ```

// ---

// ## ✅ Summary

// | Operation                   | Data Structure Used                   | Output       |
// | --------------------------- | ------------------------------------- | ------------ |
// | Minimum & Maximum           | Min-heap and Max-heap (PriorityQueue) | 60 and 90    |
// | Ascending Sort              | Max-heap (manual Heap Sort)           | Sorted marks |
// | Time Complexity (Heap Sort) | `O(n log n)`                          | Efficient    |

// ---

// Would you like to also implement this with **Min-Heap-based sorting** or as a **menu-driven program** for better interactivity?
