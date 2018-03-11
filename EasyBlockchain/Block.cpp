#include "stdafx.h"
#include "Block.h"
#include "sha256.h"
#include <cstdint>
#include <iostream>
#include <sstream>
using namespace std;



Block::Block(uint32_t index, const string & blockData)
{
	this->index = index;
	this->blockData = blockData;
	nonce = -1;
}

Block::~Block()
{
}

string Block::GetHash()
{
	return hash;
}

void Block::MineBlock(uint32_t difficulty)
{
	char *cstr = new char[difficulty + 1];

	for (uint32_t i = 0; i < difficulty; i++)
	{
		cstr[i] = '0';
	}
	cstr[difficulty] = '\0';

	string str(cstr);
	delete[] cstr;

	do
	{
		nonce++;
		hash = calculateHash();
	} while (hash.substr(0, difficulty) != str);

	cout << "Block mined #" << index << " nonce: " << nonce <<  " data: " << blockData << endl << "sha256: " << hash << endl;
	

}

string Block::calculateHash()
{
	stringstream ss;
	ss << index << blockData << nonce << PreviousHash;
	return sha256(ss.str());
}
