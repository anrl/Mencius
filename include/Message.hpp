// Copyright 2019 Lukas Joswiak, Justin Johnson, Jack Khuu"

#ifndef INCLUDE_MESSAGE_HPP_
#define INCLUDE_MESSAGE_HPP_

#include <string>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

enum MessageType {
  Request,
  Reply
};

class Message {
 public:
  Message();
  Message(std::string m, MessageType type);

  std::string GetMessage() {
    return m_;
  }

  // Serializes this Message and returns the serialized
  // output as a string.
  std::string Encode() const;

  // Deserialize the given string into a Message object.
  static Message Decode(const std::string data);

 private:
  friend class boost::serialization::access;

  template<class Archive> void serialize(Archive &ar,
      const unsigned int version) {
    ar & m_;
    ar & type_;
  }

  std::string m_;
  MessageType type_;
};

#endif  // INCLUDE_MESSAGE_HPP_