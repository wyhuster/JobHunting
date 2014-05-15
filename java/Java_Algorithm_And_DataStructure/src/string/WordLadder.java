package string;


/*
 * @description 给定两个单词和一个词典，每次单词中只是替换一个char，找出最短的替换次数.
 * @solution 可以使用按照这种规则连接成图，然后求最短路径.
 */
public class WordLadder {

	public static void main(String[] args) {
		String start = "a";
		String end="c";
		java.util.HashSet<String> dic = new java.util.HashSet<String>();
		dic.add("a");
		dic.add("b");
		dic.add("c");
		System.out.println(ladderLength(start, end, dic));
		
	}

	//有问题.
	public static int ladderLength(String start, String end,
			java.util.Set<String> dic) {
		if (dic.size() == 0) {
			return 0;
		}
		java.util.LinkedList<String> wordQueue = new java.util.LinkedList<String>();
		java.util.LinkedList<Integer> distanceQueue = new java.util.LinkedList<Integer>();

		wordQueue.add(start);
		distanceQueue.add(1);

		while (!wordQueue.isEmpty()) {
			String currWord = wordQueue.pop();
			int currLength = distanceQueue.pop();

			if (currWord.equals(end)) {
				return currLength;
			}
			char[] currWordArr = currWord.toCharArray();
			for (int i = 0; i < currWord.length(); i++) {
				for (char c = 'a'; c < 'z'; c++) {
					currWordArr[i] = c;
					String newWord = new String(currWordArr);
					if (dic.contains(newWord)) {
						wordQueue.add(newWord);
						distanceQueue.add(currLength + 1);
						dic.remove(newWord);
					}
				}
			}
		}
		return 0;
	}
}
