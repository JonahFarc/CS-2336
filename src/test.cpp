/*
 * test.cpp
 *
 *  Created on: Nov 11, 2016
 *      Author: Korbo
 */

#include "Queue.h"
#include "Stack.h"

int main()
{
	Stack<int> stack = Stack<int>();
	stack.push(5);
	stack.push(7);
	stack.push(8);
	stack.push(4);
	stack.pop();
	stack.debug(std::cout);
	auto stacky(stack);
	//stacky.pop();
	stacky.debug(std::cout);

	Queue<int> queue = Queue<int>();
	queue.push(5);
	queue.push(7);
	queue.push(8);
	queue.push(4);
	queue.debug(std::cout);
	auto queuey(queue);
	queuey.pop();
	queuey.debug(std::cout);
}
