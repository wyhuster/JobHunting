package mathproblem;

import java.util.Scanner;

//找出所有的素数
public class PrimeNumber {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Find all prime numbers <=n ,enter n: ");
		int n = input.nextInt();

		final int NUMBER_PER_LINE = 10;
		int count = 0;
		int number = 2;

		System.out.println("The prime number are: ");

		/*while (number <= n) {
			boolean isPrime = true;

			// 判断一个数是否为素数的过程
			// 时间复杂度为O(n^0.5)
			int squareRoot = (int) Math.sqrt(number);
			for (int divisor = 2; divisor <= squareRoot; divisor++) {
				if (number % divisor == 0) {
					isPrime = false;
					break;
				}
			}*/
		int squareRoot = 1;
		while (number <= n) {
			boolean isPrime = true;

			if (squareRoot * squareRoot < number)
				squareRoot++;
			
			for (int divisor = 2; divisor <= squareRoot; divisor++) {
				if (number % divisor == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) {
				count++;

				if (count % NUMBER_PER_LINE == 0) {
					System.out.printf("%7d\n", number);
				} else
					System.out.printf("%7d", number);
			}
			number++;
		}
		System.out
				.println("\n" + count + " prime(s) less than n equal to " + n);
	}
}
