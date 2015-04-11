



#include <fullscore/run_script.h>



#include <string>
#include <iostream>
#include <stdio.h>

// from http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
// use "_popen" and "_pclose" for windows
// and "popen" and "pclose" for other systems

static std::string exec(const char* cmd) {
    FILE* pipe = _popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    _pclose(pipe);
    return result;
}




RubyScriptResult run_ruby_script(std::string script_filename, std::string args)
{
	RubyScriptResult result;
	std::string exec_command = "C:/Ruby200/bin/setrbvars.bat & ruby ./data/scripts/" + script_filename + " " + args;
	result.output = exec(exec_command.c_str());
	// profiling on my computer demonstrates that this method takes 0.09sec to 0.11sec to execute.
	// That's setting the environment vars, starting the interpreter, and running a simple script.
	// obviously, it's not ideal for realtime usage, but for now this is the simplest implementation
	// to begin development with ruby and scripting.

	result.filename = script_filename;
	result.exception_caught = false; // with this method, there is no way to catch the error in std err

	return result;
}
