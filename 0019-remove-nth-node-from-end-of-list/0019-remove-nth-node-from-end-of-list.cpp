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
private:
    ListNode* bruteForceApproach(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int cnt=0;
        ListNode* temp=head;
        // Then find Length of the LL
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        // If the given node is the head of LL
        if(cnt==n){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        int restNode=cnt-n;
        while(temp!=NULL){
            restNode--;
            if(restNode==0){
                break;
            }
            temp=temp->next;
        }
        ListNode* delNode=temp->next;
        temp->next=temp->next->next;
        delete(delNode);
        return head;
    }
    ListNode* optimalApproach(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* delNode= slow->next;
        slow->next=slow->next->next;
        delete(delNode);
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // return bruteForceApproach(head,n);
        return optimalApproach(head,n);
    }
};