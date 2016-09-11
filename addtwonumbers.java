/*
*	INFORMATION
*
*	addtwonumbers
*	Leetcode algorithm task 2
*	By Dayu Jin
*	Time: 09/11/2016
*
*
*	DOCUMENTATION
*
*	** Tags **
*	1. understand singly linked-list (how to memorize its start)
*	2. understand carry
*	3. the use of 0 for a null list
*		

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        ListNode lstart = new ListNode(0);
        ListNode lmid = new ListNode(0);
        ListNode lnode = new ListNode(0);
        int result, carry = 0;
        int isstart = 1;

        if(l1 == null && l2 == null)
        	return null;
        else if(l1 == null)
        	return l2;
        else if(l2 == null)
        	return l1;

        while(l1 != null && l2 != null)
        {
        	result = (l1.val + l2.val + carry) % 10;
        	carry = (l1.val + l2.val + carry) / 10;
        	lnode.next = new ListNode(result);
        	if(isstart == 1) {
        		lstart = lnode;
        		isstart = 0;
        	}

        	l1 = l1.next;
        	l2 = l2.next;
        	lnode = lnode.next;
        }

        if(l1 != null)
        	lmid = l1;
        else if(l2 != null)
        	lmid = l2;
        else {
        	if(carry == 1) 
        		lnode.next = new ListNode(1);
        	return lstart.next;
        }

        while(lmid != null)
        {
        	result = (lmid.val + carry) % 10;
        	carry = (lmid.val + carry) / 10;
        	lnode.next = new ListNode(result);
        	lmid = lmid.next;
        	lnode = lnode.next;
        }
        if(carry == 1) 
        		lnode.next = new ListNode(1);
        return lstart.next;
    }
}

public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}