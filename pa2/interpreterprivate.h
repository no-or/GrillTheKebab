// file:        interpreterprivate.h
// author:      Jack S-J, Geoff T
// date:        2017-10-11
// description: private methods for Interpreter
//              Declare and implement your private functions here.
//              Leave blank if you have no private functions to implement.
//              No includes or qualification necessary. Example below:

#ifndef _INTERPRETERPRIVATE_H_
#define _INTERPRETERPRIVATE_H_



/* Example function

bool myHelper(int a, int b)
{
if (a > b)
return true;
else
return false;
}

*/

bool has_only_digits(const std::string s){
  return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

//  bool isInteger( std::string  s)
// {
//    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
//    	return false ;
// }
//    char * p ;
//    strtol(s.c_str(), &p, 10) ;

//    return (*p == 0) ;
// }

// bool is_number(const std::string& s)
// {
//     return !s.empty() && std::find_if(s.begin(), 
//         s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
// }


//copyInterpreter needed
void copyInterpreter(const Interpreter& itpt){
	const Interpreter& copy_interpreter = itpt;
}

#endif