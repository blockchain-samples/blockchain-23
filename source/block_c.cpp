#include "block_c.hpp"
#include "sha256_c.hpp"

#include <sstream>
#include <vector>

using namespace std;
using namespace smd::hash;
using namespace smd::blockchain;

//==============================================================================================================================
const string& block_c::mcGetHash( void ) const {
    return mHash;
}

//==============================================================================================================================
void block_c::mMineBlock( uint32_t difficulty ) {
    vector< char > cstr( difficulty + 1, '0' );
    cstr[ difficulty ] = '\0';

    string str { cstr.data() };

    do {
        ++mNonce;
        mHash = mcCalculateHash();
    } while ( mHash.substr( 0, difficulty ) != str );

    cout << "Block mined: " << mHash << endl;
}

//==============================================================================================================================
block_c::block_c( uint32_t indexIn, const string& cDataIn ) :
    mIndex { indexIn },
    mNonce { -1 },
    mData { cDataIn },
    mTime { time( nullptr ) } {}

//==============================================================================================================================
block_c::block_c( const block_c& cBlock ) :
    mPrevHash { cBlock.mPrevHash },
    mIndex { cBlock.mIndex },
    mNonce { cBlock.mNonce },
    mData { cBlock.mData },
    mHash { cBlock.mHash },
    mTime { cBlock.mTime } {}

//==============================================================================================================================
string block_c::mcCalculateHash( void ) const {
    stringstream ss;
    ss << mIndex << mTime << mData << mNonce << mPrevHash;
    return bytesToHexStr( sha256( ss.str() ) );
}
