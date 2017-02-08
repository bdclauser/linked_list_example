#include <iostream>
#include "minilist.h"

using namespace std;

template <typename T>
bool isPalindrome(const miniList<T>& item)
{
	miniList<T> temp;
	temp = item;		//creates a copy of the original

	while (temp.size() > 1)
	{
		if (temp.front() != temp.back())
			return false;
		temp.removeFromBack();
		temp.removeFromFront();
	}
	return true;
}

void main()
{
	miniList<char> mList;

	mList.insertAtFront('c');
	mList.insertAtFront('a');
	mList.insertAtFront('r');
	mList.insertAtBack('e');
	mList.insertAtBack('c');
	mList.insertAtBack('a');
	mList.insertAtBack('r');

	mList.print();
	cout << (isPalindrome(mList) ? "Paladrome" : "Not Paladrome") << endl;
	mList.removeFromBack();
	mList.print();
	cout << (isPalindrome(mList) ? "Paladrome" : "Not Paladrome") << endl;

	mList.print();
	cout << "The front letter is " << mList.front() << endl;
	cout << "The back letter is " << mList.back() << endl;
	cout << "The size is " << mList.size() << endl;
}