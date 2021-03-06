/*
	Generated by cppsrc.sh
	On 2014-06-17 21:43:15,86
	by Paweu
*/

#pragma once
#ifndef CellVector_H
#define CellVector_H

namespace nSimulation {

typedef std::pair<CellContext*, glm::uvec2> CellVecPair;

struct CellVector : public std::vector<CellVecPair>  {
	CellVector(const SimulationParameters *sp);

	void Add(CellContext* cell, const glm::uvec2 &pos) {
		push_back(std::make_pair(cell, pos));
	}
	void Add(CellContext* cell, const glm::ivec2 &pos) {
		push_back(std::make_pair(cell, glm::uvec2(pos)));
	}


//for scripts
	void SortParameter(const char* Parameter, bool Reverse);
	CellContext* ScriptAt(int index) { return at(index).first; }
	glm::uvec2* PosAt(int index) { return &at(index).second; }
	int Count() const { return size(); }
private:
	const SimulationParameters *m_sp;
};


} //namespace nSimulation

using namespace nSimulation;

#endif

