void List::insert(int toadd, int pos) {
    ListNode *curNode = head;
    for (int i = 0; i < pos - 1; i++) {
        curNode = curNode->next;
    }
    ListNode *newNode = new ListNode;
    newNode->data = toadd;
    newNode->next = curNode->next;
    curNode->next = newNode;
}