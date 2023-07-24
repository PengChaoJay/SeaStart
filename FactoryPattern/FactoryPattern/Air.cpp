#include "Air.h"

Air::~Air()
{

}

string Air::Deliver() const
{
	string result = "AirTransport: Transport by air";
	return result;
}