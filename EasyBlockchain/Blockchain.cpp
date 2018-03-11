#include "stdafx.h"
#include "Blockchain.h"

#include <cstdlib>
#include <vector>
#include "Block.h"
using namespace std;

Blockchain::Blockchain()
{
	chain.emplace_back(Block(0, "Genesis Block"));
	difficulty = 4;
}


Blockchain::~Blockchain()
{
}

void Blockchain::AddBlock(Block newBlock)
{
	newBlock.PreviousHash = getLastBlock().GetHash();
	newBlock.MineBlock(difficulty);
	chain.push_back(newBlock);
}

Block Blockchain::getLastBlock() const
{
	return chain.back();
}
