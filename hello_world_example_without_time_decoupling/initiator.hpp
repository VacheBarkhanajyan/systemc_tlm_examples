#ifndef INITIATOR 
#define INITIATOR 
 
#include <systemc> 
#include <string> 
#include <tlm.h> 
#include "tlm_utils/simple_initiator_socket.h" 
#include <vector> 
 
class Initiator : public sc_core::sc_module { 
public: 
    tlm_utils::simple_initiator_socket<Initiator> initiator_sk; 

    Initiator(sc_core::sc_module_name nm);
    SC_HAS_PROCESS(Initiator);

    void run();
}; 
 
#endif // INITIATOR
