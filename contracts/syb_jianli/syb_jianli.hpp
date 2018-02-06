/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eosiolib/eos.hpp>
#include <eosiolib/db.hpp>

/**
 * Make it easy to change the namespace
 */
#ifndef SYB_TOKEN_NAME
#define SYB_TOKEN_NAME syb
#endif

//using namespace eosio;
namespace SYB_TOKEN_NAME {

    /**
     * @abi action save
     * @abi table i64
     */
    struct PACKED(jianli) {
        jianli() {};

        jianli(eosio::name owner, uint64_t mobile):owner(owner), mobile(mobile) {};

        eosio::name owner;

        uint64_t mobile;

    };

    using Jianli = eosio::table<N(syb), N(syb), N(jianli), jianli, uint64_t>;

}  /// @} /// syb_jianli
