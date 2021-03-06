/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(1) space
class Solution {
private:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head -> next == NULL)
			return head;
		ListNode *previous = NULL, *current = head, *next = head -> next;
		while (next != NULL) {
			current -> next = previous;
			previous = current;
			current = next;
			next = next -> next;
		}
		current -> next = previous;
		return current;
	}
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head -> next == NULL)
			return true;
		// use slow and fast pointer to find the middle node
		ListNode *slow = head, *fast = head;
		while (fast != NULL && fast -> next != NULL) {
			fast = fast -> next -> next;
			slow = slow -> next;
		}
		if (fast != NULL)
			slow = slow -> next;

		ListNode *left = head, *right = reverseList(slow);
		while (right != NULL) {
			if (left -> val != right -> val)
				return false;
			left = left -> next;
			right = right -> next;
		}
		return true;
	}
};

// O(N) space
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> nums;
		ListNode *current = head;
		while (current != NULL) {
			nums.push_back(current -> val);
			current = current -> next;
		}
		for (int i = 0; i < nums.size() / 2; i++) {
			if (nums[i] != nums[nums.size() - 1 - i])
				return false;
		}
		return true;
	}
};