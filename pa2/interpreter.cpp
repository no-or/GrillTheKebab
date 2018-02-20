#include "interpreter.h"
#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>

std::string Interpreter::execOp(std::string curr){

	int one = 0;
	int two = 0;
	int result = 0;
	int k = 0;
	int j = 0;
	
	std::string result_s = "";
	std::string operant = "";
std::cout << "here" << std::endl;
		if (curr == "+") {
				std::cout << "+" << std::endl;
			  	one = bin.pop();
					two = bin.pop();
					result = one + two;
					bin.push(result);
					return toString(result);

			} else
			if (curr == "-") {
				std::cout << "-" << std::endl;
					one = bin.pop();
					two = bin.pop();
					result = two - one;
					bin.push(result);
					return std::to_string(result);
					
				} else
			if (curr == "*") {
				std::cout << "*" << std::endl;
					one = bin.pop();
					two = bin.pop();
					result = one * two;
					bin.push(result);
					return std::to_string(result);
					
				} else
			if (curr == "/") {
				std::cout << "/" << std::endl;
					one = bin.pop();
					two = bin.pop();
					result = two / one;
					bin.push(result);
					return std::to_string(result);
					
				} else
			if (curr == "^") {
				std::cout << "^" << std::endl;
					 one = bin.pop();
					two = bin.pop();
					// result = 1;
					// for (int i=0;i<one;i++){
					// 	result = result * two;
					// }
					result = recpow(one,two);
					bin.push(result);
					return std::to_string(result);
					
				} else
			if (curr == "RQ") {
				std::cout << "RQ" << std::endl;
					k = bin.size();
					std::string temp = "";
					std::string copy = "";
					for (int i=0;i<k;i++){
						temp = bin.pop();
						copy = temp;
						tube.enqueue(copy);
						sparebin.push(toInt(temp));
					}
					j = sparebin.size();
					for (int i=0;i<j;i++){
						operant = sparebin.pop();
						bin.push(toInt(operant));
						result_s += operant;
						result_s += " ";
					}
					result_s.pop_back();
					std::cout << result_s << std::endl;
					return result_s;
					
				} else
				if (curr == "print") {
					std::cout << "print" << std::endl;
					k = tube.size();
					for (int i = 0; i<k; i++){
						result_s += tube.dequeue();
						result_s += " ";
					}
					result_s.pop_back();
					return result_s;
					
				} else
				if (curr == "#") {
					std::cout << "#" << std::endl;
					return result_s;
				}


std::cout << "again" << std::endl;
				
}


// Calculates x^y
int Interpreter::recpow(int x, int y) {
    int temp;
    if (y == 0) return 1;
    if (y == 1) return x;
    else if (y % 2 == 0){
    	temp = recpow(x, y/2);
    	return temp * temp;
    } 
    else
    	temp = recpow(x, (y - 1)/2);
    	return x * temp * temp;
}


std::string toString(int num)
{
	std::string result;
    std::ostringstream oss;
    oss << num;
    
    return oss.str();	
}

int toInt(std::string s)
{
     std::stringstream ss(s);
     int result = 0;
     ss >> result;
     
     return result;
}



Interpreter::Interpreter(){
	// Queue<std::string>* tube = new Queue<std::string>();
	// Stack<int>* bin = new Stack<int>();
	// Stack<int>* sparebin = new Stack<int>();

    Queue<std::string> tube;
    Stack<int> bin;
    Stack<int> sparebin;
}

Interpreter::Interpreter(const Interpreter& itpt){
    tube = itpt.tube;
    bin = itpt.bin;
    sparebin = itpt.sparebin;
}

Interpreter& Interpreter::operator=(const Interpreter& itpt){
	// if (this==&itpt) return *this;
	// copyInterpreter(itpt);
	// return *this;

	tube = itpt.tube;
    bin = itpt.bin;
    sparebin = itpt.sparebin;
    return *this;
}

void Interpreter::load(std::string instruction){
	std::istringstream ss(instruction);
	std::string temp;
	while (ss >> temp) {
		std::cout << temp << std::endl;
		tube.enqueue(temp);
	}
	// for (std::string instruction; ss >> instruction;){
	// 	std::cout << instruction << std::endl;
	// 	tube.enqueue(instruction);
	// }
	tube.enqueue("#");
}

bool Interpreter::hasMoreInstructions(){
	return (!tube.isEmpty());
}

std::string Interpreter::next(){
	std::string returnString;
	std::string curr = tube.dequeue();
	std::cout << curr << std::endl;
	int intCurr = 0;

	// if (is_number(curr)) {
	// 	intCurr = std::stoi(curr);
	// 	bin.push(intCurr);
	// 	return curr;
	// }  else {
		try {
			 if (
			 	curr != "+" &&
				curr != "-" &&
				curr != "*" &&
				curr != "/" &&
				curr != "^" &&
				curr != "RQ" &&
				curr != "print" &&
				curr != "#"
		//	has_only_digits(curr) 
				){
			 	std::cout << "number" << std::endl;
						intCurr = toInt(curr);
						bin.push(intCurr);
						return "";
			}

			returnString += execOp(curr);
			std::cout << "hey!" << std::endl;
			

		} catch (std::exception& e){
   				std::cout << e.what() << std::endl;
 			}
	//}

}

std::string Interpreter::run(){
	std::string result = "";
	std::string temp = "";
	int k = tube.size();
	for (int i=0; i<k; i++){
		temp=next();
		//std::cout << temp << std::endl;
		result += temp;
		result += "\n";
	}
	result.pop_back();
	return result;
}

void Interpreter::clear(){
	while (!tube.isEmpty()) {
        tube.dequeue();
    }
    while (!bin.isEmpty()) {
        bin.pop();
    }
    while (!sparebin.isEmpty()) {
        sparebin.pop();
    }
}


// bool has_only_digits(const std::string s){
// 	bool answer = (s.find_first_not_of( "0123456789" ) == std::string::npos);
//   return answer;
// }




