#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
	int top = -1;
	size_t size;
	T* arr;
	Stack() {}

	void resize(size_t new_size)
	{
		T* newArray = new T[new_size];
		for (int i = 0; i <= top; i++)
		{
			newArray[i] = arr[i];
		}

		delete[] arr;
		arr = newArray;
		size = new_size;
	}

public:
	Stack(size_t cap)
	{
		size = cap;
		arr = new T[cap];
	}

	bool isFull()
	{
		return (top == size - 1);
	}

	bool isEmpty()
	{
		return (top == -1);
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "stack is empty\n";
			return;
		}
		else
		{
			top--;
		}
	}

	void push(T value)
	{
		if (isFull())
		{
			resize(size * 2);
			cout << "Stack resized to " << size << "\n";
		}
		arr[++top] = value;
	}

	T peek()
	{
		if (isEmpty())
		{
			cout << "stack is empty\n";
			return T();
		}
		//cout << "Your value now is : " << arr[top];
		return arr[top];
	}



	~Stack()
	{
		delete[] arr;
	}
};


bool ispair(char open, char close)
{
	if (open == '(' && close == ')') return true;
	if (open == '{' && close == '}') return true;
	if (open == '[' && close == ']') return true;
	return false;
}

bool areBractBalanced(string expr)
{
	Stack<char> s(10);

	for (char c : expr)
	{
		if (c == '(' || c == '{' || c == '[')
		{
			s.push(c);
		}
		else if (c == ')' || c == '}' || c == ']')
		{
			if (s.isEmpty()) { return false; }

			char lastOpen = s.peek();
			s.pop();

			if (!ispair(lastOpen, c)) { return false; }
		}
		
	}
  return s.isEmpty();
}

void check(string exp)
{
	if(areBractBalanced(exp)){cout << " Balanced \n"; }
	else{cout << " Not Balanced \n"; }

	cout << "-----------------------\n";
}


int main()
{
	check(")1=2(");
	check("{(12*9)}");
	check("{2,3,5}");
	check("{[9 * (8 / 8)] * (1 * 7)}");

	return 0;

}
