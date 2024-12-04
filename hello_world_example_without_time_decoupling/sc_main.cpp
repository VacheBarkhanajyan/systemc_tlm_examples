#include <systemc> 
#include "initiator.hpp" 
#include "target.hpp" 
#include "top.hpp" 
#include <tlm> 
#include <cstring> 
 
using namespace sc_core; 
using namespace sc_dt; 
using namespace std; 
 
 
int sc_main(int argc, char* argv[]) { 
 
  sc_core::sc_report_handler::set_verbosity_level(sc_core::SC_MEDIUM); 
     
  Top top("top"); 
     
  sc_start(); 
 
  return 0; 
 
}