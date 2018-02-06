//
// Created by niushaohan on 2018/2/5.
//

#include <syb_fib.hpp>

using namespace syb_fib;

extern "C" {

    void init() {

    }

    uint64_t fibb(uint64_t iterations) {
        uint64_t first = 0;
        uint64_t second = 1;

        if (iterations == 0)
            return 0;

        eosio::print("1 ");
        for (uint64_t i=1; i < iterations; i++) {
            uint64_t res = first + second;
            first = second;
            second = res;
            eosio::print(res, " ");
        }

        return second;
    }

    void apply(uint64_t code, uint64_t action) {
        if (action == N(compute)) {
            auto message = eosio::current_action<compute>();
            eosio::print("Calling fib...");
            eosio::print(message.iterations);
            uint64_t num = fibb(message.iterations);

            result res(eosio::name(code), num);
            Results::store(res, res.id);
            eosio::print("Store result in database");
        }
    }
}  /// extern C
