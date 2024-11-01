/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if(!llist)
        return new SinglyLinkedListNode(data); //?
    if(position == 0)
    {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        newNode->next = llist;
        return newNode;
    }
    SinglyLinkedListNode* iter = llist;
    SinglyLinkedListNode* prev = iter;

    while(iter && position)
    {
        prev = iter;

        iter = iter->next;
        position--;
    }
    
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    prev->next = newNode;
    newNode->next = iter;
    
    return llist;

}
