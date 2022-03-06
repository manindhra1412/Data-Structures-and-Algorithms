/*

    class Node {
        public :
        int data;
        Node *next;
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };
*/
// Detect loop
Node *floydetectloop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && slow != NULL)
    {
        // Fast pointer moves with 2 steps
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
// Find starting of Loop
Node *findStartofLoop(Node *head)
{
    // start slow pointer from head and intersection pointer from there intersection from floydetectloop(Node* head)
    Node *slow = head;
    Node *intersection = floydetectloop(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
// Remove/Cut the loop
void removeLoop(Node *head)
{

    if (head == NULL)
        return;
    Node *start = findStartofLoop(head);
    if (start == NULL)
        return;
    Node *prev = start;
    while (prev->next != start)
    {
        prev = prev->next;
    }
    prev->next = NULL;
}