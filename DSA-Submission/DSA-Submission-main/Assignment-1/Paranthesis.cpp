int cheakPerenthesis(String str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == '{' || str[i] == '[' || str[i] == '(')
    {
      push(str[i]);
    }
    else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
    {
      char temp = pop();
      if (temp == '{' && str[i] == '}' || temp == '[' && str[i] == ']' || temp == '(' && str[i] == ')')
      {
      }
      else
      {
        cout << "perenthesis check wrong!\n";
        return 0;
      }
    }
  }
  if (isempty())
  {
    cout << "perenthesis check complet!\n";
    return 1;
  }
  else
  {
    cout << "perenthesis check wrong!\n";
    return 0;
  }
}