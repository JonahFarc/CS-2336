/*
 * receipt.h
 *
 *  Created on: Sep 24, 2016
 *      Author: Dylan Yu
 */

#ifndef RECEIPT_H_
#define RECEIPT_H_

#include "drinkitem.h"

class Receipt
{
private:
	std::string state;
	double change;
public:
	Receipt();
	Receipt(std::string state);
	Receipt(double change);
	bool success() const;
	bool insufficient() const;
	bool empty() const;
	double getChange() const;
};

#endif /* RECEIPT_H_ */
