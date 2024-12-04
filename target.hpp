#ifndef TARGET 
#define TARGET 
 
#include <systemc> 
#include <string> 
#include <tlm.h> 
#include "tlm_utils/simple_target_socket.h" 
#include <iostream> 
#include <cstring> 
 
class Target : public sc_core::sc_module { 
 
    public: 
        tlm_utils::simple_target_socket<Target> target_sk; 
 
    Target(sc_core::sc_module_name nm) : target_sk("target_sk") { 
        target_sk.register_b_transport(this, &Target::b_transport); 
    } 
 
    void b_transport(tlm::tlm_generic_payload& trans, sc_core::sc_time& delay) { 
        SC_REPORT_INFO("Target", ("Timestamp when received trans -> @" + sc_core::sc_time_stamp().to_string()).c_str()); 
 
        sc_core::wait( delay ); 
        unsigned char* data_ptr = trans.get_data_ptr(); 
 
        std::string recv_data_str; 
        for (int i = 0; i < trans.get_data_length(); ++i) { 
            recv_data_str += data_ptr[i]; 
        } 
 
        SC_REPORT_INFO("Target", ("Received data -> " + recv_data_str).c_str()); 
        SC_REPORT_INFO("Target", ("Timestamp after delay -> @" + sc_core::sc_time_stamp().to_string()).c_str()); 
 
        trans.set_response_status(tlm::TLM_OK_RESPONSE); 
        SC_REPORT_INFO("Target", "Respponded"); 
    } 
}; 
 
 
#endif // TARGET!!