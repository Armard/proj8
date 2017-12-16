/*
Test a char queue
*/

#include <tqueue.h>

int main()
{
	fsu::Queue<char> s;
	for(size_t i = 0; i < 26; i++)
	{
  		s.Push('a' + i);
  		std::cout << "Front " << s.Front() << '\n';
  	}
  	cout << "Size " << s.Size() << "\n";
  	cout << "Pop " << s.Pop() << "\n";
  	cout << "Pop " << s.Pop() << "\n";
  	s.Display(cout);
  	cout << "\n";

  	return 0;
}


