package search;

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

public class BST {

	// test main method
	public static void main(String[] args) {
		int[] array = { 19, 12, 3, 22, 6, 7, 21, 11, 43 };
		Node<Integer> root = new Node<Integer>(array[0]);
		for (int i = 1; i < array.length; i++) {
			binarySort(root, array[i]);
		}

		// look this binary tree
		inOrderTraverse(root);

		if (binarySerach(root, 12)) {
			System.out.println("二叉树中存在此元素");
		} else {
			System.out.println("二叉树中不存在该元素");
		}
	}

	// 二叉排序树插入操作
	public static void binarySort(Node<Integer> root, int key) {

		int value = root.getValue();

		if (key < value) {
			if (root.getL_child() == null) {
				Node<Integer> r = new Node<Integer>(key);
				root.setL_child(r);
			} else {
				binarySort(root.getL_child(), key);
			}
		} else {
			if (root.getR_child() == null) {
				Node<Integer> r = new Node<Integer>(key);
				root.setR_child(r);
			} else {
				binarySort(root.getR_child(), key);
			}
		}
	}

	public static boolean binarySerach(Node<Integer> root, int key) {
		if (root == null) {
			// throw new NullPointerException();
			return false;
		} else if (root.getValue() == key) {
			return true;
		} else if (root.getValue() < key) {
			return binarySerach(root.getR_child(), key);
		} else {
			return binarySerach(root.getL_child(), key);
		}
	}

	public static boolean delete(Node<Integer> root, int key) {
		if (root == null) {
			return false;
		}
		if (root.getValue() == key) {
			if (root.getR_child() == null) {
				root = root.getL_child();
				return true;
			} else if (root.getL_child() == null) {
				root = root.getR_child();
				return true;
			} else {

				root = root.getR_child();
				return true;
			}
		} else if (root.getValue() > key) {
			return delete(root.getL_child(), key);
		} else {
			return delete(root.getR_child(), key);
		}
	}
	
	private static Node<Integer> getSuccessor(Node<Integer> delNode)
    {
        // 后继节点的父节点
        Node<Integer> successorParent = delNode;
        // 后继节点
        Node<Integer> successor = delNode.getR_child();
        //判断后继节点是否有左孩子
        Node<Integer> current = successor.getL_child();
        while (current != null) {
            successorParent = successor;
            successor = current;
            current = current.getL_child();
        }
        //当该后继节点是属于包含左子节点的右节点的子节点
        if (successor != delNode.getR_child())
        {
            successorParent.setL_child(successor.getR_child());
            //连接被删除节点的右孩子
            successor.setR_child(delNode.getR_child());
        }
        return successor;
    }

	// 中序遍历
	public static void inOrderTraverse(Node<Integer> root) {
		if (root == null) {
			return;
		}
		inOrderTraverse(root.getL_child());
		System.out.println(root.getValue());
		inOrderTraverse(root.getR_child());
	}
}
