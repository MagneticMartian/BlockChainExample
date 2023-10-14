#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const string fpath = "Item.db";

struct Item {
    string Prod_Num;
    string Description;
    string Serial_Num;
};

class TX {
public:
    string Pub_Key_Txer;
    string Pub_Key_Txee;
    vector<Item> List_Items;

    TX(string Txer_key, string Txee_key);
private:
    string _Priv_Key_Txer;
    string _Priv_Key_Txee;

    int _Verify_TX(string priv_key1, string priv_key2) const;
};
