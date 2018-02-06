//
// Created by niushaohan on 2018/2/5.
//

#include <eosiolib/eos.hpp>
#include <eosiolib/db.hpp>


namespace syb_fib {

    /**
     * @abi action
     */
    struct compute {
        uint64_t iterations;
    };

    /**
     * @abi table i64
     * @brief Data structure to hold result information
     */
    struct PACKED(result) {
        result() {};
        result(eosio::name id, uint64_t value):id(id), value(value) {};

        eosio::name id;
        uint64_t value;
    };

    using Results = eosio::table<N(shniu), N(shniu), N(result), result, uint64_t>;

}  /// EOS_SYB_FIB
