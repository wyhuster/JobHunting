package search;

import static net.mindview.util.Print.*;

public class Matrix {

	public static void main(String[] args) {
		int[][] n = {{1,2,8,9,},{2,4,9,12,},{4,7,10,13,},{6,8,11,15,},};
		print(find(n, 15));
	}

	//在二维数组中查找某个元素
	//先决条件：二维数组从每行从左到右升序排列，没列从上到下升序排列.
	//查找过程中，每次拿右上角的数字与num进行比较，若大则去掉该列，若小则去掉该行.
	public static boolean find(int[][] n, int num) {
		boolean found = false;
		int rows = n.length;
		int columns = n[0].length;

		if (n != null && rows > 0 && columns > 0) {
			int row = 0;
			int column = columns - 1;
			while (row < rows && column < columns) {
				if (n[row][column] == num) {
					found = true;
					print("找到数据在第" + (row+1) + "行，第" + (column+1) + "列");
					break;
				} else if (n[row][column] > num)
					--column;
				else
					++row;
			}
		}
		return found;
	}

}
