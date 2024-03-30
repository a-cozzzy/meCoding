// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* current = d;
//     int carry = 0;

//     while (l1 || l2 || carry) {
//         int val1 = (l1 != NULL) ? l1->val : 0;
//         int val2 = (l2 != NULL) ? l2->val : 0;

//         int totalSum = val1 + val2 + carry;
//         carry = totalSum / 10;

//         struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//         newNode->val = totalSum % 10;
//         newNode->next = NULL;

//         current->next = newNode;
//         current = current->next;


//         if (l1 != NULL) {
//             l1 = l1->next;
//         }
//         if (l2 != NULL) {
//             l2 = l2->next;
//         }
//     }

//     struct ListNode* resultHead = d->next;

//     free(d);
    

//     return resultHead;
// }
