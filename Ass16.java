// Write a JAVA program to read the marks obtained by students in an online examination of a
// particular subject. a)Find the minimum and maximum marks obtained in that subject Use the
// heap data structure. b) sort the marks in ascending order using heapsort .

import java.util.*;

public class HeapMarks {

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
