#pragma once

#include<iostream>
using namespace std;
class CompanyDEO {
public:
	virtual void write_file() = 0;
	virtual void read_file() = 0;
};