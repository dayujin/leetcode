/*
*	INFORMATION
*
*	3SumClosest
*	Leetcode algorithm task 16
*	By Dayu Jin
*	Time: 09/02/2016
*
*
*	DOCUMENTATION
*
*	** Problem **
*		* Question *
*			1. Given an array S of n integers, find three integers in S such that 
*			the sum is closest to a given number, target. 
*			2. Return the sum of the three integers. 
*			3. You may assume that each input would have exactly one solution.
*		* Input *
*			1. Array of given numbers
*			2. Num of given numbers(Might be implicit)
*			3. Target value
*		* Output *
*			1. Sum of the three integers. 
*
*	** Solution **
*		* Idea *
*			1. Same idea as 3Sum Closest by using two pointers.
*		* Method for Idea *
*			1. Define the difference between sum and target, initializing it to maximum
*			2. Sort the input array {O(nlogn), O(1)}
*			3. Perform twoSum for each given number in input array {O(n^2), O(1)}
*			31.compute the temp difference(sum-target) and if its absolute value is fewer 
*			than original difference, make temp difference original. 
*			31.case1(sum < target) move forward start pointer
*			32.case2(sum > target) move backword end pointer
*			33.case3(sum == target) return target
*			4. Return target + original difference
*/

/* A JAVA Solution*/
public class Solution
{
	public int threeSumClosest(int[] nums, int target)
	{
		/* Declare original and temp difference*/
		int oridiff = Integer.MAX_VALUE;
		int tempdiff;
		/* Sort the Array*/
		Arrays.sort(nums);

		/* Perform twoSum for each given number in input array*/
		int firstnum, secondnum, thirdnum;
		int startpt, endpt;
		for (int i = 0; i < nums.length - 2; i++)
		{
			firstnum = nums[i];
			startpt = i + 1;
			endpt = nums.length - 1;
			while (startpt < endpt)
			{
				secondnum = nums[startpt];
				thirdnum = nums[endpt];
				tempdiff = firstnum + secondnum + thirdnum - target;
				if (Math.abs(tempdiff) < Math.abs(oridiff))
					oridiff = tempdiff;
				if (tempdiff < 0) // case1
					startpt++;
				else if (tempdiff > 0) // case2
					endpt--;
				else // case3
					return target;
			}
		}
		/* Return the result*/
		return oridiff + target;
	}
}