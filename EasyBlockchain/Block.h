#pragma once

#include <cstdint>
#include <iostream>
#include "sha256.h"
#include <time.h>
using namespace std;

class Block
{
public:
	string PreviousHash;

	Block(uint32_t index, const string &blockData);
	~Block();

	string GetHash();
	void MineBlock(uint32_t difficulty);

private:
	uint32_t index;
	int64_t nonce;
	string blockData;
	string hash;

	string calculateHash();

	SHA256 sha256;
};


