#pragma once

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class GnuplotPipe {
public:
	inline GnuplotPipe(bool persist = true) {
		std::cout << "Opening gnuplot... ";
		pipe = _popen(persist ? "gnuplot -persist" : "gnuplot", "w");
		if (!pipe)
			std::cout << "failed!" << std::endl;
		else
			std::cout << "succeded." << std::endl;
	}
	inline virtual ~GnuplotPipe() {
		if (pipe) _pclose(pipe);
	}

	void sendLine(const std::string& text, bool useBuffer = false) {
		if (!pipe) return;
		if (useBuffer)
			buffer.push_back(text + "\n");
		else
			fputs((text + "\n").c_str(), pipe);
	}
	void sendEndOfData(unsigned repeatBuffer = 1) {
		if (!pipe) return;
		for (unsigned i = 0; i < repeatBuffer; i++) {
			for (auto& line : buffer) fputs(line.c_str(), pipe);
			fputs("e\n", pipe);
		}
		fflush(pipe);

		buffer.clear();
	}
	void sendNewDataBlock() {
		sendLine("\n", !buffer.empty());
	}

	void writeBufferToFile(const std::string& fileName) {
		std::ofstream fileOut(fileName);
		for (auto& line : buffer) fileOut << line;
		fileOut.close();
	}

private:
	GnuplotPipe(GnuplotPipe const&) = delete;
	void operator=(GnuplotPipe const&) = delete;

	FILE* pipe;
	std::vector<std::string> buffer;
};