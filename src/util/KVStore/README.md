This util is used for representing an AMOStore

The main file exposed for using the AMOStore will be AMOStore.cc
and an example of how to use AMOStore is located in example.cc

The AMOStore offers a single method to the user: execute.

execute
-------
Takes in an AMOCommand and returns an AMOResponse. 
If the command was executed in that past (based off of the seqNum), the same AMOResponse will be returned. Otherwise a new AMOResponse will be created containing the result of executing the AMOCommand.

AMOResponse: AMOCommand, value (string) 

AMOCommand: seqNum (int), key (string), value (string) {Not used for GET}, action (Action)

Action: PUT, APPEND, GET 


As it currently stands, errors are thrown when Commands are issued on illegal states (i.e APPEND before GET). Error Responses will be in a later diff.


Compilation
-----------
g++ -Wall -g -std=c++14 -I ../../../include/

-c KVStore.cpp
-c AMOCommand.cpp
-c AMOResponse.cpp
-c AMOStore.cpp
-c example.cpp

-o example *.o
