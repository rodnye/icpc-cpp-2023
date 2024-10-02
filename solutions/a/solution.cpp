
/*! 
 * ICPC Problems 2023
 * Problem: 2023A
 * Answer: Rodny Estrada<rrodnyestrada1@gmail.com>
 */
#include <iostream>
#include <vector>
using namespace std;

class Supplier {
public:
  int id;       // (i)
  int startDay; // (S_i)
  int price;    // (P_i) price per day of client
};

class Client {
public:
  int id;           // (j)
  int endDay;       // (E_j)
  int grossRevenue; // (R_j) 
}; 

// Kruskal's Database
vector<Client> clients;
vector<Supplier> suppliers;

int main() {

  // get suppliers data
  int suppliersLength;
  cin >> suppliersLength;

  suppliers.resize(suppliersLength);
  for (int i = 0; i < suppliersLength; i++) {
    cin >> suppliers[i].startDay >> suppliers[i].price;
    suppliers[i].id = i + 1;
  }

  // get operations data
  int opsLength;
  cin >> opsLength;

  for (int i = 0; i < opsLength; i++) {
    char operation;
    cin >> operation;
    
    if (operation == 's') {
      // compute max revenue
      int supplierId;
      cin >> supplierId;

      Supplier &supplier = suppliers[supplierId - 1];
       
      int maxRevenue = 0;
      for (int j = 0; j < clients.size(); j++) {
        Client &client = clients[j];
        if (client.endDay < supplier.startDay) continue;
        
        int revenue = (client.endDay - supplier.startDay + 1) * (client.grossRevenue - supplier.price); 
        if (revenue <= maxRevenue) continue;
        
        maxRevenue = revenue;
      }

      cout << maxRevenue << endl;

    } else if (operation == 'c')  {
      // add a client
      Client client; 
      cin >> client.endDay >> client.grossRevenue; 
      clients.push_back(client);
    } 
  }
 
}