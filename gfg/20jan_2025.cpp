class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Edge cases: If one of the lists is empty
        if (!head1) return head2;
        if (!head2) return head1;

        // Dummy node to simplify the process
        Node* curr;
        if(head1->data<=head2->data){
            curr=head1;
            head1=head1->next;
        }
        else{
            curr=head2;
            head2=head2->next;
        }
        Node* tail = curr;

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next; 
        }

        if (head1) tail->next = head1;
        if (head2) tail->next = head2;

        return curr;
    }
};