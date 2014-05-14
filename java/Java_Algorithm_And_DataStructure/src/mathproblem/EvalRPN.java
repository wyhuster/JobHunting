package mathproblem;

public class EvalRPN {

	/*
	 * simple math operation using stack.
	 */
	public static void main(String[] args) {
		// String[] tokens = new String[] { "2", "1", "+", "3", "*" };
		String[] tokens = new String[] { "4", "13", "5", "/", "+" };
		System.out.println(evalRPN(tokens));
	}

	public static int evalRPN(String[] tokens) {
		int result = 0;
		String operators = "+-*/";
		java.util.Stack<Integer> stack = new java.util.Stack<Integer>();
		for (String token : tokens) {
			if (!operators.contains(token)) {
				stack.push(Integer.parseInt(token));
			} else {
				int a = stack.pop();
				int b = stack.pop();
				int index = operators.indexOf(token);
				switch (index) {
				case 0:
					stack.push(b + a);
					break;
				case 1:
					stack.push(b - a);
					break;
				case 2:
					stack.push(b * a);
					break;
				case 3:
					stack.push(b / a);
					break;

				}
			}
		}
		result = stack.pop();
		return result;
	}
}
