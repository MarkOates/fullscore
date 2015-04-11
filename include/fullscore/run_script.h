#ifndef __FULLSCORE_RUN_SCRIPT_HEADER
#define __FULLSCORE_RUN_SCRIPT_HEADER




#include <string>


struct RubyScriptResult
{
	bool exception_caught; // currently does not function
	std::string filename;
	std::string output;
};


// this is the stupid way to do it, but it works for now :)
// setup the ruby environment vars (located in setrbvars.bat) and run the ruby script

// profiling on my computer demonstrates that this method takes 0.09sec to 0.11sec to execute.
// That's setting the environment vars, starting the interpreter, and running a simple script.
// obviously, it's not ideal for realtime usage, but for now this is the simplest implementation
// to begin development with ruby and scripting in this program.

// Current implementation is messy, runs in a system() command, and does not check to sanitize
// inputs.

RubyScriptResult run_ruby_script(std::string script_filename, std::string args);



/*
// example usage

	RubyScriptResult result = run_ruby_script("ruby_script.rb", "Chris");
	if (result.exception_caught)
	{
		std::cout << "ruby exception caught" << std::endl;
	}
	else
	{
		std::cout << "ruby script ran successfully" << std::endl;
		std::cout << "output is: " << result.output << std::endl;
	}
*/




#endif