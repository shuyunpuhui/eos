/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <syb_jianli/syb_jianli.hpp>
#include <syb_jianli/syb_jianli.gen.hpp>

namespace SYB_TOKEN_NAME {

    bool apply_save(const save& s) {

        eosio::print("apply save...");

//        jianli cv(s.id, s.owner, s.card_id, s.mobile);

//        Jianli::store(cv, cv.id);

        return true;
    }
}

using namespace SYB_TOKEN_NAME;

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
        eosio::print( "Hello World: ", eosio::name(code), "->", eosio::name(action), "\n" );
        if (code == N(syb)) {
            if (action == N(save)) {
                eosio::print("action of save start2...");
//                std::string(eosio::name(current_receiver()));
//                char buffer[128];
//                save value;
//                auto read = read_action(&value, sizeof(value));
//                eosio::print(sizeof(value), ".....", read);
                eosio::print(eosio::name(current_receiver()));
                auto message = eosio::current_action<save>();
                eosio::print("action of save end2...");
//                apply_save(message);
            }
        }
    }

} // extern "C"
