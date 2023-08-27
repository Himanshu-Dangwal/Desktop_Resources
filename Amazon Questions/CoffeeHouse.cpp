#include<bits/stdc++.h>
using namespace std;

class CoffeeHouse{
  
  public:
  	
  	unordered_map<string,int> mp;
  	vector<string> coffees;
  	vector<string> add_on;
  	vector<string> coffee_ordered;
	vector<string> addOn_taken;
	vector<int> prices;
	int total = 0;
	int cost[3][3];
  	void init(){
	  
	  	coffees.push_back("Expresso");
	  	coffees.push_back("Capucchino");
	  	coffees.push_back("Latte");
	  
	  	
	  	add_on.push_back("Milk");
	  	add_on.push_back("Cream");
	  	add_on.push_back("Latte");	
	  
	  	
	  	mp["Expresso"] = 0;
	  	mp["Capucchino"] = 1;
	  	mp["Latte"] = 2;
	  	mp["Milk"] = 0;
	  	mp["Cream"] = 1;
	  
	  	
	  
	  	cost[0][0] = 60; cost[0][2] = 100; cost[1][0] = 80; cost[1][1] = 90; cost[1][2] = 125;
	  	cost[0][1] = 75; cost[2][0] = 100; cost[2][1] = 125; cost[2][2] = 150;
	  	

  	}
  	void add_item(){
  	  cout<<"Enter the coffee name"<<endl;
      string cof;
      cin>>cof;
      
      coffee_ordered.push_back(cof);
      
      cout<<"Enter the add_on name"<<endl;
      string add;
      cin>>add;
      addOn_taken.push_back(add);
      
      int val = cost[mp[cof]][mp[add]];
      prices.push_back(val);
      total += val;
    }
  
  	void remove_item(){
      coffee_ordered.pop_back();
      addOn_taken.pop_back();
      int val = prices.back();
      prices.pop_back();
      total -= val;
    }
  
  	void display_total(){
      
      cout<<"Items ordered are"<<endl;
      
      for(int i=0;i<coffee_ordered.size();i++){
        cout<<coffee_ordered[i]<<" "<<addOn_taken[i]<<" "<<prices[i]<<endl;
      }
      
      cout<<"Total = "<<total;
      
    }
  
  	
};

int main(){
  CoffeeHouse obj;
  obj.init();
  
  int selection;

  do{
	system("cls");
	
	cout<<"                         Items available to order"<<endl<<endl<<endl;
  
  	cout<<"Product/Add-on    Milk    Cream    Latte"<<endl<<"Expresso          60      75       100"<<endl<<"Cappuccino        80      90         125"<<endl;
  	cout<<"Latte             100     125      150"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"Select one of the options below"<<endl;
  	cout<<"1. Add item to your list"<<endl;
  	cout<<"2. Remove item from your list"<<endl;
  	cout<<"3. Show the final bill"<<endl;
  	cout<<"4. Quit"<<endl;
  	cin>>selection;
    switch(selection){
      case 1:
        obj.add_item();
        break;
      
      case 2:
        obj.remove_item();
        break;
        
      case 3:
        obj.display_total();
        cout<<endl<<endl;
        cout<<"Press a number to start selection"<<endl;
        int x;
        cin>>x;
        
        break;
      
      case 4:
        break;
    }
  }while(selection != 4);
  
  system("cls");
  obj.display_total();
  return 0;
}
















