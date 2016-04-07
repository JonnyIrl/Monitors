#include "BoundedBuffer.h"
#include <iostream>
using namespace std;

BoundedBuffer::BoundedBuffer()
{
	n = 10;	
	use = fill = count = fullEntries = 0;
	notfull = SDL_CreateSemaphore(1);
	notempty = SDL_CreateSemaphore(1);
}

BoundedBuffer::~BoundedBuffer()
{
}

int BoundedBuffer::Fetch()
{
	while (fullEntries == 0)
	{
		SDL_SemWait(notempty);
	}
	
	int tmp = buffer[use];
	use = (use + 1) % n;
	fullEntries--;

	cout << "Just took an element" << endl << "Count =  " << fullEntries << endl;

	SDL_SemPost(notfull);
	return tmp;
}

void BoundedBuffer::Deposit(int element)
{
	while (fullEntries == n)
	{
		SDL_SemWait(notfull);
	}

	buffer[fill] = element;
	fill = (fill + 1) % 10;
	fullEntries++;

	cout << "Added new element to be removed.." << "Count =  " << fullEntries << endl;
	SDL_SemPost(notempty);
}