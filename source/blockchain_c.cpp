#include "blockchain_c.hpp"

using namespace std;
using namespace smd::blockchain;

//==============================================================================================================================
blockchain_c::blockchain_c( void ) :
    mDifficulty { 5 }
{
    mChain.emplace_back( 0, "Genesis Block" );
}

//==============================================================================================================================
void blockchain_c::mAddBlock( uint32_t indexIn, const string& cDataIn ) {
    block_c block { indexIn, cDataIn };

    block.mPrevHash = mcGetLastBlock().mcGetHash();
    block.mMineBlock( mDifficulty );

    mChain.emplace_back( block );
}

//==============================================================================================================================
const block_c& blockchain_c::mcGetLastBlock( void ) const {
    return mChain.back();
}
