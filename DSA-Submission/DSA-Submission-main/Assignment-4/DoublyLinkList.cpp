class Node
{
public:
  int data;
  Node *next;
  Node *pre;
  Node()
  {
    data = 0;
    pre = NULL;
    next = NULL;
  }
  Node(int x)
  {
    data = x;
    pre = NULL;
    next = NULL;
  }
  Node(int x, Node *p, Node *n)
  {
    data = x;
    pre =
        p;
    next = n;
  }
};
Node *insertAtFirst(Node *list, int newValue)
{

  Node *head = list;
  Node *a = new Node(newValue, head);
  head = a;
  return head;
}
Node *deleteLastNode(Node *head)
{

  Node *ptr = head;
  if (head->next == nullptr)
  {
    return nullptr;
  }
  Node *temp = nullptr;
  while (ptr->next != nullptr)
  {
    temp = ptr;
    ptr = ptr->next;
  }
  temp->next = nullptr;
  ptr->prev = nullptr;
  return head;
}
Node *reverseDLL(Node *head)
{
  Node *ptr = head;
  Node *newhead = NULL;
  while (ptr != NULL)
  {
    int deta = ptr->data;
    if (newhead == NULL)
    {
      Node *a = new Node(deta);
      newhead = a;
    }
    else
    {
      Node *a = new Node(deta);
      a->next = newhead;
      newhead->prev = a;
      newhead = a;
    }
    ptr = ptr->next;
  }
  return newhead;
}