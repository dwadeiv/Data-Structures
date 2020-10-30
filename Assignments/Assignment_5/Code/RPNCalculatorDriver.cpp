/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <iomanip>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator Calc;
  string input;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, input);
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */
   bool is_number = isNumber(input);
   if(input == "="){
     break;
   }
   else if(is_number == true){
     float new_operand = (float)atof(input.c_str());
     Calc.push(new_operand);
   }
   else if(is_number == false){
     Calc.compute(input);
   }
  }

  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
  if(Calc.isEmpty()){
    cout << "No operands: Nothing to evaluate" << endl;
  }

  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/
  
  else {
    Operand* final_result = Calc.peek();
    float result = final_result->number;
    Calc.pop();
    if(Calc.isEmpty()){
      int result_int = int(result);
      if(result_int == result){
        cout << result_int << endl;
      }
      else {
        cout << fixed << setprecision(1) << result << endl;
      }
    }
    else if(!Calc.isEmpty()){
      cout << "Invalid expression" << endl;
    }
  }

  return 0;
}
