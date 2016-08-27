/**
 *	@file 		clipboard.cpp
 *	@author		Eshan Shafeeq
 *	@date		17 June 2016
 *	@version 	v0.1
 *	@brief		This program demostrates the process of copying an std::sting
 *				to the clipboard
 **/

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <stdexcept>

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
	return result;

}
void clipboard( std::string data ){

	std::string cmd = "echo -n \"";
   	cmd = cmd + data;
   	cmd = cmd + "\" > .clipboarddata";

	exec( cmd.c_str() );
	exec( "xclip -selection clipboard .clipboarddata" );
	exec( "rm -rf .clipboarddata" );


}
int main( int argc, char* argv[] ){

	clipboard("awesomnessofdeathofdeath");
	return 0;
}
