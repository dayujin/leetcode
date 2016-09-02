/*
*	INFORMATION
*
*	3Sum
*	Leetcode algorithm task 15
*	By Dayu Jin
*	Time: 09/01/2016
*
*
*	DOCUMENTATION
*
*	** Problem **
*		* Question *
*			1. Given an array S of n integers, are there elements a, b, c in S
*			such that a + b + c = 0?
*			2. Find all unique triplets in the array which gives the sum of zero.
*			3. The solution set must not contain duplicate triplets.
*		* Input *
*			1. Array of given numbers
*			2. Num of given numbers(Might be implicit)
*		* Output *
*			1. 2D Array contains all suitable tripples
*
*	** Solution **
*		* Idea *
*			1. In this case, we will not consider the brutal force method since
*			its T = O(n^3) which is somewhat unacceptable.
*			2. For each given number in the array, we can perform a twoSum for it,
*			since in this case, multiple same numbers may occur, hashmap is not a
*			direct way for solving this, therefore we use two pointers to tackle this
*			problem.
*			3. The core idea of using two pointers is simple. Given a sorted array and
*			a target, we can set two pointers one at front and one at the end and we know
*			the sum of the two elements these pointers pointed to. Since the array is
*			sorted, by computing the difference between target and sum, we can decide on
*			how to move those pointers. Finally, in each iteration, at least one pointer
*			will be moved toward the other and it will converge within O(n).
*		* Challenge*
*			1. Same number can appear multiple times but the result needs to be exclusive.
*			2. Strict time limitation is imposed on the eliminatation of same results.
*		* Method for Idea *
*			1. Define the Return List {O(1), O(1)}
*			2. Sort the input array {O(nlogn), O(1)}
*			3. Perform twoSum for each given number(number value different) in input array {O(n^2), O(n^2)}
*			31.case1(sum < target) move forward start pointer
*			32.case2(sum > target) move backword end pointer
*			33.case3(sum == target)record result and move both pointers to a new num value
*			4. Return the result {O(1), O(1)}
*/

/* A JAVA Solution*/

public class Solution
{
	public List<List<Integer>> threeSum(int[] nums)
	{
		/* Define the Return List*/
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		/* Sort the input array*/
		Arrays.sort(nums);

		int firstnum, secondnum, thirdnum; // three numbers
		int startpt, endpt; // two pointers

		/* Perform twoSum for each given number*/
		for (int i = 0; i < nums.length - 2; i++)
		{
			/* Move to a new num value*/
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			firstnum = nums[i];
			startpt = i + 1;
			endpt = nums.length - 1;
			/* Converge process*/
			while (startpt < endpt)
			{
				secondnum = nums[startpt];
				thirdnum = nums[endpt];

				if (firstnum + secondnum + thirdnum < 0) // case1
					startpt++;
				else if (firstnum + secondnum + thirdnum > 0) // case22
					endpt--;
				else // case3
				{
					ArrayList<Integer> list = new ArrayList<Integer>();
					list.add(firstnum);
					list.add(secondnum);
					list.add(thirdnum);
					result.add(list);
					/* Move to a new num value*/
					while (startpt < endpt && nums[startpt] == nums[startpt + 1]) startpt++;
					while (startpt < endpt && nums[endpt] == nums[endpt - 1]) endpt--;
					startpt++;
					endpt--;
				}
			}
		}
		/* Return the result*/
		return result;
	}
}