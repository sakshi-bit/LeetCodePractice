/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Approach 1
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        vector<int>arr;
        ListNode *temp = head;
        int n=0;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
            n++;
        }

        swap(arr[k-1],arr[n-k]);

        temp=head;
        int i=0;
        while(temp){
            temp->val = arr[i];
            temp=temp->next;
            i++;
        }
        return head;
       
    }
};

//Approach 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode *head){
        int length=0;
        while(head!=NULL){
          
            head=head->next;
              length++;
        }
        return length;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        int length = findLength(head);

        int k1 = k;
        ListNode *node1 = head;
        while(k1>1){
            node1=node1->next;
            k1--;
        }

        int k2 = length-k+1;
        ListNode *node2 = head;
        while(k2>1){
            node2=node2->next;
            k2--;
        }

        swap(node1->val,node2->val);
        return head;

    }
};

//Approach 3

//optimized Approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode *p1 = NULL;
        ListNode *p2 = NULL;

        ListNode *temp = head;

        while(temp!=NULL){
            if(p2!=NULL){
                p2=p2->next;
            }
            k--;
            if(k==0){
                p1=temp;
                p2=head;
            }
            temp=temp->next;
        }
        swap(p1->val,p2->val);

        return head;
        
    }
};
