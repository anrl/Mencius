// Copyright 2019 Lukas Joswiak, Justin Johnson, Jack Khuu.
//
// Used to inform other servers that a value has been chosen.
//
// Learn(b, v)
//  - b: ballot (round) number
//  - v: the value that has been chosen

#ifndef INCLUDE_LEARN_HPP_
#define INCLUDE_LEARN_HPP_

#include <string>
#include <sstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "AMOCommand.hpp"

namespace message {

class Learn {
 public:
  Learn();
  explicit Learn(
      int instance,
      KVStore::AMOCommand value);

  int GetInstance() const {
    return instance_;
  }

  KVStore::AMOCommand GetValue() const {
    return value_;
  }

  std::string Encode() const;

  static Learn Decode(const std::string &data);

 private:
  friend class boost::serialization::access;

  template<class Archive> void serialize(Archive &ar,
      unsigned int _ /* version */) {
    ar & instance_;
    ar & value_;
  }

  int instance_;
  KVStore::AMOCommand value_;
};

}  // namespace message

#endif  // INCLUDE_LEARN_HPP_
