#pragma once

#include <cstdlib>
#include <vector>
#include "Block.h"
using namespace std;

class Blockchain
{
public:
	Blockchain();
	~Blockchain();

	void AddBlock(Block newBlock);

private:
	uint32_t difficulty;
	vector<Block> chain;

	Block getLastBlock() const;
};

