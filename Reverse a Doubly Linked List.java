/*
class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
*/
class Solution {
    public Node reverse(Node head) {
        // code here
        if(head == null || head.next == null)
        return head;
    
    //declaring a current and previous node
    Node curr = head, prev = null;
    
    //looping through the list
    while(curr != null){
        //storing the previous node in prev
        prev = curr.prev;
        //swapping the prev and next pointers of the current node
        curr.prev = curr.next;
        curr.next = prev;
        
        //moving the current node to its previous node
        curr = curr.prev;
    }
    //returning the previous node of head as the new head (the last node after reversing the list)
    return prev.prev;
    }
}
