package mathproblem;

//The definition of BalancePoint is the sums of his left and his right are equal. 
public class BalancePoint {

	public static void main(String[] args) {
		int[] n = { 1, 2, 3, 0, 1, 2, 3, 0, 0, };
		// int[] n = null;
		System.out.println(findBalancePoint1(n));
		System.out.println(findBalancePoint2(n));
	}

	/**
	 * @author Administrator
	 * @param n
	 * @return the first place of balance point in array n.
	 * @timeComplexity O(n^2).
	 */
	public static int findBalancePoint1(int[] n) {
		if (n == null) {
			return -1;
		}
		if (n.length < 3) {
			return -1;
		}
		for (int i = 1; i < n.length; i++) {
			int sum1 = 0;
			int sum2 = 0;
			for (int j = 0; j < i; j++) {
				sum1 += n[j];
			}
			for (int j = i + 1; j < n.length; j++) {
				sum2 += n[j];
			}
			if (sum1 == sum2) {
				return i;
			}
		}
		return -1;
	}

	// optimized method with a better time complexity.O()
	public static int findBalancePoint2(int[] n) {
		if (n == null)
			return -1;
		if (n.length < 3)
			return -1;
		int sum = 0;
		for (int i : n)
			sum += i;
		for (int i = 1; i < n.length - 1; i++) {
			int remain = sum - n[i];
			if (remain % 2 != 0)
				continue;
			int bRemain = remain / 2;
			if (i < n.length / 2) {
				for (int j = 0; j < i; j++) {
					bRemain -= n[j];
				}
				if (bRemain == 0)
					return i;
			} else {
				for (int j = i + 1; j < n.length; j++) {
					bRemain -= n[j];
				}
				if (bRemain == 0)
					return i;
			}

		}
		return -1;
	}
}
