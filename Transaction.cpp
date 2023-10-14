#include "Transaction.h"

TX::TX(string Txer_key, string Txee_key) : Pub_Key_Txer(Txer_key), Pub_Key_Txee(Txee_key) {   
    ifstream fin(fpath);
    string row;
    Item it;
    while(getline(fin, row)) {
        string col1, col2, col3;
        stringstream ss(row);
        ss >> col1 >> col2 >> col3;
        it.Prod_Num = col1;
        it.Description = col2;
        it.Serial_Num = col3;
        if(it.Prod_Num == "Product_Number")
            continue;
        List_Items.push_back(it);
    }
}

int TX::_Verify_TX(string priv_key1, string priv_key2) : _Priv_Key_Txer(priv_key1), _Priv_Key_Txee(priv_key2) const{
    
}
