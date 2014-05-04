package mathproblem;

import java.util.Arrays;

/**
 * @author Administrator 使用递归实现全排列.
 */
public class FullPermutation {

	static int count = 0;

	public static void main(String[] args) {
		// int[] n = { 1, 2, 3, 4, 5, 6, 7, 8, 9, };
		int[] n = { 1, 2, 3, 4, };
		allRange(n, 0, n.length - 1);
	}

	public static void allRange(int[] n, int first, int last) {
		if (first == last) {
			count++;
			System.out.println("第" + count + "组排列是:\t" + Arrays.toString(n));
		} else {
			for (int i = first; i <= last; i++) {
				swap(n, first, i);
				allRange(n, first + 1, last);
				swap(n, first, i);
			}
		}

	}

	private static void swap(int[] n, int first, int i) {
		if (first != i) {
			int tmp = n[first];
			n[first] = n[i];
			n[i] = tmp;
		}
	}
}
