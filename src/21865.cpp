void List::remove(int pos) {
    ListNode *curNode = head;
    for (int i = 0; i < pos - 1; i++) {
        curNode = curNode->next;
    }
    ListNode *byebye = curNode->next;
    curNode->next = curNode->next->next;
    delete byebye;
}