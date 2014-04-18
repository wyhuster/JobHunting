package sort;

import java.util.Arrays;

import static net.mindview.util.Print.*;

public class AllSortMethod {

	public static void main(String[] args) {
		int[] n = { 9, 1, 5, 8, };
		System.out.println(Arrays.toString(n));

//		BubbleSortMethod.bubbleSort0(n);
//		SelectSortMethod.selectSort(n);
//		InsertSortMethod.insertSort(n);
//		ShellSortMethod.shellSort(n);
//		MergeSortMethod.mergerSort(n);
		HeapSortMethod.heapSort(n);
	}
}

class SortUtils {
	public static void swap(int[] n, int i, int j) {
		int temp = n[i];
		n[i] = n[j];
		n[j] = temp;
	}
}

// 冒泡排序法
class BubbleSortMethod {
	// first bubbleSort()
	public static void bubbleSort0(int[] n) {
		for (int i = 0; i < n.length; i++) {
			for (int j = i + 1; j < n.length; j++) {
				if (n[i] > n[j]) {
					SortUtils.swap(n, i, j);
				}
			}
		}
		System.out.println(Arrays.toString(n));
	}

	// second bubbleSort(),真宗的冒泡排序算法
	public static void bubbleSort1(int[] n) {
		for (int i = 0; i < n.length; i++) {
			for (int j = n.length - 2; j >= i; j--) {
				if (n[j] > n[j + 1]) {
					SortUtils.swap(n, j, j + 1);
				}
			}
		}
		System.out.println(Arrays.toString(n));
	}

	// third bubbleSort(),冒泡排序的优化
	public static void bubbleSort2(int[] n) {
		boolean flag = true;
		for (int i = 0; i < n.length && flag; i++) {
			flag = false;
			for (int j = n.length - 2; j >= i; j--) {
				if (n[j] > n[j + 1]) {
					SortUtils.swap(n, j, j + 1);
					flag = true;
				}
			}
		}
		System.out.println(Arrays.toString(n));
	}
}

// 简单选择排序法
class SelectSortMethod {
	/*
	 * 算法时间复杂度分析：无论是最好还是最坏的情况，其进行比较的次数都是一样的，一共需要进行比较次数：1+2+3+...+(n-1)=n*(n-1)/2
	 * 交换次数，最好的情况是0次，最坏的情况是n-1此，其最终的排序时间是比较次数加上交换次数的总和因此其时间复杂度是O(n^2)
	 */
	public static void selectSort(int[] n) {
		int min;
		for (int i = 0; i < n.length; i++) {
			min = i;
			for (int j = i + 1; j < n.length; j++) {
				if (n[min] > n[j]) {
					min = j;
				}
			}
			if (i != min) {
				SortUtils.swap(n, i, min);
			}
		}
		System.out.println(Arrays.toString(n));
	}
}

// 直接插入排序法
class InsertSortMethod {
	public static void insertSort(int[] n) {
		int i, j, key;
		for (i = 1; i < n.length; i++) {
			if (n[i] < n[i - 1]) {
				key = n[i];
				for (j = i - 1; j > 0 && n[j] > key; j--) {
					n[j + 1] = n[j];
				}
				n[j + 1] = key;
			}
		}
		System.out.println(Arrays.toString(n));
	}
}

// shell排序
class ShellSortMethod {
	public static void shellSort(int[] n) {
		int increment = n.length;
		int i, j;
		int key;
		do {
			// 关键是这个增量序列的选取规则
			increment = increment / 3 + 1;
			for (i = increment; i < n.length; i++) {
				if (n[i] < n[i - increment]) {
					key = n[i];
					for (j = i - increment; j >= 0 && key < n[j]; j -= increment) {
						n[j + increment] = n[j];
					}
					n[j + increment] = key;
				}
			}
		} while (increment > 1);
		System.out.println(Arrays.toString(n));
	}
}

// 堆排序
class HeapSortMethod {
	private static void heapAdjust(int[] n, int i, int size) {
		// 堆调整
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int max = i;
		if (i <= size / 2 - 1) {
			if (lchild < size && n[lchild] > n[max]) {
				max = lchild;
			}
			if (rchild < size && n[rchild] > n[max]) {
				max = rchild;
			}
			if (max != i) {
				SortUtils.swap(n, i, max);
				heapAdjust(n, max, size);
			}
		}
	}

	private static void buildHeap(int[] n, int size) {
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapAdjust(n, i, size);
		}
	}

	public static void heapSort(int[] n) {
		int size = n.length;
		buildHeap(n, size);

		print("-----------初始建堆---------------");
		print(Arrays.toString(n));
		print("-------------------------------");

		for (int i = size - 1; i > 0; i--) {
			SortUtils.swap(n, 0, i);
			print(Arrays.toString(n));
			heapAdjust(n, 0, i);

			print(Arrays.toString(n));
			print("-------------------------------");

		}
		System.out.println(Arrays.toString(n));
	}
}

// 归并排序法
class MergeSortMethod {
	private static void partition(int[] array, int from, int end) {
		if (from < end) {
			int mid = (from + end) / 2;
			partition(array, from, mid);
			partition(array, mid + 1, end);
			merge(array, from, end, mid);
		}
	}

	private static void merge(int[] array, int from, int end, int mid) {
		int[] tmpArray = new int[10];
		int tmpArrayIndex = 0;
		int part1ArrayIndex = from;
		int part2ArrayIndex = mid + 1;
		while ((part1ArrayIndex <= mid) && (part2ArrayIndex <= end)) {
			if (array[part1ArrayIndex] < array[part2ArrayIndex]) {
				tmpArray[tmpArrayIndex++] = array[part1ArrayIndex++];
			} else {
				tmpArray[tmpArrayIndex++] = array[part2ArrayIndex++];
			}
		}
		while (part1ArrayIndex <= mid) {
			tmpArray[tmpArrayIndex++] = array[part1ArrayIndex++];
		}
		while (part2ArrayIndex <= end) {
			tmpArray[tmpArrayIndex++] = array[part2ArrayIndex++];
		}
		System.arraycopy(tmpArray, 0, array, from, end - from + 1);
	}

	public static void mergerSort(int[] n) {
		partition(n, 0, n.length - 1);
		System.out.println(Arrays.toString(n));
	}
}

// 快速排序法
class QuickSortMethod {
	public static void quickSort(int[] n) {
		qSort(n, 0, n.length - 1);
		System.out.println(Arrays.toString(n));
	}

	private static void qSort(int[] n, int low, int high) {
		int pivot;
		if (low < high) {
			pivot = quickSortPartition(n, low, high);
			qSort(n, low, pivot - 1);
			qSort(n, pivot + 1, high);
		}
	}

	private static int quickSortPartition(int[] n, int low, int high) {
		int pivotkey;
		pivotkey = n[low];
		while (low < high) {
			while (low < high && n[high] >= pivotkey) {
				high--;
			}
			SortUtils.swap(n, low, high);
			while (low < high && n[low] <= pivotkey) {
				low++;
			}
			SortUtils.swap(n, low, high);
		}
		return low;
	}
}