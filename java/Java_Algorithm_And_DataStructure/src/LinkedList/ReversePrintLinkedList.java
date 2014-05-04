package LinkedList;

import java.util.Stack;
import static net.mindview.util.Print.*;

public class ReversePrintLinkedList {

	public static void main(String[] args) {
		List<Integer> root = new List<Integer>(0);
		List<Integer> current = root;
		for (int i = 1; i < 10; i++) {
			current.next = new List<Integer>(i);
			current = current.next;
		}
		printListReversingly_Iteratively(root);
		printListReversingly_Recursion(root);
	}

	// 使用栈完成单链表的反向打印.
	public static <T> void printListReversingly_Iteratively(List<T> root) {
		Stack<T> stack = new Stack<T>();
		while (root != null) {
			stack.push(root.element);
			root = root.next;
		}
		// out print
		while (!stack.isEmpty()) {
			T element = stack.pop();
			printnb(element+" ");
		}
	}

	// 使用递归完成单链表的打印
	public static <T> void printListReversingly_Recursion(List<T> root) {
		if (root != null) {
			if (root.next != null) {
				printListReversingly_Recursion(root.next);
			}
			printnb(root.element+" ");
		}

	}

}

class List<T> {
	T element;
	List<T> next;

	public List(T element) {
		super();
		this.element = element;
	}
}
