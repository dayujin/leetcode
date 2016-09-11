/*
*	INFORMATION
*
*	addtwonumbers
*	Leetcode algorithm task 3
*	By Dayu Jin
*	Time: 09/11/2016
*
*
*	DOCUMENTATION
*
*	** Tags **
*	1. hashmap contain
*	2. hashmap remove(sliding window)
*	3. (O(n), O(1))
*/		

public class Solution {
    public int lengthOfLongestSubstring(String s) {

        /* Create a new hashmap*/
		Map<Character, Integer> map = new HashMap<>();
		int len = 0, sptr = 0, ptr = 0, clen = 0;

		/* Search the string*/
		while(ptr < s.length()) 
		{
			if(map.containsKey(s.charAt(ptr))) 
			{
				len = (len < clen) ? clen : len;
				int tptr = map.get(s.charAt(ptr));
				while(!(sptr > tptr)) 
				{
					map.remove(s.charAt(sptr));
					clen --;
					sptr ++;
				}
			}
			map.put(s.charAt(ptr), ptr);
			clen ++;
			ptr ++;
		}

		len = (len < clen) ? clen : len;
		return len;
    }
}
