#ifndef TOP 
#define TOP 
 
#include <systemc> 
#include "initiator.h" 
#include "target.h" 
#include <tlm> 
 
class Top : public sc_core::sc_module { 
public: 
    Initiator* initiator; 
    Target* target; 

    Top(sc_core::sc_module_name nm);
    ~Top();
}; 
 
#endif // TOP
