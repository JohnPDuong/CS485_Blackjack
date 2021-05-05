//***************************************************************************
// File name:  Status.h
// Author:     John Duong
// Date:       5/7/2021
// Class:      CS485
// Assignment: Blackjack
// Purpose:    Enum class for status of the players
//***************************************************************************
#pragma once

enum class Status
{
	Bust,
	Lose,
	Blackjack = 21,
	Win
};