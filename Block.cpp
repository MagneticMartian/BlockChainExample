#include "Block.h"
#include "sha256.h"

/* Initializing the block. The values for nIndexIn and sDataIn
 * are stored into _nIndex and _sData respectively.
 */
Block::Block(uint32_t nIndexIn, const string &sDataIn): _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1; /* That magical number */
    _tTime = time(nullptr); /* Time stamping */
    _sHash = _CalculateHash(); /* Initial hash. Mainly for Genesis Block */
}

/* IDK... Because OOP or something? */
string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty){
    char cstr[nDifficulty + 1];
    for(uint32_t i = 0; i < nDifficulty; ++i){
        cstr[i] = '0'; /* Nothing to see here. Just making some zeros */
    }
    cstr[nDifficulty] = '\0'; /* Got to terminate that string */

    string str(cstr); /* Creating a string of nDifficulty zeros */

    /* The do loop continues calculating new hashes
     * until it finds one with nDifficulty number of
     * zeros at the begining of it. The new hash is
     * able to be calculated because of the updating
     * of the nNonce value. Once the loop is finished
     * nNonce will ba a random value, because can you
     * guess how many loops it will take to gen the 
     * right number of zeros?
     *************************************************/
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while(_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

/* Takes all the data that has been generated about the block
 * and calculates the hash of it up to that point.
 *************************************************************/
inline string Block::_CalculateHash() const {
    stringstream ss; /* making a string behave like a stream */
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}
