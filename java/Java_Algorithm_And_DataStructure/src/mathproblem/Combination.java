package mathproblem;

import java.util.Stack;

/**
 * @author Administrator
 * @see ./c++/Math/Combination.cpp
 */
public class Combination {
	public static void main(String[] args) {
		String s = "abc";
		getAllCombination(s);
	}

	public static void combination(String s, int i, int num,
			Stack<Character> result) {
		if (s == null) {
			return;
		}
		if (num == 0) {
			System.out.println(result);
			return;
		}
		if (i >= s.length()) {
			return;
		}
		result.push(s.charAt(i));
		combination(s, i + 1, num - 1, result);
		result.pop();
		combination(s, i + 1, num, result);
	}
	
	public static void getAllCombination(String s){
		if(s==null){
			return;
		}
		Stack<Character> result = new Stack<Character>();
		int length = s.length();
		for(int i=1;i<=length;i++){
			combination(s, 0, i, result);
		}
	}
}
