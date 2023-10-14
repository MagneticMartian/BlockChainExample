#include "Blockchain.h"

/* Initializing the Blockchain
 *******************************/
Blockchain::Blockchain() {
    /* The emplace_back call appends a new element
     * to the end of the container. In this case
     * the container is a vector and the elements
     * are blocks. During initialization this is
     * gong to be the first element of the vector.
     **********************************************/
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 6; /* Numerical rep of difficulty */
}

/* Adding a new block to the blockchain
 ***************************************/
void Blockchain::AddBlock(Block bNew) {
    /* Storing the hash of the previous block */
    bNew.sPrevHash = _GetLastBlock().GetHash();
    /* Mining the new block */
    bNew.MineBlock(_nDifficulty);
    /* Pushing the new block to the end of the 
     * blockchain.
     ******************************************/
    _vChain.push_back(bNew);
}

/* Retreive the last block on the blockchain.
 *********************************************/
Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
