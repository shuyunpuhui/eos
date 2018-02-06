#pragma once
#include <eosiolib/types.hpp>
#include <eosiolib/action.hpp>
#include <eosiolib/datastream.hpp>
#include <eosiolib/raw_fwd.hpp>

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const jianli& value ) {
      raw::pack(s, value.id);
      raw::pack(s, value.owner);
      raw::pack(s, value.card_id);
      raw::pack(s, value.mobile);
   }
   template<typename Stream> inline void unpack( Stream& s, jianli& value ) {
      raw::unpack(s, value.id);
      raw::unpack(s, value.owner);
      raw::unpack(s, value.card_id);
      raw::unpack(s, value.mobile);
   }
   template<typename Stream> inline void pack( Stream& s, const save& value ) {
      raw::pack(s, value.id);
      raw::pack(s, value.owner);
      raw::pack(s, value.card_id);
      raw::pack(s, value.mobile);
   }
   template<typename Stream> inline void unpack( Stream& s, save& value ) {
      raw::unpack(s, value.id);
      raw::unpack(s, value.owner);
      raw::unpack(s, value.card_id);
      raw::unpack(s, value.mobile);
   }
} }

#include <eosiolib/raw.hpp>
namespace eosio {
   void print_ident(int n){while(n-->0){print("  ");}};
   template<typename Type>
   Type current_message_ex() {
      uint32_t size = message_size();
      char* data = (char *)eosio::malloc(size);
      assert(data && read_message(data, size) == size, "error reading message");
      Type value;
      eosio::raw::unpack(data, size, value);
      eosio::free(data);
      return value;
   }
   void dump(const jianli& value, int tab=0) {
      print_ident(tab);print("id:[");printn(value.id);print("]\n");
      print_ident(tab);print("owner:[");prints_l(value.owner.get_data(), value.owner.get_size());print("]\n");
      print_ident(tab);print("card_id:[");prints_l(value.card_id.get_data(), value.card_id.get_size());print("]\n");
      print_ident(tab);print("mobile:[");prints_l(value.mobile.get_data(), value.mobile.get_size());print("]\n");
   }
   template<>
   jianli current_message<jianli>() {
      return current_message_ex<jianli>();
   }
   void dump(const save& value, int tab=0) {
      print_ident(tab);print("id:[");printn(value.id);print("]\n");
      print_ident(tab);print("owner:[");prints_l(value.owner.get_data(), value.owner.get_size());print("]\n");
      print_ident(tab);print("card_id:[");prints_l(value.card_id.get_data(), value.card_id.get_size());print("]\n");
      print_ident(tab);print("mobile:[");prints_l(value.mobile.get_data(), value.mobile.get_size());print("]\n");
   }
   template<>
   save current_message<save>() {
      return current_message_ex<save>();
   }
} //eosio

