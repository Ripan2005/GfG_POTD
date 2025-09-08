/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* mergeSort(Node* head) {
        // code here
        if (!head || !head->next) return head;

        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;
        middle->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);

        return sortedMerge(left, right);
    }

private:
    Node* getMiddle(Node* head) {
        if (!head) return head;
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* sortedMerge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        
        if (a->data <= b->data) {
            a->next = sortedMerge(a->next, b);
            return a;
        } else {
            b->next = sortedMerge(a, b->next);
            return b;
        }
    }
};
