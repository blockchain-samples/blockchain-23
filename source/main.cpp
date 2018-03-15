#include "blockchain_c.hpp"

#include <exception>
#include <iostream>

using namespace std;
using namespace smd::blockchain;

int main( void ) try {
    blockchain_c blockchain;

    cout << "Mining block 1..." << endl;
    blockchain.mAddBlock( 1, "Block 1 Data" );

    cout << "Mining block 2..." << endl;
    blockchain.mAddBlock( 2, "Block 2 Data" );

    cout << "Mining block 3..." << endl;
    blockchain.mAddBlock( 3, "Block 3 Data" );

    return 0;

} catch ( const exception& cEx ) {
    cerr << cEx.what() << endl;
    return 1;

} catch ( ... ) {
    cerr << "FATAL ERROR !!!" << endl;
    return 2;
}
