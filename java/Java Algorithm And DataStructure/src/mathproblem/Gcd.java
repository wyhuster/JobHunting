package mathproblem;

//两个数的最大公约数的计算方法
public class Gcd {

	public static void main(String[] args) {
		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd : " + gcd(100000000, 500000000));
			}
		}).start();

		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd1 : " + gcd1(100000000, 500000000));
			}
		}).start();

		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd2 : " + gcd2(100000000, 500000000));
			}
		}).start();
		
		new Thread(new Runnable() {

			@Override
			public void run() {
				System.out.println("gcd3 : " + gcd3(100000000, 500000000));
			}
		}).start();
	}

	/**
	 * @author Administrator
	 * @return 返回m与n的最大公约数 时间复杂度为：m>=n的话，O(n)
	 */
	public static int gcd(int m, int n) {
		int gcd = 1;
		for (int k = 2; k <= m && k <= n; k++) {
			if (m % k == 0 && n % k == 0)
				gcd = k;
		}
		return gcd;
	}

	/**
	 * @author Administrator
	 * @param m
	 * @param n
	 * @return gcd(m,n) 时间复杂度分析：从n开始循环，如果找到就退出循环，最坏情况任然是O(n)
	 */
	public static int gcd1(int m, int n) {
		int gcd = 1;
		if (m >= n) {
			for (int k = n; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		} else {
			for (int k = m; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		}
		return gcd;
	}

	/**
	 * @author Administrator
	 * @param m
	 * @param n
	 * @return 时间复杂度分析：m与n的最大公约数不可能大于n/2和m/2
	 */
	public static int gcd2(int m, int n) {
		int gcd = 1;
		if (m >= n) {
			if (m % n == 0)
				return n;

			for (int k = n / 2; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		} else {
			if (n % m == 0)
				return m;

			for (int k = m / 2; k >= 1; k--) {
				if (m % k == 0 && n % k == 0) {
					gcd = k;
					break;
				}
			}
		}
		return gcd;
	}

	/**
	 * @author Administrator
	 * @param m
	 * @param n
	 * @return 使用递归来完成最大公约数的计算
	 * 时间复杂度：O(logn)
	 */
	public static int gcd3(int m, int n) {
		if (m % n == 0)
			return n;
		else
			return gcd(n, m % n);
	}

}
