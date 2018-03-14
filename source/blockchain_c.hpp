#pragma once

#include "block_c.hpp"

#include <cstdint>
#include <vector>

namespace smd::blockchain {

class blockchain_c final {
public:
    blockchain_c( void );

    void mAddBlock( uint32_t indexIn, const std::string& cDataIn );

private:
    uint32_t               mDifficulty;
    std::vector< block_c > mChain;

    const block_c& mcGetLastBlock( void ) const;
};

} // namespace smd::blockchain
