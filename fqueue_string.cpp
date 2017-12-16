/*
Test a char queue
*/

#include <tqueue.h>
#include <string>

int main()
{
	fsu::Queue<std::string> s;
	for(size_t i = 0; i < 26; i++)
	{
    std::string p = "";
    p.append(1, 'a' + i%26);
    p.append(1, 'a' + (i+1)%26);    
    p.append(1, 'a' + (i+2)%26);
		s.Push(p);
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


