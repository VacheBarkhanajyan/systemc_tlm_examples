#ifndef TARGET 
#define TARGET 
 
#include <systemc> 
#include <string> 
#include <tlm.h> 
#include "tlm_utils/simple_target_socket.h" 
 
class Target : public sc_core::sc_module { 
public: 
    tlm_utils::simple_target_socket<Target> target_sk; 

    Target(sc_core::sc_module_name nm);
 
    void b_transport(tlm::tlm_generic_payload& gp, sc_core::sc_time& delay);
}; 
 
#endif // TARGET
