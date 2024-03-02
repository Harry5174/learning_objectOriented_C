#include <iostream>
#include <vector>

using namespace std;

class Product {
	int productId;
	string name;
	double price;
	string description;
	
	public:
		Product() : productId(0) , price(0.0) {}
		
		Product(int prid, string nm, double prce, string dsc)
			: productId(prid) , name(nm) , price(prce) , description(dsc) {};
		
		int getProductId() const;
		void setProductId(int);
		
		string getName() const;
		void setName(const string&);
		
		double getPrice() const;
		void setPrice(const double);
		
		string getDescription() const;
		void setDescription(const string&);
		
		string getProductDetails();
};

int Product::getProductId() const
{
	return productId;
}
void Product::setProductId(int id) {
	productId = id;
}

string Product::getName() const
{
	return name;
}
void Product::setName(const string& productName) {
	name = productName;
}

double Product::getPrice() const
{
	return price;
}
void Product::setPrice(const double productPrice) {
	if(productPrice >= 0.0)
	{
		price = productPrice;
	}
	else {
		cerr << "Error: Invalid price. Price cannot be negative." << endl;
	}
}

string Product::getDescription() const
{
	return description;
}
void Product::setDescription(const string& productDescription) {
	description = productDescription;
}

string Product::getProductDetails()
{
	return to_string(productId) + ' ' + name + ' ' + to_string(price) + ' ' + description;
}

class ShoppingCart
{
	string bankName;
    string branch;
	vector<Product> cartItems;
	
	public:
		void addProduct(const Product &product)
		{
			cartItems.push_back(product);
		}
		
		double calculateTotalPrice()
		{
			double totalPrice = 0.0;
			
			for (const Product &product : cartItems)
			{
				totalPrice += product.getPrice();
			}
			return totalPrice;
		}
		
		void displayCartContents() const {
        cout << "Shopping Cart Contents:" << endl;
        for (const Product &product : cartItems) {
            cout<< "Product ID: " << product.getProductId() 
				<< ", Name: " << product.getName()
                << ", Price: $" << product.getPrice() 
				<< ", Description: " << product.getDescription() << endl;
        }
    }
};

int main(int argc, char* argv[]) {
	if (argc % 3 != 1)
	{
		cerr << "Usage: " << argv[0] << " <productId1> <productName1> <productPrice1> <productId2> <productName2> <productPrice2> ..."
             << endl;
        return 1;
	}
	
	ShoppingCart userCart;
	
	for (int i = 1; i < argc ; i+=3)
	{
		int productId = stoi(argv[i]);
		string productName = argv[i+1];
		double productPrice = stod(argv[i+2]);
		
		Product product(productId, productName, productPrice, "No Description provided");
		userCart.addProduct(product);
	}
	
	cout<<"Initial Cart Contents:"<<endl;
	userCart.displayCartContents();
	cout<<"Total Price: $ "<<userCart.calculateTotalPrice()<<endl;
	
	Product additionalProduct(100, "Additional Product", 49.99, "New product for testing");
    userCart.addProduct(additionalProduct);
    
    Product anotherProduct(200, "Another Product", 60.99, "Another New product for testing");
    cout<<"\n2nd Product Details: "<<anotherProduct.getProductDetails();
    userCart.addProduct(anotherProduct);
    
    cout << "\n\nUpdated Cart Contents:" << endl;
    userCart.displayCartContents();
    cout << "Total Price: $ " << userCart.calculateTotalPrice() << endl;
	
	return 0;
}