package search;

//使用泛型函数和泛型类来实现二叉排序树.
class Node<T> {
	private T value;

	public T getValue() {
		return value;
	}

	public void setValue(T value) {
		this.value = value;
	}

	public Node<T> getL_child() {
		return l_child;
	}

	public void setL_child(Node<T> l_child) {
		this.l_child = l_child;
	}

	public Node<T> getR_child() {
		return r_child;
	}

	public void setR_child(Node<T> r_child) {
		this.r_child = r_child;
	}

	private Node<T> l_child;
	private Node<T> r_child;

	public Node() {

	}

	public Node(T t) {
		value = t;
	}

}

// 树中value的测试对象.
class NodeValue implements Comparable<NodeValue> {

	private int x;
	private int y;

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public NodeValue() {
	}

	public NodeValue(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "NodeValue [x=" + x + ", y=" + y + "]";
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(NodeValue o) {
		// TODO Auto-generated method stub
		if (this.x != o.getX()) {
			return this.x - o.getX();
		} else {
			return this.y - o.getY();
		}
	}
}

public class BST {

	// test main method
	public static void main(String[] args) {
		int[] array = { 19, 12, 3, 22, 6, 7, 21, 11, 43 };
		Node<Integer> root = new Node<Integer>(array[0]);
		for (int i = 1; i < array.length; i++) {
			binaryInsert(root, array[i]);
		}

		// look this binary tree
		inOrderTraverse(root);

		//if (binarySerach(root, 12)) {
		if (binarySerach_non_recursion(root, 12)) {
			System.out.println("二叉树中存在此元素");
		} else {
			System.out.println("二叉树中不存在该元素");
		}
		System.out.println("------------------------");
		System.out.println("删除某一个节点19");
		delete(root, 19);
		inOrderTraverse(root);
		System.out.println("------------------------");
		NodeValue[] array1 = { new NodeValue(1, 2), new NodeValue(2, 2),
				new NodeValue(3, 4), new NodeValue(3, 5), new NodeValue(4, 3), };
		Node<NodeValue> root1 = new Node<NodeValue>(array1[0]);
		for (int i = 1; i < array1.length; i++) {
			binaryInsert(root1, array1[i]);
		}

		// look this binary tree
		inOrderTraverse(root1);

		if (binarySerach(root1, new NodeValue(1, 2))) {
			System.out.println("二叉树中存在此元素");
		} else {
			System.out.println("二叉树中不存在该元素");
		}
	}

	// 二叉排序树插入操作.递归实现
	public static <T extends Comparable<T>> void binaryInsert(Node<T> root,
			T key) {
		if (root == null) {
			return;
		}
		T value = root.getValue();
		if (key.compareTo(value) < 0) {
			if (root.getL_child() == null) {
				Node<T> r = new Node<T>(key);
				root.setL_child(r);
			} else {
				binaryInsert(root.getL_child(), key);
			}
		} else {
			if (root.getR_child() == null) {
				Node<T> r = new Node<T>(key);
				root.setR_child(r);
			} else {
				binaryInsert(root.getR_child(), key);
			}
		}
	}

	public static <T extends Comparable<T>> void binaryInsert_non_recursion(
			Node<T> root, T key) {
		if (root == null) {
			return;
		}
		T value = root.getValue();
		if (key.compareTo(value) < 0) {
			if (root.getL_child() == null) {
				Node<T> r = new Node<T>(key);
				root.setL_child(r);
			} else {
				binaryInsert(root.getL_child(), key);
			}
		} else {
			if (root.getR_child() == null) {
				Node<T> r = new Node<T>(key);
				root.setR_child(r);
			} else {
				binaryInsert(root.getR_child(), key);
			}
		}
	}

	// 二叉树搜索.递归实现
	public static <T extends Comparable<T>> boolean binarySerach(Node<T> root,
			T key) {
		if (root == null) {
			// throw new NullPointerException();
			return false;
		} else if (root.getValue().compareTo(key) == 0) {
			return true;
		} else if (root.getValue().compareTo(key) < 0) {
			return binarySerach(root.getR_child(), key);
		} else {
			return binarySerach(root.getL_child(), key);
		}
	}

	// 非递归实现二叉排序树的搜索.
	public static <T extends Comparable<T>> boolean binarySerach_non_recursion(
			Node<T> root, T key) {
		Node<T> current = root;
		while (current != null) {
			// current.value < key
			if (current.getValue().compareTo(key) < 0) {
				current = current.getR_child();
			} else if (current.getValue().compareTo(key) > 0) {
				current = current.getL_child();
			} else {
				return true;
			}
		}
		return false;
	}

	// 删除某个节点.可能还存在bug.
	public static <T extends Comparable<T>> boolean delete(Node<T> root, T key) {
		if (root == null) {
			return false;
		}
		if (root.getValue().compareTo(key) == 0) {
			if (root.getR_child() == null) {
				root = root.getL_child();
				return true;
			} else if (root.getL_child() == null) {
				root = root.getR_child();
				return true;
			} else {
				// 左右孩子都都不为空的情况下，使用左子树的最由端的节点来替代root，或者右子树的最左端的节点替代root.
				
				Node<T> current = root.getL_child();
				Node<T> parent = root;
				
				while (current.getR_child() != null) {
					parent = current;
					current = current.getR_child();
				}
				
				if(current != root.getL_child()){
					parent.setR_child(current.getL_child());
					current.setR_child(root.getR_child());
					current.setL_child(root.getL_child());
					//root = current;
					root.setValue(current.getValue());
					root.setL_child(current.getL_child());
					root.setR_child(current.getR_child());
					current = null;
				}else{
					current.setR_child(root.getR_child());
					//root = current;
					root.setValue(current.getValue());
					root.setL_child(current.getL_child());
					root.setR_child(current.getR_child());
					current = null;
				}
				//inOrderTraverse(root);
				return true;
			}
		} else if (root.getValue().compareTo(key) > 0) {
			return delete(root.getL_child(), key);
		} else {
			return delete(root.getR_child(), key);
		}
	}

	// 中序遍历,递归实现
	public static <T> void inOrderTraverse(Node<T> root) {
		if (root == null) {
			return;
		}
		inOrderTraverse(root.getL_child());
		System.out.print(root.getValue() + "  ");
		inOrderTraverse(root.getR_child());
	}
}
