class Node
{
public:
  int data;
  Node *next;
  Node()
  {
    data = 0;
    next = NULL;
  }
  Node(int x)
  {
    data = x;
    next = NULL;
  }
  Node(int x, Node *next)
  {
    data = x;
    next = next;
  }
};
Node *insertAtFirst(Node *list, int newValue)
{

  Node *head = list;
  Node *a = new Node(newValue, head);
  head = a;
  return head;
}
Node *deleteLast(Node *list)
{
  Node *head = list;
  Node *ptr = head;
  Node *temp = nullptr;
  while (ptr->next != nullptr)
  {
    temp = ptr;
    ptr = ptr->next;
  }
  temp->next = nullptr;
  return head;
}
int length(Node *head)
{
  int count = 0;
  Node *ptr = head;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    count++;
  }
  return count;
}
int searchInLinkedList(Node *head, int k)
{
  Node<int> *ptr = head;
  while (ptr != NULL)
  {
    if (ptr->data == k)
    {
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}