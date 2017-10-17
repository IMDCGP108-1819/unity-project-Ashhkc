#include "QuadTree.h"
#include "DrawToScreen.cpp"

/*struct gridPart
{
	int u;
	int v;
	char side;
};

struct gridFace : public gridPart
{
	gridPart vertex;
	gridPart edges[2];

};

struct gridVertex : public gridPart
{
	gridPart faces[4];
};

struct gridEdge : public gridPart
{
	gridPart vertex[2];
	gridPart faces[2];
};*/

int main()
{
	display();
	return 0;
}


//reference
//http://www.geeksforgeeks.org/quad-tree/