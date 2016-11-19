/*
 * test.cpp
 *
 *  Created on: Nov 11, 2016
 *      Author: Korbo
 */

#include "Queue.h"
#include "Stack.h"
#include <iostream>

int main()
{
	Stack<int> stack = Stack<int>();
	std::cout<<stack.empty()<<"\n";
	stack.push(5);
	stack.push(7);
	std::cout<<stack.size()<<" "<<stack.top()<<"\n";
	stack.push(8);
	stack.push(4);
	stack.pop();
	stack.debug(std::cout);
	auto stacky(stack);
	stacky.pop();
	stacky.push(3);
	stacky.debug(std::cout);

	Queue<int> queue = Queue<int>();
	std::cout<<queue.empty()<<"\n";
	queue.push(5);
	queue.push(7);
	std::cout<<queue.size()<<" "<<queue.front()<<" "<<queue.back()<<"\n";
	queue.push(8);
	queue.push(4);
	queue.debug(std::cout);
	auto queuey(queue);
	queuey.pop();
	queuey.push(3);
	queuey.debug(std::cout);
}
