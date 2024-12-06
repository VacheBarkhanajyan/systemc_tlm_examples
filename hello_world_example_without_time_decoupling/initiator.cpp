#include "initiator.h"
#include <cstring>

Initiator::Initiator(sc_core::sc_module_name nm) 
    : sc_module(nm), initiator_sk("initiator_sk") 
{
    SC_THREAD(run);
}

void Initiator::run() { 
    tlm::tlm_generic_payload gp; 
    sc_core::sc_time delay = sc_core::sc_time(10, sc_core::SC_NS); 

    std::string message_str("Hello World!");  
    std::vector<unsigned char> data(message_str.begin(), message_str.end());  
    data.push_back('\0'); 
     
    gp.set_command(tlm::TLM_WRITE_COMMAND); 
    gp.set_address(0); 
    gp.set_data_ptr(data.data()); 
    gp.set_data_length(data.size()); 
    gp.set_streaming_width(data.size()); 
    gp.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE); 

    SC_REPORT_INFO("Initiator", ("Sending data -> " + message_str).c_str()); 
    initiator_sk->b_transport(gp, delay); 

    if (gp.get_response_status() == tlm::TLM_OK_RESPONSE) { 
        SC_REPORT_INFO("Initiator", "Received response successfully"); 
    } else { 
        SC_REPORT_ERROR("Initiator", "Transaction failed"); 
    } 

    unsigned char* data_ptr = gp.get_data_ptr(); 
    std::string recv_data_str; 
    for (int i = 0; i < gp.get_data_length(); ++i) { 
        recv_data_str += data_ptr[i]; 
    } 

    SC_REPORT_INFO("Initiator", ("Data -> " + recv_data_str).c_str()); 
    SC_REPORT_INFO("Target", ("Timestamp after response -> @" + sc_core::sc_time_stamp().to_string()).c_str()); 
}
