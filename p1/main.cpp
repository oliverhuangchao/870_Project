#include <iostream>
#include <cstring>
using namespace std;
class Food
{
	private:
		int Price;
		char *color;
		static int LocationNumber;
	public:
		Food();
		Food(const Food &newFood);
		Food& operator=(const Food &newFood);
		Food& operator+(const Food &newFood);
		Food& operator-(const Food &newFood);

		const int getPrice() const;
		void setPrice(int Price);
		
		static void setLocationNumber(int newValue){LocationNumber = newValue;}
		static int getLocationNumber(){return LocationNumber;}
		
		void setColor( char * newstring);
		const char* getColor() const;

		~Food();
};

int Food::LocationNumber = 0;

Food::Food(){
	Price = 0;
	color = new char[100];
}

Food::Food(const Food &newFood)
{
	color= new char[strlen(newFood.color)+1];
	strcpy(color,newFood.color);
	Price = newFood.getPrice();
}

Food::~Food()
{
	delete [] color;
}

const int Food::getPrice() const {
	return Price;
}

void Food::setPrice(int newPrice){
	Price = newPrice;
}

void Food::setColor(char* aaa)
{
	delete []color;
	color = new char [strlen(aaa)];
	strcpy(color,aaa);
}
const char* Food::getColor() const {
	return color;
}



Food& Food::operator=(const Food& newFood){
	if (this == &newFood) return *this;
	delete []color;
	color = new char[strlen(newFood.color)+1];
	strcpy(color, newFood.color);
	Price = newFood.getPrice();
	return *this;
}

ostream& operator<<(ostream& out, const Food& newFood){
	out<<"Food's Price is "<<newFood.getPrice()<<"~~~~~~~~"<<"Food's LocationNumber is "<<newFood.getLocationNumber()<<"~~~~~~~~~~~~"<<newFood.getColor()<<endl;
	return out;
}

Food& Food::operator+(const Food &newFood)
{
	Price = Price + newFood.getPrice();
	return *this;
}

Food& Food::operator-(const Food &newFood)
{
	Price = Price-newFood.getPrice();
	return *this;
}

int main()
{
	Food food_1;
	string tmp = "red";
	food_1.setColor(&tmp[0]);
	cout<<food_1;
	

	Food food_2(food_1);
	food_2.setPrice(20);
	food_2 = food_2+food_1;
	tmp = "greem";
	food_2.setColor(&tmp[0]);
	cout<<food_2;

	Food food_3;
	food_3 = food_1;
	food_3.setPrice(30);
	food_3.setLocationNumber(100);
	food_3 = food_3-food_1;
	cout<<food_3;	

	return 1;
}