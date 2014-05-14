package string;

public class WordBreak {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String s = "leetcode";
		java.util.Set<String> dict = new java.util.HashSet<String>();
		dict.add("leet");
		dict.add("code");
		System.out.println(wordBreak1(s, dict));
		System.out.println(wordBreak2(s, dict));
	}

	//时间复杂度O(2^n)
	public static boolean wordBreak1(String s, java.util.Set<String> dict) {
        return wordBreakHelper(s, dict, 0);
	}

	public static boolean wordBreakHelper(String s, java.util.Set<String> dict, int start){
	   if(start == s.length()) 
	       return true;
	
	   for(String a: dict){
	       int len = a.length();
	       int end = start+len;
	
	       //end index should be <= string length
	       if(end > s.length()) 
	           continue;
	
	       if(s.substring(start, start+len).equals(a))
	           if(wordBreakHelper(s, dict, start+len))
	               return true;
	   }
	
	   return false;
	}


	//时间复杂度O(s.length*dic.size())
	public static boolean wordBreak2(String s, java.util.Set<String> dict) {
		boolean[] t = new boolean[s.length() + 1];
		t[0] = true;
		for (int i = 0; i < s.length(); i++) {
			if (!t[i])
				continue;

			for (String a : dict) {
				int len = a.length();
				int end = i + len;
				if (end > s.length())
					continue;

				if (t[end])
					continue;

				if (s.substring(i, end).equals(a)) {
					t[end] = true;
				}
			}
		}

		return t[s.length()];
	}

}
