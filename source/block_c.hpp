#pragma once

#include <cstdint>
#include <iostream>
#include <string>

namespace smd::blockchain {

class block_c final {
public:
    std::string mPrevHash;

    const std::string& mcGetHash( void ) const;
    void               mMineBlock( uint32_t difficulty );

    block_c& operator=( const block_c& ) = delete;
    block_c& operator=( block_c&& )      noexcept = delete;
             block_c( uint32_t indexIn, const std::string& cDataIn );
             block_c( const block_c& cBlock );
             block_c( block_c&& )        noexcept = delete;
             ~block_c( void )            = default;

private:
    uint32_t    mIndex;
    int64_t     mNonce;
    std::string mData;
    std::string mHash;
    time_t      mTime;

    std::string mcCalculateHash( void ) const;
};

} // namespace smd::blockchain
