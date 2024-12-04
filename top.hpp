#ifndef TOP 
#define TOP 
 
#include <systemc> 
#include "initiator.hpp" 
#include "target.hpp" 
#include <tlm> 
 
class Top : public sc_core::sc_module { 
 
    public: 
        Initiator* initiator; 
        Target* target; 
 
        Top(sc_core::sc_module_name nm) { 
            initiator = new Initiator("initiator"); 
            target = new Target("target"); 
            initiator->initiator_sk.bind(target->target_sk); 
        } 
 
        ~Top() { 
        delete initiator; 
        delete target; 
        } 
}; 
 
#endif // TOP!!