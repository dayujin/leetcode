/*
***************************************************************************
*								twoSum                                        
*                       Leetcode algorithm task one                           
*						By Dayu Jin    Time: 08/31/2016                           
*                                                                            
*  ************************************************************************  
*								DOCUMENTATION                                
*	** Problem **   
*		* Question *
*			1. Given an array of integers, return indices of the two numbers 
*			such that they add up to a specific target.
*			2. You may assume that each input would have exactly one solution.
*		* Input *
*			1. Array of given numbers
*			2. Num of given numbers(Might be implicit)
*			3. The specific added up target
*		* Output *
*			1. Indices of the two numbers
*  
*  ************************************************************************
*	** Solution **
*		* Idea *
*			1. A straightforward method is to use 2D loops, while the outer 
*			loop stops at an array slot, the inner loop go through all members
*			after it to find the fit.
*			2. While using OOP, hashtable could be a better choice which is
*			a tradeoff of time and space.
*		* Method for Idea1 *
*			1. Malloc a space for the return array {O(1), O(1)}
*			2. 2D loop {O(n^2), O(1)}
*			3. Return the result {O(1), O(1)}
*		* Method for Idea2 *
*			1. Create a new hashmap {O(1), O(1)}
*			2. Put all elements in the hashmap {O(n), O(n)}
*			3. 1D loop {O(n), O(1)}
*			4. Return the result {O(1), O(1)}
*                                                                          
***************************************************************************
*/

/* A brutal force C solution*/
int* twoSum(int* nums, int numsSize, int target) {

	int *rnums; //return array
	/* Malloc a space for the return array*/
	rnums = malloc(sizeof(int)*2);

	/* 2D loop*/
	int temp;
	for (int i = 0; i < numsSize; i++)
	{
		temp = nums[i];
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[j] + temp == target) // if find fit
			{
				rnums[0] = i;
				rnums[1] = j;
				return rnums; // Return the result
			}
		}
	}
	/* Not find fit*/
	return rnums;
}

/* A Clever JAVA Solution*/
public class Solution 
{
	public int[] TwoSum(int[] nums, int target) 
	{

		/* Create a new hashmap*/
		Map<integer, integer> map = new Hashmap<>();
		
		/* Put items in array into hashmap*/
		for (int i = 0; i < nums.length; i++) 
		{
			map.put(nums[i], i);
		}

		/* 1D loop*/
		int complement;
		for (int i = 0; i < nums.length; i++)
		{
			complement = target - nums[i];
			if ((map.containsKey(complement)) && (map.get(complement) != i))
				return new int[]{i, map.get(complement)}; // return results
		}
		/* No solution*/
		throw new IllegalArgumentException("No two sum solution");
	}
}