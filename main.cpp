#include "Blockchain.h"
#include <cstdio>
using namespace std;

int main(void) {
    Blockchain bChain = Blockchain();

    printf("Mining block 1...\n");
    bChain.AddBlock(Block(1, "Block 1 Data"));
    
    printf("Mining block 2...\n");
    bChain.AddBlock(Block(2, "Block 2 Data"));

    printf("Mining block 3...\n");
    bChain.AddBlock(Block(3, "Block 3 Data"));
}
