#pragma once
#ifndef BOUNDEDBUFFER_H
#define BOUNDEDBUFFER_H


#include <SDL.h>
class BoundedBuffer
{
public:
	BoundedBuffer();
	~BoundedBuffer();
	void Deposit(int element);
	int Fetch();
	void AddNewItem();
	void RemoveItem();

private:
	int buffer[10];
	int fill, use;
	int fullEntries;
	int count;
	int n;
	//sf::Mutex monitor;  // monitor lock

	SDL_sem* notempty = NULL;
	SDL_sem* notfull = NULL;

};

#endif
