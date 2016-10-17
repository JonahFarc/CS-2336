#include <iostream>

class Rectangle
{
protected:
	int length;
	int width;
public:
	Rectangle(){
		length = 0;
		width = 0;
	}
	Rectangle(int len = 0, int wid = 0)
	{
		length = len;
		width = wid;
	}
	virtual ~Rectangle(){}
	virtual int getArea() const
	{
		return length*5;
	}
	int getLength() const
	{
		return length;
	}
	int getWidth() const
	{
		return width;
	}
	void setLength(int len)
	{
		length = len;
	}
	void setWidth(int wid)
	{
		width = wid;
	}
	Rectangle operator+(const Rectangle other)
	{
		std::cout<<"RECTANGLE OPERATOR PLUS\n";
		return Rectangle(length + other.getLength(), width+other.getWidth());
	}
	Rectangle operator*(int num)
	{
		return Rectangle(length* num, width* num);
	}
	friend std::ostream &operator<<(std::ostream &output, const Rectangle rectangle)
	{
		output<<"("<<rectangle.getLength()<<", "<<rectangle.getWidth()<<")";
		return output;
	}
	friend std::istream &operator>>(std::istream &input, Rectangle rectangle)
	{
		int len;
		int wid;
		input>>len>>wid;
		rectangle.setLength(len);
		rectangle.setWidth(wid);
		return input;
	}
};
class Square : public Rectangle
{
public:
	Square(int sideLength=0) : Rectangle(sideLength, sideLength)
	{
		length = sideLength;
	}
	virtual ~Square(){}
	int getWidth() const
	{
		return length;
	}
	void setWidth(int wid)
	{
		length = wid;
	}
	int getArea() const
	{
		return length * 3;
	}
	Rectangle operator+(const Rectangle other)
	{
		std::cout<<"SQUARE OPERATOR PLUS\n";
		return Rectangle(length + other.getLength(),length + other.getWidth());
	}

	Square operator+(const Square other)
	{
		std::cout<<"SQUARE SQUARE OPERATOR PLUS\n";
		return Square(length+other.getLength());
	}
	friend std::ostream &operator<<(std::ostream &output, const Square rectangle)
	{
		output<<"I'm a square!";
		operator<<(output, (Rectangle)rectangle);
		return output;
	}
	friend std::istream &operator>>(std::istream &input, Square rectangle)
	{
		int len;
		input>>len;
		rectangle.setLength(len);
		return input;
	}
};
int main()
{
	Rectangle rectangle = Rectangle(5,7);
	std::cout<<rectangle<<"\n";
	rectangle = rectangle * 5;
	std::cout<<rectangle<<"\n";
	rectangle * 5;
	std::cout<<rectangle<<"\n";
	Square square(5);
	std::cout<<square<<"\n";
	Rectangle xd = (square + rectangle);
	std::cout<<xd<<"\n";
	std::cout<< square.getArea()<<"\n";
	std::cout<< square.Rectangle::getArea()<<"\n";
	return 0;
}
