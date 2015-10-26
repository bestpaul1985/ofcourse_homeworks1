#include "303SingleF.h"



SingleF::SingleF( ofPtr<Smoke> P ):
	s(P)
{

}

SingleF::~SingleF(void)
{

}

ofPtr<Smoke> SingleF::getS()
{
	return s;
}

