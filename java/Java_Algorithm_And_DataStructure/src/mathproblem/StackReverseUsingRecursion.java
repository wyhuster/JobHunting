package mathproblem;

import java.util.Stack;

public class StackReverseUsingRecursion {

	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();
		for (int i = 0; i < 10; i++)
			stack.push(i);
		System.out.println(stack);
		reverseStack(stack);
		System.out.println(stack);
	}

	public static <T> void reverseStack(Stack<T> stack) {
		if (!stack.isEmpty()) {
			T element = stack.pop();
			reverseStack(stack);
			addToStackBottom(stack, element);
		}
	}

	public static <T> void addToStackBottom(Stack<T> stack, T t) {
		if (!stack.isEmpty()) {
			T element = stack.pop();
			addToStackBottom(stack, t);
			stack.push(element);
		} else {
			stack.push(t);
		}
	}

}
