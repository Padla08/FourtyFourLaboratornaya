import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Task 1: Initialization of an array with 10 random numbers in the range [0, 100]
        int n = 10;
        double[] arr = new double[n];
        Random rand = new Random();
        for (int i = 0; i < n; ++i) {
            arr[i] = rand.nextDouble() * 100;
        }
        System.out.println("Task 1: Array of 10 random numbers in the range [0, 100]:");
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Task 2: Calculation of the average value and the sum of the squares of the differences
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        double average = sum / n;
        double sumOfSquares = 0;
        for (int i = 0; i < n; ++i) {
            sumOfSquares += Math.pow(arr[i] - average, 2);
        }
        System.out.println("Task 2: Sum of the squares of the differences: " + sumOfSquares);

        // Task 3: Replacement of the first and last digits of even elements with an even index
        for (int i = 0; i < n; i += 2) {
            int num = (int) arr[i];
            if (num >= 10 && num < 100) {
                int firstDigit = num / 10;
                int lastDigit = num % 10;
                arr[i] = lastDigit * 10 + firstDigit;
            }
        }
        System.out.println("Task 3: Array after replacing the first and last digits:");
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Task 4: Shift of array elements to the right by one position
        double temp = arr[n - 1];
        for (int i = n - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
        System.out.println("Task 4: Array after shifting to the right by one position:");
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Task 5: Initialization of an array with 50 random numbers in the range [-10, 10]
        int m = 50;
        int[] arr2 = new int[m];
        for (int i = 0; i < m; ++i) {
            arr2[i] = rand.nextInt(21) - 10;
        }
        System.out.println("Task 5: Array of 50 random numbers in the range [-10, 10]:");
        for (int num : arr2) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Counting the occurrences of each number in the array
        Map<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < m; ++i) {
            count.put(arr2[i], count.getOrDefault(arr2[i], 0) + 1);
        }
        System.out.println("Task 5: Count of occurrences of each number in the array:");
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Removing duplicate elements from the array
        Arrays.sort(arr2);
        int j = 0;
        for (int i = 0; i < m - 1; ++i) {
            if (arr2[i] != arr2[i + 1]) {
                arr2[j++] = arr2[i];
            }
        }
        arr2[j++] = arr2[m - 1];
        arr2 = Arrays.copyOf(arr2, j);
        System.out.println("Task 5: Array after removing duplicate elements:");
        for (int num : arr2) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}