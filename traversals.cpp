// Alanna McEachen
// traversals.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
	// adjacency matrix
	std::vector<std::vector<bool> > Graph (2);
	// vector of edges
	std::vector<char> edges;
	std::string line, srcs, dsts;
	char src, dst;
	int c, edgenum, testnum;

	c = std::cin.peek();
	while ( c != EOF )
	{
		getline(std::cin, line);
		edgenum = std::stoi(line);
		for (int i=edgenum; i > 0; i--)
		{
			
			getline(std::cin, line);
			std::istringstream iss(line);
			getline(iss, srcs, ' ');
			getline(iss, dsts, ' ');
			src = srcs[0];
			dst = dsts[0];
			if (i == edgenum)
			{
				if (src > dst)
				{
					edges.push_back(dst);
					edges.push_back(src);
					std::cout << "here?\n";
			//		Graph[1][0] = true;
				} else if (src < dst) {
					std::cout << "herem?\n";
					edges.push_back(src);
					edges.push_back(dst);
			//		Graph[0][0] = true;
				}
			} else {
				bool match=false;
				// iterate through edges vector
				std::vector<char>::iterator et = edges.begin();
				// iterate through Graph vector (vector of vectors)
				std::vector<std::vector<bool> >::iterator gt = Graph.begin();
				while (!match && et != edges.end())
				{
					if (src == *et){
						match=true;
						/*std::vector<bool>::iterator vt = gt->begin();
						while (vt != gt->end())
						{
							if (dst < *vt)
								gt->insert(vt, dst);
						}*/
					}
					else if (src < *et) 
					{
						edges.insert(et, src);
						//std::vector<bool> entry;
						match=true;
					}
					std::advance(et,1);
					std::advance(gt,1);
				}
				if (!match) {
					edges.push_back(src);
					
				}
			}
		}
		std::vector<char>::iterator et = edges.begin();
		while (et != edges.end())
		{
			std::cout << *et << " ";
			std::advance(et,1);
		}
		std::cout << "\n";
		getline(std::cin, line);
		testnum = std::stoi(line);
		for (int i=testnum; i > 0; i--)
		{
			getline(std::cin, line);
			std::istringstream iss(line);
			getline(iss, srcs, ' ');
			getline(iss, dsts, ' ');
		}

		// set up for next graph
		edges.clear();
		getline(std::cin, line); // should just be whitespace
		// check to see if this is the end of the file
		c = std::cin.peek();
		
	}
	return 0;
}
