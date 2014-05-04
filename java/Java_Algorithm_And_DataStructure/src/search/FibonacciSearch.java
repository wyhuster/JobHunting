package search;

public class FibonacciSearch {

	public static void main(String[] args) {
		int[] input = { 0,1,16,24,35,47,59,62,73,88,99, };
		System.out.print(fibonacci_search(input, 88));
	}

	public static int fibonacci_search(int[] input, int key) {
		int low, high, mid, i, k, n;
		n = input.length;
		low = 0;
		high = n - 1;
		k = 0;

		while (n > f_non_recursion(k)) {
			k++;
		}

		if (n < f_non_recursion(k) - 1) {
			int[] other = new int[(int) (f_non_recursion(k) - 1)];
			for (int j = 0; j < n; j++) {
				other[j] = input[j];
			}
			input = other;
		}

		for (i = n; i < f_non_recursion(k) - 1; i++) {
			input[i] = input[n - 1];
		}

		while (low <= high) {
			mid = (int) (low + f_non_recursion(k - 1) - 1);
			if (key < input[mid]) {
				high = mid - 1;
				k = k - 1;
			} else if (key > input[mid]) {
				low = mid + 1;
				k = k - 2;
			} else {
				if (mid <= n) {
					return mid;
				} else {
					return n;
				}
			}
		}
		return -1;
	}

	public static long f_non_recursion(int n) {
		long f1 = 0, f2 = 1;
		if (n == 1)
			return f1;
		else if (n == 2)
			return f2;
		else if (n > 2) {
			long f = f1 + f2;
			int i = 3;
			while (i <= n) {
				f = f1 + f2;
				f1 = f2;
				f2 = f;
				i++;
			}
			return f;
		}
		return -1;
	}
}
