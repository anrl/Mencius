// Copyright 2019 Jack Khuu, Justin Johnson, Lukas Joswiak

#ifndef INCLUDE_AMOCOMMAND_HPP_
#define INCLUDE_AMOCOMMAND_HPP_

#include <string>

#include "Action.hpp"

namespace KVStore {

class AMOCommand {
 public:
  AMOCommand() {}
  AMOCommand(int seqNum, const std::string key, const std::string &value,
                   const Action &action);

  bool operator< (const AMOCommand &r) const;

  int GetSeqNum() const;
  std::string GetKey() const;
  std::string GetValue() const;
  Action GetAction() const;

 private:
  int seq_num_;
  std::string key_;
  std::string value_;
  Action action_;
};
}  // namespace KVStore 

#endif  // INCLUDE_AMOCOMMAND_HPP_
