/*
Test a int queue
*/

#include <tqueue.h>

int main()
{
	fsu::Queue<int> s;
	for(size_t i = 0; i < 100; i++)
	{
  		s.Push(i);
  		std::cout << "Front " << s.Front() << '\n';
  	}
  	cout << "Size " << s.Size() << "\n";
  	cout << "Pop " << s.Pop() << "\n";
  	cout << "Pop " << s.Pop() << "\n";
    s.SetOFC(' ');
  	s.Display(cout);
  	cout << "\n";

  	return 0;
}


