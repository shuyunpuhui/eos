/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eosiolib/eos.hpp>
#include <eosiolib/string.hpp>
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
     * @abi table i64
     */
    struct PACKED(jianli) {
        jianli() {};

        jianli(eosio::name id, eosio::string owner, eosio::string card_id, eosio::string mobile)
            :id(id), owner(owner), card_id(card_id), mobile(mobile) {};

        eosio::name id;
        eosio::string owner;
        eosio::string card_id;
        eosio::string mobile;

    };

    /**
     * @abi action
     */
    struct save {
        eosio::name id;
        eosio::string owner;
        eosio::string card_id;
        eosio::string mobile;
//        uint64_t owner;
    };

    using Jianli = eosio::table<N(syb), N(syb), N(jianli), jianli, uint64_t>;

}  /// @} /// syb_jianli
